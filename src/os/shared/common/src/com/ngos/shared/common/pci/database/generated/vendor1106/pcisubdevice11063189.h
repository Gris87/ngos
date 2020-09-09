// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063189_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063189_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11063189: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043807F = 0x1043807F,
    SUBDEVICE_11060000 = 0x11060000,
    SUBDEVICE_14585000 = 0x14585000,
    SUBDEVICE_18493189 = 0x18493189
};



inline const char8* enumToString(PciSubDevice11063189 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063189::NONE:               return "NONE";
        case PciSubDevice11063189::SUBDEVICE_1043807F: return "SUBDEVICE_1043807F";
        case PciSubDevice11063189::SUBDEVICE_11060000: return "SUBDEVICE_11060000";
        case PciSubDevice11063189::SUBDEVICE_14585000: return "SUBDEVICE_14585000";
        case PciSubDevice11063189::SUBDEVICE_18493189: return "SUBDEVICE_18493189";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11063189 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11063189 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063189::SUBDEVICE_1043807F: return "A7V8X motherboard";
        case PciSubDevice11063189::SUBDEVICE_11060000: return "KT4AV motherboard (KT400A)";
        case PciSubDevice11063189::SUBDEVICE_14585000: return "GA-7VAX Mainboard";
        case PciSubDevice11063189::SUBDEVICE_18493189: return "K7VT series Motherboards";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063189_H
