// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1542_PCIDEVICE1542_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1542_PCIDEVICE1542_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1542: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_9260 = 0x9260,
    DEVICE_9271 = 0x9271,
    DEVICE_9272 = 0x9272,
    DEVICE_9277 = 0x9277,
    DEVICE_9278 = 0x9278,
    DEVICE_9287 = 0x9287,
    DEVICE_9290 = 0x9290,
    DEVICE_9300 = 0x9300,
    DEVICE_9310 = 0x9310,
    DEVICE_9350 = 0x9350
};



inline const char8* enumToString(PciDevice1542 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1542::NONE:        return "NONE";
        case PciDevice1542::DEVICE_9260: return "DEVICE_9260";
        case PciDevice1542::DEVICE_9271: return "DEVICE_9271";
        case PciDevice1542::DEVICE_9272: return "DEVICE_9272";
        case PciDevice1542::DEVICE_9277: return "DEVICE_9277";
        case PciDevice1542::DEVICE_9278: return "DEVICE_9278";
        case PciDevice1542::DEVICE_9287: return "DEVICE_9287";
        case PciDevice1542::DEVICE_9290: return "DEVICE_9290";
        case PciDevice1542::DEVICE_9300: return "DEVICE_9300";
        case PciDevice1542::DEVICE_9310: return "DEVICE_9310";
        case PciDevice1542::DEVICE_9350: return "DEVICE_9350";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1542 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1542 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1542::DEVICE_9260: return "RCIM-II Real-Time Clock & Interrupt Module";
        case PciDevice1542::DEVICE_9271: return "RCIM-III Real-Time Clock & Interrupt Module (PCIe)";
        case PciDevice1542::DEVICE_9272: return "Pulse Width Modulator Card";
        case PciDevice1542::DEVICE_9277: return "5 Volt Delta Sigma Converter Card";
        case PciDevice1542::DEVICE_9278: return "10 Volt Delta Sigma Converter Card";
        case PciDevice1542::DEVICE_9287: return "Analog Output Card";
        case PciDevice1542::DEVICE_9290: return "FPGA Card";
        case PciDevice1542::DEVICE_9300: return "Universal Exhaust Gas Oxygen Sensor Simulator";
        case PciDevice1542::DEVICE_9310: return "Digital Programmable Resistor";
        case PciDevice1542::DEVICE_9350: return "Analog Input Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1542_PCIDEVICE1542_H
