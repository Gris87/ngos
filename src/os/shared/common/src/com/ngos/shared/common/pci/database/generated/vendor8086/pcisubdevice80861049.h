// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861049_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861049_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861049: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C30C1 = 0x103C30C1,
    SUBDEVICE_17AA20B9 = 0x17AA20B9
};



inline const char8* enumToString(PciSubDevice80861049 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861049::NONE:               return "NONE";
        case PciSubDevice80861049::SUBDEVICE_103C30C1: return "SUBDEVICE_103C30C1";
        case PciSubDevice80861049::SUBDEVICE_17AA20B9: return "SUBDEVICE_17AA20B9";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861049 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861049 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861049::SUBDEVICE_103C30C1: return "Compaq 6910p";
        case PciSubDevice80861049::SUBDEVICE_17AA20B9: return "ThinkPad T61/R61";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861049_H
