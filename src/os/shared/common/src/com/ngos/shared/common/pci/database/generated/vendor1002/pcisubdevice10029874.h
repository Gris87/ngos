// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029874_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029874_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10029874: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10021871 = 0x10021871,
    SUBDEVICE_10021E20 = 0x10021E20,
    SUBDEVICE_102806BD = 0x102806BD,
    SUBDEVICE_103C2B44 = 0x103C2B44,
    SUBDEVICE_103C8221 = 0x103C8221,
    SUBDEVICE_103C8223 = 0x103C8223,
    SUBDEVICE_103C8238 = 0x103C8238,
    SUBDEVICE_103C8353 = 0x103C8353,
    SUBDEVICE_1458D000 = 0x1458D000,
    SUBDEVICE_17AA5113 = 0x17AA5113,
    SUBDEVICE_17AA5116 = 0x17AA5116,
    SUBDEVICE_17AA5118 = 0x17AA5118
};



inline const char8* enumToString(PciSubDevice10029874 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029874::NONE:               return "NONE";
        case PciSubDevice10029874::SUBDEVICE_10021871: return "SUBDEVICE_10021871";
        case PciSubDevice10029874::SUBDEVICE_10021E20: return "SUBDEVICE_10021E20";
        case PciSubDevice10029874::SUBDEVICE_102806BD: return "SUBDEVICE_102806BD";
        case PciSubDevice10029874::SUBDEVICE_103C2B44: return "SUBDEVICE_103C2B44";
        case PciSubDevice10029874::SUBDEVICE_103C8221: return "SUBDEVICE_103C8221";
        case PciSubDevice10029874::SUBDEVICE_103C8223: return "SUBDEVICE_103C8223";
        case PciSubDevice10029874::SUBDEVICE_103C8238: return "SUBDEVICE_103C8238";
        case PciSubDevice10029874::SUBDEVICE_103C8353: return "SUBDEVICE_103C8353";
        case PciSubDevice10029874::SUBDEVICE_1458D000: return "SUBDEVICE_1458D000";
        case PciSubDevice10029874::SUBDEVICE_17AA5113: return "SUBDEVICE_17AA5113";
        case PciSubDevice10029874::SUBDEVICE_17AA5116: return "SUBDEVICE_17AA5116";
        case PciSubDevice10029874::SUBDEVICE_17AA5118: return "SUBDEVICE_17AA5118";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10029874 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10029874 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029874::SUBDEVICE_10021871: return "Radeon R5 Graphics";
        case PciSubDevice10029874::SUBDEVICE_10021E20: return "Radeon R7 Graphics";
        case PciSubDevice10029874::SUBDEVICE_102806BD: return "Radeon R6 Graphics";
        case PciSubDevice10029874::SUBDEVICE_103C2B44: return "Radeon R6 Graphics";
        case PciSubDevice10029874::SUBDEVICE_103C8221: return "Radeon R5 Graphics";
        case PciSubDevice10029874::SUBDEVICE_103C8223: return "Radeon R5 Graphics";
        case PciSubDevice10029874::SUBDEVICE_103C8238: return "Radeon R7 Graphics";
        case PciSubDevice10029874::SUBDEVICE_103C8353: return "Radeon R7 Graphics";
        case PciSubDevice10029874::SUBDEVICE_1458D000: return "Radeon R7 Graphics";
        case PciSubDevice10029874::SUBDEVICE_17AA5113: return "Radeon R6 Graphics";
        case PciSubDevice10029874::SUBDEVICE_17AA5116: return "Radeon R6 Graphics";
        case PciSubDevice10029874::SUBDEVICE_17AA5118: return "Radeon R5 Graphics";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029874_H
