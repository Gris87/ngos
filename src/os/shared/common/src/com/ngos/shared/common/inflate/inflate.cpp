#include "inflate.h"

#include <com/ngos/shared/common/inflate/inflateblocktype.h>
#include <com/ngos/shared/common/inflate/inflatecode.h>
#include <com/ngos/shared/common/inflate/inflatecodetype.h>
#include <com/ngos/shared/common/inflate/inflatedecoder.h>
#include <com/ngos/shared/common/inflate/inflatefixedcodes.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/common/string/utils.h>



#define LENGTH_BUFFER_COUNT 320
#define LENGTH_CODE_COUNT   19
#define CODES_COUNT         1024
#define MAX_BITS            15



inline u64 readBits(InflateDecoder *decoder, u8 count)
{
    // COMMON_LT((" | decoder = 0x%p, count = %u", decoder, count)); // Commented to avoid too frequent logs

    COMMON_ASSERT(decoder,   "decoder is null", 0);
    COMMON_ASSERT(count > 0, "count is zero",   0);



    while (decoder->temp.bitsAvailable < count)
    {
        decoder->temp.bitBuffer     |= decoder->in[decoder->inPosition] << decoder->temp.bitsAvailable;
        decoder->temp.bitsAvailable += 8;

        ++decoder->inPosition;
    }



    u64 res = decoder->temp.bitBuffer & ((1ULL << count) - 1);

    decoder->temp.bitBuffer     >>= count;
    decoder->temp.bitsAvailable -=  count;

    return res;
}

NgosStatus buildTree(InflateCodeType codeType, u16 *lengthBuffer, u32 numberOfCodes, InflateCode *table, u8 *bits)
{
    COMMON_LT((" | codeType = %d, lengthBuffer = 0x%p, numberOfCodes = %u, table = 0x%p, bits = 0x%p", codeType, lengthBuffer, numberOfCodes, table, bits));

    COMMON_ASSERT(lengthBuffer,      "lengthBuffer is null",  NgosStatus::ASSERTION);
    COMMON_ASSERT(numberOfCodes > 0, "numberOfCodes is zero", NgosStatus::ASSERTION);
    COMMON_ASSERT(table,             "table is null",         NgosStatus::ASSERTION);
    COMMON_ASSERT(bits,              "bits is null",          NgosStatus::ASSERTION);



    // Length codes 257..285 base
    static const u16 lengthCodesBase[31] =
    {
        3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31, 35,
        43, 51, 59, 67, 83, 99, 115, 131, 163, 195, 227, 258, 0, 0
    };

    // Length codes 257..285 extra
    static const u16 lengthCodesExtra[31] =
    {
        16, 16, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 18, 18, 18, 18,
        19, 19, 19, 19, 20, 20, 20, 20, 21, 21, 21, 21, 16, 201, 196
    };

    // Distance codes 0..29 base
    static const u16 distanceCodesBase[32] =
    {
        1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193, 257, 385, 513,
        769, 1025, 1537, 2049, 3073, 4097, 6145, 8193, 12289, 16385, 24577, 0, 0
    };

    // Distance codes 0..29 extra
    static const u16 distanceCodesExtra[32] =
    {
        16, 16, 16, 16, 17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22,
        23, 23, 24, 24, 25, 25, 26, 26, 27, 27, 28, 28, 29, 29, 64, 64
    };



    u16 count[MAX_BITS + 1];

    memzero(count, sizeof(count));

    for (i64 i = 0; i < numberOfCodes; ++i)
    {
        ++count[lengthBuffer[i]];
    }



#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
    {
        // Commented to avoid too frequent logs
        // COMMON_LVVV(("count:"));
        //
        // for (i64 i = 0; i <= MAX_BITS; ++i)
        // {
        //     COMMON_LVVV(("count[%d] = %u", i, count[i]));
        // }
    }
#endif



    u8 max = MAX_BITS;

    while (max >= 1 && count[max] == 0)
    {
        --max;
    }

    if (max == 0)
    {
        COMMON_LF(("Symbols to code not found"));

        return NgosStatus::INVALID_DATA;
    }



    u8 min = 1;

    while (min < MAX_BITS && count[min] == 0)
    {
        ++min;
    }



    u8 root = *bits;

    if (root > max)
    {
        root  = max;
        *bits = max;
    }
    else
    if (root < min)
    {
        root  = min;
        *bits = min;
    }



    // COMMON_LVVV(("root = %u", root)); // Commented to avoid too frequent logs
    // COMMON_LVVV(("min  = %u", min));  // Commented to avoid too frequent logs
    // COMMON_LVVV(("max  = %u", max));  // Commented to avoid too frequent logs



    i32 left = 1;

    for (i64 i = 1; i <= MAX_BITS; ++i)
    {
        left <<= 1;
        left -=  count[i];

        if (left < 0)
        {
            COMMON_LF(("Over-subscribed"));

            return NgosStatus::INVALID_DATA;
        }
    }



    // COMMON_LVVV(("left = %d", left)); // Commented to avoid too frequent logs



    if (
        left > 0
        &&
        (
         codeType == InflateCodeType::CODES
         ||
         max != 1
        )
       )
    {
        COMMON_LF(("Incomplete set"));

        return NgosStatus::INVALID_DATA;
    }



    u16 offsets[MAX_BITS + 1];



    offsets[1] = 0;

    for (i64 i = 1; i < MAX_BITS; ++i)
    {
        offsets[i + 1] = offsets[i] + count[i];
    }



    u16 work[288];

    for (i64 i = 0; i < numberOfCodes; ++i)
    {
        if (lengthBuffer[i] != 0)
        {
            u16 &offset = offsets[lengthBuffer[i]];

            work[offset] = i;
            ++offset;
        }
    }



#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
    {
        // Commented to avoid too frequent logs
        // COMMON_LVVV(("offsets:"));
        //
        // for (i64 i = 0; i <= MAX_BITS; ++i)
        // {
        //     COMMON_LVVV(("offsets[%d] = %u", i, offsets[i]));
        // }
    }
#endif



    const u16 *base;
    const u16 *extra;
    i32        end;

    switch (codeType)
    {
        case InflateCodeType::CODES:
        {
            base  = work;
            extra = work;
            end   = LENGTH_CODE_COUNT;
        }
        break;

        case InflateCodeType::LENGTHS:
        {
            base =  lengthCodesBase;
            base -= 257;

            extra =  lengthCodesExtra;
            extra -= 257;

            end = 256;
        }
        break;

        case InflateCodeType::DISTANCES:
        {
            base  = distanceCodesBase;
            extra = distanceCodesExtra;
            end   = -1;
        }
        break;

        default:
        {
            COMMON_LF(("Unknown code type: %d, %s:%u", codeType, __FILE__, __LINE__));

            return NgosStatus::UNEXPECTED_BEHAVIOUR;
        }
        break;
    }



    // COMMON_LVVV(("base  = 0x%p", base));  // Commented to avoid too frequent logs
    // COMMON_LVVV(("extra = 0x%p", extra)); // Commented to avoid too frequent logs
    // COMMON_LVVV(("end   = %d",   end));   // Commented to avoid too frequent logs



    u32 huff = 0;
    u32 sym  = 0;
    u32 len  = min;
    u32 curr = root;
    u32 drop = 0;
    u32 low  = -1;
    u32 mask = (1ULL << root) - 1;



    InflateCode *next = table;
    InflateCode  currentCode;

    do
    {
        // create table entry
        currentCode.bits = len - drop;

        if ((i32)work[sym] < end)
        {
            currentCode.operation = 0;
            currentCode.value     = work[sym];
        }
        else
        if ((i32)work[sym] > end)
        {
            currentCode.operation = extra[work[sym]];
            currentCode.value     = base[work[sym]];
        }
        else
        {
            // end of block
            currentCode.operation = 96; // 32 + 64;
            currentCode.value     = 0;
        }



        // replicate for those indices with low len bits equal to huff
        u32 incr = (1ULL << (len - drop));
        u32 fill = (1ULL << curr);

        // save offset to next table
        u32 temp = fill;

        do
        {
            fill -= incr;

            next[(huff >> drop) + fill] = currentCode;
        } while(fill != 0);



        // backwards increment the len-bit code huff
        incr = (1ULL << (len - 1));

        while (huff & incr)
        {
            incr >>= 1;
        }



        if (incr != 0)
        {
            huff &= incr - 1;
            huff += incr;
        }
        else
        {
            huff = 0;
        }



        // go to next symbol, update count, len
        ++sym;



        --count[len];

        if (count[len] == 0)
        {
            if (len == max)
            {
                break;
            }

            len = lengthBuffer[work[sym]];
        }



        // create new sub-table if needed
        if (len > root && (huff & mask) != low)
        {
            // if first time, transition to sub-tables
            if (drop == 0)
            {
                drop = root;
            }



            // increment past last table
            next += temp;



            // determine length of next table
            curr = len - drop;
            left = (1ULL << curr);

            while (curr + drop < max)
            {
                left -= count[curr + drop];

                if (left <= 0)
                {
                    break;
                }

                curr++;
                left <<= 1;
            }



            // point entry in root table to sub-table
            low = huff & mask;



            InflateCode &entry = table[low];

            entry.operation = curr;
            entry.bits      = root;
            entry.value     = next - table;
        }
    } while(true);



    // Fill in rest of table for incomplete codes. This loop is similar to the
    // loop above in incrementing huff for table indices. It is assumed that
    // len is equal to curr + drop, so there is no loop needed to increment
    // through high index bits. When the current sub-table is filled, the loop
    // drops back to the root table to fill in any remaining entries there.
    //
    currentCode.operation = 64;                // invalid code marker
    currentCode.bits      = len - drop;
    currentCode.value     = 0;

    while (huff != 0)
    {
        // when done with sub-table, drop back to root table
        if (
            drop != 0
            &&
            (huff & mask) != low
           )
        {
            drop = 0;
            len  = root;
            next = table;

            currentCode.bits = len;
        }



        // put invalid code marker in table
        next[huff >> drop] = currentCode;



        // backwards increment the len-bit code huff
        u32 incr = (1ULL << (len - 1));

        while (huff & incr)
        {
            incr >>= 1;
        }

        if (incr != 0)
        {
            huff &= incr - 1;
            huff += incr;
        }
        else
        {
            huff = 0;
        }
    }



    return NgosStatus::OK;
}

NgosStatus decodeHuffmanBlock(InflateDecoder *decoder, InflateCode *lengthCodes, u8 lengthBits, InflateCode *distanceCodes, u8 distanceBits)
{
    COMMON_LT((" | decoder = 0x%p, lengthCodes = 0x%p, lengthBits = %u, distanceCodes = 0x%p, distanceBits = %u", decoder, lengthCodes, lengthBits, distanceCodes, distanceBits));

    COMMON_ASSERT(decoder,          "decoder is null",       NgosStatus::ASSERTION);
    COMMON_ASSERT(lengthCodes,      "lengthCodes is null",   NgosStatus::ASSERTION);
    COMMON_ASSERT(lengthBits > 0,   "lengthBits is zero",    NgosStatus::ASSERTION);
    COMMON_ASSERT(distanceCodes,    "distanceCodes is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(distanceBits > 0, "distanceBits is zero",  NgosStatus::ASSERTION);



    do
    {
        u16         codeIndex;
        InflateCode code;

        do
        {
            codeIndex = decoder->temp.bitBuffer & ((1ULL << lengthBits) - 1);
            code      = lengthCodes[codeIndex];

            if (code.bits <= decoder->temp.bitsAvailable)
            {
                break;
            }

            decoder->temp.bitBuffer     |= decoder->in[decoder->inPosition] << decoder->temp.bitsAvailable;
            decoder->temp.bitsAvailable += 8;

            ++decoder->inPosition;
        } while(true);



        if (
            code.operation
            &&
            (code.operation & 0xF0) == 0
           )
        {
            InflateCode tempCode = code;

            do
            {
                u8 bitsNeeded = tempCode.bits + tempCode.operation;

                codeIndex = tempCode.value + ((decoder->temp.bitBuffer & ((1ULL << bitsNeeded) - 1)) >> tempCode.bits);
                code      = lengthCodes[codeIndex];

                if (tempCode.bits + code.bits <= decoder->temp.bitsAvailable)
                {
                    break;
                }

                decoder->temp.bitBuffer     |= decoder->in[decoder->inPosition] << decoder->temp.bitsAvailable;
                decoder->temp.bitsAvailable += 8;

                ++decoder->inPosition;
            } while(true);



            readBits(decoder, tempCode.bits);
        }



        // COMMON_LVVV(("codeIndex        = %u", codeIndex));      // Commented to avoid too frequent logs
        // COMMON_LVVV(("code.operation   = %u", code.operation)); // Commented to avoid too frequent logs
        // COMMON_LVVV(("code.bits        = %u", code.bits));      // Commented to avoid too frequent logs
        // COMMON_LVVV(("code.value       = %u", code.value));     // Commented to avoid too frequent logs



        readBits(decoder, code.bits);



        if (code.operation & 32)
        {
            return NgosStatus::OK;
        }



        COMMON_ASSERT(!(code.operation & 64), "Invalid literal/length code", NgosStatus::ASSERTION);



        if (code.operation == 0)
        {
            decoder->out[decoder->outPosition] = code.value;
            ++decoder->outPosition;
        }
        else
        {
            u16 length = code.value;
            u8  extra  = code.operation & 15;

            if (extra != 0)
            {
                length += readBits(decoder, extra);
            }

            // COMMON_LVVV(("length = %u", length)); // Commented to avoid too frequent logs
            // COMMON_LVVV(("extra  = %u", extra));  // Commented to avoid too frequent logs



            do
            {
                codeIndex = decoder->temp.bitBuffer & ((1ULL << distanceBits) - 1);
                code      = distanceCodes[codeIndex];

                if (code.bits <= decoder->temp.bitsAvailable)
                {
                    break;
                }

                decoder->temp.bitBuffer     |= decoder->in[decoder->inPosition] << decoder->temp.bitsAvailable;
                decoder->temp.bitsAvailable += 8;

                ++decoder->inPosition;
            } while(true);



            if ((code.operation & 0xF0) == 0)
            {
                InflateCode tempCode = code;

                do
                {
                    u8 bitsNeeded = tempCode.bits + tempCode.operation;

                    codeIndex = tempCode.value + ((decoder->temp.bitBuffer & ((1ULL << bitsNeeded) - 1)) >> tempCode.bits);
                    code      = distanceCodes[codeIndex];

                    if (tempCode.bits + code.bits <= decoder->temp.bitsAvailable)
                    {
                        break;
                    }

                    decoder->temp.bitBuffer     |= decoder->in[decoder->inPosition] << decoder->temp.bitsAvailable;
                    decoder->temp.bitsAvailable += 8;

                    ++decoder->inPosition;
                } while(true);



                readBits(decoder, tempCode.bits);
            }



            // COMMON_LVVV(("codeIndex        = %u", codeIndex));      // Commented to avoid too frequent logs
            // COMMON_LVVV(("code.operation   = %u", code.operation)); // Commented to avoid too frequent logs
            // COMMON_LVVV(("code.bits        = %u", code.bits));      // Commented to avoid too frequent logs
            // COMMON_LVVV(("code.value       = %u", code.value));     // Commented to avoid too frequent logs



            readBits(decoder, code.bits);



            COMMON_ASSERT(!(code.operation & 64), "Invalid literal/length code", NgosStatus::ASSERTION);



            u16 offset = code.value;
            u8  extra2 = code.operation & 15;

            if (extra2 != 0)
            {
                offset += readBits(decoder, extra2);
            }

            // COMMON_LVVV(("offset = %u", offset)); // Commented to avoid too frequent logs
            // COMMON_LVVV(("extra  = %u", extra));  // Commented to avoid too frequent logs



            COMMON_ASSERT(offset > 0 && offset <= decoder->outPosition, "offset is too big", NgosStatus::ASSERTION);



            if (offset == 1)
            {
                memset(decoder->out + decoder->outPosition, decoder->out[decoder->outPosition - 1], length);
                decoder->outPosition += length;
            }
            else
            {
                do
                {
                    u16 copyCount = offset < length ? offset : length;

                    memcpy(decoder->out + decoder->outPosition, decoder->out + decoder->outPosition - offset, copyCount);

                    decoder->outPosition += copyCount;
                    length               -= copyCount;
                } while(length != 0);
            }
        }
    } while(true);



    return NgosStatus::OK;
}

NgosStatus decodeNotCompressedBlock(InflateDecoder *decoder)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    u16 length  = *(u16 *)(decoder->in + decoder->inPosition);
    u16 nlength = *(u16 *)(decoder->in + decoder->inPosition + 2);

    // COMMON_LVVV(("length  = %u", length));  // Commented to avoid too frequent logs
    // COMMON_LVVV(("nlength = %u", nlength)); // Commented to avoid too frequent logs



    if (length != (nlength ^ 0xFFFF))   // nlength is the inverted length value
    {
        COMMON_LF(("Invalid not compressed length %u and nlength %u", length, nlength));

        return NgosStatus::INVALID_DATA;
    }



    decoder->temp.bitBuffer     =  0;
    decoder->temp.bitsAvailable =  0;
    decoder->inPosition         += 4;



    if (length > 0)
    {
        memcpy(decoder->out + decoder->outPosition, decoder->in + decoder->inPosition, length);

        decoder->inPosition  += length;
        decoder->outPosition += length;
    }
    else
    {
        COMMON_LF(("Unexpected length value"));

        return NgosStatus::UNEXPECTED_BEHAVIOUR;
    }



    return NgosStatus::OK;
}

