#include "png.h"

#include <common/src/bits64/graphics/png/lib/pngheader.h>
#include <common/src/bits64/graphics/rgbapixel.h>
#include <common/src/bits64/graphics/rgbpixel.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/malloc.h>
#include <common/src/bits64/memory/memory.h>
#include <common/src/bits64/zlib/zlib.h>
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



    if (status == NgosStatus::OK)
    {
        status = decodeImage(&decoder);
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



    decoder->image                   = image;
    decoder->imageHeader             = 0;
    decoder->standardRgbColorSpace   = 0;
    decoder->imageGamma              = 0;
    decoder->physicalPixelDimensions = 0;
    decoder->imageDataBuffer         = 0;
    decoder->imageDataSize           = 0;
    decoder->imageDataAllocatedSize  = 0;



    return NgosStatus::OK;
}

NgosStatus Png::releaseDecoder(PngDecoder *decoder)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    if (decoder->imageDataBuffer)
    {
        COMMON_ASSERT_EXECUTION(free(decoder->imageDataBuffer), NgosStatus::ASSERTION);
    }



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
        case PngChunkType::GAMA: return decodeImageGamma(decoder, chunk, chunkLength);
        case PngChunkType::PHYS: return decodePhysicalPixelDimensions(decoder, chunk, chunkLength);
        case PngChunkType::IDAT: return decodeImageData(decoder, chunk, chunkLength);

        case PngChunkType::IEND:
        {
            // Nothing
        }
        break;

        case PngChunkType::TEXT:
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
        COMMON_LE(("Invalid %s chunk size (%u). Expected %u", pngChunkTypeToString(chunk->type), chunkLength, sizeof(PngStandardRgbColorSpace)));

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

NgosStatus Png::decodeImageGamma(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength)
{
    COMMON_LT((" | decoder = 0x%p, chunk = 0x%p, chunkLength = %u", decoder, chunk, chunkLength));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(chunk,   "chunk is null",   NgosStatus::ASSERTION);



    if (chunkLength != sizeof(PngImageGamma))
    {
        COMMON_LE(("Invalid %s chunk size (%u). Expected %u", pngChunkTypeToString(chunk->type), chunkLength, sizeof(PngImageGamma)));

        return NgosStatus::INVALID_DATA;
    }



    PngImageGamma *imageGamma = (PngImageGamma *)&chunk->data;

    COMMON_LVVV(("imageGamma->gamma = %u", ntohl(imageGamma->gamma)));

    COMMON_TEST_ASSERT(decoder->standardRgbColorSpace == 0 || imageGamma->gamma == htonl(PNG_DEFAULT_IMAGE_GAMMA), NgosStatus::ASSERTION);



    if (decoder->imageGamma)
    {
        COMMON_LE(("Found duplicate %s chunk", pngChunkTypeToString(chunk->type)));

        return NgosStatus::INVALID_DATA;
    }

    decoder->imageGamma = imageGamma;



    return NgosStatus::OK;
}

NgosStatus Png::decodePhysicalPixelDimensions(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength)
{
    COMMON_LT((" | decoder = 0x%p, chunk = 0x%p, chunkLength = %u", decoder, chunk, chunkLength));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(chunk,   "chunk is null",   NgosStatus::ASSERTION);



    if (chunkLength != sizeof(PngPhysicalPixelDimensions))
    {
        COMMON_LE(("Invalid %s chunk size (%u). Expected %u", pngChunkTypeToString(chunk->type), chunkLength, sizeof(PngPhysicalPixelDimensions)));

        return NgosStatus::INVALID_DATA;
    }



    PngPhysicalPixelDimensions *physicalPixelDimensions = (PngPhysicalPixelDimensions *)&chunk->data;

    COMMON_LVVV(("physicalPixelDimensions->pixelsPerUnitX = %u", ntohl(physicalPixelDimensions->pixelsPerUnitX)));
    COMMON_LVVV(("physicalPixelDimensions->pixelsPerUnitY = %u", ntohl(physicalPixelDimensions->pixelsPerUnitY)));
    COMMON_LVVV(("physicalPixelDimensions->unitSpecifier  = %u (%s)", physicalPixelDimensions->unitSpecifier, pngUnitSpecifierToString(physicalPixelDimensions->unitSpecifier)));



    if (decoder->physicalPixelDimensions)
    {
        COMMON_LE(("Found duplicate %s chunk", pngChunkTypeToString(chunk->type)));

        return NgosStatus::INVALID_DATA;
    }

    decoder->physicalPixelDimensions = physicalPixelDimensions;



    return NgosStatus::OK;
}

