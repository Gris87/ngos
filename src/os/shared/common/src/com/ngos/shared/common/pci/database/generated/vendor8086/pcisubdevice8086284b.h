// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086284B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086284B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086284B: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1025011F = 0x1025011F,
    SUBDEVICE_10250121 = 0x10250121,
    SUBDEVICE_10250145 = 0x10250145,
    SUBDEVICE_102801DA = 0x102801DA,
    SUBDEVICE_102801F3 = 0x102801F3,
    SUBDEVICE_102801F9 = 0x102801F9,
    SUBDEVICE_102801FF = 0x102801FF,
    SUBDEVICE_1028022F = 0x1028022F,
    SUBDEVICE_10280256 = 0x10280256,
    SUBDEVICE_103C2802 = 0x103C2802,
    SUBDEVICE_103C30C0 = 0x103C30C0,
    SUBDEVICE_103C30C1 = 0x103C30C1,
    SUBDEVICE_103C30CC = 0x103C30CC,
    SUBDEVICE_10431339 = 0x10431339,
    SUBDEVICE_104317F3 = 0x104317F3,
    SUBDEVICE_104381EC = 0x104381EC,
    SUBDEVICE_104D9005 = 0x104D9005,
    SUBDEVICE_104D9008 = 0x104D9008,
    SUBDEVICE_104D9016 = 0x104D9016,
    SUBDEVICE_104D902D = 0x104D902D,
    SUBDEVICE_14F15051 = 0x14F15051,
    SUBDEVICE_17AA20AC = 0x17AA20AC,
    SUBDEVICE_17C04088 = 0x17C04088,
    SUBDEVICE_83847616 = 0x83847616,
    SUBDEVICE_E4BFCC47 = 0xE4BFCC47
};



inline const char8* enumToString(PciSubDevice8086284B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086284B::NONE:               return "NONE";
        case PciSubDevice8086284B::SUBDEVICE_1025011F: return "SUBDEVICE_1025011F";
        case PciSubDevice8086284B::SUBDEVICE_10250121: return "SUBDEVICE_10250121";
        case PciSubDevice8086284B::SUBDEVICE_10250145: return "SUBDEVICE_10250145";
        case PciSubDevice8086284B::SUBDEVICE_102801DA: return "SUBDEVICE_102801DA";
        case PciSubDevice8086284B::SUBDEVICE_102801F3: return "SUBDEVICE_102801F3";
        case PciSubDevice8086284B::SUBDEVICE_102801F9: return "SUBDEVICE_102801F9";
        case PciSubDevice8086284B::SUBDEVICE_102801FF: return "SUBDEVICE_102801FF";
        case PciSubDevice8086284B::SUBDEVICE_1028022F: return "SUBDEVICE_1028022F";
        case PciSubDevice8086284B::SUBDEVICE_10280256: return "SUBDEVICE_10280256";
        case PciSubDevice8086284B::SUBDEVICE_103C2802: return "SUBDEVICE_103C2802";
        case PciSubDevice8086284B::SUBDEVICE_103C30C0: return "SUBDEVICE_103C30C0";
        case PciSubDevice8086284B::SUBDEVICE_103C30C1: return "SUBDEVICE_103C30C1";
        case PciSubDevice8086284B::SUBDEVICE_103C30CC: return "SUBDEVICE_103C30CC";
        case PciSubDevice8086284B::SUBDEVICE_10431339: return "SUBDEVICE_10431339";
        case PciSubDevice8086284B::SUBDEVICE_104317F3: return "SUBDEVICE_104317F3";
        case PciSubDevice8086284B::SUBDEVICE_104381EC: return "SUBDEVICE_104381EC";
        case PciSubDevice8086284B::SUBDEVICE_104D9005: return "SUBDEVICE_104D9005";
        case PciSubDevice8086284B::SUBDEVICE_104D9008: return "SUBDEVICE_104D9008";
        case PciSubDevice8086284B::SUBDEVICE_104D9016: return "SUBDEVICE_104D9016";
        case PciSubDevice8086284B::SUBDEVICE_104D902D: return "SUBDEVICE_104D902D";
        case PciSubDevice8086284B::SUBDEVICE_14F15051: return "SUBDEVICE_14F15051";
        case PciSubDevice8086284B::SUBDEVICE_17AA20AC: return "SUBDEVICE_17AA20AC";
        case PciSubDevice8086284B::SUBDEVICE_17C04088: return "SUBDEVICE_17C04088";
        case PciSubDevice8086284B::SUBDEVICE_83847616: return "SUBDEVICE_83847616";
        case PciSubDevice8086284B::SUBDEVICE_E4BFCC47: return "SUBDEVICE_E4BFCC47";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086284B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086284B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086284B::SUBDEVICE_1025011F: return "Realtek ALC268 audio codec";
        case PciSubDevice8086284B::SUBDEVICE_10250121: return "Aspire 5920G";
        case PciSubDevice8086284B::SUBDEVICE_10250145: return "Realtek ALC889 (Aspire 8920G w. Dolby Theater)";
        case PciSubDevice8086284B::SUBDEVICE_102801DA: return "OptiPlex 745";
        case PciSubDevice8086284B::SUBDEVICE_102801F3: return "Inspiron 1420";
        case PciSubDevice8086284B::SUBDEVICE_102801F9: return "Latitude D630";
        case PciSubDevice8086284B::SUBDEVICE_102801FF: return "Precision M4300";
        case PciSubDevice8086284B::SUBDEVICE_1028022F: return "Inspiron 1525";
        case PciSubDevice8086284B::SUBDEVICE_10280256: return "Studio 1735";
        case PciSubDevice8086284B::SUBDEVICE_103C2802: return "Compaq dc7700p";
        case PciSubDevice8086284B::SUBDEVICE_103C30C0: return "Compaq 6710b";
        case PciSubDevice8086284B::SUBDEVICE_103C30C1: return "Compaq 6910p";
        case PciSubDevice8086284B::SUBDEVICE_103C30CC: return "Pavilion dv6700";
        case PciSubDevice8086284B::SUBDEVICE_10431339: return "M51S series";
        case PciSubDevice8086284B::SUBDEVICE_104317F3: return "X58LE";
        case PciSubDevice8086284B::SUBDEVICE_104381EC: return "P5B";
        case PciSubDevice8086284B::SUBDEVICE_104D9005: return "Vaio VGN-FZ260E";
        case PciSubDevice8086284B::SUBDEVICE_104D9008: return "Vaio VGN-SZ79SN_C";
        case PciSubDevice8086284B::SUBDEVICE_104D9016: return "Sony VAIO VGN-AR51M";
        case PciSubDevice8086284B::SUBDEVICE_104D902D: return "VAIO VGN-NR120E";
        case PciSubDevice8086284B::SUBDEVICE_14F15051: return "Presario C700";
        case PciSubDevice8086284B::SUBDEVICE_17AA20AC: return "ThinkPad T61/R61";
        case PciSubDevice8086284B::SUBDEVICE_17C04088: return "Medion WIM 2210 Notebook PC [MD96850]";
        case PciSubDevice8086284B::SUBDEVICE_83847616: return "Dell Vostro 1400";
        case PciSubDevice8086284B::SUBDEVICE_E4BFCC47: return "CCG-RUMBA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086284B_H
