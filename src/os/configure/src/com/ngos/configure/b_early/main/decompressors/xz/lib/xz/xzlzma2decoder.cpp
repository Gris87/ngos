#include "xzlzma2decoder.h"

#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>
#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/common/ngos/utils.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



// Reset the dictionary state. When in single-call mode, set up the beginning
// of the dictionary to point to the actual output buffer.
NgosStatus dictionaryReset(LzmaDictionary *dictionary, XzBuffer *buffer)
{
    EARLY_LT((" | dictionary = 0x%p, buffer = 0x%p", dictionary, buffer));

    EARLY_ASSERT(dictionary, "dictionary is null", NgosStatus::ASSERTION);
    EARLY_ASSERT(buffer,     "buffer is null",     NgosStatus::ASSERTION);



    if (LZMA_DECODER_IS_SINGLE(dictionary->mode))
    {
        dictionary->buffer = buffer->out     + buffer->outPosition;
        dictionary->end    = buffer->outSize - buffer->outPosition;
    }

    dictionary->start    = 0;
    dictionary->position = 0;
    dictionary->limit    = 0;
    dictionary->full     = 0;



    return NgosStatus::OK;
}

// Set dictionary write limit
NgosStatus dictionaryLimit(LzmaDictionary *dictionary, u64 outMax)
{
    // EARLY_LT((" | dictionary = 0x%p, outMax = %u", dictionary, outMax)); // Commented to avoid too frequent logs

    EARLY_ASSERT(dictionary, "dictionary is null", NgosStatus::ASSERTION);
    EARLY_ASSERT(outMax > 0, "outMax is zero",     NgosStatus::ASSERTION);



    if (dictionary->end - dictionary->position <= outMax)
    {
        dictionary->limit = dictionary->end;
    }
    else
    {
        dictionary->limit = dictionary->position + outMax;
    }



    return NgosStatus::OK;
}

// Return true if at least one byte can be written into the dictionary.
inline bool dictionaryHasSpace(const LzmaDictionary *dictionary)
{
    // EARLY_LT((" | dictionary = 0x%p", dictionary)); // Commented to avoid too frequent logs

    EARLY_ASSERT(dictionary, "dictionary is null", false);



    return dictionary->position < dictionary->limit;
}

// Get a byte from the dictionary at the given distance. The distance is
// assumed to valid, or as a special case, zero when the dictionary is
// still empty. This special case is needed for single-call decoding to
// avoid writing a '\0' to the end of the destination buffer.
inline u32 dictionaryGet(const LzmaDictionary *dictionary, u32 distance)
{
    // EARLY_LT((" | dictionary = 0x%p, distance = %u", dictionary, distance)); // Commented to avoid too frequent logs

    EARLY_ASSERT(dictionary, "dictionary is null", 0);



    u64 offset = dictionary->position - distance - 1;

    if (distance >= dictionary->position)
    {
        offset += dictionary->end;
    }

    return dictionary->full > 0 ? dictionary->buffer[offset] : 0;
}

// Put one byte into the dictionary. It is assumed that there is space for it.
inline NgosStatus dictionaryPut(LzmaDictionary *dictionary, u8 byte)
{
    // EARLY_LT((" | dictionary = 0x%p, byte = %u", dictionary, byte)); // Commented to avoid too frequent logs

    EARLY_ASSERT(dictionary, "dictionary is null", NgosStatus::ASSERTION);



    dictionary->buffer[dictionary->position++] = byte;

    if (dictionary->full < dictionary->position)
    {
        dictionary->full = dictionary->position;
    }



    return NgosStatus::OK;
}

// Repeat given number of bytes from the given distance. If the distance is
// invalid, NgosStatus::INVALID_DATA is returned. On success, NgosStatus::OK is returned and *length is
// updated to indicate how many bytes were left to be repeated.
NgosStatus dictionaryRepeat(LzmaDictionary *dictionary, u32 *length, u32 distance)
{
    // EARLY_LT((" | dictionary = 0x%p, length = 0x%p, distance = %u", dictionary, length, distance)); // Commented to avoid too frequent logs

    EARLY_ASSERT(dictionary, "dictionary is null", NgosStatus::ASSERTION);
    EARLY_ASSERT(length,     "length is null",     NgosStatus::ASSERTION);



    if (distance >= dictionary->full || distance >= dictionary->size)
    {
        return NgosStatus::INVALID_DATA;
    }



    u32 left = MIN_TYPED(u64, dictionary->limit - dictionary->position, *length);
    u64 back = dictionary->position - distance - 1;

    *length -= left;



    if (distance >= dictionary->position)
    {
        back += dictionary->end;
    }



    do
    {
        dictionary->buffer[dictionary->position++] = dictionary->buffer[back++];

        if (back == dictionary->end)
        {
            back = 0;
        }
    } while(--left > 0);



    if (dictionary->full < dictionary->position)
    {
        dictionary->full = dictionary->position;
    }



    return NgosStatus::OK;
}

