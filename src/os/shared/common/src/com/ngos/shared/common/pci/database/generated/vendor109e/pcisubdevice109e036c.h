// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR109E_PCISUBDEVICE109E036C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR109E_PCISUBDEVICE109E036C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice109E036C: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_13E90070 = 0x13E90070
};



inline const char8* enumToString(PciSubDevice109E036C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice109E036C::NONE:               return "NONE";
        case PciSubDevice109E036C::SUBDEVICE_13E90070: return "SUBDEVICE_13E90070";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice109E036C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice109E036C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice109E036C::SUBDEVICE_13E90070: return "Win/TV (Video Section)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR109E_PCISUBDEVICE109E036C_H
