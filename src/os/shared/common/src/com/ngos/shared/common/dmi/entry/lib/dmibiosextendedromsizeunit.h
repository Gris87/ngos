#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZEUNIT_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZEUNIT_H



#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



enum class DmiBiosExtendedRomSizeUnit: u8
{
    MEGABYTES = 0,
    GIGABYTES = 1
};



inline const char8* enumToString(DmiBiosExtendedRomSizeUnit unit) // TEST: NO
{
    // COMMON_LT((" | unit = %u", unit)); // Commented to avoid bad looking logs



    switch (unit)
    {
        case DmiBiosExtendedRomSizeUnit::MEGABYTES: return "MEGABYTES";
        case DmiBiosExtendedRomSizeUnit::GIGABYTES: return "GIGABYTES";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiBiosExtendedRomSizeUnit unit) // TEST: NO
{
    // COMMON_LT((" | unit = %u", unit)); // Commented to avoid bad looking logs



    static char8 res[17];

    sprintf(res, "0x%02X (%s)", unit, enumToString(unit));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIBIOSEXTENDEDROMSIZEUNIT_H
