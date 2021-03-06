// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0BE9_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0BE9_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0BE9: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_15588687 = 0x15588687,
    SUBDEVICE_38421452 = 0x38421452
};



inline const char8* enumToString(PciSubDevice10DE0BE9 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0BE9::NONE:               return "NONE";
        case PciSubDevice10DE0BE9::SUBDEVICE_15588687: return "SUBDEVICE_15588687";
        case PciSubDevice10DE0BE9::SUBDEVICE_38421452: return "SUBDEVICE_38421452";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0BE9 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0BE9 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0BE9::SUBDEVICE_15588687: return "CLEVO/KAPOK W860CU";
        case PciSubDevice10DE0BE9::SUBDEVICE_38421452: return "GeForce GTS 450";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0BE9_H
