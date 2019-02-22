#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIBOOTSERVICES_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIBOOTSERVICES_H



#include "src/bits64/a_uefi/uefi/lib/efiallocatetype.h"
#include "src/bits64/a_uefi/uefi/lib/efidefines.h"
#include "src/bits64/a_uefi/uefi/lib/efidevicepath.h"
#include "src/bits64/a_uefi/uefi/lib/efifunctors.h"
#include "src/bits64/a_uefi/uefi/lib/efiguid.h"
#include "src/bits64/a_uefi/uefi/lib/efiinterfacetype.h"
#include "src/bits64/a_uefi/uefi/lib/efilocatesearchtype.h"
#include "src/bits64/a_uefi/uefi/lib/efimemorydescriptor.h"
#include "src/bits64/a_uefi/uefi/lib/efimemorytype.h"
#include "src/bits64/a_uefi/uefi/lib/efiopenprotocolinformationentry.h"
#include "src/bits64/a_uefi/uefi/lib/efistatus.h"
#include "src/bits64/a_uefi/uefi/lib/efitableheader.h"
#include "src/bits64/a_uefi/uefi/lib/efitimerdelay.h"
#include "src/bits64/a_uefi/uefi/lib/efitpl.h"
#include "src/bits64/a_uefi/uefi/lib/efitypes.h"



struct EfiBootServices
{
    EfiTableHeader header;

    efi_tpl (EFIAPI *raiseTpl)(efi_tpl newTpl); // TEST: NO
    void (EFIAPI *restoreTpl)(efi_tpl oldTpl); // TEST: NO

    EfiStatus (EFIAPI *allocatePages)(EfiAllocateType type, EfiMemoryType memoryType, u64 noPages, efi_physical_address *memory); // TEST: NO
    EfiStatus (EFIAPI *freePages)(efi_physical_address memory, u64 noPages); // TEST: NO
    EfiStatus (EFIAPI *getMemoryMap)(u64 *memoryMapSize, EfiMemoryDescriptor *memoryMap, u64 *mapKey, u64 *descriptorSize, u32 *descriptorVersion); // TEST: NO
    EfiStatus (EFIAPI *allocatePool)(EfiMemoryType poolType, u64 size, void **buffer); // TEST: NO
    EfiStatus (EFIAPI *freePool)(void *buffer); // TEST: NO

    EfiStatus (EFIAPI *createEvent)(u32 type, efi_tpl notifyTpl, efi_event_notify notifyFunction, void *notifyContext, EfiEvent *event); // TEST: NO
    EfiStatus (EFIAPI *setTimer)(EfiEvent event, EfiTimerDelay type, u64 triggerTime); // TEST: NO
    EfiStatus (EFIAPI *waitForEvent)(u64 numberOfEvents, EfiEvent *event, u64 *index); // TEST: NO
    EfiStatus (EFIAPI *signalEvent)(EfiEvent event); // TEST: NO
    EfiStatus (EFIAPI *closeEvent)(EfiEvent event); // TEST: NO
    EfiStatus (EFIAPI *checkEvent)(EfiEvent event); // TEST: NO

    EfiStatus (EFIAPI *installProtocolInterface)(EfiHandle *handle, EfiGuid *protocol, EfiInterfaceType interfaceType, void *interface); // TEST: NO
    EfiStatus (EFIAPI *reinstallProtocolInterface)(EfiHandle handle, EfiGuid *protocol, void *oldInterface, void *newInterface); // TEST: NO
    EfiStatus (EFIAPI *uninstallProtocolInterface)(EfiHandle handle, EfiGuid *protocol, void *interface); // TEST: NO
    EfiStatus (EFIAPI *handleProtocol)(EfiHandle handle, EfiGuid *protocol, void **interface); // TEST: NO
    EfiStatus (EFIAPI *pcHandleProtocol)(EfiHandle handle, EfiGuid *protocol, void **interface); // TEST: NO
    EfiStatus (EFIAPI *registerProtocolNotify)(EfiGuid *protocol, EfiEvent event, void **registration); // TEST: NO
    EfiStatus (EFIAPI *locateHandle)(EfiLocateSearchType searchType, EfiGuid *protocol, void *searchKey, u64 *bufferSize, EfiHandle *buffer); // TEST: NO
    EfiStatus (EFIAPI *locateDevicePath)(EfiGuid *protocol, EfiDevicePath **devicePath, EfiHandle *device); // TEST: NO
    EfiStatus (EFIAPI *installConfigurationTable)(EfiGuid *guid, void *table); // TEST: NO

