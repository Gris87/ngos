// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0030_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0030_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice168C0030: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1627 = 0x103C1627,
    SUBDEVICE_106B009A = 0x106B009A,
    SUBDEVICE_11863A7E = 0x11863A7E,
    SUBDEVICE_1A562000 = 0x1A562000,
    SUBDEVICE_1A562001 = 0x1A562001
};



inline const char8* enumToString(PciSubDevice168C0030 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C0030::NONE:               return "NONE";
        case PciSubDevice168C0030::SUBDEVICE_103C1627: return "SUBDEVICE_103C1627";
        case PciSubDevice168C0030::SUBDEVICE_106B009A: return "SUBDEVICE_106B009A";
        case PciSubDevice168C0030::SUBDEVICE_11863A7E: return "SUBDEVICE_11863A7E";
        case PciSubDevice168C0030::SUBDEVICE_1A562000: return "SUBDEVICE_1A562000";
        case PciSubDevice168C0030::SUBDEVICE_1A562001: return "SUBDEVICE_1A562001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice168C0030 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice168C0030 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C0030::SUBDEVICE_103C1627: return "AR9380/HB112 802.11abgn 3x3 Wi-Fi Adapter";
        case PciSubDevice168C0030::SUBDEVICE_106B009A: return "AirPort Extreme";
        case PciSubDevice168C0030::SUBDEVICE_11863A7E: return "DWA-566 Wireless N 300 Dual Band PCIe Desktop Adapter";
        case PciSubDevice168C0030::SUBDEVICE_1A562000: return "Killer Wireless-N 1102 Half-size Mini PCIe Card [AR9382]";
        case PciSubDevice168C0030::SUBDEVICE_1A562001: return "Killer Wireless-N 1103 Half-size Mini PCIe Card [AR9380]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0030_H
