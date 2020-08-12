// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR110A_PCIDEVICE110A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR110A_PCIDEVICE110A_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice110A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0002 = 0x0002,
    DEVICE_0005 = 0x0005,
    DEVICE_0006 = 0x0006,
    DEVICE_0015 = 0x0015,
    DEVICE_001D = 0x001D,
    DEVICE_007B = 0x007B,
    DEVICE_007C = 0x007C,
    DEVICE_007D = 0x007D,
    DEVICE_2101 = 0x2101,
    DEVICE_2102 = 0x2102,
    DEVICE_2104 = 0x2104,
    DEVICE_3141 = 0x3141,
    DEVICE_3142 = 0x3142,
    DEVICE_3143 = 0x3143,
    DEVICE_4021 = 0x4021,
    DEVICE_4029 = 0x4029,
    DEVICE_4035 = 0x4035,
    DEVICE_4036 = 0x4036,
    DEVICE_4038 = 0x4038,
    DEVICE_4069 = 0x4069,
    DEVICE_407C = 0x407C,
    DEVICE_407D = 0x407D,
    DEVICE_407E = 0x407E,
    DEVICE_4083 = 0x4083,
    DEVICE_4084 = 0x4084,
    DEVICE_4942 = 0x4942,
    DEVICE_6120 = 0x6120
};



inline const char8* enumToString(PciDevice110A device110A) // TEST: NO
{
    // COMMON_LT((" | device110A = %u", device110A)); // Commented to avoid bad looking logs



    switch (device110A)
    {
        case PciDevice110A::NONE:        return "NONE";
        case PciDevice110A::DEVICE_0002: return "DEVICE_0002";
        case PciDevice110A::DEVICE_0005: return "DEVICE_0005";
        case PciDevice110A::DEVICE_0006: return "DEVICE_0006";
        case PciDevice110A::DEVICE_0015: return "DEVICE_0015";
        case PciDevice110A::DEVICE_001D: return "DEVICE_001D";
        case PciDevice110A::DEVICE_007B: return "DEVICE_007B";
        case PciDevice110A::DEVICE_007C: return "DEVICE_007C";
        case PciDevice110A::DEVICE_007D: return "DEVICE_007D";
        case PciDevice110A::DEVICE_2101: return "DEVICE_2101";
        case PciDevice110A::DEVICE_2102: return "DEVICE_2102";
        case PciDevice110A::DEVICE_2104: return "DEVICE_2104";
        case PciDevice110A::DEVICE_3141: return "DEVICE_3141";
        case PciDevice110A::DEVICE_3142: return "DEVICE_3142";
        case PciDevice110A::DEVICE_3143: return "DEVICE_3143";
        case PciDevice110A::DEVICE_4021: return "DEVICE_4021";
        case PciDevice110A::DEVICE_4029: return "DEVICE_4029";
        case PciDevice110A::DEVICE_4035: return "DEVICE_4035";
        case PciDevice110A::DEVICE_4036: return "DEVICE_4036";
        case PciDevice110A::DEVICE_4038: return "DEVICE_4038";
        case PciDevice110A::DEVICE_4069: return "DEVICE_4069";
        case PciDevice110A::DEVICE_407C: return "DEVICE_407C";
        case PciDevice110A::DEVICE_407D: return "DEVICE_407D";
        case PciDevice110A::DEVICE_407E: return "DEVICE_407E";
        case PciDevice110A::DEVICE_4083: return "DEVICE_4083";
        case PciDevice110A::DEVICE_4084: return "DEVICE_4084";
        case PciDevice110A::DEVICE_4942: return "DEVICE_4942";
        case PciDevice110A::DEVICE_6120: return "DEVICE_6120";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice110A device110A) // TEST: NO
{
    // COMMON_LT((" | device110A = %u", device110A)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device110A, enumToString(device110A));

    return res;
}



inline const char8* enumToHumanString(PciDevice110A device110A) // TEST: NO
{
    // COMMON_LT((" | device110A = %u", device110A)); // Commented to avoid bad looking logs



    switch (device110A)
    {
        case PciDevice110A::DEVICE_0002: return "Pirahna 2-port";
        case PciDevice110A::DEVICE_0005: return "Tulip controller, power management, switch extender";
        case PciDevice110A::DEVICE_0006: return "FSC PINC (I/O-APIC)";
        case PciDevice110A::DEVICE_0015: return "FSC Multiprocessor Interrupt Controller";
        case PciDevice110A::DEVICE_001D: return "FSC Copernicus Management Controller";
        case PciDevice110A::DEVICE_007B: return "FSC Remote Service Controller, mailbox device";
        case PciDevice110A::DEVICE_007C: return "FSC Remote Service Controller, shared memory device";
        case PciDevice110A::DEVICE_007D: return "FSC Remote Service Controller, SMIC device";
        case PciDevice110A::DEVICE_2101: return "HST SAPHIR V Primary PCI (ISDN/PMx)";
        case PciDevice110A::DEVICE_2102: return "DSCC4 PEB/PEF 20534 DMA Supported Serial Communication Controller with 4 Channels";
        case PciDevice110A::DEVICE_2104: return "Eicon Diva 2.02 compatible passive ISDN card";
        case PciDevice110A::DEVICE_3141: return "SIMATIC NET CP 5611 / 5621";
        case PciDevice110A::DEVICE_3142: return "SIMATIC NET CP 5613 / 5614";
        case PciDevice110A::DEVICE_3143: return "SIMATIC NET CP 1613";
        case PciDevice110A::DEVICE_4021: return "SIMATIC NET CP 5512 (Profibus and MPI Cardbus Adapter)";
        case PciDevice110A::DEVICE_4029: return "SIMATIC NET CP 5613 A2";
        case PciDevice110A::DEVICE_4035: return "SIMATIC NET CP 1613 A2";
        case PciDevice110A::DEVICE_4036: return "SIMATIC NET CP 1616";
        case PciDevice110A::DEVICE_4038: return "SIMATIC NET CP 1604";
        case PciDevice110A::DEVICE_4069: return "SIMATIC NET CP 5623";
        case PciDevice110A::DEVICE_407C: return "SIMATIC NET CP 5612";
        case PciDevice110A::DEVICE_407D: return "SIMATIC NET CP 5613 A3";
        case PciDevice110A::DEVICE_407E: return "SIMATIC NET CP 5622";
        case PciDevice110A::DEVICE_4083: return "SIMATIC NET CP 5614 A3";
        case PciDevice110A::DEVICE_4084: return "SIMATIC NET CP 1626";
        case PciDevice110A::DEVICE_4942: return "FPGA I-Bus Tracer for MBD";
        case PciDevice110A::DEVICE_6120: return "SZB6120";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR110A_PCIDEVICE110A_H
