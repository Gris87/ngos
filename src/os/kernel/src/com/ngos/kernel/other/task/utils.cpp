#include "utils.h"

#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



#define STACK_END_MAGIC 0x444E454B43415453 // STACKEND



NgosStatus putTaskStackEndMagic(Task *task)
{
    COMMON_LT((" | task = 0x%p", task));

    COMMON_ASSERT(task, "task is null", NgosStatus::ASSERTION);



    *(u64 *)task->stack = STACK_END_MAGIC;



    return NgosStatus::OK;
}
