// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1415_PCIDEVICE1415_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1415_PCIDEVICE1415_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1415/pcisubdevice14159501.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1415/pcisubdevice14159510.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1415/pcisubdevice14159511.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1415/pcisubdevice1415c158.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1415: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8401 = 0x8401,
    DEVICE_8403 = 0x8403,
    DEVICE_9500 = 0x9500,
    DEVICE_9501 = 0x9501,
    DEVICE_9505 = 0x9505,
    DEVICE_950A = 0x950A,
    DEVICE_950B = 0x950B,
    DEVICE_9510 = 0x9510,
    DEVICE_9511 = 0x9511,
    DEVICE_9512 = 0x9512,
    DEVICE_9513 = 0x9513,
    DEVICE_9521 = 0x9521,
    DEVICE_9523 = 0x9523,
    DEVICE_C000 = 0xC000,
    DEVICE_C004 = 0xC004,
    DEVICE_C006 = 0xC006,
    DEVICE_C100 = 0xC100,
    DEVICE_C101 = 0xC101,
    DEVICE_C104 = 0xC104,
    DEVICE_C105 = 0xC105,
    DEVICE_C106 = 0xC106,
    DEVICE_C108 = 0xC108,
    DEVICE_C109 = 0xC109,
    DEVICE_C10C = 0xC10C,
    DEVICE_C10D = 0xC10D,
    DEVICE_C10E = 0xC10E,
    DEVICE_C110 = 0xC110,
    DEVICE_C114 = 0xC114,
    DEVICE_C118 = 0xC118,
    DEVICE_C11B = 0xC11B,
    DEVICE_C11C = 0xC11C,
    DEVICE_C11E = 0xC11E,
    DEVICE_C11F = 0xC11F,
    DEVICE_C120 = 0xC120,
    DEVICE_C124 = 0xC124,
    DEVICE_C126 = 0xC126,
    DEVICE_C128 = 0xC128,
    DEVICE_C12C = 0xC12C,
    DEVICE_C12E = 0xC12E,
    DEVICE_C134 = 0xC134,
    DEVICE_C138 = 0xC138,
    DEVICE_C13C = 0xC13C,
    DEVICE_C13D = 0xC13D,
    DEVICE_C140 = 0xC140,
    DEVICE_C141 = 0xC141,
    DEVICE_C144 = 0xC144,
    DEVICE_C145 = 0xC145,
    DEVICE_C146 = 0xC146,
    DEVICE_C148 = 0xC148,
    DEVICE_C149 = 0xC149,
    DEVICE_C14C = 0xC14C,
    DEVICE_C14D = 0xC14D,
    DEVICE_C14E = 0xC14E,
    DEVICE_C154 = 0xC154,
    DEVICE_C158 = 0xC158,
    DEVICE_C15C = 0xC15C,
    DEVICE_C15D = 0xC15D,
    DEVICE_C204 = 0xC204,
    DEVICE_C208 = 0xC208,
    DEVICE_C20C = 0xC20C,
    DEVICE_C20D = 0xC20D,
    DEVICE_C304 = 0xC304,
    DEVICE_C308 = 0xC308,
    DEVICE_C30C = 0xC30C,
    DEVICE_C30D = 0xC30D,
    DEVICE_C530 = 0xC530,
    DEVICE_C531 = 0xC531,
    DEVICE_C534 = 0xC534,
    DEVICE_C535 = 0xC535,
    DEVICE_C536 = 0xC536,
    DEVICE_C538 = 0xC538,
    DEVICE_C539 = 0xC539,
    DEVICE_C53B = 0xC53B,
    DEVICE_C53C = 0xC53C,
    DEVICE_C53D = 0xC53D,
    DEVICE_C53E = 0xC53E,
    DEVICE_C53F = 0xC53F,
    DEVICE_C540 = 0xC540,
    DEVICE_C541 = 0xC541,
    DEVICE_C544 = 0xC544,
    DEVICE_C545 = 0xC545,
    DEVICE_C546 = 0xC546,
    DEVICE_C548 = 0xC548,
    DEVICE_C549 = 0xC549,
    DEVICE_C54B = 0xC54B,
    DEVICE_C54C = 0xC54C,
    DEVICE_C54D = 0xC54D,
    DEVICE_C54E = 0xC54E,
    DEVICE_C54F = 0xC54F,
    DEVICE_C560 = 0xC560,
    DEVICE_C561 = 0xC561,
    DEVICE_C564 = 0xC564,
    DEVICE_C565 = 0xC565,
    DEVICE_C566 = 0xC566,
    DEVICE_C568 = 0xC568,
    DEVICE_C569 = 0xC569,
    DEVICE_C56B = 0xC56B,
    DEVICE_C56C = 0xC56C,
    DEVICE_C56D = 0xC56D,
    DEVICE_C56E = 0xC56E,
    DEVICE_C56F = 0xC56F,
    DEVICE_C570 = 0xC570,
    DEVICE_C571 = 0xC571,
    DEVICE_C574 = 0xC574,
    DEVICE_C575 = 0xC575,
    DEVICE_C576 = 0xC576,
    DEVICE_C578 = 0xC578,
    DEVICE_C579 = 0xC579,
    DEVICE_C57B = 0xC57B,
    DEVICE_C57C = 0xC57C,
    DEVICE_C57D = 0xC57D,
    DEVICE_C57E = 0xC57E,
    DEVICE_C57F = 0xC57F,
    DEVICE_C5A0 = 0xC5A0,
    DEVICE_C5A1 = 0xC5A1,
    DEVICE_C5A2 = 0xC5A2,
    DEVICE_C5A4 = 0xC5A4,
    DEVICE_C5A5 = 0xC5A5,
    DEVICE_C5A6 = 0xC5A6,
    DEVICE_C5A8 = 0xC5A8,
    DEVICE_C5A9 = 0xC5A9,
    DEVICE_C5AA = 0xC5AA,
    DEVICE_C5AB = 0xC5AB,
    DEVICE_C5AC = 0xC5AC,
    DEVICE_C5AD = 0xC5AD,
    DEVICE_C5AE = 0xC5AE,
    DEVICE_C5AF = 0xC5AF,
    DEVICE_C5B0 = 0xC5B0,
    DEVICE_C5B1 = 0xC5B1,
    DEVICE_C5B2 = 0xC5B2,
    DEVICE_C5B4 = 0xC5B4,
    DEVICE_C5B5 = 0xC5B5,
    DEVICE_C5B6 = 0xC5B6,
    DEVICE_C5B8 = 0xC5B8,
    DEVICE_C5B9 = 0xC5B9,
    DEVICE_C5BA = 0xC5BA,
    DEVICE_C5BB = 0xC5BB,
    DEVICE_C5BC = 0xC5BC,
    DEVICE_C5BD = 0xC5BD,
    DEVICE_C5BE = 0xC5BE,
    DEVICE_C5BF = 0xC5BF,
    DEVICE_C5C0 = 0xC5C0,
    DEVICE_C5C2 = 0xC5C2,
    DEVICE_C5C4 = 0xC5C4,
    DEVICE_C5C6 = 0xC5C6,
    DEVICE_C5C8 = 0xC5C8,
    DEVICE_C5CA = 0xC5CA,
    DEVICE_C5CB = 0xC5CB,
    DEVICE_C5CC = 0xC5CC,
    DEVICE_C5CE = 0xC5CE,
    DEVICE_C5CF = 0xC5CF
};



