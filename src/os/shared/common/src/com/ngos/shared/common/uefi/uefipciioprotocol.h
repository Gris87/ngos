#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIIOPROTOCOL_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIIOPROTOCOL_H



#include <com/ngos/shared/common/uefi/macros.h>
#include <com/ngos/shared/common/uefi/types.h>
#include <com/ngos/shared/common/uefi/uefiallocatetype.h>
#include <com/ngos/shared/common/uefi/uefimemorytype.h>
#include <com/ngos/shared/common/uefi/uefipciioprotocolaccess.h>
#include <com/ngos/shared/common/uefi/uefipciioprotocolattributeoperation.h>
#include <com/ngos/shared/common/uefi/uefipciioprotocolconfigaccess.h>
#include <com/ngos/shared/common/uefi/uefipciioprotocoloperation.h>
#include <com/ngos/shared/common/uefi/uefipciioprotocolwidth.h>
#include <com/ngos/shared/common/uefi/uefistatus.h>



#define UEFI_PCI_IO_PROTOCOL_GUID \
    { 0x4CF5B200, 0x68B8, 0x4CA5, { 0x9E, 0xEC, 0xB2, 0x3E, 0x3F, 0x50, 0x02, 0x9A } }



struct UefiPciIoProtocol
{
    UefiStatus (UEFI_API *pollMem)(UefiPciIoProtocol *obj, UefiPciIoProtocolWidth width, u8 barIndex, u64 offset, u64 mask, u64 value, u64 delay, u64 *result); // TEST: NO
    UefiStatus (UEFI_API *pollIo)(UefiPciIoProtocol *obj, UefiPciIoProtocolWidth width, u8 barIndex, u64 offset, u64 mask, u64 value, u64 delay, u64 *result); // TEST: NO

    UefiPciIoProtocolAccess       mem;
    UefiPciIoProtocolAccess       io;
    UefiPciIoProtocolConfigAccess pci;

    UefiStatus (UEFI_API *copyMem)(UefiPciIoProtocol *obj, UefiPciIoProtocolWidth width, u8 destBarIndex, u64 destOffset, u8 srcBarIndex, u64 srcOffset, u64 count); // TEST: NO
    UefiStatus (UEFI_API *map)(UefiPciIoProtocol *obj, UefiPciIoProtocolOperation operation, void *hostAddress, u64 *numberOfBytes, u64 *deviceAddress, void **mapping); // TEST: NO
    UefiStatus (UEFI_API *unmap)(UefiPciIoProtocol *obj, void *mapping); // TEST: NO
    UefiStatus (UEFI_API *allocateBuffer)(UefiPciIoProtocol *obj, UefiAllocateType type, UefiMemoryType memoryType, u64 pages, void **HostAddress, u64 attributes); // TEST: NO
    UefiStatus (UEFI_API *freeBuffer)(UefiPciIoProtocol *obj, u64 pages, void *hostAddress); // TEST: NO
    UefiStatus (UEFI_API *flush)(UefiPciIoProtocol *obj); // TEST: NO
    UefiStatus (UEFI_API *getLocation)(UefiPciIoProtocol *obj, u64 *segmentNumber, u64 *busNumber, u64 *deviceNumber, u64 *functionNumber); // TEST: NO
    UefiStatus (UEFI_API *attributes)(UefiPciIoProtocol *obj, UefiPciIoProtocolAttributeOperation operation, u64 attributes, u64 *result); // TEST: NO
    UefiStatus (UEFI_API *getBarAttributes)(UefiPciIoProtocol *obj, u8 barIndex, u64 *supports, void **resources); // TEST: NO
    UefiStatus (UEFI_API *setBarAttributes)(UefiPciIoProtocol *obj, u64 attributes, u8 barIndex, u64 *offset, u64 *length); // TEST: NO

    u64   romSize;
    void *romImage;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPCIIOPROTOCOL_H
