// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267EF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267EF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100267EF: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10251367 = 0x10251367,
    SUBDEVICE_10281703 = 0x10281703,
    SUBDEVICE_103C3421 = 0x103C3421,
    SUBDEVICE_10430561 = 0x10430561,
    SUBDEVICE_106B0160 = 0x106B0160,
    SUBDEVICE_106B0166 = 0x106B0166,
    SUBDEVICE_106B0167 = 0x106B0167,
    SUBDEVICE_106B0179 = 0x106B0179,
    SUBDEVICE_106B017A = 0x106B017A,
    SUBDEVICE_106B018F = 0x106B018F,
    SUBDEVICE_106B0190 = 0x106B0190,
    SUBDEVICE_16421727 = 0x16421727,
    SUBDEVICE_1682956D = 0x1682956D
};



inline const char8* enumToString(PciSubDevice100267EF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100267EF::NONE:               return "NONE";
        case PciSubDevice100267EF::SUBDEVICE_10251367: return "SUBDEVICE_10251367";
        case PciSubDevice100267EF::SUBDEVICE_10281703: return "SUBDEVICE_10281703";
        case PciSubDevice100267EF::SUBDEVICE_103C3421: return "SUBDEVICE_103C3421";
        case PciSubDevice100267EF::SUBDEVICE_10430561: return "SUBDEVICE_10430561";
        case PciSubDevice100267EF::SUBDEVICE_106B0160: return "SUBDEVICE_106B0160";
        case PciSubDevice100267EF::SUBDEVICE_106B0166: return "SUBDEVICE_106B0166";
        case PciSubDevice100267EF::SUBDEVICE_106B0167: return "SUBDEVICE_106B0167";
        case PciSubDevice100267EF::SUBDEVICE_106B0179: return "SUBDEVICE_106B0179";
        case PciSubDevice100267EF::SUBDEVICE_106B017A: return "SUBDEVICE_106B017A";
        case PciSubDevice100267EF::SUBDEVICE_106B018F: return "SUBDEVICE_106B018F";
        case PciSubDevice100267EF::SUBDEVICE_106B0190: return "SUBDEVICE_106B0190";
        case PciSubDevice100267EF::SUBDEVICE_16421727: return "SUBDEVICE_16421727";
        case PciSubDevice100267EF::SUBDEVICE_1682956D: return "SUBDEVICE_1682956D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100267EF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100267EF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100267EF::SUBDEVICE_10251367: return "RX560X 4GB";
        case PciSubDevice100267EF::SUBDEVICE_10281703: return "RX 560D OEM OC 2 GB";
        case PciSubDevice100267EF::SUBDEVICE_103C3421: return "Radeon RX 460";
        case PciSubDevice100267EF::SUBDEVICE_10430561: return "AREZ Radeon RX 560";
        case PciSubDevice100267EF::SUBDEVICE_106B0160: return "Radeon Pro 460";
        case PciSubDevice100267EF::SUBDEVICE_106B0166: return "Radeon Pro 455";
        case PciSubDevice100267EF::SUBDEVICE_106B0167: return "Radeon Pro 450";
        case PciSubDevice100267EF::SUBDEVICE_106B0179: return "Radeon Pro 560";
        case PciSubDevice100267EF::SUBDEVICE_106B017A: return "Radeon Pro 555";
        case PciSubDevice100267EF::SUBDEVICE_106B018F: return "Radeon Pro 560X";
        case PciSubDevice100267EF::SUBDEVICE_106B0190: return "Radeon Pro 555X";
        case PciSubDevice100267EF::SUBDEVICE_16421727: return "Polaris 21 XL [Radeon RX 560D]";
        case PciSubDevice100267EF::SUBDEVICE_1682956D: return "Polaris 21 XL [Radeon RX 560D]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267EF_H
