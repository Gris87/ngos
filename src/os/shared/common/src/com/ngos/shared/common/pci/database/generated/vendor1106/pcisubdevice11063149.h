// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063149_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063149_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11063149: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104380ED = 0x104380ED,
    SUBDEVICE_1458B003 = 0x1458B003,
    SUBDEVICE_14625901 = 0x14625901,
    SUBDEVICE_14627020 = 0x14627020,
    SUBDEVICE_14627094 = 0x14627094,
    SUBDEVICE_14627181 = 0x14627181,
    SUBDEVICE_147B1407 = 0x147B1407,
    SUBDEVICE_147B1408 = 0x147B1408,
    SUBDEVICE_18493149 = 0x18493149,
    SUBDEVICE_A0A004AD = 0xA0A004AD
};



inline const char8* enumToString(PciSubDevice11063149 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063149::NONE:               return "NONE";
        case PciSubDevice11063149::SUBDEVICE_104380ED: return "SUBDEVICE_104380ED";
        case PciSubDevice11063149::SUBDEVICE_1458B003: return "SUBDEVICE_1458B003";
        case PciSubDevice11063149::SUBDEVICE_14625901: return "SUBDEVICE_14625901";
        case PciSubDevice11063149::SUBDEVICE_14627020: return "SUBDEVICE_14627020";
        case PciSubDevice11063149::SUBDEVICE_14627094: return "SUBDEVICE_14627094";
        case PciSubDevice11063149::SUBDEVICE_14627181: return "SUBDEVICE_14627181";
        case PciSubDevice11063149::SUBDEVICE_147B1407: return "SUBDEVICE_147B1407";
        case PciSubDevice11063149::SUBDEVICE_147B1408: return "SUBDEVICE_147B1408";
        case PciSubDevice11063149::SUBDEVICE_18493149: return "SUBDEVICE_18493149";
        case PciSubDevice11063149::SUBDEVICE_A0A004AD: return "SUBDEVICE_A0A004AD";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11063149 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11063149 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063149::SUBDEVICE_104380ED: return "A7V600/K8V Deluxe/K8V-X/A8V Deluxe motherboard";
        case PciSubDevice11063149::SUBDEVICE_1458B003: return "GA-7VM400AM(F) Motherboard";
        case PciSubDevice11063149::SUBDEVICE_14625901: return "KT6 Delta-FIS2R (MS-6590)";
        case PciSubDevice11063149::SUBDEVICE_14627020: return "K8T Neo 2 Motherboard";
        case PciSubDevice11063149::SUBDEVICE_14627094: return "K8T Neo2-F V2.0";
        case PciSubDevice11063149::SUBDEVICE_14627181: return "K8MM3-V mainboard";
        case PciSubDevice11063149::SUBDEVICE_147B1407: return "KV8-MAX3 motherboard";
        case PciSubDevice11063149::SUBDEVICE_147B1408: return "KV7";
        case PciSubDevice11063149::SUBDEVICE_18493149: return "K7VT6 motherboard";
        case PciSubDevice11063149::SUBDEVICE_A0A004AD: return "AK86-L motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063149_H
