// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063059_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063059_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11063059: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10190A81 = 0x10190A81,
    SUBDEVICE_10191841 = 0x10191841,
    SUBDEVICE_10191877 = 0x10191877,
    SUBDEVICE_10438095 = 0x10438095,
    SUBDEVICE_104380A1 = 0x104380A1,
    SUBDEVICE_104380B0 = 0x104380B0,
    SUBDEVICE_104380F3 = 0x104380F3,
    SUBDEVICE_1043810D = 0x1043810D,
    SUBDEVICE_1043812A = 0x1043812A,
    SUBDEVICE_10EC8168 = 0x10EC8168,
    SUBDEVICE_11063059 = 0x11063059,
    SUBDEVICE_11064161 = 0x11064161,
    SUBDEVICE_11064170 = 0x11064170,
    SUBDEVICE_11064552 = 0x11064552,
    SUBDEVICE_1297C160 = 0x1297C160,
    SUBDEVICE_1413147B = 0x1413147B,
    SUBDEVICE_1458A002 = 0x1458A002,
    SUBDEVICE_14620080 = 0x14620080,
    SUBDEVICE_14623800 = 0x14623800,
    SUBDEVICE_14625901 = 0x14625901,
    SUBDEVICE_14627181 = 0x14627181,
    SUBDEVICE_147B1407 = 0x147B1407,
    SUBDEVICE_1695300C = 0x1695300C,
    SUBDEVICE_18490850 = 0x18490850,
    SUBDEVICE_18499739 = 0x18499739,
    SUBDEVICE_18499761 = 0x18499761,
    SUBDEVICE_40054710 = 0x40054710,
    SUBDEVICE_A0A001B6 = 0xA0A001B6,
    SUBDEVICE_A0A00342 = 0xA0A00342
};



