// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44318_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44318_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E44318: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280005 = 0x10280005,
    SUBDEVICE_10280006 = 0x10280006,
    SUBDEVICE_103C1355 = 0x103C1355,
    SUBDEVICE_103C1356 = 0x103C1356,
    SUBDEVICE_103C1357 = 0x103C1357,
    SUBDEVICE_1043100F = 0x1043100F,
    SUBDEVICE_1043120F = 0x1043120F,
    SUBDEVICE_11540355 = 0x11540355,
    SUBDEVICE_14680311 = 0x14680311,
    SUBDEVICE_14680312 = 0x14680312,
    SUBDEVICE_14E40449 = 0x14E40449,
    SUBDEVICE_16EC0119 = 0x16EC0119,
    SUBDEVICE_17370042 = 0x17370042,
    SUBDEVICE_17370048 = 0x17370048,
    SUBDEVICE_17370049 = 0x17370049,
    SUBDEVICE_17997000 = 0x17997000,
    SUBDEVICE_17997001 = 0x17997001,
    SUBDEVICE_17997010 = 0x17997010,
    SUBDEVICE_17997011 = 0x17997011
};



inline const char8* enumToString(PciSubDevice14E44318 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44318::NONE:               return "NONE";
        case PciSubDevice14E44318::SUBDEVICE_10280005: return "SUBDEVICE_10280005";
        case PciSubDevice14E44318::SUBDEVICE_10280006: return "SUBDEVICE_10280006";
        case PciSubDevice14E44318::SUBDEVICE_103C1355: return "SUBDEVICE_103C1355";
        case PciSubDevice14E44318::SUBDEVICE_103C1356: return "SUBDEVICE_103C1356";
        case PciSubDevice14E44318::SUBDEVICE_103C1357: return "SUBDEVICE_103C1357";
        case PciSubDevice14E44318::SUBDEVICE_1043100F: return "SUBDEVICE_1043100F";
        case PciSubDevice14E44318::SUBDEVICE_1043120F: return "SUBDEVICE_1043120F";
        case PciSubDevice14E44318::SUBDEVICE_11540355: return "SUBDEVICE_11540355";
        case PciSubDevice14E44318::SUBDEVICE_14680311: return "SUBDEVICE_14680311";
        case PciSubDevice14E44318::SUBDEVICE_14680312: return "SUBDEVICE_14680312";
        case PciSubDevice14E44318::SUBDEVICE_14E40449: return "SUBDEVICE_14E40449";
        case PciSubDevice14E44318::SUBDEVICE_16EC0119: return "SUBDEVICE_16EC0119";
        case PciSubDevice14E44318::SUBDEVICE_17370042: return "SUBDEVICE_17370042";
        case PciSubDevice14E44318::SUBDEVICE_17370048: return "SUBDEVICE_17370048";
        case PciSubDevice14E44318::SUBDEVICE_17370049: return "SUBDEVICE_17370049";
        case PciSubDevice14E44318::SUBDEVICE_17997000: return "SUBDEVICE_17997000";
        case PciSubDevice14E44318::SUBDEVICE_17997001: return "SUBDEVICE_17997001";
        case PciSubDevice14E44318::SUBDEVICE_17997010: return "SUBDEVICE_17997010";
        case PciSubDevice14E44318::SUBDEVICE_17997011: return "SUBDEVICE_17997011";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E44318 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E44318 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44318::SUBDEVICE_10280005: return "Wireless 1370 WLAN Mini-PCI Card";
        case PciSubDevice14E44318::SUBDEVICE_10280006: return "Wireless 1370 WLAN PC Card";
        case PciSubDevice14E44318::SUBDEVICE_103C1355: return "Broadcom 802.11b/g WLAN";
        case PciSubDevice14E44318::SUBDEVICE_103C1356: return "Broadcom 802.11b/g WLAN";
        case PciSubDevice14E44318::SUBDEVICE_103C1357: return "Broadcom 802.11b/g WLAN";
        case PciSubDevice14E44318::SUBDEVICE_1043100F: return "WL-138G v2 / WL-138gE / WL-100gE";
        case PciSubDevice14E44318::SUBDEVICE_1043120F: return "A6U notebook embedded card";
        case PciSubDevice14E44318::SUBDEVICE_11540355: return "Buffalo WLI2-PCI-G54S High Speed Mode Wireless Adapter";
        case PciSubDevice14E44318::SUBDEVICE_14680311: return "Aspire 3022WLMi, 5024WLMi, 5020";
        case PciSubDevice14E44318::SUBDEVICE_14680312: return "TravelMate 2410";
        case PciSubDevice14E44318::SUBDEVICE_14E40449: return "Gateway 7510GX";
        case PciSubDevice14E44318::SUBDEVICE_16EC0119: return "U.S.Robotics Wireless MAXg PC Card";
        case PciSubDevice14E44318::SUBDEVICE_17370042: return "WMP54GS v1.1 802.11g Wireless-G PCI Adapter with SpeedBooster";
        case PciSubDevice14E44318::SUBDEVICE_17370048: return "WPC54G v3 802.11g Wireless-G Notebook Adapter";
        case PciSubDevice14E44318::SUBDEVICE_17370049: return "WPC54GS v2 802.11g Wireless-G Notebook Adapter with SpeedBooster";
        case PciSubDevice14E44318::SUBDEVICE_17997000: return "F5D7000 v4000 Wireless G Desktop Card";
        case PciSubDevice14E44318::SUBDEVICE_17997001: return "F5D7001 v2000 Wireless G Plus Desktop Card";
        case PciSubDevice14E44318::SUBDEVICE_17997010: return "F5D7010 v4000 Wireless G Notebook Card";
        case PciSubDevice14E44318::SUBDEVICE_17997011: return "F5D7011 v2000 High-Speed Mode Wireless G Notebook Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44318_H
