// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861C18_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861C18_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861C18: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102804DA = 0x102804DA,
    SUBDEVICE_17AA21CF = 0x17AA21CF,
    SUBDEVICE_80867270 = 0x80867270
};



inline const char8* enumToString(PciSubDevice80861C18 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861C18::NONE:               return "NONE";
        case PciSubDevice80861C18::SUBDEVICE_102804DA: return "SUBDEVICE_102804DA";
        case PciSubDevice80861C18::SUBDEVICE_17AA21CF: return "SUBDEVICE_17AA21CF";
        case PciSubDevice80861C18::SUBDEVICE_80867270: return "SUBDEVICE_80867270";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861C18 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861C18 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861C18::SUBDEVICE_102804DA: return "Vostro 3750";
        case PciSubDevice80861C18::SUBDEVICE_17AA21CF: return "ThinkPad T520";
        case PciSubDevice80861C18::SUBDEVICE_80867270: return "Server Board S1200BTS";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861C18_H
