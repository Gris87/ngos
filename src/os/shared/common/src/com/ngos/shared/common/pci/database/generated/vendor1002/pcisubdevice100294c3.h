// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100294C3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100294C3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100294C3: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280302 = 0x10280302,
    SUBDEVICE_174BE400 = 0x174BE400,
    SUBDEVICE_18BC3550 = 0x18BC3550
};



inline const char8* enumToString(PciSubDevice100294C3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100294C3::NONE:               return "NONE";
        case PciSubDevice100294C3::SUBDEVICE_10280302: return "SUBDEVICE_10280302";
        case PciSubDevice100294C3::SUBDEVICE_174BE400: return "SUBDEVICE_174BE400";
        case PciSubDevice100294C3::SUBDEVICE_18BC3550: return "SUBDEVICE_18BC3550";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100294C3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100294C3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100294C3::SUBDEVICE_10280302: return "Radeon HD 2400 Pro";
        case PciSubDevice100294C3::SUBDEVICE_174BE400: return "Radeon HD 2400 PRO";
        case PciSubDevice100294C3::SUBDEVICE_18BC3550: return "Radeon HD 2400 PRO";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100294C3_H
