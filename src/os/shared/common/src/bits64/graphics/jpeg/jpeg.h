#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEG_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEG_H



#include <common/src/bits64/graphics/image.h>
#include <common/src/bits64/graphics/jpeg/jpegdecoder.h>
#include <common/src/bits64/graphics/jpeg/jpegmarkerheader.h>
#include <common/src/bits64/graphics/jpeg/jpegstartofscanmarker.h>
#include <ngos/status.h>



class Jpeg
{
public:
    static NgosStatus loadImage(u8 *data, u64 size, Image **image); // TEST: NO

private:
    static NgosStatus initDecoder(JpegDecoder *decoder, u8 *data, u64 size, Image **image); // TEST: NO
    static NgosStatus releaseDecoder(JpegDecoder *decoder); // TEST: NO
    static NgosStatus skip(JpegDecoder *decoder, u64 count); // TEST: NO
    static NgosStatus skipMarker(JpegDecoder *decoder, JpegMarkerHeader *marker); // TEST: NO
    static NgosStatus decodeStartOfFrame(JpegDecoder *decoder, JpegMarkerHeader *marker); // TEST: NO
    static NgosStatus decodeDefineHuffmanTableMarker(JpegDecoder *decoder, JpegMarkerHeader *marker); // TEST: NO
    static NgosStatus decodeDefineQuantizationTableMarker(JpegDecoder *decoder, JpegMarkerHeader *marker); // TEST: NO
    static NgosStatus decodeDefineRestartIntervalMarker(JpegDecoder *decoder, JpegMarkerHeader *marker); // TEST: NO
    static NgosStatus decodeStartOfScanMarker(JpegDecoder *decoder, JpegMarkerHeader *marker); // TEST: NO
    static NgosStatus decodeImageData(JpegDecoder *decoder); // TEST: NO
    static NgosStatus decodeMcuBlock(JpegDecoder *decoder); // TEST: NO
    static NgosStatus bufferBits(JpegDecoder *decoder, u8 count); // TEST: NO
    static NgosStatus readBits(JpegDecoder *decoder, u8 count, u64 *res); // TEST: NO
    static NgosStatus skipBits(JpegDecoder *decoder, u8 count); // TEST: NO
    static NgosStatus alignBits(JpegDecoder *decoder); // TEST: NO
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEG_H
