// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025B60_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025B60_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10025B60: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043002A = 0x1043002A,
    SUBDEVICE_1043032E = 0x1043032E,
    SUBDEVICE_14582102 = 0x14582102,
    SUBDEVICE_14620400 = 0x14620400,
    SUBDEVICE_14620402 = 0x14620402,
    SUBDEVICE_174B0500 = 0x174B0500,
    SUBDEVICE_196D1086 = 0x196D1086
};



inline const char8* enumToString(PciSubDevice10025B60 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025B60::NONE:               return "NONE";
        case PciSubDevice10025B60::SUBDEVICE_1043002A: return "SUBDEVICE_1043002A";
        case PciSubDevice10025B60::SUBDEVICE_1043032E: return "SUBDEVICE_1043032E";
        case PciSubDevice10025B60::SUBDEVICE_14582102: return "SUBDEVICE_14582102";
        case PciSubDevice10025B60::SUBDEVICE_14620400: return "SUBDEVICE_14620400";
        case PciSubDevice10025B60::SUBDEVICE_14620402: return "SUBDEVICE_14620402";
        case PciSubDevice10025B60::SUBDEVICE_174B0500: return "SUBDEVICE_174B0500";
        case PciSubDevice10025B60::SUBDEVICE_196D1086: return "SUBDEVICE_196D1086";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10025B60 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10025B60 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025B60::SUBDEVICE_1043002A: return "Extreme AX300SE-X";
        case PciSubDevice10025B60::SUBDEVICE_1043032E: return "Extreme AX300/TD";
        case PciSubDevice10025B60::SUBDEVICE_14582102: return "GV-RX30S128D (X300SE)";
        case PciSubDevice10025B60::SUBDEVICE_14620400: return "RX300SE-TD128E (MS-8940 REV: 200)";
        case PciSubDevice10025B60::SUBDEVICE_14620402: return "RX300SE-TD128E (MS-8940)";
        case PciSubDevice10025B60::SUBDEVICE_174B0500: return "Radeon X300 (PCIE)";
        case PciSubDevice10025B60::SUBDEVICE_196D1086: return "X300SE HM";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025B60_H
