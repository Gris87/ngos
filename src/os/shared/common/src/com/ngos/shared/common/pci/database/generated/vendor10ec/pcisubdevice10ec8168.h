// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8168_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8168_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10EC8168: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10198168 = 0x10198168,
    SUBDEVICE_10251094 = 0x10251094,
    SUBDEVICE_10280283 = 0x10280283,
    SUBDEVICE_102804B2 = 0x102804B2,
    SUBDEVICE_102804DA = 0x102804DA,
    SUBDEVICE_102806F2 = 0x102806F2,
    SUBDEVICE_102806F3 = 0x102806F3,
    SUBDEVICE_10280869 = 0x10280869,
    SUBDEVICE_103C1611 = 0x103C1611,
    SUBDEVICE_103C1950 = 0x103C1950,
    SUBDEVICE_103C2A6F = 0x103C2A6F,
    SUBDEVICE_103C825B = 0x103C825B,
    SUBDEVICE_103C8615 = 0x103C8615,
    SUBDEVICE_104311F5 = 0x104311F5,
    SUBDEVICE_104316D5 = 0x104316D5,
    SUBDEVICE_104381AA = 0x104381AA,
    SUBDEVICE_104382C6 = 0x104382C6,
    SUBDEVICE_104383A3 = 0x104383A3,
    SUBDEVICE_10438432 = 0x10438432,
    SUBDEVICE_10438505 = 0x10438505,
    SUBDEVICE_105B0D7C = 0x105B0D7C,
    SUBDEVICE_10EC8168 = 0x10EC8168,
    SUBDEVICE_144DC652 = 0x144DC652,
    SUBDEVICE_1458E000 = 0x1458E000,
    SUBDEVICE_1462238C = 0x1462238C,
    SUBDEVICE_1462345C = 0x1462345C,
    SUBDEVICE_1462368C = 0x1462368C,
    SUBDEVICE_14624180 = 0x14624180,
    SUBDEVICE_14627522 = 0x14627522,
    SUBDEVICE_14627C37 = 0x14627C37,
    SUBDEVICE_177511CC = 0x177511CC,
    SUBDEVICE_17AA3814 = 0x17AA3814,
    SUBDEVICE_17AA3823 = 0x17AA3823,
    SUBDEVICE_17AA5124 = 0x17AA5124,
    SUBDEVICE_18498168 = 0x18498168,
    SUBDEVICE_74703468 = 0x74703468,
    SUBDEVICE_80862055 = 0x80862055,
    SUBDEVICE_8086D615 = 0x8086D615
};



