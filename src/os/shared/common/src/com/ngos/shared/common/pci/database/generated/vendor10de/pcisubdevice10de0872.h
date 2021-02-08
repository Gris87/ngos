// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0872_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0872_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0872: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104319B4 = 0x104319B4,
    SUBDEVICE_10431AA2 = 0x10431AA2,
    SUBDEVICE_10431C02 = 0x10431C02,
    SUBDEVICE_10431C42 = 0x10431C42
};



inline const char8* enumToString(PciSubDevice10DE0872 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0872::NONE:               return "NONE";
        case PciSubDevice10DE0872::SUBDEVICE_104319B4: return "SUBDEVICE_104319B4";
        case PciSubDevice10DE0872::SUBDEVICE_10431AA2: return "SUBDEVICE_10431AA2";
        case PciSubDevice10DE0872::SUBDEVICE_10431C02: return "SUBDEVICE_10431C02";
        case PciSubDevice10DE0872::SUBDEVICE_10431C42: return "SUBDEVICE_10431C42";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0872 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0872 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0872::SUBDEVICE_104319B4: return "GeForce G102M";
        case PciSubDevice10DE0872::SUBDEVICE_10431AA2: return "GeForce G102M";
        case PciSubDevice10DE0872::SUBDEVICE_10431C02: return "GeForce G102M";
        case PciSubDevice10DE0872::SUBDEVICE_10431C42: return "GeForce G205M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0872_H
