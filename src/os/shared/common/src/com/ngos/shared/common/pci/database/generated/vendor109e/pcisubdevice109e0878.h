// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR109E_PCISUBDEVICE109E0878_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR109E_PCISUBDEVICE109E0878_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice109E0878: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_00000001 = 0x00000001,
    SUBDEVICE_007013EB = 0x007013EB,
    SUBDEVICE_0070FF01 = 0x0070FF01,
    SUBDEVICE_00710101 = 0x00710101,
    SUBDEVICE_10020001 = 0x10020001,
    SUBDEVICE_10020003 = 0x10020003,
    SUBDEVICE_11BD0012 = 0x11BD0012,
    SUBDEVICE_11BD001C = 0x11BD001C,
    SUBDEVICE_127A0001 = 0x127A0001,
    SUBDEVICE_127A0002 = 0x127A0002,
    SUBDEVICE_127A0003 = 0x127A0003,
    SUBDEVICE_127A0048 = 0x127A0048,
    SUBDEVICE_13E90070 = 0x13E90070,
    SUBDEVICE_144F3000 = 0x144F3000,
    SUBDEVICE_14610002 = 0x14610002,
    SUBDEVICE_14610003 = 0x14610003,
    SUBDEVICE_14610004 = 0x14610004,
    SUBDEVICE_14610761 = 0x14610761,
    SUBDEVICE_14610771 = 0x14610771,
    SUBDEVICE_14F10001 = 0x14F10001,
    SUBDEVICE_14F10002 = 0x14F10002,
    SUBDEVICE_14F10003 = 0x14F10003,
    SUBDEVICE_14F10048 = 0x14F10048,
    SUBDEVICE_18220001 = 0x18220001,
    SUBDEVICE_18ACD500 = 0x18ACD500,
    SUBDEVICE_270FFC00 = 0x270FFC00,
    SUBDEVICE_BD111200 = 0xBD111200
};



