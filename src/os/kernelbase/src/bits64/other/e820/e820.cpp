#include "e820.h"

#include <src/bits64/log/assert.h>
#include <src/bits64/log/log.h>
#include <src/bits64/memory/memory.h>
#include <src/bits64/other/bootparams/bootparams.h>
#include <src/bits64/other/pagetable/dynamicpagetable.h>



E820Table E820::sTable;
E820Table E820::sTableKExec;
E820Table E820::sTableFirmware;



NgosStatus E820::init()
{
    COMMON_LT((""));



    u64 memoryMapEntriesSize = bootParams.memoryMapEntriesCount * sizeof(bootParams.memoryMapEntries[0]);



    COMMON_ASSERT_EXECUTION(addDynamicIdentityMap((u64)bootParams.memoryMapEntries, (u64)bootParams.memoryMapEntries + memoryMapEntriesSize), NgosStatus::ASSERTION);

    sTable.count         = bootParams.memoryMapEntriesCount;
    sTableKExec.count    = bootParams.memoryMapEntriesCount;
    sTableFirmware.count = bootParams.memoryMapEntriesCount;

    memcpy(sTable.entries,         bootParams.memoryMapEntries, memoryMapEntriesSize);
    memcpy(sTableKExec.entries,    bootParams.memoryMapEntries, memoryMapEntriesSize);
    memcpy(sTableFirmware.entries, bootParams.memoryMapEntries, memoryMapEntriesSize);

    COMMON_ASSERT_EXECUTION(clearDynamicIdentityMap((u64)bootParams.memoryMapEntries, (u64)bootParams.memoryMapEntries + memoryMapEntriesSize), NgosStatus::ASSERTION);



    COMMON_LVVV(("sTable.count         = %u", sTable.count));
    COMMON_LVVV(("sTableKExec.count    = %u", sTableKExec.count));
    COMMON_LVVV(("sTableFirmware.count = %u", sTableFirmware.count));

#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
    {
        COMMON_LVVV(("sTable.entries:"));
        COMMON_LVVV(("-------------------------------------"));

        for (i64 i = 0; i < (i64)sTable.count; ++i)
        {
            COMMON_LVVV(("#%d: type = %20s | 0x%p-0x%p", i, getTypeName(sTable.entries[i].type), sTable.entries[i].address, sTable.entries[i].address + sTable.entries[i].size));
        }

        COMMON_LVVV(("-------------------------------------"));



        COMMON_LVVV(("sTableKExec.entries:"));
        COMMON_LVVV(("-------------------------------------"));

        for (i64 i = 0; i < (i64)sTableKExec.count; ++i)
        {
            COMMON_LVVV(("#%d: type = %20s | 0x%p-0x%p", i, getTypeName(sTableKExec.entries[i].type), sTableKExec.entries[i].address, sTableKExec.entries[i].address + sTableKExec.entries[i].size));
        }

        COMMON_LVVV(("-------------------------------------"));



        COMMON_LVVV(("sTableFirmware.entries:"));
        COMMON_LVVV(("-------------------------------------"));

        for (i64 i = 0; i < (i64)sTableFirmware.count; ++i)
        {
            COMMON_LVVV(("#%d: type = %20s | 0x%p-0x%p", i, getTypeName(sTableFirmware.entries[i].type), sTableFirmware.entries[i].address, sTableFirmware.entries[i].address + sTableFirmware.entries[i].size));
        }

        COMMON_LVVV(("-------------------------------------"));
    }
#endif



    COMMON_TEST_ASSERT(sTable.count         <= E820_TABLE_SIZE, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sTableKExec.count    <= E820_TABLE_SIZE, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sTableFirmware.count <= E820_TABLE_SIZE, NgosStatus::ASSERTION);

    // COMMON_TEST_ASSERT(sTable.count              == 10,                           NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[0].address == 0x00000000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[0].size    == 0x000A0000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[0].type    == MemoryMapEntryType::RAM,      NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[1].address == 0x00100000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[1].size    == 0x3E9D6000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[1].type    == MemoryMapEntryType::RAM,      NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[2].address == 0x3EAD6000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[2].size    == 0x00045000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[2].type    == MemoryMapEntryType::RESERVED, NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[3].address == 0x3EB1B000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[3].size    == 0x01080000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[3].type    == MemoryMapEntryType::RAM,      NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[4].address == 0x3FB9B000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[4].size    == 0x00058000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[4].type    == MemoryMapEntryType::RESERVED, NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[5].address == 0x3FBF3000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[5].size    == 0x00008000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[5].type    == MemoryMapEntryType::ACPI,     NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[6].address == 0x3FBFB000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[6].size    == 0x00004000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[6].type    == MemoryMapEntryType::NVS,      NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[7].address == 0x3FBFF000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[7].size    == 0x003E1000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[7].type    == MemoryMapEntryType::RAM,      NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[8].address == 0x3FFE0000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[8].size    == 0x00020000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[8].type    == MemoryMapEntryType::RESERVED, NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[9].address == 0xFFE00000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[9].size    == 0x00200000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTable.entries[9].type    == MemoryMapEntryType::RESERVED, NgosStatus::ASSERTION); // Commented due to value variation

    // COMMON_TEST_ASSERT(sTableKExec.count              == 10,                           NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[0].address == 0x00000000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[0].size    == 0x000A0000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[0].type    == MemoryMapEntryType::RAM,      NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[1].address == 0x00100000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[1].size    == 0x3E9D6000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[1].type    == MemoryMapEntryType::RAM,      NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[2].address == 0x3EAD6000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[2].size    == 0x00045000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[2].type    == MemoryMapEntryType::RESERVED, NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[3].address == 0x3EB1B000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[3].size    == 0x01080000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[3].type    == MemoryMapEntryType::RAM,      NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[4].address == 0x3FB9B000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[4].size    == 0x00058000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[4].type    == MemoryMapEntryType::RESERVED, NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[5].address == 0x3FBF3000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[5].size    == 0x00008000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[5].type    == MemoryMapEntryType::ACPI,     NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[6].address == 0x3FBFB000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[6].size    == 0x00004000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[6].type    == MemoryMapEntryType::NVS,      NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[7].address == 0x3FBFF000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[7].size    == 0x003E1000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[7].type    == MemoryMapEntryType::RAM,      NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[8].address == 0x3FFE0000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[8].size    == 0x00020000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[8].type    == MemoryMapEntryType::RESERVED, NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[9].address == 0xFFE00000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[9].size    == 0x00200000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableKExec.entries[9].type    == MemoryMapEntryType::RESERVED, NgosStatus::ASSERTION); // Commented due to value variation

    // COMMON_TEST_ASSERT(sTableFirmware.count              == 10,                           NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[0].address == 0x00000000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[0].size    == 0x000A0000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[0].type    == MemoryMapEntryType::RAM,      NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[1].address == 0x00100000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[1].size    == 0x3E9D6000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[1].type    == MemoryMapEntryType::RAM,      NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[2].address == 0x3EAD6000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[2].size    == 0x00045000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[2].type    == MemoryMapEntryType::RESERVED, NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[3].address == 0x3EB1B000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[3].size    == 0x01080000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[3].type    == MemoryMapEntryType::RAM,      NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[4].address == 0x3FB9B000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[4].size    == 0x00058000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[4].type    == MemoryMapEntryType::RESERVED, NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[5].address == 0x3FBF3000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[5].size    == 0x00008000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[5].type    == MemoryMapEntryType::ACPI,     NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[6].address == 0x3FBFB000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[6].size    == 0x00004000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[6].type    == MemoryMapEntryType::NVS,      NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[7].address == 0x3FBFF000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[7].size    == 0x003E1000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[7].type    == MemoryMapEntryType::RAM,      NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[8].address == 0x3FFE0000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[8].size    == 0x00020000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[8].type    == MemoryMapEntryType::RESERVED, NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[9].address == 0xFFE00000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[9].size    == 0x00200000,                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sTableFirmware.entries[9].type    == MemoryMapEntryType::RESERVED, NgosStatus::ASSERTION); // Commented due to value variation



    return NgosStatus::OK;
}

const char* E820::getTypeName(MemoryMapEntryType type)
{
    COMMON_LT((" | type = %u", type));

    switch (type)
    {
        case MemoryMapEntryType::RAM:               return "RAM";
        case MemoryMapEntryType::ACPI:              return "ACPI";
        case MemoryMapEntryType::NVS:               return "NVS";
        case MemoryMapEntryType::PERSISTENT_MEMORY: return "PERSISTENT_MEMORY";
        case MemoryMapEntryType::UNUSABLE:          return "UNUSABLE";
        case MemoryMapEntryType::RESERVED:          return "RESERVED";

        default:
        {
            COMMON_LF(("Unknown E820 type: %u", type));

            return "UNKNOWN";
        }
        break;
    }
}