inline const char8* enumToString(PciSubDevice10EC8168 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EC8168::NONE:               return "NONE";
        case PciSubDevice10EC8168::SUBDEVICE_10198168: return "SUBDEVICE_10198168";
        case PciSubDevice10EC8168::SUBDEVICE_10251094: return "SUBDEVICE_10251094";
        case PciSubDevice10EC8168::SUBDEVICE_10280283: return "SUBDEVICE_10280283";
        case PciSubDevice10EC8168::SUBDEVICE_102804B2: return "SUBDEVICE_102804B2";
        case PciSubDevice10EC8168::SUBDEVICE_102804DA: return "SUBDEVICE_102804DA";
        case PciSubDevice10EC8168::SUBDEVICE_102806F2: return "SUBDEVICE_102806F2";
        case PciSubDevice10EC8168::SUBDEVICE_102806F3: return "SUBDEVICE_102806F3";
        case PciSubDevice10EC8168::SUBDEVICE_10280869: return "SUBDEVICE_10280869";
        case PciSubDevice10EC8168::SUBDEVICE_103C1611: return "SUBDEVICE_103C1611";
        case PciSubDevice10EC8168::SUBDEVICE_103C1950: return "SUBDEVICE_103C1950";
        case PciSubDevice10EC8168::SUBDEVICE_103C2A6F: return "SUBDEVICE_103C2A6F";
        case PciSubDevice10EC8168::SUBDEVICE_103C825B: return "SUBDEVICE_103C825B";
        case PciSubDevice10EC8168::SUBDEVICE_103C8615: return "SUBDEVICE_103C8615";
        case PciSubDevice10EC8168::SUBDEVICE_104311F5: return "SUBDEVICE_104311F5";
        case PciSubDevice10EC8168::SUBDEVICE_104316D5: return "SUBDEVICE_104316D5";
        case PciSubDevice10EC8168::SUBDEVICE_104381AA: return "SUBDEVICE_104381AA";
        case PciSubDevice10EC8168::SUBDEVICE_104382C6: return "SUBDEVICE_104382C6";
        case PciSubDevice10EC8168::SUBDEVICE_104383A3: return "SUBDEVICE_104383A3";
        case PciSubDevice10EC8168::SUBDEVICE_10438432: return "SUBDEVICE_10438432";
        case PciSubDevice10EC8168::SUBDEVICE_10438505: return "SUBDEVICE_10438505";
        case PciSubDevice10EC8168::SUBDEVICE_105B0D7C: return "SUBDEVICE_105B0D7C";
        case PciSubDevice10EC8168::SUBDEVICE_10EC8168: return "SUBDEVICE_10EC8168";
        case PciSubDevice10EC8168::SUBDEVICE_144DC652: return "SUBDEVICE_144DC652";
        case PciSubDevice10EC8168::SUBDEVICE_1458E000: return "SUBDEVICE_1458E000";
        case PciSubDevice10EC8168::SUBDEVICE_1462238C: return "SUBDEVICE_1462238C";
        case PciSubDevice10EC8168::SUBDEVICE_1462345C: return "SUBDEVICE_1462345C";
        case PciSubDevice10EC8168::SUBDEVICE_1462368C: return "SUBDEVICE_1462368C";
        case PciSubDevice10EC8168::SUBDEVICE_14624180: return "SUBDEVICE_14624180";
        case PciSubDevice10EC8168::SUBDEVICE_14627522: return "SUBDEVICE_14627522";
        case PciSubDevice10EC8168::SUBDEVICE_14627C37: return "SUBDEVICE_14627C37";
        case PciSubDevice10EC8168::SUBDEVICE_177511CC: return "SUBDEVICE_177511CC";
        case PciSubDevice10EC8168::SUBDEVICE_17AA3814: return "SUBDEVICE_17AA3814";
        case PciSubDevice10EC8168::SUBDEVICE_17AA3823: return "SUBDEVICE_17AA3823";
        case PciSubDevice10EC8168::SUBDEVICE_17AA5124: return "SUBDEVICE_17AA5124";
        case PciSubDevice10EC8168::SUBDEVICE_18498168: return "SUBDEVICE_18498168";
        case PciSubDevice10EC8168::SUBDEVICE_74703468: return "SUBDEVICE_74703468";
        case PciSubDevice10EC8168::SUBDEVICE_80862055: return "SUBDEVICE_80862055";
        case PciSubDevice10EC8168::SUBDEVICE_8086D615: return "SUBDEVICE_8086D615";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10EC8168 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10EC8168 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EC8168::SUBDEVICE_10198168: return "RTL8111/8168 PCI Express Gigabit Ethernet controller";
        case PciSubDevice10EC8168::SUBDEVICE_10251094: return "Acer Aspire E5-575G";
        case PciSubDevice10EC8168::SUBDEVICE_10280283: return "Vostro 220";
        case PciSubDevice10EC8168::SUBDEVICE_102804B2: return "Vostro 3350";
        case PciSubDevice10EC8168::SUBDEVICE_102804DA: return "Vostro 3750";
        case PciSubDevice10EC8168::SUBDEVICE_102806F2: return "Latitude 3470";
        case PciSubDevice10EC8168::SUBDEVICE_102806F3: return "Latitude 3570";
        case PciSubDevice10EC8168::SUBDEVICE_10280869: return "Vostro 3470";
        case PciSubDevice10EC8168::SUBDEVICE_103C1611: return "Pavilion DM1Z-3000";
        case PciSubDevice10EC8168::SUBDEVICE_103C1950: return "ProBook 450/455";
        case PciSubDevice10EC8168::SUBDEVICE_103C2A6F: return "Asus IPIBL-LB Motherboard";
        case PciSubDevice10EC8168::SUBDEVICE_103C825B: return "OMEN-17-w001nv";
        case PciSubDevice10EC8168::SUBDEVICE_103C8615: return "Pavilion Laptop 15-cw1xxx";
        case PciSubDevice10EC8168::SUBDEVICE_104311F5: return "Notebook motherboard (one of many models)";
        case PciSubDevice10EC8168::SUBDEVICE_104316D5: return "U6V/U31J laptop";
        case PciSubDevice10EC8168::SUBDEVICE_104381AA: return "P5B";
        case PciSubDevice10EC8168::SUBDEVICE_104382C6: return "M3A78 Series Motherboard";
        case PciSubDevice10EC8168::SUBDEVICE_104383A3: return "M4A785/P7P55 Motherboard";
        case PciSubDevice10EC8168::SUBDEVICE_10438432: return "P8P67 and other motherboards";
        case PciSubDevice10EC8168::SUBDEVICE_10438505: return "P8 series motherboard";
        case PciSubDevice10EC8168::SUBDEVICE_105B0D7C: return "D270S/D250S Motherboard";
        case PciSubDevice10EC8168::SUBDEVICE_10EC8168: return "RTL8111/8168 PCI Express Gigabit Ethernet controller";
        case PciSubDevice10EC8168::SUBDEVICE_144DC652: return "RTL8168 on a NP300E5C series laptop";
        case PciSubDevice10EC8168::SUBDEVICE_1458E000: return "Onboard Ethernet";
        case PciSubDevice10EC8168::SUBDEVICE_1462238C: return "Onboard RTL8111b on MSI P965 Platinum Mainboard";
        case PciSubDevice10EC8168::SUBDEVICE_1462345C: return "RTL8111B on MS-7345 Motherboard";
        case PciSubDevice10EC8168::SUBDEVICE_1462368C: return "K9AG Neo2";
        case PciSubDevice10EC8168::SUBDEVICE_14624180: return "Wind PC MS-7418";
        case PciSubDevice10EC8168::SUBDEVICE_14627522: return "X58 Pro-E";
        case PciSubDevice10EC8168::SUBDEVICE_14627C37: return "X570-A PRO motherboard";
        case PciSubDevice10EC8168::SUBDEVICE_177511CC: return "CC11/CL11";
        case PciSubDevice10EC8168::SUBDEVICE_17AA3814: return "Z50-75";
        case PciSubDevice10EC8168::SUBDEVICE_17AA3823: return "Lenovo V130-15IGM Laptop - Type 81HL";
        case PciSubDevice10EC8168::SUBDEVICE_17AA5124: return "ThinkPad E595";
        case PciSubDevice10EC8168::SUBDEVICE_18498168: return "Motherboard (one of many)";
        case PciSubDevice10EC8168::SUBDEVICE_74703468: return "TG-3468 Gigabit PCI Express Network Adapter";
        case PciSubDevice10EC8168::SUBDEVICE_80862055: return "NUC Kit DN2820FYKH";
        case PciSubDevice10EC8168::SUBDEVICE_8086D615: return "Desktop Board D510MO/D525MW";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8168_H
