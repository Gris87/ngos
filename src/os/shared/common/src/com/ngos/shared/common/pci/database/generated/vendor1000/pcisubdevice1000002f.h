// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000002F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000002F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1000002F: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10281F39 = 0x10281F39,
    SUBDEVICE_10281F3E = 0x10281F3E
};



inline const char8* enumToString(PciSubDevice1000002F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1000002F::NONE:               return "NONE";
        case PciSubDevice1000002F::SUBDEVICE_10281F39: return "SUBDEVICE_10281F39";
        case PciSubDevice1000002F::SUBDEVICE_10281F3E: return "SUBDEVICE_10281F3E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1000002F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1000002F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1000002F::SUBDEVICE_10281F39: return "SPERC8-e";
        case PciSubDevice1000002F::SUBDEVICE_10281F3E: return "SPERC 8";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000002F_H
