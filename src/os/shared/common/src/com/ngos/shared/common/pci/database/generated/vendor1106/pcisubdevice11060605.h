// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11060605_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11060605_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11060605: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1254 = 0x103C1254,
    SUBDEVICE_1043802C = 0x1043802C
};



inline const char8* enumToString(PciSubDevice11060605 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11060605::NONE:               return "NONE";
        case PciSubDevice11060605::SUBDEVICE_103C1254: return "SUBDEVICE_103C1254";
        case PciSubDevice11060605::SUBDEVICE_1043802C: return "SUBDEVICE_1043802C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11060605 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11060605 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11060605::SUBDEVICE_103C1254: return "D9840-60001 [Brio BA410 Motherboard]";
        case PciSubDevice11060605::SUBDEVICE_1043802C: return "CUV4X mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11060605_H
