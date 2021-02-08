// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1244_PCISUBDEVICE12440E80_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1244_PCISUBDEVICE12440E80_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12440E80: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_12440E00 = 0x12440E00
};



inline const char8* enumToString(PciSubDevice12440E80 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12440E80::NONE:               return "NONE";
        case PciSubDevice12440E80::SUBDEVICE_12440E00: return "SUBDEVICE_12440E00";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12440E80 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12440E80 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12440E80::SUBDEVICE_12440E00: return "PSB 3100F (AVM KAFKA) [Fritz!Card PCI v2.1]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1244_PCISUBDEVICE12440E80_H
