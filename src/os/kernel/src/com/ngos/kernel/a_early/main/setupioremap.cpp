#include "setupioremap.h"

#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <kernelbase/src/bits64/other/ioremap/ioremap.h>



NgosStatus setupIoRemap()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(IORemap::init(),            NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(IORemap::addPmdForFixmap(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
