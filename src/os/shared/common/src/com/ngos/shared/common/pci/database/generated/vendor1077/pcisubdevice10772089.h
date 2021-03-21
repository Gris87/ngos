// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772089_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772089_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10772089: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_107702E8 = 0x107702E8,
    SUBDEVICE_107702EA = 0x107702EA
};



inline const char8* enumToString(PciSubDevice10772089 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10772089::NONE:               return "NONE";
        case PciSubDevice10772089::SUBDEVICE_107702E8: return "SUBDEVICE_107702E8";
        case PciSubDevice10772089::SUBDEVICE_107702EA: return "SUBDEVICE_107702EA";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10772089 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10772089 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10772089::SUBDEVICE_107702E8: return "QLE2884 Quad Port 64GFC PCIe Gen4 x16 Adapter with StorCryption";
        case PciSubDevice10772089::SUBDEVICE_107702EA: return "QLE2784 Quad Port 32GFC PCIe Gen4 x16 Adapter with StorCryption";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10772089_H
