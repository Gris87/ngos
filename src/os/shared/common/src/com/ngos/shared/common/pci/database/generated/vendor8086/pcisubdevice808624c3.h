// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624C3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624C3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808624C3: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140267 = 0x10140267,
    SUBDEVICE_1014052D = 0x1014052D,
    SUBDEVICE_1025005A = 0x1025005A,
    SUBDEVICE_10250064 = 0x10250064,
    SUBDEVICE_10280126 = 0x10280126,
    SUBDEVICE_1028014F = 0x1028014F,
    SUBDEVICE_10280160 = 0x10280160,
    SUBDEVICE_1028018D = 0x1028018D,
    SUBDEVICE_103C088C = 0x103C088C,
    SUBDEVICE_103C0890 = 0x103C0890,
    SUBDEVICE_103C08B0 = 0x103C08B0,
    SUBDEVICE_10718160 = 0x10718160,
    SUBDEVICE_114A0582 = 0x114A0582,
    SUBDEVICE_144DC005 = 0x144DC005,
    SUBDEVICE_144DC00C = 0x144DC00C,
    SUBDEVICE_145824C2 = 0x145824C2,
    SUBDEVICE_14625800 = 0x14625800,
    SUBDEVICE_17341004 = 0x17341004,
    SUBDEVICE_17341055 = 0x17341055,
    SUBDEVICE_4C531090 = 0x4C531090,
    SUBDEVICE_E4BF0CC9 = 0xE4BF0CC9,
    SUBDEVICE_E4BF0CD2 = 0xE4BF0CD2
};



inline const char8* enumToString(PciSubDevice808624C3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624C3::NONE:               return "NONE";
        case PciSubDevice808624C3::SUBDEVICE_10140267: return "SUBDEVICE_10140267";
        case PciSubDevice808624C3::SUBDEVICE_1014052D: return "SUBDEVICE_1014052D";
        case PciSubDevice808624C3::SUBDEVICE_1025005A: return "SUBDEVICE_1025005A";
        case PciSubDevice808624C3::SUBDEVICE_10250064: return "SUBDEVICE_10250064";
        case PciSubDevice808624C3::SUBDEVICE_10280126: return "SUBDEVICE_10280126";
        case PciSubDevice808624C3::SUBDEVICE_1028014F: return "SUBDEVICE_1028014F";
        case PciSubDevice808624C3::SUBDEVICE_10280160: return "SUBDEVICE_10280160";
        case PciSubDevice808624C3::SUBDEVICE_1028018D: return "SUBDEVICE_1028018D";
        case PciSubDevice808624C3::SUBDEVICE_103C088C: return "SUBDEVICE_103C088C";
        case PciSubDevice808624C3::SUBDEVICE_103C0890: return "SUBDEVICE_103C0890";
        case PciSubDevice808624C3::SUBDEVICE_103C08B0: return "SUBDEVICE_103C08B0";
        case PciSubDevice808624C3::SUBDEVICE_10718160: return "SUBDEVICE_10718160";
        case PciSubDevice808624C3::SUBDEVICE_114A0582: return "SUBDEVICE_114A0582";
        case PciSubDevice808624C3::SUBDEVICE_144DC005: return "SUBDEVICE_144DC005";
        case PciSubDevice808624C3::SUBDEVICE_144DC00C: return "SUBDEVICE_144DC00C";
        case PciSubDevice808624C3::SUBDEVICE_145824C2: return "SUBDEVICE_145824C2";
        case PciSubDevice808624C3::SUBDEVICE_14625800: return "SUBDEVICE_14625800";
        case PciSubDevice808624C3::SUBDEVICE_17341004: return "SUBDEVICE_17341004";
        case PciSubDevice808624C3::SUBDEVICE_17341055: return "SUBDEVICE_17341055";
        case PciSubDevice808624C3::SUBDEVICE_4C531090: return "SUBDEVICE_4C531090";
        case PciSubDevice808624C3::SUBDEVICE_E4BF0CC9: return "SUBDEVICE_E4BF0CC9";
        case PciSubDevice808624C3::SUBDEVICE_E4BF0CD2: return "SUBDEVICE_E4BF0CD2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808624C3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808624C3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624C3::SUBDEVICE_10140267: return "NetVista A30p";
        case PciSubDevice808624C3::SUBDEVICE_1014052D: return "ThinkPad";
        case PciSubDevice808624C3::SUBDEVICE_1025005A: return "TravelMate 290";
        case PciSubDevice808624C3::SUBDEVICE_10250064: return "Extensa 3000 series laptop: Intel 82801DBM (ICH4-M)";
        case PciSubDevice808624C3::SUBDEVICE_10280126: return "Optiplex GX260";
        case PciSubDevice808624C3::SUBDEVICE_1028014F: return "Latitude X300";
        case PciSubDevice808624C3::SUBDEVICE_10280160: return "Dimension 2400";
        case PciSubDevice808624C3::SUBDEVICE_1028018D: return "Inspiron 700m/710m";
        case PciSubDevice808624C3::SUBDEVICE_103C088C: return "NC8000 laptop";
        case PciSubDevice808624C3::SUBDEVICE_103C0890: return "NC6000 laptop";
        case PciSubDevice808624C3::SUBDEVICE_103C08B0: return "tc1100 tablet";
        case PciSubDevice808624C3::SUBDEVICE_10718160: return "MIM2000";
        case PciSubDevice808624C3::SUBDEVICE_114A0582: return "PC8 onboard SMbus";
        case PciSubDevice808624C3::SUBDEVICE_144DC005: return "X10 Laptop";
        case PciSubDevice808624C3::SUBDEVICE_144DC00C: return "P30/P35 notebook";
        case PciSubDevice808624C3::SUBDEVICE_145824C2: return "GA-8PE667 Ultra";
        case PciSubDevice808624C3::SUBDEVICE_14625800: return "845PE Max (MS-6580)";
        case PciSubDevice808624C3::SUBDEVICE_17341004: return "D1451 Mainboard (SCENIC N300, i845GV)";
        case PciSubDevice808624C3::SUBDEVICE_17341055: return "Amilo M1420";
        case PciSubDevice808624C3::SUBDEVICE_4C531090: return "Cx9 / Vx9 mainboard";
        case PciSubDevice808624C3::SUBDEVICE_E4BF0CC9: return "CC9-SAMBA";
        case PciSubDevice808624C3::SUBDEVICE_E4BF0CD2: return "CD2-BEBOP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624C3_H
