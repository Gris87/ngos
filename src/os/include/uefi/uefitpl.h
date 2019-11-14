#ifndef UEFI_UEFITPL_H
#define UEFI_UEFITPL_H



#include <ngos/types.h>



enum class UefiTpl: u64
{
    NONE        = 0,
    APPLICATION = 4,
    CALLBACK    = 8,
    NOTIFY      = 16,
    HIGH_LEVEL  = 31
};



inline const char8* uefiTplToString(UefiTpl type) // TEST: NO
{
    switch (type)
    {
        case UefiTpl::NONE:        return "NONE";
        case UefiTpl::APPLICATION: return "APPLICATION";
        case UefiTpl::CALLBACK:    return "CALLBACK";
        case UefiTpl::NOTIFY:      return "NOTIFY";
        case UefiTpl::HIGH_LEVEL:  return "HIGH_LEVEL";

        default: return "UNKNOWN";
    }
}



#endif // UEFI_UEFITPL_H
