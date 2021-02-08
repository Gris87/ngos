// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR109E_PCISUBDEVICE109E036E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR109E_PCISUBDEVICE109E036E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice109E036E: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_00000001 = 0x00000001,
    SUBDEVICE_007013EB = 0x007013EB,
    SUBDEVICE_0070FF01 = 0x0070FF01,
    SUBDEVICE_00710101 = 0x00710101,
    SUBDEVICE_107D6606 = 0x107D6606,
    SUBDEVICE_11BD0012 = 0x11BD0012,
    SUBDEVICE_11BD001C = 0x11BD001C,
    SUBDEVICE_127A0001 = 0x127A0001,
    SUBDEVICE_127A0002 = 0x127A0002,
    SUBDEVICE_127A0003 = 0x127A0003,
    SUBDEVICE_127A0048 = 0x127A0048,
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
    SUBDEVICE_18511850 = 0x18511850,
    SUBDEVICE_18511851 = 0x18511851,
    SUBDEVICE_18521852 = 0x18521852,
    SUBDEVICE_18ACD500 = 0x18ACD500,
    SUBDEVICE_270FFC00 = 0x270FFC00,
    SUBDEVICE_AA001460 = 0xAA001460,
    SUBDEVICE_AA011461 = 0xAA011461,
    SUBDEVICE_AA021462 = 0xAA021462,
    SUBDEVICE_AA031463 = 0xAA031463,
    SUBDEVICE_AA041464 = 0xAA041464,
    SUBDEVICE_AA051465 = 0xAA051465,
    SUBDEVICE_AA061466 = 0xAA061466,
    SUBDEVICE_AA071467 = 0xAA071467,
    SUBDEVICE_AA081468 = 0xAA081468,
    SUBDEVICE_AA091469 = 0xAA091469,
    SUBDEVICE_AA0A146A = 0xAA0A146A,
    SUBDEVICE_AA0B146B = 0xAA0B146B,
    SUBDEVICE_AA0C146C = 0xAA0C146C,
    SUBDEVICE_AA0D146D = 0xAA0D146D,
    SUBDEVICE_AA0E146E = 0xAA0E146E,
    SUBDEVICE_AA0F146F = 0xAA0F146F,
    SUBDEVICE_BD111200 = 0xBD111200
};



