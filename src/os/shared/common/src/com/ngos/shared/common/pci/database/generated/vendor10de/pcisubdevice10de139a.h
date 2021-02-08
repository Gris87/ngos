// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE139A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE139A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE139A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17AA362C = 0x17AA362C,
    SUBDEVICE_17AA362F = 0x17AA362F,
    SUBDEVICE_17AA363F = 0x17AA363F,
    SUBDEVICE_17AA3640 = 0x17AA3640,
    SUBDEVICE_17AA3647 = 0x17AA3647,
    SUBDEVICE_17AA36B9 = 0x17AA36B9
};



inline const char8* enumToString(PciSubDevice10DE139A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE139A::NONE:               return "NONE";
        case PciSubDevice10DE139A::SUBDEVICE_17AA362C: return "SUBDEVICE_17AA362C";
        case PciSubDevice10DE139A::SUBDEVICE_17AA362F: return "SUBDEVICE_17AA362F";
        case PciSubDevice10DE139A::SUBDEVICE_17AA363F: return "SUBDEVICE_17AA363F";
        case PciSubDevice10DE139A::SUBDEVICE_17AA3640: return "SUBDEVICE_17AA3640";
        case PciSubDevice10DE139A::SUBDEVICE_17AA3647: return "SUBDEVICE_17AA3647";
        case PciSubDevice10DE139A::SUBDEVICE_17AA36B9: return "SUBDEVICE_17AA36B9";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE139A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE139A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE139A::SUBDEVICE_17AA362C: return "GeForce GTX 950A";
        case PciSubDevice10DE139A::SUBDEVICE_17AA362F: return "GeForce GTX 950A";
        case PciSubDevice10DE139A::SUBDEVICE_17AA363F: return "GeForce GTX 950A";
        case PciSubDevice10DE139A::SUBDEVICE_17AA3640: return "GeForce GTX 950A";
        case PciSubDevice10DE139A::SUBDEVICE_17AA3647: return "GeForce GTX 950A";
        case PciSubDevice10DE139A::SUBDEVICE_17AA36B9: return "GeForce GTX 950A";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE139A_H
