// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1023_PCISUBDEVICE10239880_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1023_PCISUBDEVICE10239880_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10239880: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10239880 = 0x10239880
};



inline const char8* enumToString(PciSubDevice10239880 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10239880::NONE:               return "NONE";
        case PciSubDevice10239880::SUBDEVICE_10239880: return "SUBDEVICE_10239880";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10239880 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10239880 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10239880::SUBDEVICE_10239880: return "Blade 3D";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1023_PCISUBDEVICE10239880_H
