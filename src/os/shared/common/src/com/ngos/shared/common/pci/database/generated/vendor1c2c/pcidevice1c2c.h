// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C2C_PCIDEVICE1C2C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C2C_PCIDEVICE1C2C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1C2C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_000A = 0x000A,
    DEVICE_000F = 0x000F,
    DEVICE_00A0 = 0x00A0,
    DEVICE_00A1 = 0x00A1,
    DEVICE_00A2 = 0x00A2,
    DEVICE_00A3 = 0x00A3,
    DEVICE_00A4 = 0x00A4,
    DEVICE_00A5 = 0x00A5,
    DEVICE_00A6 = 0x00A6,
    DEVICE_00A9 = 0x00A9,
    DEVICE_00AD = 0x00AD,
    DEVICE_00AF = 0x00AF,
    DEVICE_00E0 = 0x00E0,
    DEVICE_00E1 = 0x00E1,
    DEVICE_00E3 = 0x00E3,
    DEVICE_00E5 = 0x00E5,
    DEVICE_A000 = 0xA000,
    DEVICE_A001 = 0xA001,
    DEVICE_A003 = 0xA003,
    DEVICE_A007 = 0xA007,
    DEVICE_A008 = 0xA008,
    DEVICE_A009 = 0xA009,
    DEVICE_A00A = 0xA00A,
    DEVICE_A00E = 0xA00E,
    DEVICE_A00F = 0xA00F,
    DEVICE_A010 = 0xA010,
    DEVICE_A011 = 0xA011,
    DEVICE_A012 = 0xA012,
    DEVICE_A013 = 0xA013,
    DEVICE_A014 = 0xA014,
    DEVICE_A015 = 0xA015
};



