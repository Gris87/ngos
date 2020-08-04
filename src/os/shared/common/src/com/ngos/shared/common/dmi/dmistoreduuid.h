#ifndef COM_NGOS_SHARED_COMMON_DMI_DMISTOREDUUID_H
#define COM_NGOS_SHARED_COMMON_DMI_DMISTOREDUUID_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiStoredUuid: u8
{
    SYSTEM_UUID,
    MAXIMUM
};



inline const char8* enumToString(DmiStoredUuid uuid) // TEST: NO
{
    // COMMON_LT((" | uuid = %u", uuid)); // Commented to avoid bad looking logs



    switch (uuid)
    {
        case DmiStoredUuid::SYSTEM_UUID: return "SYSTEM_UUID";
        case DmiStoredUuid::MAXIMUM:     return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiStoredUuid uuid) // TEST: NO
{
    // COMMON_LT((" | uuid = %u", uuid)); // Commented to avoid bad looking logs



    static char8 res[19];

    sprintf(res, "0x%02X (%s)", uuid, enumToString(uuid));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_DMISTOREDUUID_H
