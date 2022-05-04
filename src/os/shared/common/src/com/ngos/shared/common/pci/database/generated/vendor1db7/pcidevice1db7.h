// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DB7_PCIDEVICE1DB7_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DB7_PCIDEVICE1DB7_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1DB7: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_DC20 = 0xDC20,
    DEVICE_DC21 = 0xDC21,
    DEVICE_DC22 = 0xDC22,
    DEVICE_DC23 = 0xDC23,
    DEVICE_DC26 = 0xDC26,
    DEVICE_DC27 = 0xDC27,
    DEVICE_DC29 = 0xDC29,
    DEVICE_DC2B = 0xDC2B,
    DEVICE_DC2C = 0xDC2C,
    DEVICE_DC2D = 0xDC2D,
    DEVICE_DC2E = 0xDC2E,
    DEVICE_DC2F = 0xDC2F,
    DEVICE_DC30 = 0xDC30,
    DEVICE_DC31 = 0xDC31,
    DEVICE_DC32 = 0xDC32,
    DEVICE_DC34 = 0xDC34,
    DEVICE_DC35 = 0xDC35,
    DEVICE_DC36 = 0xDC36,
    DEVICE_DC38 = 0xDC38,
    DEVICE_DC3A = 0xDC3A,
    DEVICE_DC3C = 0xDC3C
};



inline const char8* enumToString(PciDevice1DB7 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1DB7::NONE:        return "NONE";
        case PciDevice1DB7::DEVICE_DC20: return "DEVICE_DC20";
        case PciDevice1DB7::DEVICE_DC21: return "DEVICE_DC21";
        case PciDevice1DB7::DEVICE_DC22: return "DEVICE_DC22";
        case PciDevice1DB7::DEVICE_DC23: return "DEVICE_DC23";
        case PciDevice1DB7::DEVICE_DC26: return "DEVICE_DC26";
        case PciDevice1DB7::DEVICE_DC27: return "DEVICE_DC27";
        case PciDevice1DB7::DEVICE_DC29: return "DEVICE_DC29";
        case PciDevice1DB7::DEVICE_DC2B: return "DEVICE_DC2B";
        case PciDevice1DB7::DEVICE_DC2C: return "DEVICE_DC2C";
        case PciDevice1DB7::DEVICE_DC2D: return "DEVICE_DC2D";
        case PciDevice1DB7::DEVICE_DC2E: return "DEVICE_DC2E";
        case PciDevice1DB7::DEVICE_DC2F: return "DEVICE_DC2F";
        case PciDevice1DB7::DEVICE_DC30: return "DEVICE_DC30";
        case PciDevice1DB7::DEVICE_DC31: return "DEVICE_DC31";
        case PciDevice1DB7::DEVICE_DC32: return "DEVICE_DC32";
        case PciDevice1DB7::DEVICE_DC34: return "DEVICE_DC34";
        case PciDevice1DB7::DEVICE_DC35: return "DEVICE_DC35";
        case PciDevice1DB7::DEVICE_DC36: return "DEVICE_DC36";
        case PciDevice1DB7::DEVICE_DC38: return "DEVICE_DC38";
        case PciDevice1DB7::DEVICE_DC3A: return "DEVICE_DC3A";
        case PciDevice1DB7::DEVICE_DC3C: return "DEVICE_DC3C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1DB7 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1DB7 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1DB7::DEVICE_DC20: return "[X100 Series]";
        case PciDevice1DB7::DEVICE_DC21: return "VPU Controller [X100 Series]";
        case PciDevice1DB7::DEVICE_DC22: return "DC Controller [X100 Series]";
        case PciDevice1DB7::DEVICE_DC23: return "I2S/DMA Controller [X100 Series]";
        case PciDevice1DB7::DEVICE_DC26: return "SATA Controller [X100 Series]";
        case PciDevice1DB7::DEVICE_DC27: return "USB Controller [X100 Series]";
        case PciDevice1DB7::DEVICE_DC29: return "NANDFLASH Controller [X100 Series]";
        case PciDevice1DB7::DEVICE_DC2B: return "I2S Controller [X100 Series]";
        case PciDevice1DB7::DEVICE_DC2C: return "SPIM Controller [X100 Series]";
        case PciDevice1DB7::DEVICE_DC2D: return "CAN Controller [X100 Series]";
        case PciDevice1DB7::DEVICE_DC2E: return "UART Controller [X100 Series]";
        case PciDevice1DB7::DEVICE_DC2F: return "PWM Controller [X100 Series]";
        case PciDevice1DB7::DEVICE_DC30: return "MIO Controller [X100 Series]";
        case PciDevice1DB7::DEVICE_DC31: return "GPIO Controller [X100 Series]";
        case PciDevice1DB7::DEVICE_DC32: return "SMBUS Controller [X100 Series]";
        case PciDevice1DB7::DEVICE_DC34: return "PS2 Controller [X100 Series]";
        case PciDevice1DB7::DEVICE_DC35: return "LPC Controller [X100 Series]";
        case PciDevice1DB7::DEVICE_DC36: return "LDMA Controller [X100 Series]";
        case PciDevice1DB7::DEVICE_DC38: return "LSD_CFG Controller [X100 Series]";
        case PciDevice1DB7::DEVICE_DC3A: return "SWITCH Controller [X100 Series]";
        case PciDevice1DB7::DEVICE_DC3C: return "GPU_DMA Controller [X100 Series]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DB7_PCIDEVICE1DB7_H
