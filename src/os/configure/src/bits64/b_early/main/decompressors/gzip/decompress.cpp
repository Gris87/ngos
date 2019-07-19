#include "decompress.h"

#include <common/src/bits64/checksum/crc.h>
#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/inflate/inflate.h>
#include <common/src/bits64/memory/memory.h>

#include "src/bits64/b_early/main/decompressors/gzip/lib/memberfooter.h"
#include "src/bits64/b_early/main/decompressors/gzip/lib/memberheader.h"



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_GZIP



NgosStatus decompress(u8 *compressedAddress, u8 *decompressedAddress, u64 expectedCompressedSize, u64 expectedDecompressedSize)
{
    EARLY_LT((" | compressedAddress = 0x%p, decompressedAddress = 0x%p, expectedCompressedSize = %u, expectedDecompressedSize = %u", compressedAddress, decompressedAddress, expectedCompressedSize, expectedDecompressedSize));

    EARLY_ASSERT(compressedAddress,            "compressedAddress is null",        NgosStatus::ASSERTION);
    EARLY_ASSERT(decompressedAddress,          "decompressedAddress is null",      NgosStatus::ASSERTION);
    EARLY_ASSERT(expectedCompressedSize > 0,   "expectedCompressedSize is zero",   NgosStatus::ASSERTION);
    EARLY_ASSERT(expectedDecompressedSize > 0, "expectedDecompressedSize is zero", NgosStatus::ASSERTION);



    u8 *currentPointer = compressedAddress;

    MemberHeader *memberHeader = (MemberHeader *)currentPointer;



    // Validation
    {
        EARLY_LVVV(("memberHeader->signature         = 0x%04X",  memberHeader->signature));
        EARLY_LVVV(("memberHeader->compressionMethod = %u (%s)", memberHeader->compressionMethod, compressionMethodToString(memberHeader->compressionMethod)));
        EARLY_LVVV(("memberHeader->flags             = 0x%02X",  memberHeader->flags));
        EARLY_LVVV(("memberHeader->modificationTime  = %u",      memberHeader->modificationTime));
        EARLY_LVVV(("memberHeader->extraFlags        = 0x%02X",  memberHeader->extraFlags));
        EARLY_LVVV(("memberHeader->operatingSystem   = %u",      memberHeader->operatingSystem));



        EARLY_TEST_ASSERT(memberHeader->signature         == GZIP_MEMBER_HEADER_SIGNATURE,                           NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(memberHeader->compressionMethod == CompressionMethod::DEFLATE,                             NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(memberHeader->flags             == (gzip_member_flags)MemberFlag::NONE,                    NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(memberHeader->modificationTime  == 0,                                                      NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(memberHeader->extraFlags        == (gzip_member_extra_flags)MemberExtraFlag::DEFLATE_SLOW, NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(memberHeader->operatingSystem   == OperatingSystem::UNIX,                                  NgosStatus::ASSERTION);
    }



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



    // Validation
    {
        EARLY_LVVV(("memberFooter->crc32     = 0x%08X", memberFooter->crc32));
        EARLY_LVVV(("memberFooter->inputSize = %u",     memberFooter->inputSize));



        EARLY_TEST_ASSERT(memberFooter->crc32     == Crc::crc32(decompressedAddress, uncompressedSize), NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(memberFooter->inputSize == uncompressedSize,                                  NgosStatus::ASSERTION);
    }



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
