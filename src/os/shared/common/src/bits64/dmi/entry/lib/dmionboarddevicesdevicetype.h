#ifndef OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIONBOARDDEVICESDEVICETYPE_H
#define OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIONBOARDDEVICESDEVICETYPE_H



#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/printf/printf.h>
#include <ngos/types.h>



enum class DmiOnboardDevicesDeviceType: u8
{
    NONE            = 0,
    OTHER           = 1,
    UNKNOWN         = 2,
    VIDEO           = 3,
    SCSI_CONTROLLER = 4,
    ETHERNET        = 5,
    TOKEN_RING      = 6,
    SOUND           = 7,
    PATA_CONTROLLER = 8,
    SATA_CONTROLLER = 9,
    SAS_CONTROLLER  = 10
};



inline const char8* enumToString(DmiOnboardDevicesDeviceType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DmiOnboardDevicesDeviceType::NONE:              return "NONE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiOnboardDevicesDeviceType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[25];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_DMI_ENTRY_LIB_DMIONBOARDDEVICESDEVICETYPE_H
