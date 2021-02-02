#include "setupbootparams.h"

#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



NgosStatus setupBootParams(BootParams *params, bad_uint64 kernelLocation)
{
    UEFI_LT((" | params = 0x%p, kernelLocation = 0x%p", params, kernelLocation));

    UEFI_ASSERT(params,         "params is null",         NgosStatus::ASSERTION);
    UEFI_ASSERT(kernelLocation, "kernelLocation is null", NgosStatus::ASSERTION);



    memzero(params, sizeof(BootParams));

    params->header.signature      = BOOT_PARAMS_HEADER_SIGNATURE;
    params->header.kernelLocation = kernelLocation;



    return NgosStatus::OK;
}
