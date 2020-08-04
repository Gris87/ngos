#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIROOTBRIDGEIOPROTOCOLACCESS_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIROOTBRIDGEIOPROTOCOLACCESS_H



#include <com/ngos/shared/common/uefi/macros.h>
#include <com/ngos/shared/common/uefi/uefipcirootbridgeioprotocolwidth.h>
#include <com/ngos/shared/common/uefi/uefistatus.h>



struct UefiPciRootBridgeIoProtocol;



struct UefiPciRootBridgeIoProtocolAccess
{
    UefiStatus (UEFI_API *read)(UefiPciRootBridgeIoProtocol *obj, UefiPciRootBridgeIoProtocolWidth width, u64 address, u64 count, void *buffer); // TEST: NO
    UefiStatus (UEFI_API *write)(UefiPciRootBridgeIoProtocol *obj, UefiPciRootBridgeIoProtocolWidth width, u64 address, u64 count, void *buffer); // TEST: NO
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIROOTBRIDGEIOPROTOCOLACCESS_H
