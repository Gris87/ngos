#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTBLTPIXEL_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTBLTPIXEL_H



#include <com/ngos/shared/common/ngos/types.h>



struct UefiGraphicsOutputBltPixel
{
    bad_uint8 blue;
    bad_uint8 green;
    bad_uint8 red;
    bad_uint8 __reserved;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTBLTPIXEL_H
