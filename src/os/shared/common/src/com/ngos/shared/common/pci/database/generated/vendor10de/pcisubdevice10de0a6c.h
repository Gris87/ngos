// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0A6C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0A6C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0A6C: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028040B = 0x1028040B,
    SUBDEVICE_17AA2142 = 0x17AA2142
};



inline const char8* enumToString(PciSubDevice10DE0A6C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0A6C::NONE:               return "NONE";
        case PciSubDevice10DE0A6C::SUBDEVICE_1028040B: return "SUBDEVICE_1028040B";
        case PciSubDevice10DE0A6C::SUBDEVICE_17AA2142: return "SUBDEVICE_17AA2142";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0A6C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0A6C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0A6C::SUBDEVICE_1028040B: return "Latitude E6510";
        case PciSubDevice10DE0A6C::SUBDEVICE_17AA2142: return "ThinkPad T410";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0A6C_H
