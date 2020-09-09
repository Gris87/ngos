// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10A9_PCISUBDEVICE10A90009_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10A9_PCISUBDEVICE10A90009_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10A90009: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10A98002 = 0x10A98002
};



inline const char8* enumToString(PciSubDevice10A90009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10A90009::NONE:               return "NONE";
        case PciSubDevice10A90009::SUBDEVICE_10A98002: return "SUBDEVICE_10A98002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10A90009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10A90009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10A90009::SUBDEVICE_10A98002: return "AceNIC Gigabit Ethernet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10A9_PCISUBDEVICE10A90009_H
