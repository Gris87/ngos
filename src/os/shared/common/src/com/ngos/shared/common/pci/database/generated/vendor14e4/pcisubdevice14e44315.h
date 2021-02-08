// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44315_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44315_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E44315: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028000B = 0x1028000B,
    SUBDEVICE_1028000C = 0x1028000C,
    SUBDEVICE_103C137C = 0x103C137C,
    SUBDEVICE_103C137D = 0x103C137D,
    SUBDEVICE_103C1507 = 0x103C1507,
    SUBDEVICE_105BE003 = 0x105BE003,
    SUBDEVICE_105BE01B = 0x105BE01B
};



inline const char8* enumToString(PciSubDevice14E44315 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44315::NONE:               return "NONE";
        case PciSubDevice14E44315::SUBDEVICE_1028000B: return "SUBDEVICE_1028000B";
        case PciSubDevice14E44315::SUBDEVICE_1028000C: return "SUBDEVICE_1028000C";
        case PciSubDevice14E44315::SUBDEVICE_103C137C: return "SUBDEVICE_103C137C";
        case PciSubDevice14E44315::SUBDEVICE_103C137D: return "SUBDEVICE_103C137D";
        case PciSubDevice14E44315::SUBDEVICE_103C1507: return "SUBDEVICE_103C1507";
        case PciSubDevice14E44315::SUBDEVICE_105BE003: return "SUBDEVICE_105BE003";
        case PciSubDevice14E44315::SUBDEVICE_105BE01B: return "SUBDEVICE_105BE01B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E44315 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E44315 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44315::SUBDEVICE_1028000B: return "Wireless 1395 WLAN Mini-Card";
        case PciSubDevice14E44315::SUBDEVICE_1028000C: return "Wireless 1397 WLAN Mini-Card";
        case PciSubDevice14E44315::SUBDEVICE_103C137C: return "BCM4312 802.11b/g Wireless LAN Controller";
        case PciSubDevice14E44315::SUBDEVICE_103C137D: return "BCM4312 802.11b/g Wireless LAN Controller";
        case PciSubDevice14E44315::SUBDEVICE_103C1507: return "U98Z049.00 Wireless Mini PCIe Card";
        case PciSubDevice14E44315::SUBDEVICE_105BE003: return "T77H030.00 Wireless Mini PCIe Card";
        case PciSubDevice14E44315::SUBDEVICE_105BE01B: return "T77H106.00 Wireless Half-size Mini PCIe Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44315_H
