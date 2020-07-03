#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIMANAGEMENTDEVICECOMPONENTENTRY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIMANAGEMENTDEVICECOMPONENTENTRY_H



#include <common/src/com/ngos/shared/common/dmi/dmientryheader.h>
#include <common/src/com/ngos/shared/common/dmi/dmistringid.h>



#define DMI_MANAGEMENT_DEVICE_COMPONENT_THRESHOLD_HANDLE_NOT_AVAILABLE 0xFFFF



struct DmiManagementDeviceComponentEntry
{
    DmiEntryHeader header;
    DmiStringId    description;
    u16            managementDeviceHandle;
    u16            componentHandle;
    u16            thresholdHandle;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIMANAGEMENTDEVICECOMPONENTENTRY_H
