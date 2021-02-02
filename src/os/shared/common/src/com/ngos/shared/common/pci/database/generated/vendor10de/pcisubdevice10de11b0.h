// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE11B0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE11B0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE11B0: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10DE101A = 0x10DE101A,
    SUBDEVICE_10DE101B = 0x10DE101B
};



inline const char8* enumToString(PciSubDevice10DE11B0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE11B0::NONE:               return "NONE";
        case PciSubDevice10DE11B0::SUBDEVICE_10DE101A: return "SUBDEVICE_10DE101A";
        case PciSubDevice10DE11B0::SUBDEVICE_10DE101B: return "SUBDEVICE_10DE101B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE11B0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE11B0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE11B0::SUBDEVICE_10DE101A: return "GRID K240Q";
        case PciSubDevice10DE11B0::SUBDEVICE_10DE101B: return "GRID K260Q";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE11B0_H
