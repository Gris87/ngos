#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_JPEGCOMPONENT_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_JPEGCOMPONENT_H



#include <com/ngos/shared/common/graphics/jpeg/jpegvlccode.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegcomponentid.h>
#include <com/ngos/shared/common/ngos/types.h>



struct JpegComponent
{
    JpegComponentId  id;
    u8               samplingFactorX;
    u8               samplingFactorY;
    u16              width;
    u16              height;
    u64              stride;
    i64              dcpred;
    u16             *quantizationTable;
    JpegVlcCode     *vlcDcTable;
    JpegVlcCode     *vlcAcTable;
    u8              *dataBuffer;
};



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_JPEGCOMPONENT_H
