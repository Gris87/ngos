// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862484_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862484_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862484: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E110030 = 0x0E110030,
    SUBDEVICE_10140220 = 0x10140220,
    SUBDEVICE_104D80E7 = 0x104D80E7,
    SUBDEVICE_15D93480 = 0x15D93480,
    SUBDEVICE_80861958 = 0x80861958
};



inline const char8* enumToString(PciSubDevice80862484 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862484::NONE:               return "NONE";
        case PciSubDevice80862484::SUBDEVICE_0E110030: return "SUBDEVICE_0E110030";
        case PciSubDevice80862484::SUBDEVICE_10140220: return "SUBDEVICE_10140220";
        case PciSubDevice80862484::SUBDEVICE_104D80E7: return "SUBDEVICE_104D80E7";
        case PciSubDevice80862484::SUBDEVICE_15D93480: return "SUBDEVICE_15D93480";
        case PciSubDevice80862484::SUBDEVICE_80861958: return "SUBDEVICE_80861958";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862484 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862484 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862484::SUBDEVICE_0E110030: return "Evo N600c";
        case PciSubDevice80862484::SUBDEVICE_10140220: return "ThinkPad A/T/X Series";
        case PciSubDevice80862484::SUBDEVICE_104D80E7: return "VAIO PCG-GR214EP/GR214MP/GR215MP/GR314MP/GR315MP";
        case PciSubDevice80862484::SUBDEVICE_15D93480: return "P4DP6";
        case PciSubDevice80862484::SUBDEVICE_80861958: return "vpr Matrix 170B4";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862484_H
