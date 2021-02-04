#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTMODEINFORMATION_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTMODEINFORMATION_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/uefigraphicspixelformat.h>
#include <com/ngos/shared/common/uefi/uefipixelbitmask.h>



struct UefiGraphicsOutputModeInformation
{
    u32                     version;
    u32                     horizontalResolution;
    u32                     verticalResolution;
    UefiGraphicsPixelFormat pixelFormat;
    UefiPixelBitmask        pixelInformation;
    u32                     pixelsPerScanLine;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTMODEINFORMATION_H
