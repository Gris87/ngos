#include "setupuefisystemtable.h"

#include <common/src/com/ngos/shared/common/early/earlyassert.h>
#include <common/src/com/ngos/shared/common/early/earlylog.h>

#include <src/com/ngos/kernel/other/uefi/uefi.h>



NgosStatus setupUefiSystemTable()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(UEFI::initSystemTable(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
