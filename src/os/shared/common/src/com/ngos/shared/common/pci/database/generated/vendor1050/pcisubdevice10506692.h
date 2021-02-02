// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1050_PCISUBDEVICE10506692_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1050_PCISUBDEVICE10506692_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10506692: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10431702 = 0x10431702,
    SUBDEVICE_10431703 = 0x10431703,
    SUBDEVICE_10431707 = 0x10431707,
    SUBDEVICE_144F1702 = 0x144F1702,
    SUBDEVICE_144F1703 = 0x144F1703,
    SUBDEVICE_144F1707 = 0x144F1707
};



inline const char8* enumToString(PciSubDevice10506692 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10506692::NONE:               return "NONE";
        case PciSubDevice10506692::SUBDEVICE_10431702: return "SUBDEVICE_10431702";
        case PciSubDevice10506692::SUBDEVICE_10431703: return "SUBDEVICE_10431703";
        case PciSubDevice10506692::SUBDEVICE_10431707: return "SUBDEVICE_10431707";
        case PciSubDevice10506692::SUBDEVICE_144F1702: return "SUBDEVICE_144F1702";
        case PciSubDevice10506692::SUBDEVICE_144F1703: return "SUBDEVICE_144F1703";
        case PciSubDevice10506692::SUBDEVICE_144F1707: return "SUBDEVICE_144F1707";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10506692 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10506692 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10506692::SUBDEVICE_10431702: return "ISDN Adapter (PCI Bus, D, W)";
        case PciSubDevice10506692::SUBDEVICE_10431703: return "ISDN Adapter (PCI Bus, DV, W)";
        case PciSubDevice10506692::SUBDEVICE_10431707: return "ISDN Adapter (PCI Bus, DV, W)";
        case PciSubDevice10506692::SUBDEVICE_144F1702: return "ISDN Adapter (PCI Bus, D, W)";
        case PciSubDevice10506692::SUBDEVICE_144F1703: return "ISDN Adapter (PCI Bus, DV, W)";
        case PciSubDevice10506692::SUBDEVICE_144F1707: return "ISDN Adapter (PCI Bus, DV, W)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1050_PCISUBDEVICE10506692_H
