// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR177D_PCISUBDEVICE177D9702_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR177D_PCISUBDEVICE177D9702_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice177D9702: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_177D0003 = 0x177D0003,
    SUBDEVICE_177D0004 = 0x177D0004,
    SUBDEVICE_177D0005 = 0x177D0005,
    SUBDEVICE_177D0006 = 0x177D0006,
    SUBDEVICE_177D0007 = 0x177D0007,
    SUBDEVICE_177D0008 = 0x177D0008,
    SUBDEVICE_177D0009 = 0x177D0009,
    SUBDEVICE_177D000A = 0x177D000A,
    SUBDEVICE_177D000B = 0x177D000B
};



inline const char8* enumToString(PciSubDevice177D9702 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice177D9702::NONE:               return "NONE";
        case PciSubDevice177D9702::SUBDEVICE_177D0003: return "SUBDEVICE_177D0003";
        case PciSubDevice177D9702::SUBDEVICE_177D0004: return "SUBDEVICE_177D0004";
        case PciSubDevice177D9702::SUBDEVICE_177D0005: return "SUBDEVICE_177D0005";
        case PciSubDevice177D9702::SUBDEVICE_177D0006: return "SUBDEVICE_177D0006";
        case PciSubDevice177D9702::SUBDEVICE_177D0007: return "SUBDEVICE_177D0007";
        case PciSubDevice177D9702::SUBDEVICE_177D0008: return "SUBDEVICE_177D0008";
        case PciSubDevice177D9702::SUBDEVICE_177D0009: return "SUBDEVICE_177D0009";
        case PciSubDevice177D9702::SUBDEVICE_177D000A: return "SUBDEVICE_177D000A";
        case PciSubDevice177D9702::SUBDEVICE_177D000B: return "SUBDEVICE_177D000B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice177D9702 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice177D9702 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice177D9702::SUBDEVICE_177D0003: return "CN2350 [LiquidIO II] 2-port 10GbE Intelligent adapter";
        case PciSubDevice177D9702::SUBDEVICE_177D0004: return "CN2350 [LiquidIO II] 2-port 10GbE Intelligent adapter";
        case PciSubDevice177D9702::SUBDEVICE_177D0005: return "CN2360 [LiquidIO II] 2-port 10GbE Intelligent adapter";
        case PciSubDevice177D9702::SUBDEVICE_177D0006: return "CN2360 [LiquidIO II] 2-port 25GbE Intelligent adapter";
        case PciSubDevice177D9702::SUBDEVICE_177D0007: return "CN2350 [LiquidIO II] 2-port 25GbE Intelligent adapter";
        case PciSubDevice177D9702::SUBDEVICE_177D0008: return "CN2350 [LiquidIO II] 2-port 10GbE SFP+ Intelligent adapter";
        case PciSubDevice177D9702::SUBDEVICE_177D0009: return "CN2360 [LiquidIO II] 2-port 10GbE SFP+ Intelligent adapter";
        case PciSubDevice177D9702::SUBDEVICE_177D000A: return "CN2350 [LiquidIO II] 2-port 10GBASE-T Intelligent adapter";
        case PciSubDevice177D9702::SUBDEVICE_177D000B: return "CN2360 [LiquidIO II] 2-port 10GBASE-T Intelligent adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR177D_PCISUBDEVICE177D9702_H
