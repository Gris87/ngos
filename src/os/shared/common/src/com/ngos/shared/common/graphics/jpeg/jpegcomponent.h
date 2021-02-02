#ifndef COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_JPEGCOMPONENT_H
#define COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_JPEGCOMPONENT_H



#include <com/ngos/shared/common/graphics/jpeg/jpegvlccode.h>
#include <com/ngos/shared/common/graphics/jpeg/lib/jpegcomponentid.h>
#include <com/ngos/shared/common/ngos/types.h>



struct JpegComponent
{
    JpegComponentId  id;
    bad_uint8               samplingFactorX;
    bad_uint8               samplingFactorY;
    bad_uint16              width;
    bad_uint16              height;
    bad_uint64              stride;
    bad_int64              dcpred;
    bad_uint16             *quantizationTable;
    JpegVlcCode     *vlcDcTable;
    JpegVlcCode     *vlcAcTable;
    bad_uint8              *dataBuffer;
};



#endif // COM_NGOS_SHARED_COMMON_GRAPHICS_JPEG_JPEGCOMPONENT_H