// Copy uncompressed data as is from input to dictionary and output buffers.
NgosStatus dictionaryUncompressed(LzmaDictionary *dictionary, XzBuffer *buffer, u32 *left)
{
    // EARLY_LT((" | dictionary = 0x%p, buffer = 0x%p, left = 0x%p", dictionary, buffer, left)); // Commented to avoid too frequent logs

    EARLY_ASSERT(dictionary, "dictionary is null", NgosStatus::ASSERTION);
    EARLY_ASSERT(buffer,     "buffer is null",     NgosStatus::ASSERTION);
    EARLY_ASSERT(left,       "left is null",       NgosStatus::ASSERTION);



    u64 copySize;

    while (
           *left > 0
           &&
           buffer->inPosition < buffer->inSize
           &&
           buffer->outPosition < buffer->outSize
          )
    {
        copySize = MIN(buffer->inSize - buffer->inPosition, buffer->outSize - buffer->outPosition);

        if (copySize > dictionary->end - dictionary->position)
        {
            copySize = dictionary->end - dictionary->position;
        }

        if (copySize > *left)
        {
            copySize = *left;
        }

        *left -= copySize;

        memcpy(dictionary->buffer + dictionary->position, buffer->in + buffer->inPosition, copySize);

        dictionary->position += copySize;

        if (dictionary->full < dictionary->position)
        {
            dictionary->full = dictionary->position;
        }

        if (LZMA_DECODER_IS_MULTI(dictionary->mode))
        {
            if (dictionary->position == dictionary->end)
            {
                dictionary->position = 0;
            }

            memcpy(buffer->out + buffer->outPosition, buffer->in + buffer->inPosition, copySize);
        }

        dictionary->start = dictionary->position;

        buffer->outPosition += copySize;
        buffer->inPosition  += copySize;
    }



    return NgosStatus::OK;
}

// Flush pending data from dictionary to buffer->out. It is assumed that there is
// enough space in buffer->out. This is guaranteed because caller uses dictionaryLimit()
// before decoding data into the dictionary.
u32 dictionaryFlush(LzmaDictionary *dictionary, XzBuffer *buffer)
{
    // EARLY_LT((" | dictionary = 0x%p, buffer = 0x%p", dictionary, buffer)); // Commented to avoid too frequent logs

    EARLY_ASSERT(dictionary, "dictionary is null", 0);
    EARLY_ASSERT(buffer,     "buffer is null",     0);



    u64 copySize = dictionary->position - dictionary->start;

    if (LZMA_DECODER_IS_MULTI(dictionary->mode))
    {
        if (dictionary->position == dictionary->end)
        {
            dictionary->position = 0;
        }

        memcpy(buffer->out + buffer->outPosition, dictionary->buffer + dictionary->start, copySize);
    }

    dictionary->start   =  dictionary->position;
    buffer->outPosition += copySize;



    return copySize;
}

// ================
// Range decoder
// ================

// Reset the range decoder.
NgosStatus rcReset(LzmaRcDecoder *rc)
{
    EARLY_LT((" | rc = 0x%p", rc));

    EARLY_ASSERT(rc, "rc is null", NgosStatus::ASSERTION);



    rc->range            = (u32)-1;
    rc->code             = 0;
    rc->initialBytesLeft = RC_INIT_BYTES;



    return NgosStatus::OK;
}

// Read the first five initial bytes into rc->code if they haven't been
// read already. (Yes, the first byte gets completely ignored.)
bool rcReadInit(LzmaRcDecoder *rc, XzBuffer *buffer)
{
    // EARLY_LT((" | rc = 0x%p, buffer = 0x%p", rc, buffer)); // Commented to avoid too frequent logs

    EARLY_ASSERT(rc,     "rc is null",     false);
    EARLY_ASSERT(buffer, "buffer is null", false);



    while (rc->initialBytesLeft > 0)
    {
        if (buffer->inPosition == buffer->inSize)
        {
            return false;
        }

        rc->code = (rc->code << 8) + buffer->in[buffer->inPosition++];
        --rc->initialBytesLeft;
    }

    return true;
}

// Return true if there may not be enough input for the next decoding loop.
inline bool rcLimitExceeded(const LzmaRcDecoder *rc)
{
    // EARLY_LT((" | rc = 0x%p", rc)); // Commented to avoid too frequent logs

    EARLY_ASSERT(rc, "rc is null", false);



    return rc->inPosition > rc->inLimit;
}

// Return true if it is possible (from point of view of range decoder) that
// we have reached the end of the LZMA chunk.
inline bool rcIsFinished(const LzmaRcDecoder *rc)
{
    // EARLY_LT((" | rc = 0x%p", rc)); // Commented to avoid too frequent logs

    EARLY_ASSERT(rc, "rc is null", false);



    return !rc->code; // rc->code == 0
}

// Read the next input byte if needed.
inline NgosStatus rcNormalize(LzmaRcDecoder *rc)
{
    // EARLY_LT((" | rc = 0x%p", rc)); // Commented to avoid too frequent logs

    EARLY_ASSERT(rc, "rc is null", NgosStatus::ASSERTION);



    if (rc->range < RC_TOP_VALUE)
    {
        rc->range <<= RC_SHIFT_BITS;
        rc->code  =   (rc->code << RC_SHIFT_BITS) + rc->in[rc->inPosition++];
    }



    return NgosStatus::OK;
}

// Decode one bit.
inline bool rcDecodeBit(LzmaRcDecoder *rc, u16 *prob)
{
    // EARLY_LT((" | rc = 0x%p, prob = 0x%p", rc, prob)); // Commented to avoid too frequent logs

    EARLY_ASSERT(rc,   "rc is null",   false);
    EARLY_ASSERT(prob, "prob is null", false);



    EARLY_ASSERT_EXECUTION(rcNormalize(rc), false);

    u32 bound = (rc->range >> RC_BIT_MODEL_TOTAL_BITS) * *prob;

    if (rc->code < bound)
    {
        rc->range = bound;

        *prob += (RC_BIT_MODEL_TOTAL - *prob) >> RC_MOVE_BITS;

        return false;
    }
    else
    {
        rc->range -= bound;
        rc->code  -= bound;

        *prob -= *prob >> RC_MOVE_BITS;

        return true;
    }
}

