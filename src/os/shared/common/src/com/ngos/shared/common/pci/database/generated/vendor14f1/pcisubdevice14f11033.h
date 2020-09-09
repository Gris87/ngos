// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F11033_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F11033_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14F11033: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10338077 = 0x10338077,
    SUBDEVICE_122D4027 = 0x122D4027,
    SUBDEVICE_122D4030 = 0x122D4030,
    SUBDEVICE_122D4034 = 0x122D4034,
    SUBDEVICE_13E0020D = 0x13E0020D,
    SUBDEVICE_13E0020E = 0x13E0020E,
    SUBDEVICE_13E00261 = 0x13E00261,
    SUBDEVICE_13E00290 = 0x13E00290,
    SUBDEVICE_13E002A0 = 0x13E002A0,
    SUBDEVICE_13E002B0 = 0x13E002B0,
    SUBDEVICE_13E002C0 = 0x13E002C0,
    SUBDEVICE_13E002D0 = 0x13E002D0,
    SUBDEVICE_144F1500 = 0x144F1500,
    SUBDEVICE_144F1501 = 0x144F1501,
    SUBDEVICE_144F150A = 0x144F150A,
    SUBDEVICE_144F150B = 0x144F150B,
    SUBDEVICE_144F1510 = 0x144F1510
};



inline const char8* enumToString(PciSubDevice14F11033 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F11033::NONE:               return "NONE";
        case PciSubDevice14F11033::SUBDEVICE_10338077: return "SUBDEVICE_10338077";
        case PciSubDevice14F11033::SUBDEVICE_122D4027: return "SUBDEVICE_122D4027";
        case PciSubDevice14F11033::SUBDEVICE_122D4030: return "SUBDEVICE_122D4030";
        case PciSubDevice14F11033::SUBDEVICE_122D4034: return "SUBDEVICE_122D4034";
        case PciSubDevice14F11033::SUBDEVICE_13E0020D: return "SUBDEVICE_13E0020D";
        case PciSubDevice14F11033::SUBDEVICE_13E0020E: return "SUBDEVICE_13E0020E";
        case PciSubDevice14F11033::SUBDEVICE_13E00261: return "SUBDEVICE_13E00261";
        case PciSubDevice14F11033::SUBDEVICE_13E00290: return "SUBDEVICE_13E00290";
        case PciSubDevice14F11033::SUBDEVICE_13E002A0: return "SUBDEVICE_13E002A0";
        case PciSubDevice14F11033::SUBDEVICE_13E002B0: return "SUBDEVICE_13E002B0";
        case PciSubDevice14F11033::SUBDEVICE_13E002C0: return "SUBDEVICE_13E002C0";
        case PciSubDevice14F11033::SUBDEVICE_13E002D0: return "SUBDEVICE_13E002D0";
        case PciSubDevice14F11033::SUBDEVICE_144F1500: return "SUBDEVICE_144F1500";
        case PciSubDevice14F11033::SUBDEVICE_144F1501: return "SUBDEVICE_144F1501";
        case PciSubDevice14F11033::SUBDEVICE_144F150A: return "SUBDEVICE_144F150A";
        case PciSubDevice14F11033::SUBDEVICE_144F150B: return "SUBDEVICE_144F150B";
        case PciSubDevice14F11033::SUBDEVICE_144F1510: return "SUBDEVICE_144F1510";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14F11033 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14F11033 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F11033::SUBDEVICE_10338077: return "NEC";
        case PciSubDevice14F11033::SUBDEVICE_122D4027: return "Dell Zeus - MDP3880-W(B) Data Fax Modem";
        case PciSubDevice14F11033::SUBDEVICE_122D4030: return "Dell Mercury - MDP3880-U(B) Data Fax Modem";
        case PciSubDevice14F11033::SUBDEVICE_122D4034: return "Dell Thor - MDP3880-W(U) Data Fax Modem";
        case PciSubDevice14F11033::SUBDEVICE_13E0020D: return "Dell Copper";
        case PciSubDevice14F11033::SUBDEVICE_13E0020E: return "Dell Silver";
        case PciSubDevice14F11033::SUBDEVICE_13E00261: return "IBM";
        case PciSubDevice14F11033::SUBDEVICE_13E00290: return "Compaq Goldwing";
        case PciSubDevice14F11033::SUBDEVICE_13E002A0: return "IBM";
        case PciSubDevice14F11033::SUBDEVICE_13E002B0: return "IBM";
        case PciSubDevice14F11033::SUBDEVICE_13E002C0: return "Compaq Scooter";
        case PciSubDevice14F11033::SUBDEVICE_13E002D0: return "IBM";
        case PciSubDevice14F11033::SUBDEVICE_144F1500: return "IBM P85-DF (1)";
        case PciSubDevice14F11033::SUBDEVICE_144F1501: return "IBM P85-DF (2)";
        case PciSubDevice14F11033::SUBDEVICE_144F150A: return "IBM P85-DF (3)";
        case PciSubDevice14F11033::SUBDEVICE_144F150B: return "IBM P85-DF Low Profile (1)";
        case PciSubDevice14F11033::SUBDEVICE_144F1510: return "IBM P85-DF Low Profile (2)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F11033_H
