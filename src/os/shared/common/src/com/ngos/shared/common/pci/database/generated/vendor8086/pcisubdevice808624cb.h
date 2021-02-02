// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624CB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624CB_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808624CB: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140267 = 0x10140267,
    SUBDEVICE_10280126 = 0x10280126,
    SUBDEVICE_10280160 = 0x10280160,
    SUBDEVICE_10438089 = 0x10438089,
    SUBDEVICE_114A0582 = 0x114A0582,
    SUBDEVICE_145824C2 = 0x145824C2,
    SUBDEVICE_14625800 = 0x14625800,
    SUBDEVICE_17341004 = 0x17341004,
    SUBDEVICE_4C531090 = 0x4C531090,
    SUBDEVICE_E4BF0CC9 = 0xE4BF0CC9,
    SUBDEVICE_E4BF0CD2 = 0xE4BF0CD2
};



inline const char8* enumToString(PciSubDevice808624CB subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624CB::NONE:               return "NONE";
        case PciSubDevice808624CB::SUBDEVICE_10140267: return "SUBDEVICE_10140267";
        case PciSubDevice808624CB::SUBDEVICE_10280126: return "SUBDEVICE_10280126";
        case PciSubDevice808624CB::SUBDEVICE_10280160: return "SUBDEVICE_10280160";
        case PciSubDevice808624CB::SUBDEVICE_10438089: return "SUBDEVICE_10438089";
        case PciSubDevice808624CB::SUBDEVICE_114A0582: return "SUBDEVICE_114A0582";
        case PciSubDevice808624CB::SUBDEVICE_145824C2: return "SUBDEVICE_145824C2";
        case PciSubDevice808624CB::SUBDEVICE_14625800: return "SUBDEVICE_14625800";
        case PciSubDevice808624CB::SUBDEVICE_17341004: return "SUBDEVICE_17341004";
        case PciSubDevice808624CB::SUBDEVICE_4C531090: return "SUBDEVICE_4C531090";
        case PciSubDevice808624CB::SUBDEVICE_E4BF0CC9: return "SUBDEVICE_E4BF0CC9";
        case PciSubDevice808624CB::SUBDEVICE_E4BF0CD2: return "SUBDEVICE_E4BF0CD2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808624CB subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808624CB subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624CB::SUBDEVICE_10140267: return "NetVista A30p";
        case PciSubDevice808624CB::SUBDEVICE_10280126: return "Optiplex GX260";
        case PciSubDevice808624CB::SUBDEVICE_10280160: return "Dimension 2400";
        case PciSubDevice808624CB::SUBDEVICE_10438089: return "P4B533";
        case PciSubDevice808624CB::SUBDEVICE_114A0582: return "PC8 onboard IDE";
        case PciSubDevice808624CB::SUBDEVICE_145824C2: return "GA-8PE667 Ultra";
        case PciSubDevice808624CB::SUBDEVICE_14625800: return "845PE Max (MS-6580)";
        case PciSubDevice808624CB::SUBDEVICE_17341004: return "D1451 Mainboard (SCENIC N300, bad_int845GV)";
        case PciSubDevice808624CB::SUBDEVICE_4C531090: return "Cx9 / Vx9 mainboard";
        case PciSubDevice808624CB::SUBDEVICE_E4BF0CC9: return "CC9-SAMBA";
        case PciSubDevice808624CB::SUBDEVICE_E4BF0CD2: return "CD2-BEBOP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624CB_H