// Decode a bittree starting from the most significant bit.
inline u32 rcDecodeBitTree(LzmaRcDecoder *rc, u16 *probs, u32 limit)
{
    // EARLY_LT((" | rc = 0x%p, probs = 0x%p, limit = %u", rc, probs, limit)); // Commented to avoid too frequent logs

    EARLY_ASSERT(rc,    "rc is null",    0);
    EARLY_ASSERT(probs, "probs is null", 0);



    u32 symbol = 1;

    do
    {
        if (rcDecodeBit(rc, &probs[symbol]))
        {
            symbol = (symbol << 1) + 1;
        }
        else
        {
            symbol <<= 1;
        }
    } while(symbol < limit);

    return symbol;
}

// Decode a bittree starting from the least significant bit.
inline NgosStatus rcDecodeBitTreeReverse(LzmaRcDecoder *rc, u16 *probs, u32 *dest, u32 limit)
{
    // EARLY_LT((" | rc = 0x%p, probs = 0x%p, dest = 0x%p, limit = %u", rc, probs, dest, limit)); // Commented to avoid too frequent logs

    EARLY_ASSERT(rc,    "rc is null",    NgosStatus::ASSERTION);
    EARLY_ASSERT(probs, "probs is null", NgosStatus::ASSERTION);
    EARLY_ASSERT(dest,  "dest is null",  NgosStatus::ASSERTION);



    u32 symbol = 1;
    u32 i      = 0;

    do
    {
        if (rcDecodeBit(rc, &probs[symbol]))
        {
            symbol =  (symbol << 1) + 1;
            *dest  += (1ULL << i);
        }
        else
        {
            symbol <<= 1;
        }
    } while(++i < limit);



    return NgosStatus::OK;
}

// Decode direct bits (fixed fifty-fifty probability)
inline NgosStatus rcDecodeDirectBits(LzmaRcDecoder *rc, u32 *dest, u32 limit)
{
    // EARLY_LT((" | rc = 0x%p, dest = 0x%p, limit = %u", rc, dest, limit)); // Commented to avoid too frequent logs

    EARLY_ASSERT(rc,   "rc is null",   NgosStatus::ASSERTION);
    EARLY_ASSERT(dest, "dest is null", NgosStatus::ASSERTION);



    do
    {
        EARLY_ASSERT_EXECUTION(rcNormalize(rc), NgosStatus::ASSERTION);

        rc->range >>= 1;
        rc->code  -=  rc->range;

        u32 mask = (u32)0 - (rc->code >> 31);

        rc->code += rc->range & mask;
        *dest    =  (*dest << 1) + (mask + 1);
    } while(--limit > 0);



    return NgosStatus::OK;
}

// =======
// LZMA
// =======

// Indicate that the latest symbol was a Literal.
inline NgosStatus lzmaSetStateLiteral(LzmaState *state)
{
    // EARLY_LT((" | state = 0x%p", state)); // Commented to avoid too frequent logs

    EARLY_ASSERT(state, "state is null", NgosStatus::ASSERTION);



    if (*state <= LzmaState::SHORTREPEAT_LITERAL_LITERAL)
    {
        *state = LzmaState::LITERAL_LITERAL;
    }
    else
    if (*state <= LzmaState::LITERAL_SHORTREPEAT)
    {
        *state = (LzmaState)((u8)(*state) - 3);
    }
    else
    {
        *state = (LzmaState)((u8)(*state) - 6);
    }

    // EARLY_LVVV(("*state = %u (%s)", *state, lzmaStateToString(*state))); // Commented to avoid too frequent logs



    return NgosStatus::OK;
}

// Indicate that the latest symbol was a Match.
inline NgosStatus lzmaSetStateMatch(LzmaState *state)
{
    // EARLY_LT((" | state = 0x%p", state)); // Commented to avoid too frequent logs

    EARLY_ASSERT(state, "state is null", NgosStatus::ASSERTION);



    *state = (u8)(*state) < LITERAL_STATES ? LzmaState::LITERAL_MATCH : LzmaState::NONLITERAL_MATCH;

    // EARLY_LVVV(("*state = %u (%s)", *state, lzmaStateToString(*state))); // Commented to avoid too frequent logs



    return NgosStatus::OK;
}

// Indicate that the latest state was a Long repeated Match.
inline NgosStatus lzmaSetStateLongRepeat(LzmaState *state)
{
    // EARLY_LT((" | state = 0x%p", state)); // Commented to avoid too frequent logs

    EARLY_ASSERT(state, "state is null", NgosStatus::ASSERTION);



    *state = (u8)(*state) < LITERAL_STATES ? LzmaState::LITERAL_LONGREPEAT : LzmaState::NONLITERAL_REPEAT;

    // EARLY_LVVV(("*state = %u (%s)", *state, lzmaStateToString(*state))); // Commented to avoid too frequent logs



    return NgosStatus::OK;
}

