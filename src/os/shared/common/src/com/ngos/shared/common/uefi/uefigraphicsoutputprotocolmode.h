#ifndef UEFI_UEFIGRAPHICSOUTPUTPROTOCOLMODE_H
#define UEFI_UEFIGRAPHICSOUTPUTPROTOCOLMODE_H



#include <common/src/com/ngos/shared/common/ngos/types.h>
#include <common/src/com/ngos/shared/common/uefi/types.h>
#include <common/src/com/ngos/shared/common/uefi/uefigraphicsoutputmodeinformation.h>



struct UefiGraphicsOutputProtocolMode
{
    u32                                maxMode;
    u32                                mode;
    UefiGraphicsOutputModeInformation *info;
    u64                                sizeOfInfo;
    u64                                frameBufferBase;
    u64                                frameBufferSize;
};



#endif // UEFI_UEFIGRAPHICSOUTPUTPROTOCOLMODE_H
