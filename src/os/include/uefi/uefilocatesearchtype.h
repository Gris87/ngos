#ifndef UEFI_UEFILOCATESEARCHTYPE_H
#define UEFI_UEFILOCATESEARCHTYPE_H



#include <ngos/types.h>



enum class UefiLocateSearchType: u32
{
    ALL_HANDLES        = 0,
    BY_REGISTER_NOTIFY = 1,
    BY_PROTOCOL        = 2
};



inline const char8* uefiLocateSearchTypeToString(UefiLocateSearchType type) // TEST: NO
{
    switch (type)
    {
        case UefiLocateSearchType::ALL_HANDLES:        return "ALL_HANDLES";
        case UefiLocateSearchType::BY_REGISTER_NOTIFY: return "BY_REGISTER_NOTIFY";
        case UefiLocateSearchType::BY_PROTOCOL:        return "BY_PROTOCOL";

        default: return "UNKNOWN";
    }
}



#endif // UEFI_UEFILOCATESEARCHTYPE_H
