#include "xzbcjdecoder.h"

#include <common/src/com/ngos/shared/common/early/earlyassert.h>
#include <common/src/com/ngos/shared/common/early/earlylog.h>
#include <common/src/com/ngos/shared/common/memory/memory.h>
#include <common/src/com/ngos/shared/common/ngos/utils.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



#define GET_UNALIGNED_LE32(pointer)        (*(u32 *)(pointer))
#define PUT_UNALIGNED_LE32(value, pointer) (*(u32 *)(pointer)) = (value)



#if NGOS_BUILD_ARCH == OPTION_ARCH_X86_64
// This is used to test the most significant byte of a memory address
// in an x86 instruction.
inline i32 bcjX86TestMsByte(u8 byte)
{
    // EARLY_LT((" | byte = 0x%02X", byte)); // Commented to avoid too frequent logs



    return !byte // byte == 0x00
            ||
            byte == 0xFF;
}

u64 bcjX86(XzBcjDecoder *decoder, u8 *buffer, u64 size)
{
    EARLY_LT((" | decoder = 0x%p, buffer = 0x%p, size = %u", decoder, buffer, size));

    EARLY_ASSERT(decoder,  "decoder is null", 0);
    EARLY_ASSERT(buffer,   "buffer is null",  0);
    EARLY_ASSERT(size > 0, "size is zero",    0);



    const bool maskToAllowedStatus[8] = { true, true, true, false, true, false, false, false };
    const u8   maskToBitNumber[8]     = { 0, 1, 2, 2, 3, 3, 3, 3 };

    u64 i;
    u64 previousPosition = (u64)-1;
    u32 previousMask     = decoder->x86PreviousMask;
    u32 src;
    u32 dest;
    u32 j;
    u8  byte;



    if (size <= 4)
    {
        return 0;
    }

    size -= 4;



    for (i = 0; i < size; ++i)
    {
        u8 flag = buffer[i] & 0xFE;

        if (flag != 0xE8)
        {
            continue;
        }



        previousPosition = i - previousPosition;

        if (previousPosition > 3)
        {
            previousMask = 0;
        }
        else
        {
            previousMask = (previousMask << (previousPosition - 1)) & 7;

            if (previousMask != 0)
            {
                byte = buffer[i + 4 - maskToBitNumber[previousMask]];

                if (
                    !maskToAllowedStatus[previousMask]
                    ||
                    bcjX86TestMsByte(byte)
                   )
                {
                    previousPosition = i;
                    previousMask     = (previousMask << 1) | 1;

                    continue;
                }
            }
        }



        previousPosition = i;

        if (bcjX86TestMsByte(buffer[i + 4]))
        {
            src = GET_UNALIGNED_LE32(buffer + i + 1);

            do
            {
                dest = src - ((u32)i + 5);

                if (previousMask == 0)
                {
                    break;
                }

                j    = maskToBitNumber[previousMask] * 8;
                byte = (u8)(dest >> (24 - j));

                if (!bcjX86TestMsByte(byte))
                {
                    break;
                }

                src = dest ^ ((1ULL << (32 - j)) - 1);
            } while(true);

            dest &= 0x01FFFFFF;
            dest |= (u32)0 - (dest & 0x01000000);

            PUT_UNALIGNED_LE32(dest, buffer + i + 1);

            i += 4;
        }
        else
        {
            previousMask = (previousMask << 1) | 1;
        }
    }

    previousPosition         = i - previousPosition;
    decoder->x86PreviousMask = previousPosition > 3 ? 0 : previousMask << (previousPosition - 1);

    return i;
}
#endif

NgosStatus runXzBcjDecoder(XzBcjDecoder *decoder, XzBuffer *buffer)
{
    EARLY_LT((" | decoder = 0x%p, buffer = 0x%p", decoder, buffer));

    EARLY_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    EARLY_ASSERT(buffer,  "buffer is null",  NgosStatus::ASSERTION);



#if NGOS_BUILD_ARCH == OPTION_ARCH_X86_64
    bcjX86(decoder, buffer->out, buffer->outSize);
#endif



    return NgosStatus::OK;
}



#endif
