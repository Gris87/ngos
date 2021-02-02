#include "setupbootparams.h"

#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/uefibase/main/setupbootparams.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



NgosStatus setupBootParams(BootParams **params, bad_uint64 kernelLocation)
{
    UEFI_LT((" | params = 0x%p, kernelLocation = 0x%p", params, kernelLocation));

    UEFI_ASSERT(params,         "params is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(kernelLocation, "kernelLocation is null", NgosStatus::ASSERTION);



    bad_uint64 size = sizeof(BootParams);



    if (UEFI::lowAlloc(size, 1, (void **)params) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate space(%u) for boot parameters", size));

        return NgosStatus::FAILED;
    }

    UEFI_LVV(("Boot parameters allocated in space(0x%p, %u)", *params, size));



    UEFI_ASSERT_EXECUTION(setupBootParams(*params, kernelLocation), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