// Indicate that the latest symbol was a Short repeated Match.
inline NgosStatus lzmaSetStateShortRepeat(LzmaState *state)
{
    // EARLY_LT((" | state = 0x%p", state)); // Commented to avoid too frequent logs

    EARLY_ASSERT(state, "state is null", NgosStatus::ASSERTION);



    *state = (u8)(*state) < LITERAL_STATES ? LzmaState::LITERAL_SHORTREPEAT : LzmaState::NONLITERAL_REPEAT;

    // EARLY_LVVV(("*state = %u (%s)", *state, lzmaStateToString(*state))); // Commented to avoid too frequent logs



    return NgosStatus::OK;
}

// Test if the previous symbol was a Literal.
inline bool lzmaIsLiteralState(LzmaState state)
{
    // EARLY_LT((" | state = %u", state)); // Commented to avoid too frequent logs



    return (u8)state < LITERAL_STATES;
}

// Get the index of the appropriate probability array for decoding
// the distance slot.
inline u32 lzmaGetDistanceState(u32 length)
{
    // EARLY_LT((" | length = %u", length)); // Commented to avoid too frequent logs

    return length < DIST_STATES + MATCH_LEN_MIN ? length - MATCH_LEN_MIN : DIST_STATES - 1;
}

// Get pointer to Literal coder probability array.
u16 *lzmaLiteralProbs(XzLzma2Decoder *decoder)
{
    // EARLY_LT((" | decoder = 0x%p", decoder)); // Commented to avoid too frequent logs

    EARLY_ASSERT(decoder, "decoder is null", 0);



    u32 previousByte = dictionaryGet(&decoder->dictionary, 0);

    u32 low  = previousByte >> (8 - decoder->lzma.lc);
    u32 high = (decoder->dictionary.position & decoder->lzma.literalPositionMask) << decoder->lzma.lc;

    return decoder->lzma.literal[low + high];
}

