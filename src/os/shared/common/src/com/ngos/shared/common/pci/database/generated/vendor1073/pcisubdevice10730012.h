// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1073_PCISUBDEVICE10730012_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1073_PCISUBDEVICE10730012_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10730012: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10730012 = 0x10730012
};



inline const char8* enumToString(PciSubDevice10730012 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10730012::NONE:               return "NONE";
        case PciSubDevice10730012::SUBDEVICE_10730012: return "SUBDEVICE_10730012";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10730012 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10730012 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10730012::SUBDEVICE_10730012: return "DS-XG PCI Audio Codec";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1073_PCISUBDEVICE10730012_H
