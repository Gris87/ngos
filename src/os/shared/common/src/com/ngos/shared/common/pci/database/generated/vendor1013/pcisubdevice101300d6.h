// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1013_PCISUBDEVICE101300D6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1013_PCISUBDEVICE101300D6_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice101300D6: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_13CE8031 = 0x13CE8031,
    SUBDEVICE_13CF8031 = 0x13CF8031
};



inline const char8* enumToString(PciSubDevice101300D6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice101300D6::NONE:               return "NONE";
        case PciSubDevice101300D6::SUBDEVICE_13CE8031: return "SUBDEVICE_13CE8031";
        case PciSubDevice101300D6::SUBDEVICE_13CF8031: return "SUBDEVICE_13CF8031";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice101300D6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice101300D6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice101300D6::SUBDEVICE_13CE8031: return "Barco Metheus 2 Megapixel, Dual Head";
        case PciSubDevice101300D6::SUBDEVICE_13CF8031: return "Barco Metheus 2 Megapixel, Dual Head";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1013_PCISUBDEVICE101300D6_H
