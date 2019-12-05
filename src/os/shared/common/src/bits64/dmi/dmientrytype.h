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



inline const char8* dmiEntryTypeToString(DmiEntryType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DmiEntryType::BIOS:                                 return "BIOS";
        case DmiEntryType::SYSTEM:                               return "SYSTEM";
        case DmiEntryType::BASEBOARD:                            return "BASEBOARD";
        case DmiEntryType::CHASSIS:                              return "CHASSIS";
        case DmiEntryType::PROCESSOR:                            return "PROCESSOR";
        case DmiEntryType::MEMORY_CONTROLLER:                    return "MEMORY_CONTROLLER";
        case DmiEntryType::MEMORY_MODULE:                        return "MEMORY_MODULE";
        case DmiEntryType::CACHE:                                return "CACHE";
        case DmiEntryType::PORT_CONNECTOR:                       return "PORT_CONNECTOR";
        case DmiEntryType::SYSTEM_SLOTS:                         return "SYSTEM_SLOTS";
        case DmiEntryType::ONBOARD_DEVICES:                      return "ONBOARD_DEVICES";
        case DmiEntryType::OEM_STRINGS:                          return "OEM_STRINGS";
        case DmiEntryType::SYSTEM_CONFIGURATION:                 return "SYSTEM_CONFIGURATION";
        case DmiEntryType::BIOS_LANGUAGE:                        return "BIOS_LANGUAGE";
        case DmiEntryType::GROUP_ASSOCIATIONS:                   return "GROUP_ASSOCIATIONS";
        case DmiEntryType::SYSTEM_EVENT_LOG:                     return "SYSTEM_EVENT_LOG";
        case DmiEntryType::PHYSICAL_MEMORY_ARRAY:                return "PHYSICAL_MEMORY_ARRAY";
        case DmiEntryType::MEMORY_DEVICE:                        return "MEMORY_DEVICE";
        case DmiEntryType::BITS32_MEMORY_ERROR:                  return "BITS32_MEMORY_ERROR";
        case DmiEntryType::MEMORY_ARRAY_MAPPED_ADDRESS:          return "MEMORY_ARRAY_MAPPED_ADDRESS";
        case DmiEntryType::MEMORY_DEVICE_MAPPED_ADDRESS:         return "MEMORY_DEVICE_MAPPED_ADDRESS";
        case DmiEntryType::BUILTIN_POINTING_DEVICE:              return "BUILTIN_POINTING_DEVICE";
        case DmiEntryType::PORTABLE_BATTERY:                     return "PORTABLE_BATTERY";
        case DmiEntryType::SYSTEM_RESET:                         return "SYSTEM_RESET";
        case DmiEntryType::HARDWARE_SECURITY:                    return "HARDWARE_SECURITY";
        case DmiEntryType::SYSTEM_POWER_CONTROLS:                return "SYSTEM_POWER_CONTROLS";
        case DmiEntryType::VOLTAGE_PROBE:                        return "VOLTAGE_PROBE";
        case DmiEntryType::COOLING_DEVICE:                       return "COOLING_DEVICE";
        case DmiEntryType::TEMPERATURE_PROBE:                    return "TEMPERATURE_PROBE";
        case DmiEntryType::ELECTRICAL_CURRENT_PROBE:             return "ELECTRICAL_CURRENT_PROBE";
        case DmiEntryType::OUT_OF_BAND_REMOTE_ACCESS:            return "OUT_OF_BAND_REMOTE_ACCESS";
        case DmiEntryType::BOOT_INTEGRITY_SERVICES_ENTRY_POINT:  return "BOOT_INTEGRITY_SERVICES_ENTRY_POINT";
        case DmiEntryType::SYSTEM_BOOT:                          return "SYSTEM_BOOT";
        case DmiEntryType::BITS64_MEMORY_ERROR:                  return "BITS64_MEMORY_ERROR";
        case DmiEntryType::MANAGEMENT_DEVICE:                    return "MANAGEMENT_DEVICE";
        case DmiEntryType::MANAGEMENT_DEVICE_COMPONENT:          return "MANAGEMENT_DEVICE_COMPONENT";
        case DmiEntryType::MANAGEMENT_DEVICE_THRESHOLD_DATA:     return "MANAGEMENT_DEVICE_THRESHOLD_DATA";
        case DmiEntryType::MEMORY_CHANNEL:                       return "MEMORY_CHANNEL";
        case DmiEntryType::IPMI_DEVICE:                          return "IPMI_DEVICE";
        case DmiEntryType::SYSTEM_POWER_SUPPLY:                  return "SYSTEM_POWER_SUPPLY";
        case DmiEntryType::ADDITIONAL:                           return "ADDITIONAL";
        case DmiEntryType::ONBOARD_DEVICES_EXTENDED:             return "ONBOARD_DEVICES_EXTENDED";
        case DmiEntryType::MANAGEMENT_CONTROLLER_HOST_INTERFACE: return "MANAGEMENT_CONTROLLER_HOST_INTERFACE";
        case DmiEntryType::TPM_DEVICE:                           return "TPM_DEVICE";
        case DmiEntryType::INACTIVE:                             return "INACTIVE";
        case DmiEntryType::END_OF_TABLE:                         return "END_OF_TABLE";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_DMI_DMIENTRYTYPE_H
