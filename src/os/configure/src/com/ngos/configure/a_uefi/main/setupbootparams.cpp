#include "setupbootparams.h"

#include <common/src/com/ngos/shared/common/memory/memory.h>
#include <uefibase/src/bits64/main/setupbootparams.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



NgosStatus setupBootParams(BootParams **params, u64 kernelLocation)
{
    UEFI_LT((" | params = 0x%p, kernelLocation = 0x%p", params, kernelLocation));

    UEFI_ASSERT(params,         "params is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(kernelLocation, "kernelLocation is null", NgosStatus::ASSERTION);



    u64 size = sizeof(BootParams);



    if (UEFI::lowAlloc(size, 1, (void **)params) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate space(%u) for boot parameters", size));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Boot parameters allocated in space(0x%p, %u)", *params, size));



    UEFI_ASSERT_EXECUTION(setupBootParams(*params, kernelLocation), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
