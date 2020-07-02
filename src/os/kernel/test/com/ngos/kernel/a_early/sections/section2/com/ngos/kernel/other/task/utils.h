#ifndef OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION2_BITS64_OTHER_TASK_UTILS_H
#define OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION2_BITS64_OTHER_TASK_UTILS_H



#include <buildconfig.h>
#include <common/src/bits64/memory/memory.h>
#include <kernelbase/src/bits64/other/task/utils.h>
#include <kernelbase/test/bits64/a_early/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section2, bits64_other_task_utils);
{
    TEST_CASE("putTaskStackEndMagic()");
    {
        Task task;
        u8   taskStack[100];

        task.stack = taskStack;
        memzero(taskStack, sizeof(taskStack));



        TEST_ASSERT_EQUALS(*(u64 *)taskStack,           0);
        TEST_ASSERT_EQUALS(putTaskStackEndMagic(&task), NgosStatus::OK);
        TEST_ASSERT_EQUALS(*(u64 *)taskStack,           0x444E454B43415453);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION2_BITS64_OTHER_TASK_UTILS_H
