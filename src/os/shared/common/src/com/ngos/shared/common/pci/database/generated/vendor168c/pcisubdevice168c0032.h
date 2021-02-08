// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0032_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0032_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice168C0032: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280208 = 0x10280208,
    SUBDEVICE_103C1838 = 0x103C1838,
    SUBDEVICE_105BE044 = 0x105BE044,
    SUBDEVICE_144D410E = 0x144D410E,
    SUBDEVICE_1A3B1186 = 0x1A3B1186
};



inline const char8* enumToString(PciSubDevice168C0032 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C0032::NONE:               return "NONE";
        case PciSubDevice168C0032::SUBDEVICE_10280208: return "SUBDEVICE_10280208";
        case PciSubDevice168C0032::SUBDEVICE_103C1838: return "SUBDEVICE_103C1838";
        case PciSubDevice168C0032::SUBDEVICE_105BE044: return "SUBDEVICE_105BE044";
        case PciSubDevice168C0032::SUBDEVICE_144D410E: return "SUBDEVICE_144D410E";
        case PciSubDevice168C0032::SUBDEVICE_1A3B1186: return "SUBDEVICE_1A3B1186";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice168C0032 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice168C0032 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C0032::SUBDEVICE_10280208: return "Wireless 1506 WLAN Half Mini-Card";
        case PciSubDevice168C0032::SUBDEVICE_103C1838: return "AR9485/HB125 802.11bgn 1x1 Wi-Fi Adapter";
        case PciSubDevice168C0032::SUBDEVICE_105BE044: return "Unex DHXA-225";
        case PciSubDevice168C0032::SUBDEVICE_144D410E: return "AR9485WB-EG 802.11b/g/n mini-PCIe card on a series 3 laptop";
        case PciSubDevice168C0032::SUBDEVICE_1A3B1186: return "AW-NE186H";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0032_H
