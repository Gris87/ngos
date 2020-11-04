// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE2484_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE2484_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE2484: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10DE146B = 0x10DE146B,
    SUBDEVICE_10DE14AE = 0x10DE14AE
};



inline const char8* enumToString(PciSubDevice10DE2484 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE2484::NONE:               return "NONE";
        case PciSubDevice10DE2484::SUBDEVICE_10DE146B: return "SUBDEVICE_10DE146B";
        case PciSubDevice10DE2484::SUBDEVICE_10DE14AE: return "SUBDEVICE_10DE14AE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE2484 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE2484 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE2484::SUBDEVICE_10DE146B: return "GA104 [GeForce RTX 3070]";
        case PciSubDevice10DE2484::SUBDEVICE_10DE14AE: return "GA104 [GeForce RTX 3070 16GB]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE2484_H
