// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1137_PCISUBDEVICE11370044_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1137_PCISUBDEVICE11370044_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11370044: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11370047 = 0x11370047,
    SUBDEVICE_11370048 = 0x11370048,
    SUBDEVICE_1137004F = 0x1137004F,
    SUBDEVICE_11370084 = 0x11370084,
    SUBDEVICE_11370085 = 0x11370085,
    SUBDEVICE_113700CD = 0x113700CD,
    SUBDEVICE_113700CE = 0x113700CE,
    SUBDEVICE_1137012A = 0x1137012A,
    SUBDEVICE_1137012C = 0x1137012C,
    SUBDEVICE_1137012E = 0x1137012E,
    SUBDEVICE_11370137 = 0x11370137,
    SUBDEVICE_1137014D = 0x1137014D
};



inline const char8* enumToString(PciSubDevice11370044 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11370044::NONE:               return "NONE";
        case PciSubDevice11370044::SUBDEVICE_11370047: return "SUBDEVICE_11370047";
        case PciSubDevice11370044::SUBDEVICE_11370048: return "SUBDEVICE_11370048";
        case PciSubDevice11370044::SUBDEVICE_1137004F: return "SUBDEVICE_1137004F";
        case PciSubDevice11370044::SUBDEVICE_11370084: return "SUBDEVICE_11370084";
        case PciSubDevice11370044::SUBDEVICE_11370085: return "SUBDEVICE_11370085";
        case PciSubDevice11370044::SUBDEVICE_113700CD: return "SUBDEVICE_113700CD";
        case PciSubDevice11370044::SUBDEVICE_113700CE: return "SUBDEVICE_113700CE";
        case PciSubDevice11370044::SUBDEVICE_1137012A: return "SUBDEVICE_1137012A";
        case PciSubDevice11370044::SUBDEVICE_1137012C: return "SUBDEVICE_1137012C";
        case PciSubDevice11370044::SUBDEVICE_1137012E: return "SUBDEVICE_1137012E";
        case PciSubDevice11370044::SUBDEVICE_11370137: return "SUBDEVICE_11370137";
        case PciSubDevice11370044::SUBDEVICE_1137014D: return "SUBDEVICE_1137014D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11370044 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11370044 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11370044::SUBDEVICE_11370047: return "VIC P81E PCIe Ethernet NIC Dynamic";
        case PciSubDevice11370044::SUBDEVICE_11370048: return "VIC M81KR Mezzanine Ethernet NIC Dynamic";
        case PciSubDevice11370044::SUBDEVICE_1137004F: return "VIC 1280 Mezzanine Ethernet NIC Dynamic";
        case PciSubDevice11370044::SUBDEVICE_11370084: return "VIC 1240 MLOM Ethernet NIC Dynamic";
        case PciSubDevice11370044::SUBDEVICE_11370085: return "VIC 1225 PCIe Ethernet NIC Dynamic";
        case PciSubDevice11370044::SUBDEVICE_113700CD: return "VIC 1285 PCIe Ethernet NIC Dynamic";
        case PciSubDevice11370044::SUBDEVICE_113700CE: return "VIC 1225T PCIe Ethernet NIC Dynamic";
        case PciSubDevice11370044::SUBDEVICE_1137012A: return "VIC M4308 Ethernet NIC Dynamic";
        case PciSubDevice11370044::SUBDEVICE_1137012C: return "VIC 1340 MLOM Ethernet NIC Dynamic";
        case PciSubDevice11370044::SUBDEVICE_1137012E: return "VIC 1227 PCIe Ethernet NIC Dynamic";
        case PciSubDevice11370044::SUBDEVICE_11370137: return "VIC 1380 Mezzanine Ethernet NIC Dynamic";
        case PciSubDevice11370044::SUBDEVICE_1137014D: return "VIC 1385 PCIe Ethernet NIC Dynamic";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1137_PCISUBDEVICE11370044_H
