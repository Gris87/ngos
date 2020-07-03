#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSLENGTH_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSLENGTH_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/ngos/types.h>



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
        case DmiSystemSlotsLength::_2_5_DRIVE_FORM_FACTOR: return "_2_5_DRIVE_FORM_FACTOR";
        case DmiSystemSlotsLength::_3_5_DRIVE_FORM_FACTOR: return "_3_5_DRIVE_FORM_FACTOR";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiSystemSlotsLength length) // TEST: NO
{
    // COMMON_LT((" | length = %u", length)); // Commented to avoid bad looking logs



    static char8 res[30];

    sprintf(res, "0x%02X (%s)", length, enumToString(length));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMISYSTEMSLOTSLENGTH_H
