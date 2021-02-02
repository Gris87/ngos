#include "devicemanagerentrypci.h"

#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>



DeviceManagerEntryPCI::DeviceManagerEntryPCI(DeviceManagerEntryPCI *parent, DeviceManagerImage image, const char8 *name)
    : DeviceManagerEntry(image, name)
{
    UEFI_LT((" | parent = 0x%p, image = %u, name = 0x%p", parent, image, name));

    UEFI_ASSERT(name != nullptr, "name is null");



    if (parent != nullptr)
    {
        parent->mChildren.append(this);
    }
}

DeviceManagerEntryPCI::~DeviceManagerEntryPCI()
{
    UEFI_LT((""));



    for (bad_int64 i = 0; i < (bad_int64)mChildren.getSize(); ++i)
    {
        delete mChildren.at(i);
    }
}

const ArrayList<DeviceManagerEntryPCI *>& DeviceManagerEntryPCI::getChildren() const
{
    // UEFI_LT(("")); // Commented to avoid too frequent logs



    return mChildren;
}