// Decode a Literal (one 8-bit byte)
NgosStatus lzmaDecodeLiteral(XzLzma2Decoder *decoder)
{
    // EARLY_LT((" | decoder = 0x%p", decoder)); // Commented to avoid too frequent logs

    EARLY_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    u16 *probs;
    u32  symbol;
    u32  matchByte;
    u32  matchBit;
    u32  offset;
    u32  i;



    probs = lzmaLiteralProbs(decoder);

    if (lzmaIsLiteralState(decoder->lzma.state))
    {
        symbol = rcDecodeBitTree(&decoder->rc, probs, 0x0100);
    }
    else
    {
        symbol    = 1;
        matchByte = dictionaryGet(&decoder->dictionary, decoder->lzma.repeat0) << 1;
        offset    = 0x0100;

        do
        {
            matchBit  =   matchByte & offset;
            matchByte <<= 1;

            i = offset + matchBit + symbol;

            if (rcDecodeBit(&decoder->rc, &probs[i]))
            {
                symbol =  (symbol << 1) + 1;
                offset &= matchBit;
            }
            else
            {
                symbol <<= 1;
                offset &=  ~matchBit;
            }
        } while(symbol < 0x0100);
    }



    EARLY_ASSERT_EXECUTION(dictionaryPut(&decoder->dictionary, (u8)symbol), NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(lzmaSetStateLiteral(&decoder->lzma.state),       NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

// Decode the length of the Match into decoder->lzma.length.
NgosStatus lzmaDecodeLength(XzLzma2Decoder *decoder, LzmaLengthDecoder *lengthDecoder, u32 positionState)
{
    // EARLY_LT((" | decoder = 0x%p, lengthDecoder = 0x%p, positionState = %u", decoder, lengthDecoder, positionState)); // Commented to avoid too frequent logs

    EARLY_ASSERT(decoder,       "decoder is null",       NgosStatus::ASSERTION);
    EARLY_ASSERT(lengthDecoder, "lengthDecoder is null", NgosStatus::ASSERTION);



    u16 *probs;
    u32  limit;

    if (!rcDecodeBit(&decoder->rc, &lengthDecoder->choice))
    {
        probs                = lengthDecoder->low[positionState];
        limit                = LEN_LOW_SYMBOLS;
        decoder->lzma.length = MATCH_LEN_MIN;
    }
    else
    {
        if (!rcDecodeBit(&decoder->rc, &lengthDecoder->choice2))
        {
            probs                = lengthDecoder->mid[positionState];
            limit                = LEN_MID_SYMBOLS;
            decoder->lzma.length = MATCH_LEN_MIN + LEN_LOW_SYMBOLS;
        }
        else
        {
            probs                = lengthDecoder->high;
            limit                = LEN_HIGH_SYMBOLS;
            decoder->lzma.length = MATCH_LEN_MIN + LEN_LOW_SYMBOLS + LEN_MID_SYMBOLS;
        }
    }

    decoder->lzma.length += rcDecodeBitTree(&decoder->rc, probs, limit) - limit;



    return NgosStatus::OK;
}

// Decode a Match. The distance will be stored in decoder->lzma.repeat0.
NgosStatus lzmaDecodeMatch(XzLzma2Decoder *decoder, u32 positionState)
{
    // EARLY_LT((" | decoder = 0x%p, positionState = %u", decoder, positionState)); // Commented to avoid too frequent logs

    EARLY_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    u16 *probs;
    u32  distanceSlot;
    u32  limit;

    EARLY_ASSERT_EXECUTION(lzmaSetStateMatch(&decoder->lzma.state), NgosStatus::ASSERTION);

    decoder->lzma.repeat3 = decoder->lzma.repeat2;
    decoder->lzma.repeat2 = decoder->lzma.repeat1;
    decoder->lzma.repeat1 = decoder->lzma.repeat0;

    EARLY_ASSERT_EXECUTION(lzmaDecodeLength(decoder, &decoder->lzma.matchLengthDecoder, positionState), NgosStatus::ASSERTION);

    probs        = decoder->lzma.distanceSlot[lzmaGetDistanceState(decoder->lzma.length)];
    distanceSlot = rcDecodeBitTree(&decoder->rc, probs, DIST_SLOTS) - DIST_SLOTS;

    if (distanceSlot < DIST_MODEL_START)
    {
        decoder->lzma.repeat0 = distanceSlot;
    }
    else
    {
        limit                 = (distanceSlot >> 1) - 1;
        decoder->lzma.repeat0 = 2 + (distanceSlot & 1);

        if (distanceSlot < DIST_MODEL_END)
        {
            decoder->lzma.repeat0 <<= limit;

            probs = decoder->lzma.distanceSpecial + decoder->lzma.repeat0 - distanceSlot - 1;

            EARLY_ASSERT_EXECUTION(rcDecodeBitTreeReverse(&decoder->rc, probs, &decoder->lzma.repeat0, limit), NgosStatus::ASSERTION);
        }
        else
        {
            EARLY_ASSERT_EXECUTION(rcDecodeDirectBits(&decoder->rc, &decoder->lzma.repeat0, limit - ALIGN_BITS), NgosStatus::ASSERTION);

            decoder->lzma.repeat0 <<= ALIGN_BITS;

            EARLY_ASSERT_EXECUTION(rcDecodeBitTreeReverse(&decoder->rc, decoder->lzma.distanceAlign, &decoder->lzma.repeat0, ALIGN_BITS), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

// Decode a repeated Match. The distance is one of the four most recently
// seen Matches. The distance will be stored in decoder->lzma.repeat0.
NgosStatus lzmaDecodeRepeatedMatch(XzLzma2Decoder *decoder, u32 positionState)
{
    // EARLY_LT((" | decoder = 0x%p, positionState = %u", decoder, positionState)); // Commented to avoid too frequent logs

    EARLY_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    if (!rcDecodeBit(&decoder->rc, &decoder->lzma.isRepeat0[(u8)(decoder->lzma.state)]))
    {
        if (!rcDecodeBit(&decoder->rc, &decoder->lzma.isRepeat0Long[(u8)(decoder->lzma.state)][positionState]))
        {
            EARLY_ASSERT_EXECUTION(lzmaSetStateShortRepeat(&decoder->lzma.state), NgosStatus::ASSERTION);

            decoder->lzma.length = 1;

            return NgosStatus::OK;
        }
    }
    else
    {
        u32 temp;

        if (!rcDecodeBit(&decoder->rc, &decoder->lzma.isRepeat1[(u8)(decoder->lzma.state)]))
        {
            temp = decoder->lzma.repeat1;
        }
        else
        {
            if (!rcDecodeBit(&decoder->rc, &decoder->lzma.isRepeat2[(u8)(decoder->lzma.state)]))
            {
                temp = decoder->lzma.repeat2;
            }
            else
            {
                temp                  = decoder->lzma.repeat3;
                decoder->lzma.repeat3 = decoder->lzma.repeat2;
            }

            decoder->lzma.repeat2 = decoder->lzma.repeat1;
        }

        decoder->lzma.repeat1 = decoder->lzma.repeat0;
        decoder->lzma.repeat0 = temp;
    }



    EARLY_ASSERT_EXECUTION(lzmaSetStateLongRepeat(&decoder->lzma.state),                                 NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(lzmaDecodeLength(decoder, &decoder->lzma.repeatLengthDecoder, positionState), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

// LZMA decoder core
NgosStatus lzmaMain(XzLzma2Decoder *decoder)
{
    EARLY_LT((" | decoder = 0x%p", decoder));

    EARLY_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    // If the dictionary was reached during the previous call, try to
    // finish the possibly pending repeat in the dictionary.
    if (dictionaryHasSpace(&decoder->dictionary) && decoder->lzma.length > 0)
    {
        EARLY_ASSERT_EXECUTION(dictionaryRepeat(&decoder->dictionary, &decoder->lzma.length, decoder->lzma.repeat0), NgosStatus::ASSERTION);
    }



    // Decode more LZMA symbols. One iteration may consume up to
    // LZMA_IN_REQUIRED - 1 bytes.
    while (dictionaryHasSpace(&decoder->dictionary) && !rcLimitExceeded(&decoder->rc))
    {
        u32 positionState = decoder->dictionary.position & decoder->lzma.positionMask;

        if (!rcDecodeBit(&decoder->rc, &decoder->lzma.isMatch[(u8)(decoder->lzma.state)][positionState]))
        {
            EARLY_ASSERT_EXECUTION(lzmaDecodeLiteral(decoder), NgosStatus::ASSERTION);
        }
        else
        {
            if (rcDecodeBit(&decoder->rc, &decoder->lzma.isRepeat[(u8)(decoder->lzma.state)]))
            {
                EARLY_ASSERT_EXECUTION(lzmaDecodeRepeatedMatch(decoder, positionState), NgosStatus::ASSERTION);
            }
            else
            {
                EARLY_ASSERT_EXECUTION(lzmaDecodeMatch(decoder, positionState), NgosStatus::ASSERTION);
            }

            if (dictionaryRepeat(&decoder->dictionary, &decoder->lzma.length, decoder->lzma.repeat0) != NgosStatus::OK)
            {
                return NgosStatus::FAILED;
            }
        }
    }



    // Having the range decoder always normalized when we are outside
    // this function makes it easier to correctly handle end of the chunk.
    EARLY_ASSERT_EXECUTION(rcNormalize(&decoder->rc), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

// Reset the LZMA decoder and range decoder state. Dictionary is nore reset
// here, because LZMA state may be reset without resetting the dictionary.
NgosStatus lzmaReset(XzLzma2Decoder *decoder)
{
    EARLY_LT((" | decoder = 0x%p", decoder));

    EARLY_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    decoder->lzma.state   = LzmaState::LITERAL_LITERAL;
    decoder->lzma.repeat0 = 0;
    decoder->lzma.repeat1 = 0;
    decoder->lzma.repeat2 = 0;
    decoder->lzma.repeat3 = 0;



    // All probabilities are initialized to the same value. This hack
    // makes the code smaller by avoiding a separate loop for each
    // probability array.
    //
    // This could be optimized so that only that part of Literal
    // probabilities that are actually required. In the common case
    // we would write 12 KiB less.
    u16 *probs = decoder->lzma.isMatch[0];

    for (i64 i = 0; i < (i64)PROBS_TOTAL; ++i)
    {
        probs[i] = RC_BIT_MODEL_TOTAL / 2;
    }



    EARLY_ASSERT_EXECUTION(rcReset(&decoder->rc), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

// Decode and validate LZMA properties (lc/lp/pb) and calculate the bit masks
// from the decoded lp and pb values. On success, the LZMA decoder state is
// reset and NgosStatus::OK is returned.
NgosStatus lzmaDecodeProperties(XzLzma2Decoder *decoder, u8 properties)
{
    EARLY_LT((" | decoder = 0x%p, properties = %u", decoder, properties));

    EARLY_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    if (properties > 224) // 224 == (4 * 5 + 4) * 9 + 8
    {
        return NgosStatus::INVALID_DATA;
    }



    decoder->lzma.positionMask = 0;

    while (properties >= 45) // 45 == 9 * 5
    {
        properties -= 45; // 45 == 9 * 5
        ++decoder->lzma.positionMask;
    }

    decoder->lzma.positionMask        = (1ULL << decoder->lzma.positionMask) - 1;
    decoder->lzma.literalPositionMask = 0;



    while (properties >= 9)
    {
        properties -= 9;
        ++decoder->lzma.literalPositionMask;
    }

    decoder->lzma.lc = properties;



    if (decoder->lzma.lc + decoder->lzma.literalPositionMask > 4)
    {
        return NgosStatus::INVALID_DATA;
    }

    decoder->lzma.literalPositionMask = (1ULL << decoder->lzma.literalPositionMask) - 1;



    EARLY_ASSERT_EXECUTION(lzmaReset(decoder), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

// ========
// LZMA2
// ========

// The LZMA decoder assumes that if the input limit (decoder->rc.inLimit) hasn't
// been exceeded, it is safe to read up to LZMA_IN_REQUIRED bytes. This
// wrapper function takes care of making the LZMA decoder's assumption safe.
//
// Since there is plenty of input left to be decoded in the current LZMA
// chunk, we decode directly from the caller-supplied input buffer until
// there's LZMA_IN_REQUIRED bytes left. Those remaining bytes are copied into
// decoder->temp.buffer, which (hopefully) gets filled on the next call to this
// function. We decode a few bytes from the temporary buffer so that we can
// continue decoding from the caller-supplied input buffer again.
NgosStatus lzma2DecodeLzma(XzLzma2Decoder *decoder, XzBuffer *buffer)
{
    EARLY_LT((" | decoder = 0x%p, buffer = 0x%p", decoder, buffer));

    EARLY_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    EARLY_ASSERT(buffer,  "buffer is null",  NgosStatus::ASSERTION);



    u64 bytesAvailable = buffer->inSize - buffer->inPosition;

    if (decoder->temp.size > 0 || decoder->lzma2.compressed == 0)
    {
        u32 temp = 2 * LZMA_IN_REQUIRED - decoder->temp.size;

        if (temp > decoder->lzma2.compressed - decoder->temp.size)
        {
            temp = decoder->lzma2.compressed - decoder->temp.size;
        }

        if (temp > bytesAvailable)
        {
            temp = bytesAvailable;
        }



        memcpy(decoder->temp.buffer + decoder->temp.size, buffer->in + buffer->inPosition, temp);



        if (decoder->temp.size + temp == decoder->lzma2.compressed)
        {
            memzero(decoder->temp.buffer + decoder->temp.size + temp, sizeof(decoder->temp.buffer) - decoder->temp.size - temp);

            decoder->rc.inLimit = decoder->temp.size + temp;
        }
        else
        if (decoder->temp.size + temp < LZMA_IN_REQUIRED)
        {
            decoder->temp.size += temp;
            buffer->inPosition += temp;

            return NgosStatus::OK;
        }
        else
        {
            decoder->rc.inLimit = decoder->temp.size + temp - LZMA_IN_REQUIRED;
        }



        decoder->rc.in         = decoder->temp.buffer;
        decoder->rc.inPosition = 0;



        if (
            lzmaMain(decoder) != NgosStatus::OK
            ||
            decoder->rc.inPosition > decoder->temp.size + temp
           )
        {
            return NgosStatus::FAILED;
        }



        decoder->lzma2.compressed -= decoder->rc.inPosition;



        if (decoder->rc.inPosition < decoder->temp.size)
        {
            decoder->temp.size -= decoder->rc.inPosition;

            memmove(decoder->temp.buffer, decoder->temp.buffer + decoder->rc.inPosition, decoder->temp.size);

            return NgosStatus::OK;
        }



        buffer->inPosition += decoder->rc.inPosition - decoder->temp.size;
        decoder->temp.size =  0;
    }



    bytesAvailable = buffer->inSize - buffer->inPosition;

    if (bytesAvailable >= LZMA_IN_REQUIRED)
    {
        decoder->rc.in         = buffer->in;
        decoder->rc.inPosition = buffer->inPosition;



        if (bytesAvailable >= decoder->lzma2.compressed + LZMA_IN_REQUIRED)
        {
            decoder->rc.inLimit = buffer->inPosition + decoder->lzma2.compressed;
        }
        else
        {
            decoder->rc.inLimit = buffer->inSize - LZMA_IN_REQUIRED;
        }



        if (lzmaMain(decoder) != NgosStatus::OK)
        {
            return NgosStatus::FAILED;
        }



        bytesAvailable = decoder->rc.inPosition - buffer->inPosition;

        if (bytesAvailable > decoder->lzma2.compressed)
        {
            return NgosStatus::INVALID_DATA;
        }



        decoder->lzma2.compressed -= bytesAvailable;
        buffer->inPosition        =  decoder->rc.inPosition;
    }



    bytesAvailable = buffer->inSize - buffer->inPosition;

    if (bytesAvailable < LZMA_IN_REQUIRED)
    {
        if (bytesAvailable > decoder->lzma2.compressed)
        {
            bytesAvailable = decoder->lzma2.compressed;
        }

        memcpy(decoder->temp.buffer, buffer->in + buffer->inPosition, bytesAvailable);

        decoder->temp.size =  bytesAvailable;
        buffer->inPosition += bytesAvailable;
    }



    return NgosStatus::OK;
}

// Take care of the LZMA2 control layer, and forward the job of actual LZMA
// decoding or copying of uncompressed chunks to other functions.
NgosStatus runXzLzma2Decoder(XzLzma2Decoder *decoder, XzBuffer *buffer)
{
    EARLY_LT((" | decoder = 0x%p, buffer = 0x%p", decoder, buffer));

    EARLY_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    EARLY_ASSERT(buffer,  "buffer is null",  NgosStatus::ASSERTION);



    u32 temp;

    while (buffer->inPosition < buffer->inSize || decoder->lzma2.sequence == Lzma2Sequence::SEQ_LZMA_RUN)
    {
        EARLY_LVVV(("buffer->inPosition      = %u", buffer->inPosition));
        EARLY_LVVV(("buffer->inSize          = %u", buffer->inSize));
        EARLY_LVVV(("decoder->lzma2.sequence = %s", enumToFullString(decoder->lzma2.sequence)));



        switch (decoder->lzma2.sequence)
        {
            case Lzma2Sequence::SEQ_CONTROL:
            {
                // LZMA2 control byte
                //
                // Exact values:
                //
                //   0x00   End marker
                //   0x01   Dictionary reset followed by
                //   |      an uncompressed chunk
                //   0x02   Uncompressed chunk (no dictionary reset)
                //
                // Highest three bits (decoder->control & 0xE0):
                //
                //   0xE0   Dictionary reset, new properties and state
                //   |      reset, followed by LZMA compressed chunk
                //   0xC0   New properties and state reset, followed
                //   |      by LZMA compressed chunk (no dictionary
                //   |      reset)
                //   0xA0   State reset using old properties,
                //   |      followed by LZMA compressed chunk (no
                //   |      dictionary reset)
                //   0x80   LZMA chunk (no dictionary or state reset)
                //
                // For LZMA compressed chunks, the lowest five bits
                // (decoder->control & 1F) are the highest bits of the
                // uncompressed size (bits 16-20).
                //
                // A new LZMA2 stream must begin with a dictionary
                // reset. The first LZMA chunk must set new
                // properties and reset the LZMA state.
                //
                // Values that don't match anything described above
                // are invalid and we return NgosStatus::INVALID_DATA.

                temp = buffer->in[buffer->inPosition++];

                EARLY_LVVV(("temp = 0x%02X", temp));

                if (temp == 0)
                {
                    return NgosStatus::OK;
                }

                if (temp >= 0xE0 || temp == 0x01)
                {
                    decoder->lzma2.needProperties      = true;
                    decoder->lzma2.needDictionaryReset = false;

                    EARLY_ASSERT_EXECUTION(dictionaryReset(&decoder->dictionary, buffer), NgosStatus::ASSERTION);
                }
                else
                if (decoder->lzma2.needDictionaryReset)
                {
                    return NgosStatus::INVALID_DATA;
                }

                if (temp >= 0x80)
                {
                    decoder->lzma2.uncompressed = (temp & 0x1F) << 16;
                    decoder->lzma2.sequence     = Lzma2Sequence::SEQ_UNCOMPRESSED_1;

                    if (temp >= 0xC0)
                    {
                        // When there are new properties,
                        // state reset is done at
                        // Lzma2Sequence::SEQ_PROPERTIES.

                        decoder->lzma2.needProperties = false;
                        decoder->lzma2.nextSequence   = Lzma2Sequence::SEQ_PROPERTIES;
                    }
                    else
                    if (decoder->lzma2.needProperties)
                    {
                        return NgosStatus::INVALID_DATA;
                    }
                    else
                    {
                        decoder->lzma2.nextSequence = Lzma2Sequence::SEQ_LZMA_PREPARE;

                        if (temp >= 0xA0)
                        {
                            EARLY_ASSERT_EXECUTION(lzmaReset(decoder), NgosStatus::ASSERTION);
                        }
                    }
                }
                else
                {
                    if (temp > 0x02)
                    {
                        return NgosStatus::INVALID_DATA;
                    }

                    decoder->lzma2.sequence     = Lzma2Sequence::SEQ_COMPRESSED_0;
                    decoder->lzma2.nextSequence = Lzma2Sequence::SEQ_COPY;
                }
            }
            break;

            case Lzma2Sequence::SEQ_UNCOMPRESSED_1:
            {
                decoder->lzma2.uncompressed += (u32)buffer->in[buffer->inPosition++] << 8;
                decoder->lzma2.sequence     =  Lzma2Sequence::SEQ_UNCOMPRESSED_2;
            }
            break;

            case Lzma2Sequence::SEQ_UNCOMPRESSED_2:
            {
                decoder->lzma2.uncompressed += (u32)buffer->in[buffer->inPosition++] + 1;
                decoder->lzma2.sequence     =  Lzma2Sequence::SEQ_COMPRESSED_0;
            }
            break;

            case Lzma2Sequence::SEQ_COMPRESSED_0:
            {
                decoder->lzma2.compressed = (u32)buffer->in[buffer->inPosition++] << 8;
                decoder->lzma2.sequence   = Lzma2Sequence::SEQ_COMPRESSED_1;
            }
            break;

            case Lzma2Sequence::SEQ_COMPRESSED_1:
            {
                decoder->lzma2.compressed += (u32)buffer->in[buffer->inPosition++] + 1;
                decoder->lzma2.sequence   =  decoder->lzma2.nextSequence;
            }
            break;

            case Lzma2Sequence::SEQ_PROPERTIES:
            {
                if (lzmaDecodeProperties(decoder, buffer->in[buffer->inPosition++]) != NgosStatus::OK)
                {
                    return NgosStatus::INVALID_DATA;
                }

                decoder->lzma2.sequence = Lzma2Sequence::SEQ_LZMA_PREPARE;
            }
            break;

            case Lzma2Sequence::SEQ_LZMA_PREPARE:
            {
                if (decoder->lzma2.compressed < RC_INIT_BYTES)
                {
                    return NgosStatus::INVALID_DATA;
                }

                if (!rcReadInit(&decoder->rc, buffer))
                {
                    return NgosStatus::OK;
                }

                decoder->lzma2.compressed -= RC_INIT_BYTES;
                decoder->lzma2.sequence   =  Lzma2Sequence::SEQ_LZMA_RUN;
            }
            break;

            case Lzma2Sequence::SEQ_LZMA_RUN:
            {
                // Set dictionary limit to indicate how much we want
                // to be encoded at maximum. Decode new data into the
                // dictionary. Flush the new data from dictionary to
                // buffer->out. Check if we finished decoding this chunk.
                // In case the dictionary got full but we didn't fill
                // the output buffer yet, we may run this loop
                // multiple times without changing decoder->lzma2.sequence.

                EARLY_ASSERT_EXECUTION(dictionaryLimit(&decoder->dictionary, MIN_TYPED(u64, buffer->outSize - buffer->outPosition, decoder->lzma2.uncompressed)), NgosStatus::ASSERTION);

                if (lzma2DecodeLzma(decoder, buffer) != NgosStatus::OK)
                {
                    return NgosStatus::INVALID_DATA;
                }

                decoder->lzma2.uncompressed -= dictionaryFlush(&decoder->dictionary, buffer);

                if (decoder->lzma2.uncompressed == 0)
                {
                    if (
                        decoder->lzma2.compressed > 0
                        ||
                        decoder->lzma.length > 0
                        ||
                        !rcIsFinished(&decoder->rc)
                       )
                    {
                        return NgosStatus::INVALID_DATA;
                    }

                    EARLY_ASSERT_EXECUTION(rcReset(&decoder->rc), NgosStatus::ASSERTION);
                    decoder->lzma2.sequence = Lzma2Sequence::SEQ_CONTROL;
                }
                else
                if (
                    buffer->outPosition == buffer->outSize
                    ||
                    (
                     buffer->inPosition == buffer->inSize
                     &&
                     decoder->temp.size < decoder->lzma2.compressed
                    )
                   )
                {
                    return NgosStatus::OK;
                }
            }
            break;

            case Lzma2Sequence::SEQ_COPY:
            {
                EARLY_ASSERT_EXECUTION(dictionaryUncompressed(&decoder->dictionary, buffer, &decoder->lzma2.compressed), NgosStatus::ASSERTION);

                if (decoder->lzma2.compressed > 0)
                {
                    return NgosStatus::OK;
                }

                decoder->lzma2.sequence = Lzma2Sequence::SEQ_CONTROL;
            }
            break;

            default:
            {
                EARLY_LF(("Unknown decoder->lzma2.sequence: %s, %s:%u", enumToFullString(decoder->lzma2.sequence), __FILE__, __LINE__));

                return NgosStatus::INVALID_DATA;
            }
            break;
        }
    }

    return NgosStatus::OK;
}



#endif
