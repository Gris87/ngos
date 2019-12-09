#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMBOOTSTATUS_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMBOOTSTATUS_H



#include <ngos/types.h>



enum class DmiSystemBootStatus: u8
{
    NO_ERROR                  = 0,
    NO_BOOTABLE_MEDIA         = 1,
    NORMAL_OS_FAILED_LOADING  = 2,
    FIRMWARE_DETECTED_FAILURE = 3,
    OS_DETECTED_FAILURE       = 4,
    USER_REQUESTED_BOOT       = 5,
    SYSTEM_SECURITY_VIOLATION = 6,
    PREVIOUS_REQUESTED_IMAGE  = 7,
    WATCHDOG_TIMER_EXPIRED    = 8,
    START_RESERVED            = 9,
    START_OEM_SPECIFIC        = 0x80,
    START_PRODUCT_SPECIFIC    = 0xC0
};



inline const char8* dmiSystemBootStatusToString(DmiSystemBootStatus status) // TEST: NO
{
    // COMMON_LT((" | status = %u", status)); // Commented to avoid bad looking logs



    switch (status)
    {
        case DmiSystemBootStatus::NO_ERROR:                  return "NO_ERROR";
        case DmiSystemBootStatus::NO_BOOTABLE_MEDIA:         return "NO_BOOTABLE_MEDIA";
        case DmiSystemBootStatus::NORMAL_OS_FAILED_LOADING:  return "NORMAL_OS_FAILED_LOADING";
        case DmiSystemBootStatus::FIRMWARE_DETECTED_FAILURE: return "FIRMWARE_DETECTED_FAILURE";
        case DmiSystemBootStatus::OS_DETECTED_FAILURE:       return "OS_DETECTED_FAILURE";
        case DmiSystemBootStatus::USER_REQUESTED_BOOT:       return "USER_REQUESTED_BOOT";
        case DmiSystemBootStatus::SYSTEM_SECURITY_VIOLATION: return "SYSTEM_SECURITY_VIOLATION";
        case DmiSystemBootStatus::PREVIOUS_REQUESTED_IMAGE:  return "PREVIOUS_REQUESTED_IMAGE";
        case DmiSystemBootStatus::WATCHDOG_TIMER_EXPIRED:    return "WATCHDOG_TIMER_EXPIRED";
        case DmiSystemBootStatus::START_RESERVED:            return "START_RESERVED";
        case DmiSystemBootStatus::START_OEM_SPECIFIC:        return "START_OEM_SPECIFIC";
        case DmiSystemBootStatus::START_PRODUCT_SPECIFIC:    return "START_PRODUCT_SPECIFIC";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMBOOTSTATUS_H