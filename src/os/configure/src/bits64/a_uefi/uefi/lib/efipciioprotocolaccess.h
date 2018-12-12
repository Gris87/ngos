#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIPCIIOPROTOCOLACCESS_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIPCIIOPROTOCOLACCESS_H



#include "src/bits64/a_uefi/uefi/lib/efidefines.h"
#include "src/bits64/a_uefi/uefi/lib/efipciioprotocolwidth.h"
#include "src/bits64/a_uefi/uefi/lib/efistatus.h"



struct EfiPciIoProtocol;



struct EfiPciIoProtocolAccess
{
    EfiStatus (EFIAPI *read)(EfiPciIoProtocol *obj, EfiPciIoProtocolWidth width, u8 barIndex, u64 offset, u64 count, void *buffer); // TEST: NO
    EfiStatus (EFIAPI *write)(EfiPciIoProtocol *obj, EfiPciIoProtocolWidth width, u8 barIndex, u64 offset, u64 count, void *buffer); // TEST: NO
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIPCIIOPROTOCOLACCESS_H
