// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10027166_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10027166_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10027166: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020323 = 0x10020323,
    SUBDEVICE_15451997 = 0x15451997
};



inline const char8* enumToString(PciSubDevice10027166 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10027166::NONE:               return "NONE";
        case PciSubDevice10027166::SUBDEVICE_10020323: return "SUBDEVICE_10020323";
        case PciSubDevice10027166::SUBDEVICE_15451997: return "SUBDEVICE_15451997";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10027166 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10027166 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10027166::SUBDEVICE_10020323: return "All-in-Wonder 2006 PCI-E Edition (Secondary)";
        case PciSubDevice10027166::SUBDEVICE_15451997: return "Radeon X1300 512MB PCI-e (Secondary)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10027166_H
