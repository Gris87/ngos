// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772289_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772289_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10772289: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_107702E9 = 0x107702E9,
    SUBDEVICE_107702EB = 0x107702EB,
    SUBDEVICE_107702EF = 0x107702EF,
    SUBDEVICE_107702F1 = 0x107702F1
};



inline const char8* enumToString(PciSubDevice10772289 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10772289::NONE:               return "NONE";
        case PciSubDevice10772289::SUBDEVICE_107702E9: return "SUBDEVICE_107702E9";
        case PciSubDevice10772289::SUBDEVICE_107702EB: return "SUBDEVICE_107702EB";
        case PciSubDevice10772289::SUBDEVICE_107702EF: return "SUBDEVICE_107702EF";
        case PciSubDevice10772289::SUBDEVICE_107702F1: return "SUBDEVICE_107702F1";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10772289 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10772289 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10772289::SUBDEVICE_107702E9: return "QLE2882 Dual Port 64GFC PCIe Gen4 x8 Adapter with StorCryption";
        case PciSubDevice10772289::SUBDEVICE_107702EB: return "QLE2782 Dual Port 32GFC PCIe Gen4 x8 Adapter with StorCryption";
        case PciSubDevice10772289::SUBDEVICE_107702EF: return "QLE2880 Single Port 64GFC PCIe Gen4 x8 Adapter with StorCryption";
        case PciSubDevice10772289::SUBDEVICE_107702F1: return "QLE2780 Single Port 32GFC PCIe Gen4 x8 Adapter with StorCryption";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772289_H
