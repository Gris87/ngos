// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772071_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772071_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10772071: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10770283 = 0x10770283,
    SUBDEVICE_1077029E = 0x1077029E,
    SUBDEVICE_107702A2 = 0x107702A2,
    SUBDEVICE_107702AD = 0x107702AD
};



inline const char8* enumToString(PciSubDevice10772071 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10772071::NONE:               return "NONE";
        case PciSubDevice10772071::SUBDEVICE_10770283: return "SUBDEVICE_10770283";
        case PciSubDevice10772071::SUBDEVICE_1077029E: return "SUBDEVICE_1077029E";
        case PciSubDevice10772071::SUBDEVICE_107702A2: return "SUBDEVICE_107702A2";
        case PciSubDevice10772071::SUBDEVICE_107702AD: return "SUBDEVICE_107702AD";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10772071 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10772071 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10772071::SUBDEVICE_10770283: return "QLE2764 Quad Port 32Gb Fibre Channel to PCIe Adapter";
        case PciSubDevice10772071::SUBDEVICE_1077029E: return "QLE2694 Quad Port 16Gb Fibre Channel to PCIe Adapter";
        case PciSubDevice10772071::SUBDEVICE_107702A2: return "QLE2694L Quad Port 16Gb Fibre Channel to PCIe Adapter";
        case PciSubDevice10772071::SUBDEVICE_107702AD: return "QLE2694U Quad Port 16/32Gb Fibre Channel to PCIe Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772071_H
