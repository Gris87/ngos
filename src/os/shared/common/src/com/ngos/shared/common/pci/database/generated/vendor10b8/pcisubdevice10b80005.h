// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B8_PCISUBDEVICE10B80005_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B8_PCISUBDEVICE10B80005_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B80005: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1055E000 = 0x1055E000,
    SUBDEVICE_1055E002 = 0x1055E002,
    SUBDEVICE_10B8A011 = 0x10B8A011,
    SUBDEVICE_10B8A014 = 0x10B8A014,
    SUBDEVICE_10B8A015 = 0x10B8A015,
    SUBDEVICE_10B8A016 = 0x10B8A016,
    SUBDEVICE_10B8A017 = 0x10B8A017
};



inline const char8* enumToString(PciSubDevice10B80005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B80005::NONE:               return "NONE";
        case PciSubDevice10B80005::SUBDEVICE_1055E000: return "SUBDEVICE_1055E000";
        case PciSubDevice10B80005::SUBDEVICE_1055E002: return "SUBDEVICE_1055E002";
        case PciSubDevice10B80005::SUBDEVICE_10B8A011: return "SUBDEVICE_10B8A011";
        case PciSubDevice10B80005::SUBDEVICE_10B8A014: return "SUBDEVICE_10B8A014";
        case PciSubDevice10B80005::SUBDEVICE_10B8A015: return "SUBDEVICE_10B8A015";
        case PciSubDevice10B80005::SUBDEVICE_10B8A016: return "SUBDEVICE_10B8A016";
        case PciSubDevice10B80005::SUBDEVICE_10B8A017: return "SUBDEVICE_10B8A017";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B80005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B80005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B80005::SUBDEVICE_1055E000: return "LANEPIC 10/100 [EVB171Q-PCI]";
        case PciSubDevice10B80005::SUBDEVICE_1055E002: return "LANEPIC 10/100 [EVB171G-PCI]";
        case PciSubDevice10B80005::SUBDEVICE_10B8A011: return "EtherPower II 10/100";
        case PciSubDevice10B80005::SUBDEVICE_10B8A014: return "EtherPower II 10/100";
        case PciSubDevice10B80005::SUBDEVICE_10B8A015: return "EtherPower II 10/100";
        case PciSubDevice10B80005::SUBDEVICE_10B8A016: return "EtherPower II 10/100";
        case PciSubDevice10B80005::SUBDEVICE_10B8A017: return "EtherPower II 10/100";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B8_PCISUBDEVICE10B80005_H
