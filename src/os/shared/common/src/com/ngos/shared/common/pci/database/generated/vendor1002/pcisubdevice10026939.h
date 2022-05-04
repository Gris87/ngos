// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026939_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026939_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026939: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14622015 = 0x14622015,
    SUBDEVICE_148C9380 = 0x148C9380,
    SUBDEVICE_174BE308 = 0x174BE308,
    SUBDEVICE_174BE315 = 0x174BE315
};



inline const char8* enumToString(PciSubDevice10026939 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026939::NONE:               return "NONE";
        case PciSubDevice10026939::SUBDEVICE_14622015: return "SUBDEVICE_14622015";
        case PciSubDevice10026939::SUBDEVICE_148C9380: return "SUBDEVICE_148C9380";
        case PciSubDevice10026939::SUBDEVICE_174BE308: return "SUBDEVICE_174BE308";
        case PciSubDevice10026939::SUBDEVICE_174BE315: return "SUBDEVICE_174BE315";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026939 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026939 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026939::SUBDEVICE_14622015: return "Radeon R9 380 Gaming 4G";
        case PciSubDevice10026939::SUBDEVICE_148C9380: return "Radeon R9 380";
        case PciSubDevice10026939::SUBDEVICE_174BE308: return "Radeon R9 380 Nitro 4G D5";
        case PciSubDevice10026939::SUBDEVICE_174BE315: return "Radeon R9 285";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026939_H
