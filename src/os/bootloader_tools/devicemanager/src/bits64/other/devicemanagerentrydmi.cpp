#include "devicemanagerentrydmi.h"

#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



DeviceManagerEntryDMI::DeviceManagerEntryDMI(DmiEntryType type, DeviceManagerImage image, const char8 *name)
    : DeviceManagerEntry(image, name)
    , mType(type)
{
    UEFI_LT((" | type = %u, image = %u, name = 0x%p", type, image, name));

    UEFI_ASSERT(name,  "name is null");
}

DeviceManagerEntryDMI::~DeviceManagerEntryDMI()
{
    UEFI_LT((""));
}

bool DeviceManagerEntryDMI::operator<(const DeviceManagerEntryDMI &another) const
{
    UEFI_LT((" | another = ..."));



    return mType < another.mType;
}

NgosStatus DeviceManagerEntryDMI::setType(DmiEntryType type)
{
    UEFI_LT((" | type = %u", type));



    mType = type;



    return NgosStatus::OK;
}

DmiEntryType DeviceManagerEntryDMI::getType() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mType;
}
