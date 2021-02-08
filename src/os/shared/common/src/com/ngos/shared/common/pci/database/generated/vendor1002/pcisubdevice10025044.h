// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025044_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025044_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10025044: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020028 = 0x10020028,
    SUBDEVICE_10020029 = 0x10020029
};



inline const char8* enumToString(PciSubDevice10025044 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025044::NONE:               return "NONE";
        case PciSubDevice10025044::SUBDEVICE_10020028: return "SUBDEVICE_10020028";
        case PciSubDevice10025044::SUBDEVICE_10020029: return "SUBDEVICE_10020029";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10025044 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10025044 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025044::SUBDEVICE_10020028: return "Rage 128 AIW";
        case PciSubDevice10025044::SUBDEVICE_10020029: return "Rage 128 AIW";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025044_H
