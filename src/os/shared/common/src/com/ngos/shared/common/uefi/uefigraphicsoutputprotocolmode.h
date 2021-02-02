#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTPROTOCOLMODE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTPROTOCOLMODE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/types.h>
#include <com/ngos/shared/common/uefi/uefigraphicsoutputmodeinformation.h>



struct UefiGraphicsOutputProtocolMode
{
    bad_uint32                                maxMode;
    bad_uint32                                mode;
    UefiGraphicsOutputModeInformation *info;
    bad_uint64                                sizeOfInfo;
    bad_uint64                                frameBufferBase;
    bad_uint64                                frameBufferSize;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIGRAPHICSOUTPUTPROTOCOLMODE_H
