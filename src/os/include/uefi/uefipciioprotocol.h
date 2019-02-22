#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIPCIIOPROTOCOL_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIPCIIOPROTOCOL_H



#include "src/bits64/a_uefi/uefi/lib/efiallocatetype.h"
#include "src/bits64/a_uefi/uefi/lib/efidefines.h"
#include "src/bits64/a_uefi/uefi/lib/efimemorytype.h"
#include "src/bits64/a_uefi/uefi/lib/efipciioprotocolaccess.h"
#include "src/bits64/a_uefi/uefi/lib/efipciioprotocolattributeoperation.h"
#include "src/bits64/a_uefi/uefi/lib/efipciioprotocolconfigaccess.h"
#include "src/bits64/a_uefi/uefi/lib/efipciioprotocoloperation.h"
#include "src/bits64/a_uefi/uefi/lib/efipciioprotocolwidth.h"
#include "src/bits64/a_uefi/uefi/lib/efistatus.h"
#include "src/bits64/a_uefi/uefi/lib/efitypes.h"



#define EFI_PCI_IO_PROTOCOL_GUID \
    { 0x4CF5B200, 0x68B8, 0x4CA5, {0x9E, 0xEC, 0xB2, 0x3E, 0x3F, 0x50, 0x02, 0x9A} }



struct EfiPciIoProtocol
{
    EfiStatus (EFIAPI *pollMem)(EfiPciIoProtocol *obj, EfiPciIoProtocolWidth width, u8 barIndex, u64 offset, u64 mask, u64 value, u64 delay, u64 *result); // TEST: NO
    EfiStatus (EFIAPI *pollIo)(EfiPciIoProtocol *obj, EfiPciIoProtocolWidth width, u8 barIndex, u64 offset, u64 mask, u64 value, u64 delay, u64 *result); // TEST: NO

    EfiPciIoProtocolAccess       mem;
    EfiPciIoProtocolAccess       io;
    EfiPciIoProtocolConfigAccess pci;

    EfiStatus (EFIAPI *copyMem)(EfiPciIoProtocol *obj, EfiPciIoProtocolWidth width, u8 destBarIndex, u64 destOffset, u8 srcBarIndex, u64 srcOffset, u64 count); // TEST: NO
    EfiStatus (EFIAPI *map)(EfiPciIoProtocol *obj, EfiPciIoProtocolOperation operation, void *hostAddress, u64 *numberOfBytes, efi_physical_address *deviceAddress, void **mapping); // TEST: NO
    EfiStatus (EFIAPI *unmap)(EfiPciIoProtocol *obj, void *mapping); // TEST: NO
    EfiStatus (EFIAPI *allocateBuffer)(EfiPciIoProtocol *obj, EfiAllocateType type, EfiMemoryType memoryType, u64 pages, void **HostAddress, u64 attributes); // TEST: NO
    EfiStatus (EFIAPI *freeBuffer)(EfiPciIoProtocol *obj, u64 pages, void *HostAddress); // TEST: NO
    EfiStatus (EFIAPI *flush)(EfiPciIoProtocol *obj); // TEST: NO
    EfiStatus (EFIAPI *getLocation)(EfiPciIoProtocol *obj, u64 *segmentNumber, u64 *busNumber, u64 *deviceNumber, u64 *functionNumber); // TEST: NO
    EfiStatus (EFIAPI *attributes)(EfiPciIoProtocol *obj, EfiPciIoProtocolAttributeOperation operation, u64 attributes, u64 *result); // TEST: NO
    EfiStatus (EFIAPI *getBarAttributes)(EfiPciIoProtocol *obj, u8 barIndex, u64 *supports, void **resources); // TEST: NO
    EfiStatus (EFIAPI *setBarAttributes)(EfiPciIoProtocol *obj, u64 attributes, u8 barIndex, u64 *offset, u64 *length); // TEST: NO

    u64   romSize;
    void *romImage;
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIPCIIOPROTOCOL_H
