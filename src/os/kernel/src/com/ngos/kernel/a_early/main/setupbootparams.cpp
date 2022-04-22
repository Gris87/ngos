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
        EARLY_LVVV(("bootParams.kernel.kernelLocation      == 0x%016llX", bootParams.header.kernelLocation));
        EARLY_LVVV(("bootParams.kernel.kernelSize          == %u",        bootParams.header.kernelSize));
        EARLY_LVVV(("bootParams.kernel.allocatedKernelSize == %u",        bootParams.header.allocatedKernelSize));

        EARLY_TEST_ASSERT(bootParams.kernel.location      == 0, NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(bootParams.kernel.size          == 0, NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(bootParams.kernel.allocatedSize == 0, NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}
