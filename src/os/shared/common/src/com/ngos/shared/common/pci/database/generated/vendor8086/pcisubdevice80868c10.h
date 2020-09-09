// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80868C10_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80868C10_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80868C10: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1998 = 0x103C1998,
    SUBDEVICE_10438534 = 0x10438534,
    SUBDEVICE_17AA220E = 0x17AA220E
};



inline const char8* enumToString(PciSubDevice80868C10 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80868C10::NONE:               return "NONE";
        case PciSubDevice80868C10::SUBDEVICE_103C1998: return "SUBDEVICE_103C1998";
        case PciSubDevice80868C10::SUBDEVICE_10438534: return "SUBDEVICE_10438534";
        case PciSubDevice80868C10::SUBDEVICE_17AA220E: return "SUBDEVICE_17AA220E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80868C10 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80868C10 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80868C10::SUBDEVICE_103C1998: return "EliteDesk 800 G1";
        case PciSubDevice80868C10::SUBDEVICE_10438534: return "ASUS H81I-PLUS";
        case PciSubDevice80868C10::SUBDEVICE_17AA220E: return "ThinkPad T440p";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80868C10_H
