#include "zlib.h"

#include <com/ngos/shared/common/checksum/adler.h>
#include <com/ngos/shared/common/inflate/inflate.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/zlib/zlibcompressioninfo.h>
#include <com/ngos/shared/common/zlib/zlibcompressionlevel.h>
#include <com/ngos/shared/common/zlib/zlibcompressionmethod.h>
#include <com/ngos/shared/common/zlib/zlibheader.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/utils.h>



NgosStatus ZLib::decompress(u8 *compressedAddress, u8 *decompressedAddress, u64 expectedCompressedSize, u64 expectedDecompressedSize)
{
    COMMON_LT((" | compressedAddress = 0x%p, decompressedAddress = 0x%p, expectedCompressedSize = %u, expectedDecompressedSize = %u", compressedAddress, decompressedAddress, expectedCompressedSize, expectedDecompressedSize));

    COMMON_ASSERT(compressedAddress,            "compressedAddress is null",        NgosStatus::ASSERTION);
    COMMON_ASSERT(decompressedAddress,          "decompressedAddress is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(expectedCompressedSize > 0,   "expectedCompressedSize is zero",   NgosStatus::ASSERTION);
    COMMON_ASSERT(expectedDecompressedSize > 0, "expectedDecompressedSize is zero", NgosStatus::ASSERTION);



    if (
        expectedCompressedSize < sizeof(ZLibHeader) + 4 // + 4 for Adler32 checksum
        ||
        ntohs(*(u16 *)compressedAddress) % 31 // ntohs(*(u16 *)compressedAddress) % 31 != 0
       )
    {
        COMMON_LE(("Data is not a zlib archive"));

        return NgosStatus::INVALID_DATA;
    }



    ZLibHeader *zlibHeader = (ZLibHeader *)compressedAddress;

    ZLibCompressionMethod compressionMethod = (ZLibCompressionMethod)zlibHeader->compressionMethod;
    ZLibCompressionInfo   compressionInfo   = (ZLibCompressionInfo)zlibHeader->compressionInfo;
    u8                    presetDictionary  = zlibHeader->presetDictionary;
    ZLibCompressionLevel  compressionLevel  = (ZLibCompressionLevel)zlibHeader->compressionLevel;

    AVOID_UNUSED(compressionLevel);

    COMMON_LVVV(("compressionMethod     = %s",     enumToFullString(compressionMethod)));
    COMMON_LVVV(("compressionInfo       = %s",     enumToFullString(compressionInfo)));
    COMMON_LVVV(("zlibHeader->checkBits = 0x%02X", zlibHeader->checkBits));
    COMMON_LVVV(("presetDictionary      = %u",     presetDictionary));
    COMMON_LVVV(("compressionLevel      = %s",     enumToFullString(compressionLevel)));



    if (compressionMethod != ZLibCompressionMethod::DEFLATE)
    {
        COMMON_LE(("zlib doesn't support compression method %s", enumToFullString(compressionMethod)));

        return NgosStatus::NOT_SUPPORTED;
    }



    if ((u64)compressionInfo > (u64)ZLibCompressionInfo::WINDOW_32K)
    {
        COMMON_LE(("zlib supports inflate with sliding window up to 32KB only"));

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

    COMMON_LVV(("Compressed data inflated"));



    COMMON_LVVV(("compressedSize   = %u", compressedSize));
    COMMON_LVVV(("uncompressedSize = %u", uncompressedSize));

    if (
        compressedSize != expectedCompressedSize - sizeof(ZLibHeader) - 4 // - 4 for Adler32 checksum
        ||
        uncompressedSize != expectedDecompressedSize
       )
    {
        COMMON_LE(("Unexpected compressed/decompressed size after inflating"));

        return NgosStatus::INVALID_DATA;
    }



    u32 adler32Checksum = ntohl(*(u32 *)((u64)currentPointer + compressedSize));
    AVOID_UNUSED(adler32Checksum);

    COMMON_LVVV(("adler32Checksum = 0x%08X", adler32Checksum));

    COMMON_TEST_ASSERT(adler32Checksum == Adler::adler32(decompressedAddress, uncompressedSize), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
