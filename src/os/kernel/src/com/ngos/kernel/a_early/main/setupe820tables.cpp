#include "setupe820tables.h"

#include <com/ngos/kernel/other/e820/e820.h>
#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>



NgosStatus setupE820Tables()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(E820::init(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
