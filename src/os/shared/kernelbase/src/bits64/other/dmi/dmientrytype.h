#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_DMIENTRYTYPE_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_DMIENTRYTYPE_H



#include <ngos/types.h>



enum class DmiEntryType: u8
{
    BIOS                                 = 0,
    SYSTEM                               = 1,
    BASEBOARD                            = 2,
    CHASSIS                              = 3,
    PROCESSOR                            = 4,
    MEMORY_CONTROLLER                    = 5,
    MEMORY_MODULE                        = 6,
    CACHE                                = 7,
    PORT_CONNECTOR                       = 8,
    SYSTEM_SLOTS                         = 9,
    ONBOARD_DEVICES                      = 10,
    OEM_STRINGS                          = 11,
    SYSTEM_CONFIGURATION                 = 12,
    BIOS_LANGUAGE                        = 13,
    GROUP_ASSOCIATIONS                   = 14,
    SYSTEM_EVENT_LOG                     = 15,
    PHYSICAL_MEMORY_ARRAY                = 16,
    MEMORY_DEVICE                        = 17,
    BITS32_MEMORY_ERROR                  = 18,
    MEMORY_ARRAY_MAPPED_ADDRESS          = 19,
    MEMORY_DEVICE_MAPPED_ADDRESS         = 20,
    BUILTIN_POINTING_DEVICE              = 21,
    PORTABLE_BATTERY                     = 22,
    SYSTEM_RESET                         = 23,
    HARDWARE_SECURITY                    = 24,
    SYSTEM_POWER_CONTROLS                = 25,
    VOLTAGE_PROBE                        = 26,
    COOLING_DEVICE                       = 27,
    TEMPERATURE_PROBE                    = 28,
    ELECTRICAL_CURRENT_PROBE             = 29,
    OUT_OF_BAND_REMOTE_ACCESS            = 30,
    BOOT_INTEGRITY_SERVICES_ENTRY_POINT  = 31,
    SYSTEM_BOOT                          = 32,
    BITS64_MEMORY_ERROR                  = 33,
    MANAGEMENT_DEVICE                    = 34,
    MANAGEMENT_DEVICE_COMPONENT          = 35,
    MANAGEMENT_DEVICE_THRESHOLD_DATA     = 36,
    MEMORY_CHANNEL                       = 37,
    IPMI_DEVICE                          = 38,
    SYSTEM_POWER_SUPPLY                  = 39,
    ADDITIONAL                           = 40,
    ONBOARD_DEVICES_EXTENDED             = 41,
    MANAGEMENT_CONTROLLER_HOST_INTERFACE = 42,
    TPM_DEVICE                           = 43,
    INACTIVE                             = 126,
    END_OF_TABLE                         = 127
};



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_DMIENTRYTYPE_H
