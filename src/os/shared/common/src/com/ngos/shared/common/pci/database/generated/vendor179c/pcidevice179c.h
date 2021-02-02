// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR179C_PCIDEVICE179C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR179C_PCIDEVICE179C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice179C: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0557 = 0x0557,
    DEVICE_0566 = 0x0566,
    DEVICE_1152 = 0x1152,
    DEVICE_5031 = 0x5031,
    DEVICE_5112 = 0x5112,
    DEVICE_5121 = 0x5121,
    DEVICE_5211 = 0x5211,
    DEVICE_5679 = 0x5679
};



inline const char8* enumToString(PciDevice179C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice179C::NONE:        return "NONE";
        case PciDevice179C::DEVICE_0557: return "DEVICE_0557";
        case PciDevice179C::DEVICE_0566: return "DEVICE_0566";
        case PciDevice179C::DEVICE_1152: return "DEVICE_1152";
        case PciDevice179C::DEVICE_5031: return "DEVICE_5031";
        case PciDevice179C::DEVICE_5112: return "DEVICE_5112";
        case PciDevice179C::DEVICE_5121: return "DEVICE_5121";
        case PciDevice179C::DEVICE_5211: return "DEVICE_5211";
        case PciDevice179C::DEVICE_5679: return "DEVICE_5679";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice179C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice179C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice179C::DEVICE_0557: return "DP-PCI-557 [PCI 1553B]";
        case PciDevice179C::DEVICE_0566: return "DP-PCI-566 [Intelligent PCI 1553B]";
        case PciDevice179C::DEVICE_1152: return "DP-cPCI-1152 (8-channel Isolated ADC Module)";
        case PciDevice179C::DEVICE_5031: return "DP-CPCI-5031-Synchro Module";
        case PciDevice179C::DEVICE_5112: return "DP-cPCI-5112 [MM-Carrier]";
        case PciDevice179C::DEVICE_5121: return "DP-CPCI-5121-IP Carrier";
        case PciDevice179C::DEVICE_5211: return "DP-CPCI-5211-IP Carrier";
        case PciDevice179C::DEVICE_5679: return "AGE Display Module";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR179C_PCIDEVICE179C_H
