// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCISUBDEVICE53339102_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCISUBDEVICE53339102_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice53339102: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10925932 = 0x10925932,
    SUBDEVICE_10925934 = 0x10925934,
    SUBDEVICE_10925952 = 0x10925952,
    SUBDEVICE_10925954 = 0x10925954,
    SUBDEVICE_10925A35 = 0x10925A35,
    SUBDEVICE_10925A37 = 0x10925A37,
    SUBDEVICE_10925A55 = 0x10925A55,
    SUBDEVICE_10925A57 = 0x10925A57
};



inline const char8* enumToString(PciSubDevice53339102 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice53339102::NONE:               return "NONE";
        case PciSubDevice53339102::SUBDEVICE_10925932: return "SUBDEVICE_10925932";
        case PciSubDevice53339102::SUBDEVICE_10925934: return "SUBDEVICE_10925934";
        case PciSubDevice53339102::SUBDEVICE_10925952: return "SUBDEVICE_10925952";
        case PciSubDevice53339102::SUBDEVICE_10925954: return "SUBDEVICE_10925954";
        case PciSubDevice53339102::SUBDEVICE_10925A35: return "SUBDEVICE_10925A35";
        case PciSubDevice53339102::SUBDEVICE_10925A37: return "SUBDEVICE_10925A37";
        case PciSubDevice53339102::SUBDEVICE_10925A55: return "SUBDEVICE_10925A55";
        case PciSubDevice53339102::SUBDEVICE_10925A57: return "SUBDEVICE_10925A57";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice53339102 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice53339102 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice53339102::SUBDEVICE_10925932: return "Viper II Z200";
        case PciSubDevice53339102::SUBDEVICE_10925934: return "Viper II Z200";
        case PciSubDevice53339102::SUBDEVICE_10925952: return "Viper II Z200";
        case PciSubDevice53339102::SUBDEVICE_10925954: return "Viper II Z200";
        case PciSubDevice53339102::SUBDEVICE_10925A35: return "Viper II Z200";
        case PciSubDevice53339102::SUBDEVICE_10925A37: return "Viper II Z200";
        case PciSubDevice53339102::SUBDEVICE_10925A55: return "Viper II Z200";
        case PciSubDevice53339102::SUBDEVICE_10925A57: return "Viper II Z200";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCISUBDEVICE53339102_H
