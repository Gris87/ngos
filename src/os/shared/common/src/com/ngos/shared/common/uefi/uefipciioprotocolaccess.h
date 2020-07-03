#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIIOPROTOCOLACCESS_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIIOPROTOCOLACCESS_H



#include <common/src/com/ngos/shared/common/uefi/macros.h>
#include <common/src/com/ngos/shared/common/uefi/uefipciioprotocolwidth.h>
#include <common/src/com/ngos/shared/common/uefi/uefistatus.h>



struct UefiPciIoProtocol;



struct UefiPciIoProtocolAccess
{
    UefiStatus (UEFI_API *read)(UefiPciIoProtocol *obj, UefiPciIoProtocolWidth width, u8 barIndex, u64 offset, u64 count, void *buffer); // TEST: NO
    UefiStatus (UEFI_API *write)(UefiPciIoProtocol *obj, UefiPciIoProtocolWidth width, u8 barIndex, u64 offset, u64 count, void *buffer); // TEST: NO
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIIOPROTOCOLACCESS_H
