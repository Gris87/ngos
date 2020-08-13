// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCIDEVICE5333_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCIDEVICE5333_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice5333: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0551 = 0x0551,
    DEVICE_5631 = 0x5631,
    DEVICE_8800 = 0x8800,
    DEVICE_8801 = 0x8801,
    DEVICE_8810 = 0x8810,
    DEVICE_8811 = 0x8811,
    DEVICE_8812 = 0x8812,
    DEVICE_8813 = 0x8813,
    DEVICE_8814 = 0x8814,
    DEVICE_8815 = 0x8815,
    DEVICE_883D = 0x883D,
    DEVICE_8870 = 0x8870,
    DEVICE_8880 = 0x8880,
    DEVICE_8881 = 0x8881,
    DEVICE_8882 = 0x8882,
    DEVICE_8883 = 0x8883,
    DEVICE_88B0 = 0x88B0,
    DEVICE_88B1 = 0x88B1,
    DEVICE_88B2 = 0x88B2,
    DEVICE_88B3 = 0x88B3,
    DEVICE_88C0 = 0x88C0,
    DEVICE_88C1 = 0x88C1,
    DEVICE_88C2 = 0x88C2,
    DEVICE_88C3 = 0x88C3,
    DEVICE_88D0 = 0x88D0,
    DEVICE_88D1 = 0x88D1,
    DEVICE_88D2 = 0x88D2,
    DEVICE_88D3 = 0x88D3,
    DEVICE_88F0 = 0x88F0,
    DEVICE_88F1 = 0x88F1,
    DEVICE_88F2 = 0x88F2,
    DEVICE_88F3 = 0x88F3,
    DEVICE_8900 = 0x8900,
    DEVICE_8901 = 0x8901,
    DEVICE_8902 = 0x8902,
    DEVICE_8903 = 0x8903,
    DEVICE_8904 = 0x8904,
    DEVICE_8905 = 0x8905,
    DEVICE_8906 = 0x8906,
    DEVICE_8907 = 0x8907,
    DEVICE_8908 = 0x8908,
    DEVICE_8909 = 0x8909,
    DEVICE_890A = 0x890A,
    DEVICE_890B = 0x890B,
    DEVICE_890C = 0x890C,
    DEVICE_890D = 0x890D,
    DEVICE_890E = 0x890E,
    DEVICE_890F = 0x890F,
    DEVICE_8A01 = 0x8A01,
    DEVICE_8A10 = 0x8A10,
    DEVICE_8A13 = 0x8A13,
    DEVICE_8A20 = 0x8A20,
    DEVICE_8A21 = 0x8A21,
    DEVICE_8A22 = 0x8A22,
    DEVICE_8A23 = 0x8A23,
    DEVICE_8A25 = 0x8A25,
    DEVICE_8A26 = 0x8A26,
    DEVICE_8C00 = 0x8C00,
    DEVICE_8C01 = 0x8C01,
    DEVICE_8C02 = 0x8C02,
    DEVICE_8C03 = 0x8C03,
    DEVICE_8C10 = 0x8C10,
    DEVICE_8C11 = 0x8C11,
    DEVICE_8C12 = 0x8C12,
    DEVICE_8C13 = 0x8C13,
    DEVICE_8C22 = 0x8C22,
    DEVICE_8C24 = 0x8C24,
    DEVICE_8C26 = 0x8C26,
    DEVICE_8C2A = 0x8C2A,
    DEVICE_8C2B = 0x8C2B,
    DEVICE_8C2C = 0x8C2C,
    DEVICE_8C2D = 0x8C2D,
    DEVICE_8C2E = 0x8C2E,
    DEVICE_8C2F = 0x8C2F,
    DEVICE_8D01 = 0x8D01,
    DEVICE_8D02 = 0x8D02,
    DEVICE_8D03 = 0x8D03,
    DEVICE_8D04 = 0x8D04,
    DEVICE_8E00 = 0x8E00,
    DEVICE_8E26 = 0x8E26,
    DEVICE_8E40 = 0x8E40,
    DEVICE_8E48 = 0x8E48,
    DEVICE_9043 = 0x9043,
    DEVICE_9045 = 0x9045,
    DEVICE_9060 = 0x9060,
    DEVICE_9102 = 0x9102,
    DEVICE_CA00 = 0xCA00
};



