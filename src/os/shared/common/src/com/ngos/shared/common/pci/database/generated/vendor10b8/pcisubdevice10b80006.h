// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B8_PCISUBDEVICE10B80006_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B8_PCISUBDEVICE10B80006_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B80006: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1055E100 = 0x1055E100,
    SUBDEVICE_1055E102 = 0x1055E102,
    SUBDEVICE_1055E300 = 0x1055E300,
    SUBDEVICE_1055E302 = 0x1055E302,
    SUBDEVICE_10B8A012 = 0x10B8A012,
    SUBDEVICE_13A28002 = 0x13A28002,
    SUBDEVICE_13A28006 = 0x13A28006
};



inline const char8* enumToString(PciSubDevice10B80006 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B80006::NONE:               return "NONE";
        case PciSubDevice10B80006::SUBDEVICE_1055E100: return "SUBDEVICE_1055E100";
        case PciSubDevice10B80006::SUBDEVICE_1055E102: return "SUBDEVICE_1055E102";
        case PciSubDevice10B80006::SUBDEVICE_1055E300: return "SUBDEVICE_1055E300";
        case PciSubDevice10B80006::SUBDEVICE_1055E302: return "SUBDEVICE_1055E302";
        case PciSubDevice10B80006::SUBDEVICE_10B8A012: return "SUBDEVICE_10B8A012";
        case PciSubDevice10B80006::SUBDEVICE_13A28002: return "SUBDEVICE_13A28002";
        case PciSubDevice10B80006::SUBDEVICE_13A28006: return "SUBDEVICE_13A28006";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B80006 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B80006 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B80006::SUBDEVICE_1055E100: return "LANEPIC Cardbus Fast Ethernet Adapter";
        case PciSubDevice10B80006::SUBDEVICE_1055E102: return "LANEPIC Cardbus Fast Ethernet Adapter";
        case PciSubDevice10B80006::SUBDEVICE_1055E300: return "LANEPIC Cardbus Fast Ethernet Adapter";
        case PciSubDevice10B80006::SUBDEVICE_1055E302: return "LANEPIC Cardbus Fast Ethernet Adapter";
        case PciSubDevice10B80006::SUBDEVICE_10B8A012: return "LANEPIC Cardbus Fast Ethernet Adapter";
        case PciSubDevice10B80006::SUBDEVICE_13A28002: return "LANEPIC Cardbus Fast Ethernet Adapter";
        case PciSubDevice10B80006::SUBDEVICE_13A28006: return "LANEPIC Cardbus Fast Ethernet Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B8_PCISUBDEVICE10B80006_H
