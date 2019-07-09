#include "png.h"

#include <common/src/bits64/graphics/png/lib/pngheader.h>
#include <common/src/bits64/graphics/rgbapixel.h>
#include <common/src/bits64/graphics/rgbpixel.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/malloc.h>
#include <ngos/linkage.h>
#include <ngos/utils.h>



NgosStatus Png::loadImage(u8 *data, u64 size, Image **image)
{
    COMMON_LT((" | data = 0x%p, size = %u, image = 0x%p", data, size, image));

    COMMON_ASSERT(data,     "data is null",  NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0, "size is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(image,    "image is null", NgosStatus::ASSERTION);

    COMMON_ASSERT(*((u64 *)&data[0]) == PNG_HEADER_SIGNATURE, "data is invalid", NgosStatus::ASSERTION);



    *image = 0;



    PngHeader *pngHeader = (PngHeader *)data;

    if (
        size <= sizeof(PngHeader) + sizeof(PngImageHeader) + 4 // 4 == size of CRC
        ||
        pngHeader->signature != PNG_HEADER_SIGNATURE
        ||
        pngHeader->imageHeaderChunk.type != PngChunkType::IHDR
       )
    {
        COMMON_LE(("Data is not a PNG image"));

        return NgosStatus::INVALID_DATA;
    }

    size -= sizeof(PngHeader) + sizeof(PngImageHeader) + 4; // 4 == size of CRC



    PngDecoder decoder;

    COMMON_ASSERT_EXECUTION(initDecoder(&decoder, image), NgosStatus::ASSERTION);



    NgosStatus  status = decodeImageHeader(&decoder, &pngHeader->imageHeaderChunk, ntohl(pngHeader->imageHeaderChunk.length));
    PngChunk   *chunk  = (PngChunk *)((u64)pngHeader + sizeof(PngHeader) + sizeof(PngImageHeader) + 4); // 4 == size of CRC

    while (status == NgosStatus::OK && size >= sizeof(PngChunk) + 4) // 4 == size of CRC
    {
        u32 chunkLength      = ntohl(chunk->length);
        u64 totalChunkLength = sizeof(PngChunk) + chunkLength + 4; // 4 == size of CRC

        COMMON_LVVV(("chunkLength      = %u", chunkLength));
        COMMON_LVVV(("chunk->type      = 0x%08X (%s)", chunk->type, pngChunkTypeToString(chunk->type)));
        COMMON_LVVV(("totalChunkLength = %u", totalChunkLength));
        COMMON_LVVV(("size             = %u", size));



        if (totalChunkLength > size)
        {
            COMMON_LE(("Invalid PNG image"));

            status = NgosStatus::INVALID_DATA;

            break;
        }



        status = decodeChunk(&decoder, chunk, chunkLength);



        chunk =  (PngChunk *)((u64)chunk + totalChunkLength);
        size  -= totalChunkLength;
    }



    if (
        status == NgosStatus::OK
        &&
        (
         size // size > 0
         ||
         !(*decoder.image)
        )
       )
    {
        COMMON_LE(("Invalid PNG image"));

        status = NgosStatus::INVALID_DATA;
    }



    if (status != NgosStatus::OK)
    {
        if (*decoder.image)
        {
            COMMON_ASSERT_EXECUTION(free(*decoder.image), NgosStatus::ASSERTION);

            *decoder.image = 0;
        }
    }



    COMMON_ASSERT_EXECUTION(releaseDecoder(&decoder), NgosStatus::ASSERTION);



    return status;
}

NgosStatus Png::initDecoder(PngDecoder *decoder, Image **image)
{
    COMMON_LT((" | decoder = 0x%p, image = 0x%p", decoder, image));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(image,   "image is null",   NgosStatus::ASSERTION);



    decoder->image                 = image;
    decoder->imageHeader           = 0;
    decoder->standardRgbColorSpace = 0;



    return NgosStatus::OK;
}

NgosStatus Png::releaseDecoder(PngDecoder *decoder)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(decoder); // TODO: Remove it when implemented



    return NgosStatus::OK;
}

