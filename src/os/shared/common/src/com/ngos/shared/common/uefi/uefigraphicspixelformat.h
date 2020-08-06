#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSPIXELFORMAT_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSPIXELFORMAT_H



#include <com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <com/ngos/shared/common/printf/printf.h>
#endif



enum class UefiGraphicsPixelFormat: u32
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



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* enumToFullString(UefiGraphicsPixelFormat format) // TEST: NO
{
    // COMMON_LT((" | format = %u", format)); // Commented to avoid bad looking logs



    static char8 res[33];

    sprintf(res, "0x%08X (%s)", (u32)format, enumToString(format));

    return res;
}



#endif



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSPIXELFORMAT_H
