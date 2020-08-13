// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR131F_PCIDEVICE131F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR131F_PCIDEVICE131F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice131F: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1000 = 0x1000,
    DEVICE_1001 = 0x1001,
    DEVICE_1002 = 0x1002,
    DEVICE_1010 = 0x1010,
    DEVICE_1011 = 0x1011,
    DEVICE_1012 = 0x1012,
    DEVICE_1020 = 0x1020,
    DEVICE_1021 = 0x1021,
    DEVICE_1030 = 0x1030,
    DEVICE_1031 = 0x1031,
    DEVICE_1032 = 0x1032,
    DEVICE_1034 = 0x1034,
    DEVICE_1035 = 0x1035,
    DEVICE_1036 = 0x1036,
    DEVICE_1050 = 0x1050,
    DEVICE_1051 = 0x1051,
    DEVICE_1052 = 0x1052,
    DEVICE_2000 = 0x2000,
    DEVICE_2001 = 0x2001,
    DEVICE_2002 = 0x2002,
    DEVICE_2010 = 0x2010,
    DEVICE_2011 = 0x2011,
    DEVICE_2012 = 0x2012,
    DEVICE_2020 = 0x2020,
    DEVICE_2021 = 0x2021,
    DEVICE_2030 = 0x2030,
    DEVICE_2031 = 0x2031,
    DEVICE_2032 = 0x2032,
    DEVICE_2040 = 0x2040,
    DEVICE_2041 = 0x2041,
    DEVICE_2042 = 0x2042,
    DEVICE_2050 = 0x2050,
    DEVICE_2051 = 0x2051,
    DEVICE_2052 = 0x2052,
    DEVICE_2060 = 0x2060,
    DEVICE_2061 = 0x2061,
    DEVICE_2062 = 0x2062,
    DEVICE_2081 = 0x2081
};



