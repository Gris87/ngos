// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1043_PCISUBDEVICE10430675_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1043_PCISUBDEVICE10430675_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10430675: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_06751704 = 0x06751704,
    SUBDEVICE_06751707 = 0x06751707,
    SUBDEVICE_10CF105E = 0x10CF105E
};



inline const char8* enumToString(PciSubDevice10430675 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10430675::NONE:               return "NONE";
        case PciSubDevice10430675::SUBDEVICE_06751704: return "SUBDEVICE_06751704";
        case PciSubDevice10430675::SUBDEVICE_06751707: return "SUBDEVICE_06751707";
        case PciSubDevice10430675::SUBDEVICE_10CF105E: return "SUBDEVICE_10CF105E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10430675 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10430675 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10430675::SUBDEVICE_06751704: return "ISDN Adapter (PCI Bus, D, C)";
        case PciSubDevice10430675::SUBDEVICE_06751707: return "ISDN Adapter (PCI Bus, DV, W)";
        case PciSubDevice10430675::SUBDEVICE_10CF105E: return "ISDN Adapter (PCI Bus, DV, W)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1043_PCISUBDEVICE10430675_H
