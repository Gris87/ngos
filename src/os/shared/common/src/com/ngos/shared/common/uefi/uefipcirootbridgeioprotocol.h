#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIROOTBRIDGEIOPROTOCOL_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIROOTBRIDGEIOPROTOCOL_H



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



// Ignore CppAlignmentVerifier [BEGIN]
#define UEFI_PCI_ADDRESS(bus, device, function, reg) \
    (bad_uint64)( \
    ((bad_uint64)(bus)      << 24) | \
    ((bad_uint64)(device)   << 16) | \
    ((bad_uint64)(function) << 8)  | \
    ((bad_uint64)(reg) < 256 ? (bad_uint64)(reg) : ((bad_uint64)(reg) << 32)))
// Ignore CppAlignmentVerifier [END]



struct UefiPciRootBridgeIoProtocol
{
    uefi_handle parentHandle;

    UefiStatus (UEFI_API *pollMem)(UefiPciRootBridgeIoProtocol *obj, UefiPciRootBridgeIoProtocolWidth width, bad_uint64 address, bad_uint64 mask, bad_uint64 value, bad_uint64 delay, bad_uint64 *result); // TEST: NO
    UefiStatus (UEFI_API *pollIo)(UefiPciRootBridgeIoProtocol *obj, UefiPciRootBridgeIoProtocolWidth width, bad_uint64 address, bad_uint64 mask, bad_uint64 value, bad_uint64 delay, bad_uint64 *result); // TEST: NO

    UefiPciRootBridgeIoProtocolAccess mem;
    UefiPciRootBridgeIoProtocolAccess io;
    UefiPciRootBridgeIoProtocolAccess pci;

    UefiStatus (UEFI_API *copyMem)(UefiPciRootBridgeIoProtocol *obj, UefiPciRootBridgeIoProtocolWidth width, bad_uint64 destinationAddress, bad_uint8 sourceAddress, bad_uint64 count); // TEST: NO
    UefiStatus (UEFI_API *map)(UefiPciRootBridgeIoProtocol *obj, UefiPciRootBridgeIoProtocolOperation operation, void *hostAddress, bad_uint64 *numberOfBytes, bad_uint64 *deviceAddress, void **mapping); // TEST: NO
    UefiStatus (UEFI_API *unmap)(UefiPciRootBridgeIoProtocol *obj, void *mapping); // TEST: NO
    UefiStatus (UEFI_API *allocateBuffer)(UefiPciRootBridgeIoProtocol *obj, UefiAllocateType type, UefiMemoryType memoryType, bad_uint64 pages, void **HostAddress, bad_uint64 attributes); // TEST: NO
    UefiStatus (UEFI_API *freeBuffer)(UefiPciRootBridgeIoProtocol *obj, bad_uint64 pages, void *hostAddress); // TEST: NO
    UefiStatus (UEFI_API *flush)(UefiPciRootBridgeIoProtocol *obj); // TEST: NO
    UefiStatus (UEFI_API *getAttributes)(UefiPciRootBridgeIoProtocol *obj, bad_uint64 *supports, bad_uint64 *attributes); // TEST: NO
    UefiStatus (UEFI_API *setAttributes)(UefiPciRootBridgeIoProtocol *obj, bad_uint64 attributes, bad_uint64 *resourceBase, bad_uint64 *resourceLength); // TEST: NO
    UefiStatus (UEFI_API *configuration)(UefiPciRootBridgeIoProtocol *obj, UefiAcpiAddressSpaceDescriptor **resources); // TEST: NO

    bad_uint32 segmentNumber;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIROOTBRIDGEIOPROTOCOL_H
