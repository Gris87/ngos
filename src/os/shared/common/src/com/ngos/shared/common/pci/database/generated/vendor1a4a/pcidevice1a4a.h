// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A4A_PCIDEVICE1A4A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A4A_PCIDEVICE1A4A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1A4A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1000 = 0x1000,
    DEVICE_1010 = 0x1010,
    DEVICE_1020 = 0x1020,
    DEVICE_2000 = 0x2000,
    DEVICE_2001 = 0x2001,
    DEVICE_2010 = 0x2010,
    DEVICE_2020 = 0x2020,
    DEVICE_2030 = 0x2030
};



inline const char8* enumToString(PciDevice1A4A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1A4A::NONE:        return "NONE";
        case PciDevice1A4A::DEVICE_1000: return "DEVICE_1000";
        case PciDevice1A4A::DEVICE_1010: return "DEVICE_1010";
        case PciDevice1A4A::DEVICE_1020: return "DEVICE_1020";
        case PciDevice1A4A::DEVICE_2000: return "DEVICE_2000";
        case PciDevice1A4A::DEVICE_2001: return "DEVICE_2001";
        case PciDevice1A4A::DEVICE_2010: return "DEVICE_2010";
        case PciDevice1A4A::DEVICE_2020: return "DEVICE_2020";
        case PciDevice1A4A::DEVICE_2030: return "DEVICE_2030";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1A4A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1A4A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1A4A::DEVICE_1000: return "MCOR Power Supply Controller";
        case PciDevice1A4A::DEVICE_1010: return "AMC EVR - Stockholm Timing Board";
        case PciDevice1A4A::DEVICE_1020: return "Cluster On Board (COB) Ethernet Switch";
        case PciDevice1A4A::DEVICE_2000: return "PGPCard - 4 Lane";
        case PciDevice1A4A::DEVICE_2001: return "PGPCard - 8 Lane Plus EVR";
        case PciDevice1A4A::DEVICE_2010: return "PCI-Express EVR";
        case PciDevice1A4A::DEVICE_2020: return "PGP-GEN3 PCIe";
        case PciDevice1A4A::DEVICE_2030: return "AXI Stream DAQ PCIe card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A4A_PCIDEVICE1A4A_H
