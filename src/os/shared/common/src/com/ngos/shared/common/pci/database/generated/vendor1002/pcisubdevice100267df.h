// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267DF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267DF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100267DF: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020B37 = 0x10020B37,
    SUBDEVICE_10281722 = 0x10281722,
    SUBDEVICE_10281723 = 0x10281723,
    SUBDEVICE_103C840E = 0x103C840E,
    SUBDEVICE_104304A8 = 0x104304A8,
    SUBDEVICE_104304B0 = 0x104304B0,
    SUBDEVICE_104304FB = 0x104304FB,
    SUBDEVICE_104304FD = 0x104304FD,
    SUBDEVICE_1043056A = 0x1043056A,
    SUBDEVICE_106B0161 = 0x106B0161,
    SUBDEVICE_106B0162 = 0x106B0162,
    SUBDEVICE_106B0163 = 0x106B0163,
    SUBDEVICE_145822F0 = 0x145822F0,
    SUBDEVICE_145822F7 = 0x145822F7,
    SUBDEVICE_14623411 = 0x14623411,
    SUBDEVICE_14623413 = 0x14623413,
    SUBDEVICE_14623416 = 0x14623416,
    SUBDEVICE_14623418 = 0x14623418,
    SUBDEVICE_1462341B = 0x1462341B,
    SUBDEVICE_1462341E = 0x1462341E,
    SUBDEVICE_1462809E = 0x1462809E,
    SUBDEVICE_14628A92 = 0x14628A92,
    SUBDEVICE_148C2372 = 0x148C2372,
    SUBDEVICE_148C2373 = 0x148C2373,
    SUBDEVICE_148C2377 = 0x148C2377,
    SUBDEVICE_148C2378 = 0x148C2378,
    SUBDEVICE_148C2379 = 0x148C2379,
    SUBDEVICE_148C2391 = 0x148C2391,
    SUBDEVICE_16829470 = 0x16829470,
    SUBDEVICE_16829480 = 0x16829480,
    SUBDEVICE_16829587 = 0x16829587,
    SUBDEVICE_16829588 = 0x16829588,
    SUBDEVICE_1682C570 = 0x1682C570,
    SUBDEVICE_1682C580 = 0x1682C580,
    SUBDEVICE_174BE347 = 0x174BE347,
    SUBDEVICE_174BE349 = 0x174BE349,
    SUBDEVICE_1787A470 = 0x1787A470,
    SUBDEVICE_1787A480 = 0x1787A480,
    SUBDEVICE_18495001 = 0x18495001,
    SUBDEVICE_18495030 = 0x18495030,
    SUBDEVICE_1DA2E353 = 0x1DA2E353,
    SUBDEVICE_1DA2E366 = 0x1DA2E366,
    SUBDEVICE_1DA2E387 = 0x1DA2E387
};



