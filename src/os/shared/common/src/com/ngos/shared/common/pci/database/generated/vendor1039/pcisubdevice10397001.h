// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10397001_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10397001_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10397001: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10190A14 = 0x10190A14,
    SUBDEVICE_10397000 = 0x10397000,
    SUBDEVICE_14625470 = 0x14625470,
    SUBDEVICE_14627010 = 0x14627010,
    SUBDEVICE_17341095 = 0x17341095
};



inline const char8* enumToString(PciSubDevice10397001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10397001::NONE:               return "NONE";
        case PciSubDevice10397001::SUBDEVICE_10190A14: return "SUBDEVICE_10190A14";
        case PciSubDevice10397001::SUBDEVICE_10397000: return "SUBDEVICE_10397000";
        case PciSubDevice10397001::SUBDEVICE_14625470: return "SUBDEVICE_14625470";
        case PciSubDevice10397001::SUBDEVICE_14627010: return "SUBDEVICE_14627010";
        case PciSubDevice10397001::SUBDEVICE_17341095: return "SUBDEVICE_17341095";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10397001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10397001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10397001::SUBDEVICE_10190A14: return "K7S5A motherboard";
        case PciSubDevice10397001::SUBDEVICE_10397000: return "Onboard USB Controller";
        case PciSubDevice10397001::SUBDEVICE_14625470: return "ECS K7SOM+ motherboard";
        case PciSubDevice10397001::SUBDEVICE_14627010: return "MS-6701 motherboard";
        case PciSubDevice10397001::SUBDEVICE_17341095: return "D2030-A1 Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10397001_H
