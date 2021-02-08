// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002679B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002679B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002679B: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020B28 = 0x10020B28,
    SUBDEVICE_10020B2A = 0x10020B2A,
    SUBDEVICE_14628036 = 0x14628036,
    SUBDEVICE_148C8990 = 0x148C8990
};



inline const char8* enumToString(PciSubDevice1002679B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002679B::NONE:               return "NONE";
        case PciSubDevice1002679B::SUBDEVICE_10020B28: return "SUBDEVICE_10020B28";
        case PciSubDevice1002679B::SUBDEVICE_10020B2A: return "SUBDEVICE_10020B2A";
        case PciSubDevice1002679B::SUBDEVICE_14628036: return "SUBDEVICE_14628036";
        case PciSubDevice1002679B::SUBDEVICE_148C8990: return "SUBDEVICE_148C8990";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002679B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002679B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002679B::SUBDEVICE_10020B28: return "Radeon HD 8990 OEM";
        case PciSubDevice1002679B::SUBDEVICE_10020B2A: return "Radeon HD 7990";
        case PciSubDevice1002679B::SUBDEVICE_14628036: return "Radeon HD 8990 OEM";
        case PciSubDevice1002679B::SUBDEVICE_148C8990: return "Radeon HD 8990 OEM";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002679B_H
