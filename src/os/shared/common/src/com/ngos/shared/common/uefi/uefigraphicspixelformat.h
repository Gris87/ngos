#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSPIXELFORMAT_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSPIXELFORMAT_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class UefiGraphicsPixelFormat: bad_uint32
{
    RGB_8_BIT_PER_COLOR,
    BGR_8_BIT_PER_COLOR,
    BIT_MASK,
    BLT_ONLY,
    MAXIMUM
};



inline const char8* enumToString(UefiGraphicsPixelFormat format) // TEST: NO
{
    // COMMON_LT((" | format = %u", format)); // Commented to avoid bad looking logs



    switch (format)
    {
        case UefiGraphicsPixelFormat::RGB_8_BIT_PER_COLOR: return "RGB_8_BIT_PER_COLOR";
        case UefiGraphicsPixelFormat::BGR_8_BIT_PER_COLOR: return "BGR_8_BIT_PER_COLOR";
        case UefiGraphicsPixelFormat::BIT_MASK:            return "BIT_MASK";
        case UefiGraphicsPixelFormat::BLT_ONLY:            return "BLT_ONLY";
        case UefiGraphicsPixelFormat::MAXIMUM:             return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(UefiGraphicsPixelFormat format) // TEST: NO
{
    // COMMON_LT((" | format = %u", format)); // Commented to avoid bad looking logs



    static char8 res[33];

    sprintf(res, "0x%08X (%s)", (bad_uint32)format, enumToString(format));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSPIXELFORMAT_H
