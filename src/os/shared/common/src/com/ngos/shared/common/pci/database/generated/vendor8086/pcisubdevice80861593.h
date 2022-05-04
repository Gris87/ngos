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
    SUBDEVICE_113702E9 = 0x113702E9,
    SUBDEVICE_113702EA = 0x113702EA,
    SUBDEVICE_80860002 = 0x80860002,
    SUBDEVICE_80860005 = 0x80860005,
    SUBDEVICE_80860006 = 0x80860006,
    SUBDEVICE_80860007 = 0x80860007,
    SUBDEVICE_80860008 = 0x80860008,
    SUBDEVICE_80860009 = 0x80860009,
    SUBDEVICE_8086000A = 0x8086000A,
    SUBDEVICE_8086000C = 0x8086000C,
    SUBDEVICE_8086000D = 0x8086000D,
    SUBDEVICE_8086000E = 0x8086000E,
    SUBDEVICE_8086000F = 0x8086000F,
    SUBDEVICE_80860010 = 0x80860010,
    SUBDEVICE_80864010 = 0x80864010,
    SUBDEVICE_80864013 = 0x80864013
};



inline const char8* enumToString(PciSubDevice80861593 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861593::NONE:               return "NONE";
        case PciSubDevice80861593::SUBDEVICE_113702C3: return "SUBDEVICE_113702C3";
        case PciSubDevice80861593::SUBDEVICE_113702E9: return "SUBDEVICE_113702E9";
        case PciSubDevice80861593::SUBDEVICE_113702EA: return "SUBDEVICE_113702EA";
        case PciSubDevice80861593::SUBDEVICE_80860002: return "SUBDEVICE_80860002";
        case PciSubDevice80861593::SUBDEVICE_80860005: return "SUBDEVICE_80860005";
        case PciSubDevice80861593::SUBDEVICE_80860006: return "SUBDEVICE_80860006";
        case PciSubDevice80861593::SUBDEVICE_80860007: return "SUBDEVICE_80860007";
        case PciSubDevice80861593::SUBDEVICE_80860008: return "SUBDEVICE_80860008";
        case PciSubDevice80861593::SUBDEVICE_80860009: return "SUBDEVICE_80860009";
        case PciSubDevice80861593::SUBDEVICE_8086000A: return "SUBDEVICE_8086000A";
        case PciSubDevice80861593::SUBDEVICE_8086000C: return "SUBDEVICE_8086000C";
        case PciSubDevice80861593::SUBDEVICE_8086000D: return "SUBDEVICE_8086000D";
        case PciSubDevice80861593::SUBDEVICE_8086000E: return "SUBDEVICE_8086000E";
        case PciSubDevice80861593::SUBDEVICE_8086000F: return "SUBDEVICE_8086000F";
        case PciSubDevice80861593::SUBDEVICE_80860010: return "SUBDEVICE_80860010";
        case PciSubDevice80861593::SUBDEVICE_80864010: return "SUBDEVICE_80864010";
        case PciSubDevice80861593::SUBDEVICE_80864013: return "SUBDEVICE_80864013";

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
        case PciSubDevice80861593::SUBDEVICE_113702E9: return "E810XXVDA4TG 4x25/10 GbE SFP28 PCIe NIC";
        case PciSubDevice80861593::SUBDEVICE_113702EA: return "E810XXVDA4T 4x25/10 GbE SFP28 PCIe NIC";
        case PciSubDevice80861593::SUBDEVICE_80860002: return "Ethernet Network Adapter E810-L-2";
        case PciSubDevice80861593::SUBDEVICE_80860005: return "Ethernet Network Adapter E810-XXV-4";
        case PciSubDevice80861593::SUBDEVICE_80860006: return "Ethernet Network Adapter E810-XXV-4";
        case PciSubDevice80861593::SUBDEVICE_80860007: return "Ethernet Network Adapter E810-XXV-4";
        case PciSubDevice80861593::SUBDEVICE_80860008: return "Ethernet Network Adapter E810-XXV-2";
        case PciSubDevice80861593::SUBDEVICE_80860009: return "Ethernet Network Adapter E810-XXV-2 for OCP 2.0";
        case PciSubDevice80861593::SUBDEVICE_8086000A: return "Ethernet 25G 4P E810-XXV Adapter";
        case PciSubDevice80861593::SUBDEVICE_8086000C: return "Ethernet Network Adapter E810-XXV-4 for OCP 3.0";
        case PciSubDevice80861593::SUBDEVICE_8086000D: return "Ethernet 25G 4P E810-XXV OCP";
        case PciSubDevice80861593::SUBDEVICE_8086000E: return "Ethernet Network Adapter E810-XXV-4T";
        case PciSubDevice80861593::SUBDEVICE_8086000F: return "Ethernet 25G 4P E810-XXV-stg Adapter";
        case PciSubDevice80861593::SUBDEVICE_80860010: return "Ethernet 25G 4P E810-XXV-st Adapter";
        case PciSubDevice80861593::SUBDEVICE_80864010: return "Ethernet Network Adapter E810-XXV-4";
        case PciSubDevice80861593::SUBDEVICE_80864013: return "Ethernet Network Adapter E810-XXV-4 for OCP 3.0";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861593_H