NgosStatus Png::decodeChunk(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength)
{
    COMMON_LT((" | decoder = 0x%p, chunk = 0x%p, chunkLength = %u", decoder, chunk, chunkLength));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(chunk,   "chunk is null",   NgosStatus::ASSERTION);



    switch (chunk->type)
    {
        case PngChunkType::SRGB: return decodeStandardRgbColorSpace(decoder, chunk, chunkLength);

        case PngChunkType::GAMA:
        case PngChunkType::PHYS:
        case PngChunkType::TEXT:
        case PngChunkType::IDAT:
        case PngChunkType::IEND:
        {
            COMMON_LVV(("Ignore PNG chunk 0x%08X (%s)", chunk->type, pngChunkTypeToString(chunk->type)));
        }
        break;

        case PngChunkType::IHDR:
        {
            COMMON_LE(("Unexpected PNG chunk found: 0x%08X (%s)", chunk->type, pngChunkTypeToString(chunk->type)));
        }
        break;

        default:
        {
            COMMON_LW(("Unknown PNG chunk found: 0x%08X (%s)", chunk->type, pngChunkTypeToString(chunk->type)));
        }
        break;
    }



    return NgosStatus::OK;
}

NgosStatus Png::decodeImageHeader(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength)
{
    COMMON_LT((" | decoder = 0x%p, chunk = 0x%p, chunkLength = %u", decoder, chunk, chunkLength));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(chunk,   "chunk is null",   NgosStatus::ASSERTION);



    if (chunkLength != sizeof(PngImageHeader))
    {
        COMMON_LE(("Invalid %s chunk size (%u). Expected %u", pngChunkTypeToString(chunk->type), chunkLength, sizeof(PngImageHeader)));

        return NgosStatus::INVALID_DATA;
    }



    PngImageHeader *imageHeader = (PngImageHeader *)&chunk->data;

    u32 width  = ntohl(imageHeader->width);
    u32 height = ntohl(imageHeader->height);

    COMMON_LVVV(("width                          = %u", width));
    COMMON_LVVV(("height                         = %u", height));
    COMMON_LVVV(("imageHeader->bitDepth          = %u", imageHeader->bitDepth));
    COMMON_LVVV(("imageHeader->colorType         = %u (%s)", imageHeader->colorType, pngColorTypeToString(imageHeader->colorType)));
    COMMON_LVVV(("imageHeader->compressionMethod = %u (%s)", imageHeader->compressionMethod, pngCompressionMethodToString(imageHeader->compressionMethod)));
    COMMON_LVVV(("imageHeader->filterMethod      = %u (%s)", imageHeader->filterMethod, pngFilterMethodToString(imageHeader->filterMethod)));
    COMMON_LVVV(("imageHeader->interlaceMethod   = %u (%s)", imageHeader->interlaceMethod, pngInterlaceMethodToString(imageHeader->interlaceMethod)));



    if (
        !width // width == 0
        ||
        !height // height == 0
        ||
        width > 0xFFFF
        ||
        height > 0xFFFF
       )
    {
        COMMON_LE(("PNG image has invalid size %u x %u", width, height));

        return NgosStatus::INVALID_DATA;
    }



    NgosStatus status = checkColorTypeAndBitDepth(imageHeader->colorType, imageHeader->bitDepth);

    if (status != NgosStatus::OK)
    {
        COMMON_LE(("PNG image has invalid color type %u (%s) and bit depth %u", imageHeader->colorType, pngColorTypeToString(imageHeader->colorType), imageHeader->bitDepth));

        return status;
    }



    if (imageHeader->compressionMethod != PngCompressionMethod::DEFLATE)
    {
        COMMON_LE(("PNG decoder doesn't support compression method %u (%s)", imageHeader->compressionMethod, pngCompressionMethodToString(imageHeader->compressionMethod)));

        return NgosStatus::INVALID_DATA;
    }



    if (imageHeader->filterMethod != PngFilterMethod::ADAPTIVE)
    {
        COMMON_LE(("PNG decoder doesn't support filter method %u (%s)", imageHeader->filterMethod, pngFilterMethodToString(imageHeader->filterMethod)));

        return NgosStatus::INVALID_DATA;
    }



    if (
        imageHeader->interlaceMethod != PngInterlaceMethod::NONE
        &&
        imageHeader->interlaceMethod != PngInterlaceMethod::ADAM_7
       )
    {
        COMMON_LE(("PNG decoder doesn't support interlace method %u (%s)", imageHeader->interlaceMethod, pngInterlaceMethodToString(imageHeader->interlaceMethod)));

        return NgosStatus::INVALID_DATA;
    }



    bool hasAlpha = (imageHeader->colorType == PngColorType::RGBA || imageHeader->colorType == PngColorType::GREYSCALE_AND_ALPHA);



    Image *image = (Image *)malloc(sizeof(Image) + width * height * (hasAlpha ? sizeof(RgbaPixel) : sizeof(RgbPixel)));

    if (!image)
    {
        COMMON_LE(("Failed to allocate space for raw image data. Out of space"));

        return NgosStatus::OUT_OF_MEMORY;
    }

    image->width    = width;
    image->height   = height;
    image->hasAlpha = hasAlpha;



    COMMON_TEST_ASSERT(*decoder->image == 0, NgosStatus::ASSERTION);

    *decoder->image = image;



    COMMON_TEST_ASSERT(decoder->imageHeader == 0, NgosStatus::ASSERTION);

    decoder->imageHeader = imageHeader;



    return NgosStatus::OK;
}

