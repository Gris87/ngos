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



#endif // UEFI_UEFIGRAPHICSPIXELFORMAT_H
