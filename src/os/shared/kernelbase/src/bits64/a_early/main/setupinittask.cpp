#include "setupinittask.h"

#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <kernelbase/src/bits64/other/task/utils.h>
#include <ngos/linkage.h>



NgosStatus setupInitTask()
{
    EARLY_LT((""));



    initTask.threadInfo.flags = FLAGS(ThreadInfoFlag::NONE);
    initTask.state            = TaskState::RUNNABLE;
    initTask.stack            = initStack;
    initTask.stackCanary      = 0;

    EARLY_ASSERT_EXECUTION(putTaskStackEndMagic(&initTask), NgosStatus::ASSERTION);



    // Validation
    {
        EARLY_LVVV(("sizeof(initTask)          == %u",        sizeof(initTask)));
        EARLY_LVVV(("initTask.threadInfo.flags == %s",        flagsToFullString(initTask.threadInfo.flags)));
        EARLY_LVVV(("initTask.state            == %s",        enumToFullString(initTask.state)));
        EARLY_LVVV(("initTask.stack            == 0x%p",      initTask.stack));
        EARLY_LVVV(("initTask.stackCanary      == %u",        initTask.stackCanary));
        EARLY_LVVV(("*(u64 *)initTask.stack    == 0x%016lX", *(u64 *)initTask.stack));



        EARLY_TEST_ASSERT(sizeof(initTask)          == 24,                          NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(initTask.threadInfo.flags == FLAGS(ThreadInfoFlag::NONE), NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(initTask.state            == TaskState::RUNNABLE,         NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(initTask.stack            == initStack,                   NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(initTask.stackCanary      == 0,                           NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(*(u64 *)initTask.stack    == 0x444E454B43415453,          NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}
