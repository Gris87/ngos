#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMSLOTSCHARACTERISTICSFLAGS_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMSLOTSCHARACTERISTICSFLAGS_H



#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/flags.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



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
        case DmiSystemSlotsCharacteristicsFlag::NONE:                               return "NONE";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(DmiSystemSlotsCharacteristicsFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[56];

    sprintf(res, "0x%016lX (%s)", flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const DmiSystemSlotsCharacteristicsFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[713];

    FLAGS_TO_STRING(res, flags.flags, DmiSystemSlotsCharacteristicsFlag);

    return res;
}



inline const char8* flagsToFullString(const DmiSystemSlotsCharacteristicsFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[734];

    FLAGS_TO_FULL_STRING(res, flags.flags, DmiSystemSlotsCharacteristicsFlag, "0x%04X");

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMISYSTEMSLOTSCHARACTERISTICSFLAGS_H
