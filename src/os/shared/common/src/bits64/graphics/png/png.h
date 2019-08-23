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

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static NgosStatus initDecoder(PngDecoder *decoder, Image **image); // TEST: NO
    static NgosStatus releaseDecoder(PngDecoder *decoder); // TEST: NO
    static NgosStatus decodeChunk(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength); // TEST: NO
    static NgosStatus decodeImageHeader(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength); // TEST: NO
    static NgosStatus decodePrimaryChromaticities(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength); // TEST: NO
    static NgosStatus decodeImageGamma(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength); // TEST: NO
    static NgosStatus decodeEmbeddedIccProfile(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength); // TEST: NO
    static NgosStatus decodeSignificantBits(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength); // TEST: NO
    static NgosStatus decodeStandardRgbColorSpace(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength); // TEST: NO
    static NgosStatus decodePhysicalPixelDimensions(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength); // TEST: NO
    static NgosStatus decodeImageLastModificationTime(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength); // TEST: NO
    static NgosStatus decodeImageData(PngDecoder *decoder, PngChunk *chunk, u32 chunkLength); // TEST: NO
    static NgosStatus decodeImage(PngDecoder *decoder); // TEST: NO
    static NgosStatus decompressImageData(PngDecoder *decoder); // TEST: NO
    static NgosStatus convertImageDataToImage(PngDecoder *decoder); // TEST: NO
    static NgosStatus processImageInterlace(PngDecoder *decoder); // TEST: NO
    static NgosStatus processImageWithoutInterlace(PngDecoder *decoder); // TEST: NO
    static NgosStatus processImageWithAdam7Interlace(PngDecoder *decoder); // TEST: NO
    static NgosStatus imagePostprocess(PngDecoder *decoder); // TEST: NO
    static NgosStatus unfilter(PngDecoder *decoder, u8 *in, u8 *out, u16 width, u16 height); // TEST: NO
    static NgosStatus unfilterLine(u8 *inLine, u8 *outLine, u8 *previousLine, PngFilterType filterType, u8 byteWidth, u32 bytesPerLine);
    static NgosStatus removePaddingBits(u8 *in, u8 *out, i64 inLineBits, i64 outLineBits, u16 height);
    static NgosStatus checkColorTypeAndBitDepth(PngColorType colorType, u8 bitDepth);
    static NgosStatus addImageDataToBuffer(PngDecoder *decoder, u8 *data, u64 count); // TEST: NO
    static NgosStatus getImageDataDecompressedSize(PngDecoder *decoder, u64 *size); // TEST: NO
    static NgosStatus getImageDataDecompressedSizeForBlock(PngDecoder *decoder, u16 width, u16 height, u64 *size); // TEST: NO
    static NgosStatus getRawImageSize(PngDecoder *decoder, u64 *size); // TEST: NO
    static u8 paethPredictor(u8 a, u8 b, u8 c);
    static u8 readBitFromReversedStream(i64 *bitPointer, u8 *bitStream);
    static NgosStatus setBitOfReversedStream(i64 *bitPointer, u8 *bitStream, u8 bit);
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_PNG_PNG_H
