#include "xzfilterlzma2.h"

#include <com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzlzma2decoder.h>
#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>
#include <com/ngos/shared/common/ngos/linkage.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



NgosStatus filterLZMA2(bad_uint8 *compressedAddress, bad_uint8 *decompressedAddress, bad_uint64 sizeOfProperties, bad_uint8 *filterProperties, bad_uint64 *compressedSize, bad_uint64 *uncompressedSize)
{
    EARLY_LT((" | compressedAddress = 0x%p, decompressedAddress = 0x%p, sizeOfProperties = %u, filterProperties = 0x%p, compressedSize = 0x%p, uncompressedSize = 0x%p", compressedAddress, decompressedAddress, sizeOfProperties, filterProperties, compressedSize, uncompressedSize));

    AVOID_UNUSED(sizeOfProperties);

    EARLY_ASSERT(compressedAddress,     "compressedAddress is null",   NgosStatus::ASSERTION);
    EARLY_ASSERT(decompressedAddress,   "decompressedAddress is null", NgosStatus::ASSERTION);
    EARLY_ASSERT(sizeOfProperties == 1, "sizeOfProperties is invalid", NgosStatus::ASSERTION);
    EARLY_ASSERT(filterProperties,      "filterProperties is null",    NgosStatus::ASSERTION);
    EARLY_ASSERT(compressedSize,        "compressedSize is null",      NgosStatus::ASSERTION);
    EARLY_ASSERT(uncompressedSize,      "uncompressedSize is null",    NgosStatus::ASSERTION);



    bad_uint8 property = filterProperties[0] & 0x3F;

    EARLY_LVVV(("property = %u", property));

    if (property > 40)
    {
        EARLY_LF(("LZMA2 dictionary size is too big"));

        return NgosStatus::INVALID_DATA;
    }



    bad_uint32 dictionarySize = 0;

    if (property == 40)
    {
        dictionarySize = 0xFFFFFFFF;
    }
    else
    {
        dictionarySize =   2 | (property & 1);
        dictionarySize <<= (property / 2) + 11;
    }

    EARLY_LVVV(("dictionarySize = %u", dictionarySize));



    XzLzma2Decoder decoder;
    XzBuffer       xzBuffer;

    decoder.dictionary.size           = dictionarySize;
    decoder.lzma.length               = 0;
    decoder.lzma2.sequence            = Lzma2Sequence::SEQ_CONTROL;
    decoder.lzma2.needDictionaryReset = true;
    decoder.temp.size                 = 0;

    xzBuffer.in          = compressedAddress;
    xzBuffer.inPosition  = 0;
    xzBuffer.inSize      = (bad_uint64)-1;
    xzBuffer.out         = decompressedAddress;
    xzBuffer.outPosition = 0;
    xzBuffer.outSize     = (bad_uint64)-1;



    NgosStatus status = runXzLzma2Decoder(&decoder, &xzBuffer);

    if (status != NgosStatus::OK)
    {
        return status;
    }



    *compressedSize   = xzBuffer.inPosition;
    *uncompressedSize = xzBuffer.outPosition;



    return NgosStatus::OK;
}



#endif
