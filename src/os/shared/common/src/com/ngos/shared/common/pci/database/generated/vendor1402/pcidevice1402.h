// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1402_PCIDEVICE1402_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1402_PCIDEVICE1402_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1402: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0630 = 0x0630,
    DEVICE_0940 = 0x0940,
    DEVICE_0950 = 0x0950,
    DEVICE_0960 = 0x0960,
    DEVICE_1000 = 0x1000,
    DEVICE_100A = 0x100A,
    DEVICE_100B = 0x100B,
    DEVICE_1400 = 0x1400,
    DEVICE_140A = 0x140A,
    DEVICE_140B = 0x140B,
    DEVICE_140C = 0x140C,
    DEVICE_140D = 0x140D,
    DEVICE_140E = 0x140E,
    DEVICE_14EA = 0x14EA,
    DEVICE_14EB = 0x14EB,
    DEVICE_1604 = 0x1604,
    DEVICE_1608 = 0x1608,
    DEVICE_160C = 0x160C,
    DEVICE_160F = 0x160F,
    DEVICE_168F = 0x168F,
    DEVICE_4610 = 0x4610,
    DEVICE_4650 = 0x4650,
    DEVICE_4660 = 0x4660,
    DEVICE_4661 = 0x4661,
    DEVICE_4662 = 0x4662,
    DEVICE_4663 = 0x4663,
    DEVICE_4670 = 0x4670,
    DEVICE_4671 = 0x4671,
    DEVICE_4672 = 0x4672,
    DEVICE_4673 = 0x4673,
    DEVICE_4680 = 0x4680,
    DEVICE_4681 = 0x4681,
    DEVICE_4682 = 0x4682,
    DEVICE_4683 = 0x4683,
    DEVICE_6004 = 0x6004,
    DEVICE_6008 = 0x6008,
    DEVICE_600F = 0x600F,
    DEVICE_6014 = 0x6014,
    DEVICE_6018 = 0x6018,
    DEVICE_601F = 0x601F,
    DEVICE_6034 = 0x6034,
    DEVICE_6038 = 0x6038,
    DEVICE_603F = 0x603F,
    DEVICE_6044 = 0x6044,
    DEVICE_6048 = 0x6048,
    DEVICE_604F = 0x604F,
    DEVICE_6054 = 0x6054,
    DEVICE_6058 = 0x6058,
    DEVICE_605F = 0x605F,
    DEVICE_6074 = 0x6074,
    DEVICE_6078 = 0x6078,
    DEVICE_607F = 0x607F,
    DEVICE_6104 = 0x6104,
    DEVICE_6108 = 0x6108,
    DEVICE_610F = 0x610F,
    DEVICE_6114 = 0x6114,
    DEVICE_6118 = 0x6118,
    DEVICE_611F = 0x611F,
    DEVICE_6134 = 0x6134,
    DEVICE_6138 = 0x6138,
    DEVICE_613F = 0x613F,
    DEVICE_6144 = 0x6144,
    DEVICE_6148 = 0x6148,
    DEVICE_614F = 0x614F,
    DEVICE_6154 = 0x6154,
    DEVICE_6158 = 0x6158,
    DEVICE_615F = 0x615F,
    DEVICE_6174 = 0x6174,
    DEVICE_6178 = 0x6178,
    DEVICE_617F = 0x617F,
    DEVICE_6259 = 0x6259,
    DEVICE_6359 = 0x6359,
    DEVICE_810A = 0x810A,
    DEVICE_810B = 0x810B,
    DEVICE_820A = 0x820A,
    DEVICE_820B = 0x820B
};



inline const char8* enumToString(PciDevice1402 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1402::NONE:        return "NONE";
        case PciDevice1402::DEVICE_0630: return "DEVICE_0630";
        case PciDevice1402::DEVICE_0940: return "DEVICE_0940";
        case PciDevice1402::DEVICE_0950: return "DEVICE_0950";
        case PciDevice1402::DEVICE_0960: return "DEVICE_0960";
        case PciDevice1402::DEVICE_1000: return "DEVICE_1000";
        case PciDevice1402::DEVICE_100A: return "DEVICE_100A";
        case PciDevice1402::DEVICE_100B: return "DEVICE_100B";
        case PciDevice1402::DEVICE_1400: return "DEVICE_1400";
        case PciDevice1402::DEVICE_140A: return "DEVICE_140A";
        case PciDevice1402::DEVICE_140B: return "DEVICE_140B";
        case PciDevice1402::DEVICE_140C: return "DEVICE_140C";
        case PciDevice1402::DEVICE_140D: return "DEVICE_140D";
        case PciDevice1402::DEVICE_140E: return "DEVICE_140E";
        case PciDevice1402::DEVICE_14EA: return "DEVICE_14EA";
        case PciDevice1402::DEVICE_14EB: return "DEVICE_14EB";
        case PciDevice1402::DEVICE_1604: return "DEVICE_1604";
        case PciDevice1402::DEVICE_1608: return "DEVICE_1608";
        case PciDevice1402::DEVICE_160C: return "DEVICE_160C";
        case PciDevice1402::DEVICE_160F: return "DEVICE_160F";
        case PciDevice1402::DEVICE_168F: return "DEVICE_168F";
        case PciDevice1402::DEVICE_4610: return "DEVICE_4610";
        case PciDevice1402::DEVICE_4650: return "DEVICE_4650";
        case PciDevice1402::DEVICE_4660: return "DEVICE_4660";
        case PciDevice1402::DEVICE_4661: return "DEVICE_4661";
        case PciDevice1402::DEVICE_4662: return "DEVICE_4662";
        case PciDevice1402::DEVICE_4663: return "DEVICE_4663";
        case PciDevice1402::DEVICE_4670: return "DEVICE_4670";
        case PciDevice1402::DEVICE_4671: return "DEVICE_4671";
        case PciDevice1402::DEVICE_4672: return "DEVICE_4672";
        case PciDevice1402::DEVICE_4673: return "DEVICE_4673";
        case PciDevice1402::DEVICE_4680: return "DEVICE_4680";
        case PciDevice1402::DEVICE_4681: return "DEVICE_4681";
        case PciDevice1402::DEVICE_4682: return "DEVICE_4682";
        case PciDevice1402::DEVICE_4683: return "DEVICE_4683";
        case PciDevice1402::DEVICE_6004: return "DEVICE_6004";
        case PciDevice1402::DEVICE_6008: return "DEVICE_6008";
        case PciDevice1402::DEVICE_600F: return "DEVICE_600F";
        case PciDevice1402::DEVICE_6014: return "DEVICE_6014";
        case PciDevice1402::DEVICE_6018: return "DEVICE_6018";
        case PciDevice1402::DEVICE_601F: return "DEVICE_601F";
        case PciDevice1402::DEVICE_6034: return "DEVICE_6034";
        case PciDevice1402::DEVICE_6038: return "DEVICE_6038";
        case PciDevice1402::DEVICE_603F: return "DEVICE_603F";
        case PciDevice1402::DEVICE_6044: return "DEVICE_6044";
        case PciDevice1402::DEVICE_6048: return "DEVICE_6048";
        case PciDevice1402::DEVICE_604F: return "DEVICE_604F";
        case PciDevice1402::DEVICE_6054: return "DEVICE_6054";
        case PciDevice1402::DEVICE_6058: return "DEVICE_6058";
        case PciDevice1402::DEVICE_605F: return "DEVICE_605F";
        case PciDevice1402::DEVICE_6074: return "DEVICE_6074";
        case PciDevice1402::DEVICE_6078: return "DEVICE_6078";
        case PciDevice1402::DEVICE_607F: return "DEVICE_607F";
        case PciDevice1402::DEVICE_6104: return "DEVICE_6104";
        case PciDevice1402::DEVICE_6108: return "DEVICE_6108";
        case PciDevice1402::DEVICE_610F: return "DEVICE_610F";
        case PciDevice1402::DEVICE_6114: return "DEVICE_6114";
        case PciDevice1402::DEVICE_6118: return "DEVICE_6118";
        case PciDevice1402::DEVICE_611F: return "DEVICE_611F";
        case PciDevice1402::DEVICE_6134: return "DEVICE_6134";
        case PciDevice1402::DEVICE_6138: return "DEVICE_6138";
        case PciDevice1402::DEVICE_613F: return "DEVICE_613F";
        case PciDevice1402::DEVICE_6144: return "DEVICE_6144";
        case PciDevice1402::DEVICE_6148: return "DEVICE_6148";
        case PciDevice1402::DEVICE_614F: return "DEVICE_614F";
        case PciDevice1402::DEVICE_6154: return "DEVICE_6154";
        case PciDevice1402::DEVICE_6158: return "DEVICE_6158";
        case PciDevice1402::DEVICE_615F: return "DEVICE_615F";
        case PciDevice1402::DEVICE_6174: return "DEVICE_6174";
        case PciDevice1402::DEVICE_6178: return "DEVICE_6178";
        case PciDevice1402::DEVICE_617F: return "DEVICE_617F";
        case PciDevice1402::DEVICE_6259: return "DEVICE_6259";
        case PciDevice1402::DEVICE_6359: return "DEVICE_6359";
        case PciDevice1402::DEVICE_810A: return "DEVICE_810A";
        case PciDevice1402::DEVICE_810B: return "DEVICE_810B";
        case PciDevice1402::DEVICE_820A: return "DEVICE_820A";
        case PciDevice1402::DEVICE_820B: return "DEVICE_820B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1402 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1402 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1402::DEVICE_0630: return "ME-630";
        case PciDevice1402::DEVICE_0940: return "ME-94";
        case PciDevice1402::DEVICE_0950: return "ME-95";
        case PciDevice1402::DEVICE_0960: return "ME-96";
        case PciDevice1402::DEVICE_1000: return "ME-1000";
        case PciDevice1402::DEVICE_100A: return "ME-1000";
        case PciDevice1402::DEVICE_100B: return "ME-1000";
        case PciDevice1402::DEVICE_1400: return "ME-1400";
        case PciDevice1402::DEVICE_140A: return "ME-1400A";
        case PciDevice1402::DEVICE_140B: return "ME-1400B";
        case PciDevice1402::DEVICE_140C: return "ME-1400C";
        case PciDevice1402::DEVICE_140D: return "ME-1400D";
        case PciDevice1402::DEVICE_140E: return "ME-1400E";
        case PciDevice1402::DEVICE_14EA: return "ME-1400EA";
        case PciDevice1402::DEVICE_14EB: return "ME-1400EB";
        case PciDevice1402::DEVICE_1604: return "ME-1600/4U";
        case PciDevice1402::DEVICE_1608: return "ME-1600/8U";
        case PciDevice1402::DEVICE_160C: return "ME-1600/12U";
        case PciDevice1402::DEVICE_160F: return "ME-1600/16U";
        case PciDevice1402::DEVICE_168F: return "ME-1600/16u8I";
        case PciDevice1402::DEVICE_4610: return "ME-4610";
        case PciDevice1402::DEVICE_4650: return "ME-4650";
        case PciDevice1402::DEVICE_4660: return "ME-4660";
        case PciDevice1402::DEVICE_4661: return "ME-4660I";
        case PciDevice1402::DEVICE_4662: return "ME-4660";
        case PciDevice1402::DEVICE_4663: return "ME-4660I";
        case PciDevice1402::DEVICE_4670: return "ME-4670";
        case PciDevice1402::DEVICE_4671: return "ME-4670I";
        case PciDevice1402::DEVICE_4672: return "ME-4670S";
        case PciDevice1402::DEVICE_4673: return "ME-4670IS";
        case PciDevice1402::DEVICE_4680: return "ME-4680";
        case PciDevice1402::DEVICE_4681: return "ME-4680I";
        case PciDevice1402::DEVICE_4682: return "ME-4680S";
        case PciDevice1402::DEVICE_4683: return "ME-4680IS";
        case PciDevice1402::DEVICE_6004: return "ME-6000/4";
        case PciDevice1402::DEVICE_6008: return "ME-6000/8";
        case PciDevice1402::DEVICE_600F: return "ME-6000/16";
        case PciDevice1402::DEVICE_6014: return "ME-6000I/4";
        case PciDevice1402::DEVICE_6018: return "ME-6000I/8";
        case PciDevice1402::DEVICE_601F: return "ME-6000I/16";
        case PciDevice1402::DEVICE_6034: return "ME-6000ISLE/4";
        case PciDevice1402::DEVICE_6038: return "ME-6000ISLE/8";
        case PciDevice1402::DEVICE_603F: return "ME-6000ISLE/16";
        case PciDevice1402::DEVICE_6044: return "ME-6000/4/DIO";
        case PciDevice1402::DEVICE_6048: return "ME-6000/8/DIO";
        case PciDevice1402::DEVICE_604F: return "ME-6000/16/DIO";
        case PciDevice1402::DEVICE_6054: return "ME-6000I/4/DIO";
        case PciDevice1402::DEVICE_6058: return "ME-6000I/8/DIO";
        case PciDevice1402::DEVICE_605F: return "ME-6000I/16/DIO";
        case PciDevice1402::DEVICE_6074: return "ME-6000ISLE/4/DIO";
        case PciDevice1402::DEVICE_6078: return "ME-6000ISLE/8/DIO";
        case PciDevice1402::DEVICE_607F: return "ME-6000ISLE/16/DIO";
        case PciDevice1402::DEVICE_6104: return "ME-6100/4";
        case PciDevice1402::DEVICE_6108: return "ME-6100/8";
        case PciDevice1402::DEVICE_610F: return "ME-6100/16";
        case PciDevice1402::DEVICE_6114: return "ME-6100I/4";
        case PciDevice1402::DEVICE_6118: return "ME-6100I/8";
        case PciDevice1402::DEVICE_611F: return "ME-6100I/16";
        case PciDevice1402::DEVICE_6134: return "ME-6100ISLE/4";
        case PciDevice1402::DEVICE_6138: return "ME-6100ISLE/8";
        case PciDevice1402::DEVICE_613F: return "ME-6100ISLE/16";
        case PciDevice1402::DEVICE_6144: return "ME-6100/4/DIO";
        case PciDevice1402::DEVICE_6148: return "ME-6100/8/DIO";
        case PciDevice1402::DEVICE_614F: return "ME-6100/16/DIO";
        case PciDevice1402::DEVICE_6154: return "ME-6100I/4/DIO";
        case PciDevice1402::DEVICE_6158: return "ME-6100I/8/DIO";
        case PciDevice1402::DEVICE_615F: return "ME-6100I/16/DIO";
        case PciDevice1402::DEVICE_6174: return "ME-6100ISLE/4/DIO";
        case PciDevice1402::DEVICE_6178: return "ME-6100ISLE/8/DIO";
        case PciDevice1402::DEVICE_617F: return "ME-6100ISLE/16/DIO";
        case PciDevice1402::DEVICE_6259: return "ME-6200I/9/DIO";
        case PciDevice1402::DEVICE_6359: return "ME-6300I/9/DIO";
        case PciDevice1402::DEVICE_810A: return "ME-8100A";
        case PciDevice1402::DEVICE_810B: return "ME-8100B";
        case PciDevice1402::DEVICE_820A: return "ME-8200A";
        case PciDevice1402::DEVICE_820B: return "ME-8200B";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1402_PCIDEVICE1402_H
