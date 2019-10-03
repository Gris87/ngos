#ifndef OS_SHARED_UEFIBASE_SRC_BITS64_UEFI_UEFI_H
#define OS_SHARED_UEFIBASE_SRC_BITS64_UEFI_UEFI_H



#include <ngos/status.h>
#include <uefi/types.h>
#include <uefi/uefifileprotocol.h>
#include <uefi/uefisimpletextoutputinterface.h>
#include <uefi/uefisystemtable.h>
#include <uefibase/src/bits64/other/uefibootmemorymap.h>



class UEFI
{
public:
    static NgosStatus init(uefi_handle imageHandle, UefiSystemTable *systemTable); // TEST: NO

    static UefiStatus switchToTextMode(); // TEST: NO
    static UefiStatus clearScreen(); // TEST: NO
    static void print(char8 ch); // TEST: NO
    static void print(const char8 *str); // TEST: NO
    static void println(); // TEST: NO
    static void println(char8 ch); // TEST: NO
    static void println(const char8 *str); // TEST: NO
    static i64 printf(const char8 *format, ...); // TEST: NO

    static NgosStatus noMorePrint(); // TEST: NO
    static bool canPrint(); // TEST: NO

    static char16* parentDirectory(const char16 *path);

    static UefiFileProtocol* openVolume(uefi_handle handle); // TEST: NO

    static char16* devicePathToString(UefiDevicePath *path); // TEST: NO
    static UefiDevicePath* devicePathFromHandle(uefi_handle handle); // TEST: NO
    static UefiDevicePath* fileDevicePath(uefi_handle device, const char16 *fileName); // TEST: NO
    static UefiDevicePath* nextDevicePathNode(UefiDevicePath *path);
    static NgosStatus setDevicePathEndNode(UefiDevicePath *path);
    static bool isDevicePathEndType(UefiDevicePath *path);
    static u64 getDevicePathSize(UefiDevicePath *path);

    static UefiStatus createEvent(UefiEventType type, uefi_tpl notifyTpl, uefi_event_notify notifyFunction, void *notifyContext, uefi_event *event); // TEST: NO
    static UefiStatus setTimer(uefi_event event, UefiTimerDelay type, u64 triggerTime); // TEST: NO
    static UefiStatus waitForEvent(u64 numberOfEvents, uefi_event *event, u64 *index); // TEST: NO
    static UefiStatus closeEvent(uefi_event event); // TEST: NO
    static UefiStatus stall(u64 microseconds); // TEST: NO

    static UefiStatus handleProtocol(uefi_handle handle, Guid *protocol, void **interface); // TEST: NO
    static UefiStatus locateHandle(UefiLocateSearchType searchType, Guid *protocol, void *searchKey, u64 *bufferSize, uefi_handle *buffer); // TEST: NO
    static UefiStatus locateDevicePath(Guid *protocol, UefiDevicePath **devicePath, uefi_handle *device); // TEST: NO

    static UefiStatus allocatePool(UefiMemoryType poolType, u64 size, void **buffer); // TEST: NO
    static UefiStatus freePool(void *buffer); // TEST: NO

    static bool memoryMapHasHeadroom(u64 bufferSize, u64 memoryMapSize, u64 descriptorSize);
    static UefiStatus allocatePages(UefiAllocateType type, UefiMemoryType memoryType, u64 noPages, u64 *memory); // TEST: NO
    static UefiStatus getMemoryMap(u64 *memoryMapSize, UefiMemoryDescriptor *memoryMap, u64 *mapKey, u64 *descriptorSize, u32 *descriptorVersion); // TEST: NO
    static UefiStatus getMemoryMap(UefiBootMemoryMap *map); // TEST: NO
    static UefiStatus lowAlloc(u64 size, u64 align, void **address); // TEST: NO

    static UefiStatus loadImage(bool bootPolicy, uefi_handle parentImageHandle, UefiDevicePath *filePath, void *sourceBuffer, u64 sourceSize, uefi_handle *imageHandle); // TEST: NO
    static UefiStatus startImage(uefi_handle imageHandle, u64 *exitDataSize, char16 **exitData); // TEST: NO

    static UefiStatus resetSystem(UefiResetType resetType, UefiStatus resetStatus, u64 dataSize, char16 *resetData); // TEST: NO
    static UefiStatus exitBootServices(u64 mapKey); // TEST: NO

    static uefi_handle getImageHandle(); // TEST: NO
    static UefiSystemTable* getSystemTable(); // TEST: NO

private:
    static NgosStatus disableWatchdogTimer(); // TEST: NO
    static NgosStatus maximizeConsole(); // TEST: NO
    static NgosStatus disableCursor(); // TEST: NO

    static void print(char16 *ch); // TEST: NO

    static uefi_handle                    sImageHandle;
    static UefiSystemTable               *sSystemTable;
    static UefiSimpleTextOutputInterface *sTextOutput;
    static UefiBootServices              *sBootServices;
};



#endif // OS_SHARED_UEFIBASE_SRC_BITS64_UEFI_UEFI_H
