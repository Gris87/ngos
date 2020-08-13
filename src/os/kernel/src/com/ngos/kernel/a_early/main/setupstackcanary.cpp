#include "setupstackcanary.h"

#include <com/ngos/kernel/other/irq/irqstack.h>
#include <com/ngos/kernel/other/task/task.h>
#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>
#include <com/ngos/shared/common/random/random.h>



NgosStatus setupStackCanary()
{
    EARLY_LT((""));



    u64 canary = simpleRandom();

    irqStack.stackCanary = canary;
    initTask.stackCanary = canary;



    // Validation
    {
        EARLY_LVVV(("canary               = 0x%016llX", canary));
        EARLY_LVVV(("irqStack.stackCanary = 0x%016llX", irqStack.stackCanary));
        EARLY_LVVV(("initTask.stackCanary = 0x%016llX", initTask.stackCanary));



        EARLY_TEST_ASSERT(irqStack.stackCanary == canary, NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(initTask.stackCanary == canary, NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}
