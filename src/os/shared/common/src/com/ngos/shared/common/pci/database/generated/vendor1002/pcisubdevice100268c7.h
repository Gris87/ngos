// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268C7_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268C7_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100268C7: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14622241 = 0x14622241,
    SUBDEVICE_14622243 = 0x14622243,
    SUBDEVICE_14622244 = 0x14622244,
    SUBDEVICE_14622245 = 0x14622245,
    SUBDEVICE_14622246 = 0x14622246
};



inline const char8* enumToString(PciSubDevice100268C7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268C7::NONE:               return "NONE";
        case PciSubDevice100268C7::SUBDEVICE_14622241: return "SUBDEVICE_14622241";
        case PciSubDevice100268C7::SUBDEVICE_14622243: return "SUBDEVICE_14622243";
        case PciSubDevice100268C7::SUBDEVICE_14622244: return "SUBDEVICE_14622244";
        case PciSubDevice100268C7::SUBDEVICE_14622245: return "SUBDEVICE_14622245";
        case PciSubDevice100268C7::SUBDEVICE_14622246: return "SUBDEVICE_14622246";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100268C7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100268C7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268C7::SUBDEVICE_14622241: return "Mobility Radeon HD 5570";
        case PciSubDevice100268C7::SUBDEVICE_14622243: return "Mobility Radeon HD 5570";
        case PciSubDevice100268C7::SUBDEVICE_14622244: return "Mobility Radeon HD 5570";
        case PciSubDevice100268C7::SUBDEVICE_14622245: return "Radeon HD 6550A";
        case PciSubDevice100268C7::SUBDEVICE_14622246: return "Radeon HD 6550A";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268C7_H
