#include "disableirq.h"

#include <asm/instructions.h>
#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>



NgosStatus disableIrq()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(cli(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
