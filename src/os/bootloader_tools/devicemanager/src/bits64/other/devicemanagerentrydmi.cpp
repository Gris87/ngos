#include "devicemanagerentrydmi.h"

#include <uefibase/src/bits64/uefi/uefiassert.h>
#include <uefibase/src/bits64/uefi/uefilog.h>



DeviceManagerEntryDMI::DeviceManagerEntryDMI(DmiEntryType type)
    : DeviceManagerEntry()
    , mType(type)
{
    UEFI_LT((" | type = %u", type));
}

DeviceManagerEntryDMI::~DeviceManagerEntryDMI()
{
    UEFI_LT((""));
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
