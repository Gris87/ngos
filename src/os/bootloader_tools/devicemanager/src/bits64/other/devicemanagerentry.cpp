#include "devicemanagerentry.h"

#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



DeviceManagerEntry::DeviceManagerEntry()
    : mRecords()
{
    UEFI_LT((""));
}

NgosStatus DeviceManagerEntry::addRecord(const char8 *name, const char8 *value)
{
    UEFI_LT((" | name = 0x%p, value = 0x%p", name, value));

    UEFI_ASSERT(name,  "name is null",  NgosStatus::ASSERTION);
    UEFI_ASSERT(value, "value is null", NgosStatus::ASSERTION);



    DeviceManagerEntryRecord *record = new DeviceManagerEntryRecord(name, value);

    UEFI_TEST_ASSERT(record, NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(mRecords.append(record), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

const ArrayList<DeviceManagerEntryRecord *>& DeviceManagerEntry::getRecords()
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mRecords;
}
