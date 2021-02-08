// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR177D_PCISUBDEVICE177DA008_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR177D_PCISUBDEVICE177DA008_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice177DA008: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_177DA108 = 0x177DA108
};



inline const char8* enumToString(PciSubDevice177DA008 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice177DA008::NONE:               return "NONE";
        case PciSubDevice177DA008::SUBDEVICE_177DA108: return "SUBDEVICE_177DA108";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice177DA008 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice177DA008 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice177DA008::SUBDEVICE_177DA108: return "CN88XX SMMU";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR177D_PCISUBDEVICE177DA008_H
