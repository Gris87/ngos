// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268C0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268C0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100268C0: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10192383 = 0x10192383,
    SUBDEVICE_102802A2 = 0x102802A2,
    SUBDEVICE_102802FE = 0x102802FE,
    SUBDEVICE_10280419 = 0x10280419,
    SUBDEVICE_103C147D = 0x103C147D,
    SUBDEVICE_103C1521 = 0x103C1521,
    SUBDEVICE_103C1593 = 0x103C1593,
    SUBDEVICE_103C1596 = 0x103C1596,
    SUBDEVICE_103C1599 = 0x103C1599,
    SUBDEVICE_10431C22 = 0x10431C22,
    SUBDEVICE_17AA3927 = 0x17AA3927,
    SUBDEVICE_17AA3952 = 0x17AA3952,
    SUBDEVICE_17AA3978 = 0x17AA3978
};



inline const char8* enumToString(PciSubDevice100268C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268C0::NONE:               return "NONE";
        case PciSubDevice100268C0::SUBDEVICE_10192383: return "SUBDEVICE_10192383";
        case PciSubDevice100268C0::SUBDEVICE_102802A2: return "SUBDEVICE_102802A2";
        case PciSubDevice100268C0::SUBDEVICE_102802FE: return "SUBDEVICE_102802FE";
        case PciSubDevice100268C0::SUBDEVICE_10280419: return "SUBDEVICE_10280419";
        case PciSubDevice100268C0::SUBDEVICE_103C147D: return "SUBDEVICE_103C147D";
        case PciSubDevice100268C0::SUBDEVICE_103C1521: return "SUBDEVICE_103C1521";
        case PciSubDevice100268C0::SUBDEVICE_103C1593: return "SUBDEVICE_103C1593";
        case PciSubDevice100268C0::SUBDEVICE_103C1596: return "SUBDEVICE_103C1596";
        case PciSubDevice100268C0::SUBDEVICE_103C1599: return "SUBDEVICE_103C1599";
        case PciSubDevice100268C0::SUBDEVICE_10431C22: return "SUBDEVICE_10431C22";
        case PciSubDevice100268C0::SUBDEVICE_17AA3927: return "SUBDEVICE_17AA3927";
        case PciSubDevice100268C0::SUBDEVICE_17AA3952: return "SUBDEVICE_17AA3952";
        case PciSubDevice100268C0::SUBDEVICE_17AA3978: return "SUBDEVICE_17AA3978";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100268C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100268C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268C0::SUBDEVICE_10192383: return "Mobility Radeon HD 5730";
        case PciSubDevice100268C0::SUBDEVICE_102802A2: return "Mobility Radeon HD 5730";
        case PciSubDevice100268C0::SUBDEVICE_102802FE: return "Mobility Radeon HD 5730";
        case PciSubDevice100268C0::SUBDEVICE_10280419: return "Mobility Radeon HD 5730";
        case PciSubDevice100268C0::SUBDEVICE_103C147D: return "Mobility Radeon HD 5730";
        case PciSubDevice100268C0::SUBDEVICE_103C1521: return "Madison XT [FirePro M5800]";
        case PciSubDevice100268C0::SUBDEVICE_103C1593: return "Mobility Radeon HD 6570";
        case PciSubDevice100268C0::SUBDEVICE_103C1596: return "Mobility Radeon HD 6570";
        case PciSubDevice100268C0::SUBDEVICE_103C1599: return "Mobility Radeon HD 6570";
        case PciSubDevice100268C0::SUBDEVICE_10431C22: return "Mobility Radeon HD 5730";
        case PciSubDevice100268C0::SUBDEVICE_17AA3927: return "Mobility Radeon HD 5730";
        case PciSubDevice100268C0::SUBDEVICE_17AA3952: return "Mobility Radeon HD 5730";
        case PciSubDevice100268C0::SUBDEVICE_17AA3978: return "Radeon HD 6570M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268C0_H
