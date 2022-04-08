#include "disableirq.h"

#include <com/ngos/shared/common/asm/asmutils.h>
#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>



NgosStatus disableIrq()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(AsmUtils::cli(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
