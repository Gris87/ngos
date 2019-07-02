#include "jpeg.h"

#include <common/src/bits64/graphics/jpeg/jpegdefinehuffmantablemarker.h>
#include <common/src/bits64/graphics/jpeg/jpegdefinequantizationtablemarker.h>
#include <common/src/bits64/graphics/jpeg/jpegdefinerestartintervalmarker.h>
#include <common/src/bits64/graphics/jpeg/jpegstartofframemarker.h>
#include <common/src/bits64/graphics/jpeg/jpegzigzagorder.h>
#include <common/src/bits64/graphics/rgbpixel.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/malloc.h>
#include <common/src/bits64/memory/memory.h>
#include <ngos/utils.h>



NgosStatus Jpeg::loadImage(u8 *data, u64 size, Image **image)
{
    COMMON_LT((" | data = 0x%p, size = %u, image = 0x%p", data, size, image));

    COMMON_ASSERT(data,     "data is null",  NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0, "size is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(image,    "image is null", NgosStatus::ASSERTION);

    COMMON_ASSERT(*((u16 *)&data[0])        == JPEG_START_OF_IMAGE_SIGNATURE, "data is invalid", NgosStatus::ASSERTION);
    COMMON_ASSERT(*((u16 *)&data[size - 2]) == JPEG_END_OF_IMAGE_SIGNATURE,   "data is invalid", NgosStatus::ASSERTION);



    if (*((u16 *)&data[0]) != JPEG_START_OF_IMAGE_SIGNATURE)
    {
        return NgosStatus::INVALID_DATA;
    }



    JpegDecoder decoder;

    COMMON_ASSERT_EXECUTION(initDecoder(&decoder, data, size, image), NgosStatus::ASSERTION);



    if (skip(&decoder, 2) != NgosStatus::OK)
    {
        COMMON_ASSERT_EXECUTION(releaseDecoder(&decoder), NgosStatus::ASSERTION);

        return NgosStatus::INVALID_DATA;
    }



    NgosStatus status = NgosStatus::OK;

    while (status == NgosStatus::OK)
    {
        JpegMarkerHeader *marker = (JpegMarkerHeader *)decoder.data;



        if (decoder.size < 2 || marker->separator != JPEG_MARKER_HEADER_SEPARATOR)
        {
            status = NgosStatus::INVALID_DATA;

            break;
        }



        COMMON_LVVV(("marker->type = 0x%02X (%s)", marker->type, jpegMarkerTypeToString(marker->type)));



        status = skip(&decoder, 2);

        if (status != NgosStatus::OK)
        {
            break;
        }



        switch (marker->type)
        {
            case JpegMarkerType::START_OF_FRAME:
            {
                status = decodeStartOfFrame(&decoder, marker);
            }
            break;

            case JpegMarkerType::DEFINE_HUFFMAN_TABLE:
            {
                status = decodeDefineHuffmanTableMarker(&decoder, marker);
            }
            break;

            case JpegMarkerType::DEFINE_QUANTIZATION_TABLE:
            {
                status = decodeDefineQuantizationTableMarker(&decoder, marker);
            }
            break;

            case JpegMarkerType::DEFINE_RESTART_INTERVAL:
            {
                status = decodeDefineRestartIntervalMarker(&decoder, marker);
            }
            break;

            case JpegMarkerType::START_OF_SCAN:
            {
                status = decodeStartOfScanMarker(&decoder, marker);
            }
            break;

            case JpegMarkerType::END_OF_IMAGE:
            {
                if (decoder.size) // decoder.size != 0
                {
                    status = NgosStatus::INVALID_DATA;

                    break;
                }



                COMMON_ASSERT_EXECUTION(releaseDecoder(&decoder), NgosStatus::ASSERTION);

                return NgosStatus::OK;
            }
            break;

            case JpegMarkerType::APPLICATION_0:
            case JpegMarkerType::APPLICATION_1:
            case JpegMarkerType::APPLICATION_2:
            case JpegMarkerType::APPLICATION_3:
            case JpegMarkerType::APPLICATION_4:
            case JpegMarkerType::APPLICATION_5:
            case JpegMarkerType::APPLICATION_6:
            case JpegMarkerType::APPLICATION_7:
            case JpegMarkerType::APPLICATION_8:
            case JpegMarkerType::APPLICATION_9:
            case JpegMarkerType::APPLICATION_10:
            case JpegMarkerType::APPLICATION_11:
            case JpegMarkerType::APPLICATION_12:
            case JpegMarkerType::APPLICATION_13:
            case JpegMarkerType::APPLICATION_14:
            case JpegMarkerType::APPLICATION_15:
            case JpegMarkerType::COMMENT:
            {
                status = skipMarker(&decoder, marker);
            }
            break;

            case JpegMarkerType::START_OF_IMAGE:
            case JpegMarkerType::RESTART_0:
            case JpegMarkerType::RESTART_1:
            case JpegMarkerType::RESTART_2:
            case JpegMarkerType::RESTART_3:
            case JpegMarkerType::RESTART_4:
            case JpegMarkerType::RESTART_5:
            case JpegMarkerType::RESTART_6:
            case JpegMarkerType::RESTART_7:
            {
                COMMON_LF(("Unexpected marker type: %u", marker->type));

                status = NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;

            default:
            {
                COMMON_LF(("Unknown marker type: %u", marker->type));

                status = NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;
        }
    }



    if (*decoder.image)
    {
        COMMON_ASSERT_EXECUTION(free(*decoder.image), NgosStatus::ASSERTION);

        *decoder.image = 0;
    }



    COMMON_ASSERT_EXECUTION(releaseDecoder(&decoder), NgosStatus::ASSERTION);



    return status;
}

NgosStatus Jpeg::initDecoder(JpegDecoder *decoder, u8 *data, u64 size, Image **image)
{
    COMMON_LT((" | decoder = 0x%p, data = 0x%p, size = %u, image = 0x%p", decoder, data, size, image));

    COMMON_ASSERT(decoder,  "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(data,     "data is null",    NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0, "size is zero",    NgosStatus::ASSERTION);
    COMMON_ASSERT(image,    "image is null",   NgosStatus::ASSERTION);



    decoder->data               = data;
    decoder->size               = size;
    decoder->image              = image;
    decoder->startOfFrameMarker = 0;
    decoder->startOfScanMarker  = 0;
    decoder->restartInterval    = 0;
    decoder->mcuBlockCountX     = 0;
    decoder->mcuBlockCountY     = 0;
    decoder->bitBuffer          = 0;
    decoder->bitsAvailable      = 0;

    memzero(decoder->quantizationTables, sizeof(decoder->quantizationTables));
    memzero(decoder->vlcDcTables,        sizeof(decoder->vlcDcTables));
    memzero(decoder->vlcAcTables,        sizeof(decoder->vlcAcTables));
    memzero(decoder->components,         sizeof(decoder->components));

    *decoder->image = 0;



    return NgosStatus::OK;
}

NgosStatus Jpeg::releaseDecoder(JpegDecoder *decoder)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    for (i64 i = 0; i < JPEG_HUFFMAN_TABLE_COUNT; ++i)
    {
        if (decoder->vlcDcTables[i])
        {
            COMMON_ASSERT_EXECUTION(free(decoder->vlcDcTables[i]), NgosStatus::ASSERTION);
        }

        if (decoder->vlcAcTables[i])
        {
            COMMON_ASSERT_EXECUTION(free(decoder->vlcAcTables[i]), NgosStatus::ASSERTION);
        }
    }



    for (i64 i = 0; i < JPEG_NUMBER_OF_COMPONENTS; ++i)
    {
        if (decoder->components[i].pixels)
        {
            COMMON_ASSERT_EXECUTION(free(decoder->components[i].pixels), NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus Jpeg::skip(JpegDecoder *decoder, u64 count)
{
    COMMON_LT((" | decoder = 0x%p, count = %u", decoder, count));

    COMMON_ASSERT(decoder,   "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(count > 0, "count is zero",   NgosStatus::ASSERTION);



    if (count > decoder->size)
    {
        return NgosStatus::INVALID_DATA;
    }



    decoder->data += count;
    decoder->size -= count;



    return NgosStatus::OK;
}

NgosStatus Jpeg::skipMarker(JpegDecoder *decoder, JpegMarkerHeader *marker)
{
    COMMON_LT((" | decoder = 0x%p, marker = 0x%p", decoder, marker));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(marker,  "marker is null",  NgosStatus::ASSERTION);



    return skip(decoder, ntohs(marker->length));
}

NgosStatus Jpeg::decodeStartOfFrame(JpegDecoder *decoder, JpegMarkerHeader *marker)
{
    COMMON_LT((" | decoder = 0x%p, marker = 0x%p", decoder, marker));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(marker,  "marker is null",  NgosStatus::ASSERTION);



    u16 length = ntohs(marker->length);

    COMMON_LVVV(("length = %u", length));



    if (skip(decoder, length) != NgosStatus::OK)
    {
        return NgosStatus::INVALID_DATA;
    }



    JpegStartOfFrameMarker *startOfFrameMarker = (JpegStartOfFrameMarker *)marker;

    COMMON_LVVV(("startOfFrameMarker->dataPrecision = %u", startOfFrameMarker->dataPrecision));

    if (startOfFrameMarker->dataPrecision != JPEG_START_OF_FRAME_DEFAULT_PRECISION)
    {
        return NgosStatus::INVALID_DATA;
    }



    if (sizeof(JpegStartOfFrameMarker) + startOfFrameMarker->numberOfComponents * sizeof(JpegStartOfFrameComponent) != (u16)(length + 2))
    {
        return NgosStatus::INVALID_DATA;
    }



    u16 width  = ntohs(startOfFrameMarker->width);
    u16 height = ntohs(startOfFrameMarker->height);

    COMMON_LVVV(("width  = %u", width));
    COMMON_LVVV(("height = %u", height));

    if (
        !width // width == 0
        ||
        !height // height == 0
       )
    {
        return NgosStatus::INVALID_DATA;
    }



    u8 numberOfComponents = startOfFrameMarker->numberOfComponents;

    COMMON_LVVV(("numberOfComponents = %u", numberOfComponents));

    if (
        numberOfComponents != 3
        &&
        numberOfComponents != 1
       )
    {
        return NgosStatus::INVALID_DATA;
    }



    u8 samplingFactorXMax = 0;
    u8 samplingFactorYMax = 0;

    for (i64 i = 0; i < numberOfComponents; ++i)
    {
        JpegStartOfFrameComponent *component        = &startOfFrameMarker->components[i];
        JpegComponent             *generalComponent = &decoder->components[i];

        JpegComponentId componentId         = component->id;
        u8              samplingFactorX     = component->samplingFactorX;
        u8              samplingFactorY     = component->samplingFactorY;
        u8              quantizationTableId = component->quantizationTableId;

        COMMON_LVVV(("componentId         = %u (%s)", componentId, jpegComponentIdToString(componentId)));
        COMMON_LVVV(("samplingFactorX     = %u", samplingFactorX));
        COMMON_LVVV(("samplingFactorY     = %u", samplingFactorY));
        COMMON_LVVV(("quantizationTableId = %u", quantizationTableId));

        if (
            (u8)componentId < (u8)JpegComponentId::Y
            ||
            (u8)componentId > (u8)JpegComponentId::Q
            ||
            !samplingFactorX // samplingFactorX == 0
            ||
            !samplingFactorY // samplingFactorY == 0
            ||
            !IS_POWER_OF_2(samplingFactorX)
            ||
            !IS_POWER_OF_2(samplingFactorY)
            ||
            quantizationTableId >= JPEG_QUANTIZATION_TABLE_COUNT
           )
        {
            return NgosStatus::INVALID_DATA;
        }



        generalComponent->id                = componentId;
        generalComponent->samplingFactorX   = samplingFactorX;
        generalComponent->samplingFactorY   = samplingFactorY;
        generalComponent->quantizationTable = decoder->quantizationTables[quantizationTableId];

        if (samplingFactorX > samplingFactorXMax)
        {
            samplingFactorXMax = samplingFactorX;
        }

        if (samplingFactorY > samplingFactorYMax)
        {
            samplingFactorYMax = samplingFactorY;
        }
    }



    if (numberOfComponents == 1)
    {
        decoder->components[0].samplingFactorX = 1;
        decoder->components[0].samplingFactorY = 1;
        samplingFactorXMax                     = 1;
        samplingFactorYMax                     = 1;
    }



    COMMON_LVVV(("samplingFactorXMax = %u", samplingFactorXMax));
    COMMON_LVVV(("samplingFactorYMax = %u", samplingFactorYMax));



    u8 mcuBlockSizeX = samplingFactorXMax << 3; // "<< 3" == "* 8"
    u8 mcuBlockSizeY = samplingFactorYMax << 3; // "<< 3" == "* 8"

    COMMON_LVVV(("mcuBlockSizeX = %u", mcuBlockSizeX));
    COMMON_LVVV(("mcuBlockSizeY = %u", mcuBlockSizeY));



    decoder->mcuBlockCountX = (width  + mcuBlockSizeX - 1) / mcuBlockSizeX;
    decoder->mcuBlockCountY = (height + mcuBlockSizeY - 1) / mcuBlockSizeY;

    COMMON_LVVV(("decoder->mcuBlockCountX = %u", decoder->mcuBlockCountX));
    COMMON_LVVV(("decoder->mcuBlockCountY = %u", decoder->mcuBlockCountY));



    for (i64 i = 0; i < numberOfComponents; ++i)
    {
        JpegComponent *generalComponent = &decoder->components[i];

        generalComponent->width  = (width  * generalComponent->samplingFactorX + samplingFactorXMax - 1) / samplingFactorXMax;
        generalComponent->height = (height * generalComponent->samplingFactorY + samplingFactorYMax - 1) / samplingFactorYMax;
        generalComponent->stride = decoder->mcuBlockCountX * generalComponent->samplingFactorX << 3; // "<< 3" == "* 8"
        generalComponent->pixels = (u8 *)malloc(generalComponent->stride * decoder->mcuBlockCountY * generalComponent->samplingFactorY << 3); // "<< 3" == "* 8"

        COMMON_LVVV(("generalComponent->id     = %u (%s)", generalComponent->id, jpegComponentIdToString(generalComponent->id)));
        COMMON_LVVV(("generalComponent->width  = %u", generalComponent->width));
        COMMON_LVVV(("generalComponent->height = %u", generalComponent->height));
        COMMON_LVVV(("generalComponent->stride = %u", generalComponent->stride));
        COMMON_LVVV(("generalComponent->pixels = 0x%p", generalComponent->pixels));

        if (!generalComponent->pixels)
        {
            return NgosStatus::OUT_OF_MEMORY;
        }
    }



    Image *image = (Image *)malloc(sizeof(Image) + width * height * sizeof(RgbPixel));

    if (!image)
    {
        return NgosStatus::OUT_OF_MEMORY;
    }

    image->width    = width;
    image->height   = height;
    image->hasAlpha = false;



    COMMON_TEST_ASSERT(*decoder->image == 0, NgosStatus::ASSERTION);

    *decoder->image = image;



    COMMON_TEST_ASSERT(decoder->startOfFrameMarker == 0, NgosStatus::ASSERTION);

    decoder->startOfFrameMarker = startOfFrameMarker;



    return NgosStatus::OK;
}

NgosStatus Jpeg::decodeDefineHuffmanTableMarker(JpegDecoder *decoder, JpegMarkerHeader *marker)
{
    COMMON_LT((" | decoder = 0x%p, marker = 0x%p", decoder, marker));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(marker,  "marker is null",  NgosStatus::ASSERTION);



    u16 length = ntohs(marker->length);

    COMMON_LVVV(("length = %u", length));



    if (skip(decoder, length) != NgosStatus::OK)
    {
        return NgosStatus::INVALID_DATA;
    }



    JpegHuffmanTable *table = &((JpegDefineHuffmanTableMarker *)marker)->tables[0];

    while (length >= 17)
    {
        u8 tableId = table->id;

        COMMON_LVVV(("tableId = %u", tableId));

        if (tableId >= JPEG_HUFFMAN_TABLE_COUNT)
        {
            return NgosStatus::INVALID_DATA;
        }



        u8 tableType = table->type;

        COMMON_LVVV(("tableType = %u (%s)", tableType, jpegHuffmanTableTypeToString(tableType)));

        COMMON_TEST_ASSERT(tableType == JPEG_HUFFMAN_TABLE_TYPE_DC || tableType == JPEG_HUFFMAN_TABLE_TYPE_AC, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(table->__reserved == 0,                                                             NgosStatus::ASSERTION);



        i64 remain = 65536;
        i64 spread = remain;

        JpegVlcCode *vlc = (JpegVlcCode *)malloc(remain * sizeof(JpegVlcCode));

        if (tableType == JPEG_HUFFMAN_TABLE_TYPE_DC)
        {
            COMMON_TEST_ASSERT(decoder->vlcDcTables[tableId] == 0, NgosStatus::ASSERTION);

            decoder->vlcDcTables[tableId] = vlc;
        }
        else
        {
            COMMON_TEST_ASSERT(decoder->vlcAcTables[tableId] == 0, NgosStatus::ASSERTION);

            decoder->vlcAcTables[tableId] = vlc;
        }



        u16 totalNumberOfSymbols = 0;

        for (i64 i = 0; i < JPEG_HUFFMAN_NUMBER_OF_SYMBOLS_COUNT; ++i)
        {
            spread >>= 1;

            // COMMON_LVVV(("spread = %d", spread)); // Commented to avoid too frequent logs



            u8 numberOfSymbols = table->numberOfSymbols[i];

            COMMON_LVVV(("numberOfSymbols = %u", numberOfSymbols));

            if (!numberOfSymbols) // numberOfSymbols == 0
            {
                continue;
            }



            remain -= numberOfSymbols << (16 - i - 1);

            COMMON_LVVV(("remain = %d", remain));

            if (remain < 0)
            {
                return NgosStatus::INVALID_DATA;
            }



            for (i64 j = 0; j < numberOfSymbols; ++j)
            {
                u8 code = table->symbols[totalNumberOfSymbols + j];

                // COMMON_LVVV(("code = 0x%02X", code)); // Commented to avoid too frequent logs

                for (i64 k = 0; k < spread; ++k)
                {
                    vlc->bits = i + 1;
                    vlc->code = code;
                    ++vlc;
                }
            }



            totalNumberOfSymbols += numberOfSymbols;
        }

        COMMON_LVVV(("totalNumberOfSymbols = %u", totalNumberOfSymbols));

        COMMON_TEST_ASSERT(totalNumberOfSymbols <= 256, NgosStatus::ASSERTION);



        while (remain > 0)
        {
            --remain;

            vlc->bits = 0;
            ++vlc;
        }



        u64 tableSize = sizeof(JpegHuffmanTable) + totalNumberOfSymbols;

        table  =  (JpegHuffmanTable *)((u64)table + tableSize);
        length -= tableSize;
    }



    if (length != 2)
    {
        return NgosStatus::INVALID_DATA;
    }



    return NgosStatus::OK;
}

NgosStatus Jpeg::decodeDefineQuantizationTableMarker(JpegDecoder *decoder, JpegMarkerHeader *marker)
{
    COMMON_LT((" | decoder = 0x%p, marker = 0x%p", decoder, marker));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(marker,  "marker is null",  NgosStatus::ASSERTION);



    u16 length = ntohs(marker->length);

    COMMON_LVVV(("length = %u", length));



    if (skip(decoder, length) != NgosStatus::OK)
    {
        return NgosStatus::INVALID_DATA;
    }

    length -= 2;



    JpegQuantizationTable *table = ((JpegDefineQuantizationTableMarker *)marker)->tables;

    while (length > 0)
    {
        --length;

        u8 tableId        = table->id;
        u8 tablePrecision = table->precision;

        COMMON_LVVV(("tableId        = %u", tableId));
        COMMON_LVVV(("tablePrecision = %u", tablePrecision));



        if (tableId >= JPEG_QUANTIZATION_TABLE_COUNT)
        {
            return NgosStatus::INVALID_DATA;
        }

        u16 *tableData = decoder->quantizationTables[tableId];



        u8 count;

        if (tablePrecision)
        {
            if (length < (JPEG_QUANTIZATION_TABLE_SIZE << 1)) // "<< 1" == "* 2"
            {
                for (i64 i = 0; i < JPEG_QUANTIZATION_TABLE_SIZE; ++i)
                {
                    tableData[i] = 1;
                }

                count = length >> 1; // ">> 1" == "/ 2"
            }
            else
            {
                count = JPEG_QUANTIZATION_TABLE_SIZE;
            }
        }
        else
        {
            if (length < JPEG_QUANTIZATION_TABLE_SIZE)
            {
                for (i64 i = 0; i < JPEG_QUANTIZATION_TABLE_SIZE; ++i)
                {
                    tableData[i] = 1;
                }

                count = length;
            }
            else
            {
                count = JPEG_QUANTIZATION_TABLE_SIZE;
            }
        }



        u8 *naturalOrder;

        switch (count)
        {
            case (2 * 2):
            {
                // Ignore CppAlignmentVerifier [BEGIN]
                asm volatile(
                    "leaq    jpegNaturalOrder2(%%rip), %0"  // leaq    jpegNaturalOrder2(%rip), %rbx     # Get address of jpegNaturalOrder2 variable to RBX. %RBX == naturalOrder
                        :                                   // Output parameters
                            "=r" (naturalOrder)             // 'r' - any general register, '=' - write only
                );
                // Ignore CppAlignmentVerifier [END]
            }
            break;

            case (3 * 3):
            {
                // Ignore CppAlignmentVerifier [BEGIN]
                asm volatile(
                    "leaq    jpegNaturalOrder3(%%rip), %0"  // leaq    jpegNaturalOrder3(%rip), %rbx     # Get address of jpegNaturalOrder3 variable to RBX. %RBX == naturalOrder
                        :                                   // Output parameters
                            "=r" (naturalOrder)             // 'r' - any general register, '=' - write only
                );
                // Ignore CppAlignmentVerifier [END]
            }
            break;

            case (4 * 4):
            {
                // Ignore CppAlignmentVerifier [BEGIN]
                asm volatile(
                    "leaq    jpegNaturalOrder4(%%rip), %0"  // leaq    jpegNaturalOrder4(%rip), %rbx     # Get address of jpegNaturalOrder4 variable to RBX. %RBX == naturalOrder
                        :                                   // Output parameters
                            "=r" (naturalOrder)             // 'r' - any general register, '=' - write only
                );
                // Ignore CppAlignmentVerifier [END]
            }
            break;

            case (5 * 5):
            {
                // Ignore CppAlignmentVerifier [BEGIN]
                asm volatile(
                    "leaq    jpegNaturalOrder5(%%rip), %0"  // leaq    jpegNaturalOrder5(%rip), %rbx     # Get address of jpegNaturalOrder5 variable to RBX. %RBX == naturalOrder
                        :                                   // Output parameters
                            "=r" (naturalOrder)             // 'r' - any general register, '=' - write only
                );
                // Ignore CppAlignmentVerifier [END]
            }
            break;

            case (6 * 6):
            {
                // Ignore CppAlignmentVerifier [BEGIN]
                asm volatile(
                    "leaq    jpegNaturalOrder6(%%rip), %0"  // leaq    jpegNaturalOrder6(%rip), %rbx     # Get address of jpegNaturalOrder6 variable to RBX. %RBX == naturalOrder
                        :                                   // Output parameters
                            "=r" (naturalOrder)             // 'r' - any general register, '=' - write only
                );
                // Ignore CppAlignmentVerifier [END]
            }
            break;

            case (7 * 7):
            {
                // Ignore CppAlignmentVerifier [BEGIN]
                asm volatile(
                    "leaq    jpegNaturalOrder7(%%rip), %0"  // leaq    jpegNaturalOrder7(%rip), %rbx     # Get address of jpegNaturalOrder7 variable to RBX. %RBX == naturalOrder
                        :                                   // Output parameters
                            "=r" (naturalOrder)             // 'r' - any general register, '=' - write only
                );
                // Ignore CppAlignmentVerifier [END]
            }
            break;

            default:
            {
                // Ignore CppAlignmentVerifier [BEGIN]
                asm volatile(
                    "leaq    jpegNaturalOrder8(%%rip), %0"  // leaq    jpegNaturalOrder8(%rip), %rbx     # Get address of jpegNaturalOrder8 variable to RBX. %RBX == naturalOrder
                        :                                   // Output parameters
                            "=r" (naturalOrder)             // 'r' - any general register, '=' - write only
                );
                // Ignore CppAlignmentVerifier [END]
            }
            break;
        }



        for (i64 i = 0; i < count; ++i)
        {
            tableData[naturalOrder[i]] = tablePrecision ? ntohs(((u16 *)table->data16)[i]) : ((u8 *)table->data8)[i];
        }



        u8 tableSize = (tablePrecision ? count << 1 : count) + 1; // "<< 1" == "* 2"

        table = (JpegQuantizationTable *)((u64)table + tableSize);
        length -= tableSize - 1;
    }



    if (length) // length != 0
    {
        return NgosStatus::INVALID_DATA;
    }



    return NgosStatus::OK;
}

NgosStatus Jpeg::decodeDefineRestartIntervalMarker(JpegDecoder *decoder, JpegMarkerHeader *marker)
{
    COMMON_LT((" | decoder = 0x%p, marker = 0x%p", decoder, marker));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(marker,  "marker is null",  NgosStatus::ASSERTION);



    u16 length = ntohs(marker->length);

    COMMON_LVVV(("length = %u", length));



    if (skip(decoder, length) != NgosStatus::OK)
    {
        return NgosStatus::INVALID_DATA;
    }



    JpegDefineRestartIntervalMarker *restartIntervalMarker = (JpegDefineRestartIntervalMarker *)marker;



    u16 restartInterval = restartIntervalMarker->restartInterval;

    COMMON_LVVV(("restartInterval = %u", restartInterval));

    if (!restartInterval) // restartInterval == 0
    {
        return NgosStatus::INVALID_DATA;
    }



    COMMON_TEST_ASSERT(decoder->restartInterval == 0, NgosStatus::ASSERTION);

    decoder->restartInterval = restartInterval;



    return NgosStatus::OK;
}

NgosStatus Jpeg::decodeStartOfScanMarker(JpegDecoder *decoder, JpegMarkerHeader *marker)
{
    COMMON_LT((" | decoder = 0x%p, marker = 0x%p", decoder, marker));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(marker,  "marker is null",  NgosStatus::ASSERTION);



    u16 length = ntohs(marker->length);

    COMMON_LVVV(("length = %u", length));



    if (skip(decoder, length) != NgosStatus::OK)
    {
        return NgosStatus::INVALID_DATA;
    }



    if (!decoder->startOfFrameMarker)
    {
        return NgosStatus::INVALID_DATA;
    }



    JpegStartOfScanMarker *startOfScanMarker = (JpegStartOfScanMarker *)marker;



    if (sizeof(JpegStartOfScanMarker) + startOfScanMarker->numberOfComponents * sizeof(JpegStartOfScanComponent) + 3 != (u16)(length + 2)) // "+ 3" because we have to ignore the last 3 bytes in JpegStartOfScanMarker
    {
        return NgosStatus::INVALID_DATA;
    }



    u8 numberOfComponents = startOfScanMarker->numberOfComponents;

    COMMON_LVVV(("numberOfComponents = %u", numberOfComponents));

    if (
        numberOfComponents != 3
        &&
        numberOfComponents != 1
        &&
        numberOfComponents != decoder->startOfFrameMarker->numberOfComponents
       )
    {
        return NgosStatus::INVALID_DATA;
    }



    for (i64 i = 0; i < numberOfComponents; ++i)
    {
        JpegStartOfScanComponent *component        = &startOfScanMarker->components[i];
        JpegComponent            *generalComponent = &decoder->components[i];

        JpegComponentId componentId      = component->id;
        u8              huffmanDcTableId = component->huffmanDcTableId;
        u8              huffmanAcTableId = component->huffmanAcTableId;

        COMMON_LVVV(("componentId      = %u (%s)", componentId, jpegComponentIdToString(componentId)));
        COMMON_LVVV(("huffmanDcTableId = %u", huffmanDcTableId));
        COMMON_LVVV(("huffmanAcTableId = %u", huffmanAcTableId));

        if (
            (u8)componentId < (u8)JpegComponentId::Y
            ||
            (u8)componentId > (u8)JpegComponentId::Q
            ||
            componentId != generalComponent->id
            ||
            huffmanDcTableId >= JPEG_HUFFMAN_TABLE_COUNT
            ||
            huffmanAcTableId >= JPEG_HUFFMAN_TABLE_COUNT
            ||
            !decoder->vlcDcTables[huffmanDcTableId]
            ||
            !decoder->vlcAcTables[huffmanAcTableId]
           )
        {
            return NgosStatus::INVALID_DATA;
        }



        generalComponent->vlcDcTable = decoder->vlcDcTables[huffmanDcTableId];
        generalComponent->vlcAcTable = decoder->vlcAcTables[huffmanAcTableId];
    }



    COMMON_TEST_ASSERT(((u8 *)startOfScanMarker)[length + 2 - 3] == 0,    NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(((u8 *)startOfScanMarker)[length + 2 - 2] == 0x3F, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(((u8 *)startOfScanMarker)[length + 2 - 1] == 0,    NgosStatus::ASSERTION);



    decoder->startOfScanMarker = startOfScanMarker;



    return decodeImageData(decoder);
}

NgosStatus Jpeg::decodeImageData(JpegDecoder *decoder)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    COMMON_LVV(("Loading image data from address 0x%p", decoder->data));



    u64            mcuBlockX           = 0;
    u64            mcuBlockY           = 0;
    u8             numberOfComponents  = decoder->startOfScanMarker->numberOfComponents;
    u16            restartInterval     = decoder->restartInterval;
    u16            blocksBeforeRestart = restartInterval;
    JpegMarkerType nextRestartMarker   = JpegMarkerType::RESTART_0;

    do
    {
        for (i64 i = 0; i < numberOfComponents; ++i)
        {
            if (decodeMcuBlock(decoder, mcuBlockX, mcuBlockY, &decoder->components[i]) != NgosStatus::OK)
            {
                return NgosStatus::INVALID_DATA;
            }
        }



        ++mcuBlockX;

        if (mcuBlockX >= decoder->mcuBlockCountX)
        {
            mcuBlockX = 0;

            ++mcuBlockY;

            if (mcuBlockY >= decoder->mcuBlockCountY)
            {
                break;
            }
        }



        if (restartInterval)
        {
            --blocksBeforeRestart;

            if (!blocksBeforeRestart) // blocksBeforeRestart == 0
            {
                blocksBeforeRestart = restartInterval;



                COMMON_ASSERT_EXECUTION(alignBits(decoder), NgosStatus::ASSERTION);



                u64 markerData;

                if (readBits(decoder, 16, &markerData) != NgosStatus::OK)
                {
                    return NgosStatus::INVALID_DATA;
                }

                JpegMarkerHeader *marker = (JpegMarkerHeader *)&markerData;



                if (marker->separator != JPEG_MARKER_HEADER_SEPARATOR)
                {
                    return NgosStatus::INVALID_DATA;
                }



                COMMON_LVVV(("marker->type = 0x%02X (%s)", marker->type, jpegMarkerTypeToString(marker->type)));



                if (marker->type != nextRestartMarker)
                {
                    return NgosStatus::INVALID_DATA;
                }



                if (nextRestartMarker == JpegMarkerType::RESTART_7)
                {
                    nextRestartMarker = JpegMarkerType::RESTART_0;
                }
                else
                {
                    nextRestartMarker = (JpegMarkerType)((u8)nextRestartMarker + 1);
                }
            }
        }
    } while(true);



    return NgosStatus::OK;
}

NgosStatus Jpeg::decodeMcuBlock(JpegDecoder *decoder, u64 mcuBlockX, u64 mcuBlockY, JpegComponent *component)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder,                             "decoder is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(mcuBlockX < decoder->mcuBlockCountX, "mcuBlockX is invalid", NgosStatus::ASSERTION);
    COMMON_ASSERT(mcuBlockY < decoder->mcuBlockCountY, "mcuBlockY is invalid", NgosStatus::ASSERTION);
    COMMON_ASSERT(component,                           "component is null",    NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Jpeg::bufferBits(JpegDecoder *decoder, u8 count)
{
    COMMON_LT((" | decoder = 0x%p, count = %u", decoder, count));

    COMMON_ASSERT(decoder,   "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(count > 0, "count is zero",   NgosStatus::ASSERTION);



    while (decoder->bitsAvailable < count)
    {
        if (!decoder->size) // decoder->size == 0
        {
            return NgosStatus::INVALID_DATA;
        }



        decoder->bitBuffer     =  (decoder->bitBuffer << 8) | (*decoder->data);
        decoder->bitsAvailable += 8;

        ++decoder->data;
        --decoder->size;
    }



    return NgosStatus::OK;
}

NgosStatus Jpeg::readBits(JpegDecoder *decoder, u8 count, u64 *res)
{
    COMMON_LT((" | decoder = 0x%p, count = %u, res = 0x%p", decoder, count, res));

    COMMON_ASSERT(decoder,   "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(count > 0, "count is zero",   NgosStatus::ASSERTION);
    COMMON_ASSERT(res,       "res is null",     NgosStatus::ASSERTION);



    if (bufferBits(decoder, count) != NgosStatus::OK)
    {
        return NgosStatus::INVALID_DATA;
    }



    *res                   =  (decoder->bitBuffer >> (decoder->bitsAvailable - count)) & ((1ULL << count) - 1);
    decoder->bitsAvailable -= count;



    return NgosStatus::OK;
}

NgosStatus Jpeg::skipBits(JpegDecoder *decoder, u8 count)
{
    COMMON_LT((" | decoder = 0x%p, count = %u", decoder, count));

    COMMON_ASSERT(decoder,   "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(count > 0, "count is zero",   NgosStatus::ASSERTION);



    if (bufferBits(decoder, count) != NgosStatus::OK)
    {
        return NgosStatus::INVALID_DATA;
    }



    decoder->bitsAvailable -= count;



    return NgosStatus::OK;
}

NgosStatus Jpeg::alignBits(JpegDecoder *decoder)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    decoder->bitsAvailable &= 0xF8;



    return NgosStatus::OK;
}
