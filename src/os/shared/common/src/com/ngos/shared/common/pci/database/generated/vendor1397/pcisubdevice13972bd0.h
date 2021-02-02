// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1397_PCISUBDEVICE13972BD0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1397_PCISUBDEVICE13972BD0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice13972BD0: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_06751704 = 0x06751704,
    SUBDEVICE_06751708 = 0x06751708,
    SUBDEVICE_13972BD0 = 0x13972BD0,
    SUBDEVICE_E4BF1000 = 0xE4BF1000
};



inline const char8* enumToString(PciSubDevice13972BD0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13972BD0::NONE:               return "NONE";
        case PciSubDevice13972BD0::SUBDEVICE_06751704: return "SUBDEVICE_06751704";
        case PciSubDevice13972BD0::SUBDEVICE_06751708: return "SUBDEVICE_06751708";
        case PciSubDevice13972BD0::SUBDEVICE_13972BD0: return "SUBDEVICE_13972BD0";
        case PciSubDevice13972BD0::SUBDEVICE_E4BF1000: return "SUBDEVICE_E4BF1000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice13972BD0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice13972BD0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13972BD0::SUBDEVICE_06751704: return "ISDN Adapter (PCI Bus, D, C)";
        case PciSubDevice13972BD0::SUBDEVICE_06751708: return "ISDN Adapter (PCI Bus, D, C, ACPI)";
        case PciSubDevice13972BD0::SUBDEVICE_13972BD0: return "ISDN Board";
        case PciSubDevice13972BD0::SUBDEVICE_E4BF1000: return "CI1-1-Harp";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1397_PCISUBDEVICE13972BD0_H
