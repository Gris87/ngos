// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE10140144_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE10140144_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10140144: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140145 = 0x10140145
};



inline const char8* enumToString(PciSubDevice10140144 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10140144::NONE:               return "NONE";
        case PciSubDevice10140144::SUBDEVICE_10140145: return "SUBDEVICE_10140145";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10140144 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10140144 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10140144::SUBDEVICE_10140145: return "Yotta Output Controller (ytout)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1014_PCISUBDEVICE10140144_H
