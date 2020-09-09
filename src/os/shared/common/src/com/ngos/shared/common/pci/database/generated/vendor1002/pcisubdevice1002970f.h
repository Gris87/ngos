// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002970F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002970F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002970F: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10192120 = 0x10192120,
    SUBDEVICE_104383A2 = 0x104383A2,
    SUBDEVICE_1043843E = 0x1043843E
};



inline const char8* enumToString(PciSubDevice1002970F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002970F::NONE:               return "NONE";
        case PciSubDevice1002970F::SUBDEVICE_10192120: return "SUBDEVICE_10192120";
        case PciSubDevice1002970F::SUBDEVICE_104383A2: return "SUBDEVICE_104383A2";
        case PciSubDevice1002970F::SUBDEVICE_1043843E: return "SUBDEVICE_1043843E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002970F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002970F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002970F::SUBDEVICE_10192120: return "A785GM-M";
        case PciSubDevice1002970F::SUBDEVICE_104383A2: return "M4A785TD Motherboard";
        case PciSubDevice1002970F::SUBDEVICE_1043843E: return "M5A88-V EVO";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002970F_H
