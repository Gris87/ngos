#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIGRAPHICSOUTPUTPROTOCOLMODE_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIGRAPHICSOUTPUTPROTOCOLMODE_H



#include <ngos/types.h>

#include "src/bits64/a_uefi/uefi/lib/efigraphicsoutputmodeinformation.h"
#include "src/bits64/a_uefi/uefi/lib/efitypes.h"



struct EfiGraphicsOutputProtocolMode
{
    u32                               maxMode;
    u32                               mode;
    EfiGraphicsOutputModeInformation *info;
    u64                               sizeOfInfo;
    efi_physical_address              frameBufferBase;
    u64                               frameBufferSize;
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIGRAPHICSOUTPUTPROTOCOLMODE_H
