// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C58_PCISUBDEVICE1C580023_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C58_PCISUBDEVICE1C580023_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1C580023: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1C588823 = 0x1C588823
};



inline const char8* enumToString(PciSubDevice1C580023 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1C580023::NONE:               return "NONE";
        case PciSubDevice1C580023::SUBDEVICE_1C588823: return "SUBDEVICE_1C588823";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1C580023 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1C580023 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1C580023::SUBDEVICE_1C588823: return "Ultrastar Memory (ME200)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C58_PCISUBDEVICE1C580023_H
