// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCIDEVICE102B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCIDEVICE102B_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice102B: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0010 = 0x0010,
    DEVICE_0100 = 0x0100,
    DEVICE_0518 = 0x0518,
    DEVICE_0519 = 0x0519,
    DEVICE_051A = 0x051A,
    DEVICE_051B = 0x051B,
    DEVICE_051E = 0x051E,
    DEVICE_051F = 0x051F,
    DEVICE_0520 = 0x0520,
    DEVICE_0521 = 0x0521,
    DEVICE_0522 = 0x0522,
    DEVICE_0525 = 0x0525,
    DEVICE_0527 = 0x0527,
    DEVICE_0528 = 0x0528,
    DEVICE_0530 = 0x0530,
    DEVICE_0532 = 0x0532,
    DEVICE_0533 = 0x0533,
    DEVICE_0534 = 0x0534,
    DEVICE_0536 = 0x0536,
    DEVICE_0538 = 0x0538,
    DEVICE_0540 = 0x0540,
    DEVICE_0550 = 0x0550,
    DEVICE_0D10 = 0x0D10,
    DEVICE_1000 = 0x1000,
    DEVICE_1001 = 0x1001,
    DEVICE_2007 = 0x2007,
    DEVICE_2527 = 0x2527,
    DEVICE_2537 = 0x2537,
    DEVICE_2538 = 0x2538,
    DEVICE_2539 = 0x2539,
    DEVICE_4164 = 0x4164,
    DEVICE_43B4 = 0x43B4,
    DEVICE_4510 = 0x4510,
    DEVICE_4536 = 0x4536,
    DEVICE_4686 = 0x4686,
    DEVICE_475B = 0x475B,
    DEVICE_475D = 0x475D,
    DEVICE_475F = 0x475F,
    DEVICE_47A1 = 0x47A1,
    DEVICE_47A2 = 0x47A2,
    DEVICE_47C1 = 0x47C1,
    DEVICE_47C2 = 0x47C2,
    DEVICE_4949 = 0x4949,
    DEVICE_4CDC = 0x4CDC,
    DEVICE_4F54 = 0x4F54,
    DEVICE_4FC5 = 0x4FC5,
    DEVICE_5E10 = 0x5E10,
    DEVICE_6573 = 0x6573
};



