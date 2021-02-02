// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025653_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025653_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10025653: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250080 = 0x10250080,
    SUBDEVICE_103C0940 = 0x103C0940
};



inline const char8* enumToString(PciSubDevice10025653 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025653::NONE:               return "NONE";
        case PciSubDevice10025653::SUBDEVICE_10250080: return "SUBDEVICE_10250080";
        case PciSubDevice10025653::SUBDEVICE_103C0940: return "SUBDEVICE_103C0940";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10025653 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10025653 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10025653::SUBDEVICE_10250080: return "Aspire 5024WLMi";
        case PciSubDevice10025653::SUBDEVICE_103C0940: return "Compaq NW8240 Mobile Workstation";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10025653_H
