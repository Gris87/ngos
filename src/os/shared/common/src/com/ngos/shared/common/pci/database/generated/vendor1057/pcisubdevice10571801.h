// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1057_PCISUBDEVICE10571801_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1057_PCISUBDEVICE10571801_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10571801: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14FB0101 = 0x14FB0101,
    SUBDEVICE_14FB0102 = 0x14FB0102,
    SUBDEVICE_14FB0202 = 0x14FB0202,
    SUBDEVICE_14FB0611 = 0x14FB0611,
    SUBDEVICE_14FB0612 = 0x14FB0612,
    SUBDEVICE_14FB0613 = 0x14FB0613,
    SUBDEVICE_14FB0614 = 0x14FB0614,
    SUBDEVICE_14FB0621 = 0x14FB0621,
    SUBDEVICE_14FB0622 = 0x14FB0622,
    SUBDEVICE_14FB0810 = 0x14FB0810,
    SUBDEVICE_175C4200 = 0x175C4200,
    SUBDEVICE_175C4300 = 0x175C4300,
    SUBDEVICE_175C4400 = 0x175C4400,
    SUBDEVICE_ECC00010 = 0xECC00010,
    SUBDEVICE_ECC00020 = 0xECC00020,
    SUBDEVICE_ECC00030 = 0xECC00030,
    SUBDEVICE_ECC00031 = 0xECC00031,
    SUBDEVICE_ECC00040 = 0xECC00040,
    SUBDEVICE_ECC00041 = 0xECC00041,
    SUBDEVICE_ECC00050 = 0xECC00050,
    SUBDEVICE_ECC00051 = 0xECC00051,
    SUBDEVICE_ECC00070 = 0xECC00070,
    SUBDEVICE_ECC00071 = 0xECC00071,
    SUBDEVICE_ECC00072 = 0xECC00072
};



inline const char8* enumToString(PciSubDevice10571801 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10571801::NONE:               return "NONE";
        case PciSubDevice10571801::SUBDEVICE_14FB0101: return "SUBDEVICE_14FB0101";
        case PciSubDevice10571801::SUBDEVICE_14FB0102: return "SUBDEVICE_14FB0102";
        case PciSubDevice10571801::SUBDEVICE_14FB0202: return "SUBDEVICE_14FB0202";
        case PciSubDevice10571801::SUBDEVICE_14FB0611: return "SUBDEVICE_14FB0611";
        case PciSubDevice10571801::SUBDEVICE_14FB0612: return "SUBDEVICE_14FB0612";
        case PciSubDevice10571801::SUBDEVICE_14FB0613: return "SUBDEVICE_14FB0613";
        case PciSubDevice10571801::SUBDEVICE_14FB0614: return "SUBDEVICE_14FB0614";
        case PciSubDevice10571801::SUBDEVICE_14FB0621: return "SUBDEVICE_14FB0621";
        case PciSubDevice10571801::SUBDEVICE_14FB0622: return "SUBDEVICE_14FB0622";
        case PciSubDevice10571801::SUBDEVICE_14FB0810: return "SUBDEVICE_14FB0810";
        case PciSubDevice10571801::SUBDEVICE_175C4200: return "SUBDEVICE_175C4200";
        case PciSubDevice10571801::SUBDEVICE_175C4300: return "SUBDEVICE_175C4300";
        case PciSubDevice10571801::SUBDEVICE_175C4400: return "SUBDEVICE_175C4400";
        case PciSubDevice10571801::SUBDEVICE_ECC00010: return "SUBDEVICE_ECC00010";
        case PciSubDevice10571801::SUBDEVICE_ECC00020: return "SUBDEVICE_ECC00020";
        case PciSubDevice10571801::SUBDEVICE_ECC00030: return "SUBDEVICE_ECC00030";
        case PciSubDevice10571801::SUBDEVICE_ECC00031: return "SUBDEVICE_ECC00031";
        case PciSubDevice10571801::SUBDEVICE_ECC00040: return "SUBDEVICE_ECC00040";
        case PciSubDevice10571801::SUBDEVICE_ECC00041: return "SUBDEVICE_ECC00041";
        case PciSubDevice10571801::SUBDEVICE_ECC00050: return "SUBDEVICE_ECC00050";
        case PciSubDevice10571801::SUBDEVICE_ECC00051: return "SUBDEVICE_ECC00051";
        case PciSubDevice10571801::SUBDEVICE_ECC00070: return "SUBDEVICE_ECC00070";
        case PciSubDevice10571801::SUBDEVICE_ECC00071: return "SUBDEVICE_ECC00071";
        case PciSubDevice10571801::SUBDEVICE_ECC00072: return "SUBDEVICE_ECC00072";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10571801 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10571801 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10571801::SUBDEVICE_14FB0101: return "Transas Radar Imitator Board [RIM]";
        case PciSubDevice10571801::SUBDEVICE_14FB0102: return "Transas Radar Imitator Board [RIM-2]";
        case PciSubDevice10571801::SUBDEVICE_14FB0202: return "Transas Radar Integrator Board [RIB-2]";
        case PciSubDevice10571801::SUBDEVICE_14FB0611: return "1 channel CAN bus Controller [CanPci-1]";
        case PciSubDevice10571801::SUBDEVICE_14FB0612: return "2 channels CAN bus Controller [CanPci-2]";
        case PciSubDevice10571801::SUBDEVICE_14FB0613: return "3 channels CAN bus Controller [CanPci-3]";
        case PciSubDevice10571801::SUBDEVICE_14FB0614: return "4 channels CAN bus Controller [CanPci-4]";
        case PciSubDevice10571801::SUBDEVICE_14FB0621: return "1 channel CAN bus Controller [CanPci2-1]";
        case PciSubDevice10571801::SUBDEVICE_14FB0622: return "2 channels CAN bus Controller [CanPci2-2]";
        case PciSubDevice10571801::SUBDEVICE_14FB0810: return "Transas VTS Radar Integrator Board [RIB-4]";
        case PciSubDevice10571801::SUBDEVICE_175C4200: return "ASI4215 Audio Adapter";
        case PciSubDevice10571801::SUBDEVICE_175C4300: return "ASI43xx Audio Adapter";
        case PciSubDevice10571801::SUBDEVICE_175C4400: return "ASI4401 Audio Adapter";
        case PciSubDevice10571801::SUBDEVICE_ECC00010: return "Darla";
        case PciSubDevice10571801::SUBDEVICE_ECC00020: return "Gina";
        case PciSubDevice10571801::SUBDEVICE_ECC00030: return "Layla rev.0";
        case PciSubDevice10571801::SUBDEVICE_ECC00031: return "Layla rev.1";
        case PciSubDevice10571801::SUBDEVICE_ECC00040: return "Darla24 rev.0";
        case PciSubDevice10571801::SUBDEVICE_ECC00041: return "Darla24 rev.1";
        case PciSubDevice10571801::SUBDEVICE_ECC00050: return "Gina24 rev.0";
        case PciSubDevice10571801::SUBDEVICE_ECC00051: return "Gina24 rev.1";
        case PciSubDevice10571801::SUBDEVICE_ECC00070: return "Mona rev.0";
        case PciSubDevice10571801::SUBDEVICE_ECC00071: return "Mona rev.1";
        case PciSubDevice10571801::SUBDEVICE_ECC00072: return "Mona rev.2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1057_PCISUBDEVICE10571801_H
