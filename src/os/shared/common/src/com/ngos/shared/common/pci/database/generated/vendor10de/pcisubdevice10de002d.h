// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE002D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE002D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE002D: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10430200 = 0x10430200,
    SUBDEVICE_10430201 = 0x10430201,
    SUBDEVICE_10480C3A = 0x10480C3A,
    SUBDEVICE_10480C3B = 0x10480C3B,
    SUBDEVICE_107D2137 = 0x107D2137,
    SUBDEVICE_10DE0006 = 0x10DE0006,
    SUBDEVICE_10DE001E = 0x10DE001E,
    SUBDEVICE_11021023 = 0x11021023,
    SUBDEVICE_11021024 = 0x11021024,
    SUBDEVICE_1102102C = 0x1102102C,
    SUBDEVICE_11021030 = 0x11021030,
    SUBDEVICE_110A006F = 0x110A006F,
    SUBDEVICE_110A0081 = 0x110A0081,
    SUBDEVICE_14628808 = 0x14628808,
    SUBDEVICE_14AF5620 = 0x14AF5620,
    SUBDEVICE_15541041 = 0x15541041,
    SUBDEVICE_1569002D = 0x1569002D
};



inline const char8* enumToString(PciSubDevice10DE002D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE002D::NONE:               return "NONE";
        case PciSubDevice10DE002D::SUBDEVICE_10430200: return "SUBDEVICE_10430200";
        case PciSubDevice10DE002D::SUBDEVICE_10430201: return "SUBDEVICE_10430201";
        case PciSubDevice10DE002D::SUBDEVICE_10480C3A: return "SUBDEVICE_10480C3A";
        case PciSubDevice10DE002D::SUBDEVICE_10480C3B: return "SUBDEVICE_10480C3B";
        case PciSubDevice10DE002D::SUBDEVICE_107D2137: return "SUBDEVICE_107D2137";
        case PciSubDevice10DE002D::SUBDEVICE_10DE0006: return "SUBDEVICE_10DE0006";
        case PciSubDevice10DE002D::SUBDEVICE_10DE001E: return "SUBDEVICE_10DE001E";
        case PciSubDevice10DE002D::SUBDEVICE_11021023: return "SUBDEVICE_11021023";
        case PciSubDevice10DE002D::SUBDEVICE_11021024: return "SUBDEVICE_11021024";
        case PciSubDevice10DE002D::SUBDEVICE_1102102C: return "SUBDEVICE_1102102C";
        case PciSubDevice10DE002D::SUBDEVICE_11021030: return "SUBDEVICE_11021030";
        case PciSubDevice10DE002D::SUBDEVICE_110A006F: return "SUBDEVICE_110A006F";
        case PciSubDevice10DE002D::SUBDEVICE_110A0081: return "SUBDEVICE_110A0081";
        case PciSubDevice10DE002D::SUBDEVICE_14628808: return "SUBDEVICE_14628808";
        case PciSubDevice10DE002D::SUBDEVICE_14AF5620: return "SUBDEVICE_14AF5620";
        case PciSubDevice10DE002D::SUBDEVICE_15541041: return "SUBDEVICE_15541041";
        case PciSubDevice10DE002D::SUBDEVICE_1569002D: return "SUBDEVICE_1569002D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE002D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE002D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE002D::SUBDEVICE_10430200: return "AGP-V3800M";
        case PciSubDevice10DE002D::SUBDEVICE_10430201: return "AGP-V3800M";
        case PciSubDevice10DE002D::SUBDEVICE_10480C3A: return "Erazor III LT";
        case PciSubDevice10DE002D::SUBDEVICE_10480C3B: return "Erazor III LT";
        case PciSubDevice10DE002D::SUBDEVICE_107D2137: return "WinFast 3D S325";
        case PciSubDevice10DE002D::SUBDEVICE_10DE0006: return "RIVA TNT2 Model 64/Model 64 Pro";
        case PciSubDevice10DE002D::SUBDEVICE_10DE001E: return "M64 AGP4x";
        case PciSubDevice10DE002D::SUBDEVICE_11021023: return "CT6892 RIVA TNT2 Value";
        case PciSubDevice10DE002D::SUBDEVICE_11021024: return "CT6932 RIVA TNT2 Value 32Mb";
        case PciSubDevice10DE002D::SUBDEVICE_1102102C: return "CT6931 RIVA TNT2 Value [Jumper]";
        case PciSubDevice10DE002D::SUBDEVICE_11021030: return "CT6931 RIVA TNT2 Value";
        case PciSubDevice10DE002D::SUBDEVICE_110A006F: return "GM1000-16";
        case PciSubDevice10DE002D::SUBDEVICE_110A0081: return "GM1000-16";
        case PciSubDevice10DE002D::SUBDEVICE_14628808: return "MSI-8808";
        case PciSubDevice10DE002D::SUBDEVICE_14AF5620: return "Gamer Cougar Video Edition";
        case PciSubDevice10DE002D::SUBDEVICE_15541041: return "Pixelview RIVA TNT2 M64";
        case PciSubDevice10DE002D::SUBDEVICE_1569002D: return "Palit Microsystems Daytona TNT2 M64";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE002D_H
