#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEG_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEG_H



#include <common/src/bits64/graphics/image.h>
#include <common/src/bits64/graphics/jpeg/jpegdecoder.h>
#include <ngos/status.h>



class Jpeg
{
public:
    static NgosStatus loadImage(u8 *data, u64 size, Image **image); // TEST: NO

private:
    static NgosStatus skip(JpegDecoder *decoder, u64 count); // TEST: NO
    static NgosStatus skipMarker(JpegDecoder *decoder); // TEST: NO
    static NgosStatus decodeStartOfFrameBaselineDCT(JpegDecoder *decoder); // TEST: NO
    static NgosStatus decodeDefineHuffmanTableMarker(JpegDecoder *decoder); // TEST: NO
    static NgosStatus decodeDefineQuantizationTableMarker(JpegDecoder *decoder); // TEST: NO
    static NgosStatus decodeDefineRestartIntervalMarker(JpegDecoder *decoder); // TEST: NO
    static NgosStatus decodeStartOfScanMarker(JpegDecoder *decoder); // TEST: NO
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEG_H
