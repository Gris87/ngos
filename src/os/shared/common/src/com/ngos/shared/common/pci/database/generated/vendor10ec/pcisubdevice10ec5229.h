// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC5229_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC5229_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10EC5229: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250813 = 0x10250813,
    SUBDEVICE_103C194E = 0x103C194E,
    SUBDEVICE_103C1985 = 0x103C1985,
    SUBDEVICE_17AA3832 = 0x17AA3832
};



inline const char8* enumToString(PciSubDevice10EC5229 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EC5229::NONE:               return "NONE";
        case PciSubDevice10EC5229::SUBDEVICE_10250813: return "SUBDEVICE_10250813";
        case PciSubDevice10EC5229::SUBDEVICE_103C194E: return "SUBDEVICE_103C194E";
        case PciSubDevice10EC5229::SUBDEVICE_103C1985: return "SUBDEVICE_103C1985";
        case PciSubDevice10EC5229::SUBDEVICE_17AA3832: return "SUBDEVICE_17AA3832";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10EC5229 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10EC5229 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EC5229::SUBDEVICE_10250813: return "Aspire R7-571";
        case PciSubDevice10EC5229::SUBDEVICE_103C194E: return "ProBook 455 G1 Notebook";
        case PciSubDevice10EC5229::SUBDEVICE_103C1985: return "Pavilion 17-e163sg Notebook PC";
        case PciSubDevice10EC5229::SUBDEVICE_17AA3832: return "Yoga 520";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC5229_H
