#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMANAGEMENTDEVICETHRESHOLDDATAENTRY_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMANAGEMENTDEVICETHRESHOLDDATAENTRY_H



#include <common/src/bits64/dmi/dmientryheader.h>



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



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_DMIMANAGEMENTDEVICETHRESHOLDDATAENTRY_H
