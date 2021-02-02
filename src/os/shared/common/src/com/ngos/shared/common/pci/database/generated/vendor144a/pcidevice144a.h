// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144A_PCIDEVICE144A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144A_PCIDEVICE144A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice144A: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_6208 = 0x6208,
    DEVICE_7250 = 0x7250,
    DEVICE_7296 = 0x7296,
    DEVICE_7432 = 0x7432,
    DEVICE_7433 = 0x7433,
    DEVICE_7434 = 0x7434,
    DEVICE_7841 = 0x7841,
    DEVICE_8133 = 0x8133,
    DEVICE_8164 = 0x8164,
    DEVICE_8554 = 0x8554,
    DEVICE_9111 = 0x9111,
    DEVICE_9113 = 0x9113,
    DEVICE_9114 = 0x9114,
    DEVICE_A001 = 0xA001
};



inline const char8* enumToString(PciDevice144A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice144A::NONE:        return "NONE";
        case PciDevice144A::DEVICE_6208: return "DEVICE_6208";
        case PciDevice144A::DEVICE_7250: return "DEVICE_7250";
        case PciDevice144A::DEVICE_7296: return "DEVICE_7296";
        case PciDevice144A::DEVICE_7432: return "DEVICE_7432";
        case PciDevice144A::DEVICE_7433: return "DEVICE_7433";
        case PciDevice144A::DEVICE_7434: return "DEVICE_7434";
        case PciDevice144A::DEVICE_7841: return "DEVICE_7841";
        case PciDevice144A::DEVICE_8133: return "DEVICE_8133";
        case PciDevice144A::DEVICE_8164: return "DEVICE_8164";
        case PciDevice144A::DEVICE_8554: return "DEVICE_8554";
        case PciDevice144A::DEVICE_9111: return "DEVICE_9111";
        case PciDevice144A::DEVICE_9113: return "DEVICE_9113";
        case PciDevice144A::DEVICE_9114: return "DEVICE_9114";
        case PciDevice144A::DEVICE_A001: return "DEVICE_A001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice144A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice144A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice144A::DEVICE_6208: return "PCI-6208V";
        case PciDevice144A::DEVICE_7250: return "PCI-7250";
        case PciDevice144A::DEVICE_7296: return "PCI-7296";
        case PciDevice144A::DEVICE_7432: return "PCI-7432";
        case PciDevice144A::DEVICE_7433: return "PCI-7433";
        case PciDevice144A::DEVICE_7434: return "PCI-7434";
        case PciDevice144A::DEVICE_7841: return "PCI-7841";
        case PciDevice144A::DEVICE_8133: return "PCI-8133";
        case PciDevice144A::DEVICE_8164: return "PCI-8164";
        case PciDevice144A::DEVICE_8554: return "PCI-8554";
        case PciDevice144A::DEVICE_9111: return "PCI-9111";
        case PciDevice144A::DEVICE_9113: return "PCI-9113";
        case PciDevice144A::DEVICE_9114: return "PCI-9114";
        case PciDevice144A::DEVICE_A001: return "ADi-BSEC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144A_PCIDEVICE144A_H
