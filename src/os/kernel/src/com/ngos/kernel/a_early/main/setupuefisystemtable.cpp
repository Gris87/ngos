#include "setupuefisystemtable.h"

#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <kernelbase/src/bits64/other/uefi/uefi.h>



NgosStatus setupUefiSystemTable()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(UEFI::initSystemTable(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
