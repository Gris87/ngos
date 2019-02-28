#include "setupuefisystemtable.h"

#include <kernelbase/src/bits64/a_early/early/earlyassert.h>
#include <kernelbase/src/bits64/a_early/early/earlylog.h>
#include <kernelbase/src/bits64/other/uefi/uefi.h>



NgosStatus setupUefiSystemTable()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(UEFI::initSystemTable(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