inline const char8* enumToString(PciDevice1C2C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1C2C::NONE:        return "NONE";
        case PciDevice1C2C::DEVICE_000A: return "DEVICE_000A";
        case PciDevice1C2C::DEVICE_000F: return "DEVICE_000F";
        case PciDevice1C2C::DEVICE_00A0: return "DEVICE_00A0";
        case PciDevice1C2C::DEVICE_00A1: return "DEVICE_00A1";
        case PciDevice1C2C::DEVICE_00A2: return "DEVICE_00A2";
        case PciDevice1C2C::DEVICE_00A3: return "DEVICE_00A3";
        case PciDevice1C2C::DEVICE_00A4: return "DEVICE_00A4";
        case PciDevice1C2C::DEVICE_00A5: return "DEVICE_00A5";
        case PciDevice1C2C::DEVICE_00A6: return "DEVICE_00A6";
        case PciDevice1C2C::DEVICE_00A9: return "DEVICE_00A9";
        case PciDevice1C2C::DEVICE_00AD: return "DEVICE_00AD";
        case PciDevice1C2C::DEVICE_00AF: return "DEVICE_00AF";
        case PciDevice1C2C::DEVICE_00E0: return "DEVICE_00E0";
        case PciDevice1C2C::DEVICE_00E1: return "DEVICE_00E1";
        case PciDevice1C2C::DEVICE_00E3: return "DEVICE_00E3";
        case PciDevice1C2C::DEVICE_00E5: return "DEVICE_00E5";
        case PciDevice1C2C::DEVICE_A000: return "DEVICE_A000";
        case PciDevice1C2C::DEVICE_A001: return "DEVICE_A001";
        case PciDevice1C2C::DEVICE_A003: return "DEVICE_A003";
        case PciDevice1C2C::DEVICE_A007: return "DEVICE_A007";
        case PciDevice1C2C::DEVICE_A008: return "DEVICE_A008";
        case PciDevice1C2C::DEVICE_A009: return "DEVICE_A009";
        case PciDevice1C2C::DEVICE_A00A: return "DEVICE_A00A";
        case PciDevice1C2C::DEVICE_A00E: return "DEVICE_A00E";
        case PciDevice1C2C::DEVICE_A00F: return "DEVICE_A00F";
        case PciDevice1C2C::DEVICE_A010: return "DEVICE_A010";
        case PciDevice1C2C::DEVICE_A011: return "DEVICE_A011";
        case PciDevice1C2C::DEVICE_A012: return "DEVICE_A012";
        case PciDevice1C2C::DEVICE_A013: return "DEVICE_A013";
        case PciDevice1C2C::DEVICE_A014: return "DEVICE_A014";
        case PciDevice1C2C::DEVICE_A015: return "DEVICE_A015";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1C2C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1C2C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1C2C::DEVICE_000A: return "Capture";
        case PciDevice1C2C::DEVICE_000F: return "SmartNIC";
        case PciDevice1C2C::DEVICE_00A0: return "FBC4G Capture 4x1Gb [Herculaneum]";
        case PciDevice1C2C::DEVICE_00A1: return "FBC4XG Capture 4x10Gb [Ancona]";
        case PciDevice1C2C::DEVICE_00A2: return "FBC8XG Capture 8x10Gb [Livorno]";
        case PciDevice1C2C::DEVICE_00A3: return "FBC2XG Capture 2x10Gb [Genoa]";
        case PciDevice1C2C::DEVICE_00A4: return "FBC4XGG3 Capture 4x10Gb [Livigno]";
        case PciDevice1C2C::DEVICE_00A5: return "FBC2XLG Capture 2x40Gb [Livorno]";
        case PciDevice1C2C::DEVICE_00A6: return "FBC1CG Capture 1x100Gb";
        case PciDevice1C2C::DEVICE_00A9: return "FBC2XGHH Capture 2x10Gb [Latina]";
        case PciDevice1C2C::DEVICE_00AD: return "FBC2CGG3HL Capture 2x100Gb [Padua]";
        case PciDevice1C2C::DEVICE_00AF: return "Capture slave device";
        case PciDevice1C2C::DEVICE_00E0: return "PacketMover 2x100Gb [Savona]";
        case PciDevice1C2C::DEVICE_00E1: return "PacketMover 2x100Gb [Tivoli]";
        case PciDevice1C2C::DEVICE_00E3: return "PacketMover 2x10Gb [Tivoli]";
        case PciDevice1C2C::DEVICE_00E5: return "PacketMover 2x10Gb [Corfu]";
        case PciDevice1C2C::DEVICE_A000: return "FBC2CGG3 Capture 2x40Gb [Mango_02]";
        case PciDevice1C2C::DEVICE_A001: return "FBC2CGG3 Capture 2x100Gb [Mango_02]";
        case PciDevice1C2C::DEVICE_A003: return "FBC2CGG3 Capture 16x10Gb [Mango]";
        case PciDevice1C2C::DEVICE_A007: return "FBC2CGG3 Capture 2x40Gb [Mango]";
        case PciDevice1C2C::DEVICE_A008: return "FBC2CGG3 Capture 2x25Gb [Mango]";
        case PciDevice1C2C::DEVICE_A009: return "FBC2CGG3 Capture 16x10Gb [Mango]";
        case PciDevice1C2C::DEVICE_A00A: return "FBC2CGG3 Capture 8x10Gb [Mango]";
        case PciDevice1C2C::DEVICE_A00E: return "FB2CG Capture 2x100Gb [Savona]";
        case PciDevice1C2C::DEVICE_A00F: return "FB2CG Capture 2x40Gb [Savona]";
        case PciDevice1C2C::DEVICE_A010: return "FB2CGHH Capture 2x40Gb [Tivoli]";
        case PciDevice1C2C::DEVICE_A011: return "FB2CG Capture 2x25Gb [Savona]";
        case PciDevice1C2C::DEVICE_A012: return "FB2CG Capture 8x10Gb [Savona]";
        case PciDevice1C2C::DEVICE_A013: return "FB2CGHH Capture 2x25Gb [Tivoli]";
        case PciDevice1C2C::DEVICE_A014: return "FB2CGHH Capture 8x10Gb [Tivoli]";
        case PciDevice1C2C::DEVICE_A015: return "FB2CGHH Capture 2x100Gb [Tivoli]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C2C_PCIDEVICE1C2C_H
