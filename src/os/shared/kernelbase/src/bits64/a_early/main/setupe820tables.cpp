#include "setupe820tables.h"

#include <kernelbase/src/bits64/a_early/early/earlyassert.h>
#include <kernelbase/src/bits64/a_early/early/earlylog.h>
#include <kernelbase/src/bits64/other/e820/e820.h>



NgosStatus setupE820Tables()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(E820::init(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
