#ifndef UEFI_UEFILOCATESEARCHTYPE_H
#define UEFI_UEFILOCATESEARCHTYPE_H



#include <ngos/types.h>



enum class UefiLocateSearchType: u32
{
    ALL_HANDLES,
    BY_REGISTER_NOTIFY,
    BY_PROTOCOL
};



inline const char* uefiLocateSearchTypeToString(UefiLocateSearchType type) // TEST: NO
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
