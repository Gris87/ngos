#ifndef UEFI_UEFIGRAPHICSOUTPUTMODEINFORMATION_H
#define UEFI_UEFIGRAPHICSOUTPUTMODEINFORMATION_H



#include <common/src/com/ngos/shared/common/ngos/types.h>
#include <common/src/com/ngos/shared/common/uefi/uefigraphicspixelformat.h>
#include <common/src/com/ngos/shared/common/uefi/uefipixelbitmask.h>



struct UefiGraphicsOutputModeInformation
{
    u32                     version;
    u32                     horizontalResolution;
    u32                     verticalResolution;
    UefiGraphicsPixelFormat pixelFormat;
    UefiPixelBitmask        pixelInformation;
    u32                     pixelsPerScanLine;
};



#endif // UEFI_UEFIGRAPHICSOUTPUTMODEINFORMATION_H
