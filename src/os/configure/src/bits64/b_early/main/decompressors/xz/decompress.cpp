#include "decompress.h"

#include <ngos/utils.h>
#include <src/bits64/memory/memory.h>

#include "src/bits64/b_early/early/earlyassert.h"
#include "src/bits64/b_early/early/earlylog.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/blockheader.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/filter.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/filterbcj.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/filterlzma2.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/streamfooter.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/streamheader.h"



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



#define MAX_AMOUNT_OF_FILTERS 4



#if NGOS_BUILD_RELEASE == OPTION_NO // Ignore CppReleaseUsageVerifier
u32 xzCrc32Table[256];
u64 xzCrc64Table[256];



NgosStatus xzInitCrc()
{
    EARLY_LT((""));



    for (i64 i = 0; i < 256; ++i)
    {
        u32 crc32 = i;
        u64 crc64 = i;

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

            if (crc64 & 1)
            {
                crc64 = (crc64 >> 1) ^ 0xC96C5795D7870F42;
            }
            else
            {
                crc64 >>= 1;
            }
        }

        xzCrc32Table[i] = crc32;
        xzCrc64Table[i] = crc64;
    }



    return NgosStatus::OK;
}

u32 xzCrc32(const u8 *buffer, i64 size, u32 crc)
{
    EARLY_LT((" | buffer = 0x%p, size = %u, crc = 0x%08X", buffer, size, crc));

    EARLY_ASSERT(buffer,   "buffer is null",  0);
    EARLY_ASSERT(size > 0, "size is invalid", 0);



    crc = ~crc;

    for (i64 i = 0; i < size; ++i)
    {
        crc = xzCrc32Table[buffer[i] ^ (crc & 0xFF)] ^ (crc >> 8);
    }

    return ~crc;
}

u64 xzCrc64(const u8 *buffer, i64 size, u64 crc)
{
    EARLY_LT((" | buffer = 0x%p, size = %u, crc = 0x%016lX", buffer, size, crc));

    EARLY_ASSERT(buffer,   "buffer is null",  0);
    EARLY_ASSERT(size > 0, "size is invalid", 0);



    crc = ~crc;

    for (i64 i = 0; i < size; ++i)
    {
        crc = xzCrc64Table[buffer[i] ^ (crc & 0xFF)] ^ (crc >> 8);
    }

    return ~crc;
}
#endif



u64 decodeMultibyteInteger(const u8 *buffer, u64 sizeMax, u64 *num)
{
    EARLY_LT((" | buffer = 0x%p, sizeMax = %u, num = 0x%u", buffer, sizeMax, num));



    if (!sizeMax) // sizeMax == 0
    {
        return 0;
    }

    if (sizeMax > 9)
    {
        sizeMax = 9;
    }

    *num = buffer[0] & 0x7F;



    u64 i = 0;

    while (buffer[i++] & 0x80)
    {
        if (i >= sizeMax || !buffer[i]) // buffer[i] == 0x00
        {
            return 0;
        }

        *num |= (u64)(buffer[i] & 0x7F) << (i * 7);
    }



    return i;
}

