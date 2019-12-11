#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICHASSISTYPE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICHASSISTYPE_H



#include <ngos/types.h>



enum class DmiChassisType: u8
{
    NONE                  = 0,
    OTHER                 = 1,
    UNKNOWN               = 2,
    DESKTOP               = 3,
    LOW_PROFILE_DESKTOP   = 4,
    PIZZA_BOX             = 5,
    MINI_TOWER            = 6,
    TOWER                 = 7,
    PORTABLE              = 8,
    LAPTOP                = 9,
    NOTEBOOK              = 10,
    HAND_HELD             = 11,
    DOCKING_STATION       = 12,
    ALL_IN_ONE            = 13,
    SUB_NOTEBOOK          = 14,
    SPACE_SAVING          = 15,
    LUNCH_BOX             = 16,
    MAIN_SERVER_CHASSIS   = 17,
    EXPANSION_CHASSIS     = 18,
    SUB_CHASSIS           = 19,
    BUS_EXPANSION_CHASSIS = 20,
    PERIPHERAL_CHASSIS    = 21,
    RAID_CHASSIS          = 22,
    RACK_MOUNT_CHASSIS    = 23,
    SEALED_CASE_PC        = 24,
    MULTI_SYSTEM_CHASSIS  = 25,
    COMPACT_PCI           = 26,
    ADVANCED_TCA          = 27,
    BLADE                 = 28,
    BLADE_ENCLOSURE       = 29,
    TABLET                = 30,
    CONVERTIBLE           = 31,
    DETACHABLE            = 32,
    IOT_GATEWAY           = 33,
    EMBEDDED_PC           = 34,
    MINI_PC               = 35,
    STICK_PC              = 36
};



