#include "zlib.h"

#include <common/src/bits64/inflate/inflate.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/zlib/zlibcompressionmethod.h>
#include <common/src/bits64/zlib/zlibheader.h>
#include <ngos/utils.h>



NgosStatus ZLib::decompress(u8 *compressedAddress, u8 *decompressedAddress, u64 expectedCompressedSize, u64 expectedDecompressedSize)
{
    COMMON_LT((" | compressedAddress = 0x%p, decompressedAddress = 0x%p, expectedCompressedSize = %u, expectedDecompressedSize = %u", compressedAddress, decompressedAddress, expectedCompressedSize, expectedDecompressedSize));

    COMMON_ASSERT(compressedAddress,            "compressedAddress is null",        NgosStatus::ASSERTION);
    COMMON_ASSERT(decompressedAddress,          "decompressedAddress is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(expectedCompressedSize > 0,   "expectedCompressedSize is zero",   NgosStatus::ASSERTION);
    COMMON_ASSERT(expectedDecompressedSize > 0, "expectedDecompressedSize is zero", NgosStatus::ASSERTION);



    if (
        expectedCompressedSize < 6
        ||
        ntohs(*((u16 *)compressedAddress)) % 31 // ntohs(*((u16 *)compressedAddress)) % 31 != 0
       )
    {
        COMMON_LE(("Data is not a zlib archive"));

        return NgosStatus::INVALID_DATA;
    }



    ZLibHeader *zlibHeader = (ZLibHeader *)compressedAddress;

    ZLibCompressionMethod compressionMethod = (ZLibCompressionMethod)zlibHeader->compressionMethod;
    u8                    compressionInfo   = zlibHeader->compressionInfo;
    u8                    presetDictionary  = zlibHeader->presetDictionary;

    COMMON_LVVV(("compressionMethod            = %u (%s)", compressionMethod, zlibCompressionMethodToString(compressionMethod)));
    COMMON_LVVV(("compressionInfo              = %u", compressionInfo));
    COMMON_LVVV(("zlibHeader->checkBits        = 0x%02X", zlibHeader->checkBits));
    COMMON_LVVV(("presetDictionary             = %u", presetDictionary));
    COMMON_LVVV(("zlibHeader->compressionLevel = %u", zlibHeader->compressionLevel));



    if (compressionMethod != ZLibCompressionMethod::DEFLATE)
    {
        COMMON_LE(("zlib doesn't support compression method %u (%s)", compressionMethod, zlibCompressionMethodToString(compressionMethod)));

        return NgosStatus::NOT_SUPPORTED;
    }



    if (compressionInfo != 7)
    {
        COMMON_LE(("zlib supports inflate with sliding window of 32KB only"));

        return NgosStatus::NOT_SUPPORTED;
    }



    if (presetDictionary)
    {
        COMMON_LE(("zlib doesn't support preset dictionary"));

        return NgosStatus::NOT_SUPPORTED;
    }



    u8  *currentPointer   = compressedAddress + sizeof(ZLibHeader);
    u64  compressedSize   = 0;
    u64  uncompressedSize = 0;

    NgosStatus status = inflate(currentPointer, decompressedAddress, &compressedSize, &uncompressedSize);

    if (status != NgosStatus::OK)
    {
        COMMON_LE(("Failed to inflate compressed image data"));

        return status;
    }

    COMMON_LVV(("Image data inflated"));



    COMMON_LVVV(("compressedSize   = %u", compressedSize));
    COMMON_LVVV(("uncompressedSize = %u", uncompressedSize));

    if (
        compressedSize != expectedCompressedSize - sizeof(ZLibHeader) - 4
        ||
        uncompressedSize != expectedDecompressedSize
       )
    {
        COMMON_LE(("Unexpected compressed/decompressed size after inflating"));

        return NgosStatus::INVALID_DATA;
    }



    currentPointer += compressedSize;



    return NgosStatus::OK;
}
