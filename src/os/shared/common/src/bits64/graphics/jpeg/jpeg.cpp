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



#define W1 2841
#define W2 2676
#define W3 2408
#define W5 1609
#define W6 1108
#define W7 565

#define CLAMP_TO_BYTE(a) clamp((i64)(a), (i64)0x00, (i64)0xFF);



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
        COMMON_LE(("Data is not a JPEG image"));

        return NgosStatus::INVALID_DATA;
    }



    JpegDecoder decoder;

    COMMON_ASSERT_EXECUTION(initDecoder(&decoder, data, size, image), NgosStatus::ASSERTION);



    NgosStatus status = skip(&decoder, 2);

    if (status != NgosStatus::OK)
    {
        COMMON_ASSERT_EXECUTION(releaseDecoder(&decoder), NgosStatus::ASSERTION);

        return status;
    }



    while (status == NgosStatus::OK && decoder.size >= 2)
    {
        JpegMarkerHeader *marker = (JpegMarkerHeader *)decoder.data;



        if (marker->separator != JPEG_MARKER_HEADER_SEPARATOR)
        {
            COMMON_LE(("Invalid separator(0x%02X) value in JPEG marker", marker->separator));

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
                    COMMON_LE(("There is some data found after JpegMarkerType::END_OF_IMAGE marker"));

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
                COMMON_LF(("Unexpected marker type: 0x%02X (%s)", marker->type, jpegMarkerTypeToString(marker->type)));

                status = NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;

            default:
            {
                COMMON_LF(("Unknown marker type: 0x%02X (%s)", marker->type, jpegMarkerTypeToString(marker->type)));

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



    return NgosStatus::OK;
}

NgosStatus Jpeg::skip(JpegDecoder *decoder, u64 count)
{
    COMMON_LT((" | decoder = 0x%p, count = %u", decoder, count));

    COMMON_ASSERT(decoder,   "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(count > 0, "count is zero",   NgosStatus::ASSERTION);



    if (count > decoder->size)
    {
        COMMON_LE(("There are no more bytes to read"));

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



    NgosStatus status = skip(decoder, length);

    if (status != NgosStatus::OK)
    {
        return status;
    }



    JpegStartOfFrameMarker *startOfFrameMarker = (JpegStartOfFrameMarker *)marker;

    COMMON_LVVV(("startOfFrameMarker->dataPrecision = %u", startOfFrameMarker->dataPrecision));

    if (startOfFrameMarker->dataPrecision != JPEG_START_OF_FRAME_DEFAULT_PRECISION)
    {
        COMMON_LE(("JPEG decoder doesn't support data precision = %u", startOfFrameMarker->dataPrecision));

        return NgosStatus::NOT_SUPPORTED;
    }



    if (sizeof(JpegStartOfFrameMarker) + startOfFrameMarker->numberOfComponents * sizeof(JpegStartOfFrameComponent) != (u16)(length + 2))
    {
        COMMON_LE(("Invalid JpegMarkerType::START_OF_FRAME marker"));

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
        COMMON_LE(("Empty JPEG image"));

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
        COMMON_LE(("JPEG decoder supports images with 1 or 3 color components"));

        return NgosStatus::NOT_SUPPORTED;
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
            COMMON_LE(("Invalid JPEG component:"));

            COMMON_LE(("componentId         = %u (%s)", componentId, jpegComponentIdToString(componentId)));
            COMMON_LE(("samplingFactorX     = %u", samplingFactorX));
            COMMON_LE(("samplingFactorY     = %u", samplingFactorY));
            COMMON_LE(("quantizationTableId = %u", quantizationTableId));

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

        // Ignore CppAlignmentVerifier [BEGIN]
        generalComponent->width        = (width  * generalComponent->samplingFactorX + samplingFactorXMax - 1) / samplingFactorXMax;
        generalComponent->height       = (height * generalComponent->samplingFactorY + samplingFactorYMax - 1) / samplingFactorYMax;
        generalComponent->sampleStride = generalComponent->samplingFactorX << 3; // "<< 3" == "* 8"
        // Ignore CppAlignmentVerifier [END]

        COMMON_LVVV(("generalComponent->id           = %u (%s)", generalComponent->id, jpegComponentIdToString(generalComponent->id)));
        COMMON_LVVV(("generalComponent->width        = %u", generalComponent->width));
        COMMON_LVVV(("generalComponent->height       = %u", generalComponent->height));
        COMMON_LVVV(("generalComponent->sampleStride = %u", generalComponent->sampleStride));
    }



    Image *image = (Image *)malloc(sizeof(Image) + width * height * sizeof(RgbPixel));

    if (!image)
    {
        COMMON_LE(("Failed to allocate space for raw image data. Out of space"));

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



    NgosStatus status = skip(decoder, length);

    if (status != NgosStatus::OK)
    {
        return status;
    }



    JpegHuffmanTable *table = &((JpegDefineHuffmanTableMarker *)marker)->tables[0];

    while (length >= 17)
    {
        u8 tableId = table->id;

        COMMON_LVVV(("tableId = %u", tableId));

        if (tableId >= JPEG_HUFFMAN_TABLE_COUNT)
        {
            COMMON_LE(("Huffman table id(%u) is more than %u", tableId, JPEG_HUFFMAN_TABLE_COUNT));

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
                COMMON_LE(("Invalid JpegMarkerType::DEFINE_HUFFMAN_TABLE marker"));

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
        COMMON_LE(("Invalid JpegMarkerType::DEFINE_HUFFMAN_TABLE marker"));

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



    NgosStatus status = skip(decoder, length);

    if (status != NgosStatus::OK)
    {
        return status;
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
            COMMON_LE(("Quantization table id(%u) is more than %u", tableId, JPEG_QUANTIZATION_TABLE_COUNT));

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



        for (i64 i = 0; i < count; ++i)
        {
            tableData[i] = tablePrecision ? ntohs(((u16 *)table->data16)[i]) : ((u8 *)table->data8)[i];
        }



        u8 tableSize = (tablePrecision ? count << 1 : count) + 1; // "<< 1" == "* 2"

        table  =  (JpegQuantizationTable *)((u64)table + tableSize);
        length -= tableSize - 1;
    }



    if (length) // length != 0
    {
        COMMON_LE(("Invalid JpegMarkerType::DEFINE_QUANTIZATION_TABLE marker"));

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



    NgosStatus status = skip(decoder, length);

    if (status != NgosStatus::OK)
    {
        return status;
    }



    if (length != sizeof(JpegDefineRestartIntervalMarker) - 2)
    {
        COMMON_LE(("Invalid JpegMarkerType::DEFINE_RESTART_INTERVAL marker"));

        return NgosStatus::INVALID_DATA;
    }



    JpegDefineRestartIntervalMarker *restartIntervalMarker = (JpegDefineRestartIntervalMarker *)marker;



    u16 restartInterval = restartIntervalMarker->restartInterval;

    COMMON_LVVV(("restartInterval = %u", restartInterval));

    if (!restartInterval) // restartInterval == 0
    {
        COMMON_LE(("Invalid JpegMarkerType::DEFINE_RESTART_INTERVAL marker"));

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



    NgosStatus status = skip(decoder, length);

    if (status != NgosStatus::OK)
    {
        return status;
    }



    if (!decoder->startOfFrameMarker)
    {
        COMMON_LE(("JpegMarkerType::START_OF_FRAME marker not found before JpegMarkerType::START_OF_SCAN marker"));

        return NgosStatus::INVALID_DATA;
    }



    JpegStartOfScanMarker *startOfScanMarker = (JpegStartOfScanMarker *)marker;



    if (sizeof(JpegStartOfScanMarker) + startOfScanMarker->numberOfComponents * sizeof(JpegStartOfScanComponent) + 3 != (u16)(length + 2)) // "+ 3" because we have to ignore the last 3 bytes in JpegStartOfScanMarker
    {
        COMMON_LE(("Invalid JpegMarkerType::START_OF_SCAN marker"));

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
        COMMON_LE(("JPEG decoder supports images with 1 or 3 color components"));

        return NgosStatus::NOT_SUPPORTED;
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
            COMMON_LE(("Invalid JPEG component:"));

            COMMON_LE(("componentId      = %u (%s)", componentId, jpegComponentIdToString(componentId)));
            COMMON_LE(("huffmanDcTableId = %u", huffmanDcTableId));
            COMMON_LE(("huffmanAcTableId = %u", huffmanAcTableId));

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



    u8* componentDataBuffer[JPEG_NUMBER_OF_COMPONENTS];

    u64            mcuBlockX           = 0;
    u64            mcuBlockY           = 0;
    u8             numberOfComponents  = decoder->startOfScanMarker->numberOfComponents;
    u16            restartInterval     = decoder->restartInterval;
    u16            blocksBeforeRestart = restartInterval;
    JpegMarkerType nextRestartMarker   = JpegMarkerType::RESTART_0;



    NgosStatus status = NgosStatus::OK;



    for (i64 i = 0; i < numberOfComponents; ++i)
    {
        componentDataBuffer[i] = (u8 *)malloc(decoder->components[i].samplingFactorX * decoder->components[i].samplingFactorY << 6); // "<< 6" == "* 64"

        if (!componentDataBuffer[i])
        {
            COMMON_LE(("Failed to allocate space for component data buffer. Out of space"));

            status = NgosStatus::OUT_OF_MEMORY;

            break;
        }
    }



    while (status == NgosStatus::OK)
    {
        for (i64 i = 0; i < numberOfComponents; ++i)
        {
            status = decodeMcuBlock(decoder, &decoder->components[i], componentDataBuffer[i]);

            if (status != NgosStatus::OK)
            {
                COMMON_LE(("Failed to decode MCU block at position (%u, %u) with component %d", mcuBlockX, mcuBlockY, i));

                break;
            }
        }

        if (status != NgosStatus::OK)
        {
            break;
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



                for (i64 i = 0; i < numberOfComponents; ++i)
                {
                    decoder->components[i].dcpred = 0;
                }



                COMMON_ASSERT_EXECUTION(alignBits(decoder), NgosStatus::ASSERTION);



                u64 markerData;

                status = readBits(decoder, 16, &markerData);

                if (status != NgosStatus::OK)
                {
                    break;
                }

                JpegMarkerHeader *marker = (JpegMarkerHeader *)&markerData;



                if (marker->separator != JPEG_MARKER_HEADER_SEPARATOR)
                {
                    COMMON_LE(("Invalid separator(0x%02X) value in JPEG restart marker", marker->separator));

                    status = NgosStatus::INVALID_DATA;

                    break;
                }



                COMMON_LVVV(("marker->type = 0x%02X (%s)", marker->type, jpegMarkerTypeToString(marker->type)));



                if (marker->type != nextRestartMarker)
                {
                    COMMON_LE(("Unexpected restart marker %u (%s). Expecting for %u (%s)", marker->type, marker->type, nextRestartMarker, nextRestartMarker));

                    status = NgosStatus::INVALID_DATA;

                    break;
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
    }



    for (i64 i = 0; i < numberOfComponents; ++i)
    {
        if (componentDataBuffer[i])
        {
            COMMON_ASSERT_EXECUTION(free(componentDataBuffer[i]), NgosStatus::ASSERTION);
        }
    }



    return status;
}

NgosStatus Jpeg::decodeMcuBlock(JpegDecoder *decoder, JpegComponent *component, u8 *componentDataBuffer)
{
    COMMON_LT((" | decoder = 0x%p, component = 0x%p, componentDataBuffer = 0x%p", decoder, component, componentDataBuffer));

    COMMON_ASSERT(decoder,             "decoder is null",             NgosStatus::ASSERTION);
    COMMON_ASSERT(component,           "component is null",           NgosStatus::ASSERTION);
    COMMON_ASSERT(componentDataBuffer, "componentDataBuffer is null", NgosStatus::ASSERTION);



    for (i64 i = 0; i < component->samplingFactorY; ++i)
    {
        for (i64 j = 0; j < component->samplingFactorX; ++j)
        {
            NgosStatus status = decodeMcuBlockSample(decoder, component, componentDataBuffer + ((i * component->samplingFactorX + j) << 6)); // "<< 6" == "* 64"

            if (status != NgosStatus::OK)
            {
                return status;
            }
        }
    }



    return NgosStatus::OK;
}

NgosStatus Jpeg::decodeMcuBlockSample(JpegDecoder *decoder, JpegComponent *component, u8 *sampleDataBuffer)
{
    COMMON_LT((" | decoder = 0x%p, component = 0x%p, sampleDataBuffer = 0x%p", decoder, component, sampleDataBuffer));

    COMMON_ASSERT(decoder,          "decoder is null",          NgosStatus::ASSERTION);
    COMMON_ASSERT(component,        "component is null",        NgosStatus::ASSERTION);
    COMMON_ASSERT(sampleDataBuffer, "sampleDataBuffer is null", NgosStatus::ASSERTION);



    u8 *naturalOrder;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "leaq    jpegNaturalOrder(%%rip), %0"   // leaq    jpegNaturalOrder(%rip), %rbx     # Get address of jpegNaturalOrder variable to RBX. %RBX == naturalOrder
            :                                   // Output parameters
                "=r" (naturalOrder)             // 'r' - any general register, '=' - write only
    );
    // Ignore CppAlignmentVerifier [END]



    u8  vlcCode;
    i64 vlcValue;

    NgosStatus status = getVlc(decoder, component->vlcDcTable, &vlcCode, &vlcValue);

    if (status != NgosStatus::OK)
    {
        return status;
    }

    // COMMON_LVVV(("vlcCode  = %u", vlcCode));  // Commented to avoid too frequent logs
    // COMMON_LVVV(("vlcValue = %d", vlcValue)); // Commented to avoid too frequent logs



    i64 block[64];
    memzero(&block[1], sizeof(block) - sizeof(block[0]));



    component->dcpred += vlcValue;
    block[0]          =  component->dcpred * component->quantizationTable[0];

    // COMMON_LVVV(("component->dcpred = %d", component->dcpred)); // Commented to avoid too frequent logs



    u16 coefficient = 0;

    do
    {
        NgosStatus status = getVlc(decoder, component->vlcAcTable, &vlcCode, &vlcValue);

        if (status != NgosStatus::OK)
        {
            return status;
        }

        // COMMON_LVVV(("vlcCode  = %u", vlcCode));  // Commented to avoid too frequent logs
        // COMMON_LVVV(("vlcValue = %d", vlcValue)); // Commented to avoid too frequent logs



        if (!vlcCode) // vlcCode == 0
        {
            break;
        }



        if (!(vlcCode & 0x0F) && (vlcCode != 0xF0))
        {
            COMMON_LE(("Invalid VLC code found: 0x%02X", vlcCode));

            return NgosStatus::INVALID_DATA;
        }



        coefficient += (vlcCode >> 4) + 1;

        // COMMON_LVVV(("coefficient = %u", coefficient)); // Commented to avoid too frequent logs

        if (coefficient > 63)
        {
            COMMON_LE(("Invalid coefficient value: %u", coefficient));

            return NgosStatus::INVALID_DATA;
        }



        block[naturalOrder[coefficient]] = vlcValue * component->quantizationTable[coefficient];
    } while(coefficient < 63);



    for (i64 i = 0; i < 64; i += 8)
    {
        COMMON_ASSERT_EXECUTION(handleRowIDCT(decoder, &block[i]), NgosStatus::ASSERTION);
    }



    for (i64 i = 0; i < 8; ++i)
    {
        COMMON_ASSERT_EXECUTION(handleColIDCT(decoder, &block[i], &sampleDataBuffer[i], component->sampleStride), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus Jpeg::getVlc(JpegDecoder *decoder, JpegVlcCode *vlc, u8 *code, i64 *value)
{
    // COMMON_LT((" | decoder = 0x%p, vlc = 0x%p, code = 0x%p, value = 0x%p", decoder, vlc, code, value)); // Commented to avoid too frequent logs

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(vlc,     "vlc is null",     NgosStatus::ASSERTION);
    COMMON_ASSERT(code,    "code is null",    NgosStatus::ASSERTION);
    COMMON_ASSERT(value,   "value is null",   NgosStatus::ASSERTION);



    u64 vlcId;

    NgosStatus status = getBits(decoder, 16, &vlcId);

    if (status != NgosStatus::OK)
    {
        return status;
    }

    // COMMON_LVVV(("vlcId = %u", vlcId)); // Commented to avoid too frequent logs



    u8 bits = vlc[vlcId].bits;

    // COMMON_LVVV(("bits = %u", bits)); // Commented to avoid too frequent logs

    if (!bits) // bits == 0
    {
        COMMON_LE(("Zero bits found in VLC"));

        return NgosStatus::INVALID_DATA;
    }



    status = skipBits(decoder, bits);

    if (status != NgosStatus::OK)
    {
        return status;
    }



    i64 valueTemp = vlc[vlcId].code;
    *code         = valueTemp;

    // COMMON_LVVV(("valueTemp = %d", valueTemp)); // Commented to avoid too frequent logs



    bits = valueTemp & 0x0F;

    // COMMON_LVVV(("bits = %u", bits)); // Commented to avoid too frequent logs

    if (!bits) // bits == 0
    {
        *value = 0;

        return NgosStatus::OK;
    }



    status = readBits(decoder, bits, (u64 *)&valueTemp);

    if (status != NgosStatus::OK)
    {
        return status;
    }

    // COMMON_LVVV(("valueTemp = %d", valueTemp)); // Commented to avoid too frequent logs



    if (valueTemp < (1 << (bits - 1)))
    {
        valueTemp += (0xFFFFFFFFFFFFFFFF << bits) + 1;

        // COMMON_LVVV(("valueTemp = %d", valueTemp)); // Commented to avoid too frequent logs
    }



    *value = valueTemp;

    return NgosStatus::OK;
}

NgosStatus Jpeg::handleRowIDCT(JpegDecoder *decoder, i64 *block)
{
    // COMMON_LT((" | decoder = 0x%p, block = 0x%p", decoder, block)); // Commented to avoid too frequent logs

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(block,   "block is null",   NgosStatus::ASSERTION);



    i64 x0 = (block[0] << 11) + 128;
    i64 x1 = block[4] << 11;
    i64 x2 = block[6];
    i64 x3 = block[2];
    i64 x4 = block[1];
    i64 x5 = block[7];
    i64 x6 = block[5];
    i64 x7 = block[3];
    i64 x8 = W7 * (x4 + x5);

    if (
        !x1 // x1 == 0
        &&
        !x2 // x2 == 0
        &&
        !x3 // x3 == 0
        &&
        !x4 // x4 == 0
        &&
        !x5 // x5 == 0
        &&
        !x6 // x6 == 0
        &&
        !x7 // x7 == 0
       )
    {
        x0       = block[0] << 3;
        block[0] = x0;
        block[1] = x0;
        block[2] = x0;
        block[3] = x0;
        block[4] = x0;
        block[5] = x0;
        block[6] = x0;
        block[7] = x0;

        return NgosStatus::OK;
    }



    x4 =  x8 + (W1 - W7) * x4;
    x5 =  x8 - (W1 + W7) * x5;
    x8 =  W3 * (x6 + x7);
    x6 =  x8 - (W3 - W5) * x6;
    x7 =  x8 - (W3 + W5) * x7;
    x8 =  x0 + x1;
    x0 -= x1;
    x1 =  W6 * (x3 + x2);
    x2 =  x1 - (W2 + W6) * x2;
    x3 =  x1 + (W2 - W6) * x3;
    x1 =  x4 + x6;
    x4 -= x6;
    x6 =  x5 + x7;
    x5 -= x7;
    x7 =  x8 + x3;
    x8 -= x3;
    x3 =  x0 + x2;
    x0 -= x2;
    x2 =  (181 * (x4 + x5) + 128) >> 8;
    x4 =  (181 * (x4 - x5) + 128) >> 8;



    block[0] = (x7 + x1) >> 8;
    block[1] = (x3 + x2) >> 8;
    block[2] = (x0 + x4) >> 8;
    block[3] = (x8 + x6) >> 8;
    block[4] = (x8 - x6) >> 8;
    block[5] = (x0 - x4) >> 8;
    block[6] = (x3 - x2) >> 8;
    block[7] = (x7 - x1) >> 8;



    return NgosStatus::OK;
}

NgosStatus Jpeg::handleColIDCT(JpegDecoder *decoder, i64 *block, u8 *sampleDataBuffer, u64 sampleStride)
{
    // COMMON_LT((" | decoder = 0x%p, block = 0x%p, sampleDataBuffer = 0x%p, sampleStride = %u", decoder, block, sampleDataBuffer, sampleStride)); // Commented to avoid too frequent logs

    COMMON_ASSERT(decoder,          "decoder is null",          NgosStatus::ASSERTION);
    COMMON_ASSERT(block,            "block is null",            NgosStatus::ASSERTION);
    COMMON_ASSERT(sampleDataBuffer, "sampleDataBuffer is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(sampleStride > 0, "sampleStride is zero",     NgosStatus::ASSERTION);



    i64 x0 = (block[0] << 8) + 8192;
    i64 x1 = block[32] << 8;            // 32 == 8 * 4
    i64 x2 = block[48];                 // 48 == 8 * 6
    i64 x3 = block[16];                 // 16 == 8 * 2
    i64 x4 = block[8];                  // 8  == 8 * 1
    i64 x5 = block[56];                 // 56 == 8 * 7
    i64 x6 = block[40];                 // 40 == 8 * 5
    i64 x7 = block[24];                 // 24 == 8 * 3
    i64 x8 = W7 * (x4 + x5) + 4;

    if (
        !x1 // x1 == 0
        &&
        !x2 // x2 == 0
        &&
        !x3 // x3 == 0
        &&
        !x4 // x4 == 0
        &&
        !x5 // x5 == 0
        &&
        !x6 // x6 == 0
        &&
        !x7 // x7 == 0
       )
    {
        x0 = CLAMP_TO_BYTE(((block[0] + 32) >> 6) + 128);

        for (i64 i = 0; i < 8; ++i)
        {
            *sampleDataBuffer =  x0;
            sampleDataBuffer  += sampleStride;
        }

        return NgosStatus::OK;
    }



    x4 =  (x8 + (W1 - W7) * x4) >> 3;
    x5 =  (x8 - (W1 + W7) * x5) >> 3;
    x8 =  W3 * (x6 + x7) + 4;
    x6 =  (x8 - (W3 - W5) * x6) >> 3;
    x7 =  (x8 - (W3 + W5) * x7) >> 3;
    x8 =  x0 + x1;
    x0 -= x1;
    x1 =  W6 * (x3 + x2) + 4;
    x2 =  (x1 - (W2 + W6) * x2) >> 3;
    x3 =  (x1 + (W2 - W6) * x3) >> 3;
    x1 =  x4 + x6;
    x4 -= x6;
    x6 =  x5 + x7;
    x5 -= x7;
    x7 =  x8 + x3;
    x8 -= x3;
    x3 =  x0 + x2;
    x0 -= x2;
    x2 =  (181 * (x4 + x5) + 128) >> 8;
    x4 =  (181 * (x4 - x5) + 128) >> 8;



    *sampleDataBuffer =  CLAMP_TO_BYTE(((x7 + x1) >> 14) + 128);
    sampleDataBuffer  += sampleStride;

    *sampleDataBuffer =  CLAMP_TO_BYTE(((x3 + x2) >> 14) + 128);
    sampleDataBuffer  += sampleStride;

    *sampleDataBuffer =  CLAMP_TO_BYTE(((x0 + x4) >> 14) + 128);
    sampleDataBuffer  += sampleStride;

    *sampleDataBuffer =  CLAMP_TO_BYTE(((x8 + x6) >> 14) + 128);
    sampleDataBuffer  += sampleStride;

    *sampleDataBuffer =  CLAMP_TO_BYTE(((x8 - x6) >> 14) + 128);
    sampleDataBuffer  += sampleStride;

    *sampleDataBuffer =  CLAMP_TO_BYTE(((x0 - x4) >> 14) + 128);
    sampleDataBuffer  += sampleStride;

    *sampleDataBuffer =  CLAMP_TO_BYTE(((x3 - x2) >> 14) + 128);
    sampleDataBuffer  += sampleStride;

    *sampleDataBuffer = CLAMP_TO_BYTE(((x7 - x1) >> 14) + 128);



    return NgosStatus::OK;
}

NgosStatus Jpeg::bufferBits(JpegDecoder *decoder, u8 count)
{
    // COMMON_LT((" | decoder = 0x%p, count = %u", decoder, count)); // Commented to avoid too frequent logs

    COMMON_ASSERT(decoder,   "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(count > 0, "count is zero",   NgosStatus::ASSERTION);



    while (decoder->bitsAvailable < count)
    {
        if (!decoder->size) // decoder->size == 0
        {
            decoder->bitBuffer     =  (decoder->bitBuffer << 8) | 0xFF;
            decoder->bitsAvailable += 8;

            continue;
        }



        u8 newByte = *decoder->data;

        ++decoder->data;
        --decoder->size;

        decoder->bitBuffer     =  (decoder->bitBuffer << 8) | newByte;
        decoder->bitsAvailable += 8;



        if (newByte == 0xFF)
        {
            if (!decoder->size) // decoder->size == 0
            {
                COMMON_LE(("There are no more bytes to read"));

                return NgosStatus::INVALID_DATA;
            }



            newByte = *decoder->data;

            ++decoder->data;
            --decoder->size;



            if (newByte != 0 && newByte != 0xFF)
            {
                if (newByte == (u8)JpegMarkerType::END_OF_IMAGE)
                {
                    decoder->size = 0;
                }
                else
                {
                    if ((newByte & 0xF8) != 0xD0)
                    {
                        COMMON_LE(("Invalid byte found during bits buffering"));

                        return NgosStatus::INVALID_DATA;
                    }

                    decoder->bitBuffer     =  (decoder->bitBuffer << 8) | newByte;
                    decoder->bitsAvailable += 8;
                }
            }
        }
    }



    return NgosStatus::OK;
}

NgosStatus Jpeg::getBits(JpegDecoder *decoder, u8 count, u64 *res)
{
    // COMMON_LT((" | decoder = 0x%p, count = %u, res = 0x%p", decoder, count, res)); // Commented to avoid too frequent logs

    COMMON_ASSERT(decoder,   "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(count > 0, "count is zero",   NgosStatus::ASSERTION);
    COMMON_ASSERT(res,       "res is null",     NgosStatus::ASSERTION);



    NgosStatus status = bufferBits(decoder, count);

    if (status != NgosStatus::OK)
    {
        return status;
    }



    *res = (decoder->bitBuffer >> (decoder->bitsAvailable - count)) & ((1ULL << count) - 1);



    return NgosStatus::OK;
}

NgosStatus Jpeg::readBits(JpegDecoder *decoder, u8 count, u64 *res)
{
    // COMMON_LT((" | decoder = 0x%p, count = %u, res = 0x%p", decoder, count, res)); // Commented to avoid too frequent logs

    COMMON_ASSERT(decoder,   "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(count > 0, "count is zero",   NgosStatus::ASSERTION);
    COMMON_ASSERT(res,       "res is null",     NgosStatus::ASSERTION);



    NgosStatus status = getBits(decoder, count, res);

    if (status != NgosStatus::OK)
    {
        return status;
    }



    decoder->bitsAvailable -= count;



    return NgosStatus::OK;
}

NgosStatus Jpeg::skipBits(JpegDecoder *decoder, u8 count)
{
    // COMMON_LT((" | decoder = 0x%p, count = %u", decoder, count)); // Commented to avoid too frequent logs

    COMMON_ASSERT(decoder,   "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(count > 0, "count is zero",   NgosStatus::ASSERTION);



    NgosStatus status = bufferBits(decoder, count);

    if (status != NgosStatus::OK)
    {
        return status;
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
