// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17F3_PCIDEVICE17F3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17F3_PCIDEVICE17F3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice17F3: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1010 = 0x1010,
    DEVICE_1011 = 0x1011,
    DEVICE_1012 = 0x1012,
    DEVICE_1031 = 0x1031,
    DEVICE_1070 = 0x1070,
    DEVICE_1331 = 0x1331,
    DEVICE_1930 = 0x1930,
    DEVICE_2010 = 0x2010,
    DEVICE_2012 = 0x2012,
    DEVICE_2015 = 0x2015,
    DEVICE_6011 = 0x6011,
    DEVICE_6013 = 0x6013,
    DEVICE_6020 = 0x6020,
    DEVICE_6021 = 0x6021,
    DEVICE_6023 = 0x6023,
    DEVICE_6025 = 0x6025,
    DEVICE_6026 = 0x6026,
    DEVICE_6030 = 0x6030,
    DEVICE_6031 = 0x6031,
    DEVICE_6035 = 0x6035,
    DEVICE_6036 = 0x6036,
    DEVICE_6040 = 0x6040,
    DEVICE_6060 = 0x6060,
    DEVICE_6061 = 0x6061
};



inline const char8* enumToString(PciDevice17F3 device17F3) // TEST: NO
{
    // COMMON_LT((" | device17F3 = %u", device17F3)); // Commented to avoid bad looking logs



    switch (device17F3)
    {
        case PciDevice17F3::NONE:        return "NONE";
        case PciDevice17F3::DEVICE_1010: return "DEVICE_1010";
        case PciDevice17F3::DEVICE_1011: return "DEVICE_1011";
        case PciDevice17F3::DEVICE_1012: return "DEVICE_1012";
        case PciDevice17F3::DEVICE_1031: return "DEVICE_1031";
        case PciDevice17F3::DEVICE_1070: return "DEVICE_1070";
        case PciDevice17F3::DEVICE_1331: return "DEVICE_1331";
        case PciDevice17F3::DEVICE_1930: return "DEVICE_1930";
        case PciDevice17F3::DEVICE_2010: return "DEVICE_2010";
        case PciDevice17F3::DEVICE_2012: return "DEVICE_2012";
        case PciDevice17F3::DEVICE_2015: return "DEVICE_2015";
        case PciDevice17F3::DEVICE_6011: return "DEVICE_6011";
        case PciDevice17F3::DEVICE_6013: return "DEVICE_6013";
        case PciDevice17F3::DEVICE_6020: return "DEVICE_6020";
        case PciDevice17F3::DEVICE_6021: return "DEVICE_6021";
        case PciDevice17F3::DEVICE_6023: return "DEVICE_6023";
        case PciDevice17F3::DEVICE_6025: return "DEVICE_6025";
        case PciDevice17F3::DEVICE_6026: return "DEVICE_6026";
        case PciDevice17F3::DEVICE_6030: return "DEVICE_6030";
        case PciDevice17F3::DEVICE_6031: return "DEVICE_6031";
        case PciDevice17F3::DEVICE_6035: return "DEVICE_6035";
        case PciDevice17F3::DEVICE_6036: return "DEVICE_6036";
        case PciDevice17F3::DEVICE_6040: return "DEVICE_6040";
        case PciDevice17F3::DEVICE_6060: return "DEVICE_6060";
        case PciDevice17F3::DEVICE_6061: return "DEVICE_6061";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice17F3 device17F3) // TEST: NO
{
    // COMMON_LT((" | device17F3 = %u", device17F3)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device17F3, enumToString(device17F3));

    return res;
}



inline const char8* enumToHumanString(PciDevice17F3 device17F3) // TEST: NO
{
    // COMMON_LT((" | device17F3 = %u", device17F3)); // Commented to avoid bad looking logs



    switch (device17F3)
    {
        case PciDevice17F3::DEVICE_1010: return "R1010 IDE Controller";
        case PciDevice17F3::DEVICE_1011: return "R1011 IDE Controller";
        case PciDevice17F3::DEVICE_1012: return "R1012 IDE Controller";
        case PciDevice17F3::DEVICE_1031: return "PCI/PCI-X to PCI-E Bridge";
        case PciDevice17F3::DEVICE_1070: return "CAN Bus Controller";
        case PciDevice17F3::DEVICE_1331: return "Motion Control Interface";
        case PciDevice17F3::DEVICE_1930: return "Hybrid Function Control Register";
        case PciDevice17F3::DEVICE_2010: return "RDC M2010 VGA-compatible graphics adapter";
        case PciDevice17F3::DEVICE_2012: return "M2012/R3308 VGA-compatible graphics adapter";
        case PciDevice17F3::DEVICE_2015: return "RDC M2015 VGA-compatible graphics adapter";
        case PciDevice17F3::DEVICE_6011: return "R6011 ISA Bridge";
        case PciDevice17F3::DEVICE_6013: return "R6013 ISA Bridge";
        case PciDevice17F3::DEVICE_6020: return "R6020 North Bridge";
        case PciDevice17F3::DEVICE_6021: return "R6021 Host Bridge";
        case PciDevice17F3::DEVICE_6023: return "R6023 Host Bridge";
        case PciDevice17F3::DEVICE_6025: return "R6025 Host Bridge";
        case PciDevice17F3::DEVICE_6026: return "R6026 Host Bridge";
        case PciDevice17F3::DEVICE_6030: return "R6030 ISA Bridge";
        case PciDevice17F3::DEVICE_6031: return "R6031 ISA Bridge";
        case PciDevice17F3::DEVICE_6035: return "R6035 ISA Bridge";
        case PciDevice17F3::DEVICE_6036: return "R6036 ISA Bridge";
        case PciDevice17F3::DEVICE_6040: return "R6040 MAC Controller";
        case PciDevice17F3::DEVICE_6060: return "R6060 USB 1.1 Controller";
        case PciDevice17F3::DEVICE_6061: return "R6061 USB 2.0 Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17F3_PCIDEVICE17F3_H
