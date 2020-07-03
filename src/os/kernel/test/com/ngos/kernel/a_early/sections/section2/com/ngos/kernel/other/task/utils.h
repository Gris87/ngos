#ifndef KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_TASK_UTILS_H
#define KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_TASK_UTILS_H



#include <buildconfig.h>
#include <com/ngos/shared/common/memory/memory.h>

#include <com/ngos/kernel/other/task/utils.h>
#include <com/ngos/kernel/a_early/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section2, com_ngos_kernel_other_task_utils);
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



#endif // KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_TASK_UTILS_H
