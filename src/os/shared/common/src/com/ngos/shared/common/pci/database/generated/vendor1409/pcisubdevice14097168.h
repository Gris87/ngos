// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1409_PCISUBDEVICE14097168_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1409_PCISUBDEVICE14097168_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14097168: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14090002 = 0x14090002,
    SUBDEVICE_14094027 = 0x14094027,
    SUBDEVICE_14094037 = 0x14094037,
    SUBDEVICE_14094056 = 0x14094056,
    SUBDEVICE_14095027 = 0x14095027,
    SUBDEVICE_14095037 = 0x14095037,
    SUBDEVICE_14095066 = 0x14095066,
    SUBDEVICE_14096056 = 0x14096056
};



inline const char8* enumToString(PciSubDevice14097168 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14097168::NONE:               return "NONE";
        case PciSubDevice14097168::SUBDEVICE_14090002: return "SUBDEVICE_14090002";
        case PciSubDevice14097168::SUBDEVICE_14094027: return "SUBDEVICE_14094027";
        case PciSubDevice14097168::SUBDEVICE_14094037: return "SUBDEVICE_14094037";
        case PciSubDevice14097168::SUBDEVICE_14094056: return "SUBDEVICE_14094056";
        case PciSubDevice14097168::SUBDEVICE_14095027: return "SUBDEVICE_14095027";
        case PciSubDevice14097168::SUBDEVICE_14095037: return "SUBDEVICE_14095037";
        case PciSubDevice14097168::SUBDEVICE_14095066: return "SUBDEVICE_14095066";
        case PciSubDevice14097168::SUBDEVICE_14096056: return "SUBDEVICE_14096056";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14097168 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14097168 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14097168::SUBDEVICE_14090002: return "SER4036A3V (2x RS232 port)";
        case PciSubDevice14097168::SUBDEVICE_14094027: return "SER4027A (1x RS232 port)";
        case PciSubDevice14097168::SUBDEVICE_14094037: return "SER4037A(L) [SUNIX SUN1889] (2x RS232 port)";
        case PciSubDevice14097168::SUBDEVICE_14094056: return "SER4056A (4x RS232)";
        case PciSubDevice14097168::SUBDEVICE_14095027: return "SER4027D";
        case PciSubDevice14097168::SUBDEVICE_14095037: return "SER4037D (2x RS232 port)";
        case PciSubDevice14097168::SUBDEVICE_14095066: return "SER4066R (8x RS232)";
        case PciSubDevice14097168::SUBDEVICE_14096056: return "SER4056D (4x RS232 port)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1409_PCISUBDEVICE14097168_H
