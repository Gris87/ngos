#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMANAGEMENTDEVICEENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMANAGEMENTDEVICEENTRY_H



#include <common/src/com/ngos/shared/common/dmi/dmientryheader.h>
#include <common/src/com/ngos/shared/common/dmi/dmistringid.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmimanagementdeviceaddresstype.h>
#include <common/src/com/ngos/shared/common/dmi/entry/lib/dmimanagementdevicetype.h>



struct DmiManagementDeviceEntry
{
    DmiEntryHeader                 header;
    DmiStringId                    description;
    DmiManagementDeviceType        type;
    u32                            address;
    DmiManagementDeviceAddressType addressType;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMANAGEMENTDEVICEENTRY_H
