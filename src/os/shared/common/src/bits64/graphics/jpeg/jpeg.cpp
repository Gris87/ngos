#include "jpeg.h"

#include <common/src/bits64/graphics/jpeg/jpegmarkertype.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>



NgosStatus Jpeg::loadImage(u8 *data, u64 size, Image **image)
{
    COMMON_LT((" | data = 0x%p, size = %u, image = 0x%p", data, size, image));

    COMMON_ASSERT(data,     "data is null",  NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0, "size is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(image,    "image is null", NgosStatus::ASSERTION);

    COMMON_ASSERT(*((u16 *)&data[0])        == JPEG_START_OF_IMAGE_SIGNATURE, "data is invalid", NgosStatus::ASSERTION);
    COMMON_ASSERT(*((u16 *)&data[size - 2]) == JPEG_END_OF_IMAGE_SIGNATURE,   "data is invalid", NgosStatus::ASSERTION);



    JpegDecoder decoder;

    decoder.data = data;
    decoder.size = size;

    if (*((u16 *)&decoder.data[0]) != JPEG_START_OF_IMAGE_SIGNATURE)
    {
        return NgosStatus::INVALID_DATA;
    }



    if (skip(&decoder, 2) != NgosStatus::OK)
    {
        return NgosStatus::INVALID_DATA;
    }



    do
    {
        if (decoder.size < 2 || decoder.data[0] != JPEG_MARKER_SPLITTER)
        {
            return NgosStatus::INVALID_DATA;
        }



        JpegMarkerType markerType = (JpegMarkerType)decoder.data[1];

        COMMON_LVVV(("markerType = 0x%02X (%s)", markerType, jpegMarkerTypeToString(markerType)));



        if (skip(&decoder, 2) != NgosStatus::OK)
        {
            return NgosStatus::INVALID_DATA;
        }



        NgosStatus status;

        switch (markerType)
        {
            case JpegMarkerType::DEFINE_HUFFMAN_TABLE:
            {
                status = decodeDefineHuffmanTableMarker(&decoder);
            }
            break;

            case JpegMarkerType::DEFINE_QUANTIZATION_TABLE:
            {
                status = decodeDefineQuantizationTableMarker(&decoder);
            }
            break;

            case JpegMarkerType::DEFINE_RESTART_INTERVAL:
            {
                status = decodeDefineRestartIntervalMarker(&decoder);
            }
            break;

            case JpegMarkerType::START_OF_SCAN:
            {
                status = decodeStartOfScanMarker(&decoder);
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
            case JpegMarkerType::COMMENT:
            {
                status = skipMarker(&decoder);
            }
            break;

            case JpegMarkerType::START_OF_IMAGE:
            case JpegMarkerType::START_OF_FRAME_PROGRESSIVE_DCT:
            case JpegMarkerType::RESTART_0:
            case JpegMarkerType::RESTART_1:
            case JpegMarkerType::RESTART_2:
            case JpegMarkerType::RESTART_3:
            case JpegMarkerType::RESTART_4:
            case JpegMarkerType::RESTART_5:
            case JpegMarkerType::RESTART_6:
            case JpegMarkerType::RESTART_7:
            {
                COMMON_LF(("Unexpected marker type: %u", markerType));

                return NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;

            default:
            {
                COMMON_LF(("Unknown marker type: %u", markerType));

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

NgosStatus Jpeg::skipMarker(JpegDecoder *decoder)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Jpeg::decodeStartOfFrameBaselineDCT(JpegDecoder *decoder)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Jpeg::decodeDefineHuffmanTableMarker(JpegDecoder *decoder)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Jpeg::decodeDefineQuantizationTableMarker(JpegDecoder *decoder)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Jpeg::decodeDefineRestartIntervalMarker(JpegDecoder *decoder)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Jpeg::decodeStartOfScanMarker(JpegDecoder *decoder)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
