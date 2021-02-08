// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267E8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267E8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100267E8: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028075D = 0x1028075D,
    SUBDEVICE_102807B0 = 0x102807B0,
    SUBDEVICE_102807B1 = 0x102807B1,
    SUBDEVICE_1028175D = 0x1028175D,
    SUBDEVICE_102817B0 = 0x102817B0,
    SUBDEVICE_102817B1 = 0x102817B1,
    SUBDEVICE_103C8275 = 0x103C8275,
    SUBDEVICE_103C8277 = 0x103C8277
};



inline const char8* enumToString(PciSubDevice100267E8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100267E8::NONE:               return "NONE";
        case PciSubDevice100267E8::SUBDEVICE_1028075D: return "SUBDEVICE_1028075D";
        case PciSubDevice100267E8::SUBDEVICE_102807B0: return "SUBDEVICE_102807B0";
        case PciSubDevice100267E8::SUBDEVICE_102807B1: return "SUBDEVICE_102807B1";
        case PciSubDevice100267E8::SUBDEVICE_1028175D: return "SUBDEVICE_1028175D";
        case PciSubDevice100267E8::SUBDEVICE_102817B0: return "SUBDEVICE_102817B0";
        case PciSubDevice100267E8::SUBDEVICE_102817B1: return "SUBDEVICE_102817B1";
        case PciSubDevice100267E8::SUBDEVICE_103C8275: return "SUBDEVICE_103C8275";
        case PciSubDevice100267E8::SUBDEVICE_103C8277: return "SUBDEVICE_103C8277";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100267E8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100267E8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100267E8::SUBDEVICE_1028075D: return "Radeon Pro WX 4150";
        case PciSubDevice100267E8::SUBDEVICE_102807B0: return "Radeon Pro WX 4130/4150";
        case PciSubDevice100267E8::SUBDEVICE_102807B1: return "Radeon Pro WX 4130";
        case PciSubDevice100267E8::SUBDEVICE_1028175D: return "Radeon Pro WX 4150";
        case PciSubDevice100267E8::SUBDEVICE_102817B0: return "Radeon Pro WX 4130/4150";
        case PciSubDevice100267E8::SUBDEVICE_102817B1: return "Radeon Pro WX 4130";
        case PciSubDevice100267E8::SUBDEVICE_103C8275: return "Radeon Pro WX 4150";
        case PciSubDevice100267E8::SUBDEVICE_103C8277: return "Radeon Pro WX 4150";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267E8_H
