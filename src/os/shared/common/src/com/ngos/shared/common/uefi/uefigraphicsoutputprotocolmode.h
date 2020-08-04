#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTPROTOCOLMODE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTPROTOCOLMODE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/types.h>
#include <com/ngos/shared/common/uefi/uefigraphicsoutputmodeinformation.h>



struct UefiGraphicsOutputProtocolMode
{
    u32                                maxMode;
    u32                                mode;
    UefiGraphicsOutputModeInformation *info;
    u64                                sizeOfInfo;
    u64                                frameBufferBase;
    u64                                frameBufferSize;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTPROTOCOLMODE_H
