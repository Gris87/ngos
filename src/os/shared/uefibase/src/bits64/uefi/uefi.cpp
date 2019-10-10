#include "uefi.h"

#include <common/src/bits64/memory/memory.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/utils.h>
#include <page/macros.h>
#include <uefi/ueficonsolecontrolprotocol.h>
#include <uefi/uefidevicepathtotextprotocol.h>
#include <uefi/uefifilepath.h>
#include <uefi/uefisimplefilesystemprotocol.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



#define UEFI_MAXIMUM_VARIABLE_SIZE            2048
#define UEFI_MEMORY_MAP_NUMBER_OF_SLACK_SLOTS 8



uefi_handle                    UEFI::sImageHandle;
UefiSystemTable               *UEFI::sSystemTable;
UefiSimpleTextOutputInterface *UEFI::sTextOutput;
UefiBootServices              *UEFI::sBootServices;



NgosStatus UEFI::init(uefi_handle imageHandle, UefiSystemTable *systemTable)
{
    // We can't output at the moment
    // UEFI_LT((" | imageHandle = 0x%p, systemTable = 0x%p", imageHandle, systemTable)); // Commented to avoid error because sTextOutput is null



    sImageHandle  = imageHandle;
    sSystemTable  = systemTable;
    sTextOutput   = sSystemTable->stdout;
    sBootServices = sSystemTable->bootServices;



    UEFI_LT((" | imageHandle = 0x%p, systemTable = 0x%p", imageHandle, systemTable)); // We can output now

    UEFI_ASSERT(sImageHandle,  "sImageHandle is null",  NgosStatus::ASSERTION);
    UEFI_ASSERT(sSystemTable,  "sSystemTable is null",  NgosStatus::ASSERTION);
    UEFI_ASSERT(sTextOutput,   "sTextOutput is null",   NgosStatus::ASSERTION);
    UEFI_ASSERT(sBootServices, "sBootServices is null", NgosStatus::ASSERTION);

    UEFI_ASSERT(sSystemTable->runtimeServices->header.signature == UEFI_RUNTIME_SERVICES_SIGNATURE, "Runtime services signature is invalid", NgosStatus::ASSERTION);
    UEFI_ASSERT(sSystemTable->bootServices->header.signature    == UEFI_BOOT_SERVICES_SIGNATURE,    "Boot services signature is invalid",    NgosStatus::ASSERTION);



    UEFI_ASSERT_EXECUTION(disableWatchdogTimer(),       NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(maximizeConsole(sTextOutput), NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(disableCursor(),              NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus UEFI::switchToGraphicsMode()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(switchConsoleControlScreenMode(UefiConsoleControlScreenMode::GRAPHICS), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus UEFI::switchToTextMode()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(switchConsoleControlScreenMode(UefiConsoleControlScreenMode::TEXT),                      NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(sSystemTable->stdout->setMode(sSystemTable->stdout, 0), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);
    UEFI_ASSERT_EXECUTION(maximizeConsole(sSystemTable->stdout),                                                   NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

UefiStatus UEFI::clearScreen()
{
    UEFI_LT((""));

    UEFI_ASSERT(sTextOutput, "sTextOutput is null", UefiStatus::ABORTED);



    return sTextOutput->clearScreen(sTextOutput);
}

void UEFI::print(char8 ch)
{
    // UEFI_LT((" | ch = %c", ch)); // Commented to avoid bad looking logs



    char16 buffer[2] = { (char16)ch, 0 };
    print(buffer);
}

void UEFI::print(const char8 *str)
{
    // UEFI_LT((" | str = 0x%p", str)); // Commented to avoid infinite loop

    UEFI_ASSERT(str, "str is null");



    char16  buffer[1024];
    char16 *cur = &buffer[0];

    while (*str)
    {
        if (*str == '\n')
        {
            *cur = u'\r';
            ++cur;
        }

        *cur = *str;
        ++cur;
        ++str;
    }

    UEFI_TEST_ASSERT((u64)(cur - buffer) < sizeof(buffer));
    *cur = 0;



    print(buffer);
}

void UEFI::println()
{
    // UEFI_LT(("")); // Commented to avoid bad looking logs



    char16 nl[3] = { u'\r', u'\n', 0 };
    print(nl);
}

void UEFI::println(char8 ch)
{
    // UEFI_LT((" | ch = %c", ch)); // Commented to avoid bad looking logs



    char16 buffer[4] = { (char16)ch, u'\r', u'\n', 0 };
    print(buffer);
}

void UEFI::println(const char8 *str)
{
    // UEFI_LT((" | str = 0x%p", str)); // Commented to avoid infinite loop

    UEFI_ASSERT(str, "str is null");



    print(str);

    char16 nl[3] = { u'\r', u'\n', 0 };
    print(nl);
}

i64 UEFI::printf(const char8 *format, ...)
{
    // UEFI_LT((" | format = 0x%p", format)); // Commented to avoid infinite loop

    UEFI_ASSERT(format, "format is null", 0);



    va_list args;

    va_start(args, format);
    i64 res = vsprintf(printfBuffer, format, args);
    va_end(args);

    UEFI_TEST_ASSERT(res < (i64)sizeof(printfBuffer), 0);



    println(printfBuffer);



    return res;
}

NgosStatus UEFI::noMorePrint()
{
    UEFI_LT((""));

    UEFI_ASSERT(sTextOutput, "sTextOutput is null", NgosStatus::ASSERTION);



    sTextOutput = 0;



    return NgosStatus::OK;
}

bool UEFI::canPrint()
{
    // UEFI_LT(("")); // Commented to avoid infinite loop



    return sTextOutput;
}

UefiStatus UEFI::getVariable(const char16 *variableName, Guid *vendorGuid, void **data)
{
    u64   size = UEFI_MAXIMUM_VARIABLE_SIZE;
    void *res;

    if (allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&res) != UefiStatus::SUCCESS)
    {
        UEFI_LE(("Failed to allocate pool(%u) for variable", size));

        return UefiStatus::OUT_OF_RESOURCES;
    }

    UEFI_LVV(("Allocated pool(0x%p, %u) for variable", res, size));



    if (getVariable(variableName, vendorGuid, nullptr, &size, res) != UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Failed to load variable %ls from NVRAM", variableName));

        if (freePool(res) == UefiStatus::SUCCESS)
        {
            UEFI_LVV(("Released pool(0x%p) for variable", res));
        }
        else
        {
            UEFI_LE(("Failed to release pool(0x%p) for variable", res));
        }

        return UefiStatus::ABORTED;
    }

    UEFI_LVV(("Loaded variable %ls from NVRAM", variableName));



    *data = res;



    return UefiStatus::SUCCESS;
}

UefiStatus UEFI::getVariable(const char16 *variableName, Guid *vendorGuid, uefi_variable_attribute_flags *attributes, u64 *dataSize, void *data)
{
    UEFI_LT((" | variableName = 0x%p, vendorGuid = 0x%p, attributes = 0x%p, dataSize = 0x%p, data = 0x%p", variableName, vendorGuid, attributes, dataSize, data));

    UEFI_ASSERT(variableName,                            "variableName is null", UefiStatus::ABORTED);
    UEFI_ASSERT(vendorGuid,                              "vendorGuid is null",   UefiStatus::ABORTED);
    UEFI_ASSERT(dataSize,                                "dataSize is null",     UefiStatus::ABORTED);
    UEFI_ASSERT(*dataSize <= UEFI_MAXIMUM_VARIABLE_SIZE, "dataSize is invalid",  UefiStatus::ABORTED);
    UEFI_ASSERT(data,                                    "data is null",         UefiStatus::ABORTED);



    return sSystemTable->runtimeServices->getVariable(variableName, vendorGuid, attributes, dataSize, data);
}

UefiStatus UEFI::setVariable(const char16 *variableName, Guid *vendorGuid, u64 dataSize, void *data)
{
    UEFI_LT((" | variableName = 0x%p, vendorGuid = 0x%p, dataSize = %u, data = 0x%p", variableName, vendorGuid, dataSize, data));

    UEFI_ASSERT(variableName, "variableName is null", UefiStatus::ABORTED);
    UEFI_ASSERT(vendorGuid,   "vendorGuid is null",   UefiStatus::ABORTED);
    UEFI_ASSERT(dataSize > 0, "dataSize is zero",     UefiStatus::ABORTED);
    UEFI_ASSERT(data,         "data is null",         UefiStatus::ABORTED);



    return setVariable(variableName,
                        vendorGuid,
                        FLAGS(UefiVariableAttributeFlag::BOOTSERVICE_ACCESS, UefiVariableAttributeFlag::RUNTIME_ACCESS, UefiVariableAttributeFlag::NON_VOLATILE),
                        dataSize,
                        data);
}

UefiStatus UEFI::setVariable(const char16 *variableName, Guid *vendorGuid, uefi_variable_attribute_flags attributes, u64 dataSize, void *data)
{
    UEFI_LT((" | variableName = 0x%p, vendorGuid = 0x%p, attributes = %u, dataSize = %u, data = 0x%p", variableName, vendorGuid, attributes, dataSize, data));

    UEFI_ASSERT(variableName,                           "variableName is null", UefiStatus::ABORTED);
    UEFI_ASSERT(vendorGuid,                             "vendorGuid is null",   UefiStatus::ABORTED);
    UEFI_ASSERT(dataSize > 0,                           "dataSize is zero",     UefiStatus::ABORTED);
    UEFI_ASSERT(dataSize <= UEFI_MAXIMUM_VARIABLE_SIZE, "dataSize is invalid",  UefiStatus::ABORTED);
    UEFI_ASSERT(data,                                   "data is null",         UefiStatus::ABORTED);



    return sSystemTable->runtimeServices->setVariable(variableName, vendorGuid, attributes, dataSize, data);
}

UefiFileProtocol* UEFI::openVolume(uefi_handle handle)
{
    UEFI_LT((" | handle = 0x%p", handle));

    UEFI_ASSERT(handle, "handle is null", 0);



    Guid                          protocol = UEFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID;
    UefiSimpleFileSystemProtocol *fs;

    if (handleProtocol(handle, &protocol, (void **)&fs) != UefiStatus::SUCCESS)
    {
        return 0;
    }

    UEFI_LVV(("Handled(0x%p) protocol(0x%p) for UEFI_SIMPLE_FILE_SYSTEM_PROTOCOL", handle, fs));



    UefiFileProtocol *res;

    if (fs->openVolume(fs, &res) != UefiStatus::SUCCESS)
    {
        return 0;
    }

    UEFI_LVV(("Openned volume(0x%p) for handle(0x%p)", res, handle));



    return res;
}

bool UEFI::fileExists(UefiFileProtocol *parentDirectory, const char16 *path)
{
    UEFI_LT((" | parentDirectory = 0x%p, path = 0x%p", parentDirectory, path));

    UEFI_ASSERT(parentDirectory, "parentDirectory is null", false);
    UEFI_ASSERT(path,            "path is null",            false);



    UefiFileProtocol *tempFile;

    if (parentDirectory->open(parentDirectory, &tempFile, path, FLAGS(UefiFileModeFlag::READ), FLAG(UefiFileAttributeFlag::NONE)) == UefiStatus::SUCCESS)
    {
        UEFI_ASSERT_EXECUTION(tempFile->close(tempFile), UefiStatus, UefiStatus::SUCCESS, false);

        return true;
    }



    return false;
}

char16* UEFI::parentDirectory(const char16 *path)
{
    UEFI_LT((" | path = %ls", path));

    UEFI_ASSERT(path, "path is null", 0);



    u64           size = 0;
    const char16 *str  = path;

    while (*str)
    {
        if (*str == u'\\')
        {
            size = (u64)str;
        }

        ++str;
    }

    UEFI_TEST_ASSERT(size > 0, 0);

    size = size - (u64)path + sizeof(char16);



    char16 *res;

    if (allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&res) != UefiStatus::SUCCESS)
    {
        UEFI_LE(("Failed to allocate pool(%u) for string", size));

        return 0;
    }

    UEFI_LVV(("Allocated pool(0x%p, %u) for string", res, size));



    memcpy(res, path, size - sizeof(char16));
    res[size / sizeof(char16) - 1] = 0;



    return res;
}

char16* UEFI::devicePathToString(UefiDevicePath *path)
{
    UEFI_LT((" | path = 0x%p", path));

    UEFI_ASSERT(path, "path is null", 0);



    Guid                          protocol                 = UEFI_DEVICE_PATH_TO_TEXT_PROTOCOL_GUID;
    UefiDevicePathToTextProtocol *devicePathToTextProtocol = 0;

    if (locateProtocol(&protocol, 0, (void **)&devicePathToTextProtocol) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to locate protocol for UEFI_DEVICE_PATH_TO_TEXT_PROTOCOL"));

        return 0;
    }

    UEFI_LVV(("Located(0x%p) protocol for UEFI_DEVICE_PATH_TO_TEXT_PROTOCOL", devicePathToTextProtocol));



    char16 *res = devicePathToTextProtocol->convertDevicePathToText(path, false, true);

    if (!res) // pathStr == 0
    {
        UEFI_LE(("Failed to allocate pool(0x%p) for string", res));

        return 0;
    }

    UEFI_LVV(("Allocated pool(0x%p) for string", res));



    return res;
}

UefiDevicePath* UEFI::devicePathFromHandle(uefi_handle handle)
{
    UEFI_LT((" | handle = 0x%p", handle));

    UEFI_ASSERT(handle, "handle is null", 0);



    Guid            protocol = UEFI_DEVICE_PATH_PROTOCOL_GUID;
    UefiDevicePath *res;

    if (handleProtocol(handle, &protocol, (void **)&res) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to handle(0x%p) protocol for UEFI_DEVICE_PATH_PROTOCOL", handle));

        return 0;
    }

    UEFI_LVV(("Handled(0x%p) protocol(0x%p) for UEFI_DEVICE_PATH_PROTOCOL", handle, res));



    return res;
}

UefiDevicePath* UEFI::fileDevicePath(uefi_handle device, const char16 *fileName)
{
    UEFI_LT((" | device = 0x%p, fileName = 0x%p", device, fileName));

    UEFI_ASSERT(device,   "device is null",   0);
    UEFI_ASSERT(fileName, "fileName is null", 0);



    UefiDevicePath *parentDevicePath = devicePathFromHandle(device);
    UEFI_TEST_ASSERT(parentDevicePath != 0, 0);

    u64 parentDevicePathSize = getDevicePathSize(parentDevicePath);
    UEFI_TEST_ASSERT(parentDevicePathSize > 0, 0);



    u64 fileNameSize = strlen(fileName) + 1;
    u64 filePathSize = sizeof(UefiFilePath) + fileNameSize * sizeof(char16);
    u64 size         = parentDevicePathSize + filePathSize + sizeof(UefiDevicePath);



    UefiDevicePath *res;

    if (allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&res) != UefiStatus::SUCCESS)
    {
        UEFI_LE(("Failed to allocate pool(%u) for device path", size));

        return 0;
    }

    UEFI_LVV(("Allocated pool(0x%p, %u) for device path", res, size));



    memcpy(res, parentDevicePath, parentDevicePathSize);



    UefiFilePath *filePath = (UefiFilePath *)((u64)res + parentDevicePathSize);

    filePath->header.type    = UefiDevicePathType::MEDIA_DEVICE_PATH;
    filePath->header.subType = UefiDevicePathSubType::MEDIA_FILEPATH_DP;
    filePath->header.length  = filePathSize;

    for (i64 i = 0; i < (i64)fileNameSize; ++i)
    {
        filePath->pathName[i] = fileName[i];
    }



    UEFI_ASSERT_EXECUTION(setDevicePathEndNode((UefiDevicePath *)((u64)res + size - sizeof(UefiDevicePath))), 0);



    return res;
}

UefiDevicePath* UEFI::nextDevicePathNode(UefiDevicePath *path)
{
    UEFI_LT((" | path = 0x%p", path));

    UEFI_ASSERT(path, "path is null", 0);



    return (UefiDevicePath *)((u64)path + path->length);
}

NgosStatus UEFI::setDevicePathEndNode(UefiDevicePath *path)
{
    UEFI_LT((" | path = 0x%p", path));

    UEFI_ASSERT(path, "path is null", NgosStatus::ASSERTION);



    path->type    = UefiDevicePathType::END_DEVICE_PATH_TYPE;
    path->subType = UefiDevicePathSubType::END_ENTIRE_DEVICE_PATH_SUBTYPE;
    path->length  = sizeof(UefiDevicePath);



    return NgosStatus::OK;
}

bool UEFI::isDevicePathEndType(UefiDevicePath *path)
{
    UEFI_LT((" | path = 0x%p", path));

    UEFI_ASSERT(path, "path is null", false);



    return path->type == UefiDevicePathType::END_DEVICE_PATH_TYPE;
}

u64 UEFI::getDevicePathSize(UefiDevicePath *path)
{
    UEFI_LT((" | path = 0x%p", path));

    UEFI_ASSERT(path, "path is null", 0);



    UefiDevicePath *currentDevicePath = path;

    while (!isDevicePathEndType(currentDevicePath))
    {
        currentDevicePath = nextDevicePathNode(currentDevicePath);
    }



    return (u64)currentDevicePath - (u64)path;
}

UefiStatus UEFI::createEvent(UefiEventType type, uefi_tpl notifyTpl, uefi_event_notify notifyFunction, void *notifyContext, uefi_event *event)
{
    UEFI_LT((" | type = %u, notifyTpl = %u, notifyFunction = 0x%p, notifyContext = 0x%p, event = 0x%p", type, notifyTpl, notifyFunction, notifyContext, event));

    UEFI_ASSERT(event, "event is null", UefiStatus::ABORTED);



    return sBootServices->createEvent(type, notifyTpl, notifyFunction, notifyContext, event);
}

UefiStatus UEFI::setTimer(uefi_event event, UefiTimerDelay type, u64 triggerTime)
{
    UEFI_LT((" | event = 0x%p, type = %d, triggerTime = %u", event, type, triggerTime));

    UEFI_ASSERT(event, "event is null", UefiStatus::ABORTED);



    return sBootServices->setTimer(event, type, triggerTime);
}

UefiStatus UEFI::waitForEvent(u64 numberOfEvents, uefi_event *event, u64 *index)
{
    UEFI_LT((" | numberOfEvents = %u, event = 0x%p, index = 0x%p", numberOfEvents, event, index));

    UEFI_ASSERT(numberOfEvents > 0, "numberOfEvents is zero", UefiStatus::ABORTED);
    UEFI_ASSERT(event,              "event is null",          UefiStatus::ABORTED);
    UEFI_ASSERT(index,              "index is null",          UefiStatus::ABORTED);



    return sBootServices->waitForEvent(numberOfEvents, event, index);
}

UefiStatus UEFI::closeEvent(uefi_event event)
{
    UEFI_LT((" | event = 0x%p", event));

    UEFI_ASSERT(event, "event is null", UefiStatus::ABORTED);



    return sBootServices->closeEvent(event);
}

UefiStatus UEFI::stall(u64 microseconds)
{
    UEFI_LT((" | microseconds = %u", microseconds));

    UEFI_ASSERT(microseconds > 0, "microseconds is zero", UefiStatus::ABORTED);



    return sBootServices->stall(microseconds);
}

UefiStatus UEFI::handleProtocol(uefi_handle handle, Guid *protocol, void **interface)
{
    UEFI_LT((" | handle = 0x%p, protocol = 0x%p, interface = 0x%p", handle, protocol, interface));

    UEFI_ASSERT(handle,    "handle is null",    UefiStatus::ABORTED);
    UEFI_ASSERT(protocol,  "protocol is null",  UefiStatus::ABORTED);
    UEFI_ASSERT(interface, "interface is null", UefiStatus::ABORTED);



    return sBootServices->handleProtocol(handle, protocol, interface);
}

UefiStatus UEFI::locateProtocol(Guid *protocol, void *registration, void **interface)
{
    UEFI_LT((" | protocol = 0x%p, registration = 0x%p, interface = 0x%p", protocol, registration, interface));

    UEFI_ASSERT(protocol,     "protocol is null",     UefiStatus::ABORTED);
    UEFI_ASSERT(interface,    "interface is null",    UefiStatus::ABORTED);



    return sBootServices->locateProtocol(protocol, registration, interface);
}

UefiStatus UEFI::locateHandle(UefiLocateSearchType searchType, Guid *protocol, void *searchKey, u64 *bufferSize, uefi_handle *buffer)
{
    UEFI_LT((" | searchType = %d, protocol = 0x%p, searchKey = 0x%p, bufferSize = 0x%p, buffer = 0x%p", searchType, protocol, searchKey, bufferSize, buffer));

    UEFI_ASSERT((searchType == UefiLocateSearchType::BY_PROTOCOL
                &&
                protocol)
                ||
                (searchType == UefiLocateSearchType::BY_REGISTER_NOTIFY
                &&
                searchKey)
                ||
                searchType == UefiLocateSearchType::ALL_HANDLES, "Invalid arguments",  UefiStatus::ABORTED);

    UEFI_ASSERT(bufferSize,                                     "bufferSize is null", UefiStatus::ABORTED);
    UEFI_ASSERT(buffer || (bufferSize && *bufferSize == 0),     "buffer is null",     UefiStatus::ABORTED);



    return sBootServices->locateHandle(searchType, protocol, searchKey, bufferSize, buffer);
}

UefiStatus UEFI::locateDevicePath(Guid *protocol, UefiDevicePath **devicePath, uefi_handle *device)
{
    UEFI_LT((" | protocol = 0x%p, devicePath = 0x%p, device = 0x%p", protocol, devicePath, device));

    UEFI_ASSERT(protocol,   "protocol is null",   UefiStatus::ABORTED);
    UEFI_ASSERT(devicePath, "devicePath is null", UefiStatus::ABORTED);
    UEFI_ASSERT(device,     "device is null",     UefiStatus::ABORTED);



    return sBootServices->locateDevicePath(protocol, devicePath, device);
}

UefiStatus UEFI::allocatePool(UefiMemoryType poolType, u64 size, void **buffer)
{
    UEFI_LT((" | poolType = %d, size = %u, buffer = 0x%p", poolType, size, buffer));

    UEFI_ASSERT(size > 0, "size is zero",   UefiStatus::ABORTED);
    UEFI_ASSERT(buffer,   "buffer is null", UefiStatus::ABORTED);



    return sBootServices->allocatePool(poolType, size, buffer);
}

UefiStatus UEFI::freePool(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));

    UEFI_ASSERT(buffer, "buffer is null", UefiStatus::ABORTED);



    return sBootServices->freePool(buffer);
}

bool UEFI::memoryMapHasHeadroom(u64 bufferSize, u64 memoryMapSize, u64 descriptorSize)
{
    UEFI_LT((" | bufferSize = %u, memoryMapSize = %u, descriptorSize = %u", bufferSize, memoryMapSize, descriptorSize));

    UEFI_ASSERT(bufferSize > 0,     "bufferSize is zero",     false);
    UEFI_ASSERT(memoryMapSize > 0,  "memoryMapSize is zero",  false);
    UEFI_ASSERT(descriptorSize > 0, "descriptorSize is zero", false);



    i64 slack = bufferSize - memoryMapSize;

    return slack / (i64)descriptorSize >= UEFI_MEMORY_MAP_NUMBER_OF_SLACK_SLOTS;
}

UefiStatus UEFI::allocatePages(UefiAllocateType type, UefiMemoryType memoryType, u64 noPages, u64 *memory)
{
    UEFI_LT((" | type = %d, memoryType = %d, noPages = %u, memory = 0x%p", type, memoryType, noPages, memory));

    UEFI_ASSERT(noPages > 0, "noPages is zero", UefiStatus::ABORTED);
    UEFI_ASSERT(memory,      "memory is null",  UefiStatus::ABORTED);



    return sBootServices->allocatePages(type, memoryType, noPages, memory);
}

UefiStatus UEFI::getMemoryMap(u64 *memoryMapSize, UefiMemoryDescriptor *memoryMap, u64 *mapKey, u64 *descriptorSize, u32 *descriptorVersion)
{
    UEFI_LT((" | memoryMapSize = 0x%p, memoryMap = 0x%p, mapKey = 0x%p, descriptorSize = 0x%p, descriptorVersion = 0x%p", memoryMapSize, memoryMap, mapKey, descriptorSize, descriptorVersion));

    UEFI_ASSERT(memoryMapSize,     "memoryMapSize is null",     UefiStatus::ABORTED);
    UEFI_ASSERT(memoryMap,         "memoryMap is null",         UefiStatus::ABORTED);
    UEFI_ASSERT(mapKey,            "mapKey is null",            UefiStatus::ABORTED);
    UEFI_ASSERT(descriptorSize,    "descriptorSize is null",    UefiStatus::ABORTED);
    UEFI_ASSERT(descriptorVersion, "descriptorVersion is null", UefiStatus::ABORTED);



    return sBootServices->getMemoryMap(memoryMapSize, memoryMap, mapKey, descriptorSize, descriptorVersion);
}

UefiStatus UEFI::getMemoryMap(UefiBootMemoryMap *map)
{
    UEFI_LT((" | map = 0x%p", map));

    UEFI_ASSERT(map,                 "map is null",                 UefiStatus::ABORTED);
    UEFI_ASSERT(map->memoryMapSize,  "map->memoryMapSize is null",  UefiStatus::ABORTED);
    UEFI_ASSERT(map->descriptorSize, "map->descriptorSize is null", UefiStatus::ABORTED);
    UEFI_ASSERT(map->bufferSize,     "map->bufferSize is null",     UefiStatus::ABORTED);



    UefiMemoryDescriptor *memoryDescriptor = 0;

    *map->descriptorSize = sizeof(UefiMemoryDescriptor);
    *map->memoryMapSize  = *map->descriptorSize << 6; // "<< 6" == "* 64"
    *map->bufferSize     = *map->memoryMapSize;



    do
    {
        if (allocatePool(UefiMemoryType::LOADER_DATA, *map->memoryMapSize, (void **)&memoryDescriptor) != UefiStatus::SUCCESS)
        {
            UEFI_LF(("Failed to allocate pool(%u) for memory descriptor", *map->memoryMapSize));

            return UefiStatus::ABORTED;
        }

        UEFI_LVV(("Allocated pool(0x%p, %u) for memory descriptor", memoryDescriptor, *map->memoryMapSize));



        *map->descriptorSize = 0;

        u64 mapKey            = 0;
        u32 descriptorVersion = 0;



        UefiStatus status = getMemoryMap(map->memoryMapSize, memoryDescriptor, &mapKey, map->descriptorSize, &descriptorVersion);

        if (status == UefiStatus::BUFFER_TOO_SMALL || !memoryMapHasHeadroom(*map->bufferSize, *map->memoryMapSize, *map->descriptorSize))
        {
            UEFI_LW(("Buffer for memory descriptor is too small. Trying to allocate bigger buffer"));



            if (freePool(memoryDescriptor) == UefiStatus::SUCCESS)
            {
                UEFI_LVV(("Released pool(0x%p) for memory descriptor", memoryDescriptor));
            }
            else
            {
                UEFI_LE(("Failed to release pool(0x%p) for memory descriptor", memoryDescriptor));
            }



            *map->memoryMapSize += *map->descriptorSize * UEFI_MEMORY_MAP_NUMBER_OF_SLACK_SLOTS;
            *map->bufferSize    =  *map->memoryMapSize;



            continue;
        }



        if (status != UefiStatus::SUCCESS)
        {
            UEFI_LF(("Failed to get memory map"));



            if (freePool(memoryDescriptor) == UefiStatus::SUCCESS)
            {
                UEFI_LVV(("Released pool(0x%p) for memory descriptor", memoryDescriptor));
            }
            else
            {
                UEFI_LE(("Failed to release pool(0x%p) for memory descriptor", memoryDescriptor));
            }



            return UefiStatus::ABORTED;
        }

        UEFI_LVV(("Found memory map"));

        UEFI_LVVV(("mapKey            = %u", mapKey));
        UEFI_LVVV(("descriptorVersion = %u", descriptorVersion));



        if (map->mapKey)
        {
            *map->mapKey = mapKey;
        }

        if (map->descriptorVersion)
        {
            *map->descriptorVersion = descriptorVersion;
        }

        *map->memoryMap = memoryDescriptor;



        return UefiStatus::SUCCESS;
    } while(true);
}

UefiStatus UEFI::lowAlloc(u64 size, u64 align, void **address)
{
    UEFI_LT((" | size = %u, align = %u, address = 0x%p", size, align, address));

    UEFI_ASSERT(size > 0,             "size is zero",            UefiStatus::ABORTED);
    UEFI_ASSERT(align > 0,            "align is zero",           UefiStatus::ABORTED);
    UEFI_ASSERT(IS_POWER_OF_2(align), "align is not power of 2", UefiStatus::ABORTED);
    UEFI_ASSERT(address,              "address is null",         UefiStatus::ABORTED);



    UefiMemoryDescriptor *memoryMap      = 0;
    u64                   memoryMapSize  = 0;
    u64                   descriptorSize = 0;
    u64                   bufferSize     = 0;



    UefiBootMemoryMap bootMemoryMap;

    bootMemoryMap.memoryMap         = &memoryMap;
    bootMemoryMap.memoryMapSize     = &memoryMapSize;
    bootMemoryMap.descriptorSize    = &descriptorSize;
    bootMemoryMap.descriptorVersion = 0;
    bootMemoryMap.mapKey            = 0;
    bootMemoryMap.bufferSize        = &bufferSize;



    if (getMemoryMap(&bootMemoryMap) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to get memory map"));

        return UefiStatus::ABORTED;
    }

    // UEFI_LVV(("Found memory map")); // Commented to avoid log duplication



    UEFI_LVVV(("bootMemoryMap parameters:"));
    UEFI_LVVV(("-------------------------------------"));

    UEFI_LVVV(("memoryMap      = 0x%p", memoryMap));
    UEFI_LVVV(("memoryMapSize  = %u",   memoryMapSize));
    UEFI_LVVV(("descriptorSize = %u",   descriptorSize));
    UEFI_LVVV(("bufferSize     = %u",   bufferSize));

    UEFI_LVVV(("-------------------------------------"));



    if (align < PAGE_SIZE)
    {
        UEFI_LVVV(("align value increased from %u to %u", align, PAGE_SIZE));

        align = PAGE_SIZE;
    }



    size = ROUND_UP(size, PAGE_SIZE);

    u64 numberOfPages = size / PAGE_SIZE;



    UEFI_LVVV(("size          = %u", size));
    UEFI_LVVV(("numberOfPages = %u", numberOfPages));



    *address = 0;



    i64 count = memoryMapSize / descriptorSize;
    UEFI_LVVV(("count = %d", count));

    for (i64 i = 0; i < count; ++i)
    {
        UefiMemoryDescriptor *memoryDescriptor = (UefiMemoryDescriptor *)((u64)memoryMap + (i * descriptorSize));
        UEFI_LVV(("Handling memory descriptor #%d at address 0x%p", i, memoryDescriptor));

        UEFI_TEST_ASSERT(memoryDescriptor, UefiStatus::ABORTED);



        UEFI_LVVV(("type          = %u (%s)",  memoryDescriptor->type, uefiMemoryTypeToString(memoryDescriptor->type)));
        UEFI_LVVV(("physicalStart = 0x%p",     memoryDescriptor->physicalStart));
        UEFI_LVVV(("virtualStart  = 0x%p",     memoryDescriptor->virtualStart));
        UEFI_LVVV(("numberOfPages = %u",       memoryDescriptor->numberOfPages));
        UEFI_LVVV(("attribute     = 0x%016lX", memoryDescriptor->attribute));



        if (memoryDescriptor->type != UefiMemoryType::CONVENTIONAL_MEMORY)
        {
            UEFI_LVV(("Skipped memory descriptor 0x%p because type = %u (%s)", memoryDescriptor, memoryDescriptor->type, uefiMemoryTypeToString(memoryDescriptor->type)));

            continue;
        }

        if (memoryDescriptor->numberOfPages < numberOfPages)
        {
            UEFI_LVV(("Skipped memory descriptor 0x%p because numberOfPages(%u) is less than %u", memoryDescriptor, memoryDescriptor->numberOfPages, numberOfPages));

            continue;
        }



        u64 start = memoryDescriptor->physicalStart;
        u64 end   = start + memoryDescriptor->numberOfPages * PAGE_SIZE;

        if (!start) // start == 0
        {
            UEFI_LVV(("Offset 0 assigned to offset 8 since 0 is a special case for null pointer"));

            start = 8;
        }



        start = ROUND_UP(start, align);

        if (start >= end)
        {
            UEFI_LVV(("Skipped memory descriptor 0x%p because there is no proper aligned location", memoryDescriptor));

            continue;
        }
        else
        if (start + size > end)
        {
            UEFI_LVV(("Skipped memory descriptor 0x%p because there is no enough space(%u). Expected size = %u", memoryDescriptor, end - start, size));

            continue;
        }



        if (allocatePages(UefiAllocateType::ALLOCATE_ADDRESS, UefiMemoryType::LOADER_DATA, numberOfPages, &start) != UefiStatus::SUCCESS)
        {
            UEFI_LE(("Failed to allocate pages(%u)", numberOfPages));

            continue;
        }



        *address = (void *)start;

        UEFI_LVV(("Allocated pages(%u) at address(0x%p)", numberOfPages, *address));



        break;
    }



    if (freePool(memoryMap) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Released pool(0x%p) for memory descriptor", memoryMap));
    }
    else
    {
        UEFI_LE(("Failed to release pool(0x%p) for memory descriptor", memoryMap));
    }



    if (!(*address)) // *address == 0
    {
        UEFI_LF(("Failed to find valid memory descriptor"));

        return UefiStatus::NOT_FOUND;
    }

    UEFI_LVV(("Allocated address(0x%p)", *address));



    return UefiStatus::SUCCESS;
}

UefiStatus UEFI::loadImage(bool bootPolicy, uefi_handle parentImageHandle, UefiDevicePath *filePath, void *sourceBuffer, u64 sourceSize, uefi_handle *imageHandle)
{
    UEFI_LT((" | bootPolicy = %u, parentImageHandle = 0x%p, filePath = 0x%p, sourceBuffer = 0x%p, sourceSize = %u, imageHandle = 0x%p", bootPolicy, parentImageHandle, filePath, sourceBuffer, sourceSize, imageHandle));

    UEFI_ASSERT(parentImageHandle, "parentImageHandle is null", UefiStatus::ABORTED);
    UEFI_ASSERT(filePath,          "filePath is null",          UefiStatus::ABORTED);
    UEFI_ASSERT(imageHandle,       "imageHandle is null",       UefiStatus::ABORTED);



    return sBootServices->loadImage(bootPolicy, parentImageHandle, filePath, sourceBuffer, sourceSize, imageHandle);
}

UefiStatus UEFI::startImage(uefi_handle imageHandle, u64 *exitDataSize, char16 **exitData)
{
    UEFI_LT((" | imageHandle = 0x%p, exitDataSize = 0x%p, exitData = 0x%p", imageHandle, exitDataSize, exitData));

    UEFI_ASSERT(imageHandle, "imageHandle is null", UefiStatus::ABORTED);



    return sBootServices->startImage(imageHandle, exitDataSize, exitData);
}

UefiStatus UEFI::resetSystem(UefiResetType resetType, UefiStatus resetStatus, u64 dataSize, char16 *resetData)
{
    UEFI_LT((" | resetType = %u, resetStatus = 0x%016lX, dataSize = %u, resetData = 0x%p", resetType, resetStatus, dataSize, resetData));



    return sSystemTable->runtimeServices->resetSystem(resetType, resetStatus, dataSize, resetData);
}

UefiStatus UEFI::exitBootServices(u64 mapKey)
{
    UEFI_LT((" | mapKey = %u", mapKey));



    asm volatile(
        "pushq   %rbp"          "\n\t"  // pushq   %rbp         # Store RBP to stack
        "movq    %rsp, %rbp"    "\n\t"  // movq    %rsp, %rbp   # Store RSP value in RBP
        "andq    $-0x10, %rsp"  "\n\t"  // andq    $-0x10, %rsp # Make RSP aligned
    );



    UefiStatus res = sBootServices->exitBootServices(sImageHandle, mapKey);



    asm volatile(
        "movq    %rbp, %rsp"    "\n\t"  // movq    %rbp, %rsp   # Restore RSP from RBP
        "popq    %rbp"          "\n\t"  // popq    %rbp         # Restore RBP from stack
    );



    return res;
}

uefi_handle UEFI::getImageHandle()
{
    UEFI_LT((""));



    return sImageHandle;
}

UefiSystemTable* UEFI::getSystemTable()
{
    UEFI_LT((""));



    return sSystemTable;
}

NgosStatus UEFI::disableWatchdogTimer()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(sBootServices->setWatchdogTimer(0, 0, 0, 0), UefiStatus, UefiStatus::SUCCESS, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus UEFI::maximizeConsole(UefiSimpleTextOutputInterface *textOutput)
{
    UEFI_LT((" | textOutput = 0x%p", textOutput));

    UEFI_ASSERT(textOutput, "textOutput is null", NgosStatus::ASSERTION);



    u64 maximumBuffer = 0;
    i32 foundMode     = 0;

    for (i64 i = 0; i < textOutput->mode->maxMode; ++i)
    {
        u64 columns;
        u64 rows;

        if (textOutput->queryMode(textOutput, i, &columns, &rows) != UefiStatus::SUCCESS)
        {
            UEFI_LV(("Failed to query mode(%d) for protocol(0x%p) for UefiSimpleTextOutputInterface", i, textOutput));

            continue;
        }

        UEFI_LVV(("Queried mode(%d) for protocol(0x%p) for UefiSimpleTextOutputInterface", i, textOutput));



        u64 screenSize = columns * rows;

        UEFI_LVVV(("columns    = %u", columns));
        UEFI_LVVV(("rows       = %u", rows));
        UEFI_LVVV(("screenSize = %u", screenSize));

        if (screenSize > maximumBuffer)
        {
            maximumBuffer = screenSize;
            foundMode     = i;
        }
    }



    if (textOutput->mode->mode != foundMode)
    {
        if (textOutput->setMode(textOutput, foundMode) != UefiStatus::SUCCESS)
        {
            UEFI_LF(("Failed to update screen text mode"));

            return NgosStatus::FAILED;
        }

        UEFI_LVV(("Updated screen text mode to %u", foundMode));
    }



    return NgosStatus::OK;
}

NgosStatus UEFI::disableCursor()
{
    UEFI_LT((""));

    UEFI_ASSERT(sTextOutput, "sTextOutput is null", NgosStatus::ASSERTION);



    sTextOutput->enableCursor(sTextOutput, false);



    return NgosStatus::OK;
}

NgosStatus UEFI::switchConsoleControlScreenMode(UefiConsoleControlScreenMode mode)
{
    UEFI_LT((" | mode = %u", mode));

    UEFI_ASSERT(mode < UefiConsoleControlScreenMode::MAXIMUM, "mode is invalid", NgosStatus::ASSERTION);



    UefiConsoleControlProtocol *consoleControl;
    Guid                        protocol = UEFI_CONSOLE_CONTROL_PROTOCOL_GUID;

    if (locateProtocol(&protocol, nullptr, (void **)&consoleControl) == UefiStatus::SUCCESS)
    {
        UEFI_LVV(("Located protocol(0x%p) UEFI_CONSOLE_CONTROL_PROTOCOL", consoleControl));



        UefiConsoleControlScreenMode oldMode;

        if (consoleControl->getMode(consoleControl, &oldMode, nullptr, nullptr) == UefiStatus::SUCCESS)
        {
            UEFI_LVV(("Got current console control screen mode: %u (%s)", oldMode, uefiConsoleControlScreenModeToString(oldMode)));

            if (oldMode != mode)
            {
                if (consoleControl->setMode(consoleControl, mode) == UefiStatus::SUCCESS)
                {
                    UEFI_LVV(("Switched console control screen mode to %u (%s) mode", mode, uefiConsoleControlScreenModeToString(mode)));
                }
                else
                {
                    UEFI_LV(("Failed to switch console control screen mode to %u (%s) mode", mode, uefiConsoleControlScreenModeToString(mode)));
                }
            }
            else
            {
                UEFI_LVV(("Already in %u (%s) mode", mode, uefiConsoleControlScreenModeToString(mode)));
            }
        }
        else
        {
            UEFI_LV(("Failed to get current console control screen mode"));
        }
    }
    else
    {
        UEFI_LV(("Failed to locate protocol UEFI_CONSOLE_CONTROL_PROTOCOL"));
    }



    return NgosStatus::OK;
}

void UEFI::print(char16 *ch)
{
    // UEFI_LT((" | ch = 0x%p", ch)); // Commented to avoid infinite loop

    UEFI_ASSERT(ch,          "ch is null");
    UEFI_ASSERT(sTextOutput, "sTextOutput is null");



    sTextOutput->outputString(sTextOutput, ch);
}
