#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTBLTPIXEL_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTBLTPIXEL_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



struct UefiGraphicsOutputBltPixel
{
    u8 blue;
    u8 green;
    u8 red;
    u8 __reserved;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTBLTPIXEL_H
