// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1414_PCIDEVICE1414_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1414_PCIDEVICE1414_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1414: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_008C = 0x008C,
    DEVICE_5353 = 0x5353,
    DEVICE_5801 = 0x5801,
    DEVICE_5802 = 0x5802,
    DEVICE_5803 = 0x5803,
    DEVICE_5804 = 0x5804,
    DEVICE_5805 = 0x5805,
    DEVICE_5806 = 0x5806,
    DEVICE_5807 = 0x5807,
    DEVICE_580A = 0x580A,
    DEVICE_580B = 0x580B,
    DEVICE_580D = 0x580D,
    DEVICE_5811 = 0x5811
};



inline const char8* enumToString(PciDevice1414 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1414::NONE:        return "NONE";
        case PciDevice1414::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1414::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1414::DEVICE_008C: return "DEVICE_008C";
        case PciDevice1414::DEVICE_5353: return "DEVICE_5353";
        case PciDevice1414::DEVICE_5801: return "DEVICE_5801";
        case PciDevice1414::DEVICE_5802: return "DEVICE_5802";
        case PciDevice1414::DEVICE_5803: return "DEVICE_5803";
        case PciDevice1414::DEVICE_5804: return "DEVICE_5804";
        case PciDevice1414::DEVICE_5805: return "DEVICE_5805";
        case PciDevice1414::DEVICE_5806: return "DEVICE_5806";
        case PciDevice1414::DEVICE_5807: return "DEVICE_5807";
        case PciDevice1414::DEVICE_580A: return "DEVICE_580A";
        case PciDevice1414::DEVICE_580B: return "DEVICE_580B";
        case PciDevice1414::DEVICE_580D: return "DEVICE_580D";
        case PciDevice1414::DEVICE_5811: return "DEVICE_5811";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1414 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1414 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1414::DEVICE_0001: return "MN-120 (ADMtek Centaur-C based)";
        case PciDevice1414::DEVICE_0002: return "MN-130 (ADMtek Centaur-P based)";
        case PciDevice1414::DEVICE_008C: return "Basic Render Driver";
        case PciDevice1414::DEVICE_5353: return "Hyper-V virtual VGA";
        case PciDevice1414::DEVICE_5801: return "XMA Decoder (Xenon)";
        case PciDevice1414::DEVICE_5802: return "SATA Controller - CdRom (Xenon)";
        case PciDevice1414::DEVICE_5803: return "SATA Controller - Disk (Xenon)";
        case PciDevice1414::DEVICE_5804: return "OHCI Controller 0 (Xenon)";
        case PciDevice1414::DEVICE_5805: return "EHCI Controller 0 (Xenon)";
        case PciDevice1414::DEVICE_5806: return "OHCI Controller 1 (Xenon)";
        case PciDevice1414::DEVICE_5807: return "EHCI Controller 1 (Xenon)";
        case PciDevice1414::DEVICE_580A: return "Fast Ethernet Adapter (Xenon)";
        case PciDevice1414::DEVICE_580B: return "Secure Flash Controller (Xenon)";
        case PciDevice1414::DEVICE_580D: return "System Management Controller (Xenon)";
        case PciDevice1414::DEVICE_5811: return "Xenos GPU (Xenon)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1414_PCIDEVICE1414_H
