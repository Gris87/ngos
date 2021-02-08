// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B95288_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B95288_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B95288: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10438056 = 0x10438056
};



inline const char8* enumToString(PciSubDevice10B95288 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B95288::NONE:               return "NONE";
        case PciSubDevice10B95288::SUBDEVICE_10438056: return "SUBDEVICE_10438056";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B95288 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B95288 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B95288::SUBDEVICE_10438056: return "A8R-MVP Mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B95288_H
