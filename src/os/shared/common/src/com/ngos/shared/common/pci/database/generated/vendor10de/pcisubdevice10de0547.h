// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0547_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0547_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0547: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10438308 = 0x10438308,
    SUBDEVICE_18490547 = 0x18490547
};



inline const char8* enumToString(PciSubDevice10DE0547 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0547::NONE:               return "NONE";
        case PciSubDevice10DE0547::SUBDEVICE_10438308: return "SUBDEVICE_10438308";
        case PciSubDevice10DE0547::SUBDEVICE_18490547: return "SUBDEVICE_18490547";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0547 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0547 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0547::SUBDEVICE_10438308: return "M2N68-AM Motherboard";
        case PciSubDevice10DE0547::SUBDEVICE_18490547: return "ALiveNF7G-HDready";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0547_H
