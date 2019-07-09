#include "png.h"

#include <common/src/bits64/graphics/png/lib/pngheader.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/malloc.h>
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
        size <= sizeof(PngHeader)
        ||
        pngHeader->signature != PNG_HEADER_SIGNATURE
       )
    {
        COMMON_LE(("Data is not a PNG image"));

        return NgosStatus::INVALID_DATA;
    }

    size -= sizeof(pngHeader->signature);



    PngDecoder decoder;

    COMMON_ASSERT_EXECUTION(initDecoder(&decoder, image), NgosStatus::ASSERTION);



    NgosStatus  status = NgosStatus::OK;
    PngChunk   *chunk  = &pngHeader->chunk;

    while (status == NgosStatus::OK && size >= sizeof(PngChunk) + 4) // 4 == size of CRC
    {
        u32          chunkLength      = ntohl(chunk->length);
        PngChunkType chunkType        = chunk->type;
        u64          totalChunkLength = sizeof(PngChunk) + chunkLength + 4; // 4 == size of CRC

        COMMON_LVVV(("chunkLength      = %u", chunkLength));
        COMMON_LVVV(("chunkType        = 0x%08X (%s)", chunkType, pngChunkTypeToString(chunkType)));
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



    decoder->image = image;



    return NgosStatus::OK;
}

NgosStatus Png::releaseDecoder(PngDecoder *decoder)
{
    COMMON_LT((" | decoder = 0x%p", decoder));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus Png::decodeChunk(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength)
{
    COMMON_LT((" | decoder = 0x%p, chunk = 0x%p, chunkLength = %u", decoder, chunk, chunkLength));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(chunk,   "chunk is null",   NgosStatus::ASSERTION);



    switch (chunk->type)
    {
        case PngChunkType::IHDR: return decodeImageHeader(decoder, chunk, chunkLength);

        case PngChunkType::SRGB:
        case PngChunkType::GAMA:
        case PngChunkType::PHYS:
        case PngChunkType::TEXT:
        case PngChunkType::IDAT:
        case PngChunkType::IEND:
        {
            COMMON_LVV(("Ignore PNG chunk 0x%08X (%s)", chunk->type, pngChunkTypeToString(chunk->type)));
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

NgosStatus Png::decodeImageHeader(PngDecoder *decoder, PngChunk *chunk, u32 /*chunkLength*/)
{
    COMMON_LT((" | decoder = 0x%p, chunk = 0x%p, chunkLength = %u", decoder, chunk, chunkLength));

    COMMON_ASSERT(decoder, "decoder is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(chunk,   "chunk is null",   NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
