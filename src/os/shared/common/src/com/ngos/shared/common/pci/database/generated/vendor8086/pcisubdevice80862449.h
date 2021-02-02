// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862449_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862449_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862449: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E110012 = 0x0E110012,
    SUBDEVICE_0E110091 = 0x0E110091,
    SUBDEVICE_101401CE = 0x101401CE,
    SUBDEVICE_101401DC = 0x101401DC,
    SUBDEVICE_101401EB = 0x101401EB,
    SUBDEVICE_101401EC = 0x101401EC,
    SUBDEVICE_10140202 = 0x10140202,
    SUBDEVICE_10140205 = 0x10140205,
    SUBDEVICE_10140217 = 0x10140217,
    SUBDEVICE_10140234 = 0x10140234,
    SUBDEVICE_1014023D = 0x1014023D,
    SUBDEVICE_10140244 = 0x10140244,
    SUBDEVICE_10140245 = 0x10140245,
    SUBDEVICE_10140265 = 0x10140265,
    SUBDEVICE_10140267 = 0x10140267,
    SUBDEVICE_1014026A = 0x1014026A,
    SUBDEVICE_109F315D = 0x109F315D,
    SUBDEVICE_109F3181 = 0x109F3181,
    SUBDEVICE_1179FF01 = 0x1179FF01,
    SUBDEVICE_11867801 = 0x11867801,
    SUBDEVICE_144D2602 = 0x144D2602,
    SUBDEVICE_1AF41100 = 0x1AF41100,
    SUBDEVICE_80863010 = 0x80863010,
    SUBDEVICE_80863011 = 0x80863011,
    SUBDEVICE_80863012 = 0x80863012,
    SUBDEVICE_80863013 = 0x80863013,
    SUBDEVICE_80863014 = 0x80863014,
    SUBDEVICE_80863015 = 0x80863015,
    SUBDEVICE_80863016 = 0x80863016,
    SUBDEVICE_80863017 = 0x80863017,
    SUBDEVICE_80863018 = 0x80863018
};



inline const char8* enumToString(PciSubDevice80862449 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862449::NONE:               return "NONE";
        case PciSubDevice80862449::SUBDEVICE_0E110012: return "SUBDEVICE_0E110012";
        case PciSubDevice80862449::SUBDEVICE_0E110091: return "SUBDEVICE_0E110091";
        case PciSubDevice80862449::SUBDEVICE_101401CE: return "SUBDEVICE_101401CE";
        case PciSubDevice80862449::SUBDEVICE_101401DC: return "SUBDEVICE_101401DC";
        case PciSubDevice80862449::SUBDEVICE_101401EB: return "SUBDEVICE_101401EB";
        case PciSubDevice80862449::SUBDEVICE_101401EC: return "SUBDEVICE_101401EC";
        case PciSubDevice80862449::SUBDEVICE_10140202: return "SUBDEVICE_10140202";
        case PciSubDevice80862449::SUBDEVICE_10140205: return "SUBDEVICE_10140205";
        case PciSubDevice80862449::SUBDEVICE_10140217: return "SUBDEVICE_10140217";
        case PciSubDevice80862449::SUBDEVICE_10140234: return "SUBDEVICE_10140234";
        case PciSubDevice80862449::SUBDEVICE_1014023D: return "SUBDEVICE_1014023D";
        case PciSubDevice80862449::SUBDEVICE_10140244: return "SUBDEVICE_10140244";
        case PciSubDevice80862449::SUBDEVICE_10140245: return "SUBDEVICE_10140245";
        case PciSubDevice80862449::SUBDEVICE_10140265: return "SUBDEVICE_10140265";
        case PciSubDevice80862449::SUBDEVICE_10140267: return "SUBDEVICE_10140267";
        case PciSubDevice80862449::SUBDEVICE_1014026A: return "SUBDEVICE_1014026A";
        case PciSubDevice80862449::SUBDEVICE_109F315D: return "SUBDEVICE_109F315D";
        case PciSubDevice80862449::SUBDEVICE_109F3181: return "SUBDEVICE_109F3181";
        case PciSubDevice80862449::SUBDEVICE_1179FF01: return "SUBDEVICE_1179FF01";
        case PciSubDevice80862449::SUBDEVICE_11867801: return "SUBDEVICE_11867801";
        case PciSubDevice80862449::SUBDEVICE_144D2602: return "SUBDEVICE_144D2602";
        case PciSubDevice80862449::SUBDEVICE_1AF41100: return "SUBDEVICE_1AF41100";
        case PciSubDevice80862449::SUBDEVICE_80863010: return "SUBDEVICE_80863010";
        case PciSubDevice80862449::SUBDEVICE_80863011: return "SUBDEVICE_80863011";
        case PciSubDevice80862449::SUBDEVICE_80863012: return "SUBDEVICE_80863012";
        case PciSubDevice80862449::SUBDEVICE_80863013: return "SUBDEVICE_80863013";
        case PciSubDevice80862449::SUBDEVICE_80863014: return "SUBDEVICE_80863014";
        case PciSubDevice80862449::SUBDEVICE_80863015: return "SUBDEVICE_80863015";
        case PciSubDevice80862449::SUBDEVICE_80863016: return "SUBDEVICE_80863016";
        case PciSubDevice80862449::SUBDEVICE_80863017: return "SUBDEVICE_80863017";
        case PciSubDevice80862449::SUBDEVICE_80863018: return "SUBDEVICE_80863018";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862449 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862449 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862449::SUBDEVICE_0E110012: return "EtherExpress PRO/100 VM";
        case PciSubDevice80862449::SUBDEVICE_0E110091: return "EtherExpress PRO/100 VE";
        case PciSubDevice80862449::SUBDEVICE_101401CE: return "EtherExpress PRO/100 VE";
        case PciSubDevice80862449::SUBDEVICE_101401DC: return "EtherExpress PRO/100 VE";
        case PciSubDevice80862449::SUBDEVICE_101401EB: return "EtherExpress PRO/100 VE";
        case PciSubDevice80862449::SUBDEVICE_101401EC: return "EtherExpress PRO/100 VE";
        case PciSubDevice80862449::SUBDEVICE_10140202: return "EtherExpress PRO/100 VE";
        case PciSubDevice80862449::SUBDEVICE_10140205: return "EtherExpress PRO/100 VE";
        case PciSubDevice80862449::SUBDEVICE_10140217: return "EtherExpress PRO/100 VE";
        case PciSubDevice80862449::SUBDEVICE_10140234: return "EtherExpress PRO/100 VE";
        case PciSubDevice80862449::SUBDEVICE_1014023D: return "EtherExpress PRO/100 VE";
        case PciSubDevice80862449::SUBDEVICE_10140244: return "EtherExpress PRO/100 VE";
        case PciSubDevice80862449::SUBDEVICE_10140245: return "EtherExpress PRO/100 VE";
        case PciSubDevice80862449::SUBDEVICE_10140265: return "PRO/100 VE Desktop Connection";
        case PciSubDevice80862449::SUBDEVICE_10140267: return "PRO/100 VE Desktop Connection";
        case PciSubDevice80862449::SUBDEVICE_1014026A: return "PRO/100 VE Desktop Connection";
        case PciSubDevice80862449::SUBDEVICE_109F315D: return "EtherExpress PRO/100 VE";
        case PciSubDevice80862449::SUBDEVICE_109F3181: return "EtherExpress PRO/100 VE";
        case PciSubDevice80862449::SUBDEVICE_1179FF01: return "PRO/100 VE Network Connection";
        case PciSubDevice80862449::SUBDEVICE_11867801: return "EtherExpress PRO/100 VE";
        case PciSubDevice80862449::SUBDEVICE_144D2602: return "HomePNA 1M CNR";
        case PciSubDevice80862449::SUBDEVICE_1AF41100: return "QEMU Virtual Machine";
        case PciSubDevice80862449::SUBDEVICE_80863010: return "EtherExpress PRO/100 VE";
        case PciSubDevice80862449::SUBDEVICE_80863011: return "EtherExpress PRO/100 VM";
        case PciSubDevice80862449::SUBDEVICE_80863012: return "82562EH based Phoneline";
        case PciSubDevice80862449::SUBDEVICE_80863013: return "EtherExpress PRO/100 VE";
        case PciSubDevice80862449::SUBDEVICE_80863014: return "EtherExpress PRO/100 VM";
        case PciSubDevice80862449::SUBDEVICE_80863015: return "82562EH based Phoneline";
        case PciSubDevice80862449::SUBDEVICE_80863016: return "EtherExpress PRO/100 P Mobile Combo";
        case PciSubDevice80862449::SUBDEVICE_80863017: return "EtherExpress PRO/100 P Mobile";
        case PciSubDevice80862449::SUBDEVICE_80863018: return "EtherExpress PRO/100";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862449_H
