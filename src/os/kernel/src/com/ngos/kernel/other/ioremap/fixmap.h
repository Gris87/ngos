#ifndef COM_NGOS_KERNEL_OTHER_IOREMAP_FIXMAP_H
#define COM_NGOS_KERNEL_OTHER_IOREMAP_FIXMAP_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class FixMap: u8
{
    MAXIMUM
};



inline const char8* enumToString(FixMap map) // TEST: NO
{
    // COMMON_LT((" | map = %u", map)); // Commented to avoid bad looking logs



    switch (map)
    {
        case FixMap::MAXIMUM: return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(FixMap map) // TEST: NO
{
    // COMMON_LT((" | map = %u", map)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (u8)map, enumToString(map));

    return res;
}



#endif // COM_NGOS_KERNEL_OTHER_IOREMAP_FIXMAP_H
