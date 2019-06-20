#include "setupbootparams.h"

#include <common/src/bits64/memory/memory.h>
#include <uefibase/src/bits64/main/setupbootparams.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



NgosStatus setupBootParams(BootParams **params, u64 kernelLocation)
{
    UEFI_LT((" | params = 0x%p, kernelLocation = 0x%p", params, kernelLocation));

    UEFI_ASSERT(params,         "params is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(kernelLocation, "kernelLocation is null", NgosStatus::ASSERTION);



    if (UEFI::lowAlloc(sizeof(BootParams), 1, (void **)params) != UefiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate space(%u) for boot parameters", sizeof(BootParams)));

        return NgosStatus::FAILED;
    }

#if NGOS_BUILD_RELEASE == OPTION_NO
    UEFI_LD(("gdb_debug: Boot parameters allocated in space(0x%p, %u)", *params, sizeof(BootParams)));
#else
    UEFI_LVV(("Boot parameters allocated in space(0x%p, %u)", *params, sizeof(BootParams)));
#endif



    UEFI_ASSERT_EXECUTION(setupBootParams(*params, kernelLocation), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
