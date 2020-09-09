// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80868C26_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80868C26_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80868C26: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1909 = 0x103C1909,
    SUBDEVICE_103C1998 = 0x103C1998,
    SUBDEVICE_17AA220E = 0x17AA220E,
    SUBDEVICE_17AA2210 = 0x17AA2210,
    SUBDEVICE_17AA309F = 0x17AA309F,
    SUBDEVICE_221017AA = 0x221017AA
};



inline const char8* enumToString(PciSubDevice80868C26 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80868C26::NONE:               return "NONE";
        case PciSubDevice80868C26::SUBDEVICE_103C1909: return "SUBDEVICE_103C1909";
        case PciSubDevice80868C26::SUBDEVICE_103C1998: return "SUBDEVICE_103C1998";
        case PciSubDevice80868C26::SUBDEVICE_17AA220E: return "SUBDEVICE_17AA220E";
        case PciSubDevice80868C26::SUBDEVICE_17AA2210: return "SUBDEVICE_17AA2210";
        case PciSubDevice80868C26::SUBDEVICE_17AA309F: return "SUBDEVICE_17AA309F";
        case PciSubDevice80868C26::SUBDEVICE_221017AA: return "SUBDEVICE_221017AA";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80868C26 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80868C26 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80868C26::SUBDEVICE_103C1909: return "ZBook 15";
        case PciSubDevice80868C26::SUBDEVICE_103C1998: return "EliteDesk 800 G1";
        case PciSubDevice80868C26::SUBDEVICE_17AA220E: return "ThinkPad T440p";
        case PciSubDevice80868C26::SUBDEVICE_17AA2210: return "ThinkPad T540p";
        case PciSubDevice80868C26::SUBDEVICE_17AA309F: return "ThinkCentre M83";
        case PciSubDevice80868C26::SUBDEVICE_221017AA: return "ThinkPad T540p";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80868C26_H
