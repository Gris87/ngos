// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41645_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41645_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E41645: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11007C = 0x0E11007C,
    SUBDEVICE_0E11007D = 0x0E11007D,
    SUBDEVICE_0E110085 = 0x0E110085,
    SUBDEVICE_0E110099 = 0x0E110099,
    SUBDEVICE_0E11009A = 0x0E11009A,
    SUBDEVICE_0E1100C1 = 0x0E1100C1,
    SUBDEVICE_10280121 = 0x10280121,
    SUBDEVICE_103C128A = 0x103C128A,
    SUBDEVICE_103C128B = 0x103C128B,
    SUBDEVICE_103C12A4 = 0x103C12A4,
    SUBDEVICE_103C12C1 = 0x103C12C1,
    SUBDEVICE_103C1300 = 0x103C1300,
    SUBDEVICE_10A98010 = 0x10A98010,
    SUBDEVICE_10A98011 = 0x10A98011,
    SUBDEVICE_10A98012 = 0x10A98012,
    SUBDEVICE_10B71004 = 0x10B71004,
    SUBDEVICE_10B71006 = 0x10B71006,
    SUBDEVICE_10B71007 = 0x10B71007,
    SUBDEVICE_10B71008 = 0x10B71008,
    SUBDEVICE_14E40001 = 0x14E40001,
    SUBDEVICE_14E40005 = 0x14E40005,
    SUBDEVICE_14E40006 = 0x14E40006,
    SUBDEVICE_14E40007 = 0x14E40007,
    SUBDEVICE_14E40008 = 0x14E40008,
    SUBDEVICE_14E41645 = 0x14E41645,
    SUBDEVICE_14E48008 = 0x14E48008
};



