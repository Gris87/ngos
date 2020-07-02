#include "setupbrk.h"

#include <common/src/com/ngos/shared/common/early/earlyassert.h>
#include <common/src/com/ngos/shared/common/early/earlylog.h>

#include <src/com/ngos/kernel/other/brk/brk.h>



NgosStatus setupBrk()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(BRK::init(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
