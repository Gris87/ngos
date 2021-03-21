// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024385_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024385_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024385: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10192120 = 0x10192120,
    SUBDEVICE_103C1611 = 0x103C1611,
    SUBDEVICE_103C280A = 0x103C280A,
    SUBDEVICE_104382EF = 0x104382EF,
    SUBDEVICE_10438389 = 0x10438389,
    SUBDEVICE_105B0E13 = 0x105B0E13,
    SUBDEVICE_1179FF50 = 0x1179FF50,
    SUBDEVICE_14584385 = 0x14584385,
    SUBDEVICE_14627368 = 0x14627368,
    SUBDEVICE_14627596 = 0x14627596,
    SUBDEVICE_15D9A811 = 0x15D9A811,
    SUBDEVICE_174B1001 = 0x174B1001,
    SUBDEVICE_17F25000 = 0x17F25000
};



inline const char8* enumToString(PciSubDevice10024385 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024385::NONE:               return "NONE";
        case PciSubDevice10024385::SUBDEVICE_10192120: return "SUBDEVICE_10192120";
        case PciSubDevice10024385::SUBDEVICE_103C1611: return "SUBDEVICE_103C1611";
        case PciSubDevice10024385::SUBDEVICE_103C280A: return "SUBDEVICE_103C280A";
        case PciSubDevice10024385::SUBDEVICE_104382EF: return "SUBDEVICE_104382EF";
        case PciSubDevice10024385::SUBDEVICE_10438389: return "SUBDEVICE_10438389";
        case PciSubDevice10024385::SUBDEVICE_105B0E13: return "SUBDEVICE_105B0E13";
        case PciSubDevice10024385::SUBDEVICE_1179FF50: return "SUBDEVICE_1179FF50";
        case PciSubDevice10024385::SUBDEVICE_14584385: return "SUBDEVICE_14584385";
        case PciSubDevice10024385::SUBDEVICE_14627368: return "SUBDEVICE_14627368";
        case PciSubDevice10024385::SUBDEVICE_14627596: return "SUBDEVICE_14627596";
        case PciSubDevice10024385::SUBDEVICE_15D9A811: return "SUBDEVICE_15D9A811";
        case PciSubDevice10024385::SUBDEVICE_174B1001: return "SUBDEVICE_174B1001";
        case PciSubDevice10024385::SUBDEVICE_17F25000: return "SUBDEVICE_17F25000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024385 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024385 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024385::SUBDEVICE_10192120: return "A785GM-M";
        case PciSubDevice10024385::SUBDEVICE_103C1611: return "Pavilion DM1Z-3000";
        case PciSubDevice10024385::SUBDEVICE_103C280A: return "DC5750 Microtower";
        case PciSubDevice10024385::SUBDEVICE_104382EF: return "M3A78-EH Motherboard";
        case PciSubDevice10024385::SUBDEVICE_10438389: return "M4A785TD Motherboard";
        case PciSubDevice10024385::SUBDEVICE_105B0E13: return "N15235/A74MX mainboard / AMD SB700";
        case PciSubDevice10024385::SUBDEVICE_1179FF50: return "Satellite P305D-S8995E";
        case PciSubDevice10024385::SUBDEVICE_14584385: return "GA-MA770-DS3rev2.0 Motherboard";
        case PciSubDevice10024385::SUBDEVICE_14627368: return "K9AG Neo2";
        case PciSubDevice10024385::SUBDEVICE_14627596: return "760GM-E51(MS-7596) Motherboard";
        case PciSubDevice10024385::SUBDEVICE_15D9A811: return "H8DGU";
        case PciSubDevice10024385::SUBDEVICE_174B1001: return "PURE Fusion Mini";
        case PciSubDevice10024385::SUBDEVICE_17F25000: return "KI690-AM2 Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024385_H
