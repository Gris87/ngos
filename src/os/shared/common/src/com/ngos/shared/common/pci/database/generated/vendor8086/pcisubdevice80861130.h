// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861130_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861130_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861130: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10251016 = 0x10251016,
    SUBDEVICE_10438027 = 0x10438027,
    SUBDEVICE_104D80DF = 0x104D80DF,
    SUBDEVICE_80864532 = 0x80864532,
    SUBDEVICE_80864557 = 0x80864557
};



inline const char8* enumToString(PciSubDevice80861130 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861130::NONE:               return "NONE";
        case PciSubDevice80861130::SUBDEVICE_10251016: return "SUBDEVICE_10251016";
        case PciSubDevice80861130::SUBDEVICE_10438027: return "SUBDEVICE_10438027";
        case PciSubDevice80861130::SUBDEVICE_104D80DF: return "SUBDEVICE_104D80DF";
        case PciSubDevice80861130::SUBDEVICE_80864532: return "SUBDEVICE_80864532";
        case PciSubDevice80861130::SUBDEVICE_80864557: return "SUBDEVICE_80864557";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861130 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861130 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861130::SUBDEVICE_10251016: return "Travelmate 612 TX";
        case PciSubDevice80861130::SUBDEVICE_10438027: return "TUSL2-C Mainboard";
        case PciSubDevice80861130::SUBDEVICE_104D80DF: return "Vaio PCG-FX403";
        case PciSubDevice80861130::SUBDEVICE_80864532: return "Desktop Board D815EEA2/D815EFV";
        case PciSubDevice80861130::SUBDEVICE_80864557: return "D815EGEW Mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861130_H
