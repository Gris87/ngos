// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1092_PCISUBDEVICE10920028_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1092_PCISUBDEVICE10920028_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10920028: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10924A00 = 0x10924A00
};



inline const char8* enumToString(PciSubDevice10920028 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10920028::NONE:               return "NONE";
        case PciSubDevice10920028::SUBDEVICE_10924A00: return "SUBDEVICE_10924A00";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10920028 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10920028 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10920028::SUBDEVICE_10924A00: return "Viper V770 32MB";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1092_PCISUBDEVICE10920028_H
