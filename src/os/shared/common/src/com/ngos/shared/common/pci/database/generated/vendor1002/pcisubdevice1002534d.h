// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002534D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002534D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002534D: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020008 = 0x10020008,
    SUBDEVICE_10020018 = 0x10020018
};



inline const char8* enumToString(PciSubDevice1002534D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002534D::NONE:               return "NONE";
        case PciSubDevice1002534D::SUBDEVICE_10020008: return "SUBDEVICE_10020008";
        case PciSubDevice1002534D::SUBDEVICE_10020018: return "SUBDEVICE_10020018";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002534D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002534D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002534D::SUBDEVICE_10020008: return "Xpert 99/Xpert 2000";
        case PciSubDevice1002534D::SUBDEVICE_10020018: return "Xpert 2000";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002534D_H
