// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029490_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029490_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10029490: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_174BE880 = 0x174BE880
};



inline const char8* enumToString(PciSubDevice10029490 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029490::NONE:               return "NONE";
        case PciSubDevice10029490::SUBDEVICE_174BE880: return "SUBDEVICE_174BE880";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10029490 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10029490 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029490::SUBDEVICE_174BE880: return "Radeon HD 4670 512MB GDDR3 Dual DVI-I/TVO";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029490_H
