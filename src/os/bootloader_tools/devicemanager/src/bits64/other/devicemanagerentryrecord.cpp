#include "devicemanagerentryrecord.h"

#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



DeviceManagerEntryRecord::DeviceManagerEntryRecord(const char8 *name, const char8 *value, DeviceManagerMode mode)
    : mName(name)
    , mValue(value)
    , mMode(mode)
{
    UEFI_LT((" | name = 0x%p, value = 0x%p, mode = %u", name, value, mode));

    UEFI_ASSERT(name,                              "name is null");
    UEFI_ASSERT(value,                             "value is null");
    UEFI_ASSERT(mode < DeviceManagerMode::MAXIMUM, "mode is invalid");
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

NgosStatus DeviceManagerEntryRecord::setMode(DeviceManagerMode mode)
{
    UEFI_LT((" | mode = %u", mode));



    mMode = mode;



    return NgosStatus::OK;
}

DeviceManagerMode DeviceManagerEntryRecord::getMode() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mMode;
}
