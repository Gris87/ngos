// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F15B7A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F15B7A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14F15B7A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_00707444 = 0x00707444,
    SUBDEVICE_107D6F34 = 0x107D6F34,
    SUBDEVICE_58543343 = 0x58543343
};



inline const char8* enumToString(PciSubDevice14F15B7A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F15B7A::NONE:               return "NONE";
        case PciSubDevice14F15B7A::SUBDEVICE_00707444: return "SUBDEVICE_00707444";
        case PciSubDevice14F15B7A::SUBDEVICE_107D6F34: return "SUBDEVICE_107D6F34";
        case PciSubDevice14F15B7A::SUBDEVICE_58543343: return "SUBDEVICE_58543343";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14F15B7A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14F15B7A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F15B7A::SUBDEVICE_00707444: return "WinTV HVR-1600";
        case PciSubDevice14F15B7A::SUBDEVICE_107D6F34: return "WinFast DVR3100 H";
        case PciSubDevice14F15B7A::SUBDEVICE_58543343: return "GoTView PCI DVD3 Hybrid";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F15B7A_H
