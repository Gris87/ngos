// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4163A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4163A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E4163A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028027B = 0x1028027B,
    SUBDEVICE_1028029C = 0x1028029C,
    SUBDEVICE_103C171D = 0x103C171D,
    SUBDEVICE_103C7056 = 0x103C7056,
    SUBDEVICE_12592984 = 0x12592984
};



inline const char8* enumToString(PciSubDevice14E4163A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4163A::NONE:               return "NONE";
        case PciSubDevice14E4163A::SUBDEVICE_1028027B: return "SUBDEVICE_1028027B";
        case PciSubDevice14E4163A::SUBDEVICE_1028029C: return "SUBDEVICE_1028029C";
        case PciSubDevice14E4163A::SUBDEVICE_103C171D: return "SUBDEVICE_103C171D";
        case PciSubDevice14E4163A::SUBDEVICE_103C7056: return "SUBDEVICE_103C7056";
        case PciSubDevice14E4163A::SUBDEVICE_12592984: return "SUBDEVICE_12592984";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E4163A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E4163A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4163A::SUBDEVICE_1028027B: return "PowerEdge M805 Broadcom NetXtreme II BCM5709S";
        case PciSubDevice14E4163A::SUBDEVICE_1028029C: return "PowerEdge M710 BCM5709S Gigabit Ethernet";
        case PciSubDevice14E4163A::SUBDEVICE_103C171D: return "NC382m Dual Port 1GbE Multifunction BL-c Adapter";
        case PciSubDevice14E4163A::SUBDEVICE_103C7056: return "NC382i Integrated Quad Port PCI Express Gigabit Server Adapter";
        case PciSubDevice14E4163A::SUBDEVICE_12592984: return "AT-2973SX";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4163A_H
