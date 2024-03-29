// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100273AF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100273AF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100273AF: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_148C2414 = 0x148C2414
};



inline const char8* enumToString(PciSubDevice100273AF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100273AF::NONE:               return "NONE";
        case PciSubDevice100273AF::SUBDEVICE_148C2414: return "SUBDEVICE_148C2414";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100273AF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100273AF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100273AF::SUBDEVICE_148C2414: return "Navi 21 XTXH [PowerColor Red Devil RX 6900 XT Ultimate]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100273AF_H
