// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0028_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0028_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0028: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10430200 = 0x10430200,
    SUBDEVICE_10430201 = 0x10430201,
    SUBDEVICE_10430205 = 0x10430205,
    SUBDEVICE_10434000 = 0x10434000,
    SUBDEVICE_10480C21 = 0x10480C21,
    SUBDEVICE_10480C28 = 0x10480C28,
    SUBDEVICE_10480C29 = 0x10480C29,
    SUBDEVICE_10480C2A = 0x10480C2A,
    SUBDEVICE_10480C2B = 0x10480C2B,
    SUBDEVICE_10480C31 = 0x10480C31,
    SUBDEVICE_10480C32 = 0x10480C32,
    SUBDEVICE_10480C33 = 0x10480C33,
    SUBDEVICE_10480C34 = 0x10480C34,
    SUBDEVICE_107D2134 = 0x107D2134,
    SUBDEVICE_10924804 = 0x10924804,
    SUBDEVICE_10924A00 = 0x10924A00,
    SUBDEVICE_10924A02 = 0x10924A02,
    SUBDEVICE_10925A00 = 0x10925A00,
    SUBDEVICE_10925A40 = 0x10925A40,
    SUBDEVICE_10926A02 = 0x10926A02,
    SUBDEVICE_10927A02 = 0x10927A02,
    SUBDEVICE_10DE0005 = 0x10DE0005,
    SUBDEVICE_10DE000F = 0x10DE000F,
    SUBDEVICE_11021020 = 0x11021020,
    SUBDEVICE_11021026 = 0x11021026,
    SUBDEVICE_14628806 = 0x14628806,
    SUBDEVICE_14AF5810 = 0x14AF5810
};



inline const char8* enumToString(PciSubDevice10DE0028 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0028::NONE:               return "NONE";
        case PciSubDevice10DE0028::SUBDEVICE_10430200: return "SUBDEVICE_10430200";
        case PciSubDevice10DE0028::SUBDEVICE_10430201: return "SUBDEVICE_10430201";
        case PciSubDevice10DE0028::SUBDEVICE_10430205: return "SUBDEVICE_10430205";
        case PciSubDevice10DE0028::SUBDEVICE_10434000: return "SUBDEVICE_10434000";
        case PciSubDevice10DE0028::SUBDEVICE_10480C21: return "SUBDEVICE_10480C21";
        case PciSubDevice10DE0028::SUBDEVICE_10480C28: return "SUBDEVICE_10480C28";
        case PciSubDevice10DE0028::SUBDEVICE_10480C29: return "SUBDEVICE_10480C29";
        case PciSubDevice10DE0028::SUBDEVICE_10480C2A: return "SUBDEVICE_10480C2A";
        case PciSubDevice10DE0028::SUBDEVICE_10480C2B: return "SUBDEVICE_10480C2B";
        case PciSubDevice10DE0028::SUBDEVICE_10480C31: return "SUBDEVICE_10480C31";
        case PciSubDevice10DE0028::SUBDEVICE_10480C32: return "SUBDEVICE_10480C32";
        case PciSubDevice10DE0028::SUBDEVICE_10480C33: return "SUBDEVICE_10480C33";
        case PciSubDevice10DE0028::SUBDEVICE_10480C34: return "SUBDEVICE_10480C34";
        case PciSubDevice10DE0028::SUBDEVICE_107D2134: return "SUBDEVICE_107D2134";
        case PciSubDevice10DE0028::SUBDEVICE_10924804: return "SUBDEVICE_10924804";
        case PciSubDevice10DE0028::SUBDEVICE_10924A00: return "SUBDEVICE_10924A00";
        case PciSubDevice10DE0028::SUBDEVICE_10924A02: return "SUBDEVICE_10924A02";
        case PciSubDevice10DE0028::SUBDEVICE_10925A00: return "SUBDEVICE_10925A00";
        case PciSubDevice10DE0028::SUBDEVICE_10925A40: return "SUBDEVICE_10925A40";
        case PciSubDevice10DE0028::SUBDEVICE_10926A02: return "SUBDEVICE_10926A02";
        case PciSubDevice10DE0028::SUBDEVICE_10927A02: return "SUBDEVICE_10927A02";
        case PciSubDevice10DE0028::SUBDEVICE_10DE0005: return "SUBDEVICE_10DE0005";
        case PciSubDevice10DE0028::SUBDEVICE_10DE000F: return "SUBDEVICE_10DE000F";
        case PciSubDevice10DE0028::SUBDEVICE_11021020: return "SUBDEVICE_11021020";
        case PciSubDevice10DE0028::SUBDEVICE_11021026: return "SUBDEVICE_11021026";
        case PciSubDevice10DE0028::SUBDEVICE_14628806: return "SUBDEVICE_14628806";
        case PciSubDevice10DE0028::SUBDEVICE_14AF5810: return "SUBDEVICE_14AF5810";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0028 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0028 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0028::SUBDEVICE_10430200: return "AGP-V3800 SGRAM";
        case PciSubDevice10DE0028::SUBDEVICE_10430201: return "AGP-V3800 SDRAM";
        case PciSubDevice10DE0028::SUBDEVICE_10430205: return "PCI-V3800";
        case PciSubDevice10DE0028::SUBDEVICE_10434000: return "AGP-V3800PRO";
        case PciSubDevice10DE0028::SUBDEVICE_10480C21: return "Synergy II";
        case PciSubDevice10DE0028::SUBDEVICE_10480C28: return "Erazor III";
        case PciSubDevice10DE0028::SUBDEVICE_10480C29: return "Erazor III";
        case PciSubDevice10DE0028::SUBDEVICE_10480C2A: return "Erazor III";
        case PciSubDevice10DE0028::SUBDEVICE_10480C2B: return "Erazor III";
        case PciSubDevice10DE0028::SUBDEVICE_10480C31: return "Erazor III Pro";
        case PciSubDevice10DE0028::SUBDEVICE_10480C32: return "Erazor III Pro";
        case PciSubDevice10DE0028::SUBDEVICE_10480C33: return "Erazor III Pro";
        case PciSubDevice10DE0028::SUBDEVICE_10480C34: return "Erazor III Pro";
        case PciSubDevice10DE0028::SUBDEVICE_107D2134: return "WinFast 3D S320 II + TV-Out";
        case PciSubDevice10DE0028::SUBDEVICE_10924804: return "Viper V770";
        case PciSubDevice10DE0028::SUBDEVICE_10924A00: return "Viper V770";
        case PciSubDevice10DE0028::SUBDEVICE_10924A02: return "Viper V770 Ultra";
        case PciSubDevice10DE0028::SUBDEVICE_10925A00: return "RIVA TNT2/TNT2 Pro";
        case PciSubDevice10DE0028::SUBDEVICE_10925A40: return "Viper V770D AGP";
        case PciSubDevice10DE0028::SUBDEVICE_10926A02: return "Viper V770 Ultra";
        case PciSubDevice10DE0028::SUBDEVICE_10927A02: return "Viper V770 Ultra";
        case PciSubDevice10DE0028::SUBDEVICE_10DE0005: return "RIVA TNT2 Pro";
        case PciSubDevice10DE0028::SUBDEVICE_10DE000F: return "Compaq NVIDIA TNT2 Pro";
        case PciSubDevice10DE0028::SUBDEVICE_11021020: return "3D Blaster RIVA TNT2";
        case PciSubDevice10DE0028::SUBDEVICE_11021026: return "3D Blaster RIVA TNT2 Digital";
        case PciSubDevice10DE0028::SUBDEVICE_14628806: return "MS-8806 AGPhantom Graphics Card";
        case PciSubDevice10DE0028::SUBDEVICE_14AF5810: return "Maxi Gamer Xentor";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0028_H
