// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267C4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267C4_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100267C4: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020336 = 0x10020336,
    SUBDEVICE_10021336 = 0x10021336
};



inline const char8* enumToString(PciSubDevice100267C4 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100267C4::NONE:               return "NONE";
        case PciSubDevice100267C4::SUBDEVICE_10020336: return "SUBDEVICE_10020336";
        case PciSubDevice100267C4::SUBDEVICE_10021336: return "SUBDEVICE_10021336";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100267C4 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100267C4 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100267C4::SUBDEVICE_10020336: return "Radeon Pro Duo";
        case PciSubDevice100267C4::SUBDEVICE_10021336: return "Radeon Pro Duo";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267C4_H
