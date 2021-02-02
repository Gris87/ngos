// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR109E_PCISUBDEVICE109E036F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR109E_PCISUBDEVICE109E036F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice109E036F: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_127A0044 = 0x127A0044,
    SUBDEVICE_127A0122 = 0x127A0122,
    SUBDEVICE_127A0144 = 0x127A0144,
    SUBDEVICE_127A0222 = 0x127A0222,
    SUBDEVICE_127A0244 = 0x127A0244,
    SUBDEVICE_127A0322 = 0x127A0322,
    SUBDEVICE_127A0422 = 0x127A0422,
    SUBDEVICE_127A1122 = 0x127A1122,
    SUBDEVICE_127A1222 = 0x127A1222,
    SUBDEVICE_127A1322 = 0x127A1322,
    SUBDEVICE_127A1522 = 0x127A1522,
    SUBDEVICE_127A1622 = 0x127A1622,
    SUBDEVICE_127A1722 = 0x127A1722,
    SUBDEVICE_14F10044 = 0x14F10044,
    SUBDEVICE_14F10122 = 0x14F10122,
    SUBDEVICE_14F10144 = 0x14F10144,
    SUBDEVICE_14F10222 = 0x14F10222,
    SUBDEVICE_14F10244 = 0x14F10244,
    SUBDEVICE_14F10322 = 0x14F10322,
    SUBDEVICE_14F10422 = 0x14F10422,
    SUBDEVICE_14F11122 = 0x14F11122,
    SUBDEVICE_14F11222 = 0x14F11222,
    SUBDEVICE_14F11322 = 0x14F11322,
    SUBDEVICE_14F11522 = 0x14F11522,
    SUBDEVICE_14F11622 = 0x14F11622,
    SUBDEVICE_14F11722 = 0x14F11722,
    SUBDEVICE_18511850 = 0x18511850,
    SUBDEVICE_18511851 = 0x18511851,
    SUBDEVICE_18521852 = 0x18521852
};



