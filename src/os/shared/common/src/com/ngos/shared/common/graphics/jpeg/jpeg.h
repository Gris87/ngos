#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEG_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEG_H



#include <common/src/com/ngos/shared/common/graphics/image.h>
#include <common/src/com/ngos/shared/common/graphics/jpeg/jpegdecoder.h>
#include <common/src/com/ngos/shared/common/graphics/jpeg/lib/jpegmarkerheader.h>
#include <common/src/com/ngos/shared/common/graphics/jpeg/lib/jpegstartofscanmarker.h>
#include <common/src/com/ngos/shared/common/ngos/status.h>



class Jpeg
{
public:
    static NgosStatus loadImage(u8 *data, u64 size, Image **image); // TEST: NO

private:
    static NgosStatus initDecoder(JpegDecoder *decoder, u8 *data, u64 size, Image **image); // TEST: NO
    static NgosStatus releaseDecoder(JpegDecoder *decoder); // TEST: NO
    static NgosStatus skip(JpegDecoder *decoder, u64 count); // TEST: NO
    static NgosStatus skipMarker(JpegDecoder *decoder, JpegMarkerHeader *marker); // TEST: NO
    static NgosStatus decodeMarker(JpegDecoder *decoder); // TEST: NO
    static NgosStatus decodeStartOfFrame(JpegDecoder *decoder, JpegMarkerHeader *marker); // TEST: NO
    static NgosStatus decodeDefineHuffmanTableMarker(JpegDecoder *decoder, JpegMarkerHeader *marker); // TEST: NO
    static NgosStatus decodeDefineQuantizationTableMarker(JpegDecoder *decoder, JpegMarkerHeader *marker); // TEST: NO
    static NgosStatus decodeDefineRestartIntervalMarker(JpegDecoder *decoder, JpegMarkerHeader *marker); // TEST: NO
    static NgosStatus decodeStartOfScanMarker(JpegDecoder *decoder, JpegMarkerHeader *marker); // TEST: NO
    static NgosStatus decodeImageData(JpegDecoder *decoder); // TEST: NO
    static NgosStatus decodeMcuBlock(JpegDecoder *decoder, JpegComponent *component, u64 mcuBlockX, u64 mcuBlockY); // TEST: NO
    static NgosStatus decodeMcuBlockSample(JpegDecoder *decoder, JpegComponent *component, u8 *sampleDataBuffer); // TEST: NO
    static NgosStatus getVlc(JpegDecoder *decoder, JpegVlcCode *vlc, u8 *code, i64 *value); // TEST: NO
    static NgosStatus handleRowIDCT(i64 *block); // TEST: NO
    static NgosStatus handleColIDCT(i64 *block, u8 *sampleDataBuffer, u64 stride); // TEST: NO
    static NgosStatus convertToRgb(JpegDecoder *decoder); // TEST: NO
    static NgosStatus upsampleX(JpegComponent *component); // TEST: NO
    static NgosStatus upsampleY(JpegComponent *component); // TEST: NO
    static NgosStatus bufferBits(JpegDecoder *decoder, u8 count); // TEST: NO
    static NgosStatus getBits(JpegDecoder *decoder, u8 count, u64 *res); // TEST: NO
    static NgosStatus readBits(JpegDecoder *decoder, u8 count, u64 *res); // TEST: NO
    static NgosStatus skipBits(JpegDecoder *decoder, u8 count); // TEST: NO
    static NgosStatus alignBits(JpegDecoder *decoder); // TEST: NO
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEG_H
