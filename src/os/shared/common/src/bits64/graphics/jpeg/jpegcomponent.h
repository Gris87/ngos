#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGCOMPONENT_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGCOMPONENT_H



#include <common/src/bits64/graphics/jpeg/jpegcomponentid.h>
#include <common/src/bits64/graphics/jpeg/jpegvlccode.h>
#include <ngos/types.h>



struct JpegComponent
{
    JpegComponentId  id;
    u8               samplingFactorX;
    u8               samplingFactorY;
    u64              width;
    u64              height;
    u64              stride;
    u64              dcpred;
    u16             *quantizationTable;
    JpegVlcCode     *vlcDcTable;
    JpegVlcCode     *vlcAcTable;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGCOMPONENT_H
