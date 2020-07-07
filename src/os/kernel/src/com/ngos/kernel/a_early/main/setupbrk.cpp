#include "setupbrk.h"

#include <com/ngos/kernel/other/brk/brk.h>
#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>



NgosStatus setupBrk()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(BRK::init(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
