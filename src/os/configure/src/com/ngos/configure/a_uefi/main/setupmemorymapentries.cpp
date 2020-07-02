#include "setupmemorymapentries.h"

#include <common/src/com/ngos/shared/common/page/macros.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



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
        UEFI_LVV(("Handling memory descriptor #%d at address 0x%p", i, memoryDescriptor));

        UEFI_TEST_ASSERT(memoryDescriptor, NgosStatus::ASSERTION);



        UEFI_LVVV(("type          = %us",      enumToFullString(memoryDescriptor->type)));
        UEFI_LVVV(("physicalStart = 0x%p",     memoryDescriptor->physicalStart));
        UEFI_LVVV(("virtualStart  = 0x%p",     memoryDescriptor->virtualStart));
        UEFI_LVVV(("numberOfPages = %u",       memoryDescriptor->numberOfPages));
        UEFI_LVVV(("attribute     = 0x%016lX", memoryDescriptor->attribute));



        MemoryMapEntryType entryType;

        switch (memoryDescriptor->type)
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
                UEFI_LF(("Unexpected memory descriptor type %s, %s:%u", enumToFullString(memoryDescriptor->type), __FILE__, __LINE__));

                return NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;

            default:
            {
                UEFI_LF(("Unknown memory descriptor type %s, %s:%u", enumToFullString(memoryDescriptor->type), __FILE__, __LINE__));

                return NgosStatus::UNEXPECTED_BEHAVIOUR;
            }
            break;
        }



        if (
            previous
            &&
            previous->type == entryType
            &&
            previous->end() == memoryDescriptor->physicalStart
           )
        {
            previous->size += memoryDescriptor->numberOfPages * PAGE_SIZE;
        }
        else
        {
            MemoryMapEntry *entry = &memoryMapEntries[memoryMapEntriesCount];

            entry->start = memoryDescriptor->physicalStart;
            entry->size  = memoryDescriptor->numberOfPages * PAGE_SIZE;
            entry->type  = entryType;

            ++memoryMapEntriesCount;

            previous = entry;
        }
    }

    params->uefi.memoryMap.map               = *bootMemoryMap->memoryMap;
    params->uefi.memoryMap.size              = *bootMemoryMap->memoryMapSize;
    params->uefi.memoryMap.descriptorSize    = *bootMemoryMap->descriptorSize;
    params->uefi.memoryMap.descriptorVersion = *bootMemoryMap->descriptorVersion;
    params->uefi.systemTable                 = UEFI::getSystemTable();
    params->memoryMapEntriesCount            = memoryMapEntriesCount;
    params->memoryMapEntries                 = memoryMapEntries;



    // Validation
    {
        UEFI_LVVV(("params->uefi.memoryMap.map               = 0x%p", params->uefi.memoryMap.map));
        UEFI_LVVV(("params->uefi.memoryMap.size              = %u",   params->uefi.memoryMap.size));
        UEFI_LVVV(("params->uefi.memoryMap.descriptorSize    = %u",   params->uefi.memoryMap.descriptorSize));
        UEFI_LVVV(("params->uefi.memoryMap.descriptorVersion = %u",   params->uefi.memoryMap.descriptorVersion));
        UEFI_LVVV(("params->uefi.systemTable                 = 0x%p", params->uefi.systemTable));
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

                UEFI_LVVV(("#%-3d: type = %-27s | 0x%p-0x%p | 0x%016lX", i, enumToFullString(memoryDescriptor->type), memoryDescriptor->physicalStart, memoryDescriptor->physicalStart + memoryDescriptor->numberOfPages * PAGE_SIZE, memoryDescriptor->attribute));
            }

            UEFI_LVVV(("-------------------------------------"));



            UEFI_LVVV(("Memory Map entries:"));
            UEFI_LVVV(("-------------------------------------"));

            for (i64 i = 0; i < (i64)params->memoryMapEntriesCount; ++i)
            {
                UEFI_LVVV(("#%-3d: type = %-2u | 0x%p-0x%p", i, params->memoryMapEntries[i].type, params->memoryMapEntries[i].start, params->memoryMapEntries[i].end()));
            }

            UEFI_LVVV(("-------------------------------------"));
        }
