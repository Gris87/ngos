// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1058_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1058_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE1058: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C2AED = 0x103C2AED,
    SUBDEVICE_103C2AF1 = 0x103C2AF1,
    SUBDEVICE_104310AC = 0x104310AC,
    SUBDEVICE_104310BC = 0x104310BC,
    SUBDEVICE_10431652 = 0x10431652,
    SUBDEVICE_17AA367A = 0x17AA367A,
    SUBDEVICE_17AA3682 = 0x17AA3682,
    SUBDEVICE_17AA3687 = 0x17AA3687,
    SUBDEVICE_17AA3692 = 0x17AA3692,
    SUBDEVICE_17AA3695 = 0x17AA3695,
    SUBDEVICE_17AAA117 = 0x17AAA117
};



inline const char8* enumToString(PciSubDevice10DE1058 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1058::NONE:               return "NONE";
        case PciSubDevice10DE1058::SUBDEVICE_103C2AED: return "SUBDEVICE_103C2AED";
        case PciSubDevice10DE1058::SUBDEVICE_103C2AF1: return "SUBDEVICE_103C2AF1";
        case PciSubDevice10DE1058::SUBDEVICE_104310AC: return "SUBDEVICE_104310AC";
        case PciSubDevice10DE1058::SUBDEVICE_104310BC: return "SUBDEVICE_104310BC";
        case PciSubDevice10DE1058::SUBDEVICE_10431652: return "SUBDEVICE_10431652";
        case PciSubDevice10DE1058::SUBDEVICE_17AA367A: return "SUBDEVICE_17AA367A";
        case PciSubDevice10DE1058::SUBDEVICE_17AA3682: return "SUBDEVICE_17AA3682";
        case PciSubDevice10DE1058::SUBDEVICE_17AA3687: return "SUBDEVICE_17AA3687";
        case PciSubDevice10DE1058::SUBDEVICE_17AA3692: return "SUBDEVICE_17AA3692";
        case PciSubDevice10DE1058::SUBDEVICE_17AA3695: return "SUBDEVICE_17AA3695";
        case PciSubDevice10DE1058::SUBDEVICE_17AAA117: return "SUBDEVICE_17AAA117";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE1058 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE1058 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1058::SUBDEVICE_103C2AED: return "GeForce 610";
        case PciSubDevice10DE1058::SUBDEVICE_103C2AF1: return "GeForce 610";
        case PciSubDevice10DE1058::SUBDEVICE_104310AC: return "GeForce GT 610M";
        case PciSubDevice10DE1058::SUBDEVICE_104310BC: return "GeForce GT 610M";
        case PciSubDevice10DE1058::SUBDEVICE_10431652: return "GeForce GT 610M";
        case PciSubDevice10DE1058::SUBDEVICE_17AA367A: return "GeForce 610M";
        case PciSubDevice10DE1058::SUBDEVICE_17AA3682: return "GeForce 800A";
        case PciSubDevice10DE1058::SUBDEVICE_17AA3687: return "GeForce 800A";
        case PciSubDevice10DE1058::SUBDEVICE_17AA3692: return "GeForce 705A";
        case PciSubDevice10DE1058::SUBDEVICE_17AA3695: return "GeForce 800A";
        case PciSubDevice10DE1058::SUBDEVICE_17AAA117: return "GeForce 610M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1058_H
