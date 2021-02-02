#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIOPENPROTOCOLINFORMATIONENTRY_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIOPENPROTOCOLINFORMATIONENTRY_H



#include <com/ngos/shared/common/uefi/types.h>



struct UefiOpenProtocolInformationEntry
{
    uefi_handle agentHandle;
    uefi_handle controllerHandle;
    bad_uint32         attributes;
    bad_uint32         openCount;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIOPENPROTOCOLINFORMATIONENTRY_H
