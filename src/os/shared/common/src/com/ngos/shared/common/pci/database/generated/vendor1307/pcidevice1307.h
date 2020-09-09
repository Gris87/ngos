// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1307_PCIDEVICE1307_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1307_PCIDEVICE1307_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1307: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_000B = 0x000B,
    DEVICE_000C = 0x000C,
    DEVICE_000D = 0x000D,
    DEVICE_000F = 0x000F,
    DEVICE_0010 = 0x0010,
    DEVICE_0014 = 0x0014,
    DEVICE_0015 = 0x0015,
    DEVICE_0016 = 0x0016,
    DEVICE_0017 = 0x0017,
    DEVICE_0018 = 0x0018,
    DEVICE_0019 = 0x0019,
    DEVICE_001A = 0x001A,
    DEVICE_001B = 0x001B,
    DEVICE_001C = 0x001C,
    DEVICE_001D = 0x001D,
    DEVICE_001E = 0x001E,
    DEVICE_001F = 0x001F,
    DEVICE_0020 = 0x0020,
    DEVICE_0021 = 0x0021,
    DEVICE_0022 = 0x0022,
    DEVICE_0023 = 0x0023,
    DEVICE_0024 = 0x0024,
    DEVICE_0025 = 0x0025,
    DEVICE_0026 = 0x0026,
    DEVICE_0027 = 0x0027,
    DEVICE_0028 = 0x0028,
    DEVICE_0029 = 0x0029,
    DEVICE_002C = 0x002C,
    DEVICE_0033 = 0x0033,
    DEVICE_0034 = 0x0034,
    DEVICE_0035 = 0x0035,
    DEVICE_0036 = 0x0036,
    DEVICE_0037 = 0x0037,
    DEVICE_004C = 0x004C,
    DEVICE_004D = 0x004D,
    DEVICE_0052 = 0x0052,
    DEVICE_0053 = 0x0053,
    DEVICE_0054 = 0x0054,
    DEVICE_005D = 0x005D,
    DEVICE_005E = 0x005E,
    DEVICE_005F = 0x005F,
    DEVICE_0060 = 0x0060,
    DEVICE_0061 = 0x0061,
    DEVICE_0062 = 0x0062,
    DEVICE_0063 = 0x0063,
    DEVICE_0064 = 0x0064,
    DEVICE_0065 = 0x0065,
    DEVICE_0066 = 0x0066,
    DEVICE_0067 = 0x0067,
    DEVICE_0068 = 0x0068,
    DEVICE_006F = 0x006F,
    DEVICE_0070 = 0x0070,
    DEVICE_0078 = 0x0078,
    DEVICE_0079 = 0x0079,
    DEVICE_0115 = 0x0115
};



inline const char8* enumToString(PciDevice1307 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1307::NONE:        return "NONE";
        case PciDevice1307::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1307::DEVICE_000B: return "DEVICE_000B";
        case PciDevice1307::DEVICE_000C: return "DEVICE_000C";
        case PciDevice1307::DEVICE_000D: return "DEVICE_000D";
        case PciDevice1307::DEVICE_000F: return "DEVICE_000F";
        case PciDevice1307::DEVICE_0010: return "DEVICE_0010";
        case PciDevice1307::DEVICE_0014: return "DEVICE_0014";
        case PciDevice1307::DEVICE_0015: return "DEVICE_0015";
        case PciDevice1307::DEVICE_0016: return "DEVICE_0016";
        case PciDevice1307::DEVICE_0017: return "DEVICE_0017";
        case PciDevice1307::DEVICE_0018: return "DEVICE_0018";
        case PciDevice1307::DEVICE_0019: return "DEVICE_0019";
        case PciDevice1307::DEVICE_001A: return "DEVICE_001A";
        case PciDevice1307::DEVICE_001B: return "DEVICE_001B";
        case PciDevice1307::DEVICE_001C: return "DEVICE_001C";
        case PciDevice1307::DEVICE_001D: return "DEVICE_001D";
        case PciDevice1307::DEVICE_001E: return "DEVICE_001E";
        case PciDevice1307::DEVICE_001F: return "DEVICE_001F";
        case PciDevice1307::DEVICE_0020: return "DEVICE_0020";
        case PciDevice1307::DEVICE_0021: return "DEVICE_0021";
        case PciDevice1307::DEVICE_0022: return "DEVICE_0022";
        case PciDevice1307::DEVICE_0023: return "DEVICE_0023";
        case PciDevice1307::DEVICE_0024: return "DEVICE_0024";
        case PciDevice1307::DEVICE_0025: return "DEVICE_0025";
        case PciDevice1307::DEVICE_0026: return "DEVICE_0026";
        case PciDevice1307::DEVICE_0027: return "DEVICE_0027";
        case PciDevice1307::DEVICE_0028: return "DEVICE_0028";
        case PciDevice1307::DEVICE_0029: return "DEVICE_0029";
        case PciDevice1307::DEVICE_002C: return "DEVICE_002C";
        case PciDevice1307::DEVICE_0033: return "DEVICE_0033";
        case PciDevice1307::DEVICE_0034: return "DEVICE_0034";
        case PciDevice1307::DEVICE_0035: return "DEVICE_0035";
        case PciDevice1307::DEVICE_0036: return "DEVICE_0036";
        case PciDevice1307::DEVICE_0037: return "DEVICE_0037";
        case PciDevice1307::DEVICE_004C: return "DEVICE_004C";
        case PciDevice1307::DEVICE_004D: return "DEVICE_004D";
        case PciDevice1307::DEVICE_0052: return "DEVICE_0052";
        case PciDevice1307::DEVICE_0053: return "DEVICE_0053";
        case PciDevice1307::DEVICE_0054: return "DEVICE_0054";
        case PciDevice1307::DEVICE_005D: return "DEVICE_005D";
        case PciDevice1307::DEVICE_005E: return "DEVICE_005E";
        case PciDevice1307::DEVICE_005F: return "DEVICE_005F";
        case PciDevice1307::DEVICE_0060: return "DEVICE_0060";
        case PciDevice1307::DEVICE_0061: return "DEVICE_0061";
        case PciDevice1307::DEVICE_0062: return "DEVICE_0062";
        case PciDevice1307::DEVICE_0063: return "DEVICE_0063";
        case PciDevice1307::DEVICE_0064: return "DEVICE_0064";
        case PciDevice1307::DEVICE_0065: return "DEVICE_0065";
        case PciDevice1307::DEVICE_0066: return "DEVICE_0066";
        case PciDevice1307::DEVICE_0067: return "DEVICE_0067";
        case PciDevice1307::DEVICE_0068: return "DEVICE_0068";
        case PciDevice1307::DEVICE_006F: return "DEVICE_006F";
        case PciDevice1307::DEVICE_0070: return "DEVICE_0070";
        case PciDevice1307::DEVICE_0078: return "DEVICE_0078";
        case PciDevice1307::DEVICE_0079: return "DEVICE_0079";
        case PciDevice1307::DEVICE_0115: return "DEVICE_0115";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1307 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1307 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1307::DEVICE_0001: return "PCI-DAS1602/16";
        case PciDevice1307::DEVICE_000B: return "PCI-DIO48H";
        case PciDevice1307::DEVICE_000C: return "PCI-PDISO8";
        case PciDevice1307::DEVICE_000D: return "PCI-PDISO16";
        case PciDevice1307::DEVICE_000F: return "PCI-DAS1200";
        case PciDevice1307::DEVICE_0010: return "PCI-DAS1602/12";
        case PciDevice1307::DEVICE_0014: return "PCI-DIO24H";
        case PciDevice1307::DEVICE_0015: return "PCI-DIO24H/CTR3";
        case PciDevice1307::DEVICE_0016: return "PCI-DIO48H/CTR15";
        case PciDevice1307::DEVICE_0017: return "PCI-DIO96H";
        case PciDevice1307::DEVICE_0018: return "PCI-CTR05";
        case PciDevice1307::DEVICE_0019: return "PCI-DAS1200/JR";
        case PciDevice1307::DEVICE_001A: return "PCI-DAS1001";
        case PciDevice1307::DEVICE_001B: return "PCI-DAS1002";
        case PciDevice1307::DEVICE_001C: return "PCI-DAS1602JR/16";
        case PciDevice1307::DEVICE_001D: return "PCI-DAS6402/16";
        case PciDevice1307::DEVICE_001E: return "PCI-DAS6402/12";
        case PciDevice1307::DEVICE_001F: return "PCI-DAS16/M1";
        case PciDevice1307::DEVICE_0020: return "PCI-DDA02/12";
        case PciDevice1307::DEVICE_0021: return "PCI-DDA04/12";
        case PciDevice1307::DEVICE_0022: return "PCI-DDA08/12";
        case PciDevice1307::DEVICE_0023: return "PCI-DDA02/16";
        case PciDevice1307::DEVICE_0024: return "PCI-DDA04/16";
        case PciDevice1307::DEVICE_0025: return "PCI-DDA08/16";
        case PciDevice1307::DEVICE_0026: return "PCI-DAC04/12-HS";
        case PciDevice1307::DEVICE_0027: return "PCI-DAC04/16-HS";
        case PciDevice1307::DEVICE_0028: return "PCI-DIO24";
        case PciDevice1307::DEVICE_0029: return "PCI-DAS08";
        case PciDevice1307::DEVICE_002C: return "PCI-INT32";
        case PciDevice1307::DEVICE_0033: return "PCI-DUAL-AC5";
        case PciDevice1307::DEVICE_0034: return "PCI-DAS-TC";
        case PciDevice1307::DEVICE_0035: return "PCI-DAS64/M1/16";
        case PciDevice1307::DEVICE_0036: return "PCI-DAS64/M2/16";
        case PciDevice1307::DEVICE_0037: return "PCI-DAS64/M3/16";
        case PciDevice1307::DEVICE_004C: return "PCI-DAS1000";
        case PciDevice1307::DEVICE_004D: return "PCI-QUAD04";
        case PciDevice1307::DEVICE_0052: return "PCI-DAS4020/12";
        case PciDevice1307::DEVICE_0053: return "PCIM-DDA06/16";
        case PciDevice1307::DEVICE_0054: return "PCI-DIO96";
        case PciDevice1307::DEVICE_005D: return "PCI-DAS6023";
        case PciDevice1307::DEVICE_005E: return "PCI-DAS6025";
        case PciDevice1307::DEVICE_005F: return "PCI-DAS6030";
        case PciDevice1307::DEVICE_0060: return "PCI-DAS6031";
        case PciDevice1307::DEVICE_0061: return "PCI-DAS6032";
        case PciDevice1307::DEVICE_0062: return "PCI-DAS6033";
        case PciDevice1307::DEVICE_0063: return "PCI-DAS6034";
        case PciDevice1307::DEVICE_0064: return "PCI-DAS6035";
        case PciDevice1307::DEVICE_0065: return "PCI-DAS6040";
        case PciDevice1307::DEVICE_0066: return "PCI-DAS6052";
        case PciDevice1307::DEVICE_0067: return "PCI-DAS6070";
        case PciDevice1307::DEVICE_0068: return "PCI-DAS6071";
        case PciDevice1307::DEVICE_006F: return "PCI-DAS6036";
        case PciDevice1307::DEVICE_0070: return "PCI-DAC6702";
        case PciDevice1307::DEVICE_0078: return "PCI-DAS6013";
        case PciDevice1307::DEVICE_0079: return "PCI-DAS6014";
        case PciDevice1307::DEVICE_0115: return "PCIe-DAS1602/16";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1307_PCIDEVICE1307_H
