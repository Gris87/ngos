#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSCHARACTERISTICSFLAGS_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSCHARACTERISTICSFLAGS_H



#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>



typedef u16 dmi_system_slots_characteristics_flags;

enum class DmiSystemSlotsCharacteristicsFlag: dmi_system_slots_characteristics_flags
{
    NONE                        = 0,
    CHARACTERISTICS_UNKNOWN     = (1ULL << 0),
    PROVIDES_50_VOLTS           = (1ULL << 1),
    PROVIDES_33_VOLTS           = (1ULL << 2),
    SHARED_SLOT                 = (1ULL << 3),
    PC_CARD_16_SUPPORTED        = (1ULL << 4),
    CARD_BUS_SUPPORTED          = (1ULL << 5),
    ZOOM_VIDEO_SUPPORTED        = (1ULL << 6),
    MODEM_RING_RESUME_SUPPORTED = (1ULL << 7),
    PME_SIGNAL_SUPPORTED        = (1ULL << 8),
    HOT_PLUG_DEVICES_SUPPORTED  = (1ULL << 9),
    SMBUS_SIGNAL_SUPPORTED      = (1ULL << 10),
    BIFURCATION_SUPPORTED       = (1ULL << 11)
};

DEFINE_FLAGS(DmiSystemSlotsCharacteristicsFlags, dmi_system_slots_characteristics_flags); // TEST: NO



inline const char8* flagToString(DmiSystemSlotsCharacteristicsFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case DmiSystemSlotsCharacteristicsFlag::NONE:                        return "NONE";
        case DmiSystemSlotsCharacteristicsFlag::CHARACTERISTICS_UNKNOWN:     return "CHARACTERISTICS_UNKNOWN";
        case DmiSystemSlotsCharacteristicsFlag::PROVIDES_50_VOLTS:           return "PROVIDES_50_VOLTS";
        case DmiSystemSlotsCharacteristicsFlag::PROVIDES_33_VOLTS:           return "PROVIDES_33_VOLTS";
        case DmiSystemSlotsCharacteristicsFlag::SHARED_SLOT:                 return "SHARED_SLOT";
        case DmiSystemSlotsCharacteristicsFlag::PC_CARD_16_SUPPORTED:        return "PC_CARD_16_SUPPORTED";
        case DmiSystemSlotsCharacteristicsFlag::CARD_BUS_SUPPORTED:          return "CARD_BUS_SUPPORTED";
        case DmiSystemSlotsCharacteristicsFlag::ZOOM_VIDEO_SUPPORTED:        return "ZOOM_VIDEO_SUPPORTED";
        case DmiSystemSlotsCharacteristicsFlag::MODEM_RING_RESUME_SUPPORTED: return "MODEM_RING_RESUME_SUPPORTED";
        case DmiSystemSlotsCharacteristicsFlag::PME_SIGNAL_SUPPORTED:        return "PME_SIGNAL_SUPPORTED";
        case DmiSystemSlotsCharacteristicsFlag::HOT_PLUG_DEVICES_SUPPORTED:  return "HOT_PLUG_DEVICES_SUPPORTED";
        case DmiSystemSlotsCharacteristicsFlag::SMBUS_SIGNAL_SUPPORTED:      return "SMBUS_SIGNAL_SUPPORTED";
        case DmiSystemSlotsCharacteristicsFlag::BIFURCATION_SUPPORTED:       return "BIFURCATION_SUPPORTED";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(DmiSystemSlotsCharacteristicsFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[37];

    sprintf(res, "0x%04X (%s)", (dmi_system_slots_characteristics_flags)flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const DmiSystemSlotsCharacteristicsFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[291];

    FLAGS_TO_STRING(res, flags.flags, DmiSystemSlotsCharacteristicsFlag);

    return res;
}



inline const char8* flagsToFullString(const DmiSystemSlotsCharacteristicsFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[300];

    FLAGS_TO_FULL_STRING(res, flags.flags, DmiSystemSlotsCharacteristicsFlag, "0x%04X");

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSCHARACTERISTICSFLAGS_H
