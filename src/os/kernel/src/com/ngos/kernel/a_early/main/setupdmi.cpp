#include "setupdmi.h"

#include <common/src/com/ngos/shared/common/dmi/dmi.h>
#include <common/src/com/ngos/shared/common/early/earlyassert.h>
#include <common/src/com/ngos/shared/common/early/earlylog.h>



NgosStatus setupDmi()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(DMI::init(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
