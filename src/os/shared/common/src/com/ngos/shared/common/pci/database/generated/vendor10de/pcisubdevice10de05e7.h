// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE05E7_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE05E7_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE05E7: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10DE0595 = 0x10DE0595,
    SUBDEVICE_10DE068F = 0x10DE068F,
    SUBDEVICE_10DE0697 = 0x10DE0697,
    SUBDEVICE_10DE0714 = 0x10DE0714,
    SUBDEVICE_10DE0743 = 0x10DE0743
};



inline const char8* enumToString(PciSubDevice10DE05E7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE05E7::NONE:               return "NONE";
        case PciSubDevice10DE05E7::SUBDEVICE_10DE0595: return "SUBDEVICE_10DE0595";
        case PciSubDevice10DE05E7::SUBDEVICE_10DE068F: return "SUBDEVICE_10DE068F";
        case PciSubDevice10DE05E7::SUBDEVICE_10DE0697: return "SUBDEVICE_10DE0697";
        case PciSubDevice10DE05E7::SUBDEVICE_10DE0714: return "SUBDEVICE_10DE0714";
        case PciSubDevice10DE05E7::SUBDEVICE_10DE0743: return "SUBDEVICE_10DE0743";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE05E7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE05E7 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE05E7::SUBDEVICE_10DE0595: return "Tesla T10 Processor";
        case PciSubDevice10DE05E7::SUBDEVICE_10DE068F: return "Tesla T10 Processor";
        case PciSubDevice10DE05E7::SUBDEVICE_10DE0697: return "Tesla M1060";
        case PciSubDevice10DE05E7::SUBDEVICE_10DE0714: return "Tesla M1060";
        case PciSubDevice10DE05E7::SUBDEVICE_10DE0743: return "Tesla M1060";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE05E7_H
