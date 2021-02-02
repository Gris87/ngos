// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861522_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861522_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861522: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_108E7B17 = 0x108E7B17,
    SUBDEVICE_108E7B19 = 0x108E7B19,
    SUBDEVICE_80860002 = 0x80860002,
    SUBDEVICE_80860003 = 0x80860003,
    SUBDEVICE_80860004 = 0x80860004,
    SUBDEVICE_80860005 = 0x80860005,
    SUBDEVICE_808600A2 = 0x808600A2,
    SUBDEVICE_808600A3 = 0x808600A3,
    SUBDEVICE_808600A4 = 0x808600A4
};



inline const char8* enumToString(PciSubDevice80861522 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861522::NONE:               return "NONE";
        case PciSubDevice80861522::SUBDEVICE_108E7B17: return "SUBDEVICE_108E7B17";
        case PciSubDevice80861522::SUBDEVICE_108E7B19: return "SUBDEVICE_108E7B19";
        case PciSubDevice80861522::SUBDEVICE_80860002: return "SUBDEVICE_80860002";
        case PciSubDevice80861522::SUBDEVICE_80860003: return "SUBDEVICE_80860003";
        case PciSubDevice80861522::SUBDEVICE_80860004: return "SUBDEVICE_80860004";
        case PciSubDevice80861522::SUBDEVICE_80860005: return "SUBDEVICE_80860005";
        case PciSubDevice80861522::SUBDEVICE_808600A2: return "SUBDEVICE_808600A2";
        case PciSubDevice80861522::SUBDEVICE_808600A3: return "SUBDEVICE_808600A3";
        case PciSubDevice80861522::SUBDEVICE_808600A4: return "SUBDEVICE_808600A4";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861522 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861522 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861522::SUBDEVICE_108E7B17: return "Quad Port GbE PCIe 2.0 ExpressModule, MMF";
        case PciSubDevice80861522::SUBDEVICE_108E7B19: return "Dual Port GbE PCIe 2.0 Low Profile Adapter, MMF";
        case PciSubDevice80861522::SUBDEVICE_80860002: return "Ethernet Server Adapter I350-T2";
        case PciSubDevice80861522::SUBDEVICE_80860003: return "Ethernet Server Adapter I350-F4";
        case PciSubDevice80861522::SUBDEVICE_80860004: return "Ethernet Server Adapter I350-F2";
        case PciSubDevice80861522::SUBDEVICE_80860005: return "Ethernet Server Adapter I350-F1";
        case PciSubDevice80861522::SUBDEVICE_808600A2: return "Ethernet Server Adapter I350-T2";
        case PciSubDevice80861522::SUBDEVICE_808600A3: return "Ethernet Server Adapter I350-F4";
        case PciSubDevice80861522::SUBDEVICE_808600A4: return "Ethernet Server Adapter I350-F2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861522_H
