// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861584_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861584_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861584: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80860000 = 0x80860000,
    SUBDEVICE_80860001 = 0x80860001,
    SUBDEVICE_80860002 = 0x80860002,
    SUBDEVICE_80860003 = 0x80860003,
    SUBDEVICE_80860004 = 0x80860004
};



inline const char8* enumToString(PciSubDevice80861584 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861584::NONE:               return "NONE";
        case PciSubDevice80861584::SUBDEVICE_80860000: return "SUBDEVICE_80860000";
        case PciSubDevice80861584::SUBDEVICE_80860001: return "SUBDEVICE_80860001";
        case PciSubDevice80861584::SUBDEVICE_80860002: return "SUBDEVICE_80860002";
        case PciSubDevice80861584::SUBDEVICE_80860003: return "SUBDEVICE_80860003";
        case PciSubDevice80861584::SUBDEVICE_80860004: return "SUBDEVICE_80860004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861584 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861584 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861584::SUBDEVICE_80860000: return "Ethernet Converged Network Adapter XL710-Q1";
        case PciSubDevice80861584::SUBDEVICE_80860001: return "Ethernet Converged Network Adapter XL710-Q1";
        case PciSubDevice80861584::SUBDEVICE_80860002: return "Ethernet Converged Network Adapter XL710-Q1";
        case PciSubDevice80861584::SUBDEVICE_80860003: return "Ethernet I/O Module XL710-Q1";
        case PciSubDevice80861584::SUBDEVICE_80860004: return "Ethernet Server Adapter XL710-Q1OCP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861584_H
