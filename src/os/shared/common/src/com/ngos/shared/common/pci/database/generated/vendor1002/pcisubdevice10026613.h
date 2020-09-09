// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026613_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026613_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026613: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_148C7340 = 0x148C7340,
    SUBDEVICE_16827240 = 0x16827240
};



inline const char8* enumToString(PciSubDevice10026613 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026613::NONE:               return "NONE";
        case PciSubDevice10026613::SUBDEVICE_148C7340: return "SUBDEVICE_148C7340";
        case PciSubDevice10026613::SUBDEVICE_16827240: return "SUBDEVICE_16827240";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026613 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026613 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026613::SUBDEVICE_148C7340: return "Radeon R7 340";
        case PciSubDevice10026613::SUBDEVICE_16827240: return "R7 240 2048 MB";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026613_H