inline const char8* enumToString(PciSubDevice109E036F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice109E036F::NONE:               return "NONE";
        case PciSubDevice109E036F::SUBDEVICE_127A0044: return "SUBDEVICE_127A0044";
        case PciSubDevice109E036F::SUBDEVICE_127A0122: return "SUBDEVICE_127A0122";
        case PciSubDevice109E036F::SUBDEVICE_127A0144: return "SUBDEVICE_127A0144";
        case PciSubDevice109E036F::SUBDEVICE_127A0222: return "SUBDEVICE_127A0222";
        case PciSubDevice109E036F::SUBDEVICE_127A0244: return "SUBDEVICE_127A0244";
        case PciSubDevice109E036F::SUBDEVICE_127A0322: return "SUBDEVICE_127A0322";
        case PciSubDevice109E036F::SUBDEVICE_127A0422: return "SUBDEVICE_127A0422";
        case PciSubDevice109E036F::SUBDEVICE_127A1122: return "SUBDEVICE_127A1122";
        case PciSubDevice109E036F::SUBDEVICE_127A1222: return "SUBDEVICE_127A1222";
        case PciSubDevice109E036F::SUBDEVICE_127A1322: return "SUBDEVICE_127A1322";
        case PciSubDevice109E036F::SUBDEVICE_127A1522: return "SUBDEVICE_127A1522";
        case PciSubDevice109E036F::SUBDEVICE_127A1622: return "SUBDEVICE_127A1622";
        case PciSubDevice109E036F::SUBDEVICE_127A1722: return "SUBDEVICE_127A1722";
        case PciSubDevice109E036F::SUBDEVICE_14F10044: return "SUBDEVICE_14F10044";
        case PciSubDevice109E036F::SUBDEVICE_14F10122: return "SUBDEVICE_14F10122";
        case PciSubDevice109E036F::SUBDEVICE_14F10144: return "SUBDEVICE_14F10144";
        case PciSubDevice109E036F::SUBDEVICE_14F10222: return "SUBDEVICE_14F10222";
        case PciSubDevice109E036F::SUBDEVICE_14F10244: return "SUBDEVICE_14F10244";
        case PciSubDevice109E036F::SUBDEVICE_14F10322: return "SUBDEVICE_14F10322";
        case PciSubDevice109E036F::SUBDEVICE_14F10422: return "SUBDEVICE_14F10422";
        case PciSubDevice109E036F::SUBDEVICE_14F11122: return "SUBDEVICE_14F11122";
        case PciSubDevice109E036F::SUBDEVICE_14F11222: return "SUBDEVICE_14F11222";
        case PciSubDevice109E036F::SUBDEVICE_14F11322: return "SUBDEVICE_14F11322";
        case PciSubDevice109E036F::SUBDEVICE_14F11522: return "SUBDEVICE_14F11522";
        case PciSubDevice109E036F::SUBDEVICE_14F11622: return "SUBDEVICE_14F11622";
        case PciSubDevice109E036F::SUBDEVICE_14F11722: return "SUBDEVICE_14F11722";
        case PciSubDevice109E036F::SUBDEVICE_18511850: return "SUBDEVICE_18511850";
        case PciSubDevice109E036F::SUBDEVICE_18511851: return "SUBDEVICE_18511851";
        case PciSubDevice109E036F::SUBDEVICE_18521852: return "SUBDEVICE_18521852";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice109E036F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice109E036F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice109E036F::SUBDEVICE_127A0044: return "Bt879 Video Capture NTSC";
        case PciSubDevice109E036F::SUBDEVICE_127A0122: return "Bt879 Video Capture PAL I";
        case PciSubDevice109E036F::SUBDEVICE_127A0144: return "Bt879 Video Capture NTSC";
        case PciSubDevice109E036F::SUBDEVICE_127A0222: return "Bt879 Video Capture PAL BG";
        case PciSubDevice109E036F::SUBDEVICE_127A0244: return "Bt879a Video Capture NTSC";
        case PciSubDevice109E036F::SUBDEVICE_127A0322: return "Bt879 Video Capture NTSC";
        case PciSubDevice109E036F::SUBDEVICE_127A0422: return "Bt879 Video Capture NTSC";
        case PciSubDevice109E036F::SUBDEVICE_127A1122: return "Bt879 Video Capture PAL I";
        case PciSubDevice109E036F::SUBDEVICE_127A1222: return "Bt879 Video Capture PAL BG";
        case PciSubDevice109E036F::SUBDEVICE_127A1322: return "Bt879 Video Capture NTSC";
        case PciSubDevice109E036F::SUBDEVICE_127A1522: return "Bt879a Video Capture PAL I";
        case PciSubDevice109E036F::SUBDEVICE_127A1622: return "Bt879a Video Capture PAL BG";
        case PciSubDevice109E036F::SUBDEVICE_127A1722: return "Bt879a Video Capture NTSC";
        case PciSubDevice109E036F::SUBDEVICE_14F10044: return "Bt879 Video Capture NTSC";
        case PciSubDevice109E036F::SUBDEVICE_14F10122: return "Bt879 Video Capture PAL I";
        case PciSubDevice109E036F::SUBDEVICE_14F10144: return "Bt879 Video Capture NTSC";
        case PciSubDevice109E036F::SUBDEVICE_14F10222: return "Bt879 Video Capture PAL BG";
        case PciSubDevice109E036F::SUBDEVICE_14F10244: return "Bt879a Video Capture NTSC";
        case PciSubDevice109E036F::SUBDEVICE_14F10322: return "Bt879 Video Capture NTSC";
        case PciSubDevice109E036F::SUBDEVICE_14F10422: return "Bt879 Video Capture NTSC";
        case PciSubDevice109E036F::SUBDEVICE_14F11122: return "Bt879 Video Capture PAL I";
        case PciSubDevice109E036F::SUBDEVICE_14F11222: return "Bt879 Video Capture PAL BG";
        case PciSubDevice109E036F::SUBDEVICE_14F11322: return "Bt879 Video Capture NTSC";
        case PciSubDevice109E036F::SUBDEVICE_14F11522: return "Bt879a Video Capture PAL I";
        case PciSubDevice109E036F::SUBDEVICE_14F11622: return "Bt879a Video Capture PAL BG";
        case PciSubDevice109E036F::SUBDEVICE_14F11722: return "Bt879a Video Capture NTSC";
        case PciSubDevice109E036F::SUBDEVICE_18511850: return "FlyVideo'98 - Video";
        case PciSubDevice109E036F::SUBDEVICE_18511851: return "FlyVideo II";
        case PciSubDevice109E036F::SUBDEVICE_18521852: return "FlyVideo'98 - Video (with FM Tuner)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR109E_PCISUBDEVICE109E036F_H
