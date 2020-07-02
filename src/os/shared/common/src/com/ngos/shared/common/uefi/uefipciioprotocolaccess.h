#ifndef UEFI_UEFIPCIIOPROTOCOLACCESS_H
#define UEFI_UEFIPCIIOPROTOCOLACCESS_H



#include <common/src/com/ngos/shared/common/uefi/macros.h>
#include <common/src/com/ngos/shared/common/uefi/uefipciioprotocolwidth.h>
#include <common/src/com/ngos/shared/common/uefi/uefistatus.h>



struct UefiPciIoProtocol;



struct UefiPciIoProtocolAccess
{
    UefiStatus (UEFI_API *read)(UefiPciIoProtocol *obj, UefiPciIoProtocolWidth width, u8 barIndex, u64 offset, u64 count, void *buffer); // TEST: NO
    UefiStatus (UEFI_API *write)(UefiPciIoProtocol *obj, UefiPciIoProtocolWidth width, u8 barIndex, u64 offset, u64 count, void *buffer); // TEST: NO
};



#endif // UEFI_UEFIPCIIOPROTOCOLACCESS_H
