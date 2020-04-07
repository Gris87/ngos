#include "devicemanagerentry.h"

#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



DeviceManagerEntry::DeviceManagerEntry(DeviceManagerImage image)
    : mImage(image)
    , mRecords()
{
    UEFI_LT((" | image = %u", image));
}

DeviceManagerEntry::~DeviceManagerEntry()
{
    UEFI_LT((""));



    for (i64 i = 0; i < (i64)mRecords.getSize(); ++i)
    {
        delete mRecords.at(i);
    }
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
