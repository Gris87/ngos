#include "setupbootparams.h"

#include <src/bits64/memory/memory.h>

#include "src/bits64/a_uefi/uefi/lib/eficonstants.h"
#include "src/bits64/a_uefi/uefi/uefiassert.h"
#include "src/bits64/a_uefi/uefi/uefilog.h"



NgosStatus setupBootParams(BootParams **params, u64 kernelLocation)
{
    UEFI_LT((" | params = 0x%p, kernelLocation = 0x%p", params, kernelLocation));

    UEFI_ASSERT(params,         "params is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(kernelLocation, "kernelLocation is null", NgosStatus::ASSERTION);



    if (UEFI::lowAlloc(sizeof(BootParams), 1, (void **)params) != EfiStatus::SUCCESS)
    {
        UEFI_LF(("Failed to allocate space(%u) for boot parameters", sizeof(BootParams)));

        return NgosStatus::FAILED;
    }

#if NGOS_BUILD_RELEASE == OPTION_NO
    UEFI_LD(("gdb_debug: Boot parameters allocated in space(%u, 0x%p)", sizeof(BootParams), *params));
#else
    UEFI_LVV(("Boot parameters allocated in space(%u, 0x%p)", sizeof(BootParams), *params));
#endif



    memzero(*params, sizeof(BootParams));

    (*params)->header.signature      = BOOT_PARAMS_HEADER_SIGNATURE;
    (*params)->header.kernelLocation = kernelLocation;



    return NgosStatus::OK;
}
