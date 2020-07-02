#ifndef OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGCOMPONENTID_H
#define OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGCOMPONENTID_H



#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



enum class JpegComponentId: u8
{
    NONE = 0,
    Y    = 1,
    CB   = 2,
    CR   = 3,
    I    = 4,
    Q    = 5
};



inline const char8* enumToString(JpegComponentId id) // TEST: NO
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



inline const char8* enumToFullString(JpegComponentId id) // TEST: NO
{
    // COMMON_LT((" | id = %u", id)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", id, enumToString(id));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_GRAPHICS_JPEG_LIB_JPEGCOMPONENTID_H
