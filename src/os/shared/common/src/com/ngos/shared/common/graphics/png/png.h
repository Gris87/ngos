#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_PNG_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_PNG_H



#include <com/ngos/shared/common/graphics/image.h>
#include <com/ngos/shared/common/graphics/png/lib/pngchunk.h>
#include <com/ngos/shared/common/graphics/png/lib/pngfiltertype.h>
#include <com/ngos/shared/common/graphics/png/pngdecoder.h>
#include <com/ngos/shared/common/ngos/status.h>



class Png
{
public:
    static NgosStatus loadImage(bad_uint8 *data, bad_uint64 size, bool withNinePatch, Image **image); // TEST: NO

#if NGOS_BUILD_TEST_MODE == OPTION_YES
public:
#else
private:
#endif
    static NgosStatus initDecoder(PngDecoder *decoder, Image **image); // TEST: NO
    static NgosStatus releaseDecoder(PngDecoder *decoder); // TEST: NO
    static NgosStatus decodeChunk(PngDecoder *decoder, PngChunk *chunk, bad_uint32 chunkLength); // TEST: NO
    static NgosStatus decodeImageHeader(PngDecoder *decoder, PngChunk *chunk, bad_uint32 chunkLength); // TEST: NO
    static NgosStatus decodePrimaryChromaticities(PngDecoder *decoder, PngChunk *chunk, bad_uint32 chunkLength); // TEST: NO
    static NgosStatus decodeImageGamma(PngDecoder *decoder, PngChunk *chunk, bad_uint32 chunkLength); // TEST: NO
    static NgosStatus decodeEmbeddedIccProfile(PngDecoder *decoder, PngChunk *chunk, bad_uint32 chunkLength); // TEST: NO
    static NgosStatus decodeSignificantBits(PngDecoder *decoder, PngChunk *chunk, bad_uint32 chunkLength); // TEST: NO
    static NgosStatus decodeStandardRgbColorSpace(PngDecoder *decoder, PngChunk *chunk, bad_uint32 chunkLength); // TEST: NO
    static NgosStatus decodePhysicalPixelDimensions(PngDecoder *decoder, PngChunk *chunk, bad_uint32 chunkLength); // TEST: NO
    static NgosStatus decodeImageLastModificationTime(PngDecoder *decoder, PngChunk *chunk, bad_uint32 chunkLength); // TEST: NO
    static NgosStatus decodeImageData(PngDecoder *decoder, PngChunk *chunk, bad_uint32 chunkLength); // TEST: NO
    static NgosStatus decodeImage(PngDecoder *decoder); // TEST: NO
    static NgosStatus decompressImageData(PngDecoder *decoder); // TEST: NO
    static NgosStatus convertImageDataToImage(PngDecoder *decoder); // TEST: NO
    static NgosStatus processImageInterlace(PngDecoder *decoder); // TEST: NO
    static NgosStatus processImageWithoutInterlace(PngDecoder *decoder); // TEST: NO
    static NgosStatus processImageWithAdam7Interlace(PngDecoder *decoder); // TEST: NO
    static NgosStatus imagePostprocess(PngDecoder *decoder, bool withNinePatch); // TEST: NO
    static NgosStatus applyNinePatch(PngDecoder *decoder); // TEST: NO
    static NgosStatus unfilter(PngDecoder *decoder, bad_uint8 *in, bad_uint8 *out, bad_uint16 width, bad_uint16 height); // TEST: NO
    static NgosStatus unfilterLine(bad_uint8 *inLine, bad_uint8 *outLine, bad_uint8 *previousLine, PngFilterType filterType, bad_uint8 byteWidth, bad_uint32 bytesPerLine);
    static NgosStatus removePaddingBits(bad_uint8 *in, bad_uint8 *out, bad_int64 inLineBits, bad_int64 outLineBits, bad_uint16 height);
    static NgosStatus checkColorTypeAndBitDepth(PngColorType colorType, bad_uint8 bitDepth);
    static NgosStatus addImageDataToBuffer(PngDecoder *decoder, bad_uint8 *data, bad_uint64 count); // TEST: NO
    static NgosStatus getImageDataDecompressedSize(PngDecoder *decoder, bad_uint64 *size); // TEST: NO
    static NgosStatus getImageDataDecompressedSizeForBlock(PngDecoder *decoder, bad_uint16 width, bad_uint16 height, bad_uint64 *size); // TEST: NO
    static NgosStatus getRawImageSize(PngDecoder *decoder, bad_uint64 *size); // TEST: NO
    static bad_uint8 paethPredictor(bad_uint8 a, bad_uint8 b, bad_uint8 c);
    static bad_uint8 readBitFromReversedStream(bad_int64 *bitPointer, bad_uint8 *bitStream);
    static NgosStatus setBitOfReversedStream(bad_int64 *bitPointer, bad_uint8 *bitStream, bad_uint8 bit);
};



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_PNG_PNG_H
