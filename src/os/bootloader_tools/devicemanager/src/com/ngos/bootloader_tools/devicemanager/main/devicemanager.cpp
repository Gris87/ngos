#include "devicemanager.h"

#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>

#include "src/com/ngos/bootloader_tools/devicemanager/sources/dmi/devicemanagerdmi.h"



NgosStatus DeviceManager::init()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(DeviceManagerDMI::init(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
