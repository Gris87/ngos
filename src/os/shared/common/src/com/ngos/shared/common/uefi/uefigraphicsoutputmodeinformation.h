#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTMODEINFORMATION_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTMODEINFORMATION_H



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



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTMODEINFORMATION_H
