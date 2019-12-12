#ifndef UEFI_UEFIGRAPHICSPIXELFORMAT_H
#define UEFI_UEFIGRAPHICSPIXELFORMAT_H



#include <ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) || defined(BUILD_TARGET_INSTALLER) // Defined in Makefile
#include <common/src/bits64/printf/printf.h>
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



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) || defined(BUILD_TARGET_INSTALLER) // Defined in Makefile



inline const char8* enumToFullString(UefiGraphicsPixelFormat format) // TEST: NO
{
    static char8 res[33];

    sprintf(res, "0x%08X (%s)", format, enumToString(format));

    return res;
}



#endif



#endif // UEFI_UEFIGRAPHICSPIXELFORMAT_H
