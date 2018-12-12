#include "disableirq.h"

#include <asm/instructions.h>
#include <src/bits64/a_early/early/earlyassert.h>
#include <src/bits64/a_early/early/earlylog.h>



NgosStatus disableIrq()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(cli(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
