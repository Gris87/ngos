// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCISUBDEVICE0731910A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCISUBDEVICE0731910A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice0731910A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0731910A = 0x0731910A,
    SUBDEVICE_0731910B = 0x0731910B,
    SUBDEVICE_0731910C = 0x0731910C
};



inline const char8* enumToString(PciSubDevice0731910A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice0731910A::NONE:               return "NONE";
        case PciSubDevice0731910A::SUBDEVICE_0731910A: return "SUBDEVICE_0731910A";
        case PciSubDevice0731910A::SUBDEVICE_0731910B: return "SUBDEVICE_0731910B";
        case PciSubDevice0731910A::SUBDEVICE_0731910C: return "SUBDEVICE_0731910C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice0731910A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice0731910A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice0731910A::SUBDEVICE_0731910A: return "JH910";
        case PciSubDevice0731910A::SUBDEVICE_0731910B: return "JH910-I";
        case PciSubDevice0731910A::SUBDEVICE_0731910C: return "JH910-M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCISUBDEVICE0731910A_H
