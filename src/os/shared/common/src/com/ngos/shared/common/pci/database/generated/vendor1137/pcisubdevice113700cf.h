// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1137_PCISUBDEVICE113700CF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1137_PCISUBDEVICE113700CF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice113700CF: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1137004F = 0x1137004F,
    SUBDEVICE_11370084 = 0x11370084,
    SUBDEVICE_11370085 = 0x11370085,
    SUBDEVICE_113700CD = 0x113700CD,
    SUBDEVICE_113700CE = 0x113700CE,
    SUBDEVICE_1137012A = 0x1137012A,
    SUBDEVICE_1137012C = 0x1137012C,
    SUBDEVICE_1137012E = 0x1137012E,
    SUBDEVICE_11370137 = 0x11370137
};



inline const char8* enumToString(PciSubDevice113700CF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice113700CF::NONE:               return "NONE";
        case PciSubDevice113700CF::SUBDEVICE_1137004F: return "SUBDEVICE_1137004F";
        case PciSubDevice113700CF::SUBDEVICE_11370084: return "SUBDEVICE_11370084";
        case PciSubDevice113700CF::SUBDEVICE_11370085: return "SUBDEVICE_11370085";
        case PciSubDevice113700CF::SUBDEVICE_113700CD: return "SUBDEVICE_113700CD";
        case PciSubDevice113700CF::SUBDEVICE_113700CE: return "SUBDEVICE_113700CE";
        case PciSubDevice113700CF::SUBDEVICE_1137012A: return "SUBDEVICE_1137012A";
        case PciSubDevice113700CF::SUBDEVICE_1137012C: return "SUBDEVICE_1137012C";
        case PciSubDevice113700CF::SUBDEVICE_1137012E: return "SUBDEVICE_1137012E";
        case PciSubDevice113700CF::SUBDEVICE_11370137: return "SUBDEVICE_11370137";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice113700CF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice113700CF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice113700CF::SUBDEVICE_1137004F: return "VIC 1280 Mezzanine Userspace NIC";
        case PciSubDevice113700CF::SUBDEVICE_11370084: return "VIC 1240 MLOM Userspace NIC";
        case PciSubDevice113700CF::SUBDEVICE_11370085: return "VIC 1225 PCIe Userspace NIC";
        case PciSubDevice113700CF::SUBDEVICE_113700CD: return "VIC 1285 PCIe Userspace NIC";
        case PciSubDevice113700CF::SUBDEVICE_113700CE: return "VIC 1225T PCIe Userspace NIC";
        case PciSubDevice113700CF::SUBDEVICE_1137012A: return "VIC M4308 Userspace NIC";
        case PciSubDevice113700CF::SUBDEVICE_1137012C: return "VIC 1340 MLOM Userspace NIC";
        case PciSubDevice113700CF::SUBDEVICE_1137012E: return "VIC 1227 PCIe Userspace NIC";
        case PciSubDevice113700CF::SUBDEVICE_11370137: return "VIC 1380 Mezzanine Userspace NIC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1137_PCISUBDEVICE113700CF_H
