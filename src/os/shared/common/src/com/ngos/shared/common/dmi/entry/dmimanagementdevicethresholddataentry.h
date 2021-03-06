#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIMANAGEMENTDEVICETHRESHOLDDATAENTRY_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIMANAGEMENTDEVICETHRESHOLDDATAENTRY_H



#include <com/ngos/shared/common/dmi/dmientryheader.h>



#define DMI_MANAGEMENT_DEVICE_THRESHOLD_DATA_LOWER_THRESHOLD_NON_CRITICAL_NOT_AVAILABLE    0x8000
#define DMI_MANAGEMENT_DEVICE_THRESHOLD_DATA_UPPER_THRESHOLD_NON_CRITICAL_NOT_AVAILABLE    0x8000
#define DMI_MANAGEMENT_DEVICE_THRESHOLD_DATA_LOWER_THRESHOLD_CRITICAL_NOT_AVAILABLE        0x8000
#define DMI_MANAGEMENT_DEVICE_THRESHOLD_DATA_UPPER_THRESHOLD_CRITICAL_NOT_AVAILABLE        0x8000
#define DMI_MANAGEMENT_DEVICE_THRESHOLD_DATA_LOWER_THRESHOLD_NON_RECOVERABLE_NOT_AVAILABLE 0x8000
#define DMI_MANAGEMENT_DEVICE_THRESHOLD_DATA_UPPER_THRESHOLD_NON_RECOVERABLE_NOT_AVAILABLE 0x8000



struct DmiManagementDeviceThresholdDataEntry
{
    DmiEntryHeader header;
    u16            lowerThresholdNonCritical;
    u16            upperThresholdNonCritical;
    u16            lowerThresholdCritical;
    u16            upperThresholdCritical;
    u16            lowerThresholdNonRecoverable;
    u16            upperThresholdNonRecoverable;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_DMIMANAGEMENTDEVICETHRESHOLDDATAENTRY_H
