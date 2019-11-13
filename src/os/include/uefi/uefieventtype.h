#ifndef UEFI_UEFIEVENTTYPE_H
#define UEFI_UEFIEVENTTYPE_H



#include <ngos/types.h>



enum class UefiEventType: u32
{
    NONE                  = 0,
    APPLICATION_PROCESSOR = 0x00000001,
    TIMER                 = 0x80000000
};



inline const char8* uefiEventTypeToString(UefiEventType type) // TEST: NO
{
    switch (type)
    {
        case UefiEventType::NONE:                  return "NONE";
        case UefiEventType::APPLICATION_PROCESSOR: return "APPLICATION_PROCESSOR";
        case UefiEventType::TIMER:                 return "TIMER";

        default: return "UNKNOWN";
    }
}



#endif // UEFI_UEFIEVENTTYPE_H
