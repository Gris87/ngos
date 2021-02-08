// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1BE0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1BE0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE1BE0: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102807C0 = 0x102807C0,
    SUBDEVICE_1458355B = 0x1458355B
};



inline const char8* enumToString(PciSubDevice10DE1BE0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1BE0::NONE:               return "NONE";
        case PciSubDevice10DE1BE0::SUBDEVICE_102807C0: return "SUBDEVICE_102807C0";
        case PciSubDevice10DE1BE0::SUBDEVICE_1458355B: return "SUBDEVICE_1458355B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE1BE0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE1BE0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1BE0::SUBDEVICE_102807C0: return "GeForce GTX 1080 Max-Q";
        case PciSubDevice10DE1BE0::SUBDEVICE_1458355B: return "GeForce GTX 1080 Max-Q";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1BE0_H
