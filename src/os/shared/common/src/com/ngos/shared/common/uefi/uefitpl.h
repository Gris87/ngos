#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFITPL_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFITPL_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class UefiTpl: u64
{
    NONE        = 0,
    APPLICATION = 4,
    CALLBACK    = 8,
    NOTIFY      = 16,
    HIGH_LEVEL  = 31
};



inline const char8* enumToString(UefiTpl tpl) // TEST: NO
{
    // COMMON_LT((" | tpl = %u", tpl)); // Commented to avoid bad looking logs



    switch (tpl)
    {
        case UefiTpl::NONE:        return "NONE";
        case UefiTpl::APPLICATION: return "APPLICATION";
        case UefiTpl::CALLBACK:    return "CALLBACK";
        case UefiTpl::NOTIFY:      return "NOTIFY";
        case UefiTpl::HIGH_LEVEL:  return "HIGH_LEVEL";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(UefiTpl tpl) // TEST: NO
{
    // COMMON_LT((" | tpl = %u", tpl)); // Commented to avoid bad looking logs



    static char8 res[33];

    sprintf(res, "0x%016llX (%s)", (u64)tpl, enumToString(tpl));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFITPL_H
