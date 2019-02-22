#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIGRAPHICSOUTPUTMODEINFORMATION_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIGRAPHICSOUTPUTMODEINFORMATION_H



#include <ngos/types.h>

#include "src/bits64/a_uefi/uefi/lib/efigraphicspixelformat.h"
#include "src/bits64/a_uefi/uefi/lib/efipixelbitmask.h"



struct EfiGraphicsOutputModeInformation
{
    u32                    version;
    u32                    horizontalResolution;
    u32                    verticalResolution;
    EfiGraphicsPixelFormat pixelFormat;
    EfiPixelBitmask        pixelInformation;
    u32                    pixelsPerScanLine;
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIGRAPHICSOUTPUTMODEINFORMATION_H
