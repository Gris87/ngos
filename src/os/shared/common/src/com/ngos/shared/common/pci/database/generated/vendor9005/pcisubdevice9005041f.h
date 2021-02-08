// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE9005041F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE9005041F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice9005041F: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_9005041F = 0x9005041F
};



inline const char8* enumToString(PciSubDevice9005041F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice9005041F::NONE:               return "NONE";
        case PciSubDevice9005041F::SUBDEVICE_9005041F: return "SUBDEVICE_9005041F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice9005041F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice9005041F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice9005041F::SUBDEVICE_9005041F: return "AIC-9410W SAS (Razor ASIC RAID)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE9005041F_H
