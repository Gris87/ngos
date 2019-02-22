#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIOPENPROTOCOLINFORMATIONENTRY_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIOPENPROTOCOLINFORMATIONENTRY_H



#include "src/bits64/a_uefi/uefi/lib/efitypes.h"



struct EfiOpenProtocolInformationEntry
{
    EfiHandle agentHandle;
    EfiHandle controllerHandle;
    u32       attributes;
    u32       openCount;
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIOPENPROTOCOLINFORMATIONENTRY_H
