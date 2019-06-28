#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGCOMPONENTID_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGCOMPONENTID_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/types.h>



enum class JpegComponentId: u8
{
    Y  = 1,
    CB = 2,
    CR = 3,
    I  = 4,
    Q  = 5
};



inline const char* jpegComponentIdToString(JpegComponentId type) // TEST: NO
{
    COMMON_LT((" | type = %u", type));



    switch (type)
    {
        case JpegComponentId::Y:  return "Y"; // Ignore CppSingleCharVerifier
        case JpegComponentId::CR: return "CR";
        case JpegComponentId::CB: return "CB";
        case JpegComponentId::I:  return "I"; // Ignore CppSingleCharVerifier
        case JpegComponentId::Q:  return "Q"; // Ignore CppSingleCharVerifier

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_JPEGCOMPONENTID_H
