#ifndef UEFI_UEFIGRAPHICSOUTPUTPROTOCOLMODE_H
#define UEFI_UEFIGRAPHICSOUTPUTPROTOCOLMODE_H



#include <ngos/types.h>
#include <uefi/uefigraphicsoutputmodeinformation.h>
#include <uefi/types.h>



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
