// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610F7_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610F7_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808610F7: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_108E7B12 = 0x108E7B12,
    SUBDEVICE_8086000D = 0x8086000D
};



inline const char8* enumToString(PciSubDevice808610F7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610F7::NONE:               return "NONE";
        case PciSubDevice808610F7::SUBDEVICE_108E7B12: return "SUBDEVICE_108E7B12";
        case PciSubDevice808610F7::SUBDEVICE_8086000D: return "SUBDEVICE_8086000D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808610F7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808610F7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610F7::SUBDEVICE_108E7B12: return "Sun Dual 10GbE PCIe 2.0 FEM";
        case PciSubDevice808610F7::SUBDEVICE_8086000D: return "Ethernet Mezzanine Adapter X520-KX4-2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610F7_H
