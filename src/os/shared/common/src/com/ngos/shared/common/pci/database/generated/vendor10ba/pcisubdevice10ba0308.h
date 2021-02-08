// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10BA_PCISUBDEVICE10BA0308_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10BA_PCISUBDEVICE10BA0308_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10BA0308: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10DD0024 = 0x10DD0024
};



inline const char8* enumToString(PciSubDevice10BA0308 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10BA0308::NONE:               return "NONE";
        case PciSubDevice10BA0308::SUBDEVICE_10DD0024: return "SUBDEVICE_10DD0024";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10BA0308 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10BA0308 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10BA0308::SUBDEVICE_10DD0024: return "Tornado 3000";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10BA_PCISUBDEVICE10BA0308_H
