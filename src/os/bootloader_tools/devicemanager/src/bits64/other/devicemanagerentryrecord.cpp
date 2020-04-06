#include "devicemanagerentryrecord.h"

#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



DeviceManagerEntryRecord::DeviceManagerEntryRecord(const char8 *name, const char8 *value)
    : mName(name)
    , mValue(value)
{
    UEFI_LT((" | name = 0x%p, value = 0x%p", name, value));

    UEFI_ASSERT(name,  "name is null");
    UEFI_ASSERT(value, "value is null");
}

NgosStatus DeviceManagerEntryRecord::setName(const char8 *name)
{
    UEFI_LT((" | name = 0x%p", name));

    UEFI_ASSERT(name, "name is null", NgosStatus::ASSERTION);



    mName = name;



    return NgosStatus::OK;
}

const char8* DeviceManagerEntryRecord::getName() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mName;
}

NgosStatus DeviceManagerEntryRecord::setValue(const char8 *value)
{
    UEFI_LT((" | value = 0x%p", value));

    UEFI_ASSERT(value, "value is null", NgosStatus::ASSERTION);



    mValue = value;



    return NgosStatus::OK;
}

const char8* DeviceManagerEntryRecord::getValue() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mValue;
}
