// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B6_PCIDEVICE15B6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B6_PCIDEVICE15B6_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice15B6: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0007 = 0x0007,
    DEVICE_0008 = 0x0008,
    DEVICE_0009 = 0x0009,
    DEVICE_000A = 0x000A,
    DEVICE_000E = 0x000E,
    DEVICE_000F = 0x000F,
    DEVICE_0010 = 0x0010,
    DEVICE_0011 = 0x0011,
    DEVICE_0012 = 0x0012,
    DEVICE_0013 = 0x0013,
    DEVICE_0014 = 0x0014,
    DEVICE_0015 = 0x0015
};



inline const char8* enumToString(PciDevice15B6 device15B6) // TEST: NO
{
    // COMMON_LT((" | device15B6 = %u", device15B6)); // Commented to avoid bad looking logs



    switch (device15B6)
    {
        case PciDevice15B6::NONE:        return "NONE";
        case PciDevice15B6::DEVICE_0001: return "DEVICE_0001";
        case PciDevice15B6::DEVICE_0002: return "DEVICE_0002";
        case PciDevice15B6::DEVICE_0003: return "DEVICE_0003";
        case PciDevice15B6::DEVICE_0004: return "DEVICE_0004";
        case PciDevice15B6::DEVICE_0007: return "DEVICE_0007";
        case PciDevice15B6::DEVICE_0008: return "DEVICE_0008";
        case PciDevice15B6::DEVICE_0009: return "DEVICE_0009";
        case PciDevice15B6::DEVICE_000A: return "DEVICE_000A";
        case PciDevice15B6::DEVICE_000E: return "DEVICE_000E";
        case PciDevice15B6::DEVICE_000F: return "DEVICE_000F";
        case PciDevice15B6::DEVICE_0010: return "DEVICE_0010";
        case PciDevice15B6::DEVICE_0011: return "DEVICE_0011";
        case PciDevice15B6::DEVICE_0012: return "DEVICE_0012";
        case PciDevice15B6::DEVICE_0013: return "DEVICE_0013";
        case PciDevice15B6::DEVICE_0014: return "DEVICE_0014";
        case PciDevice15B6::DEVICE_0015: return "DEVICE_0015";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice15B6 device15B6) // TEST: NO
{
    // COMMON_LT((" | device15B6 = %u", device15B6)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device15B6, enumToString(device15B6));

    return res;
}



inline const char8* enumToHumanString(PciDevice15B6 device15B6) // TEST: NO
{
    // COMMON_LT((" | device15B6 = %u", device15B6)); // Commented to avoid bad looking logs



    switch (device15B6)
    {
        case PciDevice15B6::DEVICE_0001: return "XP15 DSP Accelerator";
        case PciDevice15B6::DEVICE_0002: return "XP30 DSP Accelerator";
        case PciDevice15B6::DEVICE_0003: return "XP00 Data Acquisition Device";
        case PciDevice15B6::DEVICE_0004: return "XP35 DSP Accelerator";
        case PciDevice15B6::DEVICE_0007: return "XP100 DSP Accelerator [XP100-T0]";
        case PciDevice15B6::DEVICE_0008: return "XP100 DSP Accelerator [XP100-T1]";
        case PciDevice15B6::DEVICE_0009: return "XP100 DSP Accelerator [XP100-E0]";
        case PciDevice15B6::DEVICE_000A: return "XP100 DSP Accelerator [XP100-E1]";
        case PciDevice15B6::DEVICE_000E: return "XP100 DSP Accelerator [XP100-0]";
        case PciDevice15B6::DEVICE_000F: return "XP100 DSP Accelerator [XP100-1]";
        case PciDevice15B6::DEVICE_0010: return "XP100 DSP Accelerator [XP100-P0]";
        case PciDevice15B6::DEVICE_0011: return "XP100 DSP Accelerator [XP100-P1]";
        case PciDevice15B6::DEVICE_0012: return "XP100 DSP Accelerator [XP100-P2]";
        case PciDevice15B6::DEVICE_0013: return "XP100 DSP Accelerator [XP100-P3]";
        case PciDevice15B6::DEVICE_0014: return "RamSan Flash SSD";
        case PciDevice15B6::DEVICE_0015: return "ZBox";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15B6_PCIDEVICE15B6_H
