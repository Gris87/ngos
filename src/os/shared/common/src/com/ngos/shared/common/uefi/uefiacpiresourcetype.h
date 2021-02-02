#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIACPIRESOURCETYPE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIACPIRESOURCETYPE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class UefiAcpiResourceType: bad_uint8
{
    MEMORY = 0,
    IO     = 1,
    BUS    = 2
};



inline const char8* enumToString(UefiAcpiResourceType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case UefiAcpiResourceType::MEMORY: return "MEMORY";
        case UefiAcpiResourceType::IO:     return "IO";
        case UefiAcpiResourceType::BUS:    return "BUS";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(UefiAcpiResourceType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[15];

    sprintf(res, "0x%02X (%s)", (bad_uint8)type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIACPIRESOURCETYPE_H
