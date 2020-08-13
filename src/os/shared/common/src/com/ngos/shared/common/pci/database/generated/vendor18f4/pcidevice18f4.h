// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18F4_PCIDEVICE18F4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18F4_PCIDEVICE18F4_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice18F4: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0031 = 0x0031,
    DEVICE_0051 = 0x0051,
    DEVICE_0061 = 0x0061,
    DEVICE_0064 = 0x0064,
    DEVICE_0071 = 0x0071,
    DEVICE_0074 = 0x0074,
    DEVICE_0081 = 0x0081,
    DEVICE_0091 = 0x0091,
    DEVICE_00A1 = 0x00A1,
    DEVICE_00A4 = 0x00A4,
    DEVICE_00B1 = 0x00B1,
    DEVICE_00C5 = 0x00C5,
    DEVICE_00D5 = 0x00D5,
    DEVICE_00E5 = 0x00E5,
    DEVICE_00F5 = 0x00F5,
    DEVICE_0105 = 0x0105,
    DEVICE_0115 = 0x0115,
    DEVICE_0125 = 0x0125,
    DEVICE_0135 = 0x0135,
    DEVICE_0145 = 0x0145,
    DEVICE_0155 = 0x0155,
    DEVICE_0165 = 0x0165,
    DEVICE_0175 = 0x0175,
    DEVICE_0185 = 0x0185,
    DEVICE_01A5 = 0x01A5,
    DEVICE_01C5 = 0x01C5
};



inline const char8* enumToString(PciDevice18F4 device18F4) // TEST: NO
{
    // COMMON_LT((" | device18F4 = %u", device18F4)); // Commented to avoid bad looking logs



    switch (device18F4)
    {
        case PciDevice18F4::NONE:        return "NONE";
        case PciDevice18F4::DEVICE_0031: return "DEVICE_0031";
        case PciDevice18F4::DEVICE_0051: return "DEVICE_0051";
        case PciDevice18F4::DEVICE_0061: return "DEVICE_0061";
        case PciDevice18F4::DEVICE_0064: return "DEVICE_0064";
        case PciDevice18F4::DEVICE_0071: return "DEVICE_0071";
        case PciDevice18F4::DEVICE_0074: return "DEVICE_0074";
        case PciDevice18F4::DEVICE_0081: return "DEVICE_0081";
        case PciDevice18F4::DEVICE_0091: return "DEVICE_0091";
        case PciDevice18F4::DEVICE_00A1: return "DEVICE_00A1";
        case PciDevice18F4::DEVICE_00A4: return "DEVICE_00A4";
        case PciDevice18F4::DEVICE_00B1: return "DEVICE_00B1";
        case PciDevice18F4::DEVICE_00C5: return "DEVICE_00C5";
        case PciDevice18F4::DEVICE_00D5: return "DEVICE_00D5";
        case PciDevice18F4::DEVICE_00E5: return "DEVICE_00E5";
        case PciDevice18F4::DEVICE_00F5: return "DEVICE_00F5";
        case PciDevice18F4::DEVICE_0105: return "DEVICE_0105";
        case PciDevice18F4::DEVICE_0115: return "DEVICE_0115";
        case PciDevice18F4::DEVICE_0125: return "DEVICE_0125";
        case PciDevice18F4::DEVICE_0135: return "DEVICE_0135";
        case PciDevice18F4::DEVICE_0145: return "DEVICE_0145";
        case PciDevice18F4::DEVICE_0155: return "DEVICE_0155";
        case PciDevice18F4::DEVICE_0165: return "DEVICE_0165";
        case PciDevice18F4::DEVICE_0175: return "DEVICE_0175";
        case PciDevice18F4::DEVICE_0185: return "DEVICE_0185";
        case PciDevice18F4::DEVICE_01A5: return "DEVICE_01A5";
        case PciDevice18F4::DEVICE_01C5: return "DEVICE_01C5";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice18F4 device18F4) // TEST: NO
{
    // COMMON_LT((" | device18F4 = %u", device18F4)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device18F4, enumToString(device18F4));

    return res;
}



inline const char8* enumToHumanString(PciDevice18F4 device18F4) // TEST: NO
{
    // COMMON_LT((" | device18F4 = %u", device18F4)); // Commented to avoid bad looking logs



    switch (device18F4)
    {
        case PciDevice18F4::DEVICE_0031: return "NT20X Network Adapter";
        case PciDevice18F4::DEVICE_0051: return "NT20X Capture Card";
        case PciDevice18F4::DEVICE_0061: return "NT20E Capture Card";
        case PciDevice18F4::DEVICE_0064: return "NT20E Inline Card";
        case PciDevice18F4::DEVICE_0071: return "NT4E Capture Card";
        case PciDevice18F4::DEVICE_0074: return "NT4E Inline Card";
        case PciDevice18F4::DEVICE_0081: return "NT4E 4-port Expansion Card";
        case PciDevice18F4::DEVICE_0091: return "NT20X Capture Card [New Rev]";
        case PciDevice18F4::DEVICE_00A1: return "NT4E-STD Capture Card";
        case PciDevice18F4::DEVICE_00A4: return "NT4E-STD Inline Card";
        case PciDevice18F4::DEVICE_00B1: return "NTBPE Optical Bypass Adapter";
        case PciDevice18F4::DEVICE_00C5: return "NT20E2 Network Adapter 2x10Gb";
        case PciDevice18F4::DEVICE_00D5: return "NT40E2-4 Network Adapter 4x10Gb";
        case PciDevice18F4::DEVICE_00E5: return "NT40E2-1 Network Adapter 1x40Gb";
        case PciDevice18F4::DEVICE_00F5: return "NT4E2-4T-BP Network Adapter 4x1Gb with Electrical Bypass";
        case PciDevice18F4::DEVICE_0105: return "NT4E2-4-PTP Network Adapter 4x1Gb";
        case PciDevice18F4::DEVICE_0115: return "NT20E2-PTP Network Adapter 2x10Gb";
        case PciDevice18F4::DEVICE_0125: return "NT4E2-4-PTP Network Adapter 4x1Gb";
        case PciDevice18F4::DEVICE_0135: return "NT20E2-PTP Network Adapter 2x10Gb";
        case PciDevice18F4::DEVICE_0145: return "NT40E3-4-PTP Network Adapter 4x10Gb";
        case PciDevice18F4::DEVICE_0155: return "NT100E3-1-PTP Network Adapter 1x100Gb";
        case PciDevice18F4::DEVICE_0165: return "NT80E3-2-PTP Network Adapter 2x40Gb";
        case PciDevice18F4::DEVICE_0175: return "NT20E3-2-PTP Network Adapter 2x10Gb";
        case PciDevice18F4::DEVICE_0185: return "NT40A01 Network Adapter";
        case PciDevice18F4::DEVICE_01A5: return "NT200A01 Network Adapter";
        case PciDevice18F4::DEVICE_01C5: return "NT200A02 Network Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18F4_PCIDEVICE18F4_H
