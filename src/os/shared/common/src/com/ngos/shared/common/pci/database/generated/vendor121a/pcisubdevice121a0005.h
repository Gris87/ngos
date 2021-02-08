// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR121A_PCISUBDEVICE121A0005_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR121A_PCISUBDEVICE121A0005_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice121A0005: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_121A0004 = 0x121A0004,
    SUBDEVICE_121A0030 = 0x121A0030,
    SUBDEVICE_121A0031 = 0x121A0031,
    SUBDEVICE_121A0034 = 0x121A0034,
    SUBDEVICE_121A0036 = 0x121A0036,
    SUBDEVICE_121A0037 = 0x121A0037,
    SUBDEVICE_121A0038 = 0x121A0038,
    SUBDEVICE_121A003A = 0x121A003A,
    SUBDEVICE_121A0044 = 0x121A0044,
    SUBDEVICE_121A004B = 0x121A004B,
    SUBDEVICE_121A004C = 0x121A004C,
    SUBDEVICE_121A004D = 0x121A004D,
    SUBDEVICE_121A004E = 0x121A004E,
    SUBDEVICE_121A0051 = 0x121A0051,
    SUBDEVICE_121A0052 = 0x121A0052,
    SUBDEVICE_121A0057 = 0x121A0057,
    SUBDEVICE_121A0060 = 0x121A0060,
    SUBDEVICE_121A0061 = 0x121A0061,
    SUBDEVICE_121A0062 = 0x121A0062
};



inline const char8* enumToString(PciSubDevice121A0005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice121A0005::NONE:               return "NONE";
        case PciSubDevice121A0005::SUBDEVICE_121A0004: return "SUBDEVICE_121A0004";
        case PciSubDevice121A0005::SUBDEVICE_121A0030: return "SUBDEVICE_121A0030";
        case PciSubDevice121A0005::SUBDEVICE_121A0031: return "SUBDEVICE_121A0031";
        case PciSubDevice121A0005::SUBDEVICE_121A0034: return "SUBDEVICE_121A0034";
        case PciSubDevice121A0005::SUBDEVICE_121A0036: return "SUBDEVICE_121A0036";
        case PciSubDevice121A0005::SUBDEVICE_121A0037: return "SUBDEVICE_121A0037";
        case PciSubDevice121A0005::SUBDEVICE_121A0038: return "SUBDEVICE_121A0038";
        case PciSubDevice121A0005::SUBDEVICE_121A003A: return "SUBDEVICE_121A003A";
        case PciSubDevice121A0005::SUBDEVICE_121A0044: return "SUBDEVICE_121A0044";
        case PciSubDevice121A0005::SUBDEVICE_121A004B: return "SUBDEVICE_121A004B";
        case PciSubDevice121A0005::SUBDEVICE_121A004C: return "SUBDEVICE_121A004C";
        case PciSubDevice121A0005::SUBDEVICE_121A004D: return "SUBDEVICE_121A004D";
        case PciSubDevice121A0005::SUBDEVICE_121A004E: return "SUBDEVICE_121A004E";
        case PciSubDevice121A0005::SUBDEVICE_121A0051: return "SUBDEVICE_121A0051";
        case PciSubDevice121A0005::SUBDEVICE_121A0052: return "SUBDEVICE_121A0052";
        case PciSubDevice121A0005::SUBDEVICE_121A0057: return "SUBDEVICE_121A0057";
        case PciSubDevice121A0005::SUBDEVICE_121A0060: return "SUBDEVICE_121A0060";
        case PciSubDevice121A0005::SUBDEVICE_121A0061: return "SUBDEVICE_121A0061";
        case PciSubDevice121A0005::SUBDEVICE_121A0062: return "SUBDEVICE_121A0062";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice121A0005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice121A0005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice121A0005::SUBDEVICE_121A0004: return "Voodoo3 AGP";
        case PciSubDevice121A0005::SUBDEVICE_121A0030: return "Voodoo3 AGP";
        case PciSubDevice121A0005::SUBDEVICE_121A0031: return "Voodoo3 AGP";
        case PciSubDevice121A0005::SUBDEVICE_121A0034: return "Voodoo3 AGP";
        case PciSubDevice121A0005::SUBDEVICE_121A0036: return "Voodoo3 2000 PCI";
        case PciSubDevice121A0005::SUBDEVICE_121A0037: return "Voodoo3 AGP";
        case PciSubDevice121A0005::SUBDEVICE_121A0038: return "Voodoo3 AGP";
        case PciSubDevice121A0005::SUBDEVICE_121A003A: return "Voodoo3 AGP";
        case PciSubDevice121A0005::SUBDEVICE_121A0044: return "Voodoo3";
        case PciSubDevice121A0005::SUBDEVICE_121A004B: return "Velocity 100";
        case PciSubDevice121A0005::SUBDEVICE_121A004C: return "Velocity 200";
        case PciSubDevice121A0005::SUBDEVICE_121A004D: return "Voodoo3 AGP";
        case PciSubDevice121A0005::SUBDEVICE_121A004E: return "Voodoo3 AGP";
        case PciSubDevice121A0005::SUBDEVICE_121A0051: return "Voodoo3 AGP";
        case PciSubDevice121A0005::SUBDEVICE_121A0052: return "Voodoo3 AGP";
        case PciSubDevice121A0005::SUBDEVICE_121A0057: return "Voodoo3 3000 PCI";
        case PciSubDevice121A0005::SUBDEVICE_121A0060: return "Voodoo3 3500 TV (NTSC)";
        case PciSubDevice121A0005::SUBDEVICE_121A0061: return "Voodoo3 3500 TV (PAL)";
        case PciSubDevice121A0005::SUBDEVICE_121A0062: return "Voodoo3 3500 TV (SECAM)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR121A_PCISUBDEVICE121A0005_H
