#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSLENGTH_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSLENGTH_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiSystemSlotsLength: u8
{
    NONE                   = 0,
    OTHER                  = 1,
    UNKNOWN                = 2,
    SHORT                  = 3,
    LONG                   = 4,
    _2_5_DRIVE_FORM_FACTOR = 5,
    _3_5_DRIVE_FORM_FACTOR = 6
};



inline const char8* enumToString(DmiSystemSlotsLength length) // TEST: NO
{
    // COMMON_LT((" | length = %u", length)); // Commented to avoid bad looking logs



    switch (length)
    {
        case DmiSystemSlotsLength::NONE:                   return "NONE";
        case DmiSystemSlotsLength::OTHER:                  return "OTHER";
        case DmiSystemSlotsLength::UNKNOWN:                return "UNKNOWN";
        case DmiSystemSlotsLength::SHORT:                  return "SHORT";
        case DmiSystemSlotsLength::LONG:                   return "LONG";
        case DmiSystemSlotsLength::_2_5_DRIVE_FORM_FACTOR: return "2_5_DRIVE_FORM_FACTOR";
        case DmiSystemSlotsLength::_3_5_DRIVE_FORM_FACTOR: return "3_5_DRIVE_FORM_FACTOR";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiSystemSlotsLength length) // TEST: NO
{
    // COMMON_LT((" | length = %u", length)); // Commented to avoid bad looking logs



    static char8 res[29];

    sprintf(res, "0x%02X (%s)", (u8)length, enumToString(length));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSLENGTH_H
