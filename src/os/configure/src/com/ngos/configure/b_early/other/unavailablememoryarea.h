#ifndef COM_NGOS_CONFIGURE_B_EARLY_OTHER_UNAVAILABLEMEMORYAREA_H
#define COM_NGOS_CONFIGURE_B_EARLY_OTHER_UNAVAILABLEMEMORYAREA_H



#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class UnavailableMemoryArea: u8
{
    ZERO_PAGE,
    BOOT_PARAMS,
    RELOCATED_KERNEL,
    UEFI_MEMORY_MAP,
    MEMORY_MAP,
    VIDEO_RAM,
    MAXIMUM
};



inline const char8* enumToString(UnavailableMemoryArea area) // TEST: NO
{
    // EARLY_LT((" | area = %u", area)); // Commented to avoid bad looking logs



    switch (area)
    {
        case UnavailableMemoryArea::ZERO_PAGE:        return "ZERO_PAGE";
        case UnavailableMemoryArea::BOOT_PARAMS:      return "BOOT_PARAMS";
        case UnavailableMemoryArea::RELOCATED_KERNEL: return "RELOCATED_KERNEL";
        case UnavailableMemoryArea::UEFI_MEMORY_MAP:  return "UEFI_MEMORY_MAP";
        case UnavailableMemoryArea::MEMORY_MAP:       return "MEMORY_MAP";
        case UnavailableMemoryArea::VIDEO_RAM:        return "VIDEO_RAM";
        case UnavailableMemoryArea::MAXIMUM:          return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(UnavailableMemoryArea area) // TEST: NO
{
    // EARLY_LT((" | area = %u", area)); // Commented to avoid bad looking logs



    static char8 res[24];

    sprintf(res, "0x%02X (%s)", (u8)area, enumToString(area));

    return res;
}



#endif // COM_NGOS_CONFIGURE_B_EARLY_OTHER_UNAVAILABLEMEMORYAREA_H
