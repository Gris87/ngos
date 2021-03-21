// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B31017_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B31017_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice15B31017: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_15B30006 = 0x15B30006,
    SUBDEVICE_15B30007 = 0x15B30007,
    SUBDEVICE_15B30020 = 0x15B30020,
    SUBDEVICE_15B30068 = 0x15B30068,
    SUBDEVICE_193D1051 = 0x193D1051
};



inline const char8* enumToString(PciSubDevice15B31017 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15B31017::NONE:               return "NONE";
        case PciSubDevice15B31017::SUBDEVICE_15B30006: return "SUBDEVICE_15B30006";
        case PciSubDevice15B31017::SUBDEVICE_15B30007: return "SUBDEVICE_15B30007";
        case PciSubDevice15B31017::SUBDEVICE_15B30020: return "SUBDEVICE_15B30020";
        case PciSubDevice15B31017::SUBDEVICE_15B30068: return "SUBDEVICE_15B30068";
        case PciSubDevice15B31017::SUBDEVICE_193D1051: return "SUBDEVICE_193D1051";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice15B31017 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice15B31017 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15B31017::SUBDEVICE_15B30006: return "ConnectX*-5 EN network interface card, 100GbE single-port QSFP28, PCIe3.0 x16, tall bracket; MCX515A-CCAT";
        case PciSubDevice15B31017::SUBDEVICE_15B30007: return "Mellanox ConnectX*-5 MCX516A-CCAT";
        case PciSubDevice15B31017::SUBDEVICE_15B30020: return "ConnectX*-5 EN network interface card, 10/25GbE dual-port SFP28, PCIe3.0 x8, tall bracket ; MCX512A-ACAT";
        case PciSubDevice15B31017::SUBDEVICE_15B30068: return "ConnectX*-5 EN network interface card for OCP2.0, Type 1, with host management, 25GbE dual-port SFP28, PCIe3.0 x8, no bracket Halogen free ; MCX542B-ACAN";
        case PciSubDevice15B31017::SUBDEVICE_193D1051: return "NIC-IB1040i-Mb-2P";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B3_PCISUBDEVICE15B31017_H
