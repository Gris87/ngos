#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_JPEG_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_JPEG_H



#include <com/ngos/shared/common/graphics/image.h>
#include <com/ngos/shared/common/graphics/jpeg/jpegdecoder.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegmarkerheader.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegstartofscanmarker.h>
#include <com/ngos/shared/common/ngos/status.h>



class Jpeg
{
public:
    static NgosStatus loadImage(bad_uint8 *data, bad_uint64 size, Image **image); // TEST: NO

private:
    static NgosStatus initDecoder(JpegDecoder *decoder, bad_uint8 *data, bad_uint64 size, Image **image); // TEST: NO
    static NgosStatus releaseDecoder(JpegDecoder *decoder); // TEST: NO
    static NgosStatus skip(JpegDecoder *decoder, bad_uint64 count); // TEST: NO
    static NgosStatus skipMarker(JpegDecoder *decoder, JpegMarkerHeader *marker); // TEST: NO
    static NgosStatus decodeMarker(JpegDecoder *decoder); // TEST: NO
    static NgosStatus decodeStartOfFrame(JpegDecoder *decoder, JpegMarkerHeader *marker); // TEST: NO
    static NgosStatus decodeDefineHuffmanTableMarker(JpegDecoder *decoder, JpegMarkerHeader *marker); // TEST: NO
    static NgosStatus decodeDefineQuantizationTableMarker(JpegDecoder *decoder, JpegMarkerHeader *marker); // TEST: NO
    static NgosStatus decodeDefineRestartIntervalMarker(JpegDecoder *decoder, JpegMarkerHeader *marker); // TEST: NO
    static NgosStatus decodeStartOfScanMarker(JpegDecoder *decoder, JpegMarkerHeader *marker); // TEST: NO
    static NgosStatus decodeImageData(JpegDecoder *decoder); // TEST: NO
    static NgosStatus decodeMcuBlock(JpegDecoder *decoder, JpegComponent *component, bad_uint64 mcuBlockX, bad_uint64 mcuBlockY); // TEST: NO
    static NgosStatus decodeMcuBlockSample(JpegDecoder *decoder, JpegComponent *component, bad_uint8 *sampleDataBuffer); // TEST: NO
    static NgosStatus getVlc(JpegDecoder *decoder, JpegVlcCode *vlc, bad_uint8 *code, bad_int64 *value); // TEST: NO
    static NgosStatus handleRowIDCT(bad_int64 *block); // TEST: NO
    static NgosStatus handleColIDCT(bad_int64 *block, bad_uint8 *sampleDataBuffer, bad_uint64 stride); // TEST: NO
    static NgosStatus convertToRgb(JpegDecoder *decoder); // TEST: NO
    static NgosStatus upsampleX(JpegComponent *component); // TEST: NO
    static NgosStatus upsampleY(JpegComponent *component); // TEST: NO
    static NgosStatus bufferBits(JpegDecoder *decoder, bad_uint8 count); // TEST: NO
    static NgosStatus getBits(JpegDecoder *decoder, bad_uint8 count, bad_uint64 *res); // TEST: NO
    static NgosStatus readBits(JpegDecoder *decoder, bad_uint8 count, bad_uint64 *res); // TEST: NO
    static NgosStatus skipBits(JpegDecoder *decoder, bad_uint8 count); // TEST: NO
    static NgosStatus alignBits(JpegDecoder *decoder); // TEST: NO
};



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_JPEG_H
