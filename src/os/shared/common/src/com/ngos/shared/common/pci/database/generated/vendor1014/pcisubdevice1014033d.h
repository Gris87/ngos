// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE1014033D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE1014033D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1014033D: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1014033C = 0x1014033C,
    SUBDEVICE_10140353 = 0x10140353,
    SUBDEVICE_10140354 = 0x10140354,
    SUBDEVICE_10140356 = 0x10140356,
    SUBDEVICE_1014035F = 0x1014035F
};



inline const char8* enumToString(PciSubDevice1014033D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1014033D::NONE:               return "NONE";
        case PciSubDevice1014033D::SUBDEVICE_1014033C: return "SUBDEVICE_1014033C";
        case PciSubDevice1014033D::SUBDEVICE_10140353: return "SUBDEVICE_10140353";
        case PciSubDevice1014033D::SUBDEVICE_10140354: return "SUBDEVICE_10140354";
        case PciSubDevice1014033D::SUBDEVICE_10140356: return "SUBDEVICE_10140356";
        case PciSubDevice1014033D::SUBDEVICE_1014035F: return "SUBDEVICE_1014035F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1014033D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1014033D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1014033D::SUBDEVICE_1014033C: return "PCIe2 1.8GB Cache 6Gb SAS RAID Adapter Tri-port (57B5)";
        case PciSubDevice1014033D::SUBDEVICE_10140353: return "PCIe2 3.1GB Cache 6Gb SAS RAID Enclosure (57C3)";
        case PciSubDevice1014033D::SUBDEVICE_10140354: return "PCIe2 6Gb SAS Adapter Dual-port (57C4)";
        case PciSubDevice1014033D::SUBDEVICE_10140356: return "PCIe2 1.8GB Cache 6Gb SAS RAID & SSD Adapter (574D)";
        case PciSubDevice1014033D::SUBDEVICE_1014035F: return "PCIe2 6Gb SAS Adapter Quad-port (57B2)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE1014033D_H
