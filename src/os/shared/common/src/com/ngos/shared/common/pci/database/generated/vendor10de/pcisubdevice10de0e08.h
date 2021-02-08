// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0E08_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0E08_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0E08: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104383A0 = 0x104383A0,
    SUBDEVICE_10B0104A = 0x10B0104A
};



inline const char8* enumToString(PciSubDevice10DE0E08 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0E08::NONE:               return "NONE";
        case PciSubDevice10DE0E08::SUBDEVICE_104383A0: return "SUBDEVICE_104383A0";
        case PciSubDevice10DE0E08::SUBDEVICE_10B0104A: return "SUBDEVICE_10B0104A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0E08 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0E08 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0E08::SUBDEVICE_104383A0: return "ENGT520 SILENT";
        case PciSubDevice10DE0E08::SUBDEVICE_10B0104A: return "Gainward GeForce GT 610";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0E08_H
