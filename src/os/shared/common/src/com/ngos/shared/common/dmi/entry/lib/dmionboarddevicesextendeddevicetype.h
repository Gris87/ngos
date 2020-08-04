#ifndef COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIONBOARDDEVICESEXTENDEDDEVICETYPE_H
#define COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIONBOARDDEVICESEXTENDEDDEVICETYPE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class DmiOnboardDevicesExtendedDeviceType: u8
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



inline const char8* enumToString(DmiOnboardDevicesExtendedDeviceType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case DmiOnboardDevicesExtendedDeviceType::NONE:            return "NONE";
        case DmiOnboardDevicesExtendedDeviceType::OTHER:           return "OTHER";
        case DmiOnboardDevicesExtendedDeviceType::UNKNOWN:         return "UNKNOWN";
        case DmiOnboardDevicesExtendedDeviceType::VIDEO:           return "VIDEO";
        case DmiOnboardDevicesExtendedDeviceType::SCSI_CONTROLLER: return "SCSI_CONTROLLER";
        case DmiOnboardDevicesExtendedDeviceType::ETHERNET:        return "ETHERNET";
        case DmiOnboardDevicesExtendedDeviceType::TOKEN_RING:      return "TOKEN_RING";
        case DmiOnboardDevicesExtendedDeviceType::SOUND:           return "SOUND";
        case DmiOnboardDevicesExtendedDeviceType::PATA_CONTROLLER: return "PATA_CONTROLLER";
        case DmiOnboardDevicesExtendedDeviceType::SATA_CONTROLLER: return "SATA_CONTROLLER";
        case DmiOnboardDevicesExtendedDeviceType::SAS_CONTROLLER:  return "SAS_CONTROLLER";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(DmiOnboardDevicesExtendedDeviceType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_DMI_ENTRY_LIB_DMIONBOARDDEVICESEXTENDEDDEVICETYPE_H
