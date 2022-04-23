#include "setupbootparams.h"

#include <com/ngos/kernel/other/bootparams/bootparams.h>
#include <com/ngos/kernel/other/pagetable/dynamicpagetable.h>
#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>
#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/pagetable/utils.h>



NgosStatus setupBootParams(BootParams *params)
{
    EARLY_LT((" | params = 0x%p", params));

    EARLY_ASSERT(params, "params is null", NgosStatus::ASSERTION);



    EARLY_ASSERT_EXECUTION(addDynamicIdentityMap((u64)params, (u64)params + sizeof(BootParams)), NgosStatus::ASSERTION);

    memcpy(&bootParams, params, sizeof(BootParams));
    memzero(params, sizeof(BootParams)); // Do not let anyone to get something from this structure

    EARLY_ASSERT_EXECUTION(clearDynamicIdentityMap((u64)params, (u64)params + sizeof(BootParams)), NgosStatus::ASSERTION);



    // Validation
    {
        EARLY_LVVV(("bootParams.kernel.location      == 0x%016llX", bootParams.kernel.location));
        EARLY_LVVV(("bootParams.kernel.size          == %d",        bootParams.kernel.size));
        EARLY_LVVV(("bootParams.kernel.allocatedSize == %d",        bootParams.kernel.allocatedSize));

        EARLY_TEST_ASSERT(bootParams.kernel.location      == 0, NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(bootParams.kernel.size          == 0, NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(bootParams.kernel.allocatedSize == 0, NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}
