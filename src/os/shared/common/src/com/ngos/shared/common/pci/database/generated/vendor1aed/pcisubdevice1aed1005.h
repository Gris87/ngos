// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AED_PCISUBDEVICE1AED1005_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AED_PCISUBDEVICE1AED1005_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1AED1005: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101403C3 = 0x101403C3,
    SUBDEVICE_103C176F = 0x103C176F,
    SUBDEVICE_103C1770 = 0x103C1770,
    SUBDEVICE_103C178B = 0x103C178B,
    SUBDEVICE_103C178C = 0x103C178C,
    SUBDEVICE_103C178D = 0x103C178D,
    SUBDEVICE_103C178E = 0x103C178E
};



inline const char8* enumToString(PciSubDevice1AED1005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1AED1005::NONE:               return "NONE";
        case PciSubDevice1AED1005::SUBDEVICE_101403C3: return "SUBDEVICE_101403C3";
        case PciSubDevice1AED1005::SUBDEVICE_103C176F: return "SUBDEVICE_103C176F";
        case PciSubDevice1AED1005::SUBDEVICE_103C1770: return "SUBDEVICE_103C1770";
        case PciSubDevice1AED1005::SUBDEVICE_103C178B: return "SUBDEVICE_103C178B";
        case PciSubDevice1AED1005::SUBDEVICE_103C178C: return "SUBDEVICE_103C178C";
        case PciSubDevice1AED1005::SUBDEVICE_103C178D: return "SUBDEVICE_103C178D";
        case PciSubDevice1AED1005::SUBDEVICE_103C178E: return "SUBDEVICE_103C178E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1AED1005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1AED1005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1AED1005::SUBDEVICE_101403C3: return "High IOPS SSD PCIe Adapter";
        case PciSubDevice1AED1005::SUBDEVICE_103C176F: return "1.28TB MLC PCIe ioDrive Duo";
        case PciSubDevice1AED1005::SUBDEVICE_103C1770: return "5.2TB MLC PCIe ioDrive Octal";
        case PciSubDevice1AED1005::SUBDEVICE_103C178B: return "160GB SLC PCIe ioDrive";
        case PciSubDevice1AED1005::SUBDEVICE_103C178C: return "320GB MLC PCIe ioDrive";
        case PciSubDevice1AED1005::SUBDEVICE_103C178D: return "320GB SLC PCIe ioDrive Duo";
        case PciSubDevice1AED1005::SUBDEVICE_103C178E: return "640GB MLC PCIe ioDrive Duo";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AED_PCISUBDEVICE1AED1005_H
