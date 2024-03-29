// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCISUBDEVICE0731930A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCISUBDEVICE0731930A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice0731930A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0731930A = 0x0731930A,
    SUBDEVICE_0731930B = 0x0731930B
};



inline const char8* enumToString(PciSubDevice0731930A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice0731930A::NONE:               return "NONE";
        case PciSubDevice0731930A::SUBDEVICE_0731930A: return "SUBDEVICE_0731930A";
        case PciSubDevice0731930A::SUBDEVICE_0731930B: return "SUBDEVICE_0731930B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice0731930A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice0731930A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice0731930A::SUBDEVICE_0731930A: return "JH930-I";
        case PciSubDevice0731930A::SUBDEVICE_0731930B: return "JH930-M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCISUBDEVICE0731930A_H
