#include "png.h"

#include <common/src/bits64/checksum/crc.h>
#include <common/src/bits64/graphics/graphics.h>
#include <common/src/bits64/graphics/png/lib/pngheader.h>
#include <common/src/bits64/graphics/rgbapixel.h>
#include <common/src/bits64/graphics/rgbpixel.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/malloc.h>
#include <common/src/bits64/memory/memory.h>
#include <common/src/bits64/string/string.h>
#include <common/src/bits64/zlib/zlib.h>
#include <ngos/linkage.h>
#include <ngos/utils.h>



NgosStatus Png::loadImage(u8 *data, u64 size, bool withNinePatch, Image **image)
{
    COMMON_LT((" | data = 0x%p, size = %u, withNinePatch = %u, image = 0x%p", data, size, withNinePatch, image));

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



    if (status == NgosStatus::OK)
    {
        status = decodeImage(&decoder);
    }



    if (status == NgosStatus::OK)
    {
        status = imagePostprocess(&decoder, withNinePatch);
    }



    COMMON_ASSERT_EXECUTION(releaseDecoder(&decoder), NgosStatus::ASSERTION);



    if (status != NgosStatus::OK)
    {
        if (*decoder.image)
        {
            delete *decoder.image;

            *decoder.image = 0;
        }
    }



    return status;
}

