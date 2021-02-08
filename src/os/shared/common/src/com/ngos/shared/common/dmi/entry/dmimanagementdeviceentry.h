#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIMANAGEMENTDEVICEENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIMANAGEMENTDEVICEENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>
#include <com/ngos/shared/common/dmi/dmistringid.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmimanagementdeviceaddresstype.h>
#include <com/ngos/shared/common/dmi/entry/lib/dmimanagementdevicetype.h>



struct DmiManagementDeviceEntry
{
    DmiEntryHeader                 header;
    DmiStringId                    description;
    DmiManagementDeviceType        type;
    u32                            address;
    DmiManagementDeviceAddressType addressType;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIMANAGEMENTDEVICEENTRY_H
