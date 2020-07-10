#include "devicemanagerpci.h"

#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



ArrayList<DeviceManagerEntry *> DeviceManagerPci::sEntries;



NgosStatus DeviceManagerPci::init()
{
    UEFI_LT((""));



    for (i64 i = 0; i < 10; ++i)
    {
        DeviceManagerEntry *deviceManagerEntry = new DeviceManagerEntry(DeviceManagerImage::MAXIMUM, "sdfg");

        UEFI_ASSERT_EXECUTION(deviceManagerEntry->addRecord("Total memory", "dsg", DeviceManagerMode::BASIC), NgosStatus::ASSERTION);

        UEFI_ASSERT_EXECUTION(sEntries.append(deviceManagerEntry), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

const ArrayList<DeviceManagerEntry *>& DeviceManagerPci::getEntries()
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return sEntries;
}
