#include "setupdmi.h"

#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <kernelbase/src/bits64/other/dmi/dmi.h>



NgosStatus setupDmi()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(DMI::init(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
