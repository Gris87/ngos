#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGSTARTOFFRAMECOMPONENTID_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGSTARTOFFRAMECOMPONENTID_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/types.h>



enum class JpegStartOfFrameComponentId: u8
{
    Y  = 1,
    CB = 2,
    CR = 3,
    I  = 4,
    Q  = 5
};



inline const char* jpegStartOfFrameComponentIdToString(JpegStartOfFrameComponentId type) // TEST: NO
{
    COMMON_LT((" | type = %u", type));



    switch (type)
    {
        case JpegStartOfFrameComponentId::Y:  return "Y";
        case JpegStartOfFrameComponentId::CR: return "CR";
        case JpegStartOfFrameComponentId::CB: return "CB";
        case JpegStartOfFrameComponentId::I:  return "I";
        case JpegStartOfFrameComponentId::Q:  return "Q";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGSTARTOFFRAMECOMPONENTID_H
