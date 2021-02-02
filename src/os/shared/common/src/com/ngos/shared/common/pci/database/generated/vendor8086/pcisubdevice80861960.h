// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861960_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861960_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861960: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101E0431 = 0x101E0431,
    SUBDEVICE_101E0438 = 0x101E0438,
    SUBDEVICE_101E0466 = 0x101E0466,
    SUBDEVICE_101E0467 = 0x101E0467,
    SUBDEVICE_101E0490 = 0x101E0490,
    SUBDEVICE_101E0762 = 0x101E0762,
    SUBDEVICE_101E09A0 = 0x101E09A0,
    SUBDEVICE_10280467 = 0x10280467,
    SUBDEVICE_10281111 = 0x10281111,
    SUBDEVICE_103C03A2 = 0x103C03A2,
    SUBDEVICE_103C10C6 = 0x103C10C6,
    SUBDEVICE_103C10C7 = 0x103C10C7,
    SUBDEVICE_103C10CC = 0x103C10CC,
    SUBDEVICE_103C10CD = 0x103C10CD,
    SUBDEVICE_105A0000 = 0x105A0000,
    SUBDEVICE_105A2168 = 0x105A2168,
    SUBDEVICE_105A5168 = 0x105A5168,
    SUBDEVICE_11111111 = 0x11111111,
    SUBDEVICE_11111112 = 0x11111112,
    SUBDEVICE_113C03A2 = 0x113C03A2,
    SUBDEVICE_E4BF1010 = 0xE4BF1010,
    SUBDEVICE_E4BF1020 = 0xE4BF1020,
    SUBDEVICE_E4BF1040 = 0xE4BF1040,
    SUBDEVICE_E4BF3100 = 0xE4BF3100
};



inline const char8* enumToString(PciSubDevice80861960 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861960::NONE:               return "NONE";
        case PciSubDevice80861960::SUBDEVICE_101E0431: return "SUBDEVICE_101E0431";
        case PciSubDevice80861960::SUBDEVICE_101E0438: return "SUBDEVICE_101E0438";
        case PciSubDevice80861960::SUBDEVICE_101E0466: return "SUBDEVICE_101E0466";
        case PciSubDevice80861960::SUBDEVICE_101E0467: return "SUBDEVICE_101E0467";
        case PciSubDevice80861960::SUBDEVICE_101E0490: return "SUBDEVICE_101E0490";
        case PciSubDevice80861960::SUBDEVICE_101E0762: return "SUBDEVICE_101E0762";
        case PciSubDevice80861960::SUBDEVICE_101E09A0: return "SUBDEVICE_101E09A0";
        case PciSubDevice80861960::SUBDEVICE_10280467: return "SUBDEVICE_10280467";
        case PciSubDevice80861960::SUBDEVICE_10281111: return "SUBDEVICE_10281111";
        case PciSubDevice80861960::SUBDEVICE_103C03A2: return "SUBDEVICE_103C03A2";
        case PciSubDevice80861960::SUBDEVICE_103C10C6: return "SUBDEVICE_103C10C6";
        case PciSubDevice80861960::SUBDEVICE_103C10C7: return "SUBDEVICE_103C10C7";
        case PciSubDevice80861960::SUBDEVICE_103C10CC: return "SUBDEVICE_103C10CC";
        case PciSubDevice80861960::SUBDEVICE_103C10CD: return "SUBDEVICE_103C10CD";
        case PciSubDevice80861960::SUBDEVICE_105A0000: return "SUBDEVICE_105A0000";
        case PciSubDevice80861960::SUBDEVICE_105A2168: return "SUBDEVICE_105A2168";
        case PciSubDevice80861960::SUBDEVICE_105A5168: return "SUBDEVICE_105A5168";
        case PciSubDevice80861960::SUBDEVICE_11111111: return "SUBDEVICE_11111111";
        case PciSubDevice80861960::SUBDEVICE_11111112: return "SUBDEVICE_11111112";
        case PciSubDevice80861960::SUBDEVICE_113C03A2: return "SUBDEVICE_113C03A2";
        case PciSubDevice80861960::SUBDEVICE_E4BF1010: return "SUBDEVICE_E4BF1010";
        case PciSubDevice80861960::SUBDEVICE_E4BF1020: return "SUBDEVICE_E4BF1020";
        case PciSubDevice80861960::SUBDEVICE_E4BF1040: return "SUBDEVICE_E4BF1040";
        case PciSubDevice80861960::SUBDEVICE_E4BF3100: return "SUBDEVICE_E4BF3100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861960 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861960 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861960::SUBDEVICE_101E0431: return "MegaRAID 431 RAID Controller";
        case PciSubDevice80861960::SUBDEVICE_101E0438: return "MegaRAID 438 Ultra2 LVD RAID Controller";
        case PciSubDevice80861960::SUBDEVICE_101E0466: return "MegaRAID 466 Express Plus RAID Controller";
        case PciSubDevice80861960::SUBDEVICE_101E0467: return "MegaRAID 467 Enterprise 1500 RAID Controller";
        case PciSubDevice80861960::SUBDEVICE_101E0490: return "MegaRAID 490 Express 300 RAID Controller";
        case PciSubDevice80861960::SUBDEVICE_101E0762: return "MegaRAID 762 Express RAID Controller";
        case PciSubDevice80861960::SUBDEVICE_101E09A0: return "PowerEdge Expandable RAID Controller 2/SC";
        case PciSubDevice80861960::SUBDEVICE_10280467: return "PowerEdge Expandable RAID Controller 2/DC";
        case PciSubDevice80861960::SUBDEVICE_10281111: return "PowerEdge Expandable RAID Controller 2/SC";
        case PciSubDevice80861960::SUBDEVICE_103C03A2: return "MegaRAID";
        case PciSubDevice80861960::SUBDEVICE_103C10C6: return "MegaRAID 438, NetRAID-3Si";
        case PciSubDevice80861960::SUBDEVICE_103C10C7: return "MegaRAID T5, Integrated NetRAID";
        case PciSubDevice80861960::SUBDEVICE_103C10CC: return "MegaRAID, Integrated NetRAID";
        case PciSubDevice80861960::SUBDEVICE_103C10CD: return "NetRAID-1Si";
        case PciSubDevice80861960::SUBDEVICE_105A0000: return "SuperTrak";
        case PciSubDevice80861960::SUBDEVICE_105A2168: return "SuperTrak Pro";
        case PciSubDevice80861960::SUBDEVICE_105A5168: return "SuperTrak66/100";
        case PciSubDevice80861960::SUBDEVICE_11111111: return "MegaRAID 466, PowerEdge Expandable RAID Controller 2/SC";
        case PciSubDevice80861960::SUBDEVICE_11111112: return "PowerEdge Expandable RAID Controller 2/SC";
        case PciSubDevice80861960::SUBDEVICE_113C03A2: return "MegaRAID";
        case PciSubDevice80861960::SUBDEVICE_E4BF1010: return "CG1-RADIO";
        case PciSubDevice80861960::SUBDEVICE_E4BF1020: return "CU2-QUARTET";
        case PciSubDevice80861960::SUBDEVICE_E4BF1040: return "CU1-CHORUS";
        case PciSubDevice80861960::SUBDEVICE_E4BF3100: return "CX1-BAND";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861960_H
