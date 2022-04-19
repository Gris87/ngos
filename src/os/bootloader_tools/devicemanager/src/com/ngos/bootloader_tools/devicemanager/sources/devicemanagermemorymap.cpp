#include "devicemanagermemorymap.h"

#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/common/page/macros.h>
#include <com/ngos/shared/common/string/utils.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



DeviceManagerEntry* DeviceManagerMemoryMap::sEntry;



NgosStatus DeviceManagerMemoryMap::init()
{
    UEFI_LT((""));



    UefiMemoryDescriptor *memoryMap         = nullptr;
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

    UEFI_LVV(("Found memory map"));



    UEFI_LVVV(("bootMemoryMap parameters:"));
    UEFI_LVVV(("-------------------------------------"));

    UEFI_LVVV(("memoryMap         = 0x%p", memoryMap));
    UEFI_LVVV(("memoryMapSize     = %u",   memoryMapSize));
    UEFI_LVVV(("descriptorSize    = %u",   descriptorSize));
    UEFI_LVVV(("descriptorVersion = %u",   descriptorVersion));
    UEFI_LVVV(("mapKey            = %u",   mapKey));
    UEFI_LVVV(("bufferSize        = %u",   bufferSize));

    UEFI_LVVV(("-------------------------------------"));



    u64 summary[(u64)UefiMemoryType::MAXIMUM];
    memzero(summary, sizeof(summary));

    u64 totalMemory = 0;



    sEntry = new DeviceManagerEntry();



    i64 numberOfDescriptors = memoryMapSize / descriptorSize;

    for (good_I64 i = 0; i < numberOfDescriptors; ++i)
    {
        UefiMemoryDescriptor *memoryDescriptor = MEMORY_MAP_DESCRIPTOR(&bootMemoryMap, i);
        UEFI_LVV(("Handling memory descriptor #%d at address 0x%p", i, memoryDescriptor));

        UEFI_TEST_ASSERT(memoryDescriptor, NgosStatus::ASSERTION);



        UEFI_LVVV(("type          = %s",        enumToFullString(memoryDescriptor->type)));
        UEFI_LVVV(("physicalStart = 0x%p",      memoryDescriptor->physicalStart));
        UEFI_LVVV(("virtualStart  = 0x%p",      memoryDescriptor->virtualStart));
        UEFI_LVVV(("numberOfPages = %u",        memoryDescriptor->numberOfPages));
        UEFI_LVVV(("attribute     = 0x%016llX", memoryDescriptor->attribute));



        u64 size = memoryDescriptor->numberOfPages * PAGE_SIZE;

        summary[(u64)memoryDescriptor->type] += size;



        // Some memory types are not related to physical memory
        if (
            memoryDescriptor->type != UefiMemoryType::MEMORY_MAPPED_IO
            &&
            memoryDescriptor->type != UefiMemoryType::MEMORY_MAPPED_IO_PORT_SPACE
           )
        {
            totalMemory += size;
        }



        UEFI_ASSERT_EXECUTION(sEntry->addRecord(mprintf("0x%p - 0x%p", memoryDescriptor->physicalStart, memoryDescriptor->physicalStart + size), enumToString(memoryDescriptor->type), DeviceManagerMode::TECHNICAL), NgosStatus::ASSERTION);
    }



    for (good_I64 i = 0; i < (i64)UefiMemoryType::MAXIMUM; ++i)
    {
        UEFI_ASSERT_EXECUTION(sEntry->addRecord(enumToString((UefiMemoryType)i), strdup(bytesToString(summary[i])), DeviceManagerMode::BASIC), NgosStatus::ASSERTION);
    }

    UEFI_ASSERT_EXECUTION(sEntry->addRecord("Total memory", strdup(bytesToString(totalMemory)), DeviceManagerMode::BASIC), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

DeviceManagerEntry* DeviceManagerMemoryMap::getEntry()
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return sEntry;
}
