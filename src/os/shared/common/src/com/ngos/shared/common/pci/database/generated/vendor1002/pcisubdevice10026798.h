// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026798_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026798_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026798: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10023000 = 0x10023000,
    SUBDEVICE_10023001 = 0x10023001,
    SUBDEVICE_10024000 = 0x10024000,
    SUBDEVICE_1043041C = 0x1043041C,
    SUBDEVICE_10430420 = 0x10430420,
    SUBDEVICE_10430444 = 0x10430444,
    SUBDEVICE_10430448 = 0x10430448,
    SUBDEVICE_1043044A = 0x1043044A,
    SUBDEVICE_1043044C = 0x1043044C,
    SUBDEVICE_10433001 = 0x10433001,
    SUBDEVICE_10433006 = 0x10433006,
    SUBDEVICE_10439999 = 0x10439999,
    SUBDEVICE_106B0127 = 0x106B0127,
    SUBDEVICE_106B0128 = 0x106B0128,
    SUBDEVICE_10923000 = 0x10923000,
    SUBDEVICE_14582261 = 0x14582261,
    SUBDEVICE_14583001 = 0x14583001,
    SUBDEVICE_14622774 = 0x14622774,
    SUBDEVICE_16823001 = 0x16823001,
    SUBDEVICE_16823211 = 0x16823211,
    SUBDEVICE_16823213 = 0x16823213,
    SUBDEVICE_16823214 = 0x16823214,
    SUBDEVICE_1787201C = 0x1787201C,
    SUBDEVICE_17872317 = 0x17872317,
    SUBDEVICE_17873000 = 0x17873000
};



inline const char8* enumToString(PciSubDevice10026798 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026798::NONE:               return "NONE";
        case PciSubDevice10026798::SUBDEVICE_10023000: return "SUBDEVICE_10023000";
        case PciSubDevice10026798::SUBDEVICE_10023001: return "SUBDEVICE_10023001";
        case PciSubDevice10026798::SUBDEVICE_10024000: return "SUBDEVICE_10024000";
        case PciSubDevice10026798::SUBDEVICE_1043041C: return "SUBDEVICE_1043041C";
        case PciSubDevice10026798::SUBDEVICE_10430420: return "SUBDEVICE_10430420";
        case PciSubDevice10026798::SUBDEVICE_10430444: return "SUBDEVICE_10430444";
        case PciSubDevice10026798::SUBDEVICE_10430448: return "SUBDEVICE_10430448";
        case PciSubDevice10026798::SUBDEVICE_1043044A: return "SUBDEVICE_1043044A";
        case PciSubDevice10026798::SUBDEVICE_1043044C: return "SUBDEVICE_1043044C";
        case PciSubDevice10026798::SUBDEVICE_10433001: return "SUBDEVICE_10433001";
        case PciSubDevice10026798::SUBDEVICE_10433006: return "SUBDEVICE_10433006";
        case PciSubDevice10026798::SUBDEVICE_10439999: return "SUBDEVICE_10439999";
        case PciSubDevice10026798::SUBDEVICE_106B0127: return "SUBDEVICE_106B0127";
        case PciSubDevice10026798::SUBDEVICE_106B0128: return "SUBDEVICE_106B0128";
        case PciSubDevice10026798::SUBDEVICE_10923000: return "SUBDEVICE_10923000";
        case PciSubDevice10026798::SUBDEVICE_14582261: return "SUBDEVICE_14582261";
        case PciSubDevice10026798::SUBDEVICE_14583001: return "SUBDEVICE_14583001";
        case PciSubDevice10026798::SUBDEVICE_14622774: return "SUBDEVICE_14622774";
        case PciSubDevice10026798::SUBDEVICE_16823001: return "SUBDEVICE_16823001";
        case PciSubDevice10026798::SUBDEVICE_16823211: return "SUBDEVICE_16823211";
        case PciSubDevice10026798::SUBDEVICE_16823213: return "SUBDEVICE_16823213";
        case PciSubDevice10026798::SUBDEVICE_16823214: return "SUBDEVICE_16823214";
        case PciSubDevice10026798::SUBDEVICE_1787201C: return "SUBDEVICE_1787201C";
        case PciSubDevice10026798::SUBDEVICE_17872317: return "SUBDEVICE_17872317";
        case PciSubDevice10026798::SUBDEVICE_17873000: return "SUBDEVICE_17873000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026798 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026798 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026798::SUBDEVICE_10023000: return "Tahiti XT2 [Radeon HD 7970 GHz Edition]";
        case PciSubDevice10026798::SUBDEVICE_10023001: return "Tahiti XTL [Radeon R9 280X]";
        case PciSubDevice10026798::SUBDEVICE_10024000: return "Radeon HD 8970 OEM";
        case PciSubDevice10026798::SUBDEVICE_1043041C: return "HD 7970 DirectCU II";
        case PciSubDevice10026798::SUBDEVICE_10430420: return "HD 7970 DirectCU II TOP";
        case PciSubDevice10026798::SUBDEVICE_10430444: return "HD 7970 DirectCU II TOP";
        case PciSubDevice10026798::SUBDEVICE_10430448: return "HD 7970 DirectCU II TOP";
        case PciSubDevice10026798::SUBDEVICE_1043044A: return "Tahiti XT2 [Matrix HD 7970]";
        case PciSubDevice10026798::SUBDEVICE_1043044C: return "Tahiti XT2 [Matrix HD 7970 Platinum]";
        case PciSubDevice10026798::SUBDEVICE_10433001: return "Tahiti XTL [ROG Matrix R9 280X]";
        case PciSubDevice10026798::SUBDEVICE_10433006: return "Tahiti XTL [Radeon R9 280X DirectCU II TOP]";
        case PciSubDevice10026798::SUBDEVICE_10439999: return "ARES II";
        case PciSubDevice10026798::SUBDEVICE_106B0127: return "FirePro D700";
        case PciSubDevice10026798::SUBDEVICE_106B0128: return "FirePro D700";
        case PciSubDevice10026798::SUBDEVICE_10923000: return "Tahiti XT2 [Radeon HD 7970 GHz Edition]";
        case PciSubDevice10026798::SUBDEVICE_14582261: return "Tahiti XT2 [Radeon HD 7970 GHz Edition OC]";
        case PciSubDevice10026798::SUBDEVICE_14583001: return "Tahiti XTL [Radeon R9 280X OC]";
        case PciSubDevice10026798::SUBDEVICE_14622774: return "HD 7970 TwinFrozr III Boost Edition OC";
        case PciSubDevice10026798::SUBDEVICE_16823001: return "Tahiti XTL [Radeon R9 280X]";
        case PciSubDevice10026798::SUBDEVICE_16823211: return "Double D HD 7970 Black Edition";
        case PciSubDevice10026798::SUBDEVICE_16823213: return "HD 7970 Black Edition";
        case PciSubDevice10026798::SUBDEVICE_16823214: return "Double D HD 7970";
        case PciSubDevice10026798::SUBDEVICE_1787201C: return "HD 7970 IceQ X^2";
        case PciSubDevice10026798::SUBDEVICE_17872317: return "Radeon HD 7990";
        case PciSubDevice10026798::SUBDEVICE_17873000: return "Tahiti XT2 [Radeon HD 7970 GHz Edition]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026798_H