NgosStatus Png::decodeImageData(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength)
{
    COMMON_LT((" | decoder = 0x%p, chunk = 0x%p, chunkLength = %u", decoder, chunk, chunkLength));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(chunk,   "chunk is null",   NgosStatus::ASSERTION);



    return addImageDataToBuffer(decoder, chunk->data, chunkLength);
}

NgosStatus Png::decodeImage(PngDecoder *decoder)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    NgosStatus status = decompressImageData(decoder);

    if (status != NgosStatus::OK)
    {
        return status;
    }



    return NgosStatus::OK;
}

NgosStatus Png::decompressImageData(PngDecoder *decoder)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    if (!decoder->imageDataBuffer)
    {
        COMMON_LE(("IDAT chunk not found in PNG image"));

        return NgosStatus::INVALID_DATA;
    }



    u64 decompressedSize;
    COMMON_ASSERT_EXECUTION(getImageDataDecompressedSize(decoder, &decompressedSize), NgosStatus::ASSERTION);

    COMMON_LVVV(("decompressedSize = %u", decompressedSize));



    u8 *buffer = (u8 *)malloc(decompressedSize);

    if (!buffer)
    {
        COMMON_LE(("Failed to allocate space for decompressed image data buffer. Out of space"));

        return NgosStatus::OUT_OF_MEMORY;
    }



    NgosStatus status = ZLib::decompress(decoder->imageDataBuffer, buffer, decoder->imageDataSize, decompressedSize);

    if (status != NgosStatus::OK)
    {
        return status;
    }



    COMMON_ASSERT_EXECUTION(free(decoder->imageDataBuffer), NgosStatus::ASSERTION);

    decoder->imageDataBuffer        = buffer;
    decoder->imageDataSize          = decompressedSize;
    decoder->imageDataAllocatedSize = decompressedSize;



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

