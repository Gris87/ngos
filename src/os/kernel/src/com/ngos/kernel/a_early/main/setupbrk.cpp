#include "setupbrk.h"

#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>

#include <src/com/ngos/kernel/other/brk/brk.h>



NgosStatus setupBrk()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(BRK::init(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
