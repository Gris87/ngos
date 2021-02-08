// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026604_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026604_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026604: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250776 = 0x10250776,
    SUBDEVICE_103C8006 = 0x103C8006,
    SUBDEVICE_103C814F = 0x103C814F,
    SUBDEVICE_103C82AA = 0x103C82AA,
    SUBDEVICE_17AA3643 = 0x17AA3643
};



inline const char8* enumToString(PciSubDevice10026604 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026604::NONE:               return "NONE";
        case PciSubDevice10026604::SUBDEVICE_10250776: return "SUBDEVICE_10250776";
        case PciSubDevice10026604::SUBDEVICE_103C8006: return "SUBDEVICE_103C8006";
        case PciSubDevice10026604::SUBDEVICE_103C814F: return "SUBDEVICE_103C814F";
        case PciSubDevice10026604::SUBDEVICE_103C82AA: return "SUBDEVICE_103C82AA";
        case PciSubDevice10026604::SUBDEVICE_17AA3643: return "SUBDEVICE_17AA3643";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026604 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026604 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026604::SUBDEVICE_10250776: return "Aspire V5 Radeon R7 M265";
        case PciSubDevice10026604::SUBDEVICE_103C8006: return "FirePro M4170";
        case PciSubDevice10026604::SUBDEVICE_103C814F: return "Litho XT [Radeon R7 M365X]";
        case PciSubDevice10026604::SUBDEVICE_103C82AA: return "Litho XT [Radeon R7 M465]";
        case PciSubDevice10026604::SUBDEVICE_17AA3643: return "Radeon R7 A360";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026604_H
