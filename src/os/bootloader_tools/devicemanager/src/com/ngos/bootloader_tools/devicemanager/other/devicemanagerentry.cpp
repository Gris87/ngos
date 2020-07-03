#include "devicemanagerentry.h"

#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



DeviceManagerEntry::DeviceManagerEntry(DeviceManagerImage image, const char8 *name)
    : mImage(image)
    , mName(name)
    , mRecords()
{
    UEFI_LT((" | image = %u, name = 0x%p", image, name));

    UEFI_ASSERT(name,  "name is null");
}

DeviceManagerEntry::~DeviceManagerEntry()
{
    UEFI_LT((""));



    for (i64 i = 0; i < (i64)mRecords.getSize(); ++i)
    {
        delete mRecords.at(i);
    }
}

NgosStatus DeviceManagerEntry::addRecord(const char8 *name, const char8 *value, DeviceManagerMode mode)
{
    UEFI_LT((" | name = 0x%p, value = 0x%p, mode = %u", name, value, mode));

    UEFI_ASSERT(name,                              "name is null",    NgosStatus::ASSERTION);
    UEFI_ASSERT(value,                             "value is null",   NgosStatus::ASSERTION);
    UEFI_ASSERT(mode < DeviceManagerMode::MAXIMUM, "mode is invalid", NgosStatus::ASSERTION);



    DeviceManagerEntryRecord *record = new DeviceManagerEntryRecord(name, value, mode);

    UEFI_TEST_ASSERT(record, NgosStatus::ASSERTION);

    UEFI_ASSERT_EXECUTION(mRecords.append(record), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

const ArrayList<DeviceManagerEntryRecord *>& DeviceManagerEntry::getRecords()
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mRecords;
}

NgosStatus DeviceManagerEntry::setImage(DeviceManagerImage image)
{
    UEFI_LT((" | image = %u", image));



    mImage = image;



    return NgosStatus::OK;
}

DeviceManagerImage DeviceManagerEntry::getImage() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mImage;
}

NgosStatus DeviceManagerEntry::setName(const char8 *name)
{
    UEFI_LT((" | name = %u", name));



    mName = name;



    return NgosStatus::OK;
}

const char8* DeviceManagerEntry::getName() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mName;
}
