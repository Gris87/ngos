// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10396325_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10396325_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10396325: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10396325 = 0x10396325,
    SUBDEVICE_16311004 = 0x16311004
};



inline const char8* enumToString(PciSubDevice10396325 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10396325::NONE:               return "NONE";
        case PciSubDevice10396325::SUBDEVICE_10396325: return "SUBDEVICE_10396325";
        case PciSubDevice10396325::SUBDEVICE_16311004: return "SUBDEVICE_16311004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10396325 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10396325 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10396325::SUBDEVICE_10396325: return "SiS 651 onboard [Asus P4SC-EA]";
        case PciSubDevice10396325::SUBDEVICE_16311004: return "SiS 651C onboard [Gigabyte GA-8SIML Rev1.0]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10396325_H