inline const char8* enumToString(PciSubDevice14E41645 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41645::NONE:               return "NONE";
        case PciSubDevice14E41645::SUBDEVICE_0E11007C: return "SUBDEVICE_0E11007C";
        case PciSubDevice14E41645::SUBDEVICE_0E11007D: return "SUBDEVICE_0E11007D";
        case PciSubDevice14E41645::SUBDEVICE_0E110085: return "SUBDEVICE_0E110085";
        case PciSubDevice14E41645::SUBDEVICE_0E110099: return "SUBDEVICE_0E110099";
        case PciSubDevice14E41645::SUBDEVICE_0E11009A: return "SUBDEVICE_0E11009A";
        case PciSubDevice14E41645::SUBDEVICE_0E1100C1: return "SUBDEVICE_0E1100C1";
        case PciSubDevice14E41645::SUBDEVICE_10280121: return "SUBDEVICE_10280121";
        case PciSubDevice14E41645::SUBDEVICE_103C128A: return "SUBDEVICE_103C128A";
        case PciSubDevice14E41645::SUBDEVICE_103C128B: return "SUBDEVICE_103C128B";
        case PciSubDevice14E41645::SUBDEVICE_103C12A4: return "SUBDEVICE_103C12A4";
        case PciSubDevice14E41645::SUBDEVICE_103C12C1: return "SUBDEVICE_103C12C1";
        case PciSubDevice14E41645::SUBDEVICE_103C1300: return "SUBDEVICE_103C1300";
        case PciSubDevice14E41645::SUBDEVICE_10A98010: return "SUBDEVICE_10A98010";
        case PciSubDevice14E41645::SUBDEVICE_10A98011: return "SUBDEVICE_10A98011";
        case PciSubDevice14E41645::SUBDEVICE_10A98012: return "SUBDEVICE_10A98012";
        case PciSubDevice14E41645::SUBDEVICE_10B71004: return "SUBDEVICE_10B71004";
        case PciSubDevice14E41645::SUBDEVICE_10B71006: return "SUBDEVICE_10B71006";
        case PciSubDevice14E41645::SUBDEVICE_10B71007: return "SUBDEVICE_10B71007";
        case PciSubDevice14E41645::SUBDEVICE_10B71008: return "SUBDEVICE_10B71008";
        case PciSubDevice14E41645::SUBDEVICE_14E40001: return "SUBDEVICE_14E40001";
        case PciSubDevice14E41645::SUBDEVICE_14E40005: return "SUBDEVICE_14E40005";
        case PciSubDevice14E41645::SUBDEVICE_14E40006: return "SUBDEVICE_14E40006";
        case PciSubDevice14E41645::SUBDEVICE_14E40007: return "SUBDEVICE_14E40007";
        case PciSubDevice14E41645::SUBDEVICE_14E40008: return "SUBDEVICE_14E40008";
        case PciSubDevice14E41645::SUBDEVICE_14E41645: return "SUBDEVICE_14E41645";
        case PciSubDevice14E41645::SUBDEVICE_14E48008: return "SUBDEVICE_14E48008";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E41645 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E41645 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41645::SUBDEVICE_0E11007C: return "NC7770 Gigabit Server Adapter (PCI-X, 10/100/1000-T)";
        case PciSubDevice14E41645::SUBDEVICE_0E11007D: return "NC6770 Gigabit Server Adapter (PCI-X, 1000-SX)";
        case PciSubDevice14E41645::SUBDEVICE_0E110085: return "NC7780 Gigabit Server Adapter (embedded, WOL)";
        case PciSubDevice14E41645::SUBDEVICE_0E110099: return "NC7780 Gigabit Server Adapter (embedded, WOL)";
        case PciSubDevice14E41645::SUBDEVICE_0E11009A: return "NC7770 Gigabit Server Adapter (PCI-X, 10/100/1000-T)";
        case PciSubDevice14E41645::SUBDEVICE_0E1100C1: return "NC6770 Gigabit Server Adapter (PCI-X, 1000-SX)";
        case PciSubDevice14E41645::SUBDEVICE_10280121: return "Broadcom BCM5701 1000Base-T";
        case PciSubDevice14E41645::SUBDEVICE_103C128A: return "BCM5701 1000Base-T (HP, OEM 3COM)";
        case PciSubDevice14E41645::SUBDEVICE_103C128B: return "1000Base-SX (PCI) [A7073A]";
        case PciSubDevice14E41645::SUBDEVICE_103C12A4: return "Core Lan 1000Base-T";
        case PciSubDevice14E41645::SUBDEVICE_103C12C1: return "IOX Core Lan 1000Base-T [A7109AX]";
        case PciSubDevice14E41645::SUBDEVICE_103C1300: return "Core LAN/SCSI Combo [A6794A]";
        case PciSubDevice14E41645::SUBDEVICE_10A98010: return "IO9/IO10 Gigabit Ethernet (Copper)";
        case PciSubDevice14E41645::SUBDEVICE_10A98011: return "Gigabit Ethernet (Copper)";
        case PciSubDevice14E41645::SUBDEVICE_10A98012: return "Gigabit Ethernet (Fiber)";
        case PciSubDevice14E41645::SUBDEVICE_10B71004: return "3C996-SX 1000Base-SX";
        case PciSubDevice14E41645::SUBDEVICE_10B71006: return "3C996B-T 1000Base-T";
        case PciSubDevice14E41645::SUBDEVICE_10B71007: return "3C1000-T 1000Base-T";
        case PciSubDevice14E41645::SUBDEVICE_10B71008: return "3C940-BR01 1000Base-T";
        case PciSubDevice14E41645::SUBDEVICE_14E40001: return "BCM5701 1000Base-T";
        case PciSubDevice14E41645::SUBDEVICE_14E40005: return "BCM5701 1000Base-T";
        case PciSubDevice14E41645::SUBDEVICE_14E40006: return "BCM5701 1000Base-T";
        case PciSubDevice14E41645::SUBDEVICE_14E40007: return "BCM5701 1000Base-SX";
        case PciSubDevice14E41645::SUBDEVICE_14E40008: return "BCM5701 1000Base-T";
        case PciSubDevice14E41645::SUBDEVICE_14E41645: return "NetXtreme BCM5701 Gigabit Ethernet";
        case PciSubDevice14E41645::SUBDEVICE_14E48008: return "BCM5701 1000Base-T";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41645_H
