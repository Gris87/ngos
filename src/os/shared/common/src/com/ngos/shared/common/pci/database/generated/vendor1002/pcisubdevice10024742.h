// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024742_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024742_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024742: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020040 = 0x10020040,
    SUBDEVICE_10020044 = 0x10020044,
    SUBDEVICE_10020061 = 0x10020061,
    SUBDEVICE_10020062 = 0x10020062,
    SUBDEVICE_10020063 = 0x10020063,
    SUBDEVICE_10020080 = 0x10020080,
    SUBDEVICE_10020084 = 0x10020084,
    SUBDEVICE_10024742 = 0x10024742,
    SUBDEVICE_10028001 = 0x10028001,
    SUBDEVICE_10280082 = 0x10280082,
    SUBDEVICE_10284082 = 0x10284082,
    SUBDEVICE_10288082 = 0x10288082,
    SUBDEVICE_1028C082 = 0x1028C082,
    SUBDEVICE_80864152 = 0x80864152,
    SUBDEVICE_8086464A = 0x8086464A
};



inline const char8* enumToString(PciSubDevice10024742 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024742::NONE:               return "NONE";
        case PciSubDevice10024742::SUBDEVICE_10020040: return "SUBDEVICE_10020040";
        case PciSubDevice10024742::SUBDEVICE_10020044: return "SUBDEVICE_10020044";
        case PciSubDevice10024742::SUBDEVICE_10020061: return "SUBDEVICE_10020061";
        case PciSubDevice10024742::SUBDEVICE_10020062: return "SUBDEVICE_10020062";
        case PciSubDevice10024742::SUBDEVICE_10020063: return "SUBDEVICE_10020063";
        case PciSubDevice10024742::SUBDEVICE_10020080: return "SUBDEVICE_10020080";
        case PciSubDevice10024742::SUBDEVICE_10020084: return "SUBDEVICE_10020084";
        case PciSubDevice10024742::SUBDEVICE_10024742: return "SUBDEVICE_10024742";
        case PciSubDevice10024742::SUBDEVICE_10028001: return "SUBDEVICE_10028001";
        case PciSubDevice10024742::SUBDEVICE_10280082: return "SUBDEVICE_10280082";
        case PciSubDevice10024742::SUBDEVICE_10284082: return "SUBDEVICE_10284082";
        case PciSubDevice10024742::SUBDEVICE_10288082: return "SUBDEVICE_10288082";
        case PciSubDevice10024742::SUBDEVICE_1028C082: return "SUBDEVICE_1028C082";
        case PciSubDevice10024742::SUBDEVICE_80864152: return "SUBDEVICE_80864152";
        case PciSubDevice10024742::SUBDEVICE_8086464A: return "SUBDEVICE_8086464A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024742 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024742 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024742::SUBDEVICE_10020040: return "Rage Pro Turbo AGP 2X";
        case PciSubDevice10024742::SUBDEVICE_10020044: return "Rage Pro Turbo AGP 2X";
        case PciSubDevice10024742::SUBDEVICE_10020061: return "Rage Pro AIW AGP 2X";
        case PciSubDevice10024742::SUBDEVICE_10020062: return "Rage Pro AIW AGP 2X";
        case PciSubDevice10024742::SUBDEVICE_10020063: return "Rage Pro AIW AGP 2X";
        case PciSubDevice10024742::SUBDEVICE_10020080: return "Rage Pro Turbo AGP 2X";
        case PciSubDevice10024742::SUBDEVICE_10020084: return "Rage Pro Turbo AGP 2X";
        case PciSubDevice10024742::SUBDEVICE_10024742: return "Rage Pro Turbo AGP 2X";
        case PciSubDevice10024742::SUBDEVICE_10028001: return "Rage Pro Turbo AGP 2X";
        case PciSubDevice10024742::SUBDEVICE_10280082: return "Rage Pro Turbo AGP 2X";
        case PciSubDevice10024742::SUBDEVICE_10284082: return "Optiplex GX1 Onboard Display Adapter";
        case PciSubDevice10024742::SUBDEVICE_10288082: return "Rage Pro Turbo AGP 2X";
        case PciSubDevice10024742::SUBDEVICE_1028C082: return "Rage Pro Turbo AGP 2X";
        case PciSubDevice10024742::SUBDEVICE_80864152: return "Xpert 98D AGP 2X";
        case PciSubDevice10024742::SUBDEVICE_8086464A: return "Rage Pro Turbo AGP 2X";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024742_H
