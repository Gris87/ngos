#ifndef UEFI_UEFIGRAPHICSPIXELFORMAT_H
#define UEFI_UEFIGRAPHICSPIXELFORMAT_H



#include <ngos/types.h>



enum class UefiGraphicsPixelFormat: u32
{
    RGB_8_BIT_PER_COLOR,
    BGR_8_BIT_PER_COLOR,
    BIT_MASK,
    BLT_ONLY,
    MAXIMUM
};



inline const char* uefiGraphicsPixelFormatToString(UefiGraphicsPixelFormat format) // TEST: NO
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



#endif // UEFI_UEFIGRAPHICSPIXELFORMAT_H
