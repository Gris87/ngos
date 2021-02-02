#ifndef COM_NGOS_SHARED_UEFIBASE_UEFI_UEFI_H
#define COM_NGOS_SHARED_UEFIBASE_UEFI_UEFI_H



#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/uefi/config/uefismbios3configurationtable.h>
#include <com/ngos/shared/common/uefi/config/uefismbiosconfigurationtable.h>
#include <com/ngos/shared/common/uefi/types.h>
#include <com/ngos/shared/common/uefi/ueficonsolecontrolscreenmode.h>
#include <com/ngos/shared/common/uefi/uefifileprotocol.h>
#include <com/ngos/shared/common/uefi/uefisimpletextoutputinterface.h>
#include <com/ngos/shared/common/uefi/uefisystemtable.h>
#include <com/ngos/shared/uefibase/other/uefibootmemorymap.h>



class UEFI
{
public:
    static NgosStatus init(uefi_handle imageHandle, UefiSystemTable *systemTable); // TEST: NO

    static NgosStatus switchToGraphicsMode(); // TEST: NO
    static NgosStatus switchToTextMode(); // TEST: NO
    static UefiStatus clearScreen(); // TEST: NO
    static void print(char8 ch); // TEST: NO
    static void print(const char8 *str); // TEST: NO
    static void println(); // TEST: NO
    static void println(char8 ch); // TEST: NO
    static void println(const char8 *str); // TEST: NO
    static bad_int64 printf(const char8 *format, ...); // TEST: NO

    static NgosStatus noMorePrint(); // TEST: NO
    static bool canPrint(); // TEST: NO

    static UefiStatus getVariable(const char16 *variableName, Guid *vendorGuid, bad_uint64 *dataSize, bad_uint8 **data); // TEST: NO
    static UefiStatus getVariable(const char16 *variableName, Guid *vendorGuid, UefiVariableAttributeFlags *attributes, bad_uint64 *dataSize, bad_uint8 *data); // TEST: NO
    static UefiStatus setVariable(const char16 *variableName, Guid *vendorGuid, bad_uint64 dataSize, bad_uint8 *data); // TEST: NO
    static UefiStatus setVariable(const char16 *variableName, Guid *vendorGuid, const UefiVariableAttributeFlags &attributes, bad_uint64 dataSize, bad_uint8 *data); // TEST: NO

    static UefiFileProtocol* openVolume(uefi_handle handle); // TEST: NO
    static bool fileExists(UefiFileProtocol *parentDirectory, const char16 *path); // TEST: NO
    static char16* parentDirectory(const char16 *path);

    static char16* devicePathToString(UefiDevicePath *path); // TEST: NO
    static UefiDevicePath* devicePathFromHandle(uefi_handle handle); // TEST: NO
    static UefiDevicePath* fileDevicePath(uefi_handle device, const char16 *fileName); // TEST: NO
    static UefiDevicePath* nextDevicePathNode(UefiDevicePath *path);
    static NgosStatus setDevicePathEndNode(UefiDevicePath *path);
    static bool isDevicePathEndType(UefiDevicePath *path);
    static bad_uint64 getDevicePathSize(UefiDevicePath *path);

    static UefiStatus getTime(UefiTime *time, UefiTimeCapabilities *capabilities); // TEST: NO
    static NgosStatus currentTimestampToString(char8 *buffer); // TEST: NO

    static UefiStatus createEvent(UefiEventType type, UefiTpl notifyTpl, uefi_event_notify notifyFunction, void *notifyContext, uefi_event *event); // TEST: NO
    static UefiStatus setTimer(uefi_event event, UefiTimerDelay type, bad_uint64 triggerTime); // TEST: NO
    static UefiStatus waitForEvent(bad_uint64 numberOfEvents, uefi_event *event, bad_uint64 *index); // TEST: NO
    static UefiStatus closeEvent(uefi_event event); // TEST: NO
    static UefiStatus stall(bad_uint64 microseconds); // TEST: NO

    static UefiStatus handleProtocol(uefi_handle handle, Guid *protocol, void **interface); // TEST: NO
    static UefiStatus locateProtocol(Guid *protocol, void *registration, void **interface); // TEST: NO
    static UefiStatus locateHandle(UefiLocateSearchType searchType, Guid *protocol, void *searchKey, bad_uint64 *bufferSize, uefi_handle *buffer); // TEST: NO
    static UefiStatus locateDevicePath(Guid *protocol, UefiDevicePath **devicePath, uefi_handle *device); // TEST: NO

    static UefiStatus allocatePool(UefiMemoryType poolType, bad_uint64 size, void **buffer); // TEST: NO
    static UefiStatus freePool(void *buffer); // TEST: NO

    static bool memoryMapHasHeadroom(bad_uint64 bufferSize, bad_uint64 memoryMapSize, bad_uint64 descriptorSize);
    static UefiStatus allocatePages(UefiAllocateType type, UefiMemoryType memoryType, bad_uint64 noPages, bad_uint64 *memory); // TEST: NO
    static UefiStatus getMemoryMap(bad_uint64 *memoryMapSize, UefiMemoryDescriptor *memoryMap, bad_uint64 *mapKey, bad_uint64 *descriptorSize, bad_uint32 *descriptorVersion); // TEST: NO
    static UefiStatus getMemoryMap(UefiBootMemoryMap *map); // TEST: NO
    static UefiStatus lowAlloc(bad_uint64 size, bad_uint64 align, void **address); // TEST: NO

    static UefiStatus loadImage(bool bootPolicy, uefi_handle parentImageHandle, UefiDevicePath *filePath, void *sourceBuffer, bad_uint64 sourceSize, uefi_handle *imageHandle); // TEST: NO
    static UefiStatus startImage(uefi_handle imageHandle, bad_uint64 *exitDataSize, char16 **exitData); // TEST: NO

    static UefiStatus resetSystem(UefiResetType resetType, UefiStatus resetStatus, bad_uint64 dataSize, char16 *resetData); // TEST: NO
    static UefiStatus exitBootServices(bad_uint64 mapKey); // TEST: NO

    static UefiSmbios3ConfigurationTable* getSmbios3Config(); // TEST: NO
    static UefiSmbiosConfigurationTable* getSmbiosConfig(); // TEST: NO

    static uefi_handle getImageHandle(); // TEST: NO
    static UefiSystemTable* getSystemTable(); // TEST: NO

private:
    static NgosStatus disableWatchdogTimer(); // TEST: NO
    static NgosStatus maximizeConsole(UefiSimpleTextOutputInterface *textOutput); // TEST: NO
    static NgosStatus disableCursor(); // TEST: NO
    static NgosStatus switchConsoleControlScreenMode(UefiConsoleControlScreenMode mode); // TEST: NO

    static void print(char16 *ch); // TEST: NO

    static uefi_handle                    sImageHandle;
    static UefiSystemTable               *sSystemTable;
    static UefiSimpleTextOutputInterface *sTextOutput;
    static UefiBootServices              *sBootServices;
};



#endif // COM_NGOS_SHARED_UEFIBASE_UEFI_UEFI_H
