#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_PNG_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_PNG_H



#include <common/src/bits64/graphics/image.h>
#include <common/src/bits64/graphics/png/lib/pngchunk.h>
#include <common/src/bits64/graphics/png/pngdecoder.h>
#include <ngos/status.h>



class Png
{
public:
    static NgosStatus loadImage(u8 *data, u64 size, Image **image); // TEST: NO

private:
    static NgosStatus initDecoder(PngDecoder *decoder, Image **image); // TEST: NO
    static NgosStatus releaseDecoder(PngDecoder *decoder); // TEST: NO
    static NgosStatus decodeChunk(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength); // TEST: NO
    static NgosStatus decodeImageHeader(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength); // TEST: NO
    static NgosStatus decodeStandardRgbColorSpace(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength); // TEST: NO
    static NgosStatus decodeImageGamma(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength); // TEST: NO
    static NgosStatus decodePhysicalPixelDimensions(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength); // TEST: NO
    static NgosStatus decodeImageData(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength); // TEST: NO
    static NgosStatus checkColorTypeAndBitDepth(PngColorType colorType, u8 bitDepth); // TEST: NO
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_PNG_H
