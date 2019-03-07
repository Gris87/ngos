#include "setuphypervisor.h"

#include <kernelbase/src/bits64/a_early/early/earlyassert.h>
#include <kernelbase/src/bits64/a_early/early/earlylog.h>
#include <kernelbase/src/bits64/other/hypervisor/hypervisor.h>



NgosStatus setupHypervisor()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(Hypervisor::init(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