    EfiStatus (EFIAPI *loadImage)(bool bootPolicy, EfiHandle parentImageHandle, EfiDevicePath *filePath, void *sourceBuffer, u64 sourceSize, EfiHandle *imageHandle); // TEST: NO
    EfiStatus (EFIAPI *startImage)(EfiHandle imageHandle, u64 *exitDataSize, efi_char16 **exitData); // TEST: NO
    EfiStatus (EFIAPI *exit)(EfiHandle imageHandle, EfiStatus exitStatus, u64 exitDataSize, efi_char16 *exitData); // TEST: NO
    EfiStatus (EFIAPI *unloadImage)(EfiHandle imageHandle); // TEST: NO
    EfiStatus (EFIAPI *exitBootServices)(EfiHandle imageHandle, u64 mapKey); // TEST: NO

    EfiStatus (EFIAPI *getNextMonotonicCount)(u64 *count); // TEST: NO
    EfiStatus (EFIAPI *stall)(u64 microseconds); // TEST: NO
    EfiStatus (EFIAPI *setWatchdogTimer)(u64 timeout, u64 watchdogCode, u64 dataSize, efi_char16 *watchdogData); // TEST: NO

    EfiStatus (EFIAPI *connectController)(EfiHandle controllerHandle, EfiHandle *driverImageHandle, EfiDevicePath *remainingDevicePath, bool recursive); // TEST: NO
    EfiStatus (EFIAPI *disconnectController)(EfiHandle controllerHandle, EfiHandle driverImageHandle, EfiHandle childHandle); // TEST: NO

    EfiStatus (EFIAPI *openProtocol)(EfiHandle handle, EfiGuid *protocol, void **interface, EfiHandle agentHandle, EfiHandle controllerHandle, u32 attributes); // TEST: NO
    EfiStatus (EFIAPI *closeProtocol)(EfiHandle handle, EfiGuid *protocol, EfiHandle agentHandle, EfiHandle controllerHandle); // TEST: NO
    EfiStatus (EFIAPI *openProtocolInformation)(EfiHandle handle, EfiGuid *protocol, EfiOpenProtocolInformationEntry **entryBuffer, u64 *entryCount); // TEST: NO

    EfiStatus (EFIAPI *protocolsPerHandle)(EfiHandle handle, EfiGuid ***protocolBuffer, u64 *protocolBufferCount); // TEST: NO
    EfiStatus (EFIAPI *locateHandleBuffer)(EfiLocateSearchType searchType, EfiGuid *protocol, void *searchKey, u64 *noHandles, EfiHandle **buffer); // TEST: NO
    EfiStatus (EFIAPI *locateProtocol)(EfiGuid *protocol, void *registration, void **interface); // TEST: NO
    EfiStatus (EFIAPI *installMultipleProtocolInterfaces)(EfiHandle *handle, ...); // TEST: NO
    EfiStatus (EFIAPI *uninstallMultipleProtocolInterfaces)(EfiHandle handle, ...); // TEST: NO

    EfiStatus (EFIAPI *calculateCrc32)(void *data, u64 dataSize, u32 *crc32); // TEST: NO

    void (EFIAPI *copyMem)(void *destination, void *source, u64 length); // TEST: NO
    void (EFIAPI *setMem)(void *buffer, u64 size, u8 value); // TEST: NO
    EfiStatus (EFIAPI *createEventEx)(u32 type, efi_tpl notifyTpl, efi_event_notify notifyFunction, const void *notifyContext, const EfiGuid eventGroup, EfiEvent *event); // TEST: NO
};



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_LIB_EFIBOOTSERVICES_H
