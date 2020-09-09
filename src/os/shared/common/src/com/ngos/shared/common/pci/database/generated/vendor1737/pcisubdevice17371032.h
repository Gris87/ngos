// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1737_PCISUBDEVICE17371032_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1737_PCISUBDEVICE17371032_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice17371032: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17370015 = 0x17370015,
    SUBDEVICE_17370024 = 0x17370024
};



inline const char8* enumToString(PciSubDevice17371032 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17371032::NONE:               return "NONE";
        case PciSubDevice17371032::SUBDEVICE_17370015: return "SUBDEVICE_17370015";
        case PciSubDevice17371032::SUBDEVICE_17370024: return "SUBDEVICE_17370024";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice17371032 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice17371032 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17371032::SUBDEVICE_17370015: return "EG1032 v2 Instant Gigabit Network Adapter";
        case PciSubDevice17371032::SUBDEVICE_17370024: return "EG1032 v3 Instant Gigabit Network Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1737_PCISUBDEVICE17371032_H
