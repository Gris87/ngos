// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCISUBDEVICE0731920A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCISUBDEVICE0731920A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice0731920A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0731920A = 0x0731920A,
    SUBDEVICE_0731920B = 0x0731920B,
    SUBDEVICE_0731920C = 0x0731920C
};



inline const char8* enumToString(PciSubDevice0731920A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice0731920A::NONE:               return "NONE";
        case PciSubDevice0731920A::SUBDEVICE_0731920A: return "SUBDEVICE_0731920A";
        case PciSubDevice0731920A::SUBDEVICE_0731920B: return "SUBDEVICE_0731920B";
        case PciSubDevice0731920A::SUBDEVICE_0731920C: return "SUBDEVICE_0731920C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice0731920A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice0731920A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice0731920A::SUBDEVICE_0731920A: return "JH920";
        case PciSubDevice0731920A::SUBDEVICE_0731920B: return "JH920-I";
        case PciSubDevice0731920A::SUBDEVICE_0731920C: return "JH920-M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCISUBDEVICE0731920A_H
