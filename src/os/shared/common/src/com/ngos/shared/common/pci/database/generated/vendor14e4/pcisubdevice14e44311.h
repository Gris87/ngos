// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44311_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44311_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E44311: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280007 = 0x10280007,
    SUBDEVICE_10280008 = 0x10280008,
    SUBDEVICE_103C1363 = 0x103C1363,
    SUBDEVICE_103C1364 = 0x103C1364,
    SUBDEVICE_103C1365 = 0x103C1365,
    SUBDEVICE_103C1374 = 0x103C1374,
    SUBDEVICE_103C1375 = 0x103C1375,
    SUBDEVICE_103C1376 = 0x103C1376,
    SUBDEVICE_103C1377 = 0x103C1377,
    SUBDEVICE_103C137F = 0x103C137F,
    SUBDEVICE_103C1380 = 0x103C1380,
    SUBDEVICE_14E44311 = 0x14E44311
};



inline const char8* enumToString(PciSubDevice14E44311 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44311::NONE:               return "NONE";
        case PciSubDevice14E44311::SUBDEVICE_10280007: return "SUBDEVICE_10280007";
        case PciSubDevice14E44311::SUBDEVICE_10280008: return "SUBDEVICE_10280008";
        case PciSubDevice14E44311::SUBDEVICE_103C1363: return "SUBDEVICE_103C1363";
        case PciSubDevice14E44311::SUBDEVICE_103C1364: return "SUBDEVICE_103C1364";
        case PciSubDevice14E44311::SUBDEVICE_103C1365: return "SUBDEVICE_103C1365";
        case PciSubDevice14E44311::SUBDEVICE_103C1374: return "SUBDEVICE_103C1374";
        case PciSubDevice14E44311::SUBDEVICE_103C1375: return "SUBDEVICE_103C1375";
        case PciSubDevice14E44311::SUBDEVICE_103C1376: return "SUBDEVICE_103C1376";
        case PciSubDevice14E44311::SUBDEVICE_103C1377: return "SUBDEVICE_103C1377";
        case PciSubDevice14E44311::SUBDEVICE_103C137F: return "SUBDEVICE_103C137F";
        case PciSubDevice14E44311::SUBDEVICE_103C1380: return "SUBDEVICE_103C1380";
        case PciSubDevice14E44311::SUBDEVICE_14E44311: return "SUBDEVICE_14E44311";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E44311 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E44311 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44311::SUBDEVICE_10280007: return "Wireless 1390 WLAN Mini-Card";
        case PciSubDevice14E44311::SUBDEVICE_10280008: return "Wireless 1390 WLAN ExpressCard";
        case PciSubDevice14E44311::SUBDEVICE_103C1363: return "BCM4311 802.11b/g Wireless LAN Controller";
        case PciSubDevice14E44311::SUBDEVICE_103C1364: return "BCM4311 802.11b/g Wireless LAN Controller";
        case PciSubDevice14E44311::SUBDEVICE_103C1365: return "BCM4311 802.11b/g Wireless LAN Controller";
        case PciSubDevice14E44311::SUBDEVICE_103C1374: return "BCM4311 802.11b/g Wireless LAN Controller";
        case PciSubDevice14E44311::SUBDEVICE_103C1375: return "BCM4311 802.11b/g Wireless LAN Controller";
        case PciSubDevice14E44311::SUBDEVICE_103C1376: return "BCM4311 802.11b/g Wireless LAN Controller";
        case PciSubDevice14E44311::SUBDEVICE_103C1377: return "BCM4311 802.11b/g Wireless LAN Controller";
        case PciSubDevice14E44311::SUBDEVICE_103C137F: return "BCM4322 802.11a/b/g/n Wireless LAN Controller";
        case PciSubDevice14E44311::SUBDEVICE_103C1380: return "BCM4322 802.11a/b/g/n Wireless LAN Controller";
        case PciSubDevice14E44311::SUBDEVICE_14E44311: return "BCM94311MCG";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44311_H
