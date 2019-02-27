#include "setupioremap.h"

#include <kernelbase/src/bits64/a_early/early/earlyassert.h>
#include <kernelbase/src/bits64/a_early/early/earlylog.h>
#include <kernelbase/src/bits64/other/ioremap/ioremap.h>



NgosStatus setupIoRemap()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(IORemap::init(),            NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(IORemap::addPmdForFixmap(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