NgosStatus Png::addImageDataToBuffer(PngDecoder *decoder, u8 *data, u64 count)
{
    COMMON_LT((" | decoder = 0x%p, data = 0x%p, count = %u", decoder, data, count));

    COMMON_ASSERT(decoder,   "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(data,      "data is null",    NgosStatus::ASSERTION);
    COMMON_ASSERT(count > 0, "count is zero",   NgosStatus::ASSERTION);



    u64 oldSize          = decoder->imageDataSize;
    u64 newSize          = oldSize + count;
    u64 oldAllocatedSize = decoder->imageDataAllocatedSize;



    if (newSize > oldAllocatedSize)
    {
        u64 newAllocatedSize;

        if (oldAllocatedSize) // oldAllocatedSize != 0
        {
            newAllocatedSize = oldAllocatedSize << 1;

            if (newSize > newAllocatedSize)
            {
                newAllocatedSize = newSize;
            }
        }
        else
        {
            newAllocatedSize = newSize;
        }



        u8 *buffer = (u8 *)malloc(newAllocatedSize);

        if (!buffer)
        {
            COMMON_LE(("Failed to allocate space for image data buffer. Out of space"));

            return NgosStatus::OUT_OF_MEMORY;
        }



        if (oldAllocatedSize) // oldAllocatedSize != 0
        {
            memcpy(buffer, decoder->imageDataBuffer, oldSize);

            COMMON_ASSERT_EXECUTION(free(decoder->imageDataBuffer), NgosStatus::ASSERTION);
        }



        decoder->imageDataBuffer        = buffer;
        decoder->imageDataAllocatedSize = newAllocatedSize;
    }



    memcpy(&decoder->imageDataBuffer[oldSize], data, count);

    decoder->imageDataSize = newSize;



    return NgosStatus::OK;
}

NgosStatus Png::getImageDataDecompressedSize(PngDecoder *decoder, u64 *size)
{
    COMMON_LT((" | decoder = 0x%p, size = 0x%p", decoder, size));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(size,    "size is null",    NgosStatus::ASSERTION);



    *size = 0;

    u16 width  = (*decoder->image)->width;
    u16 height = (*decoder->image)->height;

    u8 bitsPerPixel;
    COMMON_ASSERT_EXECUTION(getNumberOfBitsPerPixel(decoder, &bitsPerPixel), NgosStatus::ASSERTION);



    switch (decoder->imageHeader->interlaceMethod)
    {
        case PngInterlaceMethod::NONE:
        {
            COMMON_ASSERT_EXECUTION(getImageDataDecompressedSizeForBlock(width, height, bitsPerPixel, size), NgosStatus::ASSERTION);
        }
        break;

        case PngInterlaceMethod::ADAM_7:
        {
            COMMON_ASSERT_EXECUTION(getImageDataDecompressedSizeForBlock((width + 7) >> 3, (height + 7) >> 3, bitsPerPixel, size), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(getImageDataDecompressedSizeForBlock((width + 3) >> 2, (height + 3) >> 3, bitsPerPixel, size), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(getImageDataDecompressedSizeForBlock((width + 1) >> 1, (height + 1) >> 2, bitsPerPixel, size), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(getImageDataDecompressedSizeForBlock((width + 0),      (height + 0) >> 1, bitsPerPixel, size), NgosStatus::ASSERTION);

            if (width > 1)
            {
                COMMON_ASSERT_EXECUTION(getImageDataDecompressedSizeForBlock((width + 0) >> 1, (height + 1) >> 1, bitsPerPixel, size), NgosStatus::ASSERTION);

                if (width > 2)
                {
                    COMMON_ASSERT_EXECUTION(getImageDataDecompressedSizeForBlock((width + 1) >> 2, (height + 3) >> 2, bitsPerPixel, size), NgosStatus::ASSERTION);

                    if (width > 4)
                    {
                        COMMON_ASSERT_EXECUTION(getImageDataDecompressedSizeForBlock((width + 3) >> 3, (height + 7) >> 3, bitsPerPixel, size), NgosStatus::ASSERTION);
                    }
                }
            }
        }
        break;

        default:
        {
            COMMON_LE(("Unknown interlace method %u (%s)", decoder->imageHeader->interlaceMethod, pngInterlaceMethodToString(decoder->imageHeader->interlaceMethod)));

            return NgosStatus::INVALID_DATA;
        }
        break;
    }



    return NgosStatus::OK;
}

NgosStatus Png::getImageDataDecompressedSizeForBlock(u16 width, u16 height, u8 bitsPerPixel, u64 *size)
{
    COMMON_LT((" | width = %u, height = %u, bitsPerPixel = %u, size = 0x%p", width, height, bitsPerPixel, size));

    COMMON_ASSERT(width > 0,        "width is zero",        NgosStatus::ASSERTION);
    COMMON_ASSERT(height > 0,       "height is zero",       NgosStatus::ASSERTION);
    COMMON_ASSERT(bitsPerPixel > 0, "bitsPerPixel is zero", NgosStatus::ASSERTION);
    COMMON_ASSERT(size,             "size is null",         NgosStatus::ASSERTION);



    *size += (((width >> 3) * bitsPerPixel) + DIV_UP((width & 7) * bitsPerPixel, 8) + 1) * height;



    return NgosStatus::OK;
}

NgosStatus Png::getNumberOfBitsPerPixel(PngDecoder *decoder, u8 *res)
{
    COMMON_LT((" | decoder = 0x%p, res = 0x%p", decoder, res));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(res,     "res is null",     NgosStatus::ASSERTION);



    switch (decoder->imageHeader->colorType)
    {
        case PngColorType::GREYSCALE:           *res = decoder->imageHeader->bitDepth;      break;
        case PngColorType::RGB:                 *res = decoder->imageHeader->bitDepth * 3;  break;
        case PngColorType::PALETTE:             *res = decoder->imageHeader->bitDepth;      break;
        case PngColorType::GREYSCALE_AND_ALPHA: *res = decoder->imageHeader->bitDepth << 1; break; // "<< 1" == "* 2"
        case PngColorType::RGBA:                *res = decoder->imageHeader->bitDepth << 2; break; // "<< 2" == "* 4"

        default:
        {
            COMMON_LC(("Unexpected PNG color type: 0x%02X (%s)", decoder->imageHeader->colorType, pngColorTypeToString(decoder->imageHeader->colorType)));

            return NgosStatus::UNEXPECTED_BEHAVIOUR;
        }
        break;
    }



    return NgosStatus::OK;
}
