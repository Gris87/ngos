#ifndef KERNEL_SRC_COM_NGOS_KERNEL_OTHER_IOREMAP_FIXMAP_H
#define KERNEL_SRC_COM_NGOS_KERNEL_OTHER_IOREMAP_FIXMAP_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/ngos/types.h>



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

    sprintf(res, "0x%02X (%s)", map, enumToString(map));

    return res;
}



#endif // KERNEL_SRC_COM_NGOS_KERNEL_OTHER_IOREMAP_FIXMAP_H
