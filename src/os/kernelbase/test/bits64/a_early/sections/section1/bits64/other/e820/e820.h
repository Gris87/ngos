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
