// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE105B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE105B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE105B: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C2AFB = 0x103C2AFB,
    SUBDEVICE_17AA309D = 0x17AA309D,
    SUBDEVICE_17AA30B1 = 0x17AA30B1,
    SUBDEVICE_17AA30F3 = 0x17AA30F3,
    SUBDEVICE_17AA36A1 = 0x17AA36A1
};



inline const char8* enumToString(PciSubDevice10DE105B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE105B::NONE:               return "NONE";
        case PciSubDevice10DE105B::SUBDEVICE_103C2AFB: return "SUBDEVICE_103C2AFB";
        case PciSubDevice10DE105B::SUBDEVICE_17AA309D: return "SUBDEVICE_17AA309D";
        case PciSubDevice10DE105B::SUBDEVICE_17AA30B1: return "SUBDEVICE_17AA30B1";
        case PciSubDevice10DE105B::SUBDEVICE_17AA30F3: return "SUBDEVICE_17AA30F3";
        case PciSubDevice10DE105B::SUBDEVICE_17AA36A1: return "SUBDEVICE_17AA36A1";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE105B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE105B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE105B::SUBDEVICE_103C2AFB: return "GeForce 705A";
        case PciSubDevice10DE105B::SUBDEVICE_17AA309D: return "GeForce 705A";
        case PciSubDevice10DE105B::SUBDEVICE_17AA30B1: return "GeForce 800A";
        case PciSubDevice10DE105B::SUBDEVICE_17AA30F3: return "GeForce 705A";
        case PciSubDevice10DE105B::SUBDEVICE_17AA36A1: return "GeForce 800A";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE105B_H
