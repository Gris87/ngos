#include "setupuefisystemtable.h"

#include <com/ngos/kernel/other/uefi/uefi.h>
#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>



NgosStatus setupUefiSystemTable()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(UEFI::initSystemTable(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
