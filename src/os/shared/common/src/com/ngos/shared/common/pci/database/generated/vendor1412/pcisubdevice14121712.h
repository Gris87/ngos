// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1412_PCISUBDEVICE14121712_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1412_PCISUBDEVICE14121712_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14121712: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14121712 = 0x14121712,
    SUBDEVICE_1412D630 = 0x1412D630,
    SUBDEVICE_1412D631 = 0x1412D631,
    SUBDEVICE_1412D632 = 0x1412D632,
    SUBDEVICE_1412D633 = 0x1412D633,
    SUBDEVICE_1412D634 = 0x1412D634,
    SUBDEVICE_1412D635 = 0x1412D635,
    SUBDEVICE_1412D637 = 0x1412D637,
    SUBDEVICE_1412D638 = 0x1412D638,
    SUBDEVICE_1412D63B = 0x1412D63B,
    SUBDEVICE_1412D63C = 0x1412D63C,
    SUBDEVICE_14161712 = 0x14161712,
    SUBDEVICE_153B1115 = 0x153B1115,
    SUBDEVICE_153B1125 = 0x153B1125,
    SUBDEVICE_153B112B = 0x153B112B,
    SUBDEVICE_153B112C = 0x153B112C,
    SUBDEVICE_153B1130 = 0x153B1130,
    SUBDEVICE_153B1138 = 0x153B1138,
    SUBDEVICE_153B1151 = 0x153B1151,
    SUBDEVICE_16CE1040 = 0x16CE1040
};



inline const char8* enumToString(PciSubDevice14121712 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14121712::NONE:               return "NONE";
        case PciSubDevice14121712::SUBDEVICE_14121712: return "SUBDEVICE_14121712";
        case PciSubDevice14121712::SUBDEVICE_1412D630: return "SUBDEVICE_1412D630";
        case PciSubDevice14121712::SUBDEVICE_1412D631: return "SUBDEVICE_1412D631";
        case PciSubDevice14121712::SUBDEVICE_1412D632: return "SUBDEVICE_1412D632";
        case PciSubDevice14121712::SUBDEVICE_1412D633: return "SUBDEVICE_1412D633";
        case PciSubDevice14121712::SUBDEVICE_1412D634: return "SUBDEVICE_1412D634";
        case PciSubDevice14121712::SUBDEVICE_1412D635: return "SUBDEVICE_1412D635";
        case PciSubDevice14121712::SUBDEVICE_1412D637: return "SUBDEVICE_1412D637";
        case PciSubDevice14121712::SUBDEVICE_1412D638: return "SUBDEVICE_1412D638";
        case PciSubDevice14121712::SUBDEVICE_1412D63B: return "SUBDEVICE_1412D63B";
        case PciSubDevice14121712::SUBDEVICE_1412D63C: return "SUBDEVICE_1412D63C";
        case PciSubDevice14121712::SUBDEVICE_14161712: return "SUBDEVICE_14161712";
        case PciSubDevice14121712::SUBDEVICE_153B1115: return "SUBDEVICE_153B1115";
        case PciSubDevice14121712::SUBDEVICE_153B1125: return "SUBDEVICE_153B1125";
        case PciSubDevice14121712::SUBDEVICE_153B112B: return "SUBDEVICE_153B112B";
        case PciSubDevice14121712::SUBDEVICE_153B112C: return "SUBDEVICE_153B112C";
        case PciSubDevice14121712::SUBDEVICE_153B1130: return "SUBDEVICE_153B1130";
        case PciSubDevice14121712::SUBDEVICE_153B1138: return "SUBDEVICE_153B1138";
        case PciSubDevice14121712::SUBDEVICE_153B1151: return "SUBDEVICE_153B1151";
        case PciSubDevice14121712::SUBDEVICE_16CE1040: return "SUBDEVICE_16CE1040";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14121712 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14121712 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14121712::SUBDEVICE_14121712: return "Hoontech ST Audio DSP 24";
        case PciSubDevice14121712::SUBDEVICE_1412D630: return "M-Audio Delta 1010";
        case PciSubDevice14121712::SUBDEVICE_1412D631: return "M-Audio Delta DiO";
        case PciSubDevice14121712::SUBDEVICE_1412D632: return "M-Audio Delta 66";
        case PciSubDevice14121712::SUBDEVICE_1412D633: return "M-Audio Delta 44";
        case PciSubDevice14121712::SUBDEVICE_1412D634: return "M-Audio Delta Audiophile 2496";
        case PciSubDevice14121712::SUBDEVICE_1412D635: return "M-Audio Delta TDIF";
        case PciSubDevice14121712::SUBDEVICE_1412D637: return "M-Audio Delta RBUS";
        case PciSubDevice14121712::SUBDEVICE_1412D638: return "M-Audio Delta 410";
        case PciSubDevice14121712::SUBDEVICE_1412D63B: return "M-Audio Delta 1010LT";
        case PciSubDevice14121712::SUBDEVICE_1412D63C: return "Digigram VX442";
        case PciSubDevice14121712::SUBDEVICE_14161712: return "Hoontech ST Audio DSP 24 Media 7.1";
        case PciSubDevice14121712::SUBDEVICE_153B1115: return "EWS88 MT";
        case PciSubDevice14121712::SUBDEVICE_153B1125: return "EWS88 MT (Master)";
        case PciSubDevice14121712::SUBDEVICE_153B112B: return "EWS88 D";
        case PciSubDevice14121712::SUBDEVICE_153B112C: return "EWS88 D (Master)";
        case PciSubDevice14121712::SUBDEVICE_153B1130: return "EWX 24/96";
        case PciSubDevice14121712::SUBDEVICE_153B1138: return "DMX 6fire 24/96";
        case PciSubDevice14121712::SUBDEVICE_153B1151: return "PHASE88";
        case PciSubDevice14121712::SUBDEVICE_16CE1040: return "Edirol DA-2496";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1412_PCISUBDEVICE14121712_H
