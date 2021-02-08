// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE1014034A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE1014034A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1014034A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1014033B = 0x1014033B,
    SUBDEVICE_10140355 = 0x10140355,
    SUBDEVICE_10140357 = 0x10140357,
    SUBDEVICE_1014035D = 0x1014035D,
    SUBDEVICE_1014035E = 0x1014035E,
    SUBDEVICE_101403FB = 0x101403FB,
    SUBDEVICE_101403FE = 0x101403FE,
    SUBDEVICE_101403FF = 0x101403FF,
    SUBDEVICE_10140474 = 0x10140474,
    SUBDEVICE_10140475 = 0x10140475,
    SUBDEVICE_10140499 = 0x10140499,
    SUBDEVICE_1014049A = 0x1014049A,
    SUBDEVICE_101404C7 = 0x101404C7,
    SUBDEVICE_101404C8 = 0x101404C8,
    SUBDEVICE_101404C9 = 0x101404C9
};



inline const char8* enumToString(PciSubDevice1014034A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1014034A::NONE:               return "NONE";
        case PciSubDevice1014034A::SUBDEVICE_1014033B: return "SUBDEVICE_1014033B";
        case PciSubDevice1014034A::SUBDEVICE_10140355: return "SUBDEVICE_10140355";
        case PciSubDevice1014034A::SUBDEVICE_10140357: return "SUBDEVICE_10140357";
        case PciSubDevice1014034A::SUBDEVICE_1014035D: return "SUBDEVICE_1014035D";
        case PciSubDevice1014034A::SUBDEVICE_1014035E: return "SUBDEVICE_1014035E";
        case PciSubDevice1014034A::SUBDEVICE_101403FB: return "SUBDEVICE_101403FB";
        case PciSubDevice1014034A::SUBDEVICE_101403FE: return "SUBDEVICE_101403FE";
        case PciSubDevice1014034A::SUBDEVICE_101403FF: return "SUBDEVICE_101403FF";
        case PciSubDevice1014034A::SUBDEVICE_10140474: return "SUBDEVICE_10140474";
        case PciSubDevice1014034A::SUBDEVICE_10140475: return "SUBDEVICE_10140475";
        case PciSubDevice1014034A::SUBDEVICE_10140499: return "SUBDEVICE_10140499";
        case PciSubDevice1014034A::SUBDEVICE_1014049A: return "SUBDEVICE_1014049A";
        case PciSubDevice1014034A::SUBDEVICE_101404C7: return "SUBDEVICE_101404C7";
        case PciSubDevice1014034A::SUBDEVICE_101404C8: return "SUBDEVICE_101404C8";
        case PciSubDevice1014034A::SUBDEVICE_101404C9: return "SUBDEVICE_101404C9";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1014034A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1014034A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1014034A::SUBDEVICE_1014033B: return "PCIe2 6Gb SAS RAID Adapter Quad-port (57B4)";
        case PciSubDevice1014034A::SUBDEVICE_10140355: return "PCIe2 3.6GB Cache 6Gb SAS RAID Adapter Quad-port (57B1)";
        case PciSubDevice1014034A::SUBDEVICE_10140357: return "PCIe2 6Gb SAS Adapter Quad-port (57C6)";
        case PciSubDevice1014034A::SUBDEVICE_1014035D: return "PCIe3 1.8GB Cache RAID SAS Adapter Quad-port 6GB (57C8)";
        case PciSubDevice1014034A::SUBDEVICE_1014035E: return "PCIe2 3.6GB Cache 6Gb SAS RAID Adapter Quad-port (57CE)";
        case PciSubDevice1014034A::SUBDEVICE_101403FB: return "PCIe3 28GB Cache RAID SAS Enclosure 6Gb x 16 (57D5)";
        case PciSubDevice1014034A::SUBDEVICE_101403FE: return "PCIe3 x8 Cache SAS RAID Internal Adapter 6Gb (57D8)";
        case PciSubDevice1014034A::SUBDEVICE_101403FF: return "PCIe3 x8 SAS RAID Internal Adapter 6Gb (57D7)";
        case PciSubDevice1014034A::SUBDEVICE_10140474: return "PCIe3 x16 Cache SAS RAID Internal Adapter 6Gb (57EB)";
        case PciSubDevice1014034A::SUBDEVICE_10140475: return "PCIe3 x16 SAS RAID Internal Adapter 6Gb (57EC)";
        case PciSubDevice1014034A::SUBDEVICE_10140499: return "PCIe3 x16 Cache SAS RAID Internal Adapter 6Gb (57ED)";
        case PciSubDevice1014034A::SUBDEVICE_1014049A: return "PCIe3 x16 SAS RAID Internal Adapter 6Gb (57EE)";
        case PciSubDevice1014034A::SUBDEVICE_101404C7: return "PCIe3 x 8 Cache SAS RAID Internal Adapter 6GB(2CCA)";
        case PciSubDevice1014034A::SUBDEVICE_101404C8: return "PCIe3 x 8 Cache SAS RAID Internal Adapter 6GB(2CD2)";
        case PciSubDevice1014034A::SUBDEVICE_101404C9: return "PCIe3 x 8 Cache SAS RAID Internal Adapter 6GB(2CCD)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE1014034A_H