NgosStatus decompress(u8 *compressedAddress, u8 *decompressedAddress, u64 expectedCompressedSize, u64 expectedDecompressedSize)
{
    EARLY_LT((" | compressedAddress = 0x%p, decompressedAddress = 0x%p, expectedCompressedSize = %u, expectedDecompressedSize = %u", compressedAddress, decompressedAddress, expectedCompressedSize, expectedDecompressedSize));

    EARLY_ASSERT(compressedAddress,            "compressedAddress is null",        NgosStatus::ASSERTION);
    EARLY_ASSERT(decompressedAddress,          "decompressedAddress is null",      NgosStatus::ASSERTION);
    EARLY_ASSERT(expectedCompressedSize > 0,   "expectedCompressedSize is zero",   NgosStatus::ASSERTION);
    EARLY_ASSERT(expectedDecompressedSize > 0, "expectedDecompressedSize is zero", NgosStatus::ASSERTION);



    u8 *originalDecompressedAddress = decompressedAddress;



#if NGOS_BUILD_RELEASE == OPTION_NO // Ignore CppReleaseUsageVerifier
    EARLY_ASSERT_EXECUTION(xzInitCrc(), NgosStatus::ASSERTION);
#endif



    u8 *currentPointer = compressedAddress;

    StreamHeader *streamHeader = (StreamHeader *)currentPointer;

    EARLY_LVVV(("streamHeader->signature   = \\x%02X%c%c%c%c\\x%02X", (u8)streamHeader->signature[0], streamHeader->signature[1], streamHeader->signature[2], streamHeader->signature[3], streamHeader->signature[4], (u8)streamHeader->signature[5]));
    EARLY_LVVV(("streamHeader->streamFlags = 0x%04X",                 streamHeader->streamFlags));
    EARLY_LVVV(("streamHeader->crc32       = 0x%08X",                 streamHeader->crc32));



    StreamFlag typeOfCheckFlag = (StreamFlag)(streamHeader->streamFlags & (xz_stream_flags)StreamFlag::TYPE_OF_CHECK_MASK);

    EARLY_LVVV(("typeOfCheckFlag = 0x%04X", typeOfCheckFlag));



    EARLY_ASSERT(memcmp(streamHeader->signature, XZ_STREAM_HEADER_SIGNATURE, sizeof(streamHeader->signature)) == 0, "Stream Header signature is invalid", NgosStatus::ASSERTION);
    EARLY_ASSERT(typeOfCheckFlag == StreamFlag::NONE
                ||
                typeOfCheckFlag == StreamFlag::TYPE_OF_CHECK_CRC32
                ||
                typeOfCheckFlag == StreamFlag::TYPE_OF_CHECK_CRC64,                                                 "Unsupported type of check",          NgosStatus::ASSERTION);
    EARLY_ASSERT(xzCrc32(
                    (u8 *)&streamHeader->streamFlags,
                    sizeof(streamHeader->streamFlags),
                    0) == streamHeader->crc32,                                                                      "CRC32 is invalid in Stream Header",  NgosStatus::ASSERTION);



    currentPointer += sizeof(*streamHeader);



    do
    {
        BlockHeader *blockHeader = (BlockHeader *)currentPointer;

        if (blockHeader->blockHeaderSize) // The first byte overlaps with the Index Indicator field. Non-zero value indicates a Block Header while zero value used for Index Indicator.
        {
            EARLY_LVV(("Processing Block at address 0x%p", currentPointer));



            EARLY_LVVV(("blockHeader->blockHeaderSize = %u",     blockHeader->blockHeaderSize));
            EARLY_LVVV(("blockHeader->blockFlags      = 0x%02X", blockHeader->blockFlags));



            u64 realBlockHeaderSize = (blockHeader->blockHeaderSize + 1) << 2; // "<< 2" == "* 4"

            EARLY_LVVV(("realBlockHeaderSize = %u", realBlockHeaderSize));



            u8 *currentBlockPointer = currentPointer + sizeof(BlockHeader);
            u8 *compressedBlock     = currentPointer + realBlockHeaderSize;



            u64 blockCompressedSize = 0;

            if (blockHeader->blockFlags & (xz_block_flags)BlockFlag::COMPRESSED_SIZE_PRESENT)
            {
                currentBlockPointer += decodeMultibyteInteger(currentBlockPointer, -1, &blockCompressedSize);
            }

            EARLY_LVVV(("blockCompressedSize = %u", blockCompressedSize));



            u64 blockUncompressedSize = 0;

            if (blockHeader->blockFlags & (xz_block_flags)BlockFlag::UNCOMPRESSED_SIZE_PRESENT)
            {
                currentBlockPointer += decodeMultibyteInteger(currentBlockPointer, -1, &blockUncompressedSize);
            }

            EARLY_LVVV(("blockUncompressedSize = %u", blockUncompressedSize));



            Filter filters[MAX_AMOUNT_OF_FILTERS];



            u8 numberOfFilters = (blockHeader->blockFlags & (xz_block_flags)BlockFlag::NUMBER_OF_FILTERS_MASK) + 1; // + 1 because numberOfFilters has value 1-4 not 0-3

            EARLY_LVVV(("numberOfFilters = %u", numberOfFilters));



            for (i64 i = 0; i < numberOfFilters; ++i)
            {
                Filter &filter = filters[numberOfFilters - i - 1];



                currentBlockPointer += decodeMultibyteInteger(currentBlockPointer, -1, &filter.id);

                EARLY_LVVV(("filter.id = 0x%02X", filter.id));



                currentBlockPointer += decodeMultibyteInteger(currentBlockPointer, -1, &filter.sizeOfProperties);

                EARLY_LVVV(("filter.sizeOfProperties = %u", filter.sizeOfProperties));



                filter.properties   =  currentBlockPointer;
                currentBlockPointer += filter.sizeOfProperties;

                EARLY_LVVV(("filter.properties = 0x%p", filter.properties));
            }



            EARLY_ASSERT(currentBlockPointer <= currentPointer + realBlockHeaderSize - 4, "Block header size is too small", NgosStatus::ASSERTION);



            EARLY_LVVV(("blockHeaderCrc32 = 0x%08X", *((u32 *)(currentPointer + realBlockHeaderSize - 4))));

            EARLY_ASSERT(xzCrc32(
                            currentPointer,
                            realBlockHeaderSize - 4,
                            0) == *((u32 *)(currentPointer + realBlockHeaderSize - 4)), "CRC32 is invalid in Block Header", NgosStatus::ASSERTION);



            u64 compressedSize   = 0;
            u64 uncompressedSize = 0;

            for (i64 i = 0; i < numberOfFilters; ++i)
            {
                Filter &filter = filters[i];

                if (filter.id == XZ_FILTER_LZMA2)
                {
                    EARLY_LVV(("Filtering Block by LZMA2"));

                    if (filterLZMA2(compressedBlock, decompressedAddress, filter.sizeOfProperties, filter.properties, &compressedSize, &uncompressedSize) != NgosStatus::OK)
                    {
                        EARLY_LF(("Failed to filter Block by LZMA2"));

                        return NgosStatus::FAILED;
                    }

                    EARLY_LVV(("Block filtered by LZMA2"));



                    compressedBlock = decompressedAddress;
                }
                else
                if (filter.id == XZ_FILTER_BCJ)
                {
                    EARLY_LVV(("Filtering Block by BCJ"));

                    if (filterBCJ(compressedBlock, decompressedAddress, filter.sizeOfProperties, filter.properties, uncompressedSize) != NgosStatus::OK)
                    {
                        EARLY_LF(("Failed to filter Block by BCJ"));

                        return NgosStatus::FAILED;
                    }

                    EARLY_LVV(("Block filtered by BCJ"));



                    compressedBlock = decompressedAddress;
                }
                else
                {
                    EARLY_LF(("Failed to filter compressed data with unknown Filter ID 0x%02X", filter.id));

                    return NgosStatus::FAILED;
                }
            }

            EARLY_LVVV(("compressedSize   = %u", compressedSize));
            EARLY_LVVV(("uncompressedSize = %u", uncompressedSize));



            EARLY_ASSERT(compressedSize > 0
                        &&
                        (
                            !blockCompressedSize // blockCompressedSize == 0
                            ||
                            compressedSize == blockCompressedSize
                        ),                                                       "Compressed size is invalid",   NgosStatus::ASSERTION);
            EARLY_ASSERT(uncompressedSize > 0
                        &&
                        (
                            !blockUncompressedSize // blockUncompressedSize == 0
                            ||
                            uncompressedSize == blockUncompressedSize
                        ),                                                       "Uncompressed size is invalid", NgosStatus::ASSERTION);



            currentBlockPointer = currentPointer + realBlockHeaderSize + ROUND_UP(compressedSize, 4);

            if (typeOfCheckFlag == StreamFlag::TYPE_OF_CHECK_CRC32)
            {
                EARLY_LVVV(("blockCrc32 = 0x%08X", *((u32 *)(currentBlockPointer))));

                EARLY_ASSERT(xzCrc32(
                                decompressedAddress,
                                uncompressedSize,
                                0) == *((u32 *)(currentBlockPointer)), "CRC32 is invalid in Block", NgosStatus::ASSERTION);

                currentBlockPointer += 4;
            }
            else
            if (typeOfCheckFlag == StreamFlag::TYPE_OF_CHECK_CRC64)
            {
                EARLY_LVVV(("blockCrc64 = 0x%016lX", *((u64 *)(currentBlockPointer))));

                EARLY_ASSERT(xzCrc64(
                                decompressedAddress,
                                uncompressedSize,
                                0) == *((u64 *)(currentBlockPointer)), "CRC64 is invalid in Block", NgosStatus::ASSERTION);

                currentBlockPointer += 8;
            }
            else
            if (typeOfCheckFlag != StreamFlag::NONE)
            {
                EARLY_LF(("Unsupported type of check 0x%04X", typeOfCheckFlag));

                return NgosStatus::NOT_SUPPORTED;
            }



            currentPointer      =  currentBlockPointer;
            decompressedAddress += uncompressedSize;



            EARLY_LVV(("Block processed"));
        }
        else
        {
            EARLY_LVV(("Processing Index at address 0x%p", currentPointer));



            u8 *currentIndexPointer = currentPointer + 1;



            u64 numberOfRecords = 0;

            currentIndexPointer += decodeMultibyteInteger(currentIndexPointer, -1, &numberOfRecords);

            EARLY_LVVV(("numberOfRecords = %u", numberOfRecords));



            for (i64 i = 0; i < (i64)numberOfRecords; ++i)
            {
                u64 indexUnpaddedSize = 0;

                currentIndexPointer += decodeMultibyteInteger(currentIndexPointer, -1, &indexUnpaddedSize);

                EARLY_LVVV(("indexUnpaddedSize = %u", indexUnpaddedSize));



                u64 indexUncompressedSize = 0;

                currentIndexPointer += decodeMultibyteInteger(currentIndexPointer, -1, &indexUncompressedSize);

                EARLY_LVVV(("indexUncompressedSize = %u", indexUncompressedSize));
            }



            u64 indexSize = currentIndexPointer - currentPointer;

            currentIndexPointer = currentPointer + ROUND_UP(indexSize, 4);



            EARLY_LVVV(("indexCrc32 = 0x%08X", *((u32 *)(currentIndexPointer))));

            EARLY_ASSERT(xzCrc32(
                            currentPointer,
                            currentIndexPointer - currentPointer,
                            0) == *((u32 *)(currentIndexPointer)), "CRC32 is invalid in Index", NgosStatus::ASSERTION);



            currentIndexPointer += 4;
            indexSize           =  currentIndexPointer - currentPointer;

            EARLY_LVVV(("indexSize = %u", indexSize));

            currentPointer = currentIndexPointer;



            EARLY_LVV(("Index processed"));



            StreamFooter *streamFooter = (StreamFooter *)currentPointer;

            EARLY_LVVV(("streamFooter->crc32        = 0x%08X", streamFooter->crc32));
            EARLY_LVVV(("streamFooter->backwardSize = %u",     streamFooter->backwardSize));
            EARLY_LVVV(("streamFooter->streamFlags  = 0x%04X", streamFooter->streamFlags));
            EARLY_LVVV(("streamFooter->signature    = %2s",    streamFooter->signature));

            EARLY_ASSERT(xzCrc32(
                            (u8 *)&streamFooter->backwardSize,
                            sizeof(streamFooter->backwardSize) + sizeof(streamFooter->streamFlags),
                            0) == streamFooter->crc32,                                                                      "CRC32 is invalid in Stream Footer",                                NgosStatus::ASSERTION);
            EARLY_ASSERT(((streamFooter->backwardSize + 1) << 2) == indexSize,                                              "Backward Size is invalid",                                         NgosStatus::ASSERTION); // "<< 2" == "* 4"
            EARLY_ASSERT(streamFooter->streamFlags == streamHeader->streamFlags,                                            "Stream flags are not the same in Stream Header and Stream Footer", NgosStatus::ASSERTION);
            EARLY_ASSERT(memcmp(streamFooter->signature, XZ_STREAM_FOOTER_SIGNATURE, sizeof(streamFooter->signature)) == 0, "Stream Footer signature is invalid",                               NgosStatus::ASSERTION);



            currentPointer += sizeof(*streamFooter);



            break;
        }
    } while(true);



    u64 totalCompressedSize = currentPointer - compressedAddress;

    if (totalCompressedSize != expectedCompressedSize)
    {
        EARLY_LF(("Unexpected total compressed size %u", totalCompressedSize));

        return NgosStatus::FAILED;
    }



    u64 totalDecompressedSize = decompressedAddress - originalDecompressedAddress;

    if (totalDecompressedSize != expectedDecompressedSize)
    {
        EARLY_LF(("Unexpected total decompressed size %u", totalDecompressedSize));

        return NgosStatus::FAILED;
    }



    return NgosStatus::OK;
}



#endif
