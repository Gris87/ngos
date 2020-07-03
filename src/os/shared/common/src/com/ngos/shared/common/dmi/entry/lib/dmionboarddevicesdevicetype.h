#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIONBOARDDEVICESDEVICETYPE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIONBOARDDEVICESDEVICETYPE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/ngos/types.h>



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
        case DmiOnboardDevicesDeviceType::NONE:            return "NONE";
        case DmiOnboardDevicesDeviceType::OTHER:           return "OTHER";
        case DmiOnboardDevicesDeviceType::UNKNOWN:         return "UNKNOWN";
        case DmiOnboardDevicesDeviceType::VIDEO:           return "VIDEO";
        case DmiOnboardDevicesDeviceType::SCSI_CONTROLLER: return "SCSI_CONTROLLER";
        case DmiOnboardDevicesDeviceType::ETHERNET:        return "ETHERNET";
        case DmiOnboardDevicesDeviceType::TOKEN_RING:      return "TOKEN_RING";
        case DmiOnboardDevicesDeviceType::SOUND:           return "SOUND";
        case DmiOnboardDevicesDeviceType::PATA_CONTROLLER: return "PATA_CONTROLLER";
        case DmiOnboardDevicesDeviceType::SATA_CONTROLLER: return "SATA_CONTROLLER";
        case DmiOnboardDevicesDeviceType::SAS_CONTROLLER:  return "SAS_CONTROLLER";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiOnboardDevicesDeviceType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIONBOARDDEVICESDEVICETYPE_H
