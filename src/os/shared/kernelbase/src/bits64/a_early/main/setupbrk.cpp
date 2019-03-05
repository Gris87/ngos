#include "setupbrk.h"

#include <kernelbase/src/bits64/a_early/early/earlyassert.h>
#include <kernelbase/src/bits64/a_early/early/earlylog.h>
#include <kernelbase/src/bits64/other/brk/brk.h>



NgosStatus setupBrk()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(BRK::init(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