NgosStatus decodeCompressedFixedHuffmanBlock(InflateDecoder *decoder)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    if (decodeHuffmanBlock(decoder, fixedLengthCodes, 9, fixedDistanceCodes, 5) != NgosStatus::OK)
    {
        COMMON_LF(("Failed to decode Huffman block"));

        return NgosStatus::FAILED;
    }

    return NgosStatus::OK;
}

NgosStatus decodeCompressedDynamicHuffmanBlock(InflateDecoder *decoder)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    // Permutation of code lengths
    static const u8 order[LENGTH_CODE_COUNT] = { 16, 17, 18, 0, 8, 7, 9, 6, 10, 5, 11, 4, 12, 3, 13, 2, 14, 1, 15 };



    u16 numberOfLength   = 257 + readBits(decoder, 5); // 257-288
    u8  numberOfDistance = 1   + readBits(decoder, 5); // 1-32
    u8  numberOfCodes    = 4   + readBits(decoder, 4); // 4-19

    // COMMON_LVVV(("numberOfLength   = %u", numberOfLength));   // Commented to avoid too frequent logs
    // COMMON_LVVV(("numberOfDistance = %u", numberOfDistance)); // Commented to avoid too frequent logs
    // COMMON_LVVV(("numberOfCodes    = %u", numberOfCodes));    // Commented to avoid too frequent logs



    if (numberOfLength > 286 || numberOfDistance > 30)
    {
        COMMON_LF(("Too many length or distance symbols"));

        return NgosStatus::INVALID_DATA;
    }



    u16 lengthBuffer[LENGTH_BUFFER_COUNT];



    u16 currentCodeIndex = 0;

    while (currentCodeIndex < numberOfCodes)
    {
        lengthBuffer[order[currentCodeIndex]] = readBits(decoder, 3);

        // COMMON_LVVV(("currentCodeIndex = %u, lengthBuffer[%u] = %u", currentCodeIndex, order[currentCodeIndex], lengthBuffer[order[currentCodeIndex]])); // Commented to avoid too frequent logs

        ++currentCodeIndex;
    }

    while (currentCodeIndex < LENGTH_CODE_COUNT)
    {
        lengthBuffer[order[currentCodeIndex]] = 0;

        // COMMON_LVVV(("currentCodeIndex = %u, lengthBuffer[%u] = %u", currentCodeIndex, order[currentCodeIndex], lengthBuffer[order[currentCodeIndex]])); // Commented to avoid too frequent logs

        ++currentCodeIndex;
    }



