#include "devicemanager.h"

#include <com/ngos/bootloader_tools/devicemanager/sources/dmi/devicemanagerdmi.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



NgosStatus DeviceManager::init()
{
    UEFI_LT((""));



    UEFI_ASSERT_EXECUTION(DeviceManagerDMI::init(), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
