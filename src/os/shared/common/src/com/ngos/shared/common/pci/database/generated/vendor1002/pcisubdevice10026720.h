// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026720_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026720_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026720: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028048F = 0x1028048F,
    SUBDEVICE_10280490 = 0x10280490,
    SUBDEVICE_102804A4 = 0x102804A4,
    SUBDEVICE_102804BA = 0x102804BA,
    SUBDEVICE_1028053F = 0x1028053F,
    SUBDEVICE_106B0B00 = 0x106B0B00,
    SUBDEVICE_15585102 = 0x15585102,
    SUBDEVICE_15585104 = 0x15585104,
    SUBDEVICE_15587201 = 0x15587201,
    SUBDEVICE_174BE188 = 0x174BE188
};



inline const char8* enumToString(PciSubDevice10026720 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026720::NONE:               return "NONE";
        case PciSubDevice10026720::SUBDEVICE_1028048F: return "SUBDEVICE_1028048F";
        case PciSubDevice10026720::SUBDEVICE_10280490: return "SUBDEVICE_10280490";
        case PciSubDevice10026720::SUBDEVICE_102804A4: return "SUBDEVICE_102804A4";
        case PciSubDevice10026720::SUBDEVICE_102804BA: return "SUBDEVICE_102804BA";
        case PciSubDevice10026720::SUBDEVICE_1028053F: return "SUBDEVICE_1028053F";
        case PciSubDevice10026720::SUBDEVICE_106B0B00: return "SUBDEVICE_106B0B00";
        case PciSubDevice10026720::SUBDEVICE_15585102: return "SUBDEVICE_15585102";
        case PciSubDevice10026720::SUBDEVICE_15585104: return "SUBDEVICE_15585104";
        case PciSubDevice10026720::SUBDEVICE_15587201: return "SUBDEVICE_15587201";
        case PciSubDevice10026720::SUBDEVICE_174BE188: return "SUBDEVICE_174BE188";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026720 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026720 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026720::SUBDEVICE_1028048F: return "Radeon HD 6990M";
        case PciSubDevice10026720::SUBDEVICE_10280490: return "Alienware M17x R3 Radeon HD 6970M";
        case PciSubDevice10026720::SUBDEVICE_102804A4: return "FirePro M8900";
        case PciSubDevice10026720::SUBDEVICE_102804BA: return "Radeon HD 6990M";
        case PciSubDevice10026720::SUBDEVICE_1028053F: return "FirePro M8900";
        case PciSubDevice10026720::SUBDEVICE_106B0B00: return "Radeon HD 6970M";
        case PciSubDevice10026720::SUBDEVICE_15585102: return "Radeon HD 6970M";
        case PciSubDevice10026720::SUBDEVICE_15585104: return "Radeon HD 6990M";
        case PciSubDevice10026720::SUBDEVICE_15587201: return "Radeon HD 6990M";
        case PciSubDevice10026720::SUBDEVICE_174BE188: return "Radeon HD 6970M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026720_H
