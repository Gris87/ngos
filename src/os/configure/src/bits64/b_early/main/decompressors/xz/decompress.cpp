#include "decompress.h"

#include <common/src/bits64/checksum/crc.h>
#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/memory/memory.h>
#include <ngos/utils.h>

#include "src/bits64/b_early/main/decompressors/xz/lib/xz/xzblockheader.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/xz/xzfilter.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/xz/xzfilterbcj.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/xz/xzfilterlzma2.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/xz/xzstreamfooter.h"
#include "src/bits64/b_early/main/decompressors/xz/lib/xz/xzstreamheader.h"



#if NGOS_BUILD_KERNEL_COMPRESSION == OPTION_KERNEL_COMPRESSION_XZ



#define MAX_AMOUNT_OF_FILTERS 4



u64 decodeMultibyteInteger(const u8 *buffer, u64 sizeMax, u64 *num)
{
    EARLY_LT((" | buffer = 0x%p, sizeMax = %u, num = 0x%p", buffer, sizeMax, num));



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
    u8 *currentPointer              = compressedAddress;

    XzStreamHeader *streamHeader    = (XzStreamHeader *)currentPointer;
    XzStreamFlag    typeOfCheckFlag = (XzStreamFlag)(streamHeader->streamFlags & TYPE_OF_CHECK_MASK);



    // Validation
    {
        EARLY_LVVV(("streamHeader->signature   = 0x%02X %.4s 0x%02X", streamHeader->signature[0], &streamHeader->signature[1], streamHeader->signature[5]));
        EARLY_LVVV(("streamHeader->streamFlags = %s",                 flagsToFullString(streamHeader->streamFlags)));
        EARLY_LVVV(("streamHeader->crc32       = 0x%08X",             streamHeader->crc32));
        EARLY_LVVV(("typeOfCheckFlag           = 0x%04X (%s)",        typeOfCheckFlag, flagToString(typeOfCheckFlag)));



        EARLY_TEST_ASSERT((*(u64 *)streamHeader->signature & 0x0000FFFFFFFFFFFF) == XZ_STREAM_HEADER_SIGNATURE,                                                      NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(streamHeader->streamFlags                              == FLAGS(XzStreamFlag::TYPE_OF_CHECK_CRC64),                                        NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(streamHeader->crc32                                    == Crc::crc32((u8 *)&streamHeader->streamFlags, sizeof(streamHeader->streamFlags)), NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(typeOfCheckFlag                                        == XzStreamFlag::TYPE_OF_CHECK_CRC64,                                               NgosStatus::ASSERTION);
    }



    currentPointer += sizeof(XzStreamHeader);



    do
    {
        XzBlockHeader *blockHeader = (XzBlockHeader *)currentPointer;

        if (blockHeader->blockHeaderSize) // The first byte overlaps with the Index Indicator field. Non-zero value indicates a Block Header while zero value used for Index Indicator.
        {
            EARLY_LVV(("Processing Block at address 0x%p", blockHeader));



            EARLY_LVVV(("blockHeader->blockHeaderSize = %u", blockHeader->blockHeaderSize));
            EARLY_LVVV(("blockHeader->blockFlags      = %s", flagsToFullString(blockHeader->blockFlags)));



            u64 realBlockHeaderSize = (blockHeader->blockHeaderSize + 1) << 2; // "<< 2" == "* 4"

            EARLY_LVVV(("realBlockHeaderSize = %u", realBlockHeaderSize));



            u8 *currentBlockPointer = currentPointer + sizeof(XzBlockHeader);
            u8 *compressedBlock     = currentPointer + realBlockHeaderSize;



            u64 blockCompressedSize = 0;

            if (blockHeader->blockFlags & FLAGS(XzBlockFlag::COMPRESSED_SIZE_PRESENT))
            {
                currentBlockPointer += decodeMultibyteInteger(currentBlockPointer, -1, &blockCompressedSize);
            }

            EARLY_LVVV(("blockCompressedSize = %u", blockCompressedSize));



            u64 blockUncompressedSize = 0;

            if (blockHeader->blockFlags & FLAGS(XzBlockFlag::UNCOMPRESSED_SIZE_PRESENT))
            {
                currentBlockPointer += decodeMultibyteInteger(currentBlockPointer, -1, &blockUncompressedSize);
            }

            EARLY_LVVV(("blockUncompressedSize = %u", blockUncompressedSize));



            XzFilter filters[MAX_AMOUNT_OF_FILTERS];



            u8 numberOfFilters = (blockHeader->blockFlags & NUMBER_OF_FILTERS_MASK) + 1; // + 1 because numberOfFilters has value 1-4 not 0-3

            EARLY_LVVV(("numberOfFilters = %u", numberOfFilters));



            for (i64 i = 0; i < numberOfFilters; ++i)
            {
                XzFilter &filter = filters[numberOfFilters - i - 1];



                currentBlockPointer += decodeMultibyteInteger(currentBlockPointer, -1, &filter.id);

                EARLY_LVVV(("filter.id = 0x%02X", filter.id));



                currentBlockPointer += decodeMultibyteInteger(currentBlockPointer, -1, &filter.sizeOfProperties);

                EARLY_LVVV(("filter.sizeOfProperties = %u", filter.sizeOfProperties));



                filter.properties   =  currentBlockPointer;
                currentBlockPointer += filter.sizeOfProperties;

                EARLY_LVVV(("filter.properties = 0x%p", filter.properties));
            }



            EARLY_TEST_ASSERT(currentBlockPointer <= currentPointer + realBlockHeaderSize - 4, NgosStatus::ASSERTION);



            u32 blockHeaderCrc32 = *(u32 *)(currentPointer + realBlockHeaderSize - 4);
            AVOID_UNUSED(blockHeaderCrc32);



            EARLY_LVVV(("blockHeaderCrc32 = 0x%08X", blockHeaderCrc32));

            EARLY_TEST_ASSERT(blockHeaderCrc32 == Crc::crc32(currentPointer, realBlockHeaderSize - 4), NgosStatus::ASSERTION);



            u64 compressedSize   = 0;
            u64 uncompressedSize = 0;

            for (i64 i = 0; i < numberOfFilters; ++i)
            {
                XzFilter &filter = filters[i];

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

            if (typeOfCheckFlag == XzStreamFlag::TYPE_OF_CHECK_CRC32)
            {
                u32 blockCrc32 = *(u32 *)currentBlockPointer;
                AVOID_UNUSED(blockCrc32);



                EARLY_LVVV(("blockCrc32 = 0x%08X", blockCrc32));

                EARLY_TEST_ASSERT(blockCrc32 == Crc::crc32(decompressedAddress, uncompressedSize), NgosStatus::ASSERTION);



                currentBlockPointer += sizeof(blockCrc32);
            }
            else
            if (typeOfCheckFlag == XzStreamFlag::TYPE_OF_CHECK_CRC64)
            {
                u64 blockCrc64 = *(u64 *)currentBlockPointer;
                AVOID_UNUSED(blockCrc64);



                EARLY_LVVV(("blockCrc64 = 0x%016lX", blockCrc64));

                EARLY_TEST_ASSERT(blockCrc64 == Crc::crc64(decompressedAddress, uncompressedSize), NgosStatus::ASSERTION);



                currentBlockPointer += sizeof(blockCrc64);
            }
            else
            if (typeOfCheckFlag != XzStreamFlag::NONE)
            {
                EARLY_LF(("Unsupported type of check 0x%04X (%s)", typeOfCheckFlag, flagToString(typeOfCheckFlag)));

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



            u32 indexCrc32 = *(u32 *)currentIndexPointer;

            EARLY_LVVV(("indexCrc32 = 0x%08X", indexCrc32));

            EARLY_TEST_ASSERT(indexCrc32 == Crc::crc32(currentPointer, currentIndexPointer - currentPointer), NgosStatus::ASSERTION);



            currentIndexPointer += sizeof(indexCrc32);
            indexSize           =  currentIndexPointer - currentPointer;

            EARLY_LVVV(("indexSize = %u", indexSize));

            currentPointer = currentIndexPointer;



            EARLY_LVV(("Index processed"));



            XzStreamFooter *streamFooter = (XzStreamFooter *)currentPointer;
            AVOID_UNUSED(streamFooter);



            // Validation
            {
                EARLY_LVVV(("streamFooter->crc32        = 0x%08X", streamFooter->crc32));
                EARLY_LVVV(("streamFooter->backwardSize = %u",     streamFooter->backwardSize));
                EARLY_LVVV(("streamFooter->streamFlags  = %s",     flagsToFullString(streamFooter->streamFlags)));
                EARLY_LVVV(("streamFooter->signature    = %.2s",   &streamFooter->signature));



                EARLY_TEST_ASSERT(streamFooter->crc32        == Crc::crc32((u8 *)&streamFooter->backwardSize, sizeof(streamFooter->backwardSize) + sizeof(streamFooter->streamFlags)), NgosStatus::ASSERTION);
                EARLY_TEST_ASSERT(streamFooter->backwardSize == (indexSize >> 2) - 1,                                                                                                  NgosStatus::ASSERTION); // "<< 2" == "* 4"
                EARLY_TEST_ASSERT(streamFooter->streamFlags  == streamHeader->streamFlags,                                                                                             NgosStatus::ASSERTION);
                EARLY_TEST_ASSERT(streamFooter->signature    == XZ_STREAM_FOOTER_SIGNATURE,                                                                                            NgosStatus::ASSERTION);
            }



            currentPointer += sizeof(XzStreamFooter);



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
