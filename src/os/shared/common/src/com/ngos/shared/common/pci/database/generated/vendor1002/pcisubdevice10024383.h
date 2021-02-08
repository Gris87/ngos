// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024383_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024383_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024383: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10192120 = 0x10192120,
    SUBDEVICE_103C1611 = 0x103C1611,
    SUBDEVICE_103C280A = 0x103C280A,
    SUBDEVICE_10438230 = 0x10438230,
    SUBDEVICE_1043836C = 0x1043836C,
    SUBDEVICE_10438410 = 0x10438410,
    SUBDEVICE_1043841B = 0x1043841B,
    SUBDEVICE_10438445 = 0x10438445,
    SUBDEVICE_105B0E13 = 0x105B0E13,
    SUBDEVICE_1179FF50 = 0x1179FF50,
    SUBDEVICE_1458A022 = 0x1458A022,
    SUBDEVICE_1458A102 = 0x1458A102,
    SUBDEVICE_17F25000 = 0x17F25000
};



inline const char8* enumToString(PciSubDevice10024383 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024383::NONE:               return "NONE";
        case PciSubDevice10024383::SUBDEVICE_10192120: return "SUBDEVICE_10192120";
        case PciSubDevice10024383::SUBDEVICE_103C1611: return "SUBDEVICE_103C1611";
        case PciSubDevice10024383::SUBDEVICE_103C280A: return "SUBDEVICE_103C280A";
        case PciSubDevice10024383::SUBDEVICE_10438230: return "SUBDEVICE_10438230";
        case PciSubDevice10024383::SUBDEVICE_1043836C: return "SUBDEVICE_1043836C";
        case PciSubDevice10024383::SUBDEVICE_10438410: return "SUBDEVICE_10438410";
        case PciSubDevice10024383::SUBDEVICE_1043841B: return "SUBDEVICE_1043841B";
        case PciSubDevice10024383::SUBDEVICE_10438445: return "SUBDEVICE_10438445";
        case PciSubDevice10024383::SUBDEVICE_105B0E13: return "SUBDEVICE_105B0E13";
        case PciSubDevice10024383::SUBDEVICE_1179FF50: return "SUBDEVICE_1179FF50";
        case PciSubDevice10024383::SUBDEVICE_1458A022: return "SUBDEVICE_1458A022";
        case PciSubDevice10024383::SUBDEVICE_1458A102: return "SUBDEVICE_1458A102";
        case PciSubDevice10024383::SUBDEVICE_17F25000: return "SUBDEVICE_17F25000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024383 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024383 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024383::SUBDEVICE_10192120: return "A785GM-M";
        case PciSubDevice10024383::SUBDEVICE_103C1611: return "Pavilion dm1z-3000";
        case PciSubDevice10024383::SUBDEVICE_103C280A: return "DC5750 Microtower";
        case PciSubDevice10024383::SUBDEVICE_10438230: return "M3A78-EH Motherboard";
        case PciSubDevice10024383::SUBDEVICE_1043836C: return "M4A785TD Motherboard";
        case PciSubDevice10024383::SUBDEVICE_10438410: return "M4A89GTD PRO/USB3 Motherboard";
        case PciSubDevice10024383::SUBDEVICE_1043841B: return "M5A88-V EVO";
        case PciSubDevice10024383::SUBDEVICE_10438445: return "M5A78L LE";
        case PciSubDevice10024383::SUBDEVICE_105B0E13: return "N15235/A74MX mainboard / AMD SB700";
        case PciSubDevice10024383::SUBDEVICE_1179FF50: return "Satellite P305D-S8995E";
        case PciSubDevice10024383::SUBDEVICE_1458A022: return "GA-MA770-DS3rev2.0 Motherboard";
        case PciSubDevice10024383::SUBDEVICE_1458A102: return "GA-880GMA-USB3";
        case PciSubDevice10024383::SUBDEVICE_17F25000: return "KI690-AM2 Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024383_H
