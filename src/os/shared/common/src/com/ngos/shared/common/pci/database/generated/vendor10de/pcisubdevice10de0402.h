// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0402_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0402_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0402: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14583455 = 0x14583455,
    SUBDEVICE_14620910 = 0x14620910
};



inline const char8* enumToString(PciSubDevice10DE0402 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0402::NONE:               return "NONE";
        case PciSubDevice10DE0402::SUBDEVICE_14583455: return "SUBDEVICE_14583455";
        case PciSubDevice10DE0402::SUBDEVICE_14620910: return "SUBDEVICE_14620910";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0402 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0402 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0402::SUBDEVICE_14583455: return "GV-NX86T512H";
        case PciSubDevice10DE0402::SUBDEVICE_14620910: return "NX8600GT-T2D256EZ";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0402_H
