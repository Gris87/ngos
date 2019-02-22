#include "setupmemorymapentries.h"

#include <page/macros.h>

#include "src/bits64/a_uefi/uefi/uefiassert.h"
#include "src/bits64/a_uefi/uefi/uefilog.h"



NgosStatus setupMemoryMapEntries(BootParams *params, UefiBootMemoryMap *bootMemoryMap, MemoryMapEntry *memoryMapEntries)
{
    UEFI_LT((" | params = 0x%p, bootMemoryMap = 0x%p, memoryMapEntries = 0x%p", params, bootMemoryMap, memoryMapEntries));

    UEFI_ASSERT(params,           "params is null",           NgosStatus::ASSERTION);
    UEFI_ASSERT(bootMemoryMap,    "bootMemoryMap is null",    NgosStatus::ASSERTION);
    UEFI_ASSERT(memoryMapEntries, "memoryMapEntries is null", NgosStatus::ASSERTION);



    MemoryMapEntry *previous              = 0;
    u64             memoryMapEntriesCount = 0;



    i64 count = (*bootMemoryMap->memoryMapSize) / (*bootMemoryMap->descriptorSize);
    UEFI_LVVV(("count = %d", count));

    for (i64 i = 0; i < count; ++i)
    {
        UefiMemoryDescriptor *memoryDescriptor = MEMORY_MAP_DESCRIPTOR(bootMemoryMap, i);
        UEFI_LVV(("Handling memory descriptor 0x%p", memoryDescriptor));

        UEFI_TEST_ASSERT(memoryDescriptor, NgosStatus::ASSERTION);



        UEFI_LVVV(("type          = %u",       memoryDescriptor->type));
        UEFI_LVVV(("physicalStart = 0x%p",     memoryDescriptor->physicalStart));
        UEFI_LVVV(("virtualStart  = 0x%p",     memoryDescriptor->virtualStart));
        UEFI_LVVV(("numberOfPages = %u",       memoryDescriptor->numberOfPages));
        UEFI_LVVV(("attribute     = 0x%016lX", memoryDescriptor->attribute));



        MemoryMapEntryType entryType;

        switch ((UefiMemoryType)memoryDescriptor->type)
        {
            case UefiMemoryType::RESERVED_MEMORY:
            case UefiMemoryType::RUNTIME_SERVICES_CODE:
            case UefiMemoryType::RUNTIME_SERVICES_DATA:
            case UefiMemoryType::MEMORY_MAPPED_IO:
            case UefiMemoryType::MEMORY_MAPPED_IO_PORT_SPACE:
            case UefiMemoryType::PAL_CODE:
            {
                entryType = MemoryMapEntryType::RESERVED;
            }
            break;

            case UefiMemoryType::UNUSABLE_MEMORY:
            {
                entryType = MemoryMapEntryType::UNUSABLE;
            }
            break;

            case UefiMemoryType::ACPI_RECLAIM_MEMORY:
            {
                entryType = MemoryMapEntryType::ACPI;
            }
            break;

            case UefiMemoryType::LOADER_CODE:
            case UefiMemoryType::LOADER_DATA:
            case UefiMemoryType::BOOT_SERVICES_CODE:
            case UefiMemoryType::BOOT_SERVICES_DATA:
            case UefiMemoryType::CONVENTIONAL_MEMORY:
            {
                entryType = MemoryMapEntryType::RAM;
            }
            break;

            case UefiMemoryType::ACPI_MEMORY_NVS:
            {
                entryType = MemoryMapEntryType::NVS;
            }
            break;

            case UefiMemoryType::PERSISTENT_MEMORY:
            {
                entryType = MemoryMapEntryType::PERSISTENT_MEMORY;
            }
            break;

            case UefiMemoryType::MAXIMUM:
            {
                UEFI_LF(("Invalid memory descriptor type %u", memoryDescriptor->type));

                return NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;

            default:
            {
                UEFI_LF(("Unknown memory descriptor type %u", memoryDescriptor->type));

                return NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;
        }



        if (
            previous
            &&
            previous->type == entryType
            &&
            previous->address + previous->size == memoryDescriptor->physicalStart
           )
        {
            previous->size += memoryDescriptor->numberOfPages * PAGE_SIZE;
        }
        else
        {
            MemoryMapEntry *entry = &memoryMapEntries[memoryMapEntriesCount];

            entry->address = memoryDescriptor->physicalStart;
            entry->size    = memoryDescriptor->numberOfPages * PAGE_SIZE;
            entry->type    = entryType;

            ++memoryMapEntriesCount;

            previous = entry;
        }
    }

    params->uefi.memoryMap.map               = *bootMemoryMap->memoryMap;
    params->uefi.memoryMap.size              = *bootMemoryMap->memoryMapSize;
    params->uefi.memoryMap.descriptorSize    = *bootMemoryMap->descriptorSize;
    params->uefi.memoryMap.descriptorVersion = *bootMemoryMap->descriptorVersion;
    params->memoryMapEntriesCount            = memoryMapEntriesCount;
    params->memoryMapEntries                 = memoryMapEntries;



    UEFI_LVVV(("params->uefi.memoryMap.map               = 0x%p", params->uefi.memoryMap.map));
    UEFI_LVVV(("params->uefi.memoryMap.size              = %u",   params->uefi.memoryMap.size));
    UEFI_LVVV(("params->uefi.memoryMap.descriptorSize    = %u",   params->uefi.memoryMap.descriptorSize));
    UEFI_LVVV(("params->uefi.memoryMap.descriptorVersion = %u",   params->uefi.memoryMap.descriptorVersion));
    UEFI_LVVV(("params->memoryMapEntriesCount            = %u",   params->memoryMapEntriesCount));
    UEFI_LVVV(("params->memoryMapEntries                 = 0x%p", params->memoryMapEntries));

#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
    {
        UEFI_LVVV(("UEFI Memory Map entries:"));
        UEFI_LVVV(("-------------------------------------"));

        for (i64 i = 0; i < count; ++i)
        {
            UefiMemoryDescriptor *memoryDescriptor = MEMORY_MAP_DESCRIPTOR(bootMemoryMap, i);
            UEFI_TEST_ASSERT(memoryDescriptor, NgosStatus::ASSERTION);

            UEFI_LVVV(("#%d: type = %u | 0x%p-0x%p | 0x%016lX", i, memoryDescriptor->type, memoryDescriptor->physicalStart, memoryDescriptor->physicalStart + memoryDescriptor->numberOfPages * PAGE_SIZE, memoryDescriptor->attribute));
        }

        UEFI_LVVV(("-------------------------------------"));



        UEFI_LVVV(("Memory Map entries:"));
        UEFI_LVVV(("-------------------------------------"));

        for (i64 i = 0; i < (i64)params->memoryMapEntriesCount; ++i)
        {
            UEFI_LVVV(("#%d: type = %u | 0x%p-0x%p", i, params->memoryMapEntries[i].type, params->memoryMapEntries[i].address, params->memoryMapEntries[i].address + params->memoryMapEntries[i].size));
        }

        UEFI_LVVV(("-------------------------------------"));
    }
#endif



    UEFI_TEST_ASSERT(params->uefi.memoryMap.map               != 0,    NgosStatus::ASSERTION);
    // UEFI_TEST_ASSERT(params->uefi.memoryMap.size           == 2160, NgosStatus::ASSERTION); // Commented due to value variation
    UEFI_TEST_ASSERT(params->uefi.memoryMap.descriptorSize    == 48,   NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(params->uefi.memoryMap.descriptorVersion == 1,    NgosStatus::ASSERTION);
    UEFI_TEST_ASSERT(count                                    == 45,   NgosStatus::ASSERTION);

    // UEFI_TEST_ASSERT(params->memoryMapEntriesCount       == 10,                           NgosStatus::ASSERTION); // Commented due to value variation
    UEFI_TEST_ASSERT(params->memoryMapEntries               != 0,                            NgosStatus::ASSERTION);
    // UEFI_TEST_ASSERT(params->memoryMapEntries[0].address == 0x00000000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[0].size    == 0x000A0000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[0].type    == MemoryMapEntryType::RAM,      NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[1].address == 0x00100000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[1].size    == 0x3E9D6000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[1].type    == MemoryMapEntryType::RAM,      NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[2].address == 0x3EAD6000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[2].size    == 0x00045000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[2].type    == MemoryMapEntryType::RESERVED, NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[3].address == 0x3EB1B000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[3].size    == 0x01080000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[3].type    == MemoryMapEntryType::RAM,      NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[4].address == 0x3FB9B000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[4].size    == 0x00058000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[4].type    == MemoryMapEntryType::RESERVED, NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[5].address == 0x3FBF3000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[5].size    == 0x00008000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[5].type    == MemoryMapEntryType::ACPI,     NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[6].address == 0x3FBFB000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[6].size    == 0x00004000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[6].type    == MemoryMapEntryType::NVS,      NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[7].address == 0x3FBFF000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[7].size    == 0x003E1000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[7].type    == MemoryMapEntryType::RAM,      NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[8].address == 0x3FFE0000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[8].size    == 0x00020000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[8].type    == MemoryMapEntryType::RESERVED, NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[9].address == 0xFFE00000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[9].size    == 0x00200000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // UEFI_TEST_ASSERT(params->memoryMapEntries[9].type    == MemoryMapEntryType::RESERVED, NgosStatus::ASSERTION); // Commented due to value variation



    return NgosStatus::OK;
}