inline const char8* enumToString(PciSubDevice100267DF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100267DF::NONE:               return "NONE";
        case PciSubDevice100267DF::SUBDEVICE_10020B37: return "SUBDEVICE_10020B37";
        case PciSubDevice100267DF::SUBDEVICE_10281722: return "SUBDEVICE_10281722";
        case PciSubDevice100267DF::SUBDEVICE_10281723: return "SUBDEVICE_10281723";
        case PciSubDevice100267DF::SUBDEVICE_103C840E: return "SUBDEVICE_103C840E";
        case PciSubDevice100267DF::SUBDEVICE_104304A8: return "SUBDEVICE_104304A8";
        case PciSubDevice100267DF::SUBDEVICE_104304B0: return "SUBDEVICE_104304B0";
        case PciSubDevice100267DF::SUBDEVICE_104304FB: return "SUBDEVICE_104304FB";
        case PciSubDevice100267DF::SUBDEVICE_104304FD: return "SUBDEVICE_104304FD";
        case PciSubDevice100267DF::SUBDEVICE_1043056A: return "SUBDEVICE_1043056A";
        case PciSubDevice100267DF::SUBDEVICE_106B0161: return "SUBDEVICE_106B0161";
        case PciSubDevice100267DF::SUBDEVICE_106B0162: return "SUBDEVICE_106B0162";
        case PciSubDevice100267DF::SUBDEVICE_106B0163: return "SUBDEVICE_106B0163";
        case PciSubDevice100267DF::SUBDEVICE_145822F0: return "SUBDEVICE_145822F0";
        case PciSubDevice100267DF::SUBDEVICE_145822F7: return "SUBDEVICE_145822F7";
        case PciSubDevice100267DF::SUBDEVICE_14623411: return "SUBDEVICE_14623411";
        case PciSubDevice100267DF::SUBDEVICE_14623413: return "SUBDEVICE_14623413";
        case PciSubDevice100267DF::SUBDEVICE_14623416: return "SUBDEVICE_14623416";
        case PciSubDevice100267DF::SUBDEVICE_14623418: return "SUBDEVICE_14623418";
        case PciSubDevice100267DF::SUBDEVICE_1462341B: return "SUBDEVICE_1462341B";
        case PciSubDevice100267DF::SUBDEVICE_1462341E: return "SUBDEVICE_1462341E";
        case PciSubDevice100267DF::SUBDEVICE_1462809E: return "SUBDEVICE_1462809E";
        case PciSubDevice100267DF::SUBDEVICE_14628A92: return "SUBDEVICE_14628A92";
        case PciSubDevice100267DF::SUBDEVICE_148C2372: return "SUBDEVICE_148C2372";
        case PciSubDevice100267DF::SUBDEVICE_148C2373: return "SUBDEVICE_148C2373";
        case PciSubDevice100267DF::SUBDEVICE_148C2377: return "SUBDEVICE_148C2377";
        case PciSubDevice100267DF::SUBDEVICE_148C2378: return "SUBDEVICE_148C2378";
        case PciSubDevice100267DF::SUBDEVICE_148C2379: return "SUBDEVICE_148C2379";
        case PciSubDevice100267DF::SUBDEVICE_148C2391: return "SUBDEVICE_148C2391";
        case PciSubDevice100267DF::SUBDEVICE_16829470: return "SUBDEVICE_16829470";
        case PciSubDevice100267DF::SUBDEVICE_16829480: return "SUBDEVICE_16829480";
        case PciSubDevice100267DF::SUBDEVICE_16829587: return "SUBDEVICE_16829587";
        case PciSubDevice100267DF::SUBDEVICE_16829588: return "SUBDEVICE_16829588";
        case PciSubDevice100267DF::SUBDEVICE_1682C570: return "SUBDEVICE_1682C570";
        case PciSubDevice100267DF::SUBDEVICE_1682C580: return "SUBDEVICE_1682C580";
        case PciSubDevice100267DF::SUBDEVICE_174BE347: return "SUBDEVICE_174BE347";
        case PciSubDevice100267DF::SUBDEVICE_174BE349: return "SUBDEVICE_174BE349";
        case PciSubDevice100267DF::SUBDEVICE_1787A470: return "SUBDEVICE_1787A470";
        case PciSubDevice100267DF::SUBDEVICE_1787A480: return "SUBDEVICE_1787A480";
        case PciSubDevice100267DF::SUBDEVICE_18495001: return "SUBDEVICE_18495001";
        case PciSubDevice100267DF::SUBDEVICE_18495030: return "SUBDEVICE_18495030";
        case PciSubDevice100267DF::SUBDEVICE_1DA2E353: return "SUBDEVICE_1DA2E353";
        case PciSubDevice100267DF::SUBDEVICE_1DA2E366: return "SUBDEVICE_1DA2E366";
        case PciSubDevice100267DF::SUBDEVICE_1DA2E387: return "SUBDEVICE_1DA2E387";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100267DF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100267DF subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100267DF::SUBDEVICE_10020B37: return "Radeon RX 480";
        case PciSubDevice100267DF::SUBDEVICE_10281722: return "Radeon RX 570X";
        case PciSubDevice100267DF::SUBDEVICE_10281723: return "Radeon RX 580X";
        case PciSubDevice100267DF::SUBDEVICE_103C840E: return "Radeon RX 580 4GB";
        case PciSubDevice100267DF::SUBDEVICE_104304A8: return "Radeon RX 480";
        case PciSubDevice100267DF::SUBDEVICE_104304B0: return "Radeon RX 470";
        case PciSubDevice100267DF::SUBDEVICE_104304FB: return "Radeon RX 480";
        case PciSubDevice100267DF::SUBDEVICE_104304FD: return "Radeon RX 480 8GB";
        case PciSubDevice100267DF::SUBDEVICE_1043056A: return "Radeon RX 590";
        case PciSubDevice100267DF::SUBDEVICE_106B0161: return "Radeon Pro 580";
        case PciSubDevice100267DF::SUBDEVICE_106B0162: return "Radeon Pro 575";
        case PciSubDevice100267DF::SUBDEVICE_106B0163: return "Radeon Pro 570";
        case PciSubDevice100267DF::SUBDEVICE_145822F0: return "Radeon RX 570";
        case PciSubDevice100267DF::SUBDEVICE_145822F7: return "Radeon RX 570 Gaming 4G";
        case PciSubDevice100267DF::SUBDEVICE_14623411: return "Radeon RX 470";
        case PciSubDevice100267DF::SUBDEVICE_14623413: return "Radeon RX 480 Gaming X 8GB";
        case PciSubDevice100267DF::SUBDEVICE_14623416: return "Radeon RX 570";
        case PciSubDevice100267DF::SUBDEVICE_14623418: return "Radeon RX 580 Armor 4G OC";
        case PciSubDevice100267DF::SUBDEVICE_1462341B: return "Radeon RX 570 Armor 8G OC";
        case PciSubDevice100267DF::SUBDEVICE_1462341E: return "Radeon RX 570 Armor 4G OC";
        case PciSubDevice100267DF::SUBDEVICE_1462809E: return "Radeon RX 480 4GB";
        case PciSubDevice100267DF::SUBDEVICE_14628A92: return "Radeon RX 580";
        case PciSubDevice100267DF::SUBDEVICE_148C2372: return "Radeon RX 480 [Red Dragon]";
        case PciSubDevice100267DF::SUBDEVICE_148C2373: return "Radeon RX 470";
        case PciSubDevice100267DF::SUBDEVICE_148C2377: return "Red Devil RX 580 8G Golden";
        case PciSubDevice100267DF::SUBDEVICE_148C2378: return "Radeon RX 580";
        case PciSubDevice100267DF::SUBDEVICE_148C2379: return "Radeon RX 570 4G [Red Dragon]";
        case PciSubDevice100267DF::SUBDEVICE_148C2391: return "Radeon RX 590 [Red Devil]";
        case PciSubDevice100267DF::SUBDEVICE_16829470: return "Radeon RX 470";
        case PciSubDevice100267DF::SUBDEVICE_16829480: return "Radeon RX 480";
        case PciSubDevice100267DF::SUBDEVICE_16829587: return "Radeon RX 590 FATBOY 8GB";
        case PciSubDevice100267DF::SUBDEVICE_16829588: return "Radeon RX 580 XTR";
        case PciSubDevice100267DF::SUBDEVICE_1682C570: return "Radeon RX 570";
        case PciSubDevice100267DF::SUBDEVICE_1682C580: return "Radeon RX 580";
        case PciSubDevice100267DF::SUBDEVICE_174BE347: return "Radeon RX 470/480";
        case PciSubDevice100267DF::SUBDEVICE_174BE349: return "Radeon RX 470";
        case PciSubDevice100267DF::SUBDEVICE_1787A470: return "Radeon RX 470";
        case PciSubDevice100267DF::SUBDEVICE_1787A480: return "Radeon RX 480";
        case PciSubDevice100267DF::SUBDEVICE_18495001: return "Phantom Gaming X RX 580 OC";
        case PciSubDevice100267DF::SUBDEVICE_18495030: return "Phantom Gaming D Radeon RX580 8G OC";
        case PciSubDevice100267DF::SUBDEVICE_1DA2E353: return "Radeon RX 570 Pulse 4GB";
        case PciSubDevice100267DF::SUBDEVICE_1DA2E366: return "Nitro+ Radeon RX 570/580/590";
        case PciSubDevice100267DF::SUBDEVICE_1DA2E387: return "Radeon RX 580 Pulse 4GB";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100267DF_H
