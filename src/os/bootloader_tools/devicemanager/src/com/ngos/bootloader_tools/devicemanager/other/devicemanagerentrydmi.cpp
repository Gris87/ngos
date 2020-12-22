#include "devicemanagerentrydmi.h"

#include <com/ngos/shared/common/string/string.h>
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



DeviceManagerEntryDMI::DeviceManagerEntryDMI(DmiEntryType type, u16 handle, DeviceManagerImage image, const char8 *name)
    : DeviceManagerEntry(image, name)
    , mType(type)
    , mHandle(handle)
{
    UEFI_LT((" | type = %u, handle = %u, image = %u, name = 0x%p", type, handle, image, name));

    UEFI_ASSERT(name != nullptr, "name is null");
}

DeviceManagerEntryDMI::~DeviceManagerEntryDMI()
{
    UEFI_LT((""));
}

bool DeviceManagerEntryDMI::operator<(const DeviceManagerEntryDMI &another) const
{
    UEFI_LT((" | another = ..."));



    if (mType < another.mType)
    {
        return true;
    }
    else
    if (mType > another.mType)
    {
        return false;
    }



    i8 match = strcmpi(getName(), another.getName());

    if (match < 0)
    {
        return true;
    }
    else
    if (match > 0)
    {
        return false;
    }



    return mHandle < another.mHandle;
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

NgosStatus DeviceManagerEntryDMI::setHandle(u16 handle)
{
    UEFI_LT((" | handle = %u", handle));



    mHandle = handle;



    return NgosStatus::OK;
}

u16 DeviceManagerEntryDMI::getHandle() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mHandle;
}
