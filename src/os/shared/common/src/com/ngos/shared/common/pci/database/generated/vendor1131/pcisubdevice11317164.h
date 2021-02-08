// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCISUBDEVICE11317164_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCISUBDEVICE11317164_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11317164: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_00708800 = 0x00708800,
    SUBDEVICE_00708810 = 0x00708810,
    SUBDEVICE_00708851 = 0x00708851,
    SUBDEVICE_00708853 = 0x00708853,
    SUBDEVICE_00708880 = 0x00708880,
    SUBDEVICE_00708891 = 0x00708891,
    SUBDEVICE_007088A0 = 0x007088A0,
    SUBDEVICE_007088A1 = 0x007088A1,
    SUBDEVICE_00708900 = 0x00708900,
    SUBDEVICE_00708901 = 0x00708901,
    SUBDEVICE_00708940 = 0x00708940,
    SUBDEVICE_00708951 = 0x00708951,
    SUBDEVICE_00708953 = 0x00708953,
    SUBDEVICE_00708980 = 0x00708980,
    SUBDEVICE_00708991 = 0x00708991,
    SUBDEVICE_00708993 = 0x00708993,
    SUBDEVICE_007089A0 = 0x007089A0,
    SUBDEVICE_007089A1 = 0x007089A1,
    SUBDEVICE_0070F120 = 0x0070F120,
    SUBDEVICE_0070F123 = 0x0070F123
};



inline const char8* enumToString(PciSubDevice11317164 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11317164::NONE:               return "NONE";
        case PciSubDevice11317164::SUBDEVICE_00708800: return "SUBDEVICE_00708800";
        case PciSubDevice11317164::SUBDEVICE_00708810: return "SUBDEVICE_00708810";
        case PciSubDevice11317164::SUBDEVICE_00708851: return "SUBDEVICE_00708851";
        case PciSubDevice11317164::SUBDEVICE_00708853: return "SUBDEVICE_00708853";
        case PciSubDevice11317164::SUBDEVICE_00708880: return "SUBDEVICE_00708880";
        case PciSubDevice11317164::SUBDEVICE_00708891: return "SUBDEVICE_00708891";
        case PciSubDevice11317164::SUBDEVICE_007088A0: return "SUBDEVICE_007088A0";
        case PciSubDevice11317164::SUBDEVICE_007088A1: return "SUBDEVICE_007088A1";
        case PciSubDevice11317164::SUBDEVICE_00708900: return "SUBDEVICE_00708900";
        case PciSubDevice11317164::SUBDEVICE_00708901: return "SUBDEVICE_00708901";
        case PciSubDevice11317164::SUBDEVICE_00708940: return "SUBDEVICE_00708940";
        case PciSubDevice11317164::SUBDEVICE_00708951: return "SUBDEVICE_00708951";
        case PciSubDevice11317164::SUBDEVICE_00708953: return "SUBDEVICE_00708953";
        case PciSubDevice11317164::SUBDEVICE_00708980: return "SUBDEVICE_00708980";
        case PciSubDevice11317164::SUBDEVICE_00708991: return "SUBDEVICE_00708991";
        case PciSubDevice11317164::SUBDEVICE_00708993: return "SUBDEVICE_00708993";
        case PciSubDevice11317164::SUBDEVICE_007089A0: return "SUBDEVICE_007089A0";
        case PciSubDevice11317164::SUBDEVICE_007089A1: return "SUBDEVICE_007089A1";
        case PciSubDevice11317164::SUBDEVICE_0070F120: return "SUBDEVICE_0070F120";
        case PciSubDevice11317164::SUBDEVICE_0070F123: return "SUBDEVICE_0070F123";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11317164 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11317164 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11317164::SUBDEVICE_00708800: return "WinTV HVR-2250";
        case PciSubDevice11317164::SUBDEVICE_00708810: return "WinTV HVR-2250";
        case PciSubDevice11317164::SUBDEVICE_00708851: return "WinTV HVR-2250";
        case PciSubDevice11317164::SUBDEVICE_00708853: return "WinTV HVR-2250";
        case PciSubDevice11317164::SUBDEVICE_00708880: return "WinTV HVR-2250";
        case PciSubDevice11317164::SUBDEVICE_00708891: return "WinTV HVR-2250";
        case PciSubDevice11317164::SUBDEVICE_007088A0: return "WinTV HVR-2250";
        case PciSubDevice11317164::SUBDEVICE_007088A1: return "WinTV HVR-2250";
        case PciSubDevice11317164::SUBDEVICE_00708900: return "WinTV HVR-2200";
        case PciSubDevice11317164::SUBDEVICE_00708901: return "WinTV HVR-2200";
        case PciSubDevice11317164::SUBDEVICE_00708940: return "WinTV HVR-2200 (submodel 89619)";
        case PciSubDevice11317164::SUBDEVICE_00708951: return "WinTV HVR-2200";
        case PciSubDevice11317164::SUBDEVICE_00708953: return "WinTV HVR-2200";
        case PciSubDevice11317164::SUBDEVICE_00708980: return "WinTV HVR-2200";
        case PciSubDevice11317164::SUBDEVICE_00708991: return "WinTV HVR-2200";
        case PciSubDevice11317164::SUBDEVICE_00708993: return "WinTV HVR-2200";
        case PciSubDevice11317164::SUBDEVICE_007089A0: return "WinTV HVR-2200";
        case PciSubDevice11317164::SUBDEVICE_007089A1: return "WinTV HVR-2200";
        case PciSubDevice11317164::SUBDEVICE_0070F120: return "WinTV HVR-2205";
        case PciSubDevice11317164::SUBDEVICE_0070F123: return "WinTV HVR-2215";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCISUBDEVICE11317164_H
