#ifndef UEFI_UEFIPCIIOPROTOCOLCONFIGACCESS_H
#define UEFI_UEFIPCIIOPROTOCOLCONFIGACCESS_H



#include <uefi/macros.h>
#include <uefi/uefipciioprotocolwidth.h>
#include <uefi/uefistatus.h>



struct UefiPciIoProtocol;



struct UefiPciIoProtocolConfigAccess
{
    UefiStatus (UEFI_API *read)(UefiPciIoProtocol *obj, UefiPciIoProtocolWidth width, u32 offset, u64 count, void *buffer); // TEST: NO
    UefiStatus (UEFI_API *write)(UefiPciIoProtocol *obj, UefiPciIoProtocolWidth width, u32 offset, u64 count, void *buffer); // TEST: NO
};



#endif // UEFI_UEFIPCIIOPROTOCOLCONFIGACCESS_H
