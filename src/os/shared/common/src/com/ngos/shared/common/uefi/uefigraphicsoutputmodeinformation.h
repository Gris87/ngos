#ifndef UEFI_UEFIGRAPHICSOUTPUTMODEINFORMATION_H
#define UEFI_UEFIGRAPHICSOUTPUTMODEINFORMATION_H



#include <ngos/types.h>
#include <uefi/uefigraphicspixelformat.h>
#include <uefi/uefipixelbitmask.h>



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
