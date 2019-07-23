#ifndef UEFI_UEFIRESETTYPE_H
#define UEFI_UEFIRESETTYPE_H



#include <ngos/types.h>



enum class UefiResetType: u32
{
    COLD     = 0,
    WARM     = 1,
    SHUTDOWN = 2
};



inline const char* uefiResetTypeToString(UefiResetType type) // TEST: NO
{
    switch (type)
    {
        case UefiResetType::COLD:     return "COLD";
        case UefiResetType::WARM:     return "WARM";
        case UefiResetType::SHUTDOWN: return "SHUTDOWN";

        default: return "UNKNOWN";
    }
}



#endif // UEFI_UEFIRESETTYPE_H