#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
    {
        // Commented to avoid too frequent logs
        // COMMON_LVVV(("lengthBuffer:"));
        //
        // for (i64 i = 0; i < LENGTH_CODE_COUNT; ++i)
        // {
        //     COMMON_LVVV(("lengthBuffer[%d] = %u", i, lengthBuffer[i]));
        // }
    }
#endif



    InflateCode lengthCodes[CODES_COUNT];

    u8 lengthBits = 7;

    if (buildTree(InflateCodeType::CODES, lengthBuffer, LENGTH_CODE_COUNT, lengthCodes, &lengthBits) != NgosStatus::OK)
    {
        COMMON_LF(("Invalid code lengths set"));

        return NgosStatus::INVALID_DATA;
    }

    // COMMON_LVVV(("lengthBits = %u", lengthBits)); // Commented to avoid too frequent logs



    currentCodeIndex = 0;

    while (currentCodeIndex < numberOfLength + numberOfDistance)
    {
        u16         codeIndex;
        InflateCode code;

        do
        {
            codeIndex = decoder->temp.bitBuffer & ((1ULL << lengthBits) - 1);
            code      = lengthCodes[codeIndex];

            if (code.bits <= decoder->temp.bitsAvailable)
            {
                break;
            }

            decoder->temp.bitBuffer     |= decoder->in[decoder->inPosition] << decoder->temp.bitsAvailable;
            decoder->temp.bitsAvailable += 8;

            ++decoder->inPosition;
        } while(true);

        // COMMON_LVVV(("currentCodeIndex = %u", currentCodeIndex)); // Commented to avoid too frequent logs
        // COMMON_LVVV(("codeIndex        = %u", codeIndex));        // Commented to avoid too frequent logs
        // COMMON_LVVV(("code.operation   = %u", code.operation));   // Commented to avoid too frequent logs
        // COMMON_LVVV(("code.bits        = %u", code.bits));        // Commented to avoid too frequent logs
        // COMMON_LVVV(("code.value       = %u", code.value));       // Commented to avoid too frequent logs



        readBits(decoder, code.bits);



        if (code.value < 16)
        {
            lengthBuffer[currentCodeIndex] = code.value;

            ++currentCodeIndex;
        }
        else
        if (code.value == 16)
        {
            if (currentCodeIndex == 0)
            {
                COMMON_LF(("Invalid bit length repeat"));

                return NgosStatus::INVALID_DATA;
            }



            u16 length    = lengthBuffer[currentCodeIndex - 1];
            u8  copyCount = 3 + readBits(decoder, 2);           // 3-6

            if (currentCodeIndex + copyCount > numberOfLength + numberOfDistance)
            {
                COMMON_LF(("Invalid bit length repeat"));

                return NgosStatus::INVALID_DATA;
            }

            for (i64 i = 0; i < copyCount; ++i)
            {
                lengthBuffer[currentCodeIndex] = length;

                ++currentCodeIndex;
            }
        }
        else
        if (code.value == 17)
        {
            u8 copyCount = 3 + readBits(decoder, 3); // 3-10

            if (currentCodeIndex + copyCount > numberOfLength + numberOfDistance)
            {
                COMMON_LF(("Invalid bit length repeat"));

                return NgosStatus::INVALID_DATA;
            }

            memzero(&lengthBuffer[currentCodeIndex], copyCount * sizeof(lengthBuffer[0]));
            currentCodeIndex += copyCount;
        }
        else
        if (code.value == 18)
        {
            u8 copyCount = 11 + readBits(decoder, 7); // 11-138

            if (currentCodeIndex + copyCount > numberOfLength + numberOfDistance)
            {
                COMMON_LF(("Invalid bit length repeat"));

                return NgosStatus::INVALID_DATA;
            }

            memzero(&lengthBuffer[currentCodeIndex], copyCount * sizeof(lengthBuffer[0]));
            currentCodeIndex += copyCount;
        }
        else
        {
            COMMON_LF(("Invalid bit length"));

            return NgosStatus::INVALID_DATA;
        }
    }



    // COMMON_LVVV(("currentCodeIndex = %u", currentCodeIndex)); // Commented to avoid too frequent logs

    COMMON_ASSERT(currentCodeIndex == numberOfLength + numberOfDistance, "Invalid currentCodeIndex", NgosStatus::ASSERTION);



