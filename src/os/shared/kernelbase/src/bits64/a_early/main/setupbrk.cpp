#include "setupbrk.h"

#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <kernelbase/src/bits64/other/brk/brk.h>



NgosStatus setupBrk()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(BRK::init(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
