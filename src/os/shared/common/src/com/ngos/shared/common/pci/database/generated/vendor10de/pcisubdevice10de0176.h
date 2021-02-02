// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0176_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0176_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0176: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C08B0 = 0x103C08B0,
    SUBDEVICE_144DC005 = 0x144DC005,
    SUBDEVICE_4C531090 = 0x4C531090
};



inline const char8* enumToString(PciSubDevice10DE0176 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0176::NONE:               return "NONE";
        case PciSubDevice10DE0176::SUBDEVICE_103C08B0: return "SUBDEVICE_103C08B0";
        case PciSubDevice10DE0176::SUBDEVICE_144DC005: return "SUBDEVICE_144DC005";
        case PciSubDevice10DE0176::SUBDEVICE_4C531090: return "SUBDEVICE_4C531090";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0176 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0176 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0176::SUBDEVICE_103C08B0: return "tc1100 tablet";
        case PciSubDevice10DE0176::SUBDEVICE_144DC005: return "X10 Laptop";
        case PciSubDevice10DE0176::SUBDEVICE_4C531090: return "Cx9 / Vx9 mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0176_H
