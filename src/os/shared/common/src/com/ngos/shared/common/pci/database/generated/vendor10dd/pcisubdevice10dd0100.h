// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DD_PCISUBDEVICE10DD0100_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DD_PCISUBDEVICE10DD0100_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DD0100: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10DD0023 = 0x10DD0023
};



inline const char8* enumToString(PciSubDevice10DD0100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DD0100::NONE:               return "NONE";
        case PciSubDevice10DD0100::SUBDEVICE_10DD0023: return "SUBDEVICE_10DD0023";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DD0100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DD0100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DD0100::SUBDEVICE_10DD0023: return "Lightning 1200 15+16M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DD_PCISUBDEVICE10DD0100_H