inline const char8* enumToString(PciDevice131F device131F) // TEST: NO
{
    // COMMON_LT((" | device131F = %u", device131F)); // Commented to avoid bad looking logs



    switch (device131F)
    {
        case PciDevice131F::NONE:        return "NONE";
        case PciDevice131F::DEVICE_1000: return "DEVICE_1000";
        case PciDevice131F::DEVICE_1001: return "DEVICE_1001";
        case PciDevice131F::DEVICE_1002: return "DEVICE_1002";
        case PciDevice131F::DEVICE_1010: return "DEVICE_1010";
        case PciDevice131F::DEVICE_1011: return "DEVICE_1011";
        case PciDevice131F::DEVICE_1012: return "DEVICE_1012";
        case PciDevice131F::DEVICE_1020: return "DEVICE_1020";
        case PciDevice131F::DEVICE_1021: return "DEVICE_1021";
        case PciDevice131F::DEVICE_1030: return "DEVICE_1030";
        case PciDevice131F::DEVICE_1031: return "DEVICE_1031";
        case PciDevice131F::DEVICE_1032: return "DEVICE_1032";
        case PciDevice131F::DEVICE_1034: return "DEVICE_1034";
        case PciDevice131F::DEVICE_1035: return "DEVICE_1035";
        case PciDevice131F::DEVICE_1036: return "DEVICE_1036";
        case PciDevice131F::DEVICE_1050: return "DEVICE_1050";
        case PciDevice131F::DEVICE_1051: return "DEVICE_1051";
        case PciDevice131F::DEVICE_1052: return "DEVICE_1052";
        case PciDevice131F::DEVICE_2000: return "DEVICE_2000";
        case PciDevice131F::DEVICE_2001: return "DEVICE_2001";
        case PciDevice131F::DEVICE_2002: return "DEVICE_2002";
        case PciDevice131F::DEVICE_2010: return "DEVICE_2010";
        case PciDevice131F::DEVICE_2011: return "DEVICE_2011";
        case PciDevice131F::DEVICE_2012: return "DEVICE_2012";
        case PciDevice131F::DEVICE_2020: return "DEVICE_2020";
        case PciDevice131F::DEVICE_2021: return "DEVICE_2021";
        case PciDevice131F::DEVICE_2030: return "DEVICE_2030";
        case PciDevice131F::DEVICE_2031: return "DEVICE_2031";
        case PciDevice131F::DEVICE_2032: return "DEVICE_2032";
        case PciDevice131F::DEVICE_2040: return "DEVICE_2040";
        case PciDevice131F::DEVICE_2041: return "DEVICE_2041";
        case PciDevice131F::DEVICE_2042: return "DEVICE_2042";
        case PciDevice131F::DEVICE_2050: return "DEVICE_2050";
        case PciDevice131F::DEVICE_2051: return "DEVICE_2051";
        case PciDevice131F::DEVICE_2052: return "DEVICE_2052";
        case PciDevice131F::DEVICE_2060: return "DEVICE_2060";
        case PciDevice131F::DEVICE_2061: return "DEVICE_2061";
        case PciDevice131F::DEVICE_2062: return "DEVICE_2062";
        case PciDevice131F::DEVICE_2081: return "DEVICE_2081";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice131F device131F) // TEST: NO
{
    // COMMON_LT((" | device131F = %u", device131F)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device131F, enumToString(device131F));

    return res;
}



inline const char8* enumToHumanString(PciDevice131F device131F) // TEST: NO
{
    // COMMON_LT((" | device131F = %u", device131F)); // Commented to avoid bad looking logs



    switch (device131F)
    {
        case PciDevice131F::DEVICE_1000: return "CyberSerial (1-port) 16550";
        case PciDevice131F::DEVICE_1001: return "CyberSerial (1-port) 16650";
        case PciDevice131F::DEVICE_1002: return "CyberSerial (1-port) 16850";
        case PciDevice131F::DEVICE_1010: return "Duet 1S(16550)+1P";
        case PciDevice131F::DEVICE_1011: return "Duet 1S(16650)+1P";
        case PciDevice131F::DEVICE_1012: return "Duet 1S(16850)+1P";
        case PciDevice131F::DEVICE_1020: return "CyberParallel (1-port)";
        case PciDevice131F::DEVICE_1021: return "CyberParallel (2-port)";
        case PciDevice131F::DEVICE_1030: return "CyberSerial (2-port) 16550";
        case PciDevice131F::DEVICE_1031: return "CyberSerial (2-port) 16650";
        case PciDevice131F::DEVICE_1032: return "CyberSerial (2-port) 16850";
        case PciDevice131F::DEVICE_1034: return "Trio 2S(16550)+1P";
        case PciDevice131F::DEVICE_1035: return "Trio 2S(16650)+1P";
        case PciDevice131F::DEVICE_1036: return "Trio 2S(16850)+1P";
        case PciDevice131F::DEVICE_1050: return "CyberSerial (4-port) 16550";
        case PciDevice131F::DEVICE_1051: return "CyberSerial (4-port) 16650";
        case PciDevice131F::DEVICE_1052: return "CyberSerial (4-port) 16850";
        case PciDevice131F::DEVICE_2000: return "CyberSerial (1-port) 16550";
        case PciDevice131F::DEVICE_2001: return "CyberSerial (1-port) 16650";
        case PciDevice131F::DEVICE_2002: return "CyberSerial (1-port) 16850";
        case PciDevice131F::DEVICE_2010: return "Duet 1S(16550)+1P";
        case PciDevice131F::DEVICE_2011: return "Duet 1S(16650)+1P";
        case PciDevice131F::DEVICE_2012: return "Duet 1S(16850)+1P";
        case PciDevice131F::DEVICE_2020: return "CyberParallel (1-port)";
        case PciDevice131F::DEVICE_2021: return "CyberParallel (2-port)";
        case PciDevice131F::DEVICE_2030: return "CyberSerial (2-port) 16550";
        case PciDevice131F::DEVICE_2031: return "CyberSerial (2-port) 16650";
        case PciDevice131F::DEVICE_2032: return "CyberSerial (2-port) 16850";
        case PciDevice131F::DEVICE_2040: return "Trio 1S(16550)+2P";
        case PciDevice131F::DEVICE_2041: return "Trio 1S(16650)+2P";
        case PciDevice131F::DEVICE_2042: return "Trio 1S(16850)+2P";
        case PciDevice131F::DEVICE_2050: return "CyberSerial (4-port) 16550";
        case PciDevice131F::DEVICE_2051: return "CyberSerial (4-port) 16650";
        case PciDevice131F::DEVICE_2052: return "CyberSerial (4-port) 16850";
        case PciDevice131F::DEVICE_2060: return "Trio 2S(16550)+1P";
        case PciDevice131F::DEVICE_2061: return "Trio 2S(16650)+1P";
        case PciDevice131F::DEVICE_2062: return "Trio 2S(16850)+1P";
        case PciDevice131F::DEVICE_2081: return "CyberSerial (8-port) ST16654";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR131F_PCIDEVICE131F_H
