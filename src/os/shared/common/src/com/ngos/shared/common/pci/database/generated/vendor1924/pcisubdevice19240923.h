// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19240923_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19240923_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19240923: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1924800B = 0x1924800B,
    SUBDEVICE_1924800E = 0x1924800E,
    SUBDEVICE_1924800F = 0x1924800F
};



inline const char8* enumToString(PciSubDevice19240923 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19240923::NONE:               return "NONE";
        case PciSubDevice19240923::SUBDEVICE_1924800B: return "SUBDEVICE_1924800B";
        case PciSubDevice19240923::SUBDEVICE_1924800E: return "SUBDEVICE_1924800E";
        case PciSubDevice19240923::SUBDEVICE_1924800F: return "SUBDEVICE_1924800F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19240923 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19240923 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19240923::SUBDEVICE_1924800B: return "SFN7x42Q-R1 Flareon Ultra 7000 Series 10/40G Adapter";
        case PciSubDevice19240923::SUBDEVICE_1924800E: return "SFN7x42Q-R2 Flareon Ultra 7000 Series 10/40G Adapter";
        case PciSubDevice19240923::SUBDEVICE_1924800F: return "SFN7xx4F-R1 Flareon Ultra 7000 Series 10G Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1924_PCISUBDEVICE19240923_H
