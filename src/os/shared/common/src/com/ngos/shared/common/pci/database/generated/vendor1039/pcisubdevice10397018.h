// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10397018_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10397018_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10397018: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101401B6 = 0x101401B6,
    SUBDEVICE_101401B7 = 0x101401B7,
    SUBDEVICE_10197018 = 0x10197018,
    SUBDEVICE_1025000E = 0x1025000E,
    SUBDEVICE_10250018 = 0x10250018,
    SUBDEVICE_10397018 = 0x10397018,
    SUBDEVICE_10431453 = 0x10431453,
    SUBDEVICE_1043800B = 0x1043800B,
    SUBDEVICE_104D80E2 = 0x104D80E2,
    SUBDEVICE_10547018 = 0x10547018,
    SUBDEVICE_107D5330 = 0x107D5330,
    SUBDEVICE_107D5350 = 0x107D5350,
    SUBDEVICE_11703209 = 0x11703209,
    SUBDEVICE_1462400A = 0x1462400A,
    SUBDEVICE_14A42089 = 0x14A42089,
    SUBDEVICE_14CD2194 = 0x14CD2194,
    SUBDEVICE_14FF1100 = 0x14FF1100,
    SUBDEVICE_152D8808 = 0x152D8808,
    SUBDEVICE_15581103 = 0x15581103,
    SUBDEVICE_15582200 = 0x15582200,
    SUBDEVICE_15637018 = 0x15637018,
    SUBDEVICE_15C50111 = 0x15C50111,
    SUBDEVICE_270FA171 = 0x270FA171,
    SUBDEVICE_A0A00022 = 0xA0A00022
};



inline const char8* enumToString(PciSubDevice10397018 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10397018::NONE:               return "NONE";
        case PciSubDevice10397018::SUBDEVICE_101401B6: return "SUBDEVICE_101401B6";
        case PciSubDevice10397018::SUBDEVICE_101401B7: return "SUBDEVICE_101401B7";
        case PciSubDevice10397018::SUBDEVICE_10197018: return "SUBDEVICE_10197018";
        case PciSubDevice10397018::SUBDEVICE_1025000E: return "SUBDEVICE_1025000E";
        case PciSubDevice10397018::SUBDEVICE_10250018: return "SUBDEVICE_10250018";
        case PciSubDevice10397018::SUBDEVICE_10397018: return "SUBDEVICE_10397018";
        case PciSubDevice10397018::SUBDEVICE_10431453: return "SUBDEVICE_10431453";
        case PciSubDevice10397018::SUBDEVICE_1043800B: return "SUBDEVICE_1043800B";
        case PciSubDevice10397018::SUBDEVICE_104D80E2: return "SUBDEVICE_104D80E2";
        case PciSubDevice10397018::SUBDEVICE_10547018: return "SUBDEVICE_10547018";
        case PciSubDevice10397018::SUBDEVICE_107D5330: return "SUBDEVICE_107D5330";
        case PciSubDevice10397018::SUBDEVICE_107D5350: return "SUBDEVICE_107D5350";
        case PciSubDevice10397018::SUBDEVICE_11703209: return "SUBDEVICE_11703209";
        case PciSubDevice10397018::SUBDEVICE_1462400A: return "SUBDEVICE_1462400A";
        case PciSubDevice10397018::SUBDEVICE_14A42089: return "SUBDEVICE_14A42089";
        case PciSubDevice10397018::SUBDEVICE_14CD2194: return "SUBDEVICE_14CD2194";
        case PciSubDevice10397018::SUBDEVICE_14FF1100: return "SUBDEVICE_14FF1100";
        case PciSubDevice10397018::SUBDEVICE_152D8808: return "SUBDEVICE_152D8808";
        case PciSubDevice10397018::SUBDEVICE_15581103: return "SUBDEVICE_15581103";
        case PciSubDevice10397018::SUBDEVICE_15582200: return "SUBDEVICE_15582200";
        case PciSubDevice10397018::SUBDEVICE_15637018: return "SUBDEVICE_15637018";
        case PciSubDevice10397018::SUBDEVICE_15C50111: return "SUBDEVICE_15C50111";
        case PciSubDevice10397018::SUBDEVICE_270FA171: return "SUBDEVICE_270FA171";
        case PciSubDevice10397018::SUBDEVICE_A0A00022: return "SUBDEVICE_A0A00022";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10397018 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10397018 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10397018::SUBDEVICE_101401B6: return "SiS PCI Audio Accelerator";
        case PciSubDevice10397018::SUBDEVICE_101401B7: return "SiS PCI Audio Accelerator";
        case PciSubDevice10397018::SUBDEVICE_10197018: return "SiS PCI Audio Accelerator";
        case PciSubDevice10397018::SUBDEVICE_1025000E: return "SiS PCI Audio Accelerator";
        case PciSubDevice10397018::SUBDEVICE_10250018: return "SiS PCI Audio Accelerator";
        case PciSubDevice10397018::SUBDEVICE_10397018: return "SiS PCI Audio Accelerator";
        case PciSubDevice10397018::SUBDEVICE_10431453: return "SiS PCI Audio Accelerator";
        case PciSubDevice10397018::SUBDEVICE_1043800B: return "SiS PCI Audio Accelerator";
        case PciSubDevice10397018::SUBDEVICE_104D80E2: return "VAIO PCV-J200";
        case PciSubDevice10397018::SUBDEVICE_10547018: return "SiS PCI Audio Accelerator";
        case PciSubDevice10397018::SUBDEVICE_107D5330: return "SiS PCI Audio Accelerator";
        case PciSubDevice10397018::SUBDEVICE_107D5350: return "SiS PCI Audio Accelerator";
        case PciSubDevice10397018::SUBDEVICE_11703209: return "SiS PCI Audio Accelerator";
        case PciSubDevice10397018::SUBDEVICE_1462400A: return "SiS PCI Audio Accelerator";
        case PciSubDevice10397018::SUBDEVICE_14A42089: return "SiS PCI Audio Accelerator";
        case PciSubDevice10397018::SUBDEVICE_14CD2194: return "SiS PCI Audio Accelerator";
        case PciSubDevice10397018::SUBDEVICE_14FF1100: return "SiS PCI Audio Accelerator";
        case PciSubDevice10397018::SUBDEVICE_152D8808: return "SiS PCI Audio Accelerator";
        case PciSubDevice10397018::SUBDEVICE_15581103: return "SiS PCI Audio Accelerator";
        case PciSubDevice10397018::SUBDEVICE_15582200: return "SiS PCI Audio Accelerator";
        case PciSubDevice10397018::SUBDEVICE_15637018: return "SiS PCI Audio Accelerator";
        case PciSubDevice10397018::SUBDEVICE_15C50111: return "SiS PCI Audio Accelerator";
        case PciSubDevice10397018::SUBDEVICE_270FA171: return "SiS PCI Audio Accelerator";
        case PciSubDevice10397018::SUBDEVICE_A0A00022: return "SiS PCI Audio Accelerator";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10397018_H
