// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE13F2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE13F2_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE13F2: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10DE114D = 0x10DE114D,
    SUBDEVICE_10DE114E = 0x10DE114E,
    SUBDEVICE_10DE1150 = 0x10DE1150,
    SUBDEVICE_10DE11B0 = 0x10DE11B0
};



inline const char8* enumToString(PciSubDevice10DE13F2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE13F2::NONE:               return "NONE";
        case PciSubDevice10DE13F2::SUBDEVICE_10DE114D: return "SUBDEVICE_10DE114D";
        case PciSubDevice10DE13F2::SUBDEVICE_10DE114E: return "SUBDEVICE_10DE114E";
        case PciSubDevice10DE13F2::SUBDEVICE_10DE1150: return "SUBDEVICE_10DE1150";
        case PciSubDevice10DE13F2::SUBDEVICE_10DE11B0: return "SUBDEVICE_10DE11B0";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE13F2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE13F2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE13F2::SUBDEVICE_10DE114D: return "GRID M60-1Q";
        case PciSubDevice10DE13F2::SUBDEVICE_10DE114E: return "GRID M60-2Q";
        case PciSubDevice10DE13F2::SUBDEVICE_10DE1150: return "GRID M60-8Q";
        case PciSubDevice10DE13F2::SUBDEVICE_10DE11B0: return "GRID M60-4A";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE13F2_H
