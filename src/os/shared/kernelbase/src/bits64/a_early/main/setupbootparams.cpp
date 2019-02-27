#include "setupbootparams.h"

#include <common/src/bits64/memory/memory.h>
#include <kernelbase/src/bits64/a_early/early/earlyassert.h>
#include <kernelbase/src/bits64/a_early/early/earlylog.h>
#include <kernelbase/src/bits64/other/bootparams/bootparams.h>
#include <kernelbase/src/bits64/other/pagetable/dynamicpagetable.h>
#include <ngos/linkage.h>
#include <pagetable/utils.h>



NgosStatus setupBootParams(BootParams *params)
{
    EARLY_LT((" | params = 0x%p", params));

    EARLY_ASSERT(params, "params is null", NgosStatus::ASSERTION);



    EARLY_ASSERT_EXECUTION(addDynamicIdentityMap((u64)params, (u64)params + sizeof(BootParams)), NgosStatus::ASSERTION);

    memcpy(&bootParams, params, sizeof(BootParams));
    memzero(params, sizeof(BootParams)); // Do not let anyone to get something from this structure

    EARLY_ASSERT_EXECUTION(clearDynamicIdentityMap((u64)params, (u64)params + sizeof(BootParams)), NgosStatus::ASSERTION);



    EARLY_LVVV(("bootParams.header.signature           == 0x%016lX", bootParams.header.signature));
    EARLY_LVVV(("bootParams.header.kernelLocation      == 0x%016lX", bootParams.header.kernelLocation));
    EARLY_LVVV(("bootParams.header.kernelSize          == %u",       bootParams.header.kernelSize));
    EARLY_LVVV(("bootParams.header.allocatedKernelSize == %u",       bootParams.header.allocatedKernelSize));

    EARLY_TEST_ASSERT(bootParams.header.signature           == BOOT_PARAMS_HEADER_SIGNATURE, NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(bootParams.header.kernelLocation      == 0,                            NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(bootParams.header.kernelSize          == 0,                            NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(bootParams.header.allocatedKernelSize == 0,                            NgosStatus::ASSERTION);



    return NgosStatus::OK;
}