inline const char8* enumToString(PciDevice5333 device5333) // TEST: NO
{
    // COMMON_LT((" | device5333 = %u", device5333)); // Commented to avoid bad looking logs



    switch (device5333)
    {
        case PciDevice5333::NONE:        return "NONE";
        case PciDevice5333::DEVICE_0551: return "DEVICE_0551";
        case PciDevice5333::DEVICE_5631: return "DEVICE_5631";
        case PciDevice5333::DEVICE_8800: return "DEVICE_8800";
        case PciDevice5333::DEVICE_8801: return "DEVICE_8801";
        case PciDevice5333::DEVICE_8810: return "DEVICE_8810";
        case PciDevice5333::DEVICE_8811: return "DEVICE_8811";
        case PciDevice5333::DEVICE_8812: return "DEVICE_8812";
        case PciDevice5333::DEVICE_8813: return "DEVICE_8813";
        case PciDevice5333::DEVICE_8814: return "DEVICE_8814";
        case PciDevice5333::DEVICE_8815: return "DEVICE_8815";
        case PciDevice5333::DEVICE_883D: return "DEVICE_883D";
        case PciDevice5333::DEVICE_8870: return "DEVICE_8870";
        case PciDevice5333::DEVICE_8880: return "DEVICE_8880";
        case PciDevice5333::DEVICE_8881: return "DEVICE_8881";
        case PciDevice5333::DEVICE_8882: return "DEVICE_8882";
        case PciDevice5333::DEVICE_8883: return "DEVICE_8883";
        case PciDevice5333::DEVICE_88B0: return "DEVICE_88B0";
        case PciDevice5333::DEVICE_88B1: return "DEVICE_88B1";
        case PciDevice5333::DEVICE_88B2: return "DEVICE_88B2";
        case PciDevice5333::DEVICE_88B3: return "DEVICE_88B3";
        case PciDevice5333::DEVICE_88C0: return "DEVICE_88C0";
        case PciDevice5333::DEVICE_88C1: return "DEVICE_88C1";
        case PciDevice5333::DEVICE_88C2: return "DEVICE_88C2";
        case PciDevice5333::DEVICE_88C3: return "DEVICE_88C3";
        case PciDevice5333::DEVICE_88D0: return "DEVICE_88D0";
        case PciDevice5333::DEVICE_88D1: return "DEVICE_88D1";
        case PciDevice5333::DEVICE_88D2: return "DEVICE_88D2";
        case PciDevice5333::DEVICE_88D3: return "DEVICE_88D3";
        case PciDevice5333::DEVICE_88F0: return "DEVICE_88F0";
        case PciDevice5333::DEVICE_88F1: return "DEVICE_88F1";
        case PciDevice5333::DEVICE_88F2: return "DEVICE_88F2";
        case PciDevice5333::DEVICE_88F3: return "DEVICE_88F3";
        case PciDevice5333::DEVICE_8900: return "DEVICE_8900";
        case PciDevice5333::DEVICE_8901: return "DEVICE_8901";
        case PciDevice5333::DEVICE_8902: return "DEVICE_8902";
        case PciDevice5333::DEVICE_8903: return "DEVICE_8903";
        case PciDevice5333::DEVICE_8904: return "DEVICE_8904";
        case PciDevice5333::DEVICE_8905: return "DEVICE_8905";
        case PciDevice5333::DEVICE_8906: return "DEVICE_8906";
        case PciDevice5333::DEVICE_8907: return "DEVICE_8907";
        case PciDevice5333::DEVICE_8908: return "DEVICE_8908";
        case PciDevice5333::DEVICE_8909: return "DEVICE_8909";
        case PciDevice5333::DEVICE_890A: return "DEVICE_890A";
        case PciDevice5333::DEVICE_890B: return "DEVICE_890B";
        case PciDevice5333::DEVICE_890C: return "DEVICE_890C";
        case PciDevice5333::DEVICE_890D: return "DEVICE_890D";
        case PciDevice5333::DEVICE_890E: return "DEVICE_890E";
        case PciDevice5333::DEVICE_890F: return "DEVICE_890F";
        case PciDevice5333::DEVICE_8A01: return "DEVICE_8A01";
        case PciDevice5333::DEVICE_8A10: return "DEVICE_8A10";
        case PciDevice5333::DEVICE_8A13: return "DEVICE_8A13";
        case PciDevice5333::DEVICE_8A20: return "DEVICE_8A20";
        case PciDevice5333::DEVICE_8A21: return "DEVICE_8A21";
        case PciDevice5333::DEVICE_8A22: return "DEVICE_8A22";
        case PciDevice5333::DEVICE_8A23: return "DEVICE_8A23";
        case PciDevice5333::DEVICE_8A25: return "DEVICE_8A25";
        case PciDevice5333::DEVICE_8A26: return "DEVICE_8A26";
        case PciDevice5333::DEVICE_8C00: return "DEVICE_8C00";
        case PciDevice5333::DEVICE_8C01: return "DEVICE_8C01";
        case PciDevice5333::DEVICE_8C02: return "DEVICE_8C02";
        case PciDevice5333::DEVICE_8C03: return "DEVICE_8C03";
        case PciDevice5333::DEVICE_8C10: return "DEVICE_8C10";
        case PciDevice5333::DEVICE_8C11: return "DEVICE_8C11";
        case PciDevice5333::DEVICE_8C12: return "DEVICE_8C12";
        case PciDevice5333::DEVICE_8C13: return "DEVICE_8C13";
        case PciDevice5333::DEVICE_8C22: return "DEVICE_8C22";
        case PciDevice5333::DEVICE_8C24: return "DEVICE_8C24";
        case PciDevice5333::DEVICE_8C26: return "DEVICE_8C26";
        case PciDevice5333::DEVICE_8C2A: return "DEVICE_8C2A";
        case PciDevice5333::DEVICE_8C2B: return "DEVICE_8C2B";
        case PciDevice5333::DEVICE_8C2C: return "DEVICE_8C2C";
        case PciDevice5333::DEVICE_8C2D: return "DEVICE_8C2D";
        case PciDevice5333::DEVICE_8C2E: return "DEVICE_8C2E";
        case PciDevice5333::DEVICE_8C2F: return "DEVICE_8C2F";
        case PciDevice5333::DEVICE_8D01: return "DEVICE_8D01";
        case PciDevice5333::DEVICE_8D02: return "DEVICE_8D02";
        case PciDevice5333::DEVICE_8D03: return "DEVICE_8D03";
        case PciDevice5333::DEVICE_8D04: return "DEVICE_8D04";
        case PciDevice5333::DEVICE_8E00: return "DEVICE_8E00";
        case PciDevice5333::DEVICE_8E26: return "DEVICE_8E26";
        case PciDevice5333::DEVICE_8E40: return "DEVICE_8E40";
        case PciDevice5333::DEVICE_8E48: return "DEVICE_8E48";
        case PciDevice5333::DEVICE_9043: return "DEVICE_9043";
        case PciDevice5333::DEVICE_9045: return "DEVICE_9045";
        case PciDevice5333::DEVICE_9060: return "DEVICE_9060";
        case PciDevice5333::DEVICE_9102: return "DEVICE_9102";
        case PciDevice5333::DEVICE_CA00: return "DEVICE_CA00";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice5333 device5333) // TEST: NO
{
    // COMMON_LT((" | device5333 = %u", device5333)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device5333, enumToString(device5333));

    return res;
}



inline const char8* enumToHumanString(PciDevice5333 device5333) // TEST: NO
{
    // COMMON_LT((" | device5333 = %u", device5333)); // Commented to avoid bad looking logs



    switch (device5333)
    {
        case PciDevice5333::DEVICE_0551: return "Plato/PX (system)";
        case PciDevice5333::DEVICE_5631: return "86c325 [ViRGE]";
        case PciDevice5333::DEVICE_8800: return "86c866 [Vision 866]";
        case PciDevice5333::DEVICE_8801: return "86c964 [Vision 964]";
        case PciDevice5333::DEVICE_8810: return "86c764_0 [Trio 32 vers 0]";
        case PciDevice5333::DEVICE_8811: return "86c764/765 [Trio32/64/64V+]";
        case PciDevice5333::DEVICE_8812: return "86cM65 [Aurora64V+]";
        case PciDevice5333::DEVICE_8813: return "86c764_3 [Trio 32/64 vers 3]";
        case PciDevice5333::DEVICE_8814: return "86c767 [Trio 64UV+]";
        case PciDevice5333::DEVICE_8815: return "86cM65 [Aurora 128]";
        case PciDevice5333::DEVICE_883D: return "86c988 [ViRGE/VX]";
        case PciDevice5333::DEVICE_8870: return "FireGL";
        case PciDevice5333::DEVICE_8880: return "86c868 [Vision 868 VRAM] vers 0";
        case PciDevice5333::DEVICE_8881: return "86c868 [Vision 868 VRAM] vers 1";
        case PciDevice5333::DEVICE_8882: return "86c868 [Vision 868 VRAM] vers 2";
        case PciDevice5333::DEVICE_8883: return "86c868 [Vision 868 VRAM] vers 3";
        case PciDevice5333::DEVICE_88B0: return "86c928 [Vision 928 VRAM] vers 0";
        case PciDevice5333::DEVICE_88B1: return "86c928 [Vision 928 VRAM] vers 1";
        case PciDevice5333::DEVICE_88B2: return "86c928 [Vision 928 VRAM] vers 2";
        case PciDevice5333::DEVICE_88B3: return "86c928 [Vision 928 VRAM] vers 3";
        case PciDevice5333::DEVICE_88C0: return "86c864 [Vision 864 DRAM] vers 0";
        case PciDevice5333::DEVICE_88C1: return "86c864 [Vision 864 DRAM] vers 1";
        case PciDevice5333::DEVICE_88C2: return "86c864 [Vision 864-P DRAM] vers 2";
        case PciDevice5333::DEVICE_88C3: return "86c864 [Vision 864-P DRAM] vers 3";
        case PciDevice5333::DEVICE_88D0: return "86c964 [Vision 964 VRAM] vers 0";
        case PciDevice5333::DEVICE_88D1: return "86c964 [Vision 964 VRAM] vers 1";
        case PciDevice5333::DEVICE_88D2: return "86c964 [Vision 964-P VRAM] vers 2";
        case PciDevice5333::DEVICE_88D3: return "86c964 [Vision 964-P VRAM] vers 3";
        case PciDevice5333::DEVICE_88F0: return "86c968 [Vision 968 VRAM] rev 0";
        case PciDevice5333::DEVICE_88F1: return "86c968 [Vision 968 VRAM] rev 1";
        case PciDevice5333::DEVICE_88F2: return "86c968 [Vision 968 VRAM] rev 2";
        case PciDevice5333::DEVICE_88F3: return "86c968 [Vision 968 VRAM] rev 3";
        case PciDevice5333::DEVICE_8900: return "86c755 [Trio 64V2/DX]";
        case PciDevice5333::DEVICE_8901: return "86c775/86c785 [Trio 64V2/DX or /GX]";
        case PciDevice5333::DEVICE_8902: return "Plato/PX";
        case PciDevice5333::DEVICE_8903: return "Trio 3D business multimedia";
        case PciDevice5333::DEVICE_8904: return "86c365, 86c366 [Trio 3D]";
        case PciDevice5333::DEVICE_8905: return "Trio 64V+ family";
        case PciDevice5333::DEVICE_8906: return "Trio 64V+ family";
        case PciDevice5333::DEVICE_8907: return "Trio 64V+ family";
        case PciDevice5333::DEVICE_8908: return "Trio 64V+ family";
        case PciDevice5333::DEVICE_8909: return "Trio 64V+ family";
        case PciDevice5333::DEVICE_890A: return "Trio 64V+ family";
        case PciDevice5333::DEVICE_890B: return "Trio 64V+ family";
        case PciDevice5333::DEVICE_890C: return "Trio 64V+ family";
        case PciDevice5333::DEVICE_890D: return "Trio 64V+ family";
        case PciDevice5333::DEVICE_890E: return "Trio 64V+ family";
        case PciDevice5333::DEVICE_890F: return "Trio 64V+ family";
        case PciDevice5333::DEVICE_8A01: return "86c375 [ViRGE/DX] or 86c385 [ViRGE/GX]";
        case PciDevice5333::DEVICE_8A10: return "ViRGE/GX2";
        case PciDevice5333::DEVICE_8A13: return "86c360 [Trio 3D/1X], 86c362, 86c368 [Trio 3D/2X]";
        case PciDevice5333::DEVICE_8A20: return "86c794 [Savage 3D]";
        case PciDevice5333::DEVICE_8A21: return "86c390 [Savage 3D/MV]";
        case PciDevice5333::DEVICE_8A22: return "Savage 4";
        case PciDevice5333::DEVICE_8A23: return "Savage 4";
        case PciDevice5333::DEVICE_8A25: return "ProSavage PM133";
        case PciDevice5333::DEVICE_8A26: return "ProSavage KM133";
        case PciDevice5333::DEVICE_8C00: return "ViRGE/M3";
        case PciDevice5333::DEVICE_8C01: return "ViRGE/MX";
        case PciDevice5333::DEVICE_8C02: return "ViRGE/MX+";
        case PciDevice5333::DEVICE_8C03: return "ViRGE/MX+MV";
        case PciDevice5333::DEVICE_8C10: return "86C270-294 [SavageMX-MV]";
        case PciDevice5333::DEVICE_8C11: return "82C270-294 [SavageMX]";
        case PciDevice5333::DEVICE_8C12: return "86C270-294 [SavageIX-MV]";
        case PciDevice5333::DEVICE_8C13: return "86C270-294 [SavageIX]";
        case PciDevice5333::DEVICE_8C22: return "SuperSavage MX/128";
        case PciDevice5333::DEVICE_8C24: return "SuperSavage MX/64";
        case PciDevice5333::DEVICE_8C26: return "SuperSavage MX/64C";
        case PciDevice5333::DEVICE_8C2A: return "SuperSavage IX/128 SDR";
        case PciDevice5333::DEVICE_8C2B: return "SuperSavage IX/128 DDR";
        case PciDevice5333::DEVICE_8C2C: return "SuperSavage IX/64 SDR";
        case PciDevice5333::DEVICE_8C2D: return "SuperSavage IX/64 DDR";
        case PciDevice5333::DEVICE_8C2E: return "SuperSavage IX/C SDR";
        case PciDevice5333::DEVICE_8C2F: return "SuperSavage IX/C DDR";
        case PciDevice5333::DEVICE_8D01: return "86C380 [ProSavageDDR K4M266]";
        case PciDevice5333::DEVICE_8D02: return "VT8636A [ProSavage KN133] AGP4X VGA Controller (TwisterK)";
        case PciDevice5333::DEVICE_8D03: return "VT8751 [ProSavageDDR P4M266]";
        case PciDevice5333::DEVICE_8D04: return "VT8375 [ProSavage8 KM266/KL266]";
        case PciDevice5333::DEVICE_8E00: return "DeltaChrome";
        case PciDevice5333::DEVICE_8E26: return "ProSavage";
        case PciDevice5333::DEVICE_8E40: return "2300E Graphics Processor";
        case PciDevice5333::DEVICE_8E48: return "Matrix [Chrome S25 / S27]";
        case PciDevice5333::DEVICE_9043: return "Chrome 430 GT";
        case PciDevice5333::DEVICE_9045: return "Chrome 430 ULP / 435 ULP / 440 GTX";
        case PciDevice5333::DEVICE_9060: return "Chrome 530 GT";
        case PciDevice5333::DEVICE_9102: return "86C410 [Savage 2000]";
        case PciDevice5333::DEVICE_CA00: return "SonicVibes";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCIDEVICE5333_H
