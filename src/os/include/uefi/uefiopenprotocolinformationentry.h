#ifndef UEFI_UEFIOPENPROTOCOLINFORMATIONENTRY_H
#define UEFI_UEFIOPENPROTOCOLINFORMATIONENTRY_H



#include <uefi/types.h>



struct UefiOpenProtocolInformationEntry
{
    uefi_handle agentHandle;
    uefi_handle controllerHandle;
    u32         attributes;
    u32         openCount;
};



#endif // UEFI_UEFIOPENPROTOCOLINFORMATIONENTRY_H
