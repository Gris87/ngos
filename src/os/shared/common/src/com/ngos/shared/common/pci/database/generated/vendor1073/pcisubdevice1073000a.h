// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1073_PCISUBDEVICE1073000A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1073_PCISUBDEVICE1073000A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1073000A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10730004 = 0x10730004,
    SUBDEVICE_1073000A = 0x1073000A,
    SUBDEVICE_80864D55 = 0x80864D55
};



inline const char8* enumToString(PciSubDevice1073000A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1073000A::NONE:               return "NONE";
        case PciSubDevice1073000A::SUBDEVICE_10730004: return "SUBDEVICE_10730004";
        case PciSubDevice1073000A::SUBDEVICE_1073000A: return "SUBDEVICE_1073000A";
        case PciSubDevice1073000A::SUBDEVICE_80864D55: return "SUBDEVICE_80864D55";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1073000A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1073000A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1073000A::SUBDEVICE_10730004: return "DS-XG PCI Audio CODEC";
        case PciSubDevice1073000A::SUBDEVICE_1073000A: return "DS-XG PCI Audio CODEC";
        case PciSubDevice1073000A::SUBDEVICE_80864D55: return "DS-XG PCI Audio CODEC [Intel MU440EX]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1073_PCISUBDEVICE1073000A_H