inline const char8* enumToString(PciDevice102B device102B) // TEST: NO
{
    // COMMON_LT((" | device102B = %u", device102B)); // Commented to avoid bad looking logs



    switch (device102B)
    {
        case PciDevice102B::NONE:        return "NONE";
        case PciDevice102B::DEVICE_0010: return "DEVICE_0010";
        case PciDevice102B::DEVICE_0100: return "DEVICE_0100";
        case PciDevice102B::DEVICE_0518: return "DEVICE_0518";
        case PciDevice102B::DEVICE_0519: return "DEVICE_0519";
        case PciDevice102B::DEVICE_051A: return "DEVICE_051A";
        case PciDevice102B::DEVICE_051B: return "DEVICE_051B";
        case PciDevice102B::DEVICE_051E: return "DEVICE_051E";
        case PciDevice102B::DEVICE_051F: return "DEVICE_051F";
        case PciDevice102B::DEVICE_0520: return "DEVICE_0520";
        case PciDevice102B::DEVICE_0521: return "DEVICE_0521";
        case PciDevice102B::DEVICE_0522: return "DEVICE_0522";
        case PciDevice102B::DEVICE_0525: return "DEVICE_0525";
        case PciDevice102B::DEVICE_0527: return "DEVICE_0527";
        case PciDevice102B::DEVICE_0528: return "DEVICE_0528";
        case PciDevice102B::DEVICE_0530: return "DEVICE_0530";
        case PciDevice102B::DEVICE_0532: return "DEVICE_0532";
        case PciDevice102B::DEVICE_0533: return "DEVICE_0533";
        case PciDevice102B::DEVICE_0534: return "DEVICE_0534";
        case PciDevice102B::DEVICE_0536: return "DEVICE_0536";
        case PciDevice102B::DEVICE_0538: return "DEVICE_0538";
        case PciDevice102B::DEVICE_0540: return "DEVICE_0540";
        case PciDevice102B::DEVICE_0550: return "DEVICE_0550";
        case PciDevice102B::DEVICE_0D10: return "DEVICE_0D10";
        case PciDevice102B::DEVICE_1000: return "DEVICE_1000";
        case PciDevice102B::DEVICE_1001: return "DEVICE_1001";
        case PciDevice102B::DEVICE_2007: return "DEVICE_2007";
        case PciDevice102B::DEVICE_2527: return "DEVICE_2527";
        case PciDevice102B::DEVICE_2537: return "DEVICE_2537";
        case PciDevice102B::DEVICE_2538: return "DEVICE_2538";
        case PciDevice102B::DEVICE_2539: return "DEVICE_2539";
        case PciDevice102B::DEVICE_4164: return "DEVICE_4164";
        case PciDevice102B::DEVICE_43B4: return "DEVICE_43B4";
        case PciDevice102B::DEVICE_4510: return "DEVICE_4510";
        case PciDevice102B::DEVICE_4536: return "DEVICE_4536";
        case PciDevice102B::DEVICE_4686: return "DEVICE_4686";
        case PciDevice102B::DEVICE_475B: return "DEVICE_475B";
        case PciDevice102B::DEVICE_475D: return "DEVICE_475D";
        case PciDevice102B::DEVICE_475F: return "DEVICE_475F";
        case PciDevice102B::DEVICE_47A1: return "DEVICE_47A1";
        case PciDevice102B::DEVICE_47A2: return "DEVICE_47A2";
        case PciDevice102B::DEVICE_47C1: return "DEVICE_47C1";
        case PciDevice102B::DEVICE_47C2: return "DEVICE_47C2";
        case PciDevice102B::DEVICE_4949: return "DEVICE_4949";
        case PciDevice102B::DEVICE_4CDC: return "DEVICE_4CDC";
        case PciDevice102B::DEVICE_4F54: return "DEVICE_4F54";
        case PciDevice102B::DEVICE_4FC5: return "DEVICE_4FC5";
        case PciDevice102B::DEVICE_5E10: return "DEVICE_5E10";
        case PciDevice102B::DEVICE_6573: return "DEVICE_6573";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice102B device102B) // TEST: NO
{
    // COMMON_LT((" | device102B = %u", device102B)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device102B, enumToString(device102B));

    return res;
}



inline const char8* enumToHumanString(PciDevice102B device102B) // TEST: NO
{
    // COMMON_LT((" | device102B = %u", device102B)); // Commented to avoid bad looking logs



    switch (device102B)
    {
        case PciDevice102B::DEVICE_0010: return "MGA-I [Impression?]";
        case PciDevice102B::DEVICE_0100: return "MGA 1064SG [Mystique]";
        case PciDevice102B::DEVICE_0518: return "MGA-II [Athena]";
        case PciDevice102B::DEVICE_0519: return "MGA 2064W [Millennium]";
        case PciDevice102B::DEVICE_051A: return "MGA 1064SG [Mystique]";
        case PciDevice102B::DEVICE_051B: return "MGA 2164W [Millennium II]";
        case PciDevice102B::DEVICE_051E: return "MGA 1064SG [Mystique] AGP";
        case PciDevice102B::DEVICE_051F: return "MGA 2164W [Millennium II] AGP";
        case PciDevice102B::DEVICE_0520: return "MGA G200";
        case PciDevice102B::DEVICE_0521: return "MGA G200 AGP";
        case PciDevice102B::DEVICE_0522: return "MGA G200e [Pilot] ServerEngines (SEP1)";
        case PciDevice102B::DEVICE_0525: return "MGA G400/G450";
        case PciDevice102B::DEVICE_0527: return "Parhelia";
        case PciDevice102B::DEVICE_0528: return "Parhelia";
        case PciDevice102B::DEVICE_0530: return "MGA G200EV";
        case PciDevice102B::DEVICE_0532: return "MGA G200eW WPCM450";
        case PciDevice102B::DEVICE_0533: return "MGA G200EH";
        case PciDevice102B::DEVICE_0534: return "G200eR2";
        case PciDevice102B::DEVICE_0536: return "Integrated Matrox G200eW3 Graphics Controller";
        case PciDevice102B::DEVICE_0538: return "MGA G200eH3";
        case PciDevice102B::DEVICE_0540: return "M91XX";
        case PciDevice102B::DEVICE_0550: return "SV2";
        case PciDevice102B::DEVICE_0D10: return "MGA Ultima/Impression";
        case PciDevice102B::DEVICE_1000: return "MGA G100 [Productiva]";
        case PciDevice102B::DEVICE_1001: return "MGA G100 [Productiva] AGP";
        case PciDevice102B::DEVICE_2007: return "MGA Mistral";
        case PciDevice102B::DEVICE_2527: return "Millennium G550";
        case PciDevice102B::DEVICE_2537: return "Millennium P650/P750";
        case PciDevice102B::DEVICE_2538: return "Millennium P650 PCIe";
        case PciDevice102B::DEVICE_2539: return "Millennium P690";
        case PciDevice102B::DEVICE_4164: return "Morphis QxT frame grabber";
        case PciDevice102B::DEVICE_43B4: return "Morphis Qxt encoding engine";
        case PciDevice102B::DEVICE_4510: return "Morphis COM port";
        case PciDevice102B::DEVICE_4536: return "VIA Framegrabber";
        case PciDevice102B::DEVICE_4686: return "Concord GX (customized Intel 82541)";
        case PciDevice102B::DEVICE_475B: return "Solios eCL/XCL-B frame grabber";
        case PciDevice102B::DEVICE_475D: return "Vio frame grabber family";
        case PciDevice102B::DEVICE_475F: return "Solios (single-Full) CL frame grabber";
        case PciDevice102B::DEVICE_47A1: return "Solios eA/XA frame grabber";
        case PciDevice102B::DEVICE_47A2: return "Solios COM port";
        case PciDevice102B::DEVICE_47C1: return "Solios (dual-Base/single-Medium) CL frame grabber";
        case PciDevice102B::DEVICE_47C2: return "Solios COM port";
        case PciDevice102B::DEVICE_4949: return "Radient frame grabber family";
        case PciDevice102B::DEVICE_4CDC: return "Morphis JPEG2000 accelerator";
        case PciDevice102B::DEVICE_4F54: return "Morphis (e)Quad frame grabber";
        case PciDevice102B::DEVICE_4FC5: return "Morphis (e)Dual frame grabber";
        case PciDevice102B::DEVICE_5E10: return "Morphis aux I/O";
        case PciDevice102B::DEVICE_6573: return "Shark 10/100 Multiport SwitchNIC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCIDEVICE102B_H
