#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIIOPROTOCOLCONFIGACCESS_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIIOPROTOCOLCONFIGACCESS_H



#include <com/ngos/shared/common/uefi/macros.h>
#include <com/ngos/shared/common/uefi/uefipciioprotocolwidth.h>
#include <com/ngos/shared/common/uefi/uefistatus.h>



struct UefiPciIoProtocol;



struct UefiPciIoProtocolConfigAccess
{
    UefiStatus (UEFI_API *read)(UefiPciIoProtocol *obj, UefiPciIoProtocolWidth width, u32 offset, u64 count, void *buffer); // TEST: NO
    UefiStatus (UEFI_API *write)(UefiPciIoProtocol *obj, UefiPciIoProtocolWidth width, u32 offset, u64 count, void *buffer); // TEST: NO
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIIOPROTOCOLCONFIGACCESS_H
