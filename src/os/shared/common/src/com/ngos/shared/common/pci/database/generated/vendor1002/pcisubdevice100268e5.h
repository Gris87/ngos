// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268E5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268E5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100268E5: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1179FD3C = 0x1179FD3C,
    SUBDEVICE_1179FD50 = 0x1179FD50,
    SUBDEVICE_1179FD52 = 0x1179FD52,
    SUBDEVICE_1179FD63 = 0x1179FD63,
    SUBDEVICE_1179FD65 = 0x1179FD65,
    SUBDEVICE_1179FD73 = 0x1179FD73,
    SUBDEVICE_1179FD75 = 0x1179FD75,
    SUBDEVICE_1179FDD0 = 0x1179FDD0,
    SUBDEVICE_1179FDD2 = 0x1179FDD2,
    SUBDEVICE_1179FDEA = 0x1179FDEA,
    SUBDEVICE_1179FDF8 = 0x1179FDF8,
    SUBDEVICE_148C5450 = 0x148C5450,
    SUBDEVICE_148C6350 = 0x148C6350,
    SUBDEVICE_148C7350 = 0x148C7350,
    SUBDEVICE_148C8350 = 0x148C8350,
    SUBDEVICE_15457350 = 0x15457350
};



inline const char8* enumToString(PciSubDevice100268E5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268E5::NONE:               return "NONE";
        case PciSubDevice100268E5::SUBDEVICE_1179FD3C: return "SUBDEVICE_1179FD3C";
        case PciSubDevice100268E5::SUBDEVICE_1179FD50: return "SUBDEVICE_1179FD50";
        case PciSubDevice100268E5::SUBDEVICE_1179FD52: return "SUBDEVICE_1179FD52";
        case PciSubDevice100268E5::SUBDEVICE_1179FD63: return "SUBDEVICE_1179FD63";
        case PciSubDevice100268E5::SUBDEVICE_1179FD65: return "SUBDEVICE_1179FD65";
        case PciSubDevice100268E5::SUBDEVICE_1179FD73: return "SUBDEVICE_1179FD73";
        case PciSubDevice100268E5::SUBDEVICE_1179FD75: return "SUBDEVICE_1179FD75";
        case PciSubDevice100268E5::SUBDEVICE_1179FDD0: return "SUBDEVICE_1179FDD0";
        case PciSubDevice100268E5::SUBDEVICE_1179FDD2: return "SUBDEVICE_1179FDD2";
        case PciSubDevice100268E5::SUBDEVICE_1179FDEA: return "SUBDEVICE_1179FDEA";
        case PciSubDevice100268E5::SUBDEVICE_1179FDF8: return "SUBDEVICE_1179FDF8";
        case PciSubDevice100268E5::SUBDEVICE_148C5450: return "SUBDEVICE_148C5450";
        case PciSubDevice100268E5::SUBDEVICE_148C6350: return "SUBDEVICE_148C6350";
        case PciSubDevice100268E5::SUBDEVICE_148C7350: return "SUBDEVICE_148C7350";
        case PciSubDevice100268E5::SUBDEVICE_148C8350: return "SUBDEVICE_148C8350";
        case PciSubDevice100268E5::SUBDEVICE_15457350: return "SUBDEVICE_15457350";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100268E5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100268E5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100268E5::SUBDEVICE_1179FD3C: return "Radeon HD 6330M";
        case PciSubDevice100268E5::SUBDEVICE_1179FD50: return "Radeon HD 6330M";
        case PciSubDevice100268E5::SUBDEVICE_1179FD52: return "Radeon HD 6330M";
        case PciSubDevice100268E5::SUBDEVICE_1179FD63: return "Radeon HD 6330M";
        case PciSubDevice100268E5::SUBDEVICE_1179FD65: return "Radeon HD 6330M";
        case PciSubDevice100268E5::SUBDEVICE_1179FD73: return "Radeon HD 6330M";
        case PciSubDevice100268E5::SUBDEVICE_1179FD75: return "Radeon HD 6330M";
        case PciSubDevice100268E5::SUBDEVICE_1179FDD0: return "Radeon HD 6330M";
        case PciSubDevice100268E5::SUBDEVICE_1179FDD2: return "Radeon HD 6330M";
        case PciSubDevice100268E5::SUBDEVICE_1179FDEA: return "Radeon HD 6330M";
        case PciSubDevice100268E5::SUBDEVICE_1179FDF8: return "Radeon HD 6330M";
        case PciSubDevice100268E5::SUBDEVICE_148C5450: return "Cedar [Radeon HD 5450]";
        case PciSubDevice100268E5::SUBDEVICE_148C6350: return "Cedar [Radeon HD 6350]";
        case PciSubDevice100268E5::SUBDEVICE_148C7350: return "Cedar [Radeon HD 7350]";
        case PciSubDevice100268E5::SUBDEVICE_148C8350: return "Cedar [Radeon HD 8350]";
        case PciSubDevice100268E5::SUBDEVICE_15457350: return "Cedar [Radeon HD 7350]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100268E5_H
