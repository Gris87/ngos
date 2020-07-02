#include "setuphypervisor.h"

#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <kernelbase/src/bits64/other/hypervisor/hypervisor.h>



NgosStatus setupHypervisor()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(Hypervisor::init(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
