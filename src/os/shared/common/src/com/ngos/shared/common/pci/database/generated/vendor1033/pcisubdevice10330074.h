// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1033_PCISUBDEVICE10330074_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1033_PCISUBDEVICE10330074_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10330074: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10338014 = 0x10338014
};



inline const char8* enumToString(PciSubDevice10330074 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10330074::NONE:               return "NONE";
        case PciSubDevice10330074::SUBDEVICE_10338014: return "SUBDEVICE_10338014";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10330074 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10330074 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10330074::SUBDEVICE_10338014: return "RCV56ACF 56k Voice Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1033_PCISUBDEVICE10330074_H
