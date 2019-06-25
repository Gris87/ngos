#ifndef UEFI_UEFIBOOTSERVICES_H
#define UEFI_UEFIBOOTSERVICES_H



#include <uefi/macros.h>
#include <uefi/types.h>
#include <uefi/uefiallocatetype.h>
#include <uefi/uefidevicepath.h>
#include <uefi/uefieventtype.h>
#include <uefi/uefiguid.h>
#include <uefi/uefiinterfacetype.h>
#include <uefi/uefilocatesearchtype.h>
#include <uefi/uefimemorydescriptor.h>
#include <uefi/uefimemorytype.h>
#include <uefi/uefiopenprotocolinformationentry.h>
#include <uefi/uefistatus.h>
#include <uefi/uefitableheader.h>
#include <uefi/uefitimerdelay.h>
#include <uefi/uefitpl.h>



typedef void (UEFI_API *uefi_event_notify) (uefi_event event, void *context);



struct UefiBootServices
{
    UefiTableHeader header;

    uefi_tpl (UEFI_API *raiseTpl)(uefi_tpl newTpl); // TEST: NO
    void (UEFI_API *restoreTpl)(uefi_tpl oldTpl); // TEST: NO

    UefiStatus (UEFI_API *allocatePages)(UefiAllocateType type, UefiMemoryType memoryType, u64 noPages, u64 *memory); // TEST: NO
    UefiStatus (UEFI_API *freePages)(u64 memory, u64 noPages); // TEST: NO
    UefiStatus (UEFI_API *getMemoryMap)(u64 *memoryMapSize, UefiMemoryDescriptor *memoryMap, u64 *mapKey, u64 *descriptorSize, u32 *descriptorVersion); // TEST: NO
    UefiStatus (UEFI_API *allocatePool)(UefiMemoryType poolType, u64 size, void **buffer); // TEST: NO
    UefiStatus (UEFI_API *freePool)(void *buffer); // TEST: NO

    UefiStatus (UEFI_API *createEvent)(UefiEventType type, uefi_tpl notifyTpl, uefi_event_notify notifyFunction, void *notifyContext, uefi_event *event); // TEST: NO
    UefiStatus (UEFI_API *setTimer)(uefi_event event, UefiTimerDelay type, u64 triggerTime); // TEST: NO
    UefiStatus (UEFI_API *waitForEvent)(u64 numberOfEvents, uefi_event *event, u64 *index); // TEST: NO
    UefiStatus (UEFI_API *signalEvent)(uefi_event event); // TEST: NO
    UefiStatus (UEFI_API *closeEvent)(uefi_event event); // TEST: NO
    UefiStatus (UEFI_API *checkEvent)(uefi_event event); // TEST: NO

    UefiStatus (UEFI_API *installProtocolInterface)(uefi_handle *handle, UefiGuid *protocol, UefiInterfaceType interfaceType, void *interface); // TEST: NO
    UefiStatus (UEFI_API *reinstallProtocolInterface)(uefi_handle handle, UefiGuid *protocol, void *oldInterface, void *newInterface); // TEST: NO
    UefiStatus (UEFI_API *uninstallProtocolInterface)(uefi_handle handle, UefiGuid *protocol, void *interface); // TEST: NO
    UefiStatus (UEFI_API *handleProtocol)(uefi_handle handle, UefiGuid *protocol, void **interface); // TEST: NO
    UefiStatus (UEFI_API *pcHandleProtocol)(uefi_handle handle, UefiGuid *protocol, void **interface); // TEST: NO
    UefiStatus (UEFI_API *registerProtocolNotify)(UefiGuid *protocol, uefi_event event, void **registration); // TEST: NO
    UefiStatus (UEFI_API *locateHandle)(UefiLocateSearchType searchType, UefiGuid *protocol, void *searchKey, u64 *bufferSize, uefi_handle *buffer); // TEST: NO
    UefiStatus (UEFI_API *locateDevicePath)(UefiGuid *protocol, UefiDevicePath **devicePath, uefi_handle *device); // TEST: NO
    UefiStatus (UEFI_API *installConfigurationTable)(UefiGuid *guid, void *table); // TEST: NO

