// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C001C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C001C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice168C001C: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_07773006 = 0x07773006,
    SUBDEVICE_103C137A = 0x103C137A,
    SUBDEVICE_106B0086 = 0x106B0086,
    SUBDEVICE_144F7106 = 0x144F7106,
    SUBDEVICE_144F7128 = 0x144F7128,
    SUBDEVICE_14680428 = 0x14680428,
    SUBDEVICE_1468042A = 0x1468042A,
    SUBDEVICE_147B1033 = 0x147B1033,
    SUBDEVICE_168C001C = 0x168C001C,
    SUBDEVICE_168C3061 = 0x168C3061,
    SUBDEVICE_168C3062 = 0x168C3062,
    SUBDEVICE_168C3063 = 0x168C3063,
    SUBDEVICE_168C3065 = 0x168C3065,
    SUBDEVICE_168C3067 = 0x168C3067,
    SUBDEVICE_1A3B1026 = 0x1A3B1026
};



inline const char8* enumToString(PciSubDevice168C001C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C001C::NONE:               return "NONE";
        case PciSubDevice168C001C::SUBDEVICE_07773006: return "SUBDEVICE_07773006";
        case PciSubDevice168C001C::SUBDEVICE_103C137A: return "SUBDEVICE_103C137A";
        case PciSubDevice168C001C::SUBDEVICE_106B0086: return "SUBDEVICE_106B0086";
        case PciSubDevice168C001C::SUBDEVICE_144F7106: return "SUBDEVICE_144F7106";
        case PciSubDevice168C001C::SUBDEVICE_144F7128: return "SUBDEVICE_144F7128";
        case PciSubDevice168C001C::SUBDEVICE_14680428: return "SUBDEVICE_14680428";
        case PciSubDevice168C001C::SUBDEVICE_1468042A: return "SUBDEVICE_1468042A";
        case PciSubDevice168C001C::SUBDEVICE_147B1033: return "SUBDEVICE_147B1033";
        case PciSubDevice168C001C::SUBDEVICE_168C001C: return "SUBDEVICE_168C001C";
        case PciSubDevice168C001C::SUBDEVICE_168C3061: return "SUBDEVICE_168C3061";
        case PciSubDevice168C001C::SUBDEVICE_168C3062: return "SUBDEVICE_168C3062";
        case PciSubDevice168C001C::SUBDEVICE_168C3063: return "SUBDEVICE_168C3063";
        case PciSubDevice168C001C::SUBDEVICE_168C3065: return "SUBDEVICE_168C3065";
        case PciSubDevice168C001C::SUBDEVICE_168C3067: return "SUBDEVICE_168C3067";
        case PciSubDevice168C001C::SUBDEVICE_1A3B1026: return "SUBDEVICE_1A3B1026";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice168C001C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice168C001C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C001C::SUBDEVICE_07773006: return "SRX 802.11abg Wireless ExpressCard Adapter";
        case PciSubDevice168C001C::SUBDEVICE_103C137A: return "AR5BXB63 (Foxconn) 802.11bg Mini PCIe NIC";
        case PciSubDevice168C001C::SUBDEVICE_106B0086: return "AirPort Extreme";
        case PciSubDevice168C001C::SUBDEVICE_144F7106: return "WLL3140 (Toshiba PA3501U-1MPC) 802.11bg Wireless Mini PCIe Card";
        case PciSubDevice168C001C::SUBDEVICE_144F7128: return "WLL3141 (Toshiba PA3613U-1MPC) 802.11bg Wireless Mini PCIe Card";
        case PciSubDevice168C001C::SUBDEVICE_14680428: return "AR5BXB63 802.11bg NIC";
        case PciSubDevice168C001C::SUBDEVICE_1468042A: return "AR5007EG 802.11bg NIC";
        case PciSubDevice168C001C::SUBDEVICE_147B1033: return "AirPace Wi-Fi";
        case PciSubDevice168C001C::SUBDEVICE_168C001C: return "AR242x 802.11abg NIC (PCI Express)";
        case PciSubDevice168C001C::SUBDEVICE_168C3061: return "AR5006EGS 802.11bg NIC (2.4GHz, PCI Express)";
        case PciSubDevice168C001C::SUBDEVICE_168C3062: return "AR5006EXS 802.11abg NIC (2.4/5.0GHz, PCI Express)";
        case PciSubDevice168C001C::SUBDEVICE_168C3063: return "AR5006EX 802.11abg NIC (2.4/5.0GHz, PCI Express)";
        case PciSubDevice168C001C::SUBDEVICE_168C3065: return "AR5006EG 802.11bg NIC (2.4GHz, PCI Express)";
        case PciSubDevice168C001C::SUBDEVICE_168C3067: return "AR242x 802.11abg Wireless PCI Express Adapter (rev 01)";
        case PciSubDevice168C001C::SUBDEVICE_1A3B1026: return "AW-GE780 802.11bg Wireless Mini PCIe Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C001C_H
