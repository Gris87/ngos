#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_PNG_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_PNG_H



#include <common/src/bits64/graphics/image.h>
#include <common/src/bits64/graphics/png/lib/pngchunk.h>
#include <common/src/bits64/graphics/png/lib/pngfiltertype.h>
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
    static NgosStatus decodeImage(PngDecoder *decoder); // TEST: NO
    static NgosStatus decompressImageData(PngDecoder *decoder); // TEST: NO
    static NgosStatus convertImageDataToImage(PngDecoder *decoder); // TEST: NO
    static NgosStatus processImageInterlace(PngDecoder *decoder); // TEST: NO
    static NgosStatus processImageWithoutInterlace(PngDecoder *decoder); // TEST: NO
    static NgosStatus processImageWithAdam7Interlace(PngDecoder *decoder); // TEST: NO
    static NgosStatus unfilter(PngDecoder *decoder, u8 *in, u8 *out, u16 width, u16 height); // TEST: NO
    static NgosStatus unfilterLine(PngDecoder *decoder, u8 *inLine, u8 *outLine, u8 *previousLine, PngFilterType filterType, u8 byteWidth, u32 bytesPerLine); // TEST: NO
    static u8 paethPredictor(u8 a, u8 b, u8 c); // TEST: NO
    static NgosStatus removePaddingBits(PngDecoder *decoder, u8 *in, u8 *out, i64 inLineBits, i64 outLineBits, u16 height); // TEST: NO
    static NgosStatus checkColorTypeAndBitDepth(PngColorType colorType, u8 bitDepth); // TEST: NO
    static NgosStatus addImageDataToBuffer(PngDecoder *decoder, u8 *data, u64 count); // TEST: NO
    static NgosStatus getImageDataDecompressedSize(PngDecoder *decoder, u64 *size); // TEST: NO
    static NgosStatus getImageDataDecompressedSizeForBlock(PngDecoder *decoder, u16 width, u16 height, u64 *size); // TEST: NO
    static NgosStatus getRawImageSize(PngDecoder *decoder, u64 *size); // TEST: NO
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_PNG_H
