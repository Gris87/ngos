// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026660_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026660_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026660: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102805EA = 0x102805EA,
    SUBDEVICE_102806BF = 0x102806BF,
    SUBDEVICE_103C1970 = 0x103C1970,
    SUBDEVICE_103C80BE = 0x103C80BE,
    SUBDEVICE_103C8136 = 0x103C8136,
    SUBDEVICE_103C8329 = 0x103C8329,
    SUBDEVICE_17AA3633 = 0x17AA3633,
    SUBDEVICE_17AA3804 = 0x17AA3804,
    SUBDEVICE_17AA3809 = 0x17AA3809,
    SUBDEVICE_17AA381A = 0x17AA381A,
    SUBDEVICE_17AA390C = 0x17AA390C
};



inline const char8* enumToString(PciSubDevice10026660 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026660::NONE:               return "NONE";
        case PciSubDevice10026660::SUBDEVICE_102805EA: return "SUBDEVICE_102805EA";
        case PciSubDevice10026660::SUBDEVICE_102806BF: return "SUBDEVICE_102806BF";
        case PciSubDevice10026660::SUBDEVICE_103C1970: return "SUBDEVICE_103C1970";
        case PciSubDevice10026660::SUBDEVICE_103C80BE: return "SUBDEVICE_103C80BE";
        case PciSubDevice10026660::SUBDEVICE_103C8136: return "SUBDEVICE_103C8136";
        case PciSubDevice10026660::SUBDEVICE_103C8329: return "SUBDEVICE_103C8329";
        case PciSubDevice10026660::SUBDEVICE_17AA3633: return "SUBDEVICE_17AA3633";
        case PciSubDevice10026660::SUBDEVICE_17AA3804: return "SUBDEVICE_17AA3804";
        case PciSubDevice10026660::SUBDEVICE_17AA3809: return "SUBDEVICE_17AA3809";
        case PciSubDevice10026660::SUBDEVICE_17AA381A: return "SUBDEVICE_17AA381A";
        case PciSubDevice10026660::SUBDEVICE_17AA390C: return "SUBDEVICE_17AA390C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026660 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026660 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026660::SUBDEVICE_102805EA: return "Radeon HD 8670M";
        case PciSubDevice10026660::SUBDEVICE_102806BF: return "Radeon R5 M335";
        case PciSubDevice10026660::SUBDEVICE_103C1970: return "Radeon HD 8670M";
        case PciSubDevice10026660::SUBDEVICE_103C80BE: return "Radeon R5 M330";
        case PciSubDevice10026660::SUBDEVICE_103C8136: return "Radeon R5 M330";
        case PciSubDevice10026660::SUBDEVICE_103C8329: return "Radeon R7 M520";
        case PciSubDevice10026660::SUBDEVICE_17AA3633: return "Radeon R5 A330";
        case PciSubDevice10026660::SUBDEVICE_17AA3804: return "Radeon R5 M330";
        case PciSubDevice10026660::SUBDEVICE_17AA3809: return "Radeon R5 M330";
        case PciSubDevice10026660::SUBDEVICE_17AA381A: return "Radeon R5 M430";
        case PciSubDevice10026660::SUBDEVICE_17AA390C: return "Radeon R5 M330";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026660_H