inline const char8* enumToString(DmiChassisType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DmiChassisType::NONE:                  return "NONE";
        case DmiChassisType::OTHER:                 return "OTHER";
        case DmiChassisType::UNKNOWN:               return "UNKNOWN";
        case DmiChassisType::DESKTOP:               return "DESKTOP";
        case DmiChassisType::LOW_PROFILE_DESKTOP:   return "LOW_PROFILE_DESKTOP";
        case DmiChassisType::PIZZA_BOX:             return "PIZZA_BOX";
        case DmiChassisType::MINI_TOWER:            return "MINI_TOWER";
        case DmiChassisType::TOWER:                 return "TOWER";
        case DmiChassisType::PORTABLE:              return "PORTABLE";
        case DmiChassisType::LAPTOP:                return "LAPTOP";
        case DmiChassisType::NOTEBOOK:              return "NOTEBOOK";
        case DmiChassisType::HAND_HELD:             return "HAND_HELD";
        case DmiChassisType::DOCKING_STATION:       return "DOCKING_STATION";
        case DmiChassisType::ALL_IN_ONE:            return "ALL_IN_ONE";
        case DmiChassisType::SUB_NOTEBOOK:          return "SUB_NOTEBOOK";
        case DmiChassisType::SPACE_SAVING:          return "SPACE_SAVING";
        case DmiChassisType::LUNCH_BOX:             return "LUNCH_BOX";
        case DmiChassisType::MAIN_SERVER_CHASSIS:   return "MAIN_SERVER_CHASSIS";
        case DmiChassisType::EXPANSION_CHASSIS:     return "EXPANSION_CHASSIS";
        case DmiChassisType::SUB_CHASSIS:           return "SUB_CHASSIS";
        case DmiChassisType::BUS_EXPANSION_CHASSIS: return "BUS_EXPANSION_CHASSIS";
        case DmiChassisType::PERIPHERAL_CHASSIS:    return "PERIPHERAL_CHASSIS";
        case DmiChassisType::RAID_CHASSIS:          return "RAID_CHASSIS";
        case DmiChassisType::RACK_MOUNT_CHASSIS:    return "RACK_MOUNT_CHASSIS";
        case DmiChassisType::SEALED_CASE_PC:        return "SEALED_CASE_PC";
        case DmiChassisType::MULTI_SYSTEM_CHASSIS:  return "MULTI_SYSTEM_CHASSIS";
        case DmiChassisType::COMPACT_PCI:           return "COMPACT_PCI";
        case DmiChassisType::ADVANCED_TCA:          return "ADVANCED_TCA";
        case DmiChassisType::BLADE:                 return "BLADE";
        case DmiChassisType::BLADE_ENCLOSURE:       return "BLADE_ENCLOSURE";
        case DmiChassisType::TABLET:                return "TABLET";
        case DmiChassisType::CONVERTIBLE:           return "CONVERTIBLE";
        case DmiChassisType::DETACHABLE:            return "DETACHABLE";
        case DmiChassisType::IOT_GATEWAY:           return "IOT_GATEWAY";
        case DmiChassisType::EMBEDDED_PC:           return "EMBEDDED_PC";
        case DmiChassisType::MINI_PC:               return "MINI_PC";
        case DmiChassisType::STICK_PC:              return "STICK_PC";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiChassisType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DmiChassisType::NONE:                  return "NONE";
        case DmiChassisType::OTHER:                 return "OTHER";
        case DmiChassisType::UNKNOWN:               return "UNKNOWN";
        case DmiChassisType::DESKTOP:               return "DESKTOP";
        case DmiChassisType::LOW_PROFILE_DESKTOP:   return "LOW_PROFILE_DESKTOP";
        case DmiChassisType::PIZZA_BOX:             return "PIZZA_BOX";
        case DmiChassisType::MINI_TOWER:            return "MINI_TOWER";
        case DmiChassisType::TOWER:                 return "TOWER";
        case DmiChassisType::PORTABLE:              return "PORTABLE";
        case DmiChassisType::LAPTOP:                return "LAPTOP";
        case DmiChassisType::NOTEBOOK:              return "NOTEBOOK";
        case DmiChassisType::HAND_HELD:             return "HAND_HELD";
        case DmiChassisType::DOCKING_STATION:       return "DOCKING_STATION";
        case DmiChassisType::ALL_IN_ONE:            return "ALL_IN_ONE";
        case DmiChassisType::SUB_NOTEBOOK:          return "SUB_NOTEBOOK";
        case DmiChassisType::SPACE_SAVING:          return "SPACE_SAVING";
        case DmiChassisType::LUNCH_BOX:             return "LUNCH_BOX";
        case DmiChassisType::MAIN_SERVER_CHASSIS:   return "MAIN_SERVER_CHASSIS";
        case DmiChassisType::EXPANSION_CHASSIS:     return "EXPANSION_CHASSIS";
        case DmiChassisType::SUB_CHASSIS:           return "SUB_CHASSIS";
        case DmiChassisType::BUS_EXPANSION_CHASSIS: return "BUS_EXPANSION_CHASSIS";
        case DmiChassisType::PERIPHERAL_CHASSIS:    return "PERIPHERAL_CHASSIS";
        case DmiChassisType::RAID_CHASSIS:          return "RAID_CHASSIS";
        case DmiChassisType::RACK_MOUNT_CHASSIS:    return "RACK_MOUNT_CHASSIS";
        case DmiChassisType::SEALED_CASE_PC:        return "SEALED_CASE_PC";
        case DmiChassisType::MULTI_SYSTEM_CHASSIS:  return "MULTI_SYSTEM_CHASSIS";
        case DmiChassisType::COMPACT_PCI:           return "COMPACT_PCI";
        case DmiChassisType::ADVANCED_TCA:          return "ADVANCED_TCA";
        case DmiChassisType::BLADE:                 return "BLADE";
        case DmiChassisType::BLADE_ENCLOSURE:       return "BLADE_ENCLOSURE";
        case DmiChassisType::TABLET:                return "TABLET";
        case DmiChassisType::CONVERTIBLE:           return "CONVERTIBLE";
        case DmiChassisType::DETACHABLE:            return "DETACHABLE";
        case DmiChassisType::IOT_GATEWAY:           return "IOT_GATEWAY";
        case DmiChassisType::EMBEDDED_PC:           return "EMBEDDED_PC";
        case DmiChassisType::MINI_PC:               return "MINI_PC";
        case DmiChassisType::STICK_PC:              return "STICK_PC";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMICHASSISTYPE_H
