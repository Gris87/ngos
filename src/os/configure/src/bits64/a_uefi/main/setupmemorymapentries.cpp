#include "setupmemorymapentries.h"

#include "src/bits64/a_uefi/uefi/lib/eficonstants.h"
#include "src/bits64/a_uefi/uefi/uefiassert.h"
#include "src/bits64/a_uefi/uefi/uefilog.h"



NgosStatus setupMemoryMapEntries(BootParams *params, UefiBootMemoryMap *bootMemoryMap, MemoryMapEntry *memoryMapEntries)
{
    UEFI_LT((" | params = 0x%p, bootMemoryMap = 0x%p, memoryMapEntries = 0x%ps", params, bootMemoryMap, memoryMapEntries));

    UEFI_ASSERT(params,           "params is null",           NgosStatus::ASSERTION);
    UEFI_ASSERT(bootMemoryMap,    "bootMemoryMap is null",    NgosStatus::ASSERTION);
    UEFI_ASSERT(memoryMapEntries, "memoryMapEntries is null", NgosStatus::ASSERTION);



    MemoryMapEntry *previous              = 0;
    u64             memoryMapEntriesCount = 0;



    i64 count = (*bootMemoryMap->memoryMapSize) / (*bootMemoryMap->descriptorSize);
    UEFI_LVVV(("count = %d", count));

    for (i64 i = 0; i < count; ++i)
    {
        EfiMemoryDescriptor *memoryDescriptor = (EfiMemoryDescriptor *)((u64)(*bootMemoryMap->memoryMap) + (i * (*bootMemoryMap->descriptorSize)));
        UEFI_LVV(("Handling memory descriptor 0x%p", memoryDescriptor));

        UEFI_TEST_ASSERT(memoryDescriptor, NgosStatus::ASSERTION);



        UEFI_LVVV(("type          = %u",   memoryDescriptor->type));
        UEFI_LVVV(("physicalStart = 0x%p", memoryDescriptor->physicalStart));
        UEFI_LVVV(("virtualStart  = 0x%p", memoryDescriptor->virtualStart));
        UEFI_LVVV(("numberOfPages = %u",   memoryDescriptor->numberOfPages));
        UEFI_LVVV(("attribute     = %u",   memoryDescriptor->attribute));



        MemoryMapEntryType entryType;

        switch ((EfiMemoryType)memoryDescriptor->type)
        {
            case EfiMemoryType::RESERVED_MEMORY:
            case EfiMemoryType::RUNTIME_SERVICES_CODE:
            case EfiMemoryType::RUNTIME_SERVICES_DATA:
            case EfiMemoryType::MEMORY_MAPPED_IO:
            case EfiMemoryType::MEMORY_MAPPED_IO_PORT_SPACE:
            case EfiMemoryType::PAL_CODE:
            {
                entryType = MemoryMapEntryType::RESERVED;
            }
            break;

            case EfiMemoryType::UNUSABLE_MEMORY:
            {
                entryType = MemoryMapEntryType::UNUSABLE;
            }
            break;

            case EfiMemoryType::ACPI_RECLAIM_MEMORY:
            {
                entryType = MemoryMapEntryType::ACPI;
            }
            break;

            case EfiMemoryType::LOADER_CODE:
            case EfiMemoryType::LOADER_DATA:
            case EfiMemoryType::BOOT_SERVICES_CODE:
            case EfiMemoryType::BOOT_SERVICES_DATA:
            case EfiMemoryType::CONVENTIONAL_MEMORY:
            {
                entryType = MemoryMapEntryType::RAM;
            }
            break;

            case EfiMemoryType::ACPI_MEMORY_NVS:
            {
                entryType = MemoryMapEntryType::NVS;
            }
            break;

            case EfiMemoryType::PERSISTENT_MEMORY:
            {
                entryType = MemoryMapEntryType::PERSISTENT_MEMORY;
            }
            break;

            case EfiMemoryType::MAXIMUM:
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
            previous->size += memoryDescriptor->numberOfPages * EFI_PAGE_SIZE;
        }
        else
        {
            MemoryMapEntry *entry = &memoryMapEntries[memoryMapEntriesCount];

            entry->address = memoryDescriptor->physicalStart;
            entry->size    = memoryDescriptor->numberOfPages * EFI_PAGE_SIZE;
            entry->type    = entryType;

            ++memoryMapEntriesCount;

            previous = entry;
        }
    }

    params->memoryMapEntriesCount = memoryMapEntriesCount;
    params->memoryMapEntries      = memoryMapEntries;



    UEFI_LVVV(("params->memoryMapEntriesCount = %u",   params->memoryMapEntriesCount));
    UEFI_LVVV(("params->memoryMapEntries      = 0x%p", params->memoryMapEntries));

#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
    {
        UEFI_LVVV(("Memory Map entries:"));
        UEFI_LVVV(("-------------------------------------"));

        for (i64 i = 0; i < (i64)params->memoryMapEntriesCount; ++i)
        {
            UEFI_LVVV(("#%d: type = %u | 0x%p-0x%p", i, params->memoryMapEntries[i].type, params->memoryMapEntries[i].address, params->memoryMapEntries[i].address + params->memoryMapEntries[i].size));
        }

        UEFI_LVVV(("-------------------------------------"));
    }
#endif



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
