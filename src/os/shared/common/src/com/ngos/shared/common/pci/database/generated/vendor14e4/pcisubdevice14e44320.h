// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44320_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44320_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E44320: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280001 = 0x10280001,
    SUBDEVICE_10280002 = 0x10280002,
    SUBDEVICE_10280003 = 0x10280003,
    SUBDEVICE_10280004 = 0x10280004,
    SUBDEVICE_103C12F4 = 0x103C12F4,
    SUBDEVICE_103C12F8 = 0x103C12F8,
    SUBDEVICE_103C12FA = 0x103C12FA,
    SUBDEVICE_103C12FB = 0x103C12FB,
    SUBDEVICE_1043100F = 0x1043100F,
    SUBDEVICE_10577025 = 0x10577025,
    SUBDEVICE_106B004E = 0x106B004E,
    SUBDEVICE_11540330 = 0x11540330,
    SUBDEVICE_144F7050 = 0x144F7050,
    SUBDEVICE_144F7051 = 0x144F7051,
    SUBDEVICE_17370013 = 0x17370013,
    SUBDEVICE_17370014 = 0x17370014,
    SUBDEVICE_17370015 = 0x17370015,
    SUBDEVICE_17374320 = 0x17374320,
    SUBDEVICE_17997000 = 0x17997000,
    SUBDEVICE_17997001 = 0x17997001,
    SUBDEVICE_17997010 = 0x17997010,
    SUBDEVICE_17997011 = 0x17997011,
    SUBDEVICE_185F1220 = 0x185F1220
};



inline const char8* enumToString(PciSubDevice14E44320 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44320::NONE:               return "NONE";
        case PciSubDevice14E44320::SUBDEVICE_10280001: return "SUBDEVICE_10280001";
        case PciSubDevice14E44320::SUBDEVICE_10280002: return "SUBDEVICE_10280002";
        case PciSubDevice14E44320::SUBDEVICE_10280003: return "SUBDEVICE_10280003";
        case PciSubDevice14E44320::SUBDEVICE_10280004: return "SUBDEVICE_10280004";
        case PciSubDevice14E44320::SUBDEVICE_103C12F4: return "SUBDEVICE_103C12F4";
        case PciSubDevice14E44320::SUBDEVICE_103C12F8: return "SUBDEVICE_103C12F8";
        case PciSubDevice14E44320::SUBDEVICE_103C12FA: return "SUBDEVICE_103C12FA";
        case PciSubDevice14E44320::SUBDEVICE_103C12FB: return "SUBDEVICE_103C12FB";
        case PciSubDevice14E44320::SUBDEVICE_1043100F: return "SUBDEVICE_1043100F";
        case PciSubDevice14E44320::SUBDEVICE_10577025: return "SUBDEVICE_10577025";
        case PciSubDevice14E44320::SUBDEVICE_106B004E: return "SUBDEVICE_106B004E";
        case PciSubDevice14E44320::SUBDEVICE_11540330: return "SUBDEVICE_11540330";
        case PciSubDevice14E44320::SUBDEVICE_144F7050: return "SUBDEVICE_144F7050";
        case PciSubDevice14E44320::SUBDEVICE_144F7051: return "SUBDEVICE_144F7051";
        case PciSubDevice14E44320::SUBDEVICE_17370013: return "SUBDEVICE_17370013";
        case PciSubDevice14E44320::SUBDEVICE_17370014: return "SUBDEVICE_17370014";
        case PciSubDevice14E44320::SUBDEVICE_17370015: return "SUBDEVICE_17370015";
        case PciSubDevice14E44320::SUBDEVICE_17374320: return "SUBDEVICE_17374320";
        case PciSubDevice14E44320::SUBDEVICE_17997000: return "SUBDEVICE_17997000";
        case PciSubDevice14E44320::SUBDEVICE_17997001: return "SUBDEVICE_17997001";
        case PciSubDevice14E44320::SUBDEVICE_17997010: return "SUBDEVICE_17997010";
        case PciSubDevice14E44320::SUBDEVICE_17997011: return "SUBDEVICE_17997011";
        case PciSubDevice14E44320::SUBDEVICE_185F1220: return "SUBDEVICE_185F1220";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E44320 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E44320 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44320::SUBDEVICE_10280001: return "TrueMobile 1300 WLAN Mini-PCI Card";
        case PciSubDevice14E44320::SUBDEVICE_10280002: return "TrueMobile 1300 WLAN PC Card";
        case PciSubDevice14E44320::SUBDEVICE_10280003: return "Wireless 1350 WLAN Mini-PCI Card";
        case PciSubDevice14E44320::SUBDEVICE_10280004: return "Wireless 1350 WLAN PC Card";
        case PciSubDevice14E44320::SUBDEVICE_103C12F4: return "Broadcom 802.11b/g WLAN";
        case PciSubDevice14E44320::SUBDEVICE_103C12F8: return "Broadcom 802.11b/g WLAN";
        case PciSubDevice14E44320::SUBDEVICE_103C12FA: return "Broadcom 802.11b/g WLAN";
        case PciSubDevice14E44320::SUBDEVICE_103C12FB: return "Broadcom 802.11b/g WLAN";
        case PciSubDevice14E44320::SUBDEVICE_1043100F: return "WL-100G";
        case PciSubDevice14E44320::SUBDEVICE_10577025: return "WN825G";
        case PciSubDevice14E44320::SUBDEVICE_106B004E: return "AirPort Extreme";
        case PciSubDevice14E44320::SUBDEVICE_11540330: return "Buffalo WLI2-PCI-G54S High Speed Mode Wireless Desktop Adapter";
        case PciSubDevice14E44320::SUBDEVICE_144F7050: return "eMachines M6805 802.11g Built-in Wireless";
        case PciSubDevice14E44320::SUBDEVICE_144F7051: return "Sonnet Aria Extreme PCI";
        case PciSubDevice14E44320::SUBDEVICE_17370013: return "WMP54G v1 802.11g PCI Adapter";
        case PciSubDevice14E44320::SUBDEVICE_17370014: return "WMP54G v2 802.11g PCI Adapter";
        case PciSubDevice14E44320::SUBDEVICE_17370015: return "WMP54GS v1.0 802.11g Wireless-G PCI Adapter with SpeedBooster";
        case PciSubDevice14E44320::SUBDEVICE_17374320: return "WPC54G v1 / WPC54GS v1 802.11g Wireless-G Notebook Adapter";
        case PciSubDevice14E44320::SUBDEVICE_17997000: return "F5D7000 v1000 Wireless G Desktop Card";
        case PciSubDevice14E44320::SUBDEVICE_17997001: return "F5D7001 v1000 Wireless G Plus Desktop Card";
        case PciSubDevice14E44320::SUBDEVICE_17997010: return "F5D7010 v1000 Wireless G Notebook Card";
        case PciSubDevice14E44320::SUBDEVICE_17997011: return "F5D7011 v1000 High-Speed Mode Wireless G Notebook Card";
        case PciSubDevice14E44320::SUBDEVICE_185F1220: return "TravelMate 290E WLAN Mini-PCI Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44320_H
