// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024C66_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024C66_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024C66: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1014054D = 0x1014054D
};



inline const char8* enumToString(PciSubDevice10024C66 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024C66::NONE:               return "NONE";
        case PciSubDevice10024C66::SUBDEVICE_1014054D: return "SUBDEVICE_1014054D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024C66 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024C66 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024C66::SUBDEVICE_1014054D: return "ThinkPad T41";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024C66_H
