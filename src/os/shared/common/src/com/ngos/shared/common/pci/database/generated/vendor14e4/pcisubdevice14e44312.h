// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44312_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44312_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E44312: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280007 = 0x10280007,
    SUBDEVICE_10280008 = 0x10280008,
    SUBDEVICE_103C135A = 0x103C135A,
    SUBDEVICE_103C135F = 0x103C135F,
    SUBDEVICE_103C1360 = 0x103C1360,
    SUBDEVICE_103C1361 = 0x103C1361,
    SUBDEVICE_103C1362 = 0x103C1362,
    SUBDEVICE_103C1370 = 0x103C1370,
    SUBDEVICE_103C1371 = 0x103C1371,
    SUBDEVICE_103C1372 = 0x103C1372,
    SUBDEVICE_103C1373 = 0x103C1373,
    SUBDEVICE_103C30B5 = 0x103C30B5,
    SUBDEVICE_106B0089 = 0x106B0089,
    SUBDEVICE_1371103C = 0x1371103C
};



inline const char8* enumToString(PciSubDevice14E44312 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44312::NONE:               return "NONE";
        case PciSubDevice14E44312::SUBDEVICE_10280007: return "SUBDEVICE_10280007";
        case PciSubDevice14E44312::SUBDEVICE_10280008: return "SUBDEVICE_10280008";
        case PciSubDevice14E44312::SUBDEVICE_103C135A: return "SUBDEVICE_103C135A";
        case PciSubDevice14E44312::SUBDEVICE_103C135F: return "SUBDEVICE_103C135F";
        case PciSubDevice14E44312::SUBDEVICE_103C1360: return "SUBDEVICE_103C1360";
        case PciSubDevice14E44312::SUBDEVICE_103C1361: return "SUBDEVICE_103C1361";
        case PciSubDevice14E44312::SUBDEVICE_103C1362: return "SUBDEVICE_103C1362";
        case PciSubDevice14E44312::SUBDEVICE_103C1370: return "SUBDEVICE_103C1370";
        case PciSubDevice14E44312::SUBDEVICE_103C1371: return "SUBDEVICE_103C1371";
        case PciSubDevice14E44312::SUBDEVICE_103C1372: return "SUBDEVICE_103C1372";
        case PciSubDevice14E44312::SUBDEVICE_103C1373: return "SUBDEVICE_103C1373";
        case PciSubDevice14E44312::SUBDEVICE_103C30B5: return "SUBDEVICE_103C30B5";
        case PciSubDevice14E44312::SUBDEVICE_106B0089: return "SUBDEVICE_106B0089";
        case PciSubDevice14E44312::SUBDEVICE_1371103C: return "SUBDEVICE_1371103C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E44312 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E44312 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44312::SUBDEVICE_10280007: return "Wireless 1490 Dual Band WLAN Mini-Card";
        case PciSubDevice14E44312::SUBDEVICE_10280008: return "Wireless 1490 Dual Band WLAN ExpressCard";
        case PciSubDevice14E44312::SUBDEVICE_103C135A: return "Broadcom 802.11a/b/g WLAN";
        case PciSubDevice14E44312::SUBDEVICE_103C135F: return "Broadcom 802.11a/b/g WLAN";
        case PciSubDevice14E44312::SUBDEVICE_103C1360: return "Broadcom 802.11a/b/g WLAN";
        case PciSubDevice14E44312::SUBDEVICE_103C1361: return "Broadcom 802.11a/b/g WLAN";
        case PciSubDevice14E44312::SUBDEVICE_103C1362: return "Broadcom 802.11a/b/g WLAN";
        case PciSubDevice14E44312::SUBDEVICE_103C1370: return "Broadcom 802.11a/b/g WLAN";
        case PciSubDevice14E44312::SUBDEVICE_103C1371: return "Broadcom 802.11a/b/g WLAN";
        case PciSubDevice14E44312::SUBDEVICE_103C1372: return "Broadcom 802.11a/b/g WLAN";
        case PciSubDevice14E44312::SUBDEVICE_103C1373: return "Broadcom 802.11a/b/g WLAN";
        case PciSubDevice14E44312::SUBDEVICE_103C30B5: return "Presario V3242AU";
        case PciSubDevice14E44312::SUBDEVICE_106B0089: return "AirPort Extreme";
        case PciSubDevice14E44312::SUBDEVICE_1371103C: return "Broadcom 802.11 Multiband-netwerkadapter(6715s)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44312_H
