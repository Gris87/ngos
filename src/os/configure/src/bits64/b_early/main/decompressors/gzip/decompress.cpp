#include "decompress.h"

#include <src/bits64/memory/memory.h>

#include "src/bits64/b_early/early/earlyassert.h"
#include "src/bits64/b_early/early/earlylog.h"
#include "src/bits64/b_early/main/decompressors/gzip/lib/inflate/inflate.h"
#include "src/bits64/b_early/main/decompressors/gzip/lib/memberfooter.h"
#include "src/bits64/b_early/main/decompressors/gzip/lib/memberheader.h"



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP



#if NGOS_BUILD_RELEASE == OPTION_NO
u32 gzipCrc32Table[256];



NgosStatus gzipInitCrc()
{
    EARLY_LT((""));



    for (i64 i = 0; i < 256; ++i)
    {
        u32 crc32 = i;

        for (i64 j = 0; j < 8; ++j)
        {
            if (crc32 & 1)
            {
                crc32 = (crc32 >> 1) ^ 0xEDB88320;
            }
            else
            {
                crc32 >>= 1;
            }
        }

        gzipCrc32Table[i] = crc32;
    }



    return NgosStatus::OK;
}

u32 gzipCrc32(const u8 *buffer, i64 size, u32 crc)
{
    EARLY_LT((" | buffer = 0x%p, size = %u, crc = 0x%08X", buffer, size, crc));

    EARLY_ASSERT(buffer,   "buffer is null",  0);
    EARLY_ASSERT(size > 0, "size is invalid", 0);



    crc = ~crc;

    for (i64 i = 0; i < size; ++i)
    {
        crc = gzipCrc32Table[buffer[i] ^ (crc & 0xFF)] ^ (crc >> 8);
    }

    return ~crc;
}
#endif



NgosStatus decompress(u8 *compressedAddress, u8 *decompressedAddress, u64 expectedCompressedSize, u64 expectedDecompressedSize)
{
    EARLY_LT((" | compressedAddress = 0x%p, decompressedAddress = 0x%p, expectedCompressedSize = %u, expectedDecompressedSize = %u", compressedAddress, decompressedAddress, expectedCompressedSize, expectedDecompressedSize));

    EARLY_ASSERT(compressedAddress,            "compressedAddress is null",        NgosStatus::ASSERTION);
    EARLY_ASSERT(decompressedAddress,          "decompressedAddress is null",      NgosStatus::ASSERTION);
    EARLY_ASSERT(expectedCompressedSize > 0,   "expectedCompressedSize is zero",   NgosStatus::ASSERTION);
    EARLY_ASSERT(expectedDecompressedSize > 0, "expectedDecompressedSize is zero", NgosStatus::ASSERTION);



#if NGOS_BUILD_RELEASE == OPTION_NO
    EARLY_ASSERT_EXECUTION(gzipInitCrc(), NgosStatus::ASSERTION);
#endif



    u8 *currentPointer = compressedAddress;

    MemberHeader *memberHeader = (MemberHeader *)currentPointer;

    EARLY_LVVV(("memberHeader->signature         = 0x%02X/0x%02X", (u8)(memberHeader->signature[0]), (u8)(memberHeader->signature[1])));
    EARLY_LVVV(("memberHeader->compressionMethod = %u",            memberHeader->compressionMethod));
    EARLY_LVVV(("memberHeader->flags             = 0x%02X",        memberHeader->flags));
    EARLY_LVVV(("memberHeader->modificationTime  = %u",            memberHeader->modificationTime));
    EARLY_LVVV(("memberHeader->extraFlags        = 0x%02X",        memberHeader->extraFlags));
    EARLY_LVVV(("memberHeader->operatingSystem   = %u",            memberHeader->operatingSystem));



    EARLY_ASSERT(memcmp(memberHeader->signature, GZIP_MEMBER_HEADER_SIGNATURE, sizeof(memberHeader->signature)) == 0, "Member Header signature is invalid",        NgosStatus::ASSERTION);
    EARLY_ASSERT(memberHeader->compressionMethod == CompressionMethod::DEFLATE,                                       "Unsupported compression method",            NgosStatus::ASSERTION);
    EARLY_ASSERT(memberHeader->flags == (gzip_member_flags)MemberFlag::NONE,                                          "Member Header flags is invalid",            NgosStatus::ASSERTION);
    EARLY_ASSERT(memberHeader->modificationTime == 0,                                                                 "Member Header modificationTime is invalid", NgosStatus::ASSERTION);
    EARLY_ASSERT(memberHeader->extraFlags == (gzip_member_extra_flags)MemberExtraFlag::DEFLATE_SLOW,                  "Member Header extraFlags is invalid",       NgosStatus::ASSERTION);
    EARLY_ASSERT(memberHeader->operatingSystem == OperatingSystem::UNIX,                                              "Member Header operatingSystem is invalid",  NgosStatus::ASSERTION);



    currentPointer += sizeof(*memberHeader);



    u64 compressedSize   = 0;
    u64 uncompressedSize = 0;



    EARLY_LVV(("Inflating compressed blocks"));

    if (inflate(currentPointer, decompressedAddress, &compressedSize, &uncompressedSize) != NgosStatus::OK)
    {
        EARLY_LF(("Failed to inflate compressed blocks"));

        return NgosStatus::FAILED;
    }

    EARLY_LVV(("Blocks inflated"));



    EARLY_LVVV(("compressedSize   = %u", compressedSize));
    EARLY_LVVV(("uncompressedSize = %u", uncompressedSize));



    currentPointer += compressedSize;



    MemberFooter *memberFooter = (MemberFooter *)currentPointer;

    EARLY_LVVV(("memberFooter->crc32     = 0x%08X", memberFooter->crc32));
    EARLY_LVVV(("memberFooter->inputSize = %u",     memberFooter->inputSize));



    EARLY_ASSERT(gzipCrc32(
                    decompressedAddress,
                    uncompressedSize,
                    0) == memberFooter->crc32,                "CRC32 is invalid in Member Footer",  NgosStatus::ASSERTION);
    EARLY_ASSERT(memberFooter->inputSize == uncompressedSize, "Member Footer inputSize is invalid", NgosStatus::ASSERTION);



    currentPointer += sizeof(*memberFooter);



    u64 totalCompressedSize = currentPointer - compressedAddress;

    if (totalCompressedSize != expectedCompressedSize)
    {
        EARLY_LF(("Unexpected total compressed size %u", totalCompressedSize));

        return NgosStatus::FAILED;
    }



    if (uncompressedSize != expectedDecompressedSize)
    {
        EARLY_LF(("Unexpected total decompressed size %u", uncompressedSize));

        return NgosStatus::FAILED;
    }



    return NgosStatus::OK;
}



#endif
