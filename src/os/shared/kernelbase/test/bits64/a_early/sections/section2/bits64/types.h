#ifndef OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION2_BITS64_TYPES_H
#define OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION2_BITS64_TYPES_H



#include <buildconfig.h>
#include <kernelbase/src/bits64/other/e820/e820table.h>
#include <kernelbase/src/bits64/other/irq/irqstack.h>
#include <kernelbase/src/bits64/other/memorymanager/memoryblock.h>
#include <kernelbase/src/bits64/other/memorymanager/memoryblockregion.h>
#include <kernelbase/src/bits64/other/memorymanager/memoryblocktype.h>
#include <kernelbase/src/bits64/other/task/task.h>
#include <kernelbase/src/bits64/other/task/threadinfo.h>
#include <kernelbase/test/bits64/a_early/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section2, bits64_types);
{
    TEST_CASE("Size of structures");
    {
        TEST_ASSERT_EQUALS(sizeof(E820Table), 3080);

        TEST_ASSERT_EQUALS(sizeof(MemoryBlock), 64);

        TEST_ASSERT_EQUALS(sizeof(MemoryBlockRegion), 24);

        TEST_ASSERT_EQUALS(sizeof(MemoryBlockType), 32);

        TEST_ASSERT_EQUALS(sizeof(Task), 24);

        TEST_ASSERT_EQUALS(sizeof(ThreadInfo), 4);
    }
    TEST_CASE_END();



    TEST_CASE("Size of unions");
    {
        TEST_ASSERT_EQUALS(sizeof(IrqStack), 16384);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION2_BITS64_TYPES_H
