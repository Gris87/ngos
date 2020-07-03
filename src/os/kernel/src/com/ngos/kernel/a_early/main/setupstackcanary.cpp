#include "setupstackcanary.h"

#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>
#include <com/ngos/shared/common/random/random.h>

#include <com/ngos/kernel/other/irq/irqstack.h>
#include <com/ngos/kernel/other/task/task.h>



NgosStatus setupStackCanary()
{
    EARLY_LT((""));



    u64 canary = simpleRandom();

    irqStack.stackCanary = canary;
    initTask.stackCanary = canary;



    // Validation
    {
        EARLY_LVVV(("canary               = 0x%016lX", canary));
        EARLY_LVVV(("irqStack.stackCanary = 0x%016lX", irqStack.stackCanary));
        EARLY_LVVV(("initTask.stackCanary = 0x%016lX", initTask.stackCanary));



        EARLY_TEST_ASSERT(irqStack.stackCanary == canary, NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(initTask.stackCanary == canary, NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}
