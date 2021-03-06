#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFILOCATESEARCHTYPE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFILOCATESEARCHTYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class UefiLocateSearchType: u32
{
    ALL_HANDLES        = 0,
    BY_REGISTER_NOTIFY = 1,
    BY_PROTOCOL        = 2
};



inline const char8* enumToString(UefiLocateSearchType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case UefiLocateSearchType::ALL_HANDLES:        return "ALL_HANDLES";
        case UefiLocateSearchType::BY_REGISTER_NOTIFY: return "BY_REGISTER_NOTIFY";
        case UefiLocateSearchType::BY_PROTOCOL:        return "BY_PROTOCOL";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(UefiLocateSearchType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFILOCATESEARCHTYPE_H
