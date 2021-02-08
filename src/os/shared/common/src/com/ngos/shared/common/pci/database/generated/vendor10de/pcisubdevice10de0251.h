// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0251_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0251_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0251: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10438023 = 0x10438023,
    SUBDEVICE_10DE0251 = 0x10DE0251,
    SUBDEVICE_14628710 = 0x14628710
};



inline const char8* enumToString(PciSubDevice10DE0251 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0251::NONE:               return "NONE";
        case PciSubDevice10DE0251::SUBDEVICE_10438023: return "SUBDEVICE_10438023";
        case PciSubDevice10DE0251::SUBDEVICE_10DE0251: return "SUBDEVICE_10DE0251";
        case PciSubDevice10DE0251::SUBDEVICE_14628710: return "SUBDEVICE_14628710";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0251 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0251 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0251::SUBDEVICE_10438023: return "v8440 GeForce 4 Ti4400";
        case PciSubDevice10DE0251::SUBDEVICE_10DE0251: return "PNY GeForce4 Ti 4400";
        case PciSubDevice10DE0251::SUBDEVICE_14628710: return "PNY GeForce4 Ti 4400";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0251_H
