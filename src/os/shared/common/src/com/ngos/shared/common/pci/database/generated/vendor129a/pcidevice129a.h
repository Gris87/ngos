// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR129A_PCIDEVICE129A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR129A_PCIDEVICE129A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice129A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0615 = 0x0615,
    DEVICE_1100 = 0x1100,
    DEVICE_1106 = 0x1106,
    DEVICE_1107 = 0x1107,
    DEVICE_1108 = 0x1108,
    DEVICE_1109 = 0x1109
};



inline const char8* enumToString(PciDevice129A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice129A::NONE:        return "NONE";
        case PciDevice129A::DEVICE_0615: return "DEVICE_0615";
        case PciDevice129A::DEVICE_1100: return "DEVICE_1100";
        case PciDevice129A::DEVICE_1106: return "DEVICE_1106";
        case PciDevice129A::DEVICE_1107: return "DEVICE_1107";
        case PciDevice129A::DEVICE_1108: return "DEVICE_1108";
        case PciDevice129A::DEVICE_1109: return "DEVICE_1109";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice129A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice129A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice129A::DEVICE_0615: return "PBT-615 PCI-X Bus Analyzer";
        case PciDevice129A::DEVICE_1100: return "PMC-FPGA05";
        case PciDevice129A::DEVICE_1106: return "XMC-FPGA05F, PCI interface";
        case PciDevice129A::DEVICE_1107: return "XMC-FPGA05F, PCIe interface";
        case PciDevice129A::DEVICE_1108: return "XMC-FPGA05D, PCI interface";
        case PciDevice129A::DEVICE_1109: return "XMC-FPGA05D, PCIe interface";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR129A_PCIDEVICE129A_H
