#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIEVENTTYPE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIEVENTTYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class UefiEventType: u32
{
    NONE                          = 0,
    NOTIFY_WAIT                   = 0x00000100,
    NOTIFY_SIGNAL                 = 0x00000200,
    SIGNAL_EXIT_BOOT_SERVICES     = 0x00000201,
    RUNTIME                       = 0x40000000,
    SIGNAL_VIRTUAL_ADDRESS_CHANGE = 0x60000202,
    TIMER                         = 0x80000000
};



inline const char8* enumToString(UefiEventType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case UefiEventType::NONE:                          return "NONE";
        case UefiEventType::NOTIFY_WAIT:                   return "NOTIFY_WAIT";
        case UefiEventType::NOTIFY_SIGNAL:                 return "NOTIFY_SIGNAL";
        case UefiEventType::SIGNAL_EXIT_BOOT_SERVICES:     return "SIGNAL_EXIT_BOOT_SERVICES";
        case UefiEventType::RUNTIME:                       return "RUNTIME";
        case UefiEventType::SIGNAL_VIRTUAL_ADDRESS_CHANGE: return "SIGNAL_VIRTUAL_ADDRESS_CHANGE";
        case UefiEventType::TIMER:                         return "TIMER";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(UefiEventType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[43];

    sprintf(res, "0x%08X (%s)", (u32)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIEVENTTYPE_H
