// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10027146_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10027146_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10027146: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020322 = 0x10020322,
    SUBDEVICE_15451996 = 0x15451996
};



inline const char8* enumToString(PciSubDevice10027146 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10027146::NONE:               return "NONE";
        case PciSubDevice10027146::SUBDEVICE_10020322: return "SUBDEVICE_10020322";
        case PciSubDevice10027146::SUBDEVICE_15451996: return "SUBDEVICE_15451996";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10027146 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10027146 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10027146::SUBDEVICE_10020322: return "All-in-Wonder 2006 PCI-E Edition";
        case PciSubDevice10027146::SUBDEVICE_15451996: return "Radeon X1300 512MB PCI-e";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10027146_H