#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
    {
        // Commented to avoid too frequent logs
        // COMMON_LVVV(("lengthBuffer:"));
        //
        // for (i64 i = 0; i < currentCodeIndex; ++i)
        // {
        //     COMMON_LVVV(("lengthBuffer[%d] = %u", i, lengthBuffer[i]));
        // }
    }
#endif



    lengthBits = 9;

    if (buildTree(InflateCodeType::LENGTHS, lengthBuffer, numberOfLength, lengthCodes, &lengthBits) != NgosStatus::OK)
    {
        COMMON_LF(("invalid literal/lengths set"));

        return NgosStatus::INVALID_DATA;
    }

    // COMMON_LVVV(("lengthBits = %u", lengthBits)); // Commented to avoid too frequent logs



    InflateCode distanceCodes[CODES_COUNT];

    u8 distanceBits = 6;

    if (buildTree(InflateCodeType::DISTANCES, lengthBuffer + numberOfLength, numberOfDistance, distanceCodes, &distanceBits) != NgosStatus::OK)
    {
        COMMON_LF(("invalid distances set"));

        return NgosStatus::INVALID_DATA;
    }

    // COMMON_LVVV(("distanceBits = %u", distanceBits)); // Commented to avoid too frequent logs



    if (decodeHuffmanBlock(decoder, lengthCodes, lengthBits, distanceCodes, distanceBits) != NgosStatus::OK)
    {
        COMMON_LF(("Failed to decode Huffman block"));

        return NgosStatus::FAILED;
    }



    return NgosStatus::OK;
}

