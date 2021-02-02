// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029598_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029598_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10029598: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10029598 = 0x10029598,
    SUBDEVICE_104301D6 = 0x104301D6,
    SUBDEVICE_10433001 = 0x10433001,
    SUBDEVICE_174B3001 = 0x174B3001,
    SUBDEVICE_174B4580 = 0x174B4580,
    SUBDEVICE_17AF3011 = 0x17AF3011
};



inline const char8* enumToString(PciSubDevice10029598 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029598::NONE:               return "NONE";
        case PciSubDevice10029598::SUBDEVICE_10029598: return "SUBDEVICE_10029598";
        case PciSubDevice10029598::SUBDEVICE_104301D6: return "SUBDEVICE_104301D6";
        case PciSubDevice10029598::SUBDEVICE_10433001: return "SUBDEVICE_10433001";
        case PciSubDevice10029598::SUBDEVICE_174B3001: return "SUBDEVICE_174B3001";
        case PciSubDevice10029598::SUBDEVICE_174B4580: return "SUBDEVICE_174B4580";
        case PciSubDevice10029598::SUBDEVICE_17AF3011: return "SUBDEVICE_17AF3011";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10029598 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10029598 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029598::SUBDEVICE_10029598: return "Mobility Radeon HD 3600";
        case PciSubDevice10029598::SUBDEVICE_104301D6: return "EAH3650 Silent";
        case PciSubDevice10029598::SUBDEVICE_10433001: return "Radeon HD 4570";
        case PciSubDevice10029598::SUBDEVICE_174B3001: return "Radeon HD 3750";
        case PciSubDevice10029598::SUBDEVICE_174B4580: return "RV635 PRO [Radeon HD 4580]";
        case PciSubDevice10029598::SUBDEVICE_17AF3011: return "RV635 PRO [Radeon HD 4580]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029598_H
