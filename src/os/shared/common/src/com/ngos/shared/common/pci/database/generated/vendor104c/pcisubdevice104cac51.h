// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC51_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC51_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104CAC51: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11004E = 0x0E11004E,
    SUBDEVICE_10140148 = 0x10140148,
    SUBDEVICE_1014023B = 0x1014023B,
    SUBDEVICE_102800B1 = 0x102800B1,
    SUBDEVICE_1028012A = 0x1028012A,
    SUBDEVICE_103380CD = 0x103380CD,
    SUBDEVICE_10CF1095 = 0x10CF1095,
    SUBDEVICE_E4BF1000 = 0xE4BF1000
};



inline const char8* enumToString(PciSubDevice104CAC51 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104CAC51::NONE:               return "NONE";
        case PciSubDevice104CAC51::SUBDEVICE_0E11004E: return "SUBDEVICE_0E11004E";
        case PciSubDevice104CAC51::SUBDEVICE_10140148: return "SUBDEVICE_10140148";
        case PciSubDevice104CAC51::SUBDEVICE_1014023B: return "SUBDEVICE_1014023B";
        case PciSubDevice104CAC51::SUBDEVICE_102800B1: return "SUBDEVICE_102800B1";
        case PciSubDevice104CAC51::SUBDEVICE_1028012A: return "SUBDEVICE_1028012A";
        case PciSubDevice104CAC51::SUBDEVICE_103380CD: return "SUBDEVICE_103380CD";
        case PciSubDevice104CAC51::SUBDEVICE_10CF1095: return "SUBDEVICE_10CF1095";
        case PciSubDevice104CAC51::SUBDEVICE_E4BF1000: return "SUBDEVICE_E4BF1000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104CAC51 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104CAC51 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104CAC51::SUBDEVICE_0E11004E: return "Evo N600c";
        case PciSubDevice104CAC51::SUBDEVICE_10140148: return "ThinkPad A20m";
        case PciSubDevice104CAC51::SUBDEVICE_1014023B: return "ThinkPad T23";
        case PciSubDevice104CAC51::SUBDEVICE_102800B1: return "Latitude C600";
        case PciSubDevice104CAC51::SUBDEVICE_1028012A: return "Latitude C640";
        case PciSubDevice104CAC51::SUBDEVICE_103380CD: return "Versa Note VXi";
        case PciSubDevice104CAC51::SUBDEVICE_10CF1095: return "Lifebook S-4510/C6155";
        case PciSubDevice104CAC51::SUBDEVICE_E4BF1000: return "CP2-2-HIPHOP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC51_H
