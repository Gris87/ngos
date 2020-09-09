// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861593_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861593_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861593: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_113702C3 = 0x113702C3,
    SUBDEVICE_80860002 = 0x80860002,
    SUBDEVICE_80860005 = 0x80860005,
    SUBDEVICE_80860006 = 0x80860006,
    SUBDEVICE_80860007 = 0x80860007,
    SUBDEVICE_80860008 = 0x80860008,
    SUBDEVICE_80860009 = 0x80860009,
    SUBDEVICE_8086000A = 0x8086000A
};



inline const char8* enumToString(PciSubDevice80861593 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861593::NONE:               return "NONE";
        case PciSubDevice80861593::SUBDEVICE_113702C3: return "SUBDEVICE_113702C3";
        case PciSubDevice80861593::SUBDEVICE_80860002: return "SUBDEVICE_80860002";
        case PciSubDevice80861593::SUBDEVICE_80860005: return "SUBDEVICE_80860005";
        case PciSubDevice80861593::SUBDEVICE_80860006: return "SUBDEVICE_80860006";
        case PciSubDevice80861593::SUBDEVICE_80860007: return "SUBDEVICE_80860007";
        case PciSubDevice80861593::SUBDEVICE_80860008: return "SUBDEVICE_80860008";
        case PciSubDevice80861593::SUBDEVICE_80860009: return "SUBDEVICE_80860009";
        case PciSubDevice80861593::SUBDEVICE_8086000A: return "SUBDEVICE_8086000A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861593 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861593 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861593::SUBDEVICE_113702C3: return "E810XXVDA4 4x25/10 GbE SFP28 PCIe NIC";
        case PciSubDevice80861593::SUBDEVICE_80860002: return "Ethernet Network Adapter E810-L-2";
        case PciSubDevice80861593::SUBDEVICE_80860005: return "Ethernet Network Adapter E810-XXV-4";
        case PciSubDevice80861593::SUBDEVICE_80860006: return "Ethernet Network Adapter E810-XXV-4";
        case PciSubDevice80861593::SUBDEVICE_80860007: return "Ethernet Network Adapter E810-XXV-4";
        case PciSubDevice80861593::SUBDEVICE_80860008: return "Ethernet Network Adapter E810-XXV-2";
        case PciSubDevice80861593::SUBDEVICE_80860009: return "Ethernet Network Adapter E810-XXV-2 for OCP 2.0";
        case PciSubDevice80861593::SUBDEVICE_8086000A: return "Ethernet 25G 4P E810-XXV Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861593_H
