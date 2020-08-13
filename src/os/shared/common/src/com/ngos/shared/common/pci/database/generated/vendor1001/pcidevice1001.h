// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1001_PCIDEVICE1001_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1001_PCIDEVICE1001_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1001: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0010 = 0x0010,
    DEVICE_0011 = 0x0011,
    DEVICE_0012 = 0x0012,
    DEVICE_0013 = 0x0013,
    DEVICE_0014 = 0x0014,
    DEVICE_0015 = 0x0015,
    DEVICE_0016 = 0x0016,
    DEVICE_0017 = 0x0017,
    DEVICE_9100 = 0x9100
};



inline const char8* enumToString(PciDevice1001 device1001) // TEST: NO
{
    // COMMON_LT((" | device1001 = %u", device1001)); // Commented to avoid bad looking logs



    switch (device1001)
    {
        case PciDevice1001::NONE:        return "NONE";
        case PciDevice1001::DEVICE_0010: return "DEVICE_0010";
        case PciDevice1001::DEVICE_0011: return "DEVICE_0011";
        case PciDevice1001::DEVICE_0012: return "DEVICE_0012";
        case PciDevice1001::DEVICE_0013: return "DEVICE_0013";
        case PciDevice1001::DEVICE_0014: return "DEVICE_0014";
        case PciDevice1001::DEVICE_0015: return "DEVICE_0015";
        case PciDevice1001::DEVICE_0016: return "DEVICE_0016";
        case PciDevice1001::DEVICE_0017: return "DEVICE_0017";
        case PciDevice1001::DEVICE_9100: return "DEVICE_9100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1001 device1001) // TEST: NO
{
    // COMMON_LT((" | device1001 = %u", device1001)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1001, enumToString(device1001));

    return res;
}



inline const char8* enumToHumanString(PciDevice1001 device1001) // TEST: NO
{
    // COMMON_LT((" | device1001 = %u", device1001)); // Commented to avoid bad looking logs



    switch (device1001)
    {
        case PciDevice1001::DEVICE_0010: return "PCI 1616 Measurement card with 32 digital I/O lines";
        case PciDevice1001::DEVICE_0011: return "OPTO-PCI Opto-Isolated digital I/O board";
        case PciDevice1001::DEVICE_0012: return "PCI-AD/DA Analogue I/O board";
        case PciDevice1001::DEVICE_0013: return "PCI-OPTO-RELAIS Digital I/O board with relay outputs";
        case PciDevice1001::DEVICE_0014: return "PCI-Counter/Timer Counter Timer board";
        case PciDevice1001::DEVICE_0015: return "PCI-DAC416 Analogue output board";
        case PciDevice1001::DEVICE_0016: return "PCI-MFB Analogue I/O board";
        case PciDevice1001::DEVICE_0017: return "PROTO-3 PCI Prototyping board";
        case PciDevice1001::DEVICE_9100: return "INI-9100/9100W SCSI Host";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1001_PCIDEVICE1001_H
