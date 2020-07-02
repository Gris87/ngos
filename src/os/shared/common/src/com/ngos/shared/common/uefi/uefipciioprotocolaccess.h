#ifndef UEFI_UEFIPCIIOPROTOCOLACCESS_H
#define UEFI_UEFIPCIIOPROTOCOLACCESS_H



#include <uefi/macros.h>
#include <uefi/uefipciioprotocolwidth.h>
#include <uefi/uefistatus.h>



struct UefiPciIoProtocol;



struct UefiPciIoProtocolAccess
{
    UefiStatus (UEFI_API *read)(UefiPciIoProtocol *obj, UefiPciIoProtocolWidth width, u8 barIndex, u64 offset, u64 count, void *buffer); // TEST: NO
    UefiStatus (UEFI_API *write)(UefiPciIoProtocol *obj, UefiPciIoProtocolWidth width, u8 barIndex, u64 offset, u64 count, void *buffer); // TEST: NO
};



#endif // UEFI_UEFIPCIIOPROTOCOLACCESS_H
