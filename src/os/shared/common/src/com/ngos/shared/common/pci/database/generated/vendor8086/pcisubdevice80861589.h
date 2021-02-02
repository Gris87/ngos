// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861589_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861589_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861589: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_108E0000 = 0x108E0000,
    SUBDEVICE_108E7B1C = 0x108E7B1C,
    SUBDEVICE_80860000 = 0x80860000,
    SUBDEVICE_80860001 = 0x80860001,
    SUBDEVICE_80860002 = 0x80860002,
    SUBDEVICE_80860003 = 0x80860003,
    SUBDEVICE_808600A0 = 0x808600A0,
    SUBDEVICE_80861003 = 0x80861003
};



inline const char8* enumToString(PciSubDevice80861589 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861589::NONE:               return "NONE";
        case PciSubDevice80861589::SUBDEVICE_108E0000: return "SUBDEVICE_108E0000";
        case PciSubDevice80861589::SUBDEVICE_108E7B1C: return "SUBDEVICE_108E7B1C";
        case PciSubDevice80861589::SUBDEVICE_80860000: return "SUBDEVICE_80860000";
        case PciSubDevice80861589::SUBDEVICE_80860001: return "SUBDEVICE_80860001";
        case PciSubDevice80861589::SUBDEVICE_80860002: return "SUBDEVICE_80860002";
        case PciSubDevice80861589::SUBDEVICE_80860003: return "SUBDEVICE_80860003";
        case PciSubDevice80861589::SUBDEVICE_808600A0: return "SUBDEVICE_808600A0";
        case PciSubDevice80861589::SUBDEVICE_80861003: return "SUBDEVICE_80861003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861589 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861589 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861589::SUBDEVICE_108E0000: return "Quad Port 10GBase-T Adapter";
        case PciSubDevice80861589::SUBDEVICE_108E7B1C: return "Quad Port 10GBase-T Adapter";
        case PciSubDevice80861589::SUBDEVICE_80860000: return "Ethernet Converged Network Adapter X710-T";
        case PciSubDevice80861589::SUBDEVICE_80860001: return "Ethernet Converged Network Adapter X710-T4";
        case PciSubDevice80861589::SUBDEVICE_80860002: return "Ethernet Converged Network Adapter X710-T4";
        case PciSubDevice80861589::SUBDEVICE_80860003: return "Ethernet Converged Network Adapter X710-T";
        case PciSubDevice80861589::SUBDEVICE_808600A0: return "Ethernet Converged Network Adapter X710-T4";
        case PciSubDevice80861589::SUBDEVICE_80861003: return "Ethernet Converged Network Adapter X710-T";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861589_H
