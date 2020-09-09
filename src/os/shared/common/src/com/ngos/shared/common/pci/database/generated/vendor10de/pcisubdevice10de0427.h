// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0427_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0427_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0427: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C30CC = 0x103C30CC,
    SUBDEVICE_103C30CF = 0x103C30CF
};



inline const char8* enumToString(PciSubDevice10DE0427 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0427::NONE:               return "NONE";
        case PciSubDevice10DE0427::SUBDEVICE_103C30CC: return "SUBDEVICE_103C30CC";
        case PciSubDevice10DE0427::SUBDEVICE_103C30CF: return "SUBDEVICE_103C30CF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0427 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0427 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0427::SUBDEVICE_103C30CC: return "Pavilion dv6700";
        case PciSubDevice10DE0427::SUBDEVICE_103C30CF: return "Pavilion dv9668eg Laptop";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0427_H
