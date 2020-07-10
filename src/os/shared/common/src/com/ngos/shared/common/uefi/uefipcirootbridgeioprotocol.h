#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIROOTBRIDGEIOPROTOCOL_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIROOTBRIDGEIOPROTOCOL_H



#include <com/ngos/shared/common/uefi/macros.h>
#include <com/ngos/shared/common/uefi/types.h>
#include <com/ngos/shared/common/uefi/uefiacpiaddressspacedescriptor.h>
#include <com/ngos/shared/common/uefi/uefiallocatetype.h>
#include <com/ngos/shared/common/uefi/uefimemorytype.h>
#include <com/ngos/shared/common/uefi/uefipcirootbridgeioprotocolaccess.h>
#include <com/ngos/shared/common/uefi/uefipcirootbridgeioprotocoloperation.h>
#include <com/ngos/shared/common/uefi/uefipcirootbridgeioprotocolwidth.h>
#include <com/ngos/shared/common/uefi/uefistatus.h>



#define UEFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_GUID \
    { 0x2F707EBB, 0x4A1A, 0x11D4, { 0x9A, 0x38, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D } }



struct UefiPciRootBridgeIoProtocol
{
    uefi_handle parentHandle;

    UefiStatus (UEFI_API *pollMem)(UefiPciRootBridgeIoProtocol *obj, UefiPciRootBridgeIoProtocolWidth width, u64 address, u64 mask, u64 value, u64 delay, u64 *result); // TEST: NO
    UefiStatus (UEFI_API *pollIo)(UefiPciRootBridgeIoProtocol *obj, UefiPciRootBridgeIoProtocolWidth width, u64 address, u64 mask, u64 value, u64 delay, u64 *result); // TEST: NO

    UefiPciRootBridgeIoProtocolAccess mem;
    UefiPciRootBridgeIoProtocolAccess io;
    UefiPciRootBridgeIoProtocolAccess pci;

    UefiStatus (UEFI_API *copyMem)(UefiPciRootBridgeIoProtocol *obj, UefiPciRootBridgeIoProtocolWidth width, u64 destinationAddress, u8 sourceAddress, u64 count); // TEST: NO
    UefiStatus (UEFI_API *map)(UefiPciRootBridgeIoProtocol *obj, UefiPciRootBridgeIoProtocolOperation operation, void *hostAddress, u64 *numberOfBytes, u64 *deviceAddress, void **mapping); // TEST: NO
    UefiStatus (UEFI_API *unmap)(UefiPciRootBridgeIoProtocol *obj, void *mapping); // TEST: NO
    UefiStatus (UEFI_API *allocateBuffer)(UefiPciRootBridgeIoProtocol *obj, UefiAllocateType type, UefiMemoryType memoryType, u64 pages, void **HostAddress, u64 attributes); // TEST: NO
    UefiStatus (UEFI_API *freeBuffer)(UefiPciRootBridgeIoProtocol *obj, u64 pages, void *hostAddress); // TEST: NO
    UefiStatus (UEFI_API *flush)(UefiPciRootBridgeIoProtocol *obj); // TEST: NO
    UefiStatus (UEFI_API *getAttributes)(UefiPciRootBridgeIoProtocol *obj, u64 *supports, u64 *attributes); // TEST: NO
    UefiStatus (UEFI_API *setAttributes)(UefiPciRootBridgeIoProtocol *obj, u64 attributes, u64 *resourceBase, u64 *resourceLength); // TEST: NO
    UefiStatus (UEFI_API *configuration)(UefiPciRootBridgeIoProtocol *obj, UefiAcpiAddressSpaceDescriptor **resources); // TEST: NO

    u32 segmentNumber;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIROOTBRIDGEIOPROTOCOL_H