#endif



        UEFI_TEST_ASSERT(params->uefi.memoryMap.map                                 != 0,                                     NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(params->uefi.memoryMap.size                             == 2160,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(params->uefi.memoryMap.descriptorSize                   == 48,                                    NgosStatus::ASSERTION); // Commented due to value variation
        UEFI_TEST_ASSERT(params->uefi.memoryMap.descriptorVersion                   == 1,                                     NgosStatus::ASSERTION);
        UEFI_TEST_ASSERT(params->uefi.systemTable                                   != 0,                                     NgosStatus::ASSERTION);
        // UEFI_TEST_ASSERT(count                                                   == 45,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 0)->type           == UefiMemoryType::BOOT_SERVICES_CODE,    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 0)->physicalStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 0)->virtualStart   == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 0)->numberOfPages  == 1,                                     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 0)->attribute      == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 1)->type           == UefiMemoryType::LOADER_DATA,           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 1)->physicalStart  == 0x0000000000001000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 1)->virtualStart   == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 1)->numberOfPages  == 1,                                     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 1)->attribute      == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 2)->type           == UefiMemoryType::CONVENTIONAL_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 2)->physicalStart  == 0x0000000000002000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 2)->virtualStart   == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 2)->numberOfPages  == 158,                                   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 2)->attribute      == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 3)->type           == UefiMemoryType::CONVENTIONAL_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 3)->physicalStart  == 0x0000000000100000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 3)->virtualStart   == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 3)->numberOfPages  == 256,                                   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 3)->attribute      == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 4)->type           == UefiMemoryType::LOADER_DATA,           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 4)->physicalStart  == 0x0000000000200000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 4)->virtualStart   == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 4)->numberOfPages  == 1300,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 4)->attribute      == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 5)->type           == UefiMemoryType::CONVENTIONAL_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 5)->physicalStart  == 0x0000000000714000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 5)->virtualStart   == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 5)->numberOfPages  == 242,                                   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 5)->attribute      == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 6)->type           == UefiMemoryType::BOOT_SERVICES_DATA,    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 6)->physicalStart  == 0x0000000000806000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 6)->virtualStart   == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 6)->numberOfPages  == 1,                                     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 6)->attribute      == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 7)->type           == UefiMemoryType::CONVENTIONAL_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 7)->physicalStart  == 0x0000000000807000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 7)->virtualStart   == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 7)->numberOfPages  == 25,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 7)->attribute      == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 8)->type           == UefiMemoryType::BOOT_SERVICES_DATA,    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 8)->physicalStart  == 0x0000000000820000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 8)->virtualStart   == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 8)->numberOfPages  == 3040,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 8)->attribute      == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 9)->type           == UefiMemoryType::CONVENTIONAL_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 9)->physicalStart  == 0x0000000001400000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 9)->virtualStart   == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 9)->numberOfPages  == 240574,                                NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 9)->attribute      == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 10)->type          == UefiMemoryType::BOOT_SERVICES_DATA,    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 10)->physicalStart == 0x000000003BFBE000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 10)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 10)->numberOfPages == 32,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 10)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 11)->type          == UefiMemoryType::CONVENTIONAL_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 11)->physicalStart == 0x000000003BFDE000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 11)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 11)->numberOfPages == 9062,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 11)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 12)->type          == UefiMemoryType::LOADER_DATA,           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 12)->physicalStart == 0x000000003E344000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 12)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 12)->numberOfPages == 72,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 12)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 13)->type          == UefiMemoryType::LOADER_CODE,           NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 13)->physicalStart == 0x000000003E38C000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 13)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 13)->numberOfPages == 209,                                   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 13)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 14)->type          == UefiMemoryType::BOOT_SERVICES_DATA,    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 14)->physicalStart == 0x000000003E45D000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 14)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 14)->numberOfPages == 1153,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 14)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 15)->type          == UefiMemoryType::BOOT_SERVICES_CODE,    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 15)->physicalStart == 0x000000003E8DE000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 15)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 15)->numberOfPages == 504,                                   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 15)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 16)->type          == UefiMemoryType::RUNTIME_SERVICES_DATA, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 16)->physicalStart == 0x000000003EAD6000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 16)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 16)->numberOfPages == 5,                                     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 16)->attribute     == 0x800000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 17)->type          == UefiMemoryType::RUNTIME_SERVICES_CODE, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 17)->physicalStart == 0x000000003EADB000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 17)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 17)->numberOfPages == 5,                                     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 17)->attribute     == 0x800000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 18)->type          == UefiMemoryType::RUNTIME_SERVICES_DATA, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 18)->physicalStart == 0x000000003EAE0000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 18)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 18)->numberOfPages == 5,                                     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 18)->attribute     == 0x800000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 19)->type          == UefiMemoryType::RUNTIME_SERVICES_CODE, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 19)->physicalStart == 0x000000003EAE5000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 19)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 19)->numberOfPages == 5,                                     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 19)->attribute     == 0x800000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 20)->type          == UefiMemoryType::RUNTIME_SERVICES_DATA, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 20)->physicalStart == 0x000000003EAEA000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 20)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 20)->numberOfPages == 5,                                     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 20)->attribute     == 0x800000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 21)->type          == UefiMemoryType::RUNTIME_SERVICES_CODE, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 21)->physicalStart == 0x000000003EAEF000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 21)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 21)->numberOfPages == 7,                                     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 21)->attribute     == 0x800000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 22)->type          == UefiMemoryType::RUNTIME_SERVICES_DATA, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 22)->physicalStart == 0x000000003EAF6000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 22)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 22)->numberOfPages == 37,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 22)->attribute     == 0x800000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 23)->type          == UefiMemoryType::CONVENTIONAL_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 23)->physicalStart == 0x000000003EB1B000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 23)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 23)->numberOfPages == 786,                                   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 23)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 24)->type          == UefiMemoryType::BOOT_SERVICES_DATA,    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 24)->physicalStart == 0x000000003EE2D000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 24)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 24)->numberOfPages == 261,                                   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 24)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 25)->type          == UefiMemoryType::CONVENTIONAL_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 25)->physicalStart == 0x000000003EF32000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 25)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 25)->numberOfPages == 4,                                     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 25)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 26)->type          == UefiMemoryType::BOOT_SERVICES_DATA,    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 26)->physicalStart == 0x000000003EF36000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 26)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 26)->numberOfPages == 2,                                     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 26)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 27)->type          == UefiMemoryType::CONVENTIONAL_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 27)->physicalStart == 0x000000003EF38000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 27)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 27)->numberOfPages == 1,                                     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 27)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 28)->type          == UefiMemoryType::BOOT_SERVICES_DATA,    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 28)->physicalStart == 0x000000003EF39000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 28)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 28)->numberOfPages == 121,                                   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 28)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 29)->type          == UefiMemoryType::CONVENTIONAL_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 29)->physicalStart == 0x000000003EFB2000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 29)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 29)->numberOfPages == 1,                                     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 29)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 30)->type          == UefiMemoryType::BOOT_SERVICES_DATA,    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 30)->physicalStart == 0x000000003EFB3000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 30)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 30)->numberOfPages == 2664,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 30)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 31)->type          == UefiMemoryType::BOOT_SERVICES_CODE,    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 31)->physicalStart == 0x000000003FA1B000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 31)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 31)->numberOfPages == 384,                                   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 31)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 32)->type          == UefiMemoryType::RUNTIME_SERVICES_CODE, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 32)->physicalStart == 0x000000003FB9B000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 32)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 32)->numberOfPages == 48,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 32)->attribute     == 0x800000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 33)->type          == UefiMemoryType::RUNTIME_SERVICES_DATA, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 33)->physicalStart == 0x000000003FBCB000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 33)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 33)->numberOfPages == 36,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 33)->attribute     == 0x800000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 34)->type          == UefiMemoryType::RESERVED_MEMORY,       NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 34)->physicalStart == 0x000000003FBEF000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 34)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 34)->numberOfPages == 4,                                     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 34)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 35)->type          == UefiMemoryType::ACPI_RECLAIM_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 35)->physicalStart == 0x000000003FBF3000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 35)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 35)->numberOfPages == 8,                                     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 35)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 36)->type          == UefiMemoryType::ACPI_MEMORY_NVS,       NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 36)->physicalStart == 0x000000003FBFB000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 36)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 36)->numberOfPages == 4,                                     NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 36)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 37)->type          == UefiMemoryType::BOOT_SERVICES_DATA,    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 37)->physicalStart == 0x000000003FBFF000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 37)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 37)->numberOfPages == 513,                                   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 37)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 38)->type          == UefiMemoryType::CONVENTIONAL_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 38)->physicalStart == 0x000000003FE00000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 38)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 38)->numberOfPages == 347,                                   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 38)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 39)->type          == UefiMemoryType::BOOT_SERVICES_DATA,    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 39)->physicalStart == 0x000000003FF5B000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 39)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 39)->numberOfPages == 32,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 39)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 40)->type          == UefiMemoryType::BOOT_SERVICES_CODE,    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 40)->physicalStart == 0x000000003FF7B000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 40)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 40)->numberOfPages == 37,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 40)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 41)->type          == UefiMemoryType::BOOT_SERVICES_DATA,    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 41)->physicalStart == 0x000000003FFA0000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 41)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 41)->numberOfPages == 33,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 41)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 42)->type          == UefiMemoryType::BOOT_SERVICES_CODE,    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 42)->physicalStart == 0x000000003FFC1000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 42)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 42)->numberOfPages == 31,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 42)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 43)->type          == UefiMemoryType::RUNTIME_SERVICES_DATA, NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 43)->physicalStart == 0x000000003FFE0000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 43)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 43)->numberOfPages == 32,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 43)->attribute     == 0x800000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 44)->type          == UefiMemoryType::MEMORY_MAPPED_IO,      NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 44)->physicalStart == 0x00000000FFE00000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 44)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 44)->numberOfPages == 512,                                   NgosStatus::ASSERTION); // Commented due to value variation
        // UEFI_TEST_ASSERT(MEMORY_MAP_DESCRIPTOR(bootMemoryMap, 44)->attribute     == 0x8000000000000001,                    NgosStatus::ASSERTION); // Commented due to value variation

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
    }



    return NgosStatus::OK;
}
