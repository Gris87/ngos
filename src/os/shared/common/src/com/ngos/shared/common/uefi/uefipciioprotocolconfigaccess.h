#ifndef UEFI_UEFIPCIIOPROTOCOLCONFIGACCESS_H
#define UEFI_UEFIPCIIOPROTOCOLCONFIGACCESS_H



#include <common/src/com/ngos/shared/common/uefi/macros.h>
#include <common/src/com/ngos/shared/common/uefi/uefipciioprotocolwidth.h>
#include <common/src/com/ngos/shared/common/uefi/uefistatus.h>



struct UefiPciIoProtocol;



struct UefiPciIoProtocolConfigAccess
{
    UefiStatus (UEFI_API *read)(UefiPciIoProtocol *obj, UefiPciIoProtocolWidth width, u32 offset, u64 count, void *buffer); // TEST: NO
    UefiStatus (UEFI_API *write)(UefiPciIoProtocol *obj, UefiPciIoProtocolWidth width, u32 offset, u64 count, void *buffer); // TEST: NO
};



#endif // UEFI_UEFIPCIIOPROTOCOLCONFIGACCESS_H
