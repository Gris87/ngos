#ifndef CONFIGURE_SRC_BITS64_B_EARLY_OTHER_UNAVAILABLEMEMORYAREA_H
#define CONFIGURE_SRC_BITS64_B_EARLY_OTHER_UNAVAILABLEMEMORYAREA_H



#include <ngos/types.h>



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



inline const char* unavailableMemoryAreaToString(UnavailableMemoryArea area) // TEST: NO
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



#endif // CONFIGURE_SRC_BITS64_B_EARLY_OTHER_UNAVAILABLEMEMORYAREA_H
