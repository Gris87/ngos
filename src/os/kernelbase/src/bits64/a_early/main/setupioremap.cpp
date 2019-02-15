#include "setupioremap.h"

#include <src/bits64/a_early/early/earlyassert.h>
#include <src/bits64/a_early/early/earlylog.h>
#include <src/bits64/other/ioremap/ioremap.h>



NgosStatus setupIoRemap()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(IORemap::init(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
