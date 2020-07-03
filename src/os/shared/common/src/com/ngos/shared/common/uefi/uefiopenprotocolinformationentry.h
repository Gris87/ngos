#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIOPENPROTOCOLINFORMATIONENTRY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIOPENPROTOCOLINFORMATIONENTRY_H



#include <common/src/com/ngos/shared/common/uefi/types.h>



struct UefiOpenProtocolInformationEntry
{
    uefi_handle agentHandle;
    uefi_handle controllerHandle;
    u32         attributes;
    u32         openCount;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIOPENPROTOCOLINFORMATIONENTRY_H
