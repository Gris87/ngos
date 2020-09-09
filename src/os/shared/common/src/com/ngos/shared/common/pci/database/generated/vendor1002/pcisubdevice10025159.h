// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025159_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025159_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10025159: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1002000A = 0x1002000A,
    SUBDEVICE_1002000B = 0x1002000B,
    SUBDEVICE_10020038 = 0x10020038,
    SUBDEVICE_1002003A = 0x1002003A,
    SUBDEVICE_100200BA = 0x100200BA,
    SUBDEVICE_1002013A = 0x1002013A,
    SUBDEVICE_10020908 = 0x10020908,
    SUBDEVICE_1014029A = 0x1014029A,
    SUBDEVICE_101402C8 = 0x101402C8,
    SUBDEVICE_1028016C = 0x1028016C,
    SUBDEVICE_1028016D = 0x1028016D,
    SUBDEVICE_10280170 = 0x10280170,
    SUBDEVICE_1028019A = 0x1028019A,
    SUBDEVICE_103C1292 = 0x103C1292,
    SUBDEVICE_1043C00A = 0x1043C00A,
    SUBDEVICE_14584002 = 0x14584002,
    SUBDEVICE_148C2003 = 0x148C2003,
    SUBDEVICE_148C2023 = 0x148C2023,
    SUBDEVICE_148C2081 = 0x148C2081,
    SUBDEVICE_174B0280 = 0x174B0280,
    SUBDEVICE_174B7112 = 0x174B7112,
    SUBDEVICE_174B7C28 = 0x174B7C28,
    SUBDEVICE_17870202 = 0x17870202,
    SUBDEVICE_17EE1001 = 0x17EE1001
};



inline const char8* enumToString(PciSubDevice10025159 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025159::NONE:               return "NONE";
        case PciSubDevice10025159::SUBDEVICE_1002000A: return "SUBDEVICE_1002000A";
        case PciSubDevice10025159::SUBDEVICE_1002000B: return "SUBDEVICE_1002000B";
        case PciSubDevice10025159::SUBDEVICE_10020038: return "SUBDEVICE_10020038";
        case PciSubDevice10025159::SUBDEVICE_1002003A: return "SUBDEVICE_1002003A";
        case PciSubDevice10025159::SUBDEVICE_100200BA: return "SUBDEVICE_100200BA";
        case PciSubDevice10025159::SUBDEVICE_1002013A: return "SUBDEVICE_1002013A";
        case PciSubDevice10025159::SUBDEVICE_10020908: return "SUBDEVICE_10020908";
        case PciSubDevice10025159::SUBDEVICE_1014029A: return "SUBDEVICE_1014029A";
        case PciSubDevice10025159::SUBDEVICE_101402C8: return "SUBDEVICE_101402C8";
        case PciSubDevice10025159::SUBDEVICE_1028016C: return "SUBDEVICE_1028016C";
        case PciSubDevice10025159::SUBDEVICE_1028016D: return "SUBDEVICE_1028016D";
        case PciSubDevice10025159::SUBDEVICE_10280170: return "SUBDEVICE_10280170";
        case PciSubDevice10025159::SUBDEVICE_1028019A: return "SUBDEVICE_1028019A";
        case PciSubDevice10025159::SUBDEVICE_103C1292: return "SUBDEVICE_103C1292";
        case PciSubDevice10025159::SUBDEVICE_1043C00A: return "SUBDEVICE_1043C00A";
        case PciSubDevice10025159::SUBDEVICE_14584002: return "SUBDEVICE_14584002";
        case PciSubDevice10025159::SUBDEVICE_148C2003: return "SUBDEVICE_148C2003";
        case PciSubDevice10025159::SUBDEVICE_148C2023: return "SUBDEVICE_148C2023";
        case PciSubDevice10025159::SUBDEVICE_148C2081: return "SUBDEVICE_148C2081";
        case PciSubDevice10025159::SUBDEVICE_174B0280: return "SUBDEVICE_174B0280";
        case PciSubDevice10025159::SUBDEVICE_174B7112: return "SUBDEVICE_174B7112";
        case PciSubDevice10025159::SUBDEVICE_174B7C28: return "SUBDEVICE_174B7C28";
        case PciSubDevice10025159::SUBDEVICE_17870202: return "SUBDEVICE_17870202";
        case PciSubDevice10025159::SUBDEVICE_17EE1001: return "SUBDEVICE_17EE1001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10025159 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10025159 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025159::SUBDEVICE_1002000A: return "Radeon 7000/Radeon VE";
        case PciSubDevice10025159::SUBDEVICE_1002000B: return "Radeon 7000";
        case PciSubDevice10025159::SUBDEVICE_10020038: return "Radeon 7000/Radeon VE";
        case PciSubDevice10025159::SUBDEVICE_1002003A: return "Radeon 7000/Radeon VE";
        case PciSubDevice10025159::SUBDEVICE_100200BA: return "Radeon 7000/Radeon VE";
        case PciSubDevice10025159::SUBDEVICE_1002013A: return "Radeon 7000/Radeon VE";
        case PciSubDevice10025159::SUBDEVICE_10020908: return "XVR-100 (supplied by Sun)";
        case PciSubDevice10025159::SUBDEVICE_1014029A: return "Remote Supervisor Adapter II (RSA2)";
        case PciSubDevice10025159::SUBDEVICE_101402C8: return "eServer xSeries server mainboard";
        case PciSubDevice10025159::SUBDEVICE_1028016C: return "PowerEdge 1850 Embedded Radeon 7000/VE";
        case PciSubDevice10025159::SUBDEVICE_1028016D: return "PowerEdge 2850 Embedded Radeon 7000-M";
        case PciSubDevice10025159::SUBDEVICE_10280170: return "PowerEdge 6850 Embedded Radeon 7000/VE";
        case PciSubDevice10025159::SUBDEVICE_1028019A: return "PowerEdge SC1425";
        case PciSubDevice10025159::SUBDEVICE_103C1292: return "Radeon 7000";
        case PciSubDevice10025159::SUBDEVICE_1043C00A: return "A7000/T/64M";
        case PciSubDevice10025159::SUBDEVICE_14584002: return "RV100 QY [RADEON 7000 PRO MAYA AV Series]";
        case PciSubDevice10025159::SUBDEVICE_148C2003: return "RV100 QY [Radeon 7000 Multi-Display Edition]";
        case PciSubDevice10025159::SUBDEVICE_148C2023: return "RV100 QY [Radeon 7000 Evil Master Multi-Display]";
        case PciSubDevice10025159::SUBDEVICE_148C2081: return "RV6DE";
        case PciSubDevice10025159::SUBDEVICE_174B0280: return "Radeon RV100 QY [Radeon 7000/VE]";
        case PciSubDevice10025159::SUBDEVICE_174B7112: return "Radeon VE 7000";
        case PciSubDevice10025159::SUBDEVICE_174B7C28: return "Radeon VE 7000 DDR";
        case PciSubDevice10025159::SUBDEVICE_17870202: return "RV100 QY [Excalibur Radeon 7000]";
        case PciSubDevice10025159::SUBDEVICE_17EE1001: return "Radeon 7000 64MB DDR + DVI";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025159_H
