#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_IOREMAP_FIXMAP_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_IOREMAP_FIXMAP_H



#include <ngos/types.h>



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



    switch (map)
    {
        case FixMap::MAXIMUM: return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_IOREMAP_FIXMAP_H