    UefiStatus (UEFI_API *loadImage)(bool bootPolicy, uefi_handle parentImageHandle, UefiDevicePath *filePath, void *sourceBuffer, u64 sourceSize, uefi_handle *imageHandle); // TEST: NO
    UefiStatus (UEFI_API *startImage)(uefi_handle imageHandle, u64 *exitDataSize, char16 **exitData); // TEST: NO
    UefiStatus (UEFI_API *exit)(uefi_handle imageHandle, UefiStatus exitStatus, u64 exitDataSize, char16 *exitData); // TEST: NO
    UefiStatus (UEFI_API *unloadImage)(uefi_handle imageHandle); // TEST: NO
    UefiStatus (UEFI_API *exitBootServices)(uefi_handle imageHandle, u64 mapKey); // TEST: NO

    UefiStatus (UEFI_API *getNextMonotonicCount)(u64 *count); // TEST: NO
    UefiStatus (UEFI_API *stall)(u64 microseconds); // TEST: NO
    UefiStatus (UEFI_API *setWatchdogTimer)(u64 timeout, u64 watchdogCode, u64 dataSize, char16 *watchdogData); // TEST: NO

    UefiStatus (UEFI_API *connectController)(uefi_handle controllerHandle, uefi_handle *driverImageHandle, UefiDevicePath *remainingDevicePath, bool recursive); // TEST: NO
    UefiStatus (UEFI_API *disconnectController)(uefi_handle controllerHandle, uefi_handle driverImageHandle, uefi_handle childHandle); // TEST: NO

    UefiStatus (UEFI_API *openProtocol)(uefi_handle handle, UefiGuid *protocol, void **interface, uefi_handle agentHandle, uefi_handle controllerHandle, u32 attributes); // TEST: NO
    UefiStatus (UEFI_API *closeProtocol)(uefi_handle handle, UefiGuid *protocol, uefi_handle agentHandle, uefi_handle controllerHandle); // TEST: NO
    UefiStatus (UEFI_API *openProtocolInformation)(uefi_handle handle, UefiGuid *protocol, UefiOpenProtocolInformationEntry **entryBuffer, u64 *entryCount); // TEST: NO

    UefiStatus (UEFI_API *protocolsPerHandle)(uefi_handle handle, UefiGuid ***protocolBuffer, u64 *protocolBufferCount); // TEST: NO
    UefiStatus (UEFI_API *locateHandleBuffer)(UefiLocateSearchType searchType, UefiGuid *protocol, void *searchKey, u64 *noHandles, uefi_handle **buffer); // TEST: NO
    UefiStatus (UEFI_API *locateProtocol)(UefiGuid *protocol, void *registration, void **interface); // TEST: NO
    UefiStatus (UEFI_API *installMultipleProtocolInterfaces)(uefi_handle *handle, ...); // TEST: NO
    UefiStatus (UEFI_API *uninstallMultipleProtocolInterfaces)(uefi_handle handle, ...); // TEST: NO

    UefiStatus (UEFI_API *calculateCrc32)(void *data, u64 dataSize, u32 *crc32); // TEST: NO

    void (UEFI_API *copyMem)(void *destination, void *source, u64 length); // TEST: NO
    void (UEFI_API *setMem)(void *buffer, u64 size, u8 value); // TEST: NO
    UefiStatus (UEFI_API *createEventEx)(u32 type, uefi_tpl notifyTpl, uefi_event_notify notifyFunction, const void *notifyContext, const UefiGuid eventGroup, uefi_event *event); // TEST: NO
};



#endif // UEFI_UEFIBOOTSERVICES_H
