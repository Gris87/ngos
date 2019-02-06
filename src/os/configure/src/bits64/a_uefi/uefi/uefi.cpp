#include "uefi.h"

#include <ngos/utils.h>
#include <src/bits64/printf/printf.h>

#include "src/bits64/a_uefi/uefi/lib/eficonstants.h"
#include "src/bits64/a_uefi/uefi/uefiassert.h"
#include "src/bits64/a_uefi/uefi/uefilog.h"



EfiHandle                     UEFI::sImageHandle;
EfiSystemTable               *UEFI::sSystemTable;
EfiSimpleTextOutputInterface *UEFI::sTextOutput;
EfiBootServices              *UEFI::sBootServices;



NgosStatus UEFI::init(EfiHandle imageHandle, EfiSystemTable *systemTable)
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

    UEFI_ASSERT(sSystemTable->runtimeServices->header.signature == EFI_RUNTIME_SERVICES_SIGNATURE, "Runtime services signature is invalid", NgosStatus::ASSERTION);
    UEFI_ASSERT(sSystemTable->bootServices->header.signature    == EFI_BOOT_SERVICES_SIGNATURE,    "Boot services signature is invalid",    NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

EfiStatus UEFI::clearScreen()
{
    UEFI_LT((""));

    UEFI_ASSERT(sTextOutput, "sTextOutput is null", EfiStatus::ABORTED);



    return sTextOutput->clearScreen(sTextOutput);
}

void UEFI::print(char ch)
{
    // UEFI_LT((" | ch = %c", ch)); // Commented to avoid bad looking logs



    efi_char16 buffer[2] = { (efi_char16)ch, 0 };
    print(buffer);
}

void UEFI::print(const char *str)
{
    // UEFI_LT((" | str = 0x%p", str)); // Commented to avoid infinite loop

    UEFI_ASSERT(str, "str is null");



    while (*str)
    {
        if (*str == '\n')
        {
            efi_char16 nl[2] = { '\r', 0 };
            print(nl);
        }

        efi_char16 ch[2] = { (efi_char16)(*str), 0 };
        print(ch);

        ++str;
    }
}

void UEFI::println()
{
    // UEFI_LT(("")); // Commented to avoid bad looking logs



    efi_char16 nl[3] = { '\r', '\n', 0 };
    print(nl);
}

void UEFI::println(char ch)
{
    // UEFI_LT((" | ch = %c", ch)); // Commented to avoid bad looking logs



    efi_char16 buffer[4] = { (efi_char16)ch, '\r', '\n', 0 };
    print(buffer);
}

void UEFI::println(const char *str)
{
    // UEFI_LT((" | str = 0x%p", str)); // Commented to avoid infinite loop

    UEFI_ASSERT(str, "str is null");



    print(str);

    efi_char16 nl[3] = { '\r', '\n', 0 };
    print(nl);
}

i64 UEFI::printf(const char *format, ...)
{
    // UEFI_LT((" | format = 0x%p", format)); // Commented to avoid infinite loop

    UEFI_ASSERT(format, "format is null", 0);



    // HACK: Temporary fix for PIE. Try to find another solution
    char *tempBuffer;

    // Ignore CppAlignmentVerifier [BEGIN]
    asm volatile(
        "leaq    printfBuffer(%%rip), %0" // leaq    printfBuffer(%rip), %rdi   # Get address of printfBuffer variable to RDI. %RDI == tempBuffer
            :                             // Output parameters
                "=r" (tempBuffer)         // "r" == any general register, "=" - write only
    );
    // Ignore CppAlignmentVerifier [END]



    va_list args;

    va_start(args, format);
    i64 res = vsprintf(tempBuffer, format, args);
    va_end(args);

    UEFI_TEST_ASSERT(res < (i64)sizeof(printfBuffer), 0);



    println(tempBuffer);



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

EfiStatus UEFI::createEvent(u32 type, efi_tpl notifyTpl, efi_event_notify notifyFunction, void *notifyContext, EfiEvent *event)
{
    UEFI_LT((" | type = %u, notifyTpl = %u, notifyFunction = 0x%p, notifyContext = 0x%p, event = 0x%p", type, notifyTpl, notifyFunction, notifyContext, event));

    UEFI_ASSERT(event, "event is null", EfiStatus::ABORTED);



    return sBootServices->createEvent(type, notifyTpl, notifyFunction, notifyContext, event);
}

EfiStatus UEFI::setTimer(EfiEvent event, EfiTimerDelay type, u64 triggerTime)
{
    UEFI_LT((" | event = 0x%p, type = %d, triggerTime = %u", event, type, triggerTime));

    UEFI_ASSERT(event, "event is null", EfiStatus::ABORTED);



    return sBootServices->setTimer(event, type, triggerTime);
}

EfiStatus UEFI::waitForEvent(u64 numberOfEvents, EfiEvent *event, u64 *index)
{
    UEFI_LT((" | numberOfEvents = %u, event = 0x%p, index = 0x%p", numberOfEvents, event, index));

    UEFI_ASSERT(numberOfEvents > 0, "numberOfEvents is zero", EfiStatus::ABORTED);
    UEFI_ASSERT(event,              "event is null",          EfiStatus::ABORTED);
    UEFI_ASSERT(index,              "index is null",          EfiStatus::ABORTED);



    return sBootServices->waitForEvent(numberOfEvents, event, index);
}

EfiStatus UEFI::closeEvent(EfiEvent event)
{
    UEFI_LT((" | event = 0x%p", event));

    UEFI_ASSERT(event, "event is null", EfiStatus::ABORTED);



    return sBootServices->closeEvent(event);
}

EfiStatus UEFI::allocatePool(EfiMemoryType poolType, u64 size, void **buffer)
{
    UEFI_LT((" | poolType = %d, size = %u, buffer = 0x%p", poolType, size, buffer));

    UEFI_ASSERT(size > 0, "size is zero",   EfiStatus::ABORTED);
    UEFI_ASSERT(buffer,   "buffer is null", EfiStatus::ABORTED);



    return sBootServices->allocatePool(poolType, size, buffer);
}

EfiStatus UEFI::freePool(void *buffer)
{
    UEFI_LT((" | buffer = 0x%p", buffer));

    UEFI_ASSERT(buffer, "buffer is null", EfiStatus::ABORTED);



    return sBootServices->freePool(buffer);
}

EfiStatus UEFI::handleProtocol(EfiHandle handle, EfiGuid *protocol, void **interface)
{
    UEFI_LT((" | handle = 0x%p, protocol = 0x%p, interface = 0x%p", handle, protocol, interface));

    UEFI_ASSERT(handle,    "handle is null",    EfiStatus::ABORTED);
    UEFI_ASSERT(protocol,  "protocol is null",  EfiStatus::ABORTED);
    UEFI_ASSERT(interface, "interface is null", EfiStatus::ABORTED);



    return sBootServices->handleProtocol(handle, protocol, interface);
}

EfiStatus UEFI::locateHandle(EfiLocateSearchType searchType, EfiGuid *protocol, void *searchKey, u64 *bufferSize, EfiHandle *buffer)
{
    UEFI_LT((" | searchType = %d, protocol = 0x%p, searchKey = 0x%p, bufferSize = 0x%p, buffer = 0x%p", searchType, protocol, searchKey, bufferSize, buffer));

    UEFI_ASSERT((searchType == EfiLocateSearchType::BY_PROTOCOL
                &&
                protocol)
                ||
                (searchType == EfiLocateSearchType::BY_REGISTER_NOTIFY
                &&
                searchKey)
                ||
                searchType == EfiLocateSearchType::ALL_HANDLES, "Invalid arguments",  EfiStatus::ABORTED);

    UEFI_ASSERT(bufferSize,                                     "bufferSize is null", EfiStatus::ABORTED);
    UEFI_ASSERT(buffer || (bufferSize && *bufferSize == 0),     "buffer is null",     EfiStatus::ABORTED);



    return sBootServices->locateHandle(searchType, protocol, searchKey, bufferSize, buffer);
}

bool UEFI::memoryMapHasHeadroom(u64 bufferSize, u64 memoryMapSize, u64 descriptorSize)
{
    UEFI_LT((" | bufferSize = %u, memoryMapSize = %u, descriptorSize = %u", bufferSize, memoryMapSize, descriptorSize));

    UEFI_ASSERT(bufferSize > 0,     "bufferSize is zero",     false);
    UEFI_ASSERT(memoryMapSize > 0,  "memoryMapSize is zero",  false);
    UEFI_ASSERT(descriptorSize > 0, "descriptorSize is zero", false);



    i64 slack = bufferSize - memoryMapSize;

    return slack / (i64)descriptorSize >= EFI_MEMORY_MAP_NUMBER_OF_SLACK_SLOTS;
}

EfiStatus UEFI::allocatePages(EfiAllocateType type, EfiMemoryType memoryType, u64 noPages, efi_physical_address *memory)
{
    UEFI_LT((" | type = %d, memoryType = %d, noPages = %u, memory = 0x%p", type, memoryType, noPages, memory));

    UEFI_ASSERT(noPages > 0, "noPages is zero", EfiStatus::ABORTED);
    UEFI_ASSERT(memory,      "memory is null",  EfiStatus::ABORTED);



    return sBootServices->allocatePages(type, memoryType, noPages, memory);
}

EfiStatus UEFI::getMemoryMap(u64 *memoryMapSize, EfiMemoryDescriptor *memoryMap, u64 *mapKey, u64 *descriptorSize, u32 *descriptorVersion)
{
    UEFI_LT((" | memoryMapSize = 0x%p, memoryMap = 0x%p, mapKey = 0x%p, descriptorSize = 0x%p, descriptorVersion = 0x%p", memoryMapSize, memoryMap, mapKey, descriptorSize, descriptorVersion));

    UEFI_ASSERT(memoryMapSize,     "memoryMapSize is null",     EfiStatus::ABORTED);
    UEFI_ASSERT(memoryMap,         "memoryMap is null",         EfiStatus::ABORTED);
    UEFI_ASSERT(mapKey,            "mapKey is null",            EfiStatus::ABORTED);
    UEFI_ASSERT(descriptorSize,    "descriptorSize is null",    EfiStatus::ABORTED);
    UEFI_ASSERT(descriptorVersion, "descriptorVersion is null", EfiStatus::ABORTED);



    return sBootServices->getMemoryMap(memoryMapSize, memoryMap, mapKey, descriptorSize, descriptorVersion);
}

EfiStatus UEFI::getMemoryMap(UefiBootMemoryMap *map)
{
    UEFI_LT((" | map = 0x%p", map));

    UEFI_ASSERT(map,                 "map is null",                 EfiStatus::ABORTED);
    UEFI_ASSERT(map->memoryMapSize,  "map->memoryMapSize is null",  EfiStatus::ABORTED);
    UEFI_ASSERT(map->descriptorSize, "map->descriptorSize is null", EfiStatus::ABORTED);
    UEFI_ASSERT(map->bufferSize,     "map->bufferSize is null",     EfiStatus::ABORTED);



    EfiMemoryDescriptor *memoryDescriptor = 0;

    *map->descriptorSize = sizeof(EfiMemoryDescriptor);
    *map->memoryMapSize  = *map->descriptorSize << 6; // "<< 6" == "* 64"
    *map->bufferSize     = *map->memoryMapSize;



    do
    {
        if (allocatePool(EfiMemoryType::LOADER_DATA, *map->memoryMapSize, (void **)&memoryDescriptor) != EfiStatus::SUCCESS)
        {
            UEFI_LF(("Failed to allocate pool(%u) for memory descriptor", *map->memoryMapSize));

            return EfiStatus::ABORTED;
        }

        UEFI_LVV(("Allocated pool(%u, 0x%p) for memory descriptor", *map->memoryMapSize, memoryDescriptor));



        *map->descriptorSize = 0;

        u64 mapKey            = 0;
        u32 descriptorVersion = 0;



        EfiStatus status = getMemoryMap(map->memoryMapSize, memoryDescriptor, &mapKey, map->descriptorSize, &descriptorVersion);

        if (status == EfiStatus::BUFFER_TOO_SMALL || !memoryMapHasHeadroom(*map->bufferSize, *map->memoryMapSize, *map->descriptorSize))
        {
            UEFI_LW(("Buffer for memory descriptor is too small. Trying to allocate bigger buffer"));



            if (freePool(memoryDescriptor) == EfiStatus::SUCCESS)
            {
                UEFI_LVV(("Released pool(0x%p) for memory descriptor", memoryDescriptor));
            }
            else
            {
                UEFI_LE(("Failed to release pool(0x%p) for memory descriptor", memoryDescriptor));
            }



            *map->memoryMapSize += *map->descriptorSize * EFI_MEMORY_MAP_NUMBER_OF_SLACK_SLOTS;
            *map->bufferSize    =  *map->memoryMapSize;



            continue;
        }



        if (status != EfiStatus::SUCCESS)
        {
            UEFI_LF(("Failed to get memory map"));



            if (freePool(memoryDescriptor) == EfiStatus::SUCCESS)
            {
                UEFI_LVV(("Released pool(0x%p) for memory descriptor", memoryDescriptor));
            }
            else
            {
                UEFI_LE(("Failed to release pool(0x%p) for memory descriptor", memoryDescriptor));
            }



            return EfiStatus::ABORTED;
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



        return EfiStatus::SUCCESS;
    } while(true);
}

EfiStatus UEFI::lowAlloc(u64 size, u64 align, void **address)
{
    UEFI_LT((" | size = %u, align = %u, address = 0x%p", size, align, address));

    UEFI_ASSERT(size > 0,  "size is zero",    EfiStatus::ABORTED);
    UEFI_ASSERT(align > 0, "align is zero",   EfiStatus::ABORTED);
    UEFI_ASSERT(address,   "address is null", EfiStatus::ABORTED);



    EfiMemoryDescriptor *memoryMap      = 0;
    u64                  memoryMapSize  = 0;
    u64                  descriptorSize = 0;
    u64                  bufferSize     = 0;



    UefiBootMemoryMap bootMemoryMap;

    bootMemoryMap.memoryMap         = &memoryMap;
    bootMemoryMap.memoryMapSize     = &memoryMapSize;
    bootMemoryMap.descriptorSize    = &descriptorSize;
    bootMemoryMap.descriptorVersion = 0;
    bootMemoryMap.mapKey            = 0;
    bootMemoryMap.bufferSize        = &bufferSize;



    if (getMemoryMap(&bootMemoryMap) != EfiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to get memory map"));

        return EfiStatus::ABORTED;
    }

    // UEFI_LVV(("Found memory map")); // Commented to avoid log duplication



    UEFI_LVVV(("bootMemoryMap parameters:"));
    UEFI_LVVV(("-------------------------------------"));

    UEFI_LVVV(("memoryMap      = 0x%p", memoryMap));
    UEFI_LVVV(("memoryMapSize  = %u",   memoryMapSize));
    UEFI_LVVV(("descriptorSize = %u",   descriptorSize));
    UEFI_LVVV(("bufferSize     = %u",   bufferSize));

    UEFI_LVVV(("-------------------------------------"));



    if (align < EFI_ALLOC_ALIGN)
    {
        UEFI_LVVV(("align value increased from %u to %u", align, EFI_ALLOC_ALIGN));

        align = EFI_ALLOC_ALIGN;
    }



    size = ROUND_UP(size, EFI_ALLOC_ALIGN);

    u64 numberOfPages = size / EFI_PAGE_SIZE;



    UEFI_LVVV(("size          = %u", size));
    UEFI_LVVV(("numberOfPages = %u", numberOfPages));



    *address = 0;



    i64 count = memoryMapSize / descriptorSize;
    UEFI_LVVV(("count = %d", count));

    for (i64 i = 0; i < count; ++i)
    {
        EfiMemoryDescriptor *memoryDescriptor = (EfiMemoryDescriptor *)((u64)memoryMap + (i * descriptorSize));
        UEFI_LVV(("Handling memory descriptor 0x%p", memoryDescriptor));

        UEFI_TEST_ASSERT(memoryDescriptor, EfiStatus::ABORTED);



        UEFI_LVVV(("type          = %u",   memoryDescriptor->type));
        UEFI_LVVV(("physicalStart = 0x%p", memoryDescriptor->physicalStart));
        UEFI_LVVV(("virtualStart  = 0x%p", memoryDescriptor->virtualStart));
        UEFI_LVVV(("numberOfPages = %u",   memoryDescriptor->numberOfPages));
        UEFI_LVVV(("attribute     = %u",   memoryDescriptor->attribute));



        if (memoryDescriptor->type != (u32)EfiMemoryType::CONVENTIONAL_MEMORY)
        {
            UEFI_LVV(("Skipped memory descriptor 0x%p because type = %u", memoryDescriptor, memoryDescriptor->type));

            continue;
        }

        if (memoryDescriptor->numberOfPages < numberOfPages)
        {
            UEFI_LVV(("Skipped memory descriptor 0x%p because numberOfPages(%u) is less than %u", memoryDescriptor, memoryDescriptor->numberOfPages, numberOfPages));

            continue;
        }



        u64 start = memoryDescriptor->physicalStart;
        u64 end   = start + memoryDescriptor->numberOfPages * EFI_PAGE_SIZE;

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



        if (allocatePages(EfiAllocateType::ALLOCATE_ADDRESS, EfiMemoryType::LOADER_DATA, numberOfPages, &start) != EfiStatus::SUCCESS)
        {
            UEFI_LE(("Failed to allocate pages(%u)", numberOfPages));

            continue;
        }



        *address = (void *)start;

        UEFI_LVV(("Allocated pages(%u) at address(0x%p)", numberOfPages, *address));



        break;
    }



    if (freePool(memoryMap) == EfiStatus::SUCCESS)
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

        return EfiStatus::NOT_FOUND;
    }

    UEFI_LVV(("Allocated address(0x%p)", *address));



    return EfiStatus::SUCCESS;
}

EfiStatus UEFI::exitBootServices(u64 mapKey)
{
    UEFI_LT((" | mapKey = %u", mapKey));



    asm volatile (
        "pushq   %rbp"          "\n\t"
        "movq    %rsp, %rbp"    "\n\t"
        "andq    $-0x10, %rsp"  "\n\t"
    );



    EfiStatus res = sBootServices->exitBootServices(sImageHandle, mapKey);



    asm volatile (
        "movq    %rbp, %rsp"    "\n\t"
        "popq    %rbp"          "\n\t"
    );



    return res;
}

EfiHandle UEFI::getImageHandle()
{
    UEFI_LT((""));



    return sImageHandle;
}

void UEFI::print(efi_char16 *ch)
{
    // UEFI_LT((" | ch = 0x%p", ch)); // Commented to avoid infinite loop

    UEFI_ASSERT(ch,          "ch is null");
    UEFI_ASSERT(sTextOutput, "sTextOutput is null");



    sTextOutput->outputString(sTextOutput, ch);
}
