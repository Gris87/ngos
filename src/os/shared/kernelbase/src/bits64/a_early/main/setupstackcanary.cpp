#include "setupstackcanary.h"

#include <common/src/bits64/random/random.h>
#include <kernelbase/src/bits64/a_early/early/earlyassert.h>
#include <kernelbase/src/bits64/a_early/early/earlylog.h>
#include <kernelbase/src/bits64/other/irq/irqstack.h>
#include <kernelbase/src/bits64/other/tasks/task.h>



NgosStatus setupStackCanary()
{
    EARLY_LT((""));



    u64 canary = simpleRandom();

    irqStack.stackCanary = canary;
    initTask.stackCanary = canary;



    EARLY_LVVV(("canary               = 0x%016lX", canary));
    EARLY_LVVV(("irqStack.stackCanary = 0x%016lX", irqStack.stackCanary));
    EARLY_LVVV(("initTask.stackCanary = 0x%016lX", initTask.stackCanary));

    EARLY_TEST_ASSERT(irqStack.stackCanary == canary, NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(initTask.stackCanary == canary, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}