inline const char8* enumToString(PciSubDevice109E0878 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice109E0878::NONE:               return "NONE";
        case PciSubDevice109E0878::SUBDEVICE_00000001: return "SUBDEVICE_00000001";
        case PciSubDevice109E0878::SUBDEVICE_007013EB: return "SUBDEVICE_007013EB";
        case PciSubDevice109E0878::SUBDEVICE_0070FF01: return "SUBDEVICE_0070FF01";
        case PciSubDevice109E0878::SUBDEVICE_00710101: return "SUBDEVICE_00710101";
        case PciSubDevice109E0878::SUBDEVICE_10020001: return "SUBDEVICE_10020001";
        case PciSubDevice109E0878::SUBDEVICE_10020003: return "SUBDEVICE_10020003";
        case PciSubDevice109E0878::SUBDEVICE_11BD0012: return "SUBDEVICE_11BD0012";
        case PciSubDevice109E0878::SUBDEVICE_11BD001C: return "SUBDEVICE_11BD001C";
        case PciSubDevice109E0878::SUBDEVICE_127A0001: return "SUBDEVICE_127A0001";
        case PciSubDevice109E0878::SUBDEVICE_127A0002: return "SUBDEVICE_127A0002";
        case PciSubDevice109E0878::SUBDEVICE_127A0003: return "SUBDEVICE_127A0003";
        case PciSubDevice109E0878::SUBDEVICE_127A0048: return "SUBDEVICE_127A0048";
        case PciSubDevice109E0878::SUBDEVICE_13E90070: return "SUBDEVICE_13E90070";
        case PciSubDevice109E0878::SUBDEVICE_144F3000: return "SUBDEVICE_144F3000";
        case PciSubDevice109E0878::SUBDEVICE_14610002: return "SUBDEVICE_14610002";
        case PciSubDevice109E0878::SUBDEVICE_14610003: return "SUBDEVICE_14610003";
        case PciSubDevice109E0878::SUBDEVICE_14610004: return "SUBDEVICE_14610004";
        case PciSubDevice109E0878::SUBDEVICE_14610761: return "SUBDEVICE_14610761";
        case PciSubDevice109E0878::SUBDEVICE_14610771: return "SUBDEVICE_14610771";
        case PciSubDevice109E0878::SUBDEVICE_14F10001: return "SUBDEVICE_14F10001";
        case PciSubDevice109E0878::SUBDEVICE_14F10002: return "SUBDEVICE_14F10002";
        case PciSubDevice109E0878::SUBDEVICE_14F10003: return "SUBDEVICE_14F10003";
        case PciSubDevice109E0878::SUBDEVICE_14F10048: return "SUBDEVICE_14F10048";
        case PciSubDevice109E0878::SUBDEVICE_18220001: return "SUBDEVICE_18220001";
        case PciSubDevice109E0878::SUBDEVICE_18ACD500: return "SUBDEVICE_18ACD500";
        case PciSubDevice109E0878::SUBDEVICE_270FFC00: return "SUBDEVICE_270FFC00";
        case PciSubDevice109E0878::SUBDEVICE_BD111200: return "SUBDEVICE_BD111200";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice109E0878 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice109E0878 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice109E0878::SUBDEVICE_00000001: return "Euresys Picolo PCIe";
        case PciSubDevice109E0878::SUBDEVICE_007013EB: return "WinTV Series";
        case PciSubDevice109E0878::SUBDEVICE_0070FF01: return "Viewcast Osprey 200";
        case PciSubDevice109E0878::SUBDEVICE_00710101: return "DigiTV PCI";
        case PciSubDevice109E0878::SUBDEVICE_10020001: return "TV-Wonder";
        case PciSubDevice109E0878::SUBDEVICE_10020003: return "TV-Wonder/VE";
        case PciSubDevice109E0878::SUBDEVICE_11BD0012: return "PCTV pro (TV + FM stereo receiver, audio section)";
        case PciSubDevice109E0878::SUBDEVICE_11BD001C: return "PCTV Sat (DBC receiver)";
        case PciSubDevice109E0878::SUBDEVICE_127A0001: return "Bt878 Video Capture (Audio Section)";
        case PciSubDevice109E0878::SUBDEVICE_127A0002: return "Bt878 Video Capture (Audio Section)";
        case PciSubDevice109E0878::SUBDEVICE_127A0003: return "Bt878 Video Capture (Audio Section)";
        case PciSubDevice109E0878::SUBDEVICE_127A0048: return "Bt878 Video Capture (Audio Section)";
        case PciSubDevice109E0878::SUBDEVICE_13E90070: return "Win/TV (Audio Section)";
        case PciSubDevice109E0878::SUBDEVICE_144F3000: return "MagicTView CPH060 - Audio";
        case PciSubDevice109E0878::SUBDEVICE_14610002: return "Avermedia PCTV98 Audio Capture";
        case PciSubDevice109E0878::SUBDEVICE_14610003: return "UltraTV PCI 350";
        case PciSubDevice109E0878::SUBDEVICE_14610004: return "AVerTV WDM Audio Capture";
        case PciSubDevice109E0878::SUBDEVICE_14610761: return "AVerTV DVB-T";
        case PciSubDevice109E0878::SUBDEVICE_14610771: return "AverMedia AVerTV DVB-T 771";
        case PciSubDevice109E0878::SUBDEVICE_14F10001: return "Bt878 Video Capture (Audio Section)";
        case PciSubDevice109E0878::SUBDEVICE_14F10002: return "Bt878 Video Capture (Audio Section)";
        case PciSubDevice109E0878::SUBDEVICE_14F10003: return "Bt878 Video Capture (Audio Section)";
        case PciSubDevice109E0878::SUBDEVICE_14F10048: return "Bt878 Video Capture (Audio Section)";
        case PciSubDevice109E0878::SUBDEVICE_18220001: return "VisionPlus DVB Card";
        case PciSubDevice109E0878::SUBDEVICE_18ACD500: return "DViCO FusionHDTV5 Lite";
        case PciSubDevice109E0878::SUBDEVICE_270FFC00: return "Digitop DTT-1000";
        case PciSubDevice109E0878::SUBDEVICE_BD111200: return "PCTV pro (TV + FM stereo receiver, audio section)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR109E_PCISUBDEVICE109E0878_H
