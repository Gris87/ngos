#include "exitbootservices.h"

#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <uefibase/src/com/ngos/shared/uefibase/uefi/uefilog.h>

#include "src/com/ngos/configure/a_uefi/main/setupmemorymapentries.h"



inline UefiStatus exitBootServicesAttempt(UefiBootMemoryMap *bootMemoryMap)
{
    UEFI_LT((" | bootMemoryMap = 0x%p", bootMemoryMap));

    UEFI_ASSERT(bootMemoryMap, "bootMemoryMap is null", UefiStatus::ABORTED);



    UEFI_LVVV(("bootMemoryMap parameters:"));
    UEFI_LVVV(("-------------------------------------"));

    UEFI_LVVV(("memoryMap         = 0x%p", *bootMemoryMap->memoryMap));
    UEFI_LVVV(("memoryMapSize     = %u",   *bootMemoryMap->memoryMapSize));
    UEFI_LVVV(("descriptorSize    = %u",   *bootMemoryMap->descriptorSize));
    UEFI_LVVV(("descriptorVersion = %u",   *bootMemoryMap->descriptorVersion));
    UEFI_LVVV(("mapKey            = %u",   *bootMemoryMap->mapKey));
    UEFI_LVVV(("bufferSize        = %u",   *bootMemoryMap->bufferSize));

    UEFI_LVVV(("-------------------------------------"));



    return UEFI::exitBootServices(*bootMemoryMap->mapKey);
}

NgosStatus exitBootServices(UefiBootMemoryMap *bootMemoryMap)
{
    UEFI_LT((" | bootMemoryMap = 0x%p", bootMemoryMap));

    UEFI_ASSERT(bootMemoryMap, "bootMemoryMap is null", NgosStatus::ASSERTION);



    UEFI_LI(("Exiting boot services..."));



    if (UEFI::getMemoryMap(bootMemoryMap) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to get memory map"));

        return NgosStatus::FAILED;
    }

    // UEFI_LVV(("Found memory map")); // Commented to avoid log duplication



#if NGOS_BUILD_LOG_TO_UEFI_FILE == OPTION_YES
    UEFI_ASSERT_EXECUTION(UefiLogFile::noMorePrint(), NgosStatus::ASSERTION);
#endif



    UefiStatus status = exitBootServicesAttempt(bootMemoryMap);

    // exitBootServices may return UefiStatus::INVALID_PARAMETER. It is means that memory map became invalid and we have one more attempt to repeat
    if (status == UefiStatus::INVALID_PARAMETER)
    {
        UEFI_LW(("Boot memory map became invalid during exitBootServices. Trying one more time"));



        *bootMemoryMap->memoryMapSize = *bootMemoryMap->bufferSize;



        if (UEFI::getMemoryMap(bootMemoryMap->memoryMapSize, *bootMemoryMap->memoryMap, bootMemoryMap->mapKey, bootMemoryMap->descriptorSize, bootMemoryMap->descriptorVersion) != UefiStatus::SUCCESS)
        {
            UEFI_LF(("Failed to get memory map"));

            return NgosStatus::FAILED;
        }

        // UEFI_LVV(("Found memory map")); // Commented to avoid log duplication



        if (exitBootServicesAttempt(bootMemoryMap) != UefiStatus::SUCCESS)
        {
            UEFI_LF(("Failed to exit boot services"));

            return NgosStatus::FAILED;
        }

        // UEFI_LVV(("Exit boot services completed")); // Commented to avoid log duplication
    }
    else
    if (status != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to exit boot services"));

        return NgosStatus::FAILED;
    }

    // UEFI_LVV(("Exit boot services completed")); // Commented to avoid log duplication



    return NgosStatus::OK;
}

NgosStatus exitBootServices(BootParams *params)
{
    UEFI_LT((" | params = 0x%p", params));

    UEFI_ASSERT(params, "params is null", NgosStatus::ASSERTION);



    UefiMemoryDescriptor *memoryMap         = 0;
    u64                   memoryMapSize     = 0;
    u64                   descriptorSize    = 0;
    u32                   descriptorVersion = 0;
    u64                   mapKey            = 0;
    u64                   bufferSize        = 0;



    UefiBootMemoryMap bootMemoryMap;

    bootMemoryMap.memoryMap         = &memoryMap;
    bootMemoryMap.memoryMapSize     = &memoryMapSize;
    bootMemoryMap.descriptorSize    = &descriptorSize;
    bootMemoryMap.descriptorVersion = &descriptorVersion;
    bootMemoryMap.mapKey            = &mapKey;
    bootMemoryMap.bufferSize        = &bufferSize;



    if (UEFI::getMemoryMap(&bootMemoryMap) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to get memory map"));

        return NgosStatus::FAILED;
    }

    // UEFI_LVV(("Found memory map")); // Commented to avoid log duplication



    UEFI_LVVV(("bootMemoryMap parameters:"));
    UEFI_LVVV(("-------------------------------------"));

    UEFI_LVVV(("memoryMap         = 0x%p", memoryMap));
    UEFI_LVVV(("memoryMapSize     = %u",   memoryMapSize));
    UEFI_LVVV(("descriptorSize    = %u",   descriptorSize));
    UEFI_LVVV(("descriptorVersion = %u",   descriptorVersion));
    UEFI_LVVV(("mapKey            = %u",   mapKey));
    UEFI_LVVV(("bufferSize        = %u",   bufferSize));

    UEFI_LVVV(("-------------------------------------"));



    u64             numberOfDescriptors = (memoryMapSize / descriptorSize) + 5; // Let's add few
    u64             size                = numberOfDescriptors * sizeof(MemoryMapEntry);
    MemoryMapEntry *memoryMapEntries    = 0;



    if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&memoryMapEntries) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate pool(%u) for memory map entries", size));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Allocated pool(0x%p, %u) for memory map entries", memoryMapEntries, size));



    if (exitBootServices(&bootMemoryMap) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to exit boot services"));

        return NgosStatus::FAILED;
    }

    // UEFI_LVV(("Exit boot services completed")); // Commented to avoid log duplication



    UEFI_ASSERT((memoryMapSize / descriptorSize) <= numberOfDescriptors, "numberOfDescriptors is invalid", NgosStatus::ASSERTION);



    if (setupMemoryMapEntries(params, &bootMemoryMap, memoryMapEntries) != NgosStatus::OK)
    {
        UEFI_LF(("Failed to setup memory map entries"));

        return NgosStatus::FAILED;
    }

    UEFI_LI(("Setup memory map entries completed"));



    return NgosStatus::OK;
}
