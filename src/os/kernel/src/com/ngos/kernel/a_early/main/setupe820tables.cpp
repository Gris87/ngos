#include "setupe820tables.h"

#include <common/src/com/ngos/shared/common/early/earlyassert.h>
#include <common/src/com/ngos/shared/common/early/earlylog.h>

#include <src/com/ngos/kernel/other/e820/e820.h>



NgosStatus setupE820Tables()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(E820::init(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
