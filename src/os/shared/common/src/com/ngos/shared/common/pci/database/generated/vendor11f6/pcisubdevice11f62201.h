// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11F6_PCISUBDEVICE11F62201_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11F6_PCISUBDEVICE11F62201_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11F62201: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11F62011 = 0x11F62011
};



inline const char8* enumToString(PciSubDevice11F62201 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11F62201::NONE:               return "NONE";
        case PciSubDevice11F62201::SUBDEVICE_11F62011: return "SUBDEVICE_11F62011";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11F62201 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11F62201 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11F62201::SUBDEVICE_11F62011: return "ReadyLink 100TX";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11F6_PCISUBDEVICE11F62201_H
