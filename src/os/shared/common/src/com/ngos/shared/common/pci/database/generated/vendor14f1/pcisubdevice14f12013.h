// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F12013_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F12013_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14F12013: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11B195 = 0x0E11B195,
    SUBDEVICE_0E11B196 = 0x0E11B196,
    SUBDEVICE_0E11B1BE = 0x0E11B1BE,
    SUBDEVICE_10258013 = 0x10258013,
    SUBDEVICE_1033809D = 0x1033809D,
    SUBDEVICE_103380BC = 0x103380BC,
    SUBDEVICE_155D6793 = 0x155D6793,
    SUBDEVICE_155D8850 = 0x155D8850
};



inline const char8* enumToString(PciSubDevice14F12013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F12013::NONE:               return "NONE";
        case PciSubDevice14F12013::SUBDEVICE_0E11B195: return "SUBDEVICE_0E11B195";
        case PciSubDevice14F12013::SUBDEVICE_0E11B196: return "SUBDEVICE_0E11B196";
        case PciSubDevice14F12013::SUBDEVICE_0E11B1BE: return "SUBDEVICE_0E11B1BE";
        case PciSubDevice14F12013::SUBDEVICE_10258013: return "SUBDEVICE_10258013";
        case PciSubDevice14F12013::SUBDEVICE_1033809D: return "SUBDEVICE_1033809D";
        case PciSubDevice14F12013::SUBDEVICE_103380BC: return "SUBDEVICE_103380BC";
        case PciSubDevice14F12013::SUBDEVICE_155D6793: return "SUBDEVICE_155D6793";
        case PciSubDevice14F12013::SUBDEVICE_155D8850: return "SUBDEVICE_155D8850";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14F12013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14F12013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F12013::SUBDEVICE_0E11B195: return "Bear";
        case PciSubDevice14F12013::SUBDEVICE_0E11B196: return "Seminole 1";
        case PciSubDevice14F12013::SUBDEVICE_0E11B1BE: return "Seminole 2";
        case PciSubDevice14F12013::SUBDEVICE_10258013: return "Acer";
        case PciSubDevice14F12013::SUBDEVICE_1033809D: return "NEC";
        case PciSubDevice14F12013::SUBDEVICE_103380BC: return "NEC";
        case PciSubDevice14F12013::SUBDEVICE_155D6793: return "HP";
        case PciSubDevice14F12013::SUBDEVICE_155D8850: return "E Machines";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F12013_H