NgosStatus Png::decodeStandardRgbColorSpace(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength)
{
    COMMON_LT((" | decoder = 0x%p, chunk = 0x%p, chunkLength = %u", decoder, chunk, chunkLength));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(chunk,   "chunk is null",   NgosStatus::ASSERTION);



    if (chunkLength != sizeof(PngStandardRgbColorSpace))
    {
        COMMON_LE(("Invalid %s chunk size (%u). Expected %u", pngChunkTypeToString(chunk->type), chunkLength, sizeof(PngImageHeader)));

        return NgosStatus::INVALID_DATA;
    }



    PngStandardRgbColorSpace *standardRgbColorSpace = (PngStandardRgbColorSpace *)&chunk->data;

    COMMON_LVVV(("standardRgbColorSpace->renderingIntent = %u (%s)", standardRgbColorSpace->renderingIntent, pngRenderingIntentToString(standardRgbColorSpace->renderingIntent)));



    if (decoder->standardRgbColorSpace)
    {
        COMMON_LE(("Found duplicate %s chunk", pngChunkTypeToString(chunk->type)));

        return NgosStatus::INVALID_DATA;
    }

    decoder->standardRgbColorSpace = standardRgbColorSpace;



    return NgosStatus::OK;
}

NgosStatus Png::checkColorTypeAndBitDepth(PngColorType colorType, u8 bitDepth)
{
    COMMON_LT((" | colorType = %u, bitDepth = %u", colorType, bitDepth));



    switch (colorType)
    {
        case PngColorType::GREYSCALE:
        {
            if (bitDepth != 1 && bitDepth != 2 && bitDepth != 4 && bitDepth != 8 && bitDepth != 16)
            {
                return NgosStatus::INVALID_DATA;
            }
        }
        break;

        case PngColorType::RGB:
        {
            if (bitDepth != 8 && bitDepth != 16)
            {
                return NgosStatus::INVALID_DATA;
            }
        }
        break;

        case PngColorType::PALETTE:
        {
            if (bitDepth != 1 && bitDepth != 2 && bitDepth != 4 && bitDepth != 8)
            {
                return NgosStatus::INVALID_DATA;
            }
        }
        break;

        case PngColorType::GREYSCALE_AND_ALPHA:
        {
            if (bitDepth != 8 && bitDepth != 16)
            {
                return NgosStatus::INVALID_DATA;
            }
        }
        break;

        case PngColorType::RGBA:
        {
            if (bitDepth != 8 && bitDepth != 16)
            {
                return NgosStatus::INVALID_DATA;
            }
        }
        break;

        default:
        {
            COMMON_LC(("Unexpected PNG color type: 0x%02X (%s)", colorType, pngColorTypeToString(colorType)));

            return NgosStatus::UNEXPECTED_BEHAVIOUR;
        }
        break;
    }



    return NgosStatus::OK;
}
