#include "setuphardwareid.h"

#include <common/src/bits64/dmi/dmi.h>
#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



NgosStatus setupHardwareId(BootParams *params)
{
    UEFI_LT((" | params = 0x%p", params));

    UEFI_ASSERT(params, "params is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(params); // TODO: Remove it



    UEFI_ASSERT_EXECUTION(DMI::init(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
