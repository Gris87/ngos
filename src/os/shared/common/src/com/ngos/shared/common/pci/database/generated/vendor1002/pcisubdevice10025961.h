// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025961_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025961_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10025961: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10022F72 = 0x10022F72,
    SUBDEVICE_10194C30 = 0x10194C30,
    SUBDEVICE_12AB5961 = 0x12AB5961,
    SUBDEVICE_14584018 = 0x14584018,
    SUBDEVICE_174B7C13 = 0x174B7C13,
    SUBDEVICE_17AF200C = 0x17AF200C,
    SUBDEVICE_18BC0050 = 0x18BC0050,
    SUBDEVICE_18BC0051 = 0x18BC0051,
    SUBDEVICE_18BC0053 = 0x18BC0053
};



inline const char8* enumToString(PciSubDevice10025961 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025961::NONE:               return "NONE";
        case PciSubDevice10025961::SUBDEVICE_10022F72: return "SUBDEVICE_10022F72";
        case PciSubDevice10025961::SUBDEVICE_10194C30: return "SUBDEVICE_10194C30";
        case PciSubDevice10025961::SUBDEVICE_12AB5961: return "SUBDEVICE_12AB5961";
        case PciSubDevice10025961::SUBDEVICE_14584018: return "SUBDEVICE_14584018";
        case PciSubDevice10025961::SUBDEVICE_174B7C13: return "SUBDEVICE_174B7C13";
        case PciSubDevice10025961::SUBDEVICE_17AF200C: return "SUBDEVICE_17AF200C";
        case PciSubDevice10025961::SUBDEVICE_18BC0050: return "SUBDEVICE_18BC0050";
        case PciSubDevice10025961::SUBDEVICE_18BC0051: return "SUBDEVICE_18BC0051";
        case PciSubDevice10025961::SUBDEVICE_18BC0053: return "SUBDEVICE_18BC0053";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10025961 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10025961 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025961::SUBDEVICE_10022F72: return "All-in-Wonder 9200 Series";
        case PciSubDevice10025961::SUBDEVICE_10194C30: return "Radeon 9200 VIVO";
        case PciSubDevice10025961::SUBDEVICE_12AB5961: return "YUAN SMARTVGA Radeon 9200";
        case PciSubDevice10025961::SUBDEVICE_14584018: return "Radeon 9200";
        case PciSubDevice10025961::SUBDEVICE_174B7C13: return "Radeon 9200";
        case PciSubDevice10025961::SUBDEVICE_17AF200C: return "Excalibur Radeon 9200";
        case PciSubDevice10025961::SUBDEVICE_18BC0050: return "Radeon 9200 Game Buster";
        case PciSubDevice10025961::SUBDEVICE_18BC0051: return "GC-R9200-C3";
        case PciSubDevice10025961::SUBDEVICE_18BC0053: return "Radeon 9200 Game Buster VIVO";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025961_H
