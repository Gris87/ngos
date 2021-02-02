// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100271C0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100271C0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100271C0: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1002E160 = 0x1002E160,
    SUBDEVICE_174BE160 = 0x174BE160
};



inline const char8* enumToString(PciSubDevice100271C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100271C0::NONE:               return "NONE";
        case PciSubDevice100271C0::SUBDEVICE_1002E160: return "SUBDEVICE_1002E160";
        case PciSubDevice100271C0::SUBDEVICE_174BE160: return "SUBDEVICE_174BE160";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100271C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100271C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100271C0::SUBDEVICE_1002E160: return "Radeon X1650 GTO";
        case PciSubDevice100271C0::SUBDEVICE_174BE160: return "Radeon X1650 GTO";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100271C0_H
