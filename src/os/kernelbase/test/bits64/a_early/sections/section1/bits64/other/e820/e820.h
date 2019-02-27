#ifndef OS_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_BITS64_OTHER_E820_E820_H
#define OS_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_BITS64_OTHER_E820_E820_H



#include <buildconfig.h>
#include <src/bits64/other/e820/e820.h>
#include <test/bits64/a_early/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section1, bits64_other_e820_e820);
{
    TEST_CASE("updateRangeInTable()");
    {
        E820Table table;

        table.count = 0;

        TEST_ASSERT_EQUALS(E820::insertRangeInTable(&table, 0, 0x2000, 0x1000, MemoryMapEntryType::RAM), NgosStatus::OK);
        TEST_ASSERT_EQUALS(table.count,                                                                  1);
        TEST_ASSERT_EQUALS(table.entries[0].start,                                                       0x2000);
        TEST_ASSERT_EQUALS(table.entries[0].size,                                                        0x1000);
        TEST_ASSERT_EQUALS(table.entries[0].type,                                                        MemoryMapEntryType::RAM);

        TEST_ASSERT_EQUALS(E820::insertRangeInTable(&table, 0, 0x5000, 0x4000, MemoryMapEntryType::NVS), NgosStatus::OK);
        TEST_ASSERT_EQUALS(table.count,                                                                  2);
        TEST_ASSERT_EQUALS(table.entries[0].start,                                                       0x5000);
        TEST_ASSERT_EQUALS(table.entries[0].size,                                                        0x4000);
        TEST_ASSERT_EQUALS(table.entries[0].type,                                                        MemoryMapEntryType::NVS);
        TEST_ASSERT_EQUALS(table.entries[1].start,                                                       0x2000);
        TEST_ASSERT_EQUALS(table.entries[1].size,                                                        0x1000);
        TEST_ASSERT_EQUALS(table.entries[1].type,                                                        MemoryMapEntryType::RAM);

        TEST_ASSERT_EQUALS(E820::insertRangeInTable(&table, 1, 0xA000, 0x2000, MemoryMapEntryType::RESERVED), NgosStatus::OK);
        TEST_ASSERT_EQUALS(table.count,                                                                       3);
        TEST_ASSERT_EQUALS(table.entries[0].start,                                                            0x5000);
        TEST_ASSERT_EQUALS(table.entries[0].size,                                                             0x4000);
        TEST_ASSERT_EQUALS(table.entries[0].type,                                                         MemoryMapEntryType::NVS);
        TEST_ASSERT_EQUALS(table.entries[1].start,                                                            0xA000);
        TEST_ASSERT_EQUALS(table.entries[1].size,                                                             0x2000);
        TEST_ASSERT_EQUALS(table.entries[1].type,                                                             MemoryMapEntryType::RESERVED);
        TEST_ASSERT_EQUALS(table.entries[2].start,                                                            0x2000);
        TEST_ASSERT_EQUALS(table.entries[2].size,                                                             0x1000);
        TEST_ASSERT_EQUALS(table.entries[2].type,                                                             MemoryMapEntryType::RAM);

        TEST_ASSERT_EQUALS(E820::insertRangeInTable(&table, 3, 0xD000, 0x5000, MemoryMapEntryType::UNUSABLE), NgosStatus::OK);
        TEST_ASSERT_EQUALS(table.count,                                                                       4);
        TEST_ASSERT_EQUALS(table.entries[0].start,                                                            0x5000);
        TEST_ASSERT_EQUALS(table.entries[0].size,                                                             0x4000);
        TEST_ASSERT_EQUALS(table.entries[0].type,                                                             MemoryMapEntryType::NVS);
        TEST_ASSERT_EQUALS(table.entries[1].start,                                                            0xA000);
        TEST_ASSERT_EQUALS(table.entries[1].size,                                                             0x2000);
        TEST_ASSERT_EQUALS(table.entries[1].type,                                                             MemoryMapEntryType::RESERVED);
        TEST_ASSERT_EQUALS(table.entries[2].start,                                                            0x2000);
        TEST_ASSERT_EQUALS(table.entries[2].size,                                                             0x1000);
        TEST_ASSERT_EQUALS(table.entries[2].type,                                                             MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[3].start,                                                            0xD000);
        TEST_ASSERT_EQUALS(table.entries[3].size,                                                             0x5000);
        TEST_ASSERT_EQUALS(table.entries[3].type,                                                             MemoryMapEntryType::UNUSABLE);

        TEST_ASSERT_EQUALS(E820::insertRangeInTable(&table, 2, 0x9000, 0x1000, MemoryMapEntryType::ACPI), NgosStatus::OK);
        TEST_ASSERT_EQUALS(table.count,                                                                   5);
        TEST_ASSERT_EQUALS(table.entries[0].start,                                                        0x5000);
        TEST_ASSERT_EQUALS(table.entries[0].size,                                                         0x4000);
        TEST_ASSERT_EQUALS(table.entries[0].type,                                                         MemoryMapEntryType::NVS);
        TEST_ASSERT_EQUALS(table.entries[1].start,                                                        0xA000);
        TEST_ASSERT_EQUALS(table.entries[1].size,                                                         0x2000);
        TEST_ASSERT_EQUALS(table.entries[1].type,                                                         MemoryMapEntryType::RESERVED);
        TEST_ASSERT_EQUALS(table.entries[2].start,                                                        0x9000);
        TEST_ASSERT_EQUALS(table.entries[2].size,                                                         0x1000);
        TEST_ASSERT_EQUALS(table.entries[2].type,                                                         MemoryMapEntryType::ACPI);
        TEST_ASSERT_EQUALS(table.entries[3].start,                                                        0x2000);
        TEST_ASSERT_EQUALS(table.entries[3].size,                                                         0x1000);
        TEST_ASSERT_EQUALS(table.entries[3].type,                                                         MemoryMapEntryType::RAM);
        TEST_ASSERT_EQUALS(table.entries[4].start,                                                        0xD000);
        TEST_ASSERT_EQUALS(table.entries[4].size,                                                         0x5000);
        TEST_ASSERT_EQUALS(table.entries[4].type,                                                         MemoryMapEntryType::UNUSABLE);
    }
    TEST_CASE_END();



    TEST_CASE("updateRangeInTable()");
    {
        E820Table table;

        table.count = 1;
        table.entries[0].start = 0x01000000;
        table.entries[0].size  = 0x00500000;
        table.entries[0].type  = MemoryMapEntryType::RAM;

        TEST_ASSERT_EQUALS(E820::updateRangeInTable(&table, 0x01010000, 0x1000, MemoryMapEntryType::RAM, MemoryMapEntryType::RESERVED_BY_KERNEL), NgosStatus::FAILED);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_BITS64_OTHER_E820_E820_H
