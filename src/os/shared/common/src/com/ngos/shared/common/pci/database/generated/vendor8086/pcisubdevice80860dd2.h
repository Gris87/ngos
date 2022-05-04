// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860DD2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860DD2_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860DD2: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11370000 = 0x11370000,
    SUBDEVICE_113702E3 = 0x113702E3,
    SUBDEVICE_80860000 = 0x80860000,
    SUBDEVICE_8086000D = 0x8086000D,
    SUBDEVICE_80860010 = 0x80860010,
    SUBDEVICE_8086401A = 0x8086401A,
    SUBDEVICE_8086401B = 0x8086401B
};



inline const char8* enumToString(PciSubDevice80860DD2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860DD2::NONE:               return "NONE";
        case PciSubDevice80860DD2::SUBDEVICE_11370000: return "SUBDEVICE_11370000";
        case PciSubDevice80860DD2::SUBDEVICE_113702E3: return "SUBDEVICE_113702E3";
        case PciSubDevice80860DD2::SUBDEVICE_80860000: return "SUBDEVICE_80860000";
        case PciSubDevice80860DD2::SUBDEVICE_8086000D: return "SUBDEVICE_8086000D";
        case PciSubDevice80860DD2::SUBDEVICE_80860010: return "SUBDEVICE_80860010";
        case PciSubDevice80860DD2::SUBDEVICE_8086401A: return "SUBDEVICE_8086401A";
        case PciSubDevice80860DD2::SUBDEVICE_8086401B: return "SUBDEVICE_8086401B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860DD2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860DD2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860DD2::SUBDEVICE_11370000: return "I710T4LG 4x1 GbE RJ45 PCIe NIC";
        case PciSubDevice80860DD2::SUBDEVICE_113702E3: return "I710T4LG 4x1 GbE RJ45 PCIe NIC";
        case PciSubDevice80860DD2::SUBDEVICE_80860000: return "Ethernet Network Adapter I710-T4L";
        case PciSubDevice80860DD2::SUBDEVICE_8086000D: return "Ethernet Network Adapter I710-T4L";
        case PciSubDevice80860DD2::SUBDEVICE_80860010: return "Ethernet Network Adapter I710-T4L for OCP 3.0";
        case PciSubDevice80860DD2::SUBDEVICE_8086401A: return "Ethernet Network Adapter I710-T4L";
        case PciSubDevice80860DD2::SUBDEVICE_8086401B: return "Ethernet Network Adapter I710-T4L for OCP 3.0";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860DD2_H
