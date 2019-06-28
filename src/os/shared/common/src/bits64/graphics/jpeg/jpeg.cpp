#include "jpeg.h"

#include <common/src/bits64/graphics/jpeg/jpegdefinehuffmantablemarker.h>
#include <common/src/bits64/graphics/jpeg/jpegdefinequantizationtablemarker.h>
#include <common/src/bits64/graphics/jpeg/jpegdefinerestartintervalmarker.h>
#include <common/src/bits64/graphics/jpeg/jpegstartofframemarker.h>
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
        return NgosStatus::INVALID_DATA;
    }



    do
    {
        JpegMarkerHeader *marker = (JpegMarkerHeader *)decoder.data;



        if (decoder.size < 2 || marker->separator != JPEG_MARKER_HEADER_SEPARATOR)
        {
            return NgosStatus::INVALID_DATA;
        }



        COMMON_LVVV(("marker->type = 0x%02X (%s)", marker->type, jpegMarkerTypeToString(marker->type)));



        if (skip(&decoder, 2) != NgosStatus::OK)
        {
            return NgosStatus::INVALID_DATA;
        }



        NgosStatus status;

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
                COMMON_TEST_ASSERT(decoder.size == 0, NgosStatus::ASSERTION);

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

                return NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;

            default:
            {
                COMMON_LF(("Unknown marker type: %u", marker->type));

                return NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;
        }

        if (status != NgosStatus::OK)
        {
            return status;
        }
    } while(true);



    return NgosStatus::OK;
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
    decoder->restartInterval    = 0;

    memzero(decoder->quantizationTables, sizeof(decoder->quantizationTables));
    memzero(decoder->huffmanDcTables,    sizeof(decoder->huffmanDcTables));
    memzero(decoder->huffmanAcTables,    sizeof(decoder->huffmanAcTables));

    *decoder->image = 0;



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



    for (i64 i = 0; i < numberOfComponents; ++i)
    {
        JpegStartOfFrameComponent *component = &startOfFrameMarker->components[i];

        JpegStartOfFrameComponentId componentId         = component->id;
        u8                          samplingFactorX     = component->samplingFactorX;
        u8                          samplingFactorY     = component->samplingFactorY;
        u8                          quantizationTableId = component->quantizationTableId;

        COMMON_LVVV(("componentId         = %u (%s)", componentId, jpegStartOfFrameComponentIdToString(componentId)));
        COMMON_LVVV(("samplingFactorX     = %u", samplingFactorX));
        COMMON_LVVV(("samplingFactorY     = %u", samplingFactorY));
        COMMON_LVVV(("quantizationTableId = %u", quantizationTableId));

        if (
            (u8)componentId < (u8)JpegStartOfFrameComponentId::Y
            ||
            (u8)componentId > (u8)JpegStartOfFrameComponentId::Q
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
            ||
            !decoder->quantizationTables[quantizationTableId]
           )
        {
            return NgosStatus::INVALID_DATA;
        }
    }



    Image *image = (Image *)malloc(sizeof(Image) + width * height * sizeof(RgbPixel));

    if (!image)
    {
        return NgosStatus::OUT_OF_MEMORY;
    }

    image->width    = width;
    image->width    = height;
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



        u16 totalNumberOfSymbols = 0;

        for (i64 i = 0; i < (i64)sizeof(table->numberOfSymbols); ++i)
        {
            totalNumberOfSymbols += table->numberOfSymbols[i];
        }

        COMMON_LVVV(("totalNumberOfSymbols = %u", totalNumberOfSymbols));



        if (tableType == JPEG_HUFFMAN_TABLE_TYPE_DC)
        {
            COMMON_TEST_ASSERT(decoder->huffmanDcTables[tableId] == 0, NgosStatus::ASSERTION);

            decoder->huffmanDcTables[tableId] = table;
        }
        else
        {
            COMMON_TEST_ASSERT(decoder->huffmanAcTables[tableId] == 0, NgosStatus::ASSERTION);

            decoder->huffmanAcTables[tableId] = table;
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



    length    -= 2;
    u64 count =  length / sizeof(JpegQuantizationTable);

    COMMON_LVVV(("length = %u", length));
    COMMON_LVVV(("count  = %u", count));

    if (count * sizeof(JpegQuantizationTable) != length)
    {
        return NgosStatus::INVALID_DATA;
    }



    for (i64 i = 0; i < (i64)count; ++i)
    {
        JpegQuantizationTable *table   = &((JpegDefineQuantizationTableMarker *)marker)->tables[i];
        u8                     tableId = table->id;

        COMMON_LVVV(("tableId  = %u", tableId));

        if (tableId >= JPEG_QUANTIZATION_TABLE_COUNT)
        {
            return NgosStatus::INVALID_DATA;
        }



        COMMON_TEST_ASSERT(decoder->quantizationTables[tableId] == 0, NgosStatus::ASSERTION);

        decoder->quantizationTables[tableId] = table;
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



    return NgosStatus::OK;
}
