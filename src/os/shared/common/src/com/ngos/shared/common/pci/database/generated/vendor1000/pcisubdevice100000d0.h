// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000D0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000D0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100000D0: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10003050 = 0x10003050,
    SUBDEVICE_10003070 = 0x10003070
};



inline const char8* enumToString(PciSubDevice100000D0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100000D0::NONE:               return "NONE";
        case PciSubDevice100000D0::SUBDEVICE_10003050: return "SUBDEVICE_10003050";
        case PciSubDevice100000D0::SUBDEVICE_10003070: return "SUBDEVICE_10003070";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100000D0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100000D0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100000D0::SUBDEVICE_10003050: return "HBA 9405W-16i";
        case PciSubDevice100000D0::SUBDEVICE_10003070: return "HBA 9405W-8bad_int8e";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE100000D0_H
