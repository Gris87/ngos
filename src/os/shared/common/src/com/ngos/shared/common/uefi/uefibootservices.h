#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIBOOTSERVICES_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIBOOTSERVICES_H



#include <com/ngos/shared/common/guid/guid.h>
#include <com/ngos/shared/common/uefi/macros.h>
#include <com/ngos/shared/common/uefi/types.h>
#include <com/ngos/shared/common/uefi/uefiallocatetype.h>
#include <com/ngos/shared/common/uefi/uefidevicepath.h>
#include <com/ngos/shared/common/uefi/uefieventtype.h>
#include <com/ngos/shared/common/uefi/uefiinterfacetype.h>
#include <com/ngos/shared/common/uefi/uefilocatesearchtype.h>
#include <com/ngos/shared/common/uefi/uefimemorydescriptor.h>
#include <com/ngos/shared/common/uefi/uefimemorytype.h>
#include <com/ngos/shared/common/uefi/uefiopenprotocolinformationentry.h>
#include <com/ngos/shared/common/uefi/uefistatus.h>
#include <com/ngos/shared/common/uefi/uefitableheader.h>
#include <com/ngos/shared/common/uefi/uefitimerdelay.h>
#include <com/ngos/shared/common/uefi/uefitpl.h>



#define UEFI_TIMER_MICROSECOND 10   // 10 * 100 ns
#define UEFI_TIMER_MILLISECOND (1000 * UEFI_TIMER_MICROSECOND)
#define UEFI_TIMER_SECOND      (1000 * UEFI_TIMER_MILLISECOND)

#define UEFI_STALL_MICROSECOND 1    // 1 * 1000 ns
#define UEFI_STALL_MILLISECOND (1000 * UEFI_STALL_MICROSECOND)
#define UEFI_STALL_SECOND      (1000 * UEFI_STALL_MILLISECOND)



typedef void (UEFI_API *uefi_event_notify) (uefi_event event, void *context);



struct UefiBootServices
{
    UefiTableHeader header;

    UefiTpl (UEFI_API *raiseTpl)(UefiTpl newTpl); // TEST: NO
    void (UEFI_API *restoreTpl)(UefiTpl oldTpl); // TEST: NO

    UefiStatus (UEFI_API *allocatePages)(UefiAllocateType type, UefiMemoryType memoryType, bad_uint64 noPages, bad_uint64 *memory); // TEST: NO
    UefiStatus (UEFI_API *freePages)(bad_uint64 memory, bad_uint64 noPages); // TEST: NO
    UefiStatus (UEFI_API *getMemoryMap)(bad_uint64 *memoryMapSize, UefiMemoryDescriptor *memoryMap, bad_uint64 *mapKey, bad_uint64 *descriptorSize, bad_uint32 *descriptorVersion); // TEST: NO
    UefiStatus (UEFI_API *allocatePool)(UefiMemoryType poolType, bad_uint64 size, void **buffer); // TEST: NO
    UefiStatus (UEFI_API *freePool)(void *buffer); // TEST: NO

    UefiStatus (UEFI_API *createEvent)(UefiEventType type, UefiTpl notifyTpl, uefi_event_notify notifyFunction, void *notifyContext, uefi_event *event); // TEST: NO
    UefiStatus (UEFI_API *setTimer)(uefi_event event, UefiTimerDelay type, bad_uint64 triggerTime); // TEST: NO
    UefiStatus (UEFI_API *waitForEvent)(bad_uint64 numberOfEvents, uefi_event *event, bad_uint64 *index); // TEST: NO
    UefiStatus (UEFI_API *signalEvent)(uefi_event event); // TEST: NO
    UefiStatus (UEFI_API *closeEvent)(uefi_event event); // TEST: NO
    UefiStatus (UEFI_API *checkEvent)(uefi_event event); // TEST: NO