inline const char8* enumToString(PciDevice1415 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1415::NONE:        return "NONE";
        case PciDevice1415::DEVICE_8401: return "DEVICE_8401";
        case PciDevice1415::DEVICE_8403: return "DEVICE_8403";
        case PciDevice1415::DEVICE_9500: return "DEVICE_9500";
        case PciDevice1415::DEVICE_9501: return "DEVICE_9501";
        case PciDevice1415::DEVICE_9505: return "DEVICE_9505";
        case PciDevice1415::DEVICE_950A: return "DEVICE_950A";
        case PciDevice1415::DEVICE_950B: return "DEVICE_950B";
        case PciDevice1415::DEVICE_9510: return "DEVICE_9510";
        case PciDevice1415::DEVICE_9511: return "DEVICE_9511";
        case PciDevice1415::DEVICE_9512: return "DEVICE_9512";
        case PciDevice1415::DEVICE_9513: return "DEVICE_9513";
        case PciDevice1415::DEVICE_9521: return "DEVICE_9521";
        case PciDevice1415::DEVICE_9523: return "DEVICE_9523";
        case PciDevice1415::DEVICE_C000: return "DEVICE_C000";
        case PciDevice1415::DEVICE_C004: return "DEVICE_C004";
        case PciDevice1415::DEVICE_C006: return "DEVICE_C006";
        case PciDevice1415::DEVICE_C100: return "DEVICE_C100";
        case PciDevice1415::DEVICE_C101: return "DEVICE_C101";
        case PciDevice1415::DEVICE_C104: return "DEVICE_C104";
        case PciDevice1415::DEVICE_C105: return "DEVICE_C105";
        case PciDevice1415::DEVICE_C106: return "DEVICE_C106";
        case PciDevice1415::DEVICE_C108: return "DEVICE_C108";
        case PciDevice1415::DEVICE_C109: return "DEVICE_C109";
        case PciDevice1415::DEVICE_C10C: return "DEVICE_C10C";
        case PciDevice1415::DEVICE_C10D: return "DEVICE_C10D";
        case PciDevice1415::DEVICE_C10E: return "DEVICE_C10E";
        case PciDevice1415::DEVICE_C110: return "DEVICE_C110";
        case PciDevice1415::DEVICE_C114: return "DEVICE_C114";
        case PciDevice1415::DEVICE_C118: return "DEVICE_C118";
        case PciDevice1415::DEVICE_C11B: return "DEVICE_C11B";
        case PciDevice1415::DEVICE_C11C: return "DEVICE_C11C";
        case PciDevice1415::DEVICE_C11E: return "DEVICE_C11E";
        case PciDevice1415::DEVICE_C11F: return "DEVICE_C11F";
        case PciDevice1415::DEVICE_C120: return "DEVICE_C120";
        case PciDevice1415::DEVICE_C124: return "DEVICE_C124";
        case PciDevice1415::DEVICE_C126: return "DEVICE_C126";
        case PciDevice1415::DEVICE_C128: return "DEVICE_C128";
        case PciDevice1415::DEVICE_C12C: return "DEVICE_C12C";
        case PciDevice1415::DEVICE_C12E: return "DEVICE_C12E";
        case PciDevice1415::DEVICE_C134: return "DEVICE_C134";
        case PciDevice1415::DEVICE_C138: return "DEVICE_C138";
        case PciDevice1415::DEVICE_C13C: return "DEVICE_C13C";
        case PciDevice1415::DEVICE_C13D: return "DEVICE_C13D";
        case PciDevice1415::DEVICE_C140: return "DEVICE_C140";
        case PciDevice1415::DEVICE_C141: return "DEVICE_C141";
        case PciDevice1415::DEVICE_C144: return "DEVICE_C144";
        case PciDevice1415::DEVICE_C145: return "DEVICE_C145";
        case PciDevice1415::DEVICE_C146: return "DEVICE_C146";
        case PciDevice1415::DEVICE_C148: return "DEVICE_C148";
        case PciDevice1415::DEVICE_C149: return "DEVICE_C149";
        case PciDevice1415::DEVICE_C14C: return "DEVICE_C14C";
        case PciDevice1415::DEVICE_C14D: return "DEVICE_C14D";
        case PciDevice1415::DEVICE_C14E: return "DEVICE_C14E";
        case PciDevice1415::DEVICE_C154: return "DEVICE_C154";
        case PciDevice1415::DEVICE_C158: return "DEVICE_C158";
        case PciDevice1415::DEVICE_C15C: return "DEVICE_C15C";
        case PciDevice1415::DEVICE_C15D: return "DEVICE_C15D";
        case PciDevice1415::DEVICE_C204: return "DEVICE_C204";
        case PciDevice1415::DEVICE_C208: return "DEVICE_C208";
        case PciDevice1415::DEVICE_C20C: return "DEVICE_C20C";
        case PciDevice1415::DEVICE_C20D: return "DEVICE_C20D";
        case PciDevice1415::DEVICE_C304: return "DEVICE_C304";
        case PciDevice1415::DEVICE_C308: return "DEVICE_C308";
        case PciDevice1415::DEVICE_C30C: return "DEVICE_C30C";
        case PciDevice1415::DEVICE_C30D: return "DEVICE_C30D";
        case PciDevice1415::DEVICE_C530: return "DEVICE_C530";
        case PciDevice1415::DEVICE_C531: return "DEVICE_C531";
        case PciDevice1415::DEVICE_C534: return "DEVICE_C534";
        case PciDevice1415::DEVICE_C535: return "DEVICE_C535";
        case PciDevice1415::DEVICE_C536: return "DEVICE_C536";
        case PciDevice1415::DEVICE_C538: return "DEVICE_C538";
        case PciDevice1415::DEVICE_C539: return "DEVICE_C539";
        case PciDevice1415::DEVICE_C53B: return "DEVICE_C53B";
        case PciDevice1415::DEVICE_C53C: return "DEVICE_C53C";
        case PciDevice1415::DEVICE_C53D: return "DEVICE_C53D";
        case PciDevice1415::DEVICE_C53E: return "DEVICE_C53E";
        case PciDevice1415::DEVICE_C53F: return "DEVICE_C53F";
        case PciDevice1415::DEVICE_C540: return "DEVICE_C540";
        case PciDevice1415::DEVICE_C541: return "DEVICE_C541";
        case PciDevice1415::DEVICE_C544: return "DEVICE_C544";
        case PciDevice1415::DEVICE_C545: return "DEVICE_C545";
        case PciDevice1415::DEVICE_C546: return "DEVICE_C546";
        case PciDevice1415::DEVICE_C548: return "DEVICE_C548";
        case PciDevice1415::DEVICE_C549: return "DEVICE_C549";
        case PciDevice1415::DEVICE_C54B: return "DEVICE_C54B";
        case PciDevice1415::DEVICE_C54C: return "DEVICE_C54C";
        case PciDevice1415::DEVICE_C54D: return "DEVICE_C54D";
        case PciDevice1415::DEVICE_C54E: return "DEVICE_C54E";
        case PciDevice1415::DEVICE_C54F: return "DEVICE_C54F";
        case PciDevice1415::DEVICE_C560: return "DEVICE_C560";
        case PciDevice1415::DEVICE_C561: return "DEVICE_C561";
        case PciDevice1415::DEVICE_C564: return "DEVICE_C564";
        case PciDevice1415::DEVICE_C565: return "DEVICE_C565";
        case PciDevice1415::DEVICE_C566: return "DEVICE_C566";
        case PciDevice1415::DEVICE_C568: return "DEVICE_C568";
        case PciDevice1415::DEVICE_C569: return "DEVICE_C569";
        case PciDevice1415::DEVICE_C56B: return "DEVICE_C56B";
        case PciDevice1415::DEVICE_C56C: return "DEVICE_C56C";
        case PciDevice1415::DEVICE_C56D: return "DEVICE_C56D";
        case PciDevice1415::DEVICE_C56E: return "DEVICE_C56E";
        case PciDevice1415::DEVICE_C56F: return "DEVICE_C56F";
        case PciDevice1415::DEVICE_C570: return "DEVICE_C570";
        case PciDevice1415::DEVICE_C571: return "DEVICE_C571";
        case PciDevice1415::DEVICE_C574: return "DEVICE_C574";
        case PciDevice1415::DEVICE_C575: return "DEVICE_C575";
        case PciDevice1415::DEVICE_C576: return "DEVICE_C576";
        case PciDevice1415::DEVICE_C578: return "DEVICE_C578";
        case PciDevice1415::DEVICE_C579: return "DEVICE_C579";
        case PciDevice1415::DEVICE_C57B: return "DEVICE_C57B";
        case PciDevice1415::DEVICE_C57C: return "DEVICE_C57C";
        case PciDevice1415::DEVICE_C57D: return "DEVICE_C57D";
        case PciDevice1415::DEVICE_C57E: return "DEVICE_C57E";
        case PciDevice1415::DEVICE_C57F: return "DEVICE_C57F";
        case PciDevice1415::DEVICE_C5A0: return "DEVICE_C5A0";
        case PciDevice1415::DEVICE_C5A1: return "DEVICE_C5A1";
        case PciDevice1415::DEVICE_C5A2: return "DEVICE_C5A2";
        case PciDevice1415::DEVICE_C5A4: return "DEVICE_C5A4";
        case PciDevice1415::DEVICE_C5A5: return "DEVICE_C5A5";
        case PciDevice1415::DEVICE_C5A6: return "DEVICE_C5A6";
        case PciDevice1415::DEVICE_C5A8: return "DEVICE_C5A8";
        case PciDevice1415::DEVICE_C5A9: return "DEVICE_C5A9";
        case PciDevice1415::DEVICE_C5AA: return "DEVICE_C5AA";
        case PciDevice1415::DEVICE_C5AB: return "DEVICE_C5AB";
        case PciDevice1415::DEVICE_C5AC: return "DEVICE_C5AC";
        case PciDevice1415::DEVICE_C5AD: return "DEVICE_C5AD";
        case PciDevice1415::DEVICE_C5AE: return "DEVICE_C5AE";
        case PciDevice1415::DEVICE_C5AF: return "DEVICE_C5AF";
        case PciDevice1415::DEVICE_C5B0: return "DEVICE_C5B0";
        case PciDevice1415::DEVICE_C5B1: return "DEVICE_C5B1";
        case PciDevice1415::DEVICE_C5B2: return "DEVICE_C5B2";
        case PciDevice1415::DEVICE_C5B4: return "DEVICE_C5B4";
        case PciDevice1415::DEVICE_C5B5: return "DEVICE_C5B5";
        case PciDevice1415::DEVICE_C5B6: return "DEVICE_C5B6";
        case PciDevice1415::DEVICE_C5B8: return "DEVICE_C5B8";
        case PciDevice1415::DEVICE_C5B9: return "DEVICE_C5B9";
        case PciDevice1415::DEVICE_C5BA: return "DEVICE_C5BA";
        case PciDevice1415::DEVICE_C5BB: return "DEVICE_C5BB";
        case PciDevice1415::DEVICE_C5BC: return "DEVICE_C5BC";
        case PciDevice1415::DEVICE_C5BD: return "DEVICE_C5BD";
        case PciDevice1415::DEVICE_C5BE: return "DEVICE_C5BE";
        case PciDevice1415::DEVICE_C5BF: return "DEVICE_C5BF";
        case PciDevice1415::DEVICE_C5C0: return "DEVICE_C5C0";
        case PciDevice1415::DEVICE_C5C2: return "DEVICE_C5C2";
        case PciDevice1415::DEVICE_C5C4: return "DEVICE_C5C4";
        case PciDevice1415::DEVICE_C5C6: return "DEVICE_C5C6";
        case PciDevice1415::DEVICE_C5C8: return "DEVICE_C5C8";
        case PciDevice1415::DEVICE_C5CA: return "DEVICE_C5CA";
        case PciDevice1415::DEVICE_C5CB: return "DEVICE_C5CB";
        case PciDevice1415::DEVICE_C5CC: return "DEVICE_C5CC";
        case PciDevice1415::DEVICE_C5CE: return "DEVICE_C5CE";
        case PciDevice1415::DEVICE_C5CF: return "DEVICE_C5CF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1415 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1415 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1415::DEVICE_8401: return "OX9162 Mode 1 (8-bit bus)";
        case PciDevice1415::DEVICE_8403: return "OX9162 Mode 0 (parallel port)";
        case PciDevice1415::DEVICE_9500: return "OX16PCI954 (Quad 16950 UART) function 0 (Disabled)";
        case PciDevice1415::DEVICE_9501: return "OX16PCI954 (Quad 16950 UART) function 0 (Uart)";
        case PciDevice1415::DEVICE_9505: return "OXuPCI952 (Dual 16C950 UART)";
        case PciDevice1415::DEVICE_950A: return "EXSYS EX-41092 Dual 16950 Serial adapter";
        case PciDevice1415::DEVICE_950B: return "OXCB950 Cardbus 16950 UART";
        case PciDevice1415::DEVICE_9510: return "OX16PCI954 (Quad 16950 UART) function 1 (Disabled)";
        case PciDevice1415::DEVICE_9511: return "OX16PCI954 (Quad 16950 UART) function 1 (8bit bus)";
        case PciDevice1415::DEVICE_9512: return "OX16PCI954 (Quad 16950 UART) function 1 (32bit bus)";
        case PciDevice1415::DEVICE_9513: return "OX16PCI954 (Quad 16950 UART) function 1 (parallel port)";
        case PciDevice1415::DEVICE_9521: return "OX16PCI952 (Dual 16950 UART)";
        case PciDevice1415::DEVICE_9523: return "OX16PCI952 Integrated Parallel Port";
        case PciDevice1415::DEVICE_C000: return "OXPCIe840 Parallel Port";
        case PciDevice1415::DEVICE_C004: return "OXPCIe840 Parallel Port";
        case PciDevice1415::DEVICE_C006: return "OXPCIe840 GPIO";
        case PciDevice1415::DEVICE_C100: return "OXPCIe952 Parallel Port";
        case PciDevice1415::DEVICE_C101: return "OXPCIe952 Legacy 950 UART";
        case PciDevice1415::DEVICE_C104: return "OXPCIe952 Parallel Port";
        case PciDevice1415::DEVICE_C105: return "OXPCIe952 Legacy 950 UART";
        case PciDevice1415::DEVICE_C106: return "OXPCIe952 GPIO";
        case PciDevice1415::DEVICE_C108: return "OXPCIe952 Parallel Port";
        case PciDevice1415::DEVICE_C109: return "OXPCIe952 Legacy 950 UART";
        case PciDevice1415::DEVICE_C10C: return "OXPCIe952 Parallel Port";
        case PciDevice1415::DEVICE_C10D: return "OXPCIe952 Legacy 950 UART";
        case PciDevice1415::DEVICE_C10E: return "OXPCIe952 GPIO";
        case PciDevice1415::DEVICE_C110: return "OXPCIe952 Parallel Port";
        case PciDevice1415::DEVICE_C114: return "OXPCIe952 Parallel Port";
        case PciDevice1415::DEVICE_C118: return "OXPCIe952 Parallel Port";
        case PciDevice1415::DEVICE_C11B: return "OXPCIe952 Native 950 UART";
        case PciDevice1415::DEVICE_C11C: return "OXPCIe952 Parallel Port";
        case PciDevice1415::DEVICE_C11E: return "OXPCIe952 GPIO";
        case PciDevice1415::DEVICE_C11F: return "OXPCIe952 Native 950 UART";
        case PciDevice1415::DEVICE_C120: return "OXPCIe952 Legacy 950 UART";
        case PciDevice1415::DEVICE_C124: return "OXPCIe952 Legacy 950 UART";
        case PciDevice1415::DEVICE_C126: return "OXPCIe952 GPIO";
        case PciDevice1415::DEVICE_C128: return "OXPCIe952 Legacy 950 UART";
        case PciDevice1415::DEVICE_C12C: return "OXPCIe952 Legacy 950 UART";
        case PciDevice1415::DEVICE_C12E: return "OXPCIe952 GPIO";
        case PciDevice1415::DEVICE_C134: return "OXPCIe952 GPIO";
        case PciDevice1415::DEVICE_C138: return "OXPCIe952 Native 950 UART";
        case PciDevice1415::DEVICE_C13C: return "OXPCIe952 GPIO";
        case PciDevice1415::DEVICE_C13D: return "OXPCIe952 Native 950 UART";
        case PciDevice1415::DEVICE_C140: return "OXPCIe952 Legacy 950 UART #1";
        case PciDevice1415::DEVICE_C141: return "OXPCIe952 Legacy 950 UART #2";
        case PciDevice1415::DEVICE_C144: return "OXPCIe952 Legacy 950 UART #1";
        case PciDevice1415::DEVICE_C145: return "OXPCIe952 Legacy 950 UART #2";
        case PciDevice1415::DEVICE_C146: return "OXPCIe952 GPIO";
        case PciDevice1415::DEVICE_C148: return "OXPCIe952 Legacy 950 UART #1";
        case PciDevice1415::DEVICE_C149: return "OXPCIe952 Legacy 950 UART #2";
        case PciDevice1415::DEVICE_C14C: return "OXPCIe952 Legacy 950 UART #1";
        case PciDevice1415::DEVICE_C14D: return "OXPCIe952 Legacy 950 UART #2";
        case PciDevice1415::DEVICE_C14E: return "OXPCIe952 GPIO";
        case PciDevice1415::DEVICE_C154: return "OXPCIe952 GPIO";
        case PciDevice1415::DEVICE_C158: return "OXPCIe952 Dual Native 950 UART";
        case PciDevice1415::DEVICE_C15C: return "OXPCIe952 GPIO";
        case PciDevice1415::DEVICE_C15D: return "OXPCIe952 Dual Native 950 UART";
        case PciDevice1415::DEVICE_C204: return "OXPCIe954 GPIO";
        case PciDevice1415::DEVICE_C208: return "OXPCIe954 Quad Native 950 UART";
        case PciDevice1415::DEVICE_C20C: return "OXPCIe954 GPIO";
        case PciDevice1415::DEVICE_C20D: return "OXPCIe954 Quad Native 950 UART";
        case PciDevice1415::DEVICE_C304: return "OXPCIe958 GPIO";
        case PciDevice1415::DEVICE_C308: return "OXPCIe958 Quad Native 950 UART";
        case PciDevice1415::DEVICE_C30C: return "OXPCIe958 GPIO";
        case PciDevice1415::DEVICE_C30D: return "OXPCIe958 Quad Native 950 UART";
        case PciDevice1415::DEVICE_C530: return "OXPCIe200 Dual OHCI USB Controller (ULPI/R-ULPI)";
        case PciDevice1415::DEVICE_C531: return "OXPCIe200 Dual EHCI USB Controller (ULPI/R-ULPI)";
        case PciDevice1415::DEVICE_C534: return "OXPCIe200 Dual OHCI USB Controller (ULPI/R-ULPI)";
        case PciDevice1415::DEVICE_C535: return "OXPCIe200 Dual EHCI USB Controller (ULPI/R-ULPI)";
        case PciDevice1415::DEVICE_C536: return "OXPCIe200 GPIO";
        case PciDevice1415::DEVICE_C538: return "OXPCIe200 Dual OHCI USB Controller (ULPI/R-ULPI)";
        case PciDevice1415::DEVICE_C539: return "OXPCIe200 Dual EHCI USB Controller (ULPI/R-ULPI)";
        case PciDevice1415::DEVICE_C53B: return "OXPCIe200 Native 950 UART";
        case PciDevice1415::DEVICE_C53C: return "OXPCIe200 Dual OHCI USB Controller (ULPI/R-ULPI)";
        case PciDevice1415::DEVICE_C53D: return "OXPCIe200 Dual EHCI USB Controller (ULPI/R-ULPI)";
        case PciDevice1415::DEVICE_C53E: return "OXPCIe200 GPIO";
        case PciDevice1415::DEVICE_C53F: return "OXPCIe200 Native 950 UART";
        case PciDevice1415::DEVICE_C540: return "OXPCIe200 Dual OHCI USB Controller (R-ULPI)";
        case PciDevice1415::DEVICE_C541: return "OXPCIe200 Dual EHCI USB Controller (R-ULPI)";
        case PciDevice1415::DEVICE_C544: return "OXPCIe200 Dual OHCI USB Controller (R-ULPI)";
        case PciDevice1415::DEVICE_C545: return "OXPCIe200 Dual EHCI USB Controller (R-ULPI)";
        case PciDevice1415::DEVICE_C546: return "OXPCIe200 GPIO";
        case PciDevice1415::DEVICE_C548: return "OXPCIe200 Dual OHCI USB Controller (R-ULPI)";
        case PciDevice1415::DEVICE_C549: return "OXPCIe200 Dual EHCI USB Controller (R-ULPI)";
        case PciDevice1415::DEVICE_C54B: return "OXPCIe200 Native 950 UART";
        case PciDevice1415::DEVICE_C54C: return "OXPCIe200 Dual OHCI USB Controller (R-ULPI)";
        case PciDevice1415::DEVICE_C54D: return "OXPCIe200 Dual EHCI USB Controller (R-ULPI)";
        case PciDevice1415::DEVICE_C54E: return "OXPCIe200 Dual GPIO";
        case PciDevice1415::DEVICE_C54F: return "OXPCIe200 Native 950 UART";
        case PciDevice1415::DEVICE_C560: return "OXPCIe200 Dual OHCI USB Controller (ULPI/analog)";
        case PciDevice1415::DEVICE_C561: return "OXPCIe200 EHCI USB Controller (ULPI)";
        case PciDevice1415::DEVICE_C564: return "OXPCIe200 Dual OHCI USB Controller (ULPI/analog)";
        case PciDevice1415::DEVICE_C565: return "OXPCIe200 EHCI USB Controller (ULPI)";
        case PciDevice1415::DEVICE_C566: return "OXPCIe200 GPIO";
        case PciDevice1415::DEVICE_C568: return "OXPCIe200 Dual OHCI USB Controller (ULPI/analog)";
        case PciDevice1415::DEVICE_C569: return "OXPCIe200 EHCI USB Controller (ULPI)";
        case PciDevice1415::DEVICE_C56B: return "OXPCIe200 Native 950 UART";
        case PciDevice1415::DEVICE_C56C: return "OXPCIe200 Dual OHCI USB Controller (ULPI/analog)";
        case PciDevice1415::DEVICE_C56D: return "OXPCIe200 EHCI USB Controller (ULPI)";
        case PciDevice1415::DEVICE_C56E: return "OXPCIe200 GPIO";
        case PciDevice1415::DEVICE_C56F: return "OXPCIe200 Native 950 UART";
        case PciDevice1415::DEVICE_C570: return "OXPCIe200 Dual OHCI USB Controller (R-ULPI/analog)";
        case PciDevice1415::DEVICE_C571: return "OXPCIe200 EHCI USB Controller (R-ULPI)";
        case PciDevice1415::DEVICE_C574: return "OXPCIe200 Dual OHCI USB Controller (R-ULPI/analog)";
        case PciDevice1415::DEVICE_C575: return "OXPCIe200 EHCI USB Controller (R-ULPI)";
        case PciDevice1415::DEVICE_C576: return "OXPCIe200 GPIO";
        case PciDevice1415::DEVICE_C578: return "OXPCIe200 Dual OHCI USB Controller (R-ULPI/analog)";
        case PciDevice1415::DEVICE_C579: return "OXPCIe200 EHCI USB Controller (R-ULPI)";
        case PciDevice1415::DEVICE_C57B: return "OXPCIe200 Native 950 UART";
        case PciDevice1415::DEVICE_C57C: return "OXPCIe200 Dual OHCI USB Controller (R-ULPI/analog)";
        case PciDevice1415::DEVICE_C57D: return "OXPCIe200 EHCI USB Controller (R-ULPI)";
        case PciDevice1415::DEVICE_C57E: return "OXPCIe200 GPIO";
        case PciDevice1415::DEVICE_C57F: return "OXPCIe200 Native 950 UART";
        case PciDevice1415::DEVICE_C5A0: return "OXPCIe200 OHCI USB Controller (ULPI)";
        case PciDevice1415::DEVICE_C5A1: return "OXPCIe200 EHCI USB Controller (ULPI)";
        case PciDevice1415::DEVICE_C5A2: return "OXPCIe200 Programmable Memory Interface";
        case PciDevice1415::DEVICE_C5A4: return "OXPCIe200 OHCI USB Controller (ULPI)";
        case PciDevice1415::DEVICE_C5A5: return "OXPCIe200 EHCI USB Controller (ULPI)";
        case PciDevice1415::DEVICE_C5A6: return "OXPCIe200 Programmable Memory Interface & GPIO";
        case PciDevice1415::DEVICE_C5A8: return "OXPCIe200 OHCI USB Controller (ULPI)";
        case PciDevice1415::DEVICE_C5A9: return "OXPCIe200 EHCI USB Controller (ULPI)";
        case PciDevice1415::DEVICE_C5AA: return "OXPCIe200 Programmable Memory Interface";
        case PciDevice1415::DEVICE_C5AB: return "OXPCIe200 Native 950 UART";
        case PciDevice1415::DEVICE_C5AC: return "OXPCIe200 OHCI USB Controller (ULPI)";
        case PciDevice1415::DEVICE_C5AD: return "OXPCIe200 EHCI USB Controller (ULPI)";
        case PciDevice1415::DEVICE_C5AE: return "OXPCIe200 Programmable Memory Interface & GPIO";
        case PciDevice1415::DEVICE_C5AF: return "OXPCIe200 Native 950 UART";
        case PciDevice1415::DEVICE_C5B0: return "OXPCIe200 OHCI USB Controller (R-ULPI)";
        case PciDevice1415::DEVICE_C5B1: return "OXPCIe200 EHCI USB Controller (R-ULPI)";
        case PciDevice1415::DEVICE_C5B2: return "OXPCIe200 Programmable Memory Interface";
        case PciDevice1415::DEVICE_C5B4: return "OXPCIe200 OHCI USB Controller (R-ULPI)";
        case PciDevice1415::DEVICE_C5B5: return "OXPCIe200 EHCI USB Controller (R-ULPI)";
        case PciDevice1415::DEVICE_C5B6: return "OXPCIe200 Programmable Memory Interface & GPIO";
        case PciDevice1415::DEVICE_C5B8: return "OXPCIe200 OHCI USB Controller (R-ULPI)";
        case PciDevice1415::DEVICE_C5B9: return "OXPCIe200 EHCI USB Controller (R-ULPI)";
        case PciDevice1415::DEVICE_C5BA: return "OXPCIe200 Programmable Memory Interface";
        case PciDevice1415::DEVICE_C5BB: return "OXPCIe200 Native 950 UART";
        case PciDevice1415::DEVICE_C5BC: return "OXPCIe200 OHCI USB Controller (R-ULPI)";
        case PciDevice1415::DEVICE_C5BD: return "OXPCIe200 EHCI USB Controller (R-ULPI)";
        case PciDevice1415::DEVICE_C5BE: return "OXPCIe200 Programmable Memory Interface & GPIO";
        case PciDevice1415::DEVICE_C5BF: return "OXPCIe200 Native 950 UART";
        case PciDevice1415::DEVICE_C5C0: return "OXPCIe200 OHCI USB Controller (analog)";
        case PciDevice1415::DEVICE_C5C2: return "OXPCIe200 Programmable Memory Interface";
        case PciDevice1415::DEVICE_C5C4: return "OXPCIe200 OHCI USB Controller (analog)";
        case PciDevice1415::DEVICE_C5C6: return "OXPCIe200 Programmable Memory Interface & GPIO";
        case PciDevice1415::DEVICE_C5C8: return "OXPCIe200 OHCI USB Controller (analog)";
        case PciDevice1415::DEVICE_C5CA: return "OXPCIe200 Programmable Memory Interface";
        case PciDevice1415::DEVICE_C5CB: return "OXPCIe200 Native 950 UART";
        case PciDevice1415::DEVICE_C5CC: return "OXPCIe200 OHCI USB Controller (analog)";
        case PciDevice1415::DEVICE_C5CE: return "OXPCIe200 Programmable Memory Interface & GPIO";
        case PciDevice1415::DEVICE_C5CF: return "OXPCIe200 Native 950 UART";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1415 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1415::DEVICE_8401: return "Unknown device";
        case PciDevice1415::DEVICE_8403: return "Unknown device";
        case PciDevice1415::DEVICE_9500: return "Unknown device";
        case PciDevice1415::DEVICE_9501: return enumToHumanString((PciSubDevice14159501)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1415::DEVICE_9505: return "Unknown device";
        case PciDevice1415::DEVICE_950A: return "Unknown device";
        case PciDevice1415::DEVICE_950B: return "Unknown device";
        case PciDevice1415::DEVICE_9510: return enumToHumanString((PciSubDevice14159510)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1415::DEVICE_9511: return enumToHumanString((PciSubDevice14159511)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1415::DEVICE_9512: return "Unknown device";
        case PciDevice1415::DEVICE_9513: return "Unknown device";
        case PciDevice1415::DEVICE_9521: return "Unknown device";
        case PciDevice1415::DEVICE_9523: return "Unknown device";
        case PciDevice1415::DEVICE_C000: return "Unknown device";
        case PciDevice1415::DEVICE_C004: return "Unknown device";
        case PciDevice1415::DEVICE_C006: return "Unknown device";
        case PciDevice1415::DEVICE_C100: return "Unknown device";
        case PciDevice1415::DEVICE_C101: return "Unknown device";
        case PciDevice1415::DEVICE_C104: return "Unknown device";
        case PciDevice1415::DEVICE_C105: return "Unknown device";
        case PciDevice1415::DEVICE_C106: return "Unknown device";
        case PciDevice1415::DEVICE_C108: return "Unknown device";
        case PciDevice1415::DEVICE_C109: return "Unknown device";
        case PciDevice1415::DEVICE_C10C: return "Unknown device";
        case PciDevice1415::DEVICE_C10D: return "Unknown device";
        case PciDevice1415::DEVICE_C10E: return "Unknown device";
        case PciDevice1415::DEVICE_C110: return "Unknown device";
        case PciDevice1415::DEVICE_C114: return "Unknown device";
        case PciDevice1415::DEVICE_C118: return "Unknown device";
        case PciDevice1415::DEVICE_C11B: return "Unknown device";
        case PciDevice1415::DEVICE_C11C: return "Unknown device";
        case PciDevice1415::DEVICE_C11E: return "Unknown device";
        case PciDevice1415::DEVICE_C11F: return "Unknown device";
        case PciDevice1415::DEVICE_C120: return "Unknown device";
        case PciDevice1415::DEVICE_C124: return "Unknown device";
        case PciDevice1415::DEVICE_C126: return "Unknown device";
        case PciDevice1415::DEVICE_C128: return "Unknown device";
        case PciDevice1415::DEVICE_C12C: return "Unknown device";
        case PciDevice1415::DEVICE_C12E: return "Unknown device";
        case PciDevice1415::DEVICE_C134: return "Unknown device";
        case PciDevice1415::DEVICE_C138: return "Unknown device";
        case PciDevice1415::DEVICE_C13C: return "Unknown device";
        case PciDevice1415::DEVICE_C13D: return "Unknown device";
        case PciDevice1415::DEVICE_C140: return "Unknown device";
        case PciDevice1415::DEVICE_C141: return "Unknown device";
        case PciDevice1415::DEVICE_C144: return "Unknown device";
        case PciDevice1415::DEVICE_C145: return "Unknown device";
        case PciDevice1415::DEVICE_C146: return "Unknown device";
        case PciDevice1415::DEVICE_C148: return "Unknown device";
        case PciDevice1415::DEVICE_C149: return "Unknown device";
        case PciDevice1415::DEVICE_C14C: return "Unknown device";
        case PciDevice1415::DEVICE_C14D: return "Unknown device";
        case PciDevice1415::DEVICE_C14E: return "Unknown device";
        case PciDevice1415::DEVICE_C154: return "Unknown device";
        case PciDevice1415::DEVICE_C158: return enumToHumanString((PciSubDevice1415C158)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1415::DEVICE_C15C: return "Unknown device";
        case PciDevice1415::DEVICE_C15D: return "Unknown device";
        case PciDevice1415::DEVICE_C204: return "Unknown device";
        case PciDevice1415::DEVICE_C208: return "Unknown device";
        case PciDevice1415::DEVICE_C20C: return "Unknown device";
        case PciDevice1415::DEVICE_C20D: return "Unknown device";
        case PciDevice1415::DEVICE_C304: return "Unknown device";
        case PciDevice1415::DEVICE_C308: return "Unknown device";
        case PciDevice1415::DEVICE_C30C: return "Unknown device";
        case PciDevice1415::DEVICE_C30D: return "Unknown device";
        case PciDevice1415::DEVICE_C530: return "Unknown device";
        case PciDevice1415::DEVICE_C531: return "Unknown device";
        case PciDevice1415::DEVICE_C534: return "Unknown device";
        case PciDevice1415::DEVICE_C535: return "Unknown device";
        case PciDevice1415::DEVICE_C536: return "Unknown device";
        case PciDevice1415::DEVICE_C538: return "Unknown device";
        case PciDevice1415::DEVICE_C539: return "Unknown device";
        case PciDevice1415::DEVICE_C53B: return "Unknown device";
        case PciDevice1415::DEVICE_C53C: return "Unknown device";
        case PciDevice1415::DEVICE_C53D: return "Unknown device";
        case PciDevice1415::DEVICE_C53E: return "Unknown device";
        case PciDevice1415::DEVICE_C53F: return "Unknown device";
        case PciDevice1415::DEVICE_C540: return "Unknown device";
        case PciDevice1415::DEVICE_C541: return "Unknown device";
        case PciDevice1415::DEVICE_C544: return "Unknown device";
        case PciDevice1415::DEVICE_C545: return "Unknown device";
        case PciDevice1415::DEVICE_C546: return "Unknown device";
        case PciDevice1415::DEVICE_C548: return "Unknown device";
        case PciDevice1415::DEVICE_C549: return "Unknown device";
        case PciDevice1415::DEVICE_C54B: return "Unknown device";
        case PciDevice1415::DEVICE_C54C: return "Unknown device";
        case PciDevice1415::DEVICE_C54D: return "Unknown device";
        case PciDevice1415::DEVICE_C54E: return "Unknown device";
        case PciDevice1415::DEVICE_C54F: return "Unknown device";
        case PciDevice1415::DEVICE_C560: return "Unknown device";
        case PciDevice1415::DEVICE_C561: return "Unknown device";
        case PciDevice1415::DEVICE_C564: return "Unknown device";
        case PciDevice1415::DEVICE_C565: return "Unknown device";
        case PciDevice1415::DEVICE_C566: return "Unknown device";
        case PciDevice1415::DEVICE_C568: return "Unknown device";
        case PciDevice1415::DEVICE_C569: return "Unknown device";
        case PciDevice1415::DEVICE_C56B: return "Unknown device";
        case PciDevice1415::DEVICE_C56C: return "Unknown device";
        case PciDevice1415::DEVICE_C56D: return "Unknown device";
        case PciDevice1415::DEVICE_C56E: return "Unknown device";
        case PciDevice1415::DEVICE_C56F: return "Unknown device";
        case PciDevice1415::DEVICE_C570: return "Unknown device";
        case PciDevice1415::DEVICE_C571: return "Unknown device";
        case PciDevice1415::DEVICE_C574: return "Unknown device";
        case PciDevice1415::DEVICE_C575: return "Unknown device";
        case PciDevice1415::DEVICE_C576: return "Unknown device";
        case PciDevice1415::DEVICE_C578: return "Unknown device";
        case PciDevice1415::DEVICE_C579: return "Unknown device";
        case PciDevice1415::DEVICE_C57B: return "Unknown device";
        case PciDevice1415::DEVICE_C57C: return "Unknown device";
        case PciDevice1415::DEVICE_C57D: return "Unknown device";
        case PciDevice1415::DEVICE_C57E: return "Unknown device";
        case PciDevice1415::DEVICE_C57F: return "Unknown device";
        case PciDevice1415::DEVICE_C5A0: return "Unknown device";
        case PciDevice1415::DEVICE_C5A1: return "Unknown device";
        case PciDevice1415::DEVICE_C5A2: return "Unknown device";
        case PciDevice1415::DEVICE_C5A4: return "Unknown device";
        case PciDevice1415::DEVICE_C5A5: return "Unknown device";
        case PciDevice1415::DEVICE_C5A6: return "Unknown device";
        case PciDevice1415::DEVICE_C5A8: return "Unknown device";
        case PciDevice1415::DEVICE_C5A9: return "Unknown device";
        case PciDevice1415::DEVICE_C5AA: return "Unknown device";
        case PciDevice1415::DEVICE_C5AB: return "Unknown device";
        case PciDevice1415::DEVICE_C5AC: return "Unknown device";
        case PciDevice1415::DEVICE_C5AD: return "Unknown device";
        case PciDevice1415::DEVICE_C5AE: return "Unknown device";
        case PciDevice1415::DEVICE_C5AF: return "Unknown device";
        case PciDevice1415::DEVICE_C5B0: return "Unknown device";
        case PciDevice1415::DEVICE_C5B1: return "Unknown device";
        case PciDevice1415::DEVICE_C5B2: return "Unknown device";
        case PciDevice1415::DEVICE_C5B4: return "Unknown device";
        case PciDevice1415::DEVICE_C5B5: return "Unknown device";
        case PciDevice1415::DEVICE_C5B6: return "Unknown device";
        case PciDevice1415::DEVICE_C5B8: return "Unknown device";
        case PciDevice1415::DEVICE_C5B9: return "Unknown device";
        case PciDevice1415::DEVICE_C5BA: return "Unknown device";
        case PciDevice1415::DEVICE_C5BB: return "Unknown device";
        case PciDevice1415::DEVICE_C5BC: return "Unknown device";
        case PciDevice1415::DEVICE_C5BD: return "Unknown device";
        case PciDevice1415::DEVICE_C5BE: return "Unknown device";
        case PciDevice1415::DEVICE_C5BF: return "Unknown device";
        case PciDevice1415::DEVICE_C5C0: return "Unknown device";
        case PciDevice1415::DEVICE_C5C2: return "Unknown device";
        case PciDevice1415::DEVICE_C5C4: return "Unknown device";
        case PciDevice1415::DEVICE_C5C6: return "Unknown device";
        case PciDevice1415::DEVICE_C5C8: return "Unknown device";
        case PciDevice1415::DEVICE_C5CA: return "Unknown device";
        case PciDevice1415::DEVICE_C5CB: return "Unknown device";
        case PciDevice1415::DEVICE_C5CC: return "Unknown device";
        case PciDevice1415::DEVICE_C5CE: return "Unknown device";
        case PciDevice1415::DEVICE_C5CF: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1415_PCIDEVICE1415_H
