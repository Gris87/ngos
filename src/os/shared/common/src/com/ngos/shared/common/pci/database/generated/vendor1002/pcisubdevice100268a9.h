// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268A9_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268A9_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100268A9: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_13CC3D1E = 0x13CC3D1E,
    SUBDEVICE_13CC3D20 = 0x13CC3D20
};



inline const char8* enumToString(PciSubDevice100268A9 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268A9::NONE:               return "NONE";
        case PciSubDevice100268A9::SUBDEVICE_13CC3D1E: return "SUBDEVICE_13CC3D1E";
        case PciSubDevice100268A9::SUBDEVICE_13CC3D20: return "SUBDEVICE_13CC3D20";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100268A9 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100268A9 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268A9::SUBDEVICE_13CC3D1E: return "MXRT-5400";
        case PciSubDevice100268A9::SUBDEVICE_13CC3D20: return "MXRT-5450";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268A9_H
