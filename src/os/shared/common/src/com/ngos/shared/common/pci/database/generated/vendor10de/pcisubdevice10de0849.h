// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0849_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0849_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0849: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14627508 = 0x14627508,
    SUBDEVICE_18490849 = 0x18490849
};



inline const char8* enumToString(PciSubDevice10DE0849 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0849::NONE:               return "NONE";
        case PciSubDevice10DE0849::SUBDEVICE_14627508: return "SUBDEVICE_14627508";
        case PciSubDevice10DE0849::SUBDEVICE_18490849: return "SUBDEVICE_18490849";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0849 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0849 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0849::SUBDEVICE_14627508: return "K9N2GM-FIH";
        case PciSubDevice10DE0849::SUBDEVICE_18490849: return "K10N78FullHD-hSLI R3.0 GeForce 8200";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0849_H
