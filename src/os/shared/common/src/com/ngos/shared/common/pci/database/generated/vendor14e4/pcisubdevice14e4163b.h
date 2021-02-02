// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4163B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4163B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E4163B: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028028C = 0x1028028C,
    SUBDEVICE_1028028D = 0x1028028D,
    SUBDEVICE_102802F1 = 0x102802F1
};



inline const char8* enumToString(PciSubDevice14E4163B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4163B::NONE:               return "NONE";
        case PciSubDevice14E4163B::SUBDEVICE_1028028C: return "SUBDEVICE_1028028C";
        case PciSubDevice14E4163B::SUBDEVICE_1028028D: return "SUBDEVICE_1028028D";
        case PciSubDevice14E4163B::SUBDEVICE_102802F1: return "SUBDEVICE_102802F1";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E4163B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E4163B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4163B::SUBDEVICE_1028028C: return "PowerEdge R410 BCM5716 Gigabit Ethernet";
        case PciSubDevice14E4163B::SUBDEVICE_1028028D: return "PowerEdge T410 BCM5716 Gigabit Ethernet";
        case PciSubDevice14E4163B::SUBDEVICE_102802F1: return "PowerEdge R510 BCM5716 Gigabit Ethernet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4163B_H