inline const char8* enumToString(PciSubDevice11063059 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063059::NONE:               return "NONE";
        case PciSubDevice11063059::SUBDEVICE_10190A81: return "SUBDEVICE_10190A81";
        case PciSubDevice11063059::SUBDEVICE_10191841: return "SUBDEVICE_10191841";
        case PciSubDevice11063059::SUBDEVICE_10191877: return "SUBDEVICE_10191877";
        case PciSubDevice11063059::SUBDEVICE_10438095: return "SUBDEVICE_10438095";
        case PciSubDevice11063059::SUBDEVICE_104380A1: return "SUBDEVICE_104380A1";
        case PciSubDevice11063059::SUBDEVICE_104380B0: return "SUBDEVICE_104380B0";
        case PciSubDevice11063059::SUBDEVICE_104380F3: return "SUBDEVICE_104380F3";
        case PciSubDevice11063059::SUBDEVICE_1043810D: return "SUBDEVICE_1043810D";
        case PciSubDevice11063059::SUBDEVICE_1043812A: return "SUBDEVICE_1043812A";
        case PciSubDevice11063059::SUBDEVICE_10EC8168: return "SUBDEVICE_10EC8168";
        case PciSubDevice11063059::SUBDEVICE_11063059: return "SUBDEVICE_11063059";
        case PciSubDevice11063059::SUBDEVICE_11064161: return "SUBDEVICE_11064161";
        case PciSubDevice11063059::SUBDEVICE_11064170: return "SUBDEVICE_11064170";
        case PciSubDevice11063059::SUBDEVICE_11064552: return "SUBDEVICE_11064552";
        case PciSubDevice11063059::SUBDEVICE_1297C160: return "SUBDEVICE_1297C160";
        case PciSubDevice11063059::SUBDEVICE_1413147B: return "SUBDEVICE_1413147B";
        case PciSubDevice11063059::SUBDEVICE_1458A002: return "SUBDEVICE_1458A002";
        case PciSubDevice11063059::SUBDEVICE_14620080: return "SUBDEVICE_14620080";
        case PciSubDevice11063059::SUBDEVICE_14623800: return "SUBDEVICE_14623800";
        case PciSubDevice11063059::SUBDEVICE_14625901: return "SUBDEVICE_14625901";
        case PciSubDevice11063059::SUBDEVICE_14627181: return "SUBDEVICE_14627181";
        case PciSubDevice11063059::SUBDEVICE_147B1407: return "SUBDEVICE_147B1407";
        case PciSubDevice11063059::SUBDEVICE_1695300C: return "SUBDEVICE_1695300C";
        case PciSubDevice11063059::SUBDEVICE_18490850: return "SUBDEVICE_18490850";
        case PciSubDevice11063059::SUBDEVICE_18499739: return "SUBDEVICE_18499739";
        case PciSubDevice11063059::SUBDEVICE_18499761: return "SUBDEVICE_18499761";
        case PciSubDevice11063059::SUBDEVICE_40054710: return "SUBDEVICE_40054710";
        case PciSubDevice11063059::SUBDEVICE_A0A001B6: return "SUBDEVICE_A0A001B6";
        case PciSubDevice11063059::SUBDEVICE_A0A00342: return "SUBDEVICE_A0A00342";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11063059 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11063059 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063059::SUBDEVICE_10190A81: return "L7VTA v1.0 Motherboard (KT400-8235)";
        case PciSubDevice11063059::SUBDEVICE_10191841: return "M811 (VT8367/VT8235/VT6103) [KT333] motherboard";
        case PciSubDevice11063059::SUBDEVICE_10191877: return "K8M800-M2 (V2.0) onboard audio";
        case PciSubDevice11063059::SUBDEVICE_10438095: return "A7V8X Motherboard (Realtek ALC650 codec)";
        case PciSubDevice11063059::SUBDEVICE_104380A1: return "A7V8X-X Motherboard";
        case PciSubDevice11063059::SUBDEVICE_104380B0: return "A7V600/K8V-X/K8V Deluxe motherboard (ADI AD1980 codec [SoundMAX])";
        case PciSubDevice11063059::SUBDEVICE_104380F3: return "SK8V motherboard";
        case PciSubDevice11063059::SUBDEVICE_1043810D: return "P5VD1-X (AD1888 codec [SoundMax])";
        case PciSubDevice11063059::SUBDEVICE_1043812A: return "A8V Deluxe motherboard (Realtek ALC850 codec)";
        case PciSubDevice11063059::SUBDEVICE_10EC8168: return "High Definition Audio";
        case PciSubDevice11063059::SUBDEVICE_11063059: return "L7VMM2 Motherboard";
        case PciSubDevice11063059::SUBDEVICE_11064161: return "K7VT2 motherboard";
        case PciSubDevice11063059::SUBDEVICE_11064170: return "PCPartner P4M800-8237R Motherboard";
        case PciSubDevice11063059::SUBDEVICE_11064552: return "Soyo KT-600 Dragon Plus (Realtek ALC 650)";
        case PciSubDevice11063059::SUBDEVICE_1297C160: return "FX41 motherboard (Realtek ALC650 codec)";
        case PciSubDevice11063059::SUBDEVICE_1413147B: return "KV8 Pro motherboard onboard audio";
        case PciSubDevice11063059::SUBDEVICE_1458A002: return "GA-7VAX Onboard Audio (Realtek ALC650)";
        case PciSubDevice11063059::SUBDEVICE_14620080: return "K8T NEO 2 motherboard";
        case PciSubDevice11063059::SUBDEVICE_14623800: return "KT266 onboard audio";
        case PciSubDevice11063059::SUBDEVICE_14625901: return "KT6 Delta-FIS2R (MS-6590)";
        case PciSubDevice11063059::SUBDEVICE_14627181: return "K8MM3-V mainboard";
        case PciSubDevice11063059::SUBDEVICE_147B1407: return "KV8-MAX3 motherboard";
        case PciSubDevice11063059::SUBDEVICE_1695300C: return "Realtek ALC655 audio on EP-8KRA series mainboard";
        case PciSubDevice11063059::SUBDEVICE_18490850: return "ASRock 775Dual-880 Pro onboard audio (Realtek ALC850)";
        case PciSubDevice11063059::SUBDEVICE_18499739: return "P4VT8 Mainboard (C-Media CMI9739A codec)";
        case PciSubDevice11063059::SUBDEVICE_18499761: return "K7VT series Motherboards";
        case PciSubDevice11063059::SUBDEVICE_40054710: return "MSI K7T266 Pro2-RU (MSI-6380 v2) onboard audio (Realtek/ALC 200/200P)";
        case PciSubDevice11063059::SUBDEVICE_A0A001B6: return "AK77-8XN onboard audio";
        case PciSubDevice11063059::SUBDEVICE_A0A00342: return "AK86-L motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063059_H
