#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGCOMPONENTID_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGCOMPONENTID_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <ngos/types.h>



enum class JpegComponentId: u8
{
    NONE = 0,
    Y    = 1,
    CB   = 2,
    CR   = 3,
    I    = 4,
    Q    = 5
};



inline const char8* jpegComponentIdToString(JpegComponentId id) // TEST: NO
{
    // COMMON_LT((" | id = %u", id)); // Commented to avoid bad looking logs



    switch (id)
    {
        case JpegComponentId::NONE: return "NONE";
        case JpegComponentId::Y:    return "Y"; // Ignore CppSingleCharVerifier
        case JpegComponentId::CB:   return "CB";
        case JpegComponentId::CR:   return "CR";
        case JpegComponentId::I:    return "I"; // Ignore CppSingleCharVerifier
        case JpegComponentId::Q:    return "Q"; // Ignore CppSingleCharVerifier

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGCOMPONENTID_H
