#include "e820.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/memory.h>
#include <kernelbase/src/bits64/other/bootparams/bootparams.h>
#include <kernelbase/src/bits64/other/pagetable/dynamicpagetable.h>



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
            COMMON_LVVV(("#%-3d: type = %20s | 0x%p-0x%p", i, getTypeName(sTable.entries[i].type), sTable.entries[i].start, sTable.entries[i].end()));
        }

        COMMON_LVVV(("-------------------------------------"));



        COMMON_LVVV(("sTableKExec.entries:"));
        COMMON_LVVV(("-------------------------------------"));

        for (i64 i = 0; i < (i64)sTableKExec.count; ++i)
        {
            COMMON_LVVV(("#%-3d: type = %20s | 0x%p-0x%p", i, getTypeName(sTableKExec.entries[i].type), sTableKExec.entries[i].start, sTableKExec.entries[i].end()));
        }

        COMMON_LVVV(("-------------------------------------"));



        COMMON_LVVV(("sTableFirmware.entries:"));
        COMMON_LVVV(("-------------------------------------"));

        for (i64 i = 0; i < (i64)sTableFirmware.count; ++i)
        {
            COMMON_LVVV(("#%-3d: type = %20s | 0x%p-0x%p", i, getTypeName(sTableFirmware.entries[i].type), sTableFirmware.entries[i].start, sTableFirmware.entries[i].end()));
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

NgosStatus E820::updateRange(u64 start, u64 size, MemoryMapEntryType oldType, MemoryMapEntryType newType)
{
    COMMON_LT((" | start = 0x%016lX, size = 0x%016lX, oldType = %u, newType = %u", start, size, oldType, newType));

    COMMON_ASSERT(size > 0,             "size is zero",       NgosStatus::ASSERTION);
    COMMON_ASSERT(start + size > start, "size is invalid",    NgosStatus::ASSERTION);
    COMMON_ASSERT(oldType != newType,   "types are the same", NgosStatus::ASSERTION);



    return updateRangeInTable(&sTable, start, size, oldType, newType);
}

NgosStatus E820::updateRangeKExec(u64 start, u64 size, MemoryMapEntryType oldType, MemoryMapEntryType newType)
{
    COMMON_LT((" | start = 0x%016lX, size = 0x%016lX, oldType = %u, newType = %u", start, size, oldType, newType));

    COMMON_ASSERT(size > 0,             "size is zero",       NgosStatus::ASSERTION);
    COMMON_ASSERT(start + size > start, "size is invalid",    NgosStatus::ASSERTION);
    COMMON_ASSERT(oldType != newType,   "types are the same", NgosStatus::ASSERTION);



    return updateRangeInTable(&sTableKExec, start, size, oldType, newType);
}

const char* E820::getTypeName(MemoryMapEntryType type)
{
    COMMON_LT((" | type = %u", type));



    switch (type)
    {
        case MemoryMapEntryType::RAM:                return "RAM";
        case MemoryMapEntryType::ACPI:               return "ACPI";
        case MemoryMapEntryType::NVS:                return "NVS";
        case MemoryMapEntryType::PERSISTENT_MEMORY:  return "PERSISTENT_MEMORY";
        case MemoryMapEntryType::UNUSABLE:           return "UNUSABLE";
        case MemoryMapEntryType::RESERVED:           return "RESERVED";
        case MemoryMapEntryType::RESERVED_BY_KERNEL: return "RESERVED_BY_KERNEL";

        default:
        {
            COMMON_LF(("Unknown E820 type: %u", type));

            return "UNKNOWN";
        }
        break;
    }
}

NgosStatus E820::insertRangeInTable(E820Table *table, u64 index, u64 start, u64 size, MemoryMapEntryType type)
{
    COMMON_LT((" | table = 0x%p, index = %u, start = 0x%016lX, size = 0x%016lX, type = %u", table, index, start, size, type));

    COMMON_ASSERT(table,                          "table is null",    NgosStatus::ASSERTION);
    COMMON_ASSERT(table->count < E820_TABLE_SIZE, "table is full",    NgosStatus::ASSERTION);
    COMMON_ASSERT(index <= table->count,          "index is invalid", NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0,                       "size is zero",     NgosStatus::ASSERTION);
    COMMON_ASSERT(start + size > start,           "size is invalid",  NgosStatus::ASSERTION);



    memmove(&table->entries[index + 1], &table->entries[index], (table->count - index) * sizeof(MemoryMapEntry));



    MemoryMapEntry &entry = table->entries[index];

    entry.start = start;
    entry.size  = size;
    entry.type  = type;

    ++table->count;



    return NgosStatus::OK;
}

NgosStatus E820::removeRangeInTable(E820Table *table, u64 index)
{
    COMMON_LT((" | table = 0x%p, index = %u", table, index));

    COMMON_ASSERT(table,                "table is null",    NgosStatus::ASSERTION);
    COMMON_ASSERT(table->count > 0,     "type is empty",    NgosStatus::ASSERTION);
    COMMON_ASSERT(index < table->count, "index is invalid", NgosStatus::ASSERTION);



    memmove(&table->entries[index], &table->entries[index + 1], (table->count - (index + 1)) * sizeof(MemoryMapEntry));

    --table->count;



    return NgosStatus::OK;
}

NgosStatus E820::updateRangeInTable(E820Table *table, u64 start, u64 size, MemoryMapEntryType oldType, MemoryMapEntryType newType)
{
    COMMON_LT((" | table = 0x%p, start = 0x%016lX, size = 0x%016lX, oldType = %u, newType = %u", table, start, size, oldType, newType));

    COMMON_ASSERT(table,                "table is null",      NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0,             "size is zero",       NgosStatus::ASSERTION);
    COMMON_ASSERT(start + size > start, "size is invalid",    NgosStatus::ASSERTION);
    COMMON_ASSERT(oldType != newType,   "types are the same", NgosStatus::ASSERTION);



    u64 end = start + size;

    COMMON_LVV(("Converting memory type %s to %s for E820 range: 0x%p-0x%p", getTypeName(oldType), getTypeName(newType), start, end));



    u64 left  = 0;
    u64 right = table->count;

    while (left < right)
    {
        u64 middle = (left + right) >> 1; // ">> 1" == "/ 2"

        MemoryMapEntry &entry = table->entries[middle];



        if (start < entry.end())
        {
            right = middle;
        }
        else
        {
            left = middle + 1;
        }
    }



    // COMMON_LVVV(("left  = %u", left));  // Commented to avoid too frequent logs
    // COMMON_LVVV(("right = %u", right)); // Commented to avoid too frequent logs

    COMMON_TEST_ASSERT(left == right, NgosStatus::ASSERTION);

    if (left >= table->count)
    {
        return NgosStatus::OK;
    }



    for (i64 i = left; i < (i64)table->count; ++i)
    {
        MemoryMapEntry &entry = table->entries[i];



        if (entry.start >= end)
        {
            break;
        }



        if (entry.type != oldType)
        {
            continue;
        }



        u64 entryEnd = entry.end();



        if (start >= entryEnd)
        {
            continue;
        }



        // Entry is fully covered by specified range
        if (entry.start >= start && entryEnd <= end)
        {
            entry.type = newType;

            continue;
        }



        // Specified range is fully covered by entry
        if (entry.start < start && entryEnd > end)
        {
            COMMON_ASSERT_EXECUTION(insertRangeInTable(table, i + 1, start, size,           newType), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(insertRangeInTable(table, i + 2, end,   entryEnd - end, oldType), NgosStatus::ASSERTION);

            entry.size = start - entry.start;

            continue;
        }



        // Partially covered
        if (entry.start < start)
        {
            COMMON_ASSERT_EXECUTION(insertRangeInTable(table, i + 1, start, entryEnd - start, newType), NgosStatus::ASSERTION);

            entry.size = start - entry.start;
        }
        else
        {
            COMMON_TEST_ASSERT(entryEnd > end, NgosStatus::ASSERTION);



            u64 entryStartOrig = entry.start;

            entry.start = end;
            entry.size  = entryEnd - end;

            COMMON_ASSERT_EXECUTION(insertRangeInTable(table, i, entryStartOrig, end - entryStartOrig, newType), NgosStatus::ASSERTION);
        }
    }



    // ------------------------------------------------------------------------------
    // Merge processed entries
    // ------------------------------------------------------------------------------



    i64 index = left > 0 ? left - 1 : 0;

    while (index < (i64)table->count - 1)
    {
        MemoryMapEntry &currentEntry = table->entries[index];
        MemoryMapEntry &nextEntry    = table->entries[index + 1];



        if (currentEntry.start >= end)
        {
            break;
        }



        if (
            currentEntry.end() == nextEntry.start
            &&
            currentEntry.type == nextEntry.type
           )
        {
            currentEntry.size += nextEntry.size;

            memmove(&table->entries[index + 1], &table->entries[index + 2], (table->count - (index + 2)) * sizeof(MemoryMapEntry));

            --table->count;
        }
        else
        {
            COMMON_TEST_ASSERT(currentEntry.end() <= nextEntry.start, NgosStatus::ASSERTION);

            ++index;
        }
    }



    return NgosStatus::OK;
}
