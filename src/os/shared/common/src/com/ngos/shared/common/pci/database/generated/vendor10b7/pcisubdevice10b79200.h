// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B79200_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B79200_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B79200: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280095 = 0x10280095,
    SUBDEVICE_10280097 = 0x10280097,
    SUBDEVICE_102800B4 = 0x102800B4,
    SUBDEVICE_102800D8 = 0x102800D8,
    SUBDEVICE_102800FE = 0x102800FE,
    SUBDEVICE_1028012A = 0x1028012A,
    SUBDEVICE_10B71000 = 0x10B71000,
    SUBDEVICE_10B77000 = 0x10B77000,
    SUBDEVICE_10F12466 = 0x10F12466,
    SUBDEVICE_144DC005 = 0x144DC005
};



inline const char8* enumToString(PciSubDevice10B79200 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B79200::NONE:               return "NONE";
        case PciSubDevice10B79200::SUBDEVICE_10280095: return "SUBDEVICE_10280095";
        case PciSubDevice10B79200::SUBDEVICE_10280097: return "SUBDEVICE_10280097";
        case PciSubDevice10B79200::SUBDEVICE_102800B4: return "SUBDEVICE_102800B4";
        case PciSubDevice10B79200::SUBDEVICE_102800D8: return "SUBDEVICE_102800D8";
        case PciSubDevice10B79200::SUBDEVICE_102800FE: return "SUBDEVICE_102800FE";
        case PciSubDevice10B79200::SUBDEVICE_1028012A: return "SUBDEVICE_1028012A";
        case PciSubDevice10B79200::SUBDEVICE_10B71000: return "SUBDEVICE_10B71000";
        case PciSubDevice10B79200::SUBDEVICE_10B77000: return "SUBDEVICE_10B77000";
        case PciSubDevice10B79200::SUBDEVICE_10F12466: return "SUBDEVICE_10F12466";
        case PciSubDevice10B79200::SUBDEVICE_144DC005: return "SUBDEVICE_144DC005";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B79200 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B79200 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B79200::SUBDEVICE_10280095: return "3C920 Integrated Fast Ethernet Controller";
        case PciSubDevice10B79200::SUBDEVICE_10280097: return "3C920 Integrated Fast Ethernet Controller";
        case PciSubDevice10B79200::SUBDEVICE_102800B4: return "OptiPlex GX110";
        case PciSubDevice10B79200::SUBDEVICE_102800D8: return "Precision 530";
        case PciSubDevice10B79200::SUBDEVICE_102800FE: return "Optiplex GX240";
        case PciSubDevice10B79200::SUBDEVICE_1028012A: return "3C920 Integrated Fast Ethernet Controller [Latitude C640]";
        case PciSubDevice10B79200::SUBDEVICE_10B71000: return "3C905CX-TX/TX-M Fast Etherlink for PC Management NIC";
        case PciSubDevice10B79200::SUBDEVICE_10B77000: return "10/100 Mini PCI Ethernet Adapter";
        case PciSubDevice10B79200::SUBDEVICE_10F12466: return "Tiger MPX S2466 (3C920 Integrated Fast Ethernet Controller)";
        case PciSubDevice10B79200::SUBDEVICE_144DC005: return "X10 Laptop";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B79200_H