    UefiStatus (UEFI_API *installProtocolInterface)(uefi_handle *handle, Guid *protocol, UefiInterfaceType interfaceType, void *interface); // TEST: NO
    UefiStatus (UEFI_API *reinstallProtocolInterface)(uefi_handle handle, Guid *protocol, void *oldInterface, void *newInterface); // TEST: NO
    UefiStatus (UEFI_API *uninstallProtocolInterface)(uefi_handle handle, Guid *protocol, void *interface); // TEST: NO
    UefiStatus (UEFI_API *handleProtocol)(uefi_handle handle, Guid *protocol, void **interface); // TEST: NO
    UefiStatus (UEFI_API *pcHandleProtocol)(uefi_handle handle, Guid *protocol, void **interface); // TEST: NO
    UefiStatus (UEFI_API *registerProtocolNotify)(Guid *protocol, uefi_event event, void **registration); // TEST: NO
    UefiStatus (UEFI_API *locateHandle)(UefiLocateSearchType searchType, Guid *protocol, void *searchKey, bad_uint64 *bufferSize, uefi_handle *buffer); // TEST: NO
    UefiStatus (UEFI_API *locateDevicePath)(Guid *protocol, UefiDevicePath **devicePath, uefi_handle *device); // TEST: NO
    UefiStatus (UEFI_API *installConfigurationTable)(Guid *guid, void *table); // TEST: NO

    UefiStatus (UEFI_API *loadImage)(bool bootPolicy, uefi_handle parentImageHandle, UefiDevicePath *filePath, void *sourceBuffer, bad_uint64 sourceSize, uefi_handle *imageHandle); // TEST: NO
    UefiStatus (UEFI_API *startImage)(uefi_handle imageHandle, bad_uint64 *exitDataSize, char16 **exitData); // TEST: NO
    UefiStatus (UEFI_API *exit)(uefi_handle imageHandle, UefiStatus exitStatus, bad_uint64 exitDataSize, char16 *exitData); // TEST: NO
    UefiStatus (UEFI_API *unloadImage)(uefi_handle imageHandle); // TEST: NO
    UefiStatus (UEFI_API *exitBootServices)(uefi_handle imageHandle, bad_uint64 mapKey); // TEST: NO

    UefiStatus (UEFI_API *getNextMonotonicCount)(bad_uint64 *count); // TEST: NO
    UefiStatus (UEFI_API *stall)(bad_uint64 microseconds); // TEST: NO
    UefiStatus (UEFI_API *setWatchdogTimer)(bad_uint64 timeout, bad_uint64 watchdogCode, bad_uint64 dataSize, char16 *watchdogData); // TEST: NO

    UefiStatus (UEFI_API *connectController)(uefi_handle controllerHandle, uefi_handle *driverImageHandle, UefiDevicePath *remainingDevicePath, bool recursive); // TEST: NO
    UefiStatus (UEFI_API *disconnectController)(uefi_handle controllerHandle, uefi_handle driverImageHandle, uefi_handle childHandle); // TEST: NO

    UefiStatus (UEFI_API *openProtocol)(uefi_handle handle, Guid *protocol, void **interface, uefi_handle agentHandle, uefi_handle controllerHandle, bad_uint32 attributes); // TEST: NO
    UefiStatus (UEFI_API *closeProtocol)(uefi_handle handle, Guid *protocol, uefi_handle agentHandle, uefi_handle controllerHandle); // TEST: NO
    UefiStatus (UEFI_API *openProtocolInformation)(uefi_handle handle, Guid *protocol, UefiOpenProtocolInformationEntry **entryBuffer, bad_uint64 *entryCount); // TEST: NO

    UefiStatus (UEFI_API *protocolsPerHandle)(uefi_handle handle, Guid ***protocolBuffer, bad_uint64 *protocolBufferCount); // TEST: NO
    UefiStatus (UEFI_API *locateHandleBuffer)(UefiLocateSearchType searchType, Guid *protocol, void *searchKey, bad_uint64 *noHandles, uefi_handle **buffer); // TEST: NO
    UefiStatus (UEFI_API *locateProtocol)(Guid *protocol, void *registration, void **interface); // TEST: NO
    UefiStatus (UEFI_API *installMultipleProtocolInterfaces)(uefi_handle *handle, ...); // TEST: NO
    UefiStatus (UEFI_API *uninstallMultipleProtocolInterfaces)(uefi_handle handle, ...); // TEST: NO

    UefiStatus (UEFI_API *calculateCrc32)(void *data, bad_uint64 dataSize, bad_uint32 *crc32); // TEST: NO

    void (UEFI_API *copyMem)(void *destination, void *source, bad_uint64 length); // TEST: NO
    void (UEFI_API *setMem)(void *buffer, bad_uint64 size, bad_uint8 value); // TEST: NO
    UefiStatus (UEFI_API *createEventEx)(bad_uint32 type, UefiTpl notifyTpl, uefi_event_notify notifyFunction, const void *notifyContext, const Guid eventGroup, uefi_event *event); // TEST: NO
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIBOOTSERVICES_H