inline const char8* enumToString(PciSubDevice109E036E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice109E036E::NONE:               return "NONE";
        case PciSubDevice109E036E::SUBDEVICE_00000001: return "SUBDEVICE_00000001";
        case PciSubDevice109E036E::SUBDEVICE_007013EB: return "SUBDEVICE_007013EB";
        case PciSubDevice109E036E::SUBDEVICE_0070FF01: return "SUBDEVICE_0070FF01";
        case PciSubDevice109E036E::SUBDEVICE_00710101: return "SUBDEVICE_00710101";
        case PciSubDevice109E036E::SUBDEVICE_107D6606: return "SUBDEVICE_107D6606";
        case PciSubDevice109E036E::SUBDEVICE_11BD0012: return "SUBDEVICE_11BD0012";
        case PciSubDevice109E036E::SUBDEVICE_11BD001C: return "SUBDEVICE_11BD001C";
        case PciSubDevice109E036E::SUBDEVICE_127A0001: return "SUBDEVICE_127A0001";
        case PciSubDevice109E036E::SUBDEVICE_127A0002: return "SUBDEVICE_127A0002";
        case PciSubDevice109E036E::SUBDEVICE_127A0003: return "SUBDEVICE_127A0003";
        case PciSubDevice109E036E::SUBDEVICE_127A0048: return "SUBDEVICE_127A0048";
        case PciSubDevice109E036E::SUBDEVICE_144F3000: return "SUBDEVICE_144F3000";
        case PciSubDevice109E036E::SUBDEVICE_14610002: return "SUBDEVICE_14610002";
        case PciSubDevice109E036E::SUBDEVICE_14610003: return "SUBDEVICE_14610003";
        case PciSubDevice109E036E::SUBDEVICE_14610004: return "SUBDEVICE_14610004";
        case PciSubDevice109E036E::SUBDEVICE_14610761: return "SUBDEVICE_14610761";
        case PciSubDevice109E036E::SUBDEVICE_14610771: return "SUBDEVICE_14610771";
        case PciSubDevice109E036E::SUBDEVICE_14F10001: return "SUBDEVICE_14F10001";
        case PciSubDevice109E036E::SUBDEVICE_14F10002: return "SUBDEVICE_14F10002";
        case PciSubDevice109E036E::SUBDEVICE_14F10003: return "SUBDEVICE_14F10003";
        case PciSubDevice109E036E::SUBDEVICE_14F10048: return "SUBDEVICE_14F10048";
        case PciSubDevice109E036E::SUBDEVICE_18220001: return "SUBDEVICE_18220001";
        case PciSubDevice109E036E::SUBDEVICE_18511850: return "SUBDEVICE_18511850";
        case PciSubDevice109E036E::SUBDEVICE_18511851: return "SUBDEVICE_18511851";
        case PciSubDevice109E036E::SUBDEVICE_18521852: return "SUBDEVICE_18521852";
        case PciSubDevice109E036E::SUBDEVICE_18ACD500: return "SUBDEVICE_18ACD500";
        case PciSubDevice109E036E::SUBDEVICE_270FFC00: return "SUBDEVICE_270FFC00";
        case PciSubDevice109E036E::SUBDEVICE_AA001460: return "SUBDEVICE_AA001460";
        case PciSubDevice109E036E::SUBDEVICE_AA011461: return "SUBDEVICE_AA011461";
        case PciSubDevice109E036E::SUBDEVICE_AA021462: return "SUBDEVICE_AA021462";
        case PciSubDevice109E036E::SUBDEVICE_AA031463: return "SUBDEVICE_AA031463";
        case PciSubDevice109E036E::SUBDEVICE_AA041464: return "SUBDEVICE_AA041464";
        case PciSubDevice109E036E::SUBDEVICE_AA051465: return "SUBDEVICE_AA051465";
        case PciSubDevice109E036E::SUBDEVICE_AA061466: return "SUBDEVICE_AA061466";
        case PciSubDevice109E036E::SUBDEVICE_AA071467: return "SUBDEVICE_AA071467";
        case PciSubDevice109E036E::SUBDEVICE_AA081468: return "SUBDEVICE_AA081468";
        case PciSubDevice109E036E::SUBDEVICE_AA091469: return "SUBDEVICE_AA091469";
        case PciSubDevice109E036E::SUBDEVICE_AA0A146A: return "SUBDEVICE_AA0A146A";
        case PciSubDevice109E036E::SUBDEVICE_AA0B146B: return "SUBDEVICE_AA0B146B";
        case PciSubDevice109E036E::SUBDEVICE_AA0C146C: return "SUBDEVICE_AA0C146C";
        case PciSubDevice109E036E::SUBDEVICE_AA0D146D: return "SUBDEVICE_AA0D146D";
        case PciSubDevice109E036E::SUBDEVICE_AA0E146E: return "SUBDEVICE_AA0E146E";
        case PciSubDevice109E036E::SUBDEVICE_AA0F146F: return "SUBDEVICE_AA0F146F";
        case PciSubDevice109E036E::SUBDEVICE_BD111200: return "SUBDEVICE_BD111200";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice109E036E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice109E036E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice109E036E::SUBDEVICE_00000001: return "Euresys Picolo PCIe";
        case PciSubDevice109E036E::SUBDEVICE_007013EB: return "WinTV Series";
        case PciSubDevice109E036E::SUBDEVICE_0070FF01: return "Viewcast Osprey 200";
        case PciSubDevice109E036E::SUBDEVICE_00710101: return "DigiTV PCI";
        case PciSubDevice109E036E::SUBDEVICE_107D6606: return "WinFast TV 2000";
        case PciSubDevice109E036E::SUBDEVICE_11BD0012: return "PCTV pro (TV + FM stereo receiver)";
        case PciSubDevice109E036E::SUBDEVICE_11BD001C: return "PCTV Sat (DBC receiver)";
        case PciSubDevice109E036E::SUBDEVICE_127A0001: return "Bt878 Mediastream Controller NTSC";
        case PciSubDevice109E036E::SUBDEVICE_127A0002: return "Bt878 Mediastream Controller PAL BG";
        case PciSubDevice109E036E::SUBDEVICE_127A0003: return "Bt878a Mediastream Controller PAL BG";
        case PciSubDevice109E036E::SUBDEVICE_127A0048: return "Bt878/832 Mediastream Controller";
        case PciSubDevice109E036E::SUBDEVICE_144F3000: return "MagicTView CPH060 - Video";
        case PciSubDevice109E036E::SUBDEVICE_14610002: return "TV98 Series (TV/No FM/Remote)";
        case PciSubDevice109E036E::SUBDEVICE_14610003: return "AverMedia UltraTV PCI 350";
        case PciSubDevice109E036E::SUBDEVICE_14610004: return "AVerTV WDM Video Capture";
        case PciSubDevice109E036E::SUBDEVICE_14610761: return "AverTV DVB-T";
        case PciSubDevice109E036E::SUBDEVICE_14610771: return "AverMedia AVerTV DVB-T 771";
        case PciSubDevice109E036E::SUBDEVICE_14F10001: return "Bt878 Mediastream Controller NTSC";
        case PciSubDevice109E036E::SUBDEVICE_14F10002: return "Bt878 Mediastream Controller PAL BG";
        case PciSubDevice109E036E::SUBDEVICE_14F10003: return "Bt878a Mediastream Controller PAL BG";
        case PciSubDevice109E036E::SUBDEVICE_14F10048: return "Bt878/832 Mediastream Controller";
        case PciSubDevice109E036E::SUBDEVICE_18220001: return "VisionPlus DVB card";
        case PciSubDevice109E036E::SUBDEVICE_18511850: return "FlyVideo'98 - Video";
        case PciSubDevice109E036E::SUBDEVICE_18511851: return "FlyVideo II";
        case PciSubDevice109E036E::SUBDEVICE_18521852: return "FlyVideo'98 - Video (with FM Tuner)";
        case PciSubDevice109E036E::SUBDEVICE_18ACD500: return "DViCO FusionHDTV5 Lite";
        case PciSubDevice109E036E::SUBDEVICE_270FFC00: return "Digitop DTT-1000";
        case PciSubDevice109E036E::SUBDEVICE_AA001460: return "Spectra8 CardA Input0";
        case PciSubDevice109E036E::SUBDEVICE_AA011461: return "Spectra8 CardA Input1";
        case PciSubDevice109E036E::SUBDEVICE_AA021462: return "Spectra8 CardA Input2";
        case PciSubDevice109E036E::SUBDEVICE_AA031463: return "Spectra8 CardA Input3";
        case PciSubDevice109E036E::SUBDEVICE_AA041464: return "Spectra8 CardB Input0";
        case PciSubDevice109E036E::SUBDEVICE_AA051465: return "Spectra8 CardB Input1";
        case PciSubDevice109E036E::SUBDEVICE_AA061466: return "Spectra8 CardB Input2";
        case PciSubDevice109E036E::SUBDEVICE_AA071467: return "Spectra8 CardB Input3";
        case PciSubDevice109E036E::SUBDEVICE_AA081468: return "Spectra8 CardC Input0";
        case PciSubDevice109E036E::SUBDEVICE_AA091469: return "Spectra8 CardC Input1";
        case PciSubDevice109E036E::SUBDEVICE_AA0A146A: return "Spectra8 CardC Input2";
        case PciSubDevice109E036E::SUBDEVICE_AA0B146B: return "Spectra8 CardC Input3";
        case PciSubDevice109E036E::SUBDEVICE_AA0C146C: return "Spectra8 CardD Input0";
        case PciSubDevice109E036E::SUBDEVICE_AA0D146D: return "Spectra8 CardD Input1";
        case PciSubDevice109E036E::SUBDEVICE_AA0E146E: return "Spectra8 CardD Input2";
        case PciSubDevice109E036E::SUBDEVICE_AA0F146F: return "Spectra8 CardD Input3";
        case PciSubDevice109E036E::SUBDEVICE_BD111200: return "PCTV pro (TV + FM stereo receiver)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR109E_PCISUBDEVICE109E036E_H
