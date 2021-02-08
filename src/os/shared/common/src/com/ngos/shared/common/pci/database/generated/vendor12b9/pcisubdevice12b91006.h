// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12B9_PCISUBDEVICE12B91006_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12B9_PCISUBDEVICE12B91006_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12B91006: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_12B9005C = 0x12B9005C,
    SUBDEVICE_12B9005E = 0x12B9005E,
    SUBDEVICE_12B90062 = 0x12B90062,
    SUBDEVICE_12B90068 = 0x12B90068,
    SUBDEVICE_12B9007A = 0x12B9007A,
    SUBDEVICE_12B9007F = 0x12B9007F,
    SUBDEVICE_12B90080 = 0x12B90080,
    SUBDEVICE_12B90081 = 0x12B90081,
    SUBDEVICE_12B90091 = 0x12B90091
};



inline const char8* enumToString(PciSubDevice12B91006 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12B91006::NONE:               return "NONE";
        case PciSubDevice12B91006::SUBDEVICE_12B9005C: return "SUBDEVICE_12B9005C";
        case PciSubDevice12B91006::SUBDEVICE_12B9005E: return "SUBDEVICE_12B9005E";
        case PciSubDevice12B91006::SUBDEVICE_12B90062: return "SUBDEVICE_12B90062";
        case PciSubDevice12B91006::SUBDEVICE_12B90068: return "SUBDEVICE_12B90068";
        case PciSubDevice12B91006::SUBDEVICE_12B9007A: return "SUBDEVICE_12B9007A";
        case PciSubDevice12B91006::SUBDEVICE_12B9007F: return "SUBDEVICE_12B9007F";
        case PciSubDevice12B91006::SUBDEVICE_12B90080: return "SUBDEVICE_12B90080";
        case PciSubDevice12B91006::SUBDEVICE_12B90081: return "SUBDEVICE_12B90081";
        case PciSubDevice12B91006::SUBDEVICE_12B90091: return "SUBDEVICE_12B90091";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12B91006 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12B91006 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12B91006::SUBDEVICE_12B9005C: return "USR 56k Internal Voice WinModem (Model 3472)";
        case PciSubDevice12B91006::SUBDEVICE_12B9005E: return "USR 56k Internal WinModem (Models 662975)";
        case PciSubDevice12B91006::SUBDEVICE_12B90062: return "USR 56k Internal Voice WinModem (Model 662978)";
        case PciSubDevice12B91006::SUBDEVICE_12B90068: return "USR 56k Internal Voice WinModem (Model 5690)";
        case PciSubDevice12B91006::SUBDEVICE_12B9007A: return "USR 56k Internal Voice WinModem (Model 662974)";
        case PciSubDevice12B91006::SUBDEVICE_12B9007F: return "USR 56k Internal WinModem (Models 5698, 5699)";
        case PciSubDevice12B91006::SUBDEVICE_12B90080: return "USR 56k Internal WinModem (Models 2975, 3528)";
        case PciSubDevice12B91006::SUBDEVICE_12B90081: return "USR 56k Internal Voice WinModem (Models 2974, 3529)";
        case PciSubDevice12B91006::SUBDEVICE_12B90091: return "USR 56k Internal Voice WinModem (Model 2978)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12B9_PCISUBDEVICE12B91006_H
