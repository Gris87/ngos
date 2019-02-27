#include "setupinittask.h"

#include <ngos/linkage.h>
#include <src/bits64/a_early/early/earlyassert.h>
#include <src/bits64/a_early/early/earlylog.h>
#include <src/bits64/other/tasks/utils.h>



NgosStatus setupInitTask()
{
    EARLY_LT((""));



    initTask.threadInfo.flags = (thread_info_flags)ThreadInfoFlag::NONE;
    initTask.state            = TaskState::RUNNABLE;
    initTask.stack            = initStack;
    initTask.stackCanary      = 0;

    EARLY_ASSERT_EXECUTION(putTaskStackEndMagic(&initTask), NgosStatus::ASSERTION);



    EARLY_LVVV(("sizeof(initTask)          == %u",        sizeof(initTask)));
    EARLY_LVVV(("initTask.threadInfo.flags == %u",        initTask.threadInfo.flags));
    EARLY_LVVV(("initTask.state            == %d",        initTask.state));
    EARLY_LVVV(("initTask.stack            == 0x%p",      initTask.stack));
    EARLY_LVVV(("initTask.stackCanary      == %u",        initTask.stackCanary));
    EARLY_LVVV(("*((u64 *)initTask.stack)  == 0x%016lX", *((u64 *)initTask.stack)));

    EARLY_TEST_ASSERT(sizeof(initTask)          == 24,                                      NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(initTask.threadInfo.flags == (thread_info_flags)ThreadInfoFlag::NONE, NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(initTask.state            == TaskState::RUNNABLE,                     NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(initTask.stack            == initStack,                               NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(initTask.stackCanary      == 0,                                       NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(*((u64 *)initTask.stack)  == 0x444E454B43415453,                      NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
