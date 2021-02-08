// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR100B_PCISUBDEVICE100B0503_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR100B_PCISUBDEVICE100B0503_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100B0503: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_100B0503 = 0x100B0503
};



inline const char8* enumToString(PciSubDevice100B0503 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100B0503::NONE:               return "NONE";
        case PciSubDevice100B0503::SUBDEVICE_100B0503: return "SUBDEVICE_100B0503";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100B0503 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100B0503 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100B0503::SUBDEVICE_100B0503: return "XpressAudio controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR100B_PCISUBDEVICE100B0503_H
