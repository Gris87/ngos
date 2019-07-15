#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEG_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEG_H



#include <common/src/bits64/graphics/image.h>
#include <common/src/bits64/graphics/jpeg/jpegdecoder.h>
#include <common/src/bits64/graphics/jpeg/lib/jpegmarkerheader.h>
#include <common/src/bits64/graphics/jpeg/lib/jpegstartofscanmarker.h>
#include <ngos/status.h>



class Jpeg
{
public:
    static NgosStatus loadImage(u8 *data, u64 size, Image **image); 

private:
    static NgosStatus initDecoder(JpegDecoder *decoder, u8 *data, u64 size, Image **image); 
    static NgosStatus releaseDecoder(JpegDecoder *decoder); 
    static NgosStatus skip(JpegDecoder *decoder, u64 count); 
    static NgosStatus skipMarker(JpegDecoder *decoder, JpegMarkerHeader *marker); 
    static NgosStatus decodeMarker(JpegDecoder *decoder); 
    static NgosStatus decodeStartOfFrame(JpegDecoder *decoder, JpegMarkerHeader *marker); 
    static NgosStatus decodeDefineHuffmanTableMarker(JpegDecoder *decoder, JpegMarkerHeader *marker); 
    static NgosStatus decodeDefineQuantizationTableMarker(JpegDecoder *decoder, JpegMarkerHeader *marker); 
    static NgosStatus decodeDefineRestartIntervalMarker(JpegDecoder *decoder, JpegMarkerHeader *marker); 
    static NgosStatus decodeStartOfScanMarker(JpegDecoder *decoder, JpegMarkerHeader *marker); 
    static NgosStatus decodeImageData(JpegDecoder *decoder); 
    static NgosStatus decodeMcuBlock(JpegDecoder *decoder, JpegComponent *component, u64 mcuBlockX, u64 mcuBlockY); 
    static NgosStatus decodeMcuBlockSample(JpegDecoder *decoder, JpegComponent *component, u8 *sampleDataBuffer); 
    static NgosStatus getVlc(JpegDecoder *decoder, JpegVlcCode *vlc, u8 *code, i64 *value); 
    static NgosStatus handleRowIDCT(i64 *block); 
    static NgosStatus handleColIDCT(i64 *block, u8 *sampleDataBuffer, u64 stride); 
    static NgosStatus convertToRgb(JpegDecoder *decoder); 
    static NgosStatus upsampleX(JpegComponent *component); 
    static NgosStatus upsampleY(JpegComponent *component); 
    static NgosStatus bufferBits(JpegDecoder *decoder, u8 count); 
    static NgosStatus getBits(JpegDecoder *decoder, u8 count, u64 *res); 
    static NgosStatus readBits(JpegDecoder *decoder, u8 count, u64 *res); 
    static NgosStatus skipBits(JpegDecoder *decoder, u8 count); 
    static NgosStatus alignBits(JpegDecoder *decoder); 
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEG_H
