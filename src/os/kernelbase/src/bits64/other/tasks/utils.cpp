#include "utils.h"

#include <ngos/types.h>
#include <src/bits64/a_early/early/earlyassert.h>
#include <src/bits64/a_early/early/earlylog.h>



#define STACK_END_MAGIC 0x444E454B43415453 // STACKEND



NgosStatus putTaskStackEndMagic(Task *task)
{
    EARLY_LT((" | task = 0x%p", task));

    EARLY_ASSERT(task, "task is null", NgosStatus::ASSERTION);



    *((u64*)task->stack) = STACK_END_MAGIC;



    return NgosStatus::OK;
}
