#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_DMISTOREDUUID_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_DMISTOREDUUID_H



#include <ngos/types.h>



enum class DmiStoredUuid: u8
{
    SYSTEM_UUID,
    MAXIMUM
};



inline const char8* dmiStoredUuidToString(DmiStoredUuid uuid) // TEST: NO
{
    // COMMON_LT((" | uuid = %u", uuid)); // Commented to avoid bad looking logs



    switch (uuid)
    {
        case DmiStoredUuid::SYSTEM_UUID: return "SYSTEM_UUID";
        case DmiStoredUuid::MAXIMUM:     return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_DMISTOREDUUID_H
