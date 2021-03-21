// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861911_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861911_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861911: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280869 = 0x10280869,
    SUBDEVICE_14627A72 = 0x14627A72,
    SUBDEVICE_17AA2247 = 0x17AA2247,
    SUBDEVICE_17AA224F = 0x17AA224F,
    SUBDEVICE_17AA225D = 0x17AA225D
};



inline const char8* enumToString(PciSubDevice80861911 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861911::NONE:               return "NONE";
        case PciSubDevice80861911::SUBDEVICE_10280869: return "SUBDEVICE_10280869";
        case PciSubDevice80861911::SUBDEVICE_14627A72: return "SUBDEVICE_14627A72";
        case PciSubDevice80861911::SUBDEVICE_17AA2247: return "SUBDEVICE_17AA2247";
        case PciSubDevice80861911::SUBDEVICE_17AA224F: return "SUBDEVICE_17AA224F";
        case PciSubDevice80861911::SUBDEVICE_17AA225D: return "SUBDEVICE_17AA225D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861911 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861911 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861911::SUBDEVICE_10280869: return "Vostro 3470";
        case PciSubDevice80861911::SUBDEVICE_14627A72: return "H270 PC MATE";
        case PciSubDevice80861911::SUBDEVICE_17AA2247: return "ThinkPad T570";
        case PciSubDevice80861911::SUBDEVICE_17AA224F: return "ThinkPad X1 Carbon 5th Gen";
        case PciSubDevice80861911::SUBDEVICE_17AA225D: return "ThinkPad T480";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861911_H
