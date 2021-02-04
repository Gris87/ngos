#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTBLTPIXEL_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTBLTPIXEL_H



#include <com/ngos/shared/common/ngos/types.h>



struct UefiGraphicsOutputBltPixel
{
    u8 blue;
    u8 green;
    u8 red;
    u8 __reserved;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTBLTPIXEL_H
