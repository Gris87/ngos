// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC56_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC56_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104CAC56: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140512 = 0x10140512,
    SUBDEVICE_10140528 = 0x10140528,
    SUBDEVICE_17AA2012 = 0x17AA2012
};



inline const char8* enumToString(PciSubDevice104CAC56 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104CAC56::NONE:               return "NONE";
        case PciSubDevice104CAC56::SUBDEVICE_10140512: return "SUBDEVICE_10140512";
        case PciSubDevice104CAC56::SUBDEVICE_10140528: return "SUBDEVICE_10140528";
        case PciSubDevice104CAC56::SUBDEVICE_17AA2012: return "SUBDEVICE_17AA2012";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104CAC56 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104CAC56 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104CAC56::SUBDEVICE_10140512: return "ThinkPad R50e";
        case PciSubDevice104CAC56::SUBDEVICE_10140528: return "ThinkPad R40e";
        case PciSubDevice104CAC56::SUBDEVICE_17AA2012: return "ThinkPad T60/R60 series";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC56_H
