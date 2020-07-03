#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISCONTAINEDELEMENTTYPESELECT_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISCONTAINEDELEMENTTYPESELECT_H



#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



enum class DmiChassisContainedElementTypeSelect: u8
{
    BASEBOARD_TYPE = 0,
    DMI_ENTRY_TYPE = 1
};



inline const char8* enumToString(DmiChassisContainedElementTypeSelect select) // TEST: NO
{
    // COMMON_LT((" | select = %u", select)); // Commented to avoid bad looking logs



    switch (select)
    {
        case DmiChassisContainedElementTypeSelect::BASEBOARD_TYPE: return "BASEBOARD_TYPE";
        case DmiChassisContainedElementTypeSelect::DMI_ENTRY_TYPE: return "DMI_ENTRY_TYPE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiChassisContainedElementTypeSelect select) // TEST: NO
{
    // COMMON_LT((" | select = %u", select)); // Commented to avoid bad looking logs



    static char8 res[22];

    sprintf(res, "0x%02X (%s)", select, enumToString(select));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMICHASSISCONTAINEDELEMENTTYPESELECT_H
