// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861581_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861581_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861581: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280000 = 0x10280000,
    SUBDEVICE_10281F98 = 0x10281F98,
    SUBDEVICE_10281F9E = 0x10281F9E,
    SUBDEVICE_10590150 = 0x10590150,
    SUBDEVICE_10590170 = 0x10590170,
    SUBDEVICE_15900000 = 0x15900000,
    SUBDEVICE_159000F8 = 0x159000F8,
    SUBDEVICE_80860000 = 0x80860000
};



inline const char8* enumToString(PciSubDevice80861581 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861581::NONE:               return "NONE";
        case PciSubDevice80861581::SUBDEVICE_10280000: return "SUBDEVICE_10280000";
        case PciSubDevice80861581::SUBDEVICE_10281F98: return "SUBDEVICE_10281F98";
        case PciSubDevice80861581::SUBDEVICE_10281F9E: return "SUBDEVICE_10281F9E";
        case PciSubDevice80861581::SUBDEVICE_10590150: return "SUBDEVICE_10590150";
        case PciSubDevice80861581::SUBDEVICE_10590170: return "SUBDEVICE_10590170";
        case PciSubDevice80861581::SUBDEVICE_15900000: return "SUBDEVICE_15900000";
        case PciSubDevice80861581::SUBDEVICE_159000F8: return "SUBDEVICE_159000F8";
        case PciSubDevice80861581::SUBDEVICE_80860000: return "SUBDEVICE_80860000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861581 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861581 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861581::SUBDEVICE_10280000: return "Ethernet 10G X710-k bNDC";
        case PciSubDevice80861581::SUBDEVICE_10281F98: return "Ethernet 10G 4P X710-k bNDC";
        case PciSubDevice80861581::SUBDEVICE_10281F9E: return "Ethernet 10G 2P X710-k bNDC";
        case PciSubDevice80861581::SUBDEVICE_10590150: return "RD-01068 10GbE-KR interface";
        case PciSubDevice80861581::SUBDEVICE_10590170: return "RD-01213 10GbE interface";
        case PciSubDevice80861581::SUBDEVICE_15900000: return "Ethernet 2-port 563i Adapter";
        case PciSubDevice80861581::SUBDEVICE_159000F8: return "Ethernet 2-port 563i Adapter";
        case PciSubDevice80861581::SUBDEVICE_80860000: return "Ethernet Converged Network Adapter XL710-Q2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861581_H
