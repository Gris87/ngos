// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORBDBD_PCIDEVICEBDBD_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORBDBD_PCIDEVICEBDBD_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceBDBD: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_A106 = 0xA106,
    DEVICE_A117 = 0xA117,
    DEVICE_A11A = 0xA11A,
    DEVICE_A11B = 0xA11B,
    DEVICE_A11C = 0xA11C,
    DEVICE_A11D = 0xA11D,
    DEVICE_A11E = 0xA11E,
    DEVICE_A120 = 0xA120,
    DEVICE_A121 = 0xA121,
    DEVICE_A124 = 0xA124,
    DEVICE_A126 = 0xA126,
    DEVICE_A127 = 0xA127,
    DEVICE_A129 = 0xA129,
    DEVICE_A12A = 0xA12A,
    DEVICE_A12D = 0xA12D,
    DEVICE_A12E = 0xA12E,
    DEVICE_A12F = 0xA12F,
    DEVICE_A130 = 0xA130,
    DEVICE_A132 = 0xA132,
    DEVICE_A136 = 0xA136,
    DEVICE_A137 = 0xA137,
    DEVICE_A138 = 0xA138,
    DEVICE_A139 = 0xA139,
    DEVICE_A13B = 0xA13B,
    DEVICE_A13D = 0xA13D,
    DEVICE_A13E = 0xA13E,
    DEVICE_A13F = 0xA13F,
    DEVICE_A140 = 0xA140,
    DEVICE_A141 = 0xA141,
    DEVICE_A142 = 0xA142,
    DEVICE_A143 = 0xA143,
    DEVICE_A144 = 0xA144,
    DEVICE_A148 = 0xA148,
    DEVICE_A14B = 0xA14B,
    DEVICE_A14E = 0xA14E,
    DEVICE_A1FF = 0xA1FF
};



