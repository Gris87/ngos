// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D2_PCISUBDEVICE12D20018_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D2_PCISUBDEVICE12D20018_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12D20018: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10480C10 = 0x10480C10,
    SUBDEVICE_107B8030 = 0x107B8030,
    SUBDEVICE_10920350 = 0x10920350,
    SUBDEVICE_10921092 = 0x10921092,
    SUBDEVICE_10B41B1B = 0x10B41B1B,
    SUBDEVICE_10B41B1D = 0x10B41B1D,
    SUBDEVICE_10B41B1E = 0x10B41B1E,
    SUBDEVICE_10B41B20 = 0x10B41B20,
    SUBDEVICE_10B41B21 = 0x10B41B21,
    SUBDEVICE_10B41B22 = 0x10B41B22,
    SUBDEVICE_10B41B23 = 0x10B41B23,
    SUBDEVICE_10B41B27 = 0x10B41B27,
    SUBDEVICE_10B41B88 = 0x10B41B88,
    SUBDEVICE_10B4222A = 0x10B4222A,
    SUBDEVICE_10B42230 = 0x10B42230,
    SUBDEVICE_10B42232 = 0x10B42232,
    SUBDEVICE_10B42235 = 0x10B42235,
    SUBDEVICE_2A1554A3 = 0x2A1554A3
};



inline const char8* enumToString(PciSubDevice12D20018 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12D20018::NONE:               return "NONE";
        case PciSubDevice12D20018::SUBDEVICE_10480C10: return "SUBDEVICE_10480C10";
        case PciSubDevice12D20018::SUBDEVICE_107B8030: return "SUBDEVICE_107B8030";
        case PciSubDevice12D20018::SUBDEVICE_10920350: return "SUBDEVICE_10920350";
        case PciSubDevice12D20018::SUBDEVICE_10921092: return "SUBDEVICE_10921092";
        case PciSubDevice12D20018::SUBDEVICE_10B41B1B: return "SUBDEVICE_10B41B1B";
        case PciSubDevice12D20018::SUBDEVICE_10B41B1D: return "SUBDEVICE_10B41B1D";
        case PciSubDevice12D20018::SUBDEVICE_10B41B1E: return "SUBDEVICE_10B41B1E";
        case PciSubDevice12D20018::SUBDEVICE_10B41B20: return "SUBDEVICE_10B41B20";
        case PciSubDevice12D20018::SUBDEVICE_10B41B21: return "SUBDEVICE_10B41B21";
        case PciSubDevice12D20018::SUBDEVICE_10B41B22: return "SUBDEVICE_10B41B22";
        case PciSubDevice12D20018::SUBDEVICE_10B41B23: return "SUBDEVICE_10B41B23";
        case PciSubDevice12D20018::SUBDEVICE_10B41B27: return "SUBDEVICE_10B41B27";
        case PciSubDevice12D20018::SUBDEVICE_10B41B88: return "SUBDEVICE_10B41B88";
        case PciSubDevice12D20018::SUBDEVICE_10B4222A: return "SUBDEVICE_10B4222A";
        case PciSubDevice12D20018::SUBDEVICE_10B42230: return "SUBDEVICE_10B42230";
        case PciSubDevice12D20018::SUBDEVICE_10B42232: return "SUBDEVICE_10B42232";
        case PciSubDevice12D20018::SUBDEVICE_10B42235: return "SUBDEVICE_10B42235";
        case PciSubDevice12D20018::SUBDEVICE_2A1554A3: return "SUBDEVICE_2A1554A3";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12D20018 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12D20018 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12D20018::SUBDEVICE_10480C10: return "VICTORY Erazor";
        case PciSubDevice12D20018::SUBDEVICE_107B8030: return "STB Velocity 128";
        case PciSubDevice12D20018::SUBDEVICE_10920350: return "Viper V330";
        case PciSubDevice12D20018::SUBDEVICE_10921092: return "Viper V330";
        case PciSubDevice12D20018::SUBDEVICE_10B41B1B: return "STB Velocity 128";
        case PciSubDevice12D20018::SUBDEVICE_10B41B1D: return "STB Velocity 128";
        case PciSubDevice12D20018::SUBDEVICE_10B41B1E: return "STB Velocity 128, PAL TV-Out";
        case PciSubDevice12D20018::SUBDEVICE_10B41B20: return "STB Velocity 128 Sapphire";
        case PciSubDevice12D20018::SUBDEVICE_10B41B21: return "STB Velocity 128";
        case PciSubDevice12D20018::SUBDEVICE_10B41B22: return "STB Velocity 128 AGP, NTSC TV-Out";
        case PciSubDevice12D20018::SUBDEVICE_10B41B23: return "STB Velocity 128 AGP, PAL TV-Out";
        case PciSubDevice12D20018::SUBDEVICE_10B41B27: return "STB Velocity 128 DVD";
        case PciSubDevice12D20018::SUBDEVICE_10B41B88: return "MVP Pro 128";
        case PciSubDevice12D20018::SUBDEVICE_10B4222A: return "STB Velocity 128 AGP";
        case PciSubDevice12D20018::SUBDEVICE_10B42230: return "STB Velocity 128";
        case PciSubDevice12D20018::SUBDEVICE_10B42232: return "STB Velocity 128";
        case PciSubDevice12D20018::SUBDEVICE_10B42235: return "STB Velocity 128 AGP";
        case PciSubDevice12D20018::SUBDEVICE_2A1554A3: return "3DVision-SAGP / 3DexPlorer 3000";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D2_PCISUBDEVICE12D20018_H
