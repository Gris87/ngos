// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100295C0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100295C0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100295C0: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_100295C0 = 0x100295C0,
    SUBDEVICE_10283243 = 0x10283243
};



inline const char8* enumToString(PciSubDevice100295C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100295C0::NONE:               return "NONE";
        case PciSubDevice100295C0::SUBDEVICE_100295C0: return "SUBDEVICE_100295C0";
        case PciSubDevice100295C0::SUBDEVICE_10283243: return "SUBDEVICE_10283243";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100295C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100295C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100295C0::SUBDEVICE_100295C0: return "Mobility Radeon HD 3470";
        case PciSubDevice100295C0::SUBDEVICE_10283243: return "C120D";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100295C0_H
