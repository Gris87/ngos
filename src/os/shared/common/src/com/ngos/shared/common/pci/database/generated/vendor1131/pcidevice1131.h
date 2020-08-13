// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCIDEVICE1131_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCIDEVICE1131_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1131: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1561 = 0x1561,
    DEVICE_1562 = 0x1562,
    DEVICE_3400 = 0x3400,
    DEVICE_5400 = 0x5400,
    DEVICE_5402 = 0x5402,
    DEVICE_5405 = 0x5405,
    DEVICE_5406 = 0x5406,
    DEVICE_540B = 0x540B,
    DEVICE_7130 = 0x7130,
    DEVICE_7133 = 0x7133,
    DEVICE_7134 = 0x7134,
    DEVICE_7145 = 0x7145,
    DEVICE_7146 = 0x7146,
    DEVICE_7160 = 0x7160,
    DEVICE_7162 = 0x7162,
    DEVICE_7164 = 0x7164,
    DEVICE_7231 = 0x7231,
    DEVICE_9730 = 0x9730
};



inline const char8* enumToString(PciDevice1131 device1131) // TEST: NO
{
    // COMMON_LT((" | device1131 = %u", device1131)); // Commented to avoid bad looking logs



    switch (device1131)
    {
        case PciDevice1131::NONE:        return "NONE";
        case PciDevice1131::DEVICE_1561: return "DEVICE_1561";
        case PciDevice1131::DEVICE_1562: return "DEVICE_1562";
        case PciDevice1131::DEVICE_3400: return "DEVICE_3400";
        case PciDevice1131::DEVICE_5400: return "DEVICE_5400";
        case PciDevice1131::DEVICE_5402: return "DEVICE_5402";
        case PciDevice1131::DEVICE_5405: return "DEVICE_5405";
        case PciDevice1131::DEVICE_5406: return "DEVICE_5406";
        case PciDevice1131::DEVICE_540B: return "DEVICE_540B";
        case PciDevice1131::DEVICE_7130: return "DEVICE_7130";
        case PciDevice1131::DEVICE_7133: return "DEVICE_7133";
        case PciDevice1131::DEVICE_7134: return "DEVICE_7134";
        case PciDevice1131::DEVICE_7145: return "DEVICE_7145";
        case PciDevice1131::DEVICE_7146: return "DEVICE_7146";
        case PciDevice1131::DEVICE_7160: return "DEVICE_7160";
        case PciDevice1131::DEVICE_7162: return "DEVICE_7162";
        case PciDevice1131::DEVICE_7164: return "DEVICE_7164";
        case PciDevice1131::DEVICE_7231: return "DEVICE_7231";
        case PciDevice1131::DEVICE_9730: return "DEVICE_9730";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1131 device1131) // TEST: NO
{
    // COMMON_LT((" | device1131 = %u", device1131)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1131, enumToString(device1131));

    return res;
}



inline const char8* enumToHumanString(PciDevice1131 device1131) // TEST: NO
{
    // COMMON_LT((" | device1131 = %u", device1131)); // Commented to avoid bad looking logs



    switch (device1131)
    {
        case PciDevice1131::DEVICE_1561: return "USB 1.1 Host Controller";
        case PciDevice1131::DEVICE_1562: return "USB 2.0 Host Controller";
        case PciDevice1131::DEVICE_3400: return "SmartPCI56(UCB1500) 56K Modem";
        case PciDevice1131::DEVICE_5400: return "TriMedia TM1000/1100";
        case PciDevice1131::DEVICE_5402: return "TriMedia TM1300";
        case PciDevice1131::DEVICE_5405: return "TriMedia TM1500";
        case PciDevice1131::DEVICE_5406: return "TriMedia TM1700";
        case PciDevice1131::DEVICE_540B: return "PNX1005 Media Processor";
        case PciDevice1131::DEVICE_7130: return "SAA7130 Video Broadcast Decoder";
        case PciDevice1131::DEVICE_7133: return "SAA7131/SAA7133/SAA7135 Video Broadcast Decoder";
        case PciDevice1131::DEVICE_7134: return "SAA7134/SAA7135HL Video Broadcast Decoder";
        case PciDevice1131::DEVICE_7145: return "SAA7145";
        case PciDevice1131::DEVICE_7146: return "SAA7146";
        case PciDevice1131::DEVICE_7160: return "SAA7160";
        case PciDevice1131::DEVICE_7162: return "SAA7162";
        case PciDevice1131::DEVICE_7164: return "SAA7164";
        case PciDevice1131::DEVICE_7231: return "SAA7231";
        case PciDevice1131::DEVICE_9730: return "SAA9730 Integrated Multimedia and Peripheral Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCIDEVICE1131_H
