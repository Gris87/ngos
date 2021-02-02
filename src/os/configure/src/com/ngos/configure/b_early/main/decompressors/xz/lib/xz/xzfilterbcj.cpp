#include "xzfilterbcj.h"

#include <com/ngos/configure/b_early/main/decompressors/xz/lib/xz/xzbcjdecoder.h>
#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>
#include <com/ngos/shared/common/ngos/linkage.h>



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



NgosStatus filterBCJ(bad_uint8 *compressedAddress, bad_uint8 *decompressedAddress, bad_uint64 sizeOfProperties, bad_uint8 *filterProperties, bad_uint64 uncompressedSize)
{
    EARLY_LT((" | compressedAddress = 0x%p, decompressedAddress = 0x%p, sizeOfProperties = %u, filterProperties = 0x%p, uncompressedSize = %u", compressedAddress, decompressedAddress, sizeOfProperties, filterProperties, uncompressedSize));

    AVOID_UNUSED(sizeOfProperties);
    AVOID_UNUSED(filterProperties);

    EARLY_ASSERT(compressedAddress,    "compressedAddress is null",   NgosStatus::ASSERTION);
    EARLY_ASSERT(decompressedAddress,  "decompressedAddress is null", NgosStatus::ASSERTION);
    EARLY_ASSERT(!sizeOfProperties     // sizeOfProperties == 0
                ||
                sizeOfProperties == 4, "sizeOfProperties is invalid", NgosStatus::ASSERTION);
    EARLY_ASSERT(filterProperties,     "filterProperties is null",    NgosStatus::ASSERTION);
    EARLY_ASSERT(uncompressedSize > 0, "uncompressedSize is zero",    NgosStatus::ASSERTION);



    XzBcjDecoder decoder;
    XzBuffer     xzBuffer;

    decoder.x86PreviousMask = 0;

    xzBuffer.in          = compressedAddress;
    xzBuffer.inPosition  = 0;
    xzBuffer.inSize      = (bad_uint64)-1;
    xzBuffer.out         = decompressedAddress;
    xzBuffer.outPosition = 0;
    xzBuffer.outSize     = uncompressedSize;



    NgosStatus status = runXzBcjDecoder(&decoder, &xzBuffer);

    if (status != NgosStatus::OK)
    {
        return status;
    }

    return NgosStatus::OK;
}



#endif
