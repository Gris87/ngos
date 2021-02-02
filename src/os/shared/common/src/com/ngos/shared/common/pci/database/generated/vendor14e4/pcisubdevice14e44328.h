// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44328_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44328_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E44328: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280009 = 0x10280009,
    SUBDEVICE_1028000A = 0x1028000A,
    SUBDEVICE_103C1366 = 0x103C1366,
    SUBDEVICE_103C1367 = 0x103C1367,
    SUBDEVICE_103C1368 = 0x103C1368,
    SUBDEVICE_103C1369 = 0x103C1369,
    SUBDEVICE_106B0087 = 0x106B0087,
    SUBDEVICE_106B0088 = 0x106B0088,
    SUBDEVICE_106B008B = 0x106B008B,
    SUBDEVICE_106B008C = 0x106B008C,
    SUBDEVICE_106B0090 = 0x106B0090,
    SUBDEVICE_14E44328 = 0x14E44328,
    SUBDEVICE_17370066 = 0x17370066,
    SUBDEVICE_17370068 = 0x17370068
};



inline const char8* enumToString(PciSubDevice14E44328 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44328::NONE:               return "NONE";
        case PciSubDevice14E44328::SUBDEVICE_10280009: return "SUBDEVICE_10280009";
        case PciSubDevice14E44328::SUBDEVICE_1028000A: return "SUBDEVICE_1028000A";
        case PciSubDevice14E44328::SUBDEVICE_103C1366: return "SUBDEVICE_103C1366";
        case PciSubDevice14E44328::SUBDEVICE_103C1367: return "SUBDEVICE_103C1367";
        case PciSubDevice14E44328::SUBDEVICE_103C1368: return "SUBDEVICE_103C1368";
        case PciSubDevice14E44328::SUBDEVICE_103C1369: return "SUBDEVICE_103C1369";
        case PciSubDevice14E44328::SUBDEVICE_106B0087: return "SUBDEVICE_106B0087";
        case PciSubDevice14E44328::SUBDEVICE_106B0088: return "SUBDEVICE_106B0088";
        case PciSubDevice14E44328::SUBDEVICE_106B008B: return "SUBDEVICE_106B008B";
        case PciSubDevice14E44328::SUBDEVICE_106B008C: return "SUBDEVICE_106B008C";
        case PciSubDevice14E44328::SUBDEVICE_106B0090: return "SUBDEVICE_106B0090";
        case PciSubDevice14E44328::SUBDEVICE_14E44328: return "SUBDEVICE_14E44328";
        case PciSubDevice14E44328::SUBDEVICE_17370066: return "SUBDEVICE_17370066";
        case PciSubDevice14E44328::SUBDEVICE_17370068: return "SUBDEVICE_17370068";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E44328 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E44328 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44328::SUBDEVICE_10280009: return "Wireless 1500 Draft 802.11n WLAN Mini-Card";
        case PciSubDevice14E44328::SUBDEVICE_1028000A: return "Wireless 1500 Draft 802.11n WLAN Mini-card";
        case PciSubDevice14E44328::SUBDEVICE_103C1366: return "BCM4321 802.11a/b/g/n Wireless LAN Controller";
        case PciSubDevice14E44328::SUBDEVICE_103C1367: return "BCM4321 802.11a/b/g/n Wireless LAN Controller";
        case PciSubDevice14E44328::SUBDEVICE_103C1368: return "BCM4321 802.11a/b/g/n Wireless LAN Controller";
        case PciSubDevice14E44328::SUBDEVICE_103C1369: return "BCM4321 802.11a/b/g/n Wireless LAN Controller";
        case PciSubDevice14E44328::SUBDEVICE_106B0087: return "AirPort Extreme";
        case PciSubDevice14E44328::SUBDEVICE_106B0088: return "AirPort Extreme";
        case PciSubDevice14E44328::SUBDEVICE_106B008B: return "AirPort Extreme";
        case PciSubDevice14E44328::SUBDEVICE_106B008C: return "AirPort Extreme";
        case PciSubDevice14E44328::SUBDEVICE_106B0090: return "AirPort Extreme";
        case PciSubDevice14E44328::SUBDEVICE_14E44328: return "BCM4328 802.11a/b/g/n";
        case PciSubDevice14E44328::SUBDEVICE_17370066: return "WPC600N v1 802.11a/b/g/n Wireless-N CardBus Adapter";
        case PciSubDevice14E44328::SUBDEVICE_17370068: return "WEC600N v1 802.11a/b/g/n Wireless-N ExpressCard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44328_H