inline const char8* enumToString(PciDeviceBDBD device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceBDBD::NONE:        return "NONE";
        case PciDeviceBDBD::DEVICE_A106: return "DEVICE_A106";
        case PciDeviceBDBD::DEVICE_A117: return "DEVICE_A117";
        case PciDeviceBDBD::DEVICE_A11A: return "DEVICE_A11A";
        case PciDeviceBDBD::DEVICE_A11B: return "DEVICE_A11B";
        case PciDeviceBDBD::DEVICE_A11C: return "DEVICE_A11C";
        case PciDeviceBDBD::DEVICE_A11D: return "DEVICE_A11D";
        case PciDeviceBDBD::DEVICE_A11E: return "DEVICE_A11E";
        case PciDeviceBDBD::DEVICE_A120: return "DEVICE_A120";
        case PciDeviceBDBD::DEVICE_A121: return "DEVICE_A121";
        case PciDeviceBDBD::DEVICE_A124: return "DEVICE_A124";
        case PciDeviceBDBD::DEVICE_A126: return "DEVICE_A126";
        case PciDeviceBDBD::DEVICE_A127: return "DEVICE_A127";
        case PciDeviceBDBD::DEVICE_A129: return "DEVICE_A129";
        case PciDeviceBDBD::DEVICE_A12A: return "DEVICE_A12A";
        case PciDeviceBDBD::DEVICE_A12D: return "DEVICE_A12D";
        case PciDeviceBDBD::DEVICE_A12E: return "DEVICE_A12E";
        case PciDeviceBDBD::DEVICE_A12F: return "DEVICE_A12F";
        case PciDeviceBDBD::DEVICE_A130: return "DEVICE_A130";
        case PciDeviceBDBD::DEVICE_A132: return "DEVICE_A132";
        case PciDeviceBDBD::DEVICE_A136: return "DEVICE_A136";
        case PciDeviceBDBD::DEVICE_A137: return "DEVICE_A137";
        case PciDeviceBDBD::DEVICE_A138: return "DEVICE_A138";
        case PciDeviceBDBD::DEVICE_A139: return "DEVICE_A139";
        case PciDeviceBDBD::DEVICE_A13B: return "DEVICE_A13B";
        case PciDeviceBDBD::DEVICE_A13D: return "DEVICE_A13D";
        case PciDeviceBDBD::DEVICE_A13E: return "DEVICE_A13E";
        case PciDeviceBDBD::DEVICE_A13F: return "DEVICE_A13F";
        case PciDeviceBDBD::DEVICE_A140: return "DEVICE_A140";
        case PciDeviceBDBD::DEVICE_A141: return "DEVICE_A141";
        case PciDeviceBDBD::DEVICE_A142: return "DEVICE_A142";
        case PciDeviceBDBD::DEVICE_A143: return "DEVICE_A143";
        case PciDeviceBDBD::DEVICE_A144: return "DEVICE_A144";
        case PciDeviceBDBD::DEVICE_A148: return "DEVICE_A148";
        case PciDeviceBDBD::DEVICE_A14B: return "DEVICE_A14B";
        case PciDeviceBDBD::DEVICE_A14E: return "DEVICE_A14E";
        case PciDeviceBDBD::DEVICE_A1FF: return "DEVICE_A1FF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceBDBD device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDeviceBDBD device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceBDBD::DEVICE_A106: return "Multibridge Extreme";
        case PciDeviceBDBD::DEVICE_A117: return "Intensity Pro";
        case PciDeviceBDBD::DEVICE_A11A: return "DeckLink HD Extreme 2";
        case PciDeviceBDBD::DEVICE_A11B: return "DeckLink SDI/Duo/Quad";
        case PciDeviceBDBD::DEVICE_A11C: return "DeckLink HD Extreme 3";
        case PciDeviceBDBD::DEVICE_A11D: return "DeckLink Studio";
        case PciDeviceBDBD::DEVICE_A11E: return "DeckLink Optical Fibre";
        case PciDeviceBDBD::DEVICE_A120: return "Decklink Studio 2";
        case PciDeviceBDBD::DEVICE_A121: return "DeckLink HD Extreme 3D/3D+";
        case PciDeviceBDBD::DEVICE_A124: return "Intensity Extreme";
        case PciDeviceBDBD::DEVICE_A126: return "Intensity Shuttle";
        case PciDeviceBDBD::DEVICE_A127: return "UltraStudio Express";
        case PciDeviceBDBD::DEVICE_A129: return "UltraStudio Mini Recorder";
        case PciDeviceBDBD::DEVICE_A12A: return "UltraStudio Mini Monitor";
        case PciDeviceBDBD::DEVICE_A12D: return "UltraStudio 4K";
        case PciDeviceBDBD::DEVICE_A12E: return "DeckLink 4K Extreme";
        case PciDeviceBDBD::DEVICE_A12F: return "DeckLink Mini Monitor";
        case PciDeviceBDBD::DEVICE_A130: return "DeckLink Mini Recorder";
        case PciDeviceBDBD::DEVICE_A132: return "UltraStudio 4K";
        case PciDeviceBDBD::DEVICE_A136: return "DeckLink 4K Extreme 12G";
        case PciDeviceBDBD::DEVICE_A137: return "DeckLink Studio 4K";
        case PciDeviceBDBD::DEVICE_A138: return "Decklink SDI 4K";
        case PciDeviceBDBD::DEVICE_A139: return "Intensity Pro 4K";
        case PciDeviceBDBD::DEVICE_A13B: return "DeckLink Micro Recorder";
        case PciDeviceBDBD::DEVICE_A13D: return "DeckLink 4K Pro";
        case PciDeviceBDBD::DEVICE_A13E: return "UltraStudio 4K Extreme";
        case PciDeviceBDBD::DEVICE_A13F: return "DeckLink Quad 2";
        case PciDeviceBDBD::DEVICE_A140: return "DeckLink Duo 2";
        case PciDeviceBDBD::DEVICE_A141: return "UltraStudio 4K Extreme 3";
        case PciDeviceBDBD::DEVICE_A142: return "UltraStudio HD Mini";
        case PciDeviceBDBD::DEVICE_A143: return "DeckLink Mini Recorder 4K";
        case PciDeviceBDBD::DEVICE_A144: return "DeckLink Mini Monitor 4K";
        case PciDeviceBDBD::DEVICE_A148: return "DeckLink SDI Micro";
        case PciDeviceBDBD::DEVICE_A14B: return "DeckLink 8K Pro";
        case PciDeviceBDBD::DEVICE_A14E: return "DeckLink Quad HDMI Recorder";
        case PciDeviceBDBD::DEVICE_A1FF: return "eGPU RX580";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORBDBD_PCIDEVICEBDBD_H
