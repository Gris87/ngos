// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE10222001_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE10222001_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10222001: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10920A78 = 0x10920A78,
    SUBDEVICE_16680299 = 0x16680299
};



inline const char8* enumToString(PciSubDevice10222001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10222001::NONE:               return "NONE";
        case PciSubDevice10222001::SUBDEVICE_10920A78: return "SUBDEVICE_10920A78";
        case PciSubDevice10222001::SUBDEVICE_16680299: return "SUBDEVICE_16680299";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10222001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10222001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10222001::SUBDEVICE_10920A78: return "Multimedia Home Network Adapter";
        case PciSubDevice10222001::SUBDEVICE_16680299: return "ActionLink Home Network Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE10222001_H