NgosStatus Png::initDecoder(PngDecoder *decoder, Image **image)
{
    COMMON_LT((" | decoder = 0x%p, image = 0x%p", decoder, image));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(image,   "image is null",   NgosStatus::ASSERTION);



    decoder->image                     = image;
    decoder->imageHeader               = 0;
    decoder->primaryChromaticities     = 0;
    decoder->imageGamma                = 0;
    decoder->embeddedIccProfile        = 0;
    decoder->significantBits           = 0;
    decoder->standardRgbColorSpace     = 0;
    decoder->physicalPixelDimensions   = 0;
    decoder->imageLastModificationTime = 0;
    decoder->imageDataBuffer           = 0;
    decoder->imageDataSize             = 0;
    decoder->imageDataAllocatedSize    = 0;
    decoder->rawImageBuffer            = 0;
    decoder->bitsPerPixel              = 0;



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



    if (
        decoder->rawImageBuffer
        &&
        (
         !(*decoder->image)
         ||
         decoder->rawImageBuffer != (*decoder->image)->getBuffer()
        )
       )
    {
        COMMON_ASSERT_EXECUTION(free(decoder->rawImageBuffer), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus Png::decodeChunk(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength)
{
    COMMON_LT((" | decoder = 0x%p, chunk = 0x%p, chunkLength = %u", decoder, chunk, chunkLength));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(chunk,   "chunk is null",   NgosStatus::ASSERTION);



    u32 crc32Checksum = ntohl(*(u32 *)((u64)&chunk->data + chunkLength));
    AVOID_UNUSED(crc32Checksum);

    COMMON_LVVV(("crc32Checksum = 0x%08X", crc32Checksum));

    COMMON_TEST_ASSERT(crc32Checksum == Crc::crc32((u8 *)&chunk->type, sizeof(chunk->type) + chunkLength), NgosStatus::ASSERTION);



    switch (chunk->type)
    {
        case PngChunkType::CHRM: return decodePrimaryChromaticities(decoder, chunk, chunkLength);
        case PngChunkType::GAMA: return decodeImageGamma(decoder, chunk, chunkLength);
        case PngChunkType::ICCP: return decodeEmbeddedIccProfile(decoder, chunk, chunkLength);
        case PngChunkType::SBIT: return decodeSignificantBits(decoder, chunk, chunkLength);
        case PngChunkType::SRGB: return decodeStandardRgbColorSpace(decoder, chunk, chunkLength);
        case PngChunkType::PHYS: return decodePhysicalPixelDimensions(decoder, chunk, chunkLength);
        case PngChunkType::TIME: return decodeImageLastModificationTime(decoder, chunk, chunkLength);
        case PngChunkType::IDAT: return decodeImageData(decoder, chunk, chunkLength);

        case PngChunkType::IEND:
        {
            // Nothing
        }
        break;

        case PngChunkType::ITXT:
        case PngChunkType::TEXT:
        case PngChunkType::ZTXT:
        {
            COMMON_LVV(("Ignore PNG chunk 0x%08X (%s)", chunk->type, pngChunkTypeToString(chunk->type)));
        }
        break;

        case PngChunkType::IHDR:
        case PngChunkType::PLTE:
        case PngChunkType::BKGD:
        case PngChunkType::HIST:
        case PngChunkType::TRNS:
        case PngChunkType::SPLT:
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



    u32 crc32Checksum = ntohl(*(u32 *)((u64)&chunk->data + chunkLength));
    AVOID_UNUSED(crc32Checksum);

    COMMON_LVVV(("crc32Checksum = 0x%08X", crc32Checksum));

    COMMON_TEST_ASSERT(crc32Checksum == Crc::crc32((u8 *)&chunk->type, sizeof(chunk->type) + chunkLength), NgosStatus::ASSERTION);



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



    switch (imageHeader->colorType)
    {
        case PngColorType::GREYSCALE:           decoder->bitsPerPixel = imageHeader->bitDepth;      break;
        case PngColorType::RGB:                 decoder->bitsPerPixel = imageHeader->bitDepth * 3;  break;
        case PngColorType::PALETTE:             decoder->bitsPerPixel = imageHeader->bitDepth;      break;
        case PngColorType::GREYSCALE_AND_ALPHA: decoder->bitsPerPixel = imageHeader->bitDepth << 1; break; // "<< 1" == "* 2"
        case PngColorType::RGBA:                decoder->bitsPerPixel = imageHeader->bitDepth << 2; break; // "<< 2" == "* 4"

        default:
        {
            COMMON_LC(("Unexpected PNG color type: 0x%02X (%s)", imageHeader->colorType, pngColorTypeToString(imageHeader->colorType)));

            return NgosStatus::UNEXPECTED_BEHAVIOUR;
        }
        break;
    }

    COMMON_LVVV(("decoder->bitsPerPixel = %u", decoder->bitsPerPixel));



    bool hasAlpha = (imageHeader->colorType == PngColorType::RGBA || imageHeader->colorType == PngColorType::GREYSCALE_AND_ALPHA);



    COMMON_TEST_ASSERT(*decoder->image == 0, NgosStatus::ASSERTION);

    *decoder->image = new Image(width, height, hasAlpha, true);



    COMMON_TEST_ASSERT(decoder->imageHeader == 0, NgosStatus::ASSERTION);

    decoder->imageHeader = imageHeader;



    return NgosStatus::OK;
}

NgosStatus Png::decodePrimaryChromaticities(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength)
{
    COMMON_LT((" | decoder = 0x%p, chunk = 0x%p, chunkLength = %u", decoder, chunk, chunkLength));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(chunk,   "chunk is null",   NgosStatus::ASSERTION);



    if (chunkLength != sizeof(PngPrimaryChromaticities))
    {
        COMMON_LE(("Invalid %s chunk size (%u). Expected %u", pngChunkTypeToString(chunk->type), chunkLength, sizeof(PngPrimaryChromaticities)));

        return NgosStatus::INVALID_DATA;
    }



    PngPrimaryChromaticities *primaryChromaticities = (PngPrimaryChromaticities *)&chunk->data;

    COMMON_LVVV(("primaryChromaticities->whitePointX = %u", ntohl(primaryChromaticities->whitePointX)));
    COMMON_LVVV(("primaryChromaticities->whitePointY = %u", ntohl(primaryChromaticities->whitePointY)));
    COMMON_LVVV(("primaryChromaticities->redX        = %u", ntohl(primaryChromaticities->redX)));
    COMMON_LVVV(("primaryChromaticities->redY        = %u", ntohl(primaryChromaticities->redY)));
    COMMON_LVVV(("primaryChromaticities->greenX      = %u", ntohl(primaryChromaticities->greenX)));
    COMMON_LVVV(("primaryChromaticities->greenY      = %u", ntohl(primaryChromaticities->greenY)));
    COMMON_LVVV(("primaryChromaticities->blueX       = %u", ntohl(primaryChromaticities->blueX)));
    COMMON_LVVV(("primaryChromaticities->blueY       = %u", ntohl(primaryChromaticities->blueY)));

    COMMON_TEST_ASSERT(!decoder->standardRgbColorSpace || primaryChromaticities->whitePointX == htonl(PNG_DEFAULT_WHITE_POINT_X), NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(!decoder->standardRgbColorSpace || primaryChromaticities->whitePointY == htonl(PNG_DEFAULT_WHITE_POINT_Y), NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(!decoder->standardRgbColorSpace || primaryChromaticities->redX        == htonl(PNG_DEFAULT_RED_X),         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(!decoder->standardRgbColorSpace || primaryChromaticities->redY        == htonl(PNG_DEFAULT_RED_Y),         NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(!decoder->standardRgbColorSpace || primaryChromaticities->greenX      == htonl(PNG_DEFAULT_GREEN_X),       NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(!decoder->standardRgbColorSpace || primaryChromaticities->greenY      == htonl(PNG_DEFAULT_GREEN_Y),       NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(!decoder->standardRgbColorSpace || primaryChromaticities->blueX       == htonl(PNG_DEFAULT_BLUE_X),        NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(!decoder->standardRgbColorSpace || primaryChromaticities->blueY       == htonl(PNG_DEFAULT_BLUE_Y),        NgosStatus::ASSERTION);



    if (decoder->primaryChromaticities)
    {
        COMMON_LE(("Found duplicate %s chunk", pngChunkTypeToString(chunk->type)));

        return NgosStatus::INVALID_DATA;
    }

    decoder->primaryChromaticities = primaryChromaticities;



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

    COMMON_TEST_ASSERT(!decoder->standardRgbColorSpace || imageGamma->gamma == htonl(PNG_DEFAULT_IMAGE_GAMMA), NgosStatus::ASSERTION);



    if (decoder->imageGamma)
    {
        COMMON_LE(("Found duplicate %s chunk", pngChunkTypeToString(chunk->type)));

        return NgosStatus::INVALID_DATA;
    }

    decoder->imageGamma = imageGamma;



    return NgosStatus::OK;
}

NgosStatus Png::decodeEmbeddedIccProfile(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength)
{
    COMMON_LT((" | decoder = 0x%p, chunk = 0x%p, chunkLength = %u", decoder, chunk, chunkLength));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(chunk,   "chunk is null",   NgosStatus::ASSERTION);



    if (chunkLength < sizeof(PngEmbeddedIccProfile) + 1)
    {
        COMMON_LE(("Invalid %s chunk size (%u). Expected at least %u", pngChunkTypeToString(chunk->type), chunkLength, sizeof(PngEmbeddedIccProfile) + 1));

        return NgosStatus::INVALID_DATA;
    }



    PngEmbeddedIccProfile *embeddedIccProfile = (PngEmbeddedIccProfile *)&chunk->data;



    i64 len = strnlen(embeddedIccProfile->profileName, sizeof(embeddedIccProfile->profileName));

    if (len >= (i64)sizeof(embeddedIccProfile->profileName))
    {
        COMMON_LE(("Invalid %s chunk", pngChunkTypeToString(chunk->type)));

        return NgosStatus::INVALID_DATA;
    }

    PngCompressionMethod compressionMethod = (PngCompressionMethod)chunk->data[len + 1];

    AVOID_UNUSED(compressionMethod);



    COMMON_LVVV(("embeddedIccProfile->profileName       = %s",      embeddedIccProfile->profileName));
    COMMON_LVVV(("embeddedIccProfile->compressionMethod = %u (%s)", compressionMethod, pngCompressionMethodToString(compressionMethod)));



    if (decoder->embeddedIccProfile)
    {
        COMMON_LE(("Found duplicate %s chunk", pngChunkTypeToString(chunk->type)));

        return NgosStatus::INVALID_DATA;
    }

    decoder->embeddedIccProfile = embeddedIccProfile;



    return NgosStatus::OK;
}

NgosStatus Png::decodeSignificantBits(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength)
{
    COMMON_LT((" | decoder = 0x%p, chunk = 0x%p, chunkLength = %u", decoder, chunk, chunkLength));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(chunk,   "chunk is null",   NgosStatus::ASSERTION);



    if (chunkLength != sizeof(PngSignificantBits))
    {
        COMMON_LE(("Invalid %s chunk size (%u). Expected %u", pngChunkTypeToString(chunk->type), chunkLength, sizeof(PngSignificantBits)));

        return NgosStatus::INVALID_DATA;
    }



    PngSignificantBits *significantBits = (PngSignificantBits *)&chunk->data;



    // Validation
    {
        COMMON_LVVV(("significantBits->redBits   = %u", significantBits->redBits));
        COMMON_LVVV(("significantBits->greenBits = %u", significantBits->greenBits));
        COMMON_LVVV(("significantBits->blueBits  = %u", significantBits->blueBits));
        COMMON_LVVV(("significantBits->alphaBits = %u", significantBits->alphaBits));

        COMMON_TEST_ASSERT(significantBits->redBits   == 8, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(significantBits->greenBits == 8, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(significantBits->blueBits  == 8, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(significantBits->alphaBits == 8, NgosStatus::ASSERTION);
    }



    if (decoder->significantBits)
    {
        COMMON_LE(("Found duplicate %s chunk", pngChunkTypeToString(chunk->type)));

        return NgosStatus::INVALID_DATA;
    }

    decoder->significantBits = significantBits;



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

NgosStatus Png::decodeImageLastModificationTime(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength)
{
    COMMON_LT((" | decoder = 0x%p, chunk = 0x%p, chunkLength = %u", decoder, chunk, chunkLength));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(chunk,   "chunk is null",   NgosStatus::ASSERTION);



    if (chunkLength != sizeof(PngImageLastModificationTime))
    {
        COMMON_LE(("Invalid %s chunk size (%u). Expected %u", pngChunkTypeToString(chunk->type), chunkLength, sizeof(PngImageLastModificationTime)));

        return NgosStatus::INVALID_DATA;
    }



    PngImageLastModificationTime *imageLastModificationTime = (PngImageLastModificationTime *)&chunk->data;

    COMMON_LVVV(("imageLastModificationTime->year   = %u", ntohs(imageLastModificationTime->year)));
    COMMON_LVVV(("imageLastModificationTime->month  = %u", imageLastModificationTime->month));
    COMMON_LVVV(("imageLastModificationTime->day    = %u", imageLastModificationTime->day));
    COMMON_LVVV(("imageLastModificationTime->hour   = %u", imageLastModificationTime->hour));
    COMMON_LVVV(("imageLastModificationTime->minute = %u", imageLastModificationTime->minute));
    COMMON_LVVV(("imageLastModificationTime->second = %u", imageLastModificationTime->second));



    if (decoder->imageLastModificationTime)
    {
        COMMON_LE(("Found duplicate %s chunk", pngChunkTypeToString(chunk->type)));

        return NgosStatus::INVALID_DATA;
    }

    decoder->imageLastModificationTime = imageLastModificationTime;



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



    return convertImageDataToImage(decoder);
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

    decoder->imageDataBuffer = buffer;



    return NgosStatus::OK;
}

NgosStatus Png::convertImageDataToImage(PngDecoder *decoder)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    if (
        (
         decoder->imageHeader->colorType == PngColorType::RGB
         ||
         decoder->imageHeader->colorType == PngColorType::RGBA
        )
        &&
        decoder->imageHeader->bitDepth == 8
       )
    {
        decoder->rawImageBuffer = (*decoder->image)->getBuffer();
    }
    else
    {
        u64 rawImageSize;
        COMMON_ASSERT_EXECUTION(getRawImageSize(decoder, &rawImageSize), NgosStatus::ASSERTION);

        COMMON_LVVV(("rawImageSize = %u", rawImageSize));



        u8 *buffer = (u8 *)malloc(rawImageSize);

        if (!buffer)
        {
            COMMON_LE(("Failed to allocate space for raw image buffer. Out of space"));

            return NgosStatus::OUT_OF_MEMORY;
        }

        decoder->rawImageBuffer = buffer;
    }



    NgosStatus status = processImageInterlace(decoder);

    if (status != NgosStatus::OK)
    {
        return status;
    }



    return NgosStatus::OK;
}

NgosStatus Png::processImageInterlace(PngDecoder *decoder)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    switch (decoder->imageHeader->interlaceMethod)
    {
        case PngInterlaceMethod::NONE:   return processImageWithoutInterlace(decoder);
        case PngInterlaceMethod::ADAM_7: return processImageWithAdam7Interlace(decoder);

        default:
        {
            COMMON_LE(("Unknown interlace method %u (%s)", decoder->imageHeader->interlaceMethod, pngInterlaceMethodToString(decoder->imageHeader->interlaceMethod)));

            return NgosStatus::UNEXPECTED_BEHAVIOUR;
        }
        break;
    }
}

NgosStatus Png::processImageWithoutInterlace(PngDecoder *decoder)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    u16 width        = (*decoder->image)->getWidth();
    u16 height       = (*decoder->image)->getHeight();
    u8  bitsPerPixel = decoder->bitsPerPixel;



    NgosStatus status;

    if (
        bitsPerPixel < 8
        &&
        width * bitsPerPixel != DIV_UP(width * bitsPerPixel, 8) << 3 // "<< 3" == "* 8"
       )
    {
        status = unfilter(decoder, decoder->imageDataBuffer, decoder->imageDataBuffer, width, height);

        if (status != NgosStatus::OK)
        {
            return status;
        }

        status = removePaddingBits(decoder->imageDataBuffer, decoder->rawImageBuffer, DIV_UP(width * bitsPerPixel, 8) << 3, width * bitsPerPixel, height); // "<< 3" == "* 8"
    }
    else
    {
        status = unfilter(decoder, decoder->imageDataBuffer, decoder->rawImageBuffer, width, height);
    }



    return status;
}

NgosStatus Png::processImageWithAdam7Interlace(PngDecoder *decoder)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(decoder);



    return NgosStatus::OK;
}

NgosStatus Png::imagePostprocess(PngDecoder *decoder, bool withNinePatch)
{
    COMMON_LT((" | decoder = 0x%p, withNinePatch = %u", decoder, withNinePatch));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    if (withNinePatch)
    {
        COMMON_ASSERT_EXECUTION(applyNinePatch(decoder), NgosStatus::ASSERTION);
    }



    Image *image      = *decoder->image;
    i64    resolution = image->getWidth() * image->getHeight();



    if (image->isRgba())
    {
        RgbaPixel *pixel = image->getRgbaBuffer();

        for (i64 i = 0; i < resolution; ++i)
        {
            if (pixel->alpha != 0xFF)
            {
                image->setOpaque(false);

                break;
            }

            ++pixel;
        }



        pixel = image->getRgbaBuffer();

        for (i64 i = 0; i < resolution; ++i)
        {
            u8 temp     = pixel->red;
            pixel->red  = pixel->blue;
            pixel->blue = temp;

            ++pixel;
        }
    }
    else
    {
        RgbPixel *pixel = image->getRgbBuffer();

        for (i64 i = 0; i < resolution; ++i)
        {
            u8 temp     = pixel->red;
            pixel->red  = pixel->blue;
            pixel->blue = temp;

            ++pixel;
        }
    }



    return NgosStatus::OK;
}

NgosStatus Png::applyNinePatch(PngDecoder *decoder)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    Image *image = *decoder->image;

    if (
        image->getWidth() > 2
        &&
        image->getHeight() > 2
       )
    {
        Image *newImage = new Image(image->getWidth() - 2, image->getHeight() - 2, image->isRgba(), true);

        COMMON_ASSERT_EXECUTION(newImage->createNinePatch(), NgosStatus::ASSERTION);
        NinePatch *patch = newImage->getNinePatch();



        u16 from = 0;
        u16 to   = 0;

        if (image->isRgba())
        {
            for (i64 i = 1; i < image->getWidth() - 1; ++i)
            {
                RgbaPixel *pixel = &image->getRgbaBuffer()[i];

                if (
                    !pixel->red   // pixel->red   == 0
                    &&
                    !pixel->green // pixel->green == 0
                    &&
                    !pixel->blue  // pixel->blue  == 0
                    &&
                    pixel->alpha == 0xFF
                   )
                {
                    if (!from) // from == 0
                    {
                        from = i;
                    }

                    to = i;
                }
                else
                {
                    if (from) // from != 0
                    {
                        patch->addStretchRangeX(StretchRange(from - 1, to));

                        from = 0;
                        to   = 0;
                    }
                }
            }
        }
        else
        {
            for (i64 i = 1; i < image->getWidth() - 1; ++i)
            {
                RgbPixel *pixel = &image->getRgbBuffer()[i];

                if (
                    !pixel->red   // pixel->red   == 0
                    &&
                    !pixel->green // pixel->green == 0
                    &&
                    !pixel->blue  // pixel->blue  == 0
                   )
                {
                    if (!from) // from == 0
                    {
                        from = i;
                    }

                    to = i;
                }
                else
                {
                    if (from) // from != 0
                    {
                        patch->addStretchRangeX(StretchRange(from - 1, to));

                        from = 0;
                        to   = 0;
                    }
                }
            }
        }

        if (from) // from != 0
        {
            patch->addStretchRangeX(StretchRange(from - 1, to));

            from = 0;
            to   = 0;
        }



        if (image->isRgba())
        {
            for (i64 i = 1; i < image->getHeight() - 1; ++i)
            {
                RgbaPixel *pixel = &image->getRgbaBuffer()[i * image->getWidth()];

                if (
                    !pixel->red   // pixel->red   == 0
                    &&
                    !pixel->green // pixel->green == 0
                    &&
                    !pixel->blue  // pixel->blue  == 0
                    &&
                    pixel->alpha == 0xFF
                   )
                {
                    if (!from) // from == 0
                    {
                        from = i;
                    }

                    to = i;
                }
                else
                {
                    if (from) // from != 0
                    {
                        patch->addStretchRangeY(StretchRange(from - 1, to));

                        from = 0;
                        to   = 0;
                    }
                }
            }
        }
        else
        {
            for (i64 i = 1; i < image->getHeight() - 1; ++i)
            {
                RgbPixel *pixel = &image->getRgbBuffer()[i * image->getWidth()];

                if (
                    !pixel->red   // pixel->red   == 0
                    &&
                    !pixel->green // pixel->green == 0
                    &&
                    !pixel->blue  // pixel->blue  == 0
                   )
                {
                    if (!from) // from == 0
                    {
                        from = i;
                    }

                    to = i;
                }
                else
                {
                    if (from) // from != 0
                    {
                        patch->addStretchRangeY(StretchRange(from - 1, to));

                        from = 0;
                        to   = 0;
                    }
                }
            }
        }

        if (from) // from != 0
        {
            patch->addStretchRangeY(StretchRange(from - 1, to));
        }



        u64 lastPosY = (image->getHeight() - 1) * image->getWidth();

        if (image->isRgba())
        {
            for (i64 i = 1; i < image->getWidth() - 1; ++i)
            {
                RgbaPixel *pixel = &image->getRgbaBuffer()[lastPosY + i];

                if (
                    !pixel->red   // pixel->red   == 0
                    &&
                    !pixel->green // pixel->green == 0
                    &&
                    !pixel->blue  // pixel->blue  == 0
                    &&
                    pixel->alpha == 0xFF
                   )
                {
                    patch->setPaddingLeft(i - 1);

                    break;
                }
            }

            for (i64 i = image->getWidth() - 2; i >= 1; --i)
            {
                RgbaPixel *pixel = &image->getRgbaBuffer()[lastPosY + i];

                if (
                    !pixel->red   // pixel->red   == 0
                    &&
                    !pixel->green // pixel->green == 0
                    &&
                    !pixel->blue  // pixel->blue  == 0
                    &&
                    pixel->alpha == 0xFF
                   )
                {
                    patch->setPaddingRight(image->getWidth() - i - 2);

                    break;
                }
            }

            for (i64 i = 1; i < image->getHeight() - 1; ++i)
            {
                RgbaPixel *pixel = &image->getRgbaBuffer()[(i + 1) * image->getWidth() - 1];

                if (
                    !pixel->red   // pixel->red   == 0
                    &&
                    !pixel->green // pixel->green == 0
                    &&
                    !pixel->blue  // pixel->blue  == 0
                    &&
                    pixel->alpha == 0xFF
                   )
                {
                    patch->setPaddingTop(i - 1);

                    break;
                }
            }

            for (i64 i = image->getHeight() - 2; i >= 1 ; --i)
            {
                RgbaPixel *pixel = &image->getRgbaBuffer()[(i + 1) * image->getWidth() - 1];

                if (
                    !pixel->red   // pixel->red   == 0
                    &&
                    !pixel->green // pixel->green == 0
                    &&
                    !pixel->blue  // pixel->blue  == 0
                    &&
                    pixel->alpha == 0xFF
                   )
                {
                    patch->setPaddingBottom(image->getHeight() - i - 2);

                    break;
                }
            }
        }
        else
        {
            for (i64 i = 1; i < image->getWidth() - 1; ++i)
            {
                RgbPixel *pixel = &image->getRgbBuffer()[lastPosY + i];

                if (
                    !pixel->red   // pixel->red   == 0
                    &&
                    !pixel->green // pixel->green == 0
                    &&
                    !pixel->blue  // pixel->blue  == 0
                   )
                {
                    patch->setPaddingLeft(i - 1);

                    break;
                }
            }

            for (i64 i = image->getWidth() - 2; i >= 1; --i)
            {
                RgbPixel *pixel = &image->getRgbBuffer()[lastPosY + i];

                if (
                    !pixel->red   // pixel->red   == 0
                    &&
                    !pixel->green // pixel->green == 0
                    &&
                    !pixel->blue  // pixel->blue  == 0
                   )
                {
                    patch->setPaddingRight(image->getWidth() - i - 2);

                    break;
                }
            }

            for (i64 i = 1; i < image->getHeight() - 1; ++i)
            {
                RgbPixel *pixel = &image->getRgbBuffer()[(i + 1) * image->getWidth() - 1];

                if (
                    !pixel->red   // pixel->red   == 0
                    &&
                    !pixel->green // pixel->green == 0
                    &&
                    !pixel->blue  // pixel->blue  == 0
                   )
                {
                    patch->setPaddingTop(i - 1);

                    break;
                }
            }

            for (i64 i = image->getHeight() - 2; i >= 1 ; --i)
            {
                RgbPixel *pixel = &image->getRgbBuffer()[(i + 1) * image->getWidth() - 1];

                if (
                    !pixel->red   // pixel->red   == 0
                    &&
                    !pixel->green // pixel->green == 0
                    &&
                    !pixel->blue  // pixel->blue  == 0
                   )
                {
                    patch->setPaddingBottom(image->getHeight() - i - 2);

                    break;
                }
            }
        }



        COMMON_ASSERT_EXECUTION(Graphics::insertImageRaw(image->getBuffer(), newImage->getBuffer(), image->getWidth(), image->getHeight(), newImage->getWidth(), newImage->getHeight(), image->getBytesPerPixel(), newImage->getBytesPerPixel(), true, -1, -1), NgosStatus::ASSERTION);



        if (decoder->rawImageBuffer == image->getBuffer())
        {
            decoder->rawImageBuffer = 0;
        }

        delete image;
        *decoder->image = newImage;
    }
    else
    {
        COMMON_LW(("Image size is too small for nine patch"));

        return NgosStatus::INVALID_DATA;
    }



    return NgosStatus::OK;
}

NgosStatus Png::unfilter(PngDecoder *decoder, u8 *in, u8 *out, u16 width, u16 height)
{
    COMMON_LT((" | decoder = 0x%p, in = 0x%p, out = 0x%p, width = %u, height = %u", decoder, in, out, width, height));

    COMMON_ASSERT(decoder,    "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(in,         "in is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(out,        "out is null",     NgosStatus::ASSERTION);
    COMMON_ASSERT(width > 0,  "width is zero",   NgosStatus::ASSERTION);
    COMMON_ASSERT(height > 0, "height is zero",  NgosStatus::ASSERTION);



    u8   bitsPerPixel = decoder->bitsPerPixel;
    u8   byteWidth    = DIV_UP(bitsPerPixel, 8);
    u32  bytesPerLine = DIV_UP(width * bitsPerPixel, 8);
    u8  *previousLine = 0;

    for (i64 i = 0; i < height; ++i)
    {
        u8 *inLine  = &in[i * (bytesPerLine + 1)]; // +1 because each line starts with filterType byte
        u8 *outLine = &out[i * bytesPerLine];

        PngFilterType filterType = (PngFilterType)*inLine;
        ++inLine;



        NgosStatus status = unfilterLine(inLine, outLine, previousLine, filterType, byteWidth, bytesPerLine);

        if (status != NgosStatus::OK)
        {
            return status;
        }



        previousLine = outLine;
    }



    return NgosStatus::OK;
}

NgosStatus Png::unfilterLine(u8 *inLine, u8 *outLine, u8 *previousLine, PngFilterType filterType, u8 byteWidth, u32 bytesPerLine)
{
    // COMMON_LT((" | inLine = 0x%p, outLine = 0x%p, previousLine = 0x%p, filterType = %u, byteWidth = %u, bytesPerLine = %u", inLine, outLine, previousLine, filterType, byteWidth, bytesPerLine)); // Commented to avoid too frequent logs

    COMMON_ASSERT(inLine,                                     "inLine is null",          NgosStatus::ASSERTION);
    COMMON_ASSERT(outLine,                                    "outLine is null",         NgosStatus::ASSERTION);
    COMMON_ASSERT(byteWidth > 0 && byteWidth <= 8,            "byteWidth is invalid",    NgosStatus::ASSERTION);
    COMMON_ASSERT(bytesPerLine > 0 && bytesPerLine <= 524280, "bytesPerLine is invalid", NgosStatus::ASSERTION);



    // COMMON_LVVV(("filterType = %u (%s)", filterType, pngFilterTypeToString(filterType))); // Commented to avoid too frequent logs



    switch (filterType)
    {
        case PngFilterType::NONE:
        {
            memcpy(outLine, inLine, bytesPerLine);
        }
        break;

        case PngFilterType::SUB:
        {
            memcpy(outLine, inLine, byteWidth);

            for (i64 i = byteWidth; i < bytesPerLine; ++i)
            {
                outLine[i] = inLine[i] + outLine[i - byteWidth];
            }
        }
        break;

        case PngFilterType::UP:
        {
            if (previousLine)
            {
                for (i64 i = 0; i < bytesPerLine; ++i)
                {
                    outLine[i] = inLine[i] + previousLine[i];
                }
            }
            else
            {
                memcpy(outLine, inLine, bytesPerLine);
            }
        }
        break;

        case PngFilterType::AVERAGE:
        {
            if (previousLine)
            {
                for (i64 i = 0; i < byteWidth; ++i)
                {
                    outLine[i] = inLine[i] + (previousLine[i] >> 1);
                }

                for (i64 i = byteWidth; i < bytesPerLine; ++i)
                {
                    outLine[i] = inLine[i] + ((outLine[i - byteWidth] + previousLine[i]) >> 1);
                }
            }
            else
            {
                memcpy(outLine, inLine, byteWidth);

                for (i64 i = byteWidth; i < bytesPerLine; ++i)
                {
                    outLine[i] = inLine[i] + (outLine[i - byteWidth] >> 1);
                }
            }
        }
        break;

        case PngFilterType::PAETH:
        {
            if (previousLine)
            {
                for (i64 i = 0; i < byteWidth; ++i)
                {
                    outLine[i] = (inLine[i] + previousLine[i]); // paethPredictor(0, previousLine[i], 0) is always previousLine[i]
                }

                for (i64 i = byteWidth; i < bytesPerLine; ++i)
                {
                    outLine[i] = (inLine[i] + paethPredictor(outLine[i - byteWidth], previousLine[i], previousLine[i - byteWidth]));
                }
            }
            else
            {
                memcpy(outLine, inLine, byteWidth);

                for (i64 i = byteWidth; i < bytesPerLine; ++i)
                {
                    // paethPredictor(outLine[i - byteWidth], 0, 0) is always outLine[i - byteWidth]
                    outLine[i] = (inLine[i] + outLine[i - byteWidth]);
                }
            }
        }
        break;

        default:
        {
            COMMON_LE(("Unknown filter type %u (%s)", filterType, pngFilterTypeToString(filterType)));

            return NgosStatus::INVALID_DATA;
        }
        break;
    }



    return NgosStatus::OK;
}

NgosStatus Png::removePaddingBits(u8 *in, u8 *out, i64 inLineBits, i64 outLineBits, u16 height)
{
    COMMON_LT((" | in = 0x%p, out = 0x%p, inLineBits = %d, outLineBits = %d, height = %u", in, out, inLineBits, outLineBits, height));

    COMMON_ASSERT(in,              "in is null",          NgosStatus::ASSERTION);
    COMMON_ASSERT(out,             "out is null",         NgosStatus::ASSERTION);
    COMMON_ASSERT(inLineBits > 0,  "inLineBits is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(outLineBits > 0, "outLineBits is zero", NgosStatus::ASSERTION);
    COMMON_ASSERT(height > 0,      "height is zero",      NgosStatus::ASSERTION);



    i64 diff          = inLineBits - outLineBits;
    i64 inBitPointer  = 0;
    i64 outBitPointer = 0;



    for (i64 i = 0; i < height; ++i)
    {
        for (i64 j = 0; j < outLineBits; ++j)
        {
            u8 bit = readBitFromReversedStream(&inBitPointer, in);

            COMMON_ASSERT_EXECUTION(setBitOfReversedStream(&outBitPointer, out, bit), NgosStatus::ASSERTION);
        }

        inBitPointer += diff;
    }



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

    u16 width  = (*decoder->image)->getWidth();
    u16 height = (*decoder->image)->getHeight();



    switch (decoder->imageHeader->interlaceMethod)
    {
        case PngInterlaceMethod::NONE:
        {
            COMMON_ASSERT_EXECUTION(getImageDataDecompressedSizeForBlock(decoder, width, height, size), NgosStatus::ASSERTION);
        }
        break;

        case PngInterlaceMethod::ADAM_7:
        {
            COMMON_ASSERT_EXECUTION(getImageDataDecompressedSizeForBlock(decoder, (width + 7) >> 3, (height + 7) >> 3, size), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(getImageDataDecompressedSizeForBlock(decoder, (width + 3) >> 2, (height + 3) >> 3, size), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(getImageDataDecompressedSizeForBlock(decoder, (width + 1) >> 1, (height + 1) >> 2, size), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(getImageDataDecompressedSizeForBlock(decoder, (width + 0),      (height + 0) >> 1, size), NgosStatus::ASSERTION);

            if (width > 1)
            {
                COMMON_ASSERT_EXECUTION(getImageDataDecompressedSizeForBlock(decoder, (width + 0) >> 1, (height + 1) >> 1, size), NgosStatus::ASSERTION);

                if (width > 2)
                {
                    COMMON_ASSERT_EXECUTION(getImageDataDecompressedSizeForBlock(decoder, (width + 1) >> 2, (height + 3) >> 2, size), NgosStatus::ASSERTION);

                    if (width > 4)
                    {
                        COMMON_ASSERT_EXECUTION(getImageDataDecompressedSizeForBlock(decoder, (width + 3) >> 3, (height + 7) >> 3, size), NgosStatus::ASSERTION);
                    }
                }
            }
        }
        break;

        default:
        {
            COMMON_LE(("Unknown interlace method %u (%s)", decoder->imageHeader->interlaceMethod, pngInterlaceMethodToString(decoder->imageHeader->interlaceMethod)));

            return NgosStatus::UNEXPECTED_BEHAVIOUR;
        }
        break;
    }



    return NgosStatus::OK;
}

NgosStatus Png::getImageDataDecompressedSizeForBlock(PngDecoder *decoder, u16 width, u16 height, u64 *size)
{
    COMMON_LT((" | decoder = 0x%p, width = %u, height = %u, size = 0x%p", decoder, width, height, size));

    COMMON_ASSERT(decoder,    "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(width > 0,  "width is zero",   NgosStatus::ASSERTION);
    COMMON_ASSERT(height > 0, "height is zero",  NgosStatus::ASSERTION);
    COMMON_ASSERT(size,       "size is null",    NgosStatus::ASSERTION);



    u8 bitsPerPixel = decoder->bitsPerPixel;

    *size += (((width >> 3) * bitsPerPixel) + DIV_UP((width & 7) * bitsPerPixel, 8) + 1) * height;



    return NgosStatus::OK;
}

NgosStatus Png::getRawImageSize(PngDecoder *decoder, u64 *size)
{
    COMMON_LT((" | decoder = 0x%p, size = 0x%p", decoder, size));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(size,    "size is null",    NgosStatus::ASSERTION);



    u16 width          = (*decoder->image)->getWidth();
    u16 height         = (*decoder->image)->getHeight();
    u32 numberOfPixels = width * height;
    u8  bitsPerPixel   = decoder->bitsPerPixel;



    *size = ((numberOfPixels >> 3) * bitsPerPixel) + DIV_UP((numberOfPixels & 7) * bitsPerPixel, 8);



    return NgosStatus::OK;
}

u8 Png::paethPredictor(u8 a, u8 b, u8 c)
{
    // COMMON_LT((" | a = %u, b = %u, c = %u", a, b, c)); // Commented to avoid too frequent logs



    i16 p = a + b - c;

    u16 pa = ABS(p - a);
    u16 pb = ABS(p - b);
    u16 pc = ABS(p - c);



    if (pc < pa && pc < pb)
    {
        return c;
    }

    if (pb < pa)
    {
        return b;
    }

    return a;
}

u8 Png::readBitFromReversedStream(i64 *bitPointer, u8 *bitStream)
{
    COMMON_LT((" | bitPointer = 0x%p, bitStream = 0x%p", bitPointer, bitStream));

    COMMON_ASSERT(bitPointer, "bitPointer is null", 0);
    COMMON_ASSERT(bitStream,  "bitStream is null",  0);



    u8 res = (u8)((bitStream[(*bitPointer) >> 3] >> (7 - ((*bitPointer) & 7))) & 1);

    ++(*bitPointer);



    return res;
}

NgosStatus Png::setBitOfReversedStream(i64 *bitPointer, u8 *bitStream, u8 bit)
{
    COMMON_LT((" | bitPointer = 0x%p, bitStream = 0x%p, bit = %u", bitPointer, bitStream, bit));

    COMMON_ASSERT(bitPointer,           "bitPointer is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(bitStream,            "bitStream is null",  NgosStatus::ASSERTION);
    COMMON_ASSERT(bit == 0 || bit == 1, "bit is invalid",     NgosStatus::ASSERTION);



    if (bit)
    {
        bitStream[(*bitPointer) >> 3] |= (1 << (7 - ((*bitPointer) & 7)));
    }
    else
    {
        bitStream[(*bitPointer) >> 3] &= (u8)(~(1 << (7 - ((*bitPointer) & 7))));
    }

    ++(*bitPointer);



    return NgosStatus::OK;
}
