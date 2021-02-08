#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSUSAGE_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSUSAGE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiSystemSlotsUsage: u8
{
    NONE        = 0,
    OTHER       = 1,
    UNKNOWN     = 2,
    AVAILABLE   = 3,
    IN_USE      = 4,
    UNAVAILABLE = 5
};



inline const char8* enumToString(DmiSystemSlotsUsage usage) // TEST: NO
{
    // COMMON_LT((" | usage = %u", usage)); // Commented to avoid bad looking logs



    switch (usage)
    {
        case DmiSystemSlotsUsage::NONE:        return "NONE";
        case DmiSystemSlotsUsage::OTHER:       return "OTHER";
        case DmiSystemSlotsUsage::UNKNOWN:     return "UNKNOWN";
        case DmiSystemSlotsUsage::AVAILABLE:   return "AVAILABLE";
        case DmiSystemSlotsUsage::IN_USE:      return "IN_USE";
        case DmiSystemSlotsUsage::UNAVAILABLE: return "UNAVAILABLE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiSystemSlotsUsage usage) // TEST: NO
{
    // COMMON_LT((" | usage = %u", usage)); // Commented to avoid bad looking logs



    static char8 res[19];

    sprintf(res, "0x%02X (%s)", (u8)usage, enumToString(usage));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSUSAGE_H
