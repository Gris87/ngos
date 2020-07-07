#include "setuphypervisor.h"

#include <com/ngos/kernel/other/hypervisor/hypervisor.h>
#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>



NgosStatus setupHypervisor()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(Hypervisor::init(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
