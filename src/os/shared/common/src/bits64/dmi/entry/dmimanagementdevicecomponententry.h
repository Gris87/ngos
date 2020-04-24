#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMANAGEMENTDEVICECOMPONENTENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMANAGEMENTDEVICECOMPONENTENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>



#define DMI_MANAGEMENT_DEVICE_COMPONENT_THRESHOLD_HANDLE_NOT_AVAILABLE 0xFFFF



struct DmiManagementDeviceComponentEntry
{
    DmiEntryHeader header;
    u8             descriptionStringId;
    u16            managementDeviceHandle;
    u16            componentHandle;
    u16            thresholdHandle;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMANAGEMENTDEVICECOMPONENTENTRY_H
