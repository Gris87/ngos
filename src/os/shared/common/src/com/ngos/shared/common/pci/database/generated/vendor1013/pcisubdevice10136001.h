// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1013_PCISUBDEVICE10136001_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1013_PCISUBDEVICE10136001_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10136001: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10141010 = 0x10141010
};



inline const char8* enumToString(PciSubDevice10136001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10136001::NONE:               return "NONE";
        case PciSubDevice10136001::SUBDEVICE_10141010: return "SUBDEVICE_10141010";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10136001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10136001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10136001::SUBDEVICE_10141010: return "CS4610 SoundFusion Audio Accelerator";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1013_PCISUBDEVICE10136001_H
