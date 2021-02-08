// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE01EE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE01EE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE01EE: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10DE01EE = 0x10DE01EE,
    SUBDEVICE_A0A003B9 = 0xA0A003B9
};



inline const char8* enumToString(PciSubDevice10DE01EE subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE01EE::NONE:               return "NONE";
        case PciSubDevice10DE01EE::SUBDEVICE_10DE01EE: return "SUBDEVICE_10DE01EE";
        case PciSubDevice10DE01EE::SUBDEVICE_A0A003B9: return "SUBDEVICE_A0A003B9";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE01EE subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE01EE subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE01EE::SUBDEVICE_10DE01EE: return "MSI Delta-L nForce2 memory controller";
        case PciSubDevice10DE01EE::SUBDEVICE_A0A003B9: return "UK79G-1394 motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE01EE_H
