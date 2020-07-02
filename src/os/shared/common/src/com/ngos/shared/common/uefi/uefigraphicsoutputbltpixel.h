#ifndef UEFI_UEFIGRAPHICSOUTPUTBLTPIXEL_H
#define UEFI_UEFIGRAPHICSOUTPUTBLTPIXEL_H



#include <ngos/types.h>



struct UefiGraphicsOutputBltPixel
{
    u8 blue;
    u8 green;
    u8 red;
    u8 __reserved;
};



#endif // UEFI_UEFIGRAPHICSOUTPUTBLTPIXEL_H