NgosStatus runInflate(InflateDecoder *decoder)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    do
    {
        bool             blockFinal = readBits(decoder, 1);                     // first bit      BFINAL  BFINAL is set if and only if this is the last block of the data set.
        InflateBlockType blockType  = (InflateBlockType)(readBits(decoder, 2)); // next 2 bits    BTYPE   BTYPE specifies how the data are compressed

        COMMON_LVVV(("blockFinal = %s", boolToString(blockFinal)));
        COMMON_LVVV(("blockType  = %s", enumToFullString(blockType)));



        switch (blockType)
        {
            case InflateBlockType::NO_COMPRESSION:
            {
                if (decodeNotCompressedBlock(decoder) != NgosStatus::OK)
                {
                    COMMON_LF(("Failed to decode not compressed block"));

                    return NgosStatus::FAILED;
                }
            }
            break;

            case InflateBlockType::COMPRESSED_FIXED_HUFFMAN:
            {
                if (decodeCompressedFixedHuffmanBlock(decoder) != NgosStatus::OK)
                {
                    COMMON_LF(("Failed to decode compressed fixed Huffman block"));

                    return NgosStatus::FAILED;
                }
            }
            break;

            case InflateBlockType::COMPRESSED_DYNAMIC_HUFFMAN:
            {
                if (decodeCompressedDynamicHuffmanBlock(decoder) != NgosStatus::OK)
                {
                    COMMON_LF(("Failed to decode compressed dynamic Huffman block"));

                    return NgosStatus::FAILED;
                }
            }
            break;

            default:
            {
                COMMON_LF(("Unexpected blockType: %s, %s:%u", enumToFullString(blockType), __FILE__, __LINE__));

                return NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;
        }



        if (blockFinal)
        {
            return NgosStatus::OK;
        }
    } while(true);



    return NgosStatus::FAILED;
}

NgosStatus inflate(u8 *compressedAddress, u8 *decompressedAddress, u64 *compressedSize, u64 *uncompressedSize)
{
    COMMON_LT((" | compressedAddress = 0x%p, decompressedAddress = 0x%p, compressedSize = 0x%p, uncompressedSize = 0x%p", compressedAddress, decompressedAddress, compressedSize, uncompressedSize));

    COMMON_ASSERT(compressedAddress,   "compressedAddress is null",   NgosStatus::ASSERTION);
    COMMON_ASSERT(decompressedAddress, "decompressedAddress is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(compressedSize,      "compressedSize is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(uncompressedSize,    "uncompressedSize is null",    NgosStatus::ASSERTION);



    InflateDecoder decoder;

    decoder.in                 = compressedAddress;
    decoder.inPosition         = 0;
    decoder.out                = decompressedAddress;
    decoder.outPosition        = 0;
    decoder.temp.bitBuffer     = 0;
    decoder.temp.bitsAvailable = 0;



    if (runInflate(&decoder) != NgosStatus::OK)
    {
        return NgosStatus::FAILED;
    }



    *compressedSize   = decoder.inPosition;
    *uncompressedSize = decoder.outPosition;



    return NgosStatus::OK;
}
