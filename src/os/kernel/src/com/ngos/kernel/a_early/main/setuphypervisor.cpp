#include "setuphypervisor.h"

#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>

#include <src/com/ngos/kernel/other/hypervisor/hypervisor.h>



NgosStatus setupHypervisor()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(Hypervisor::init(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
