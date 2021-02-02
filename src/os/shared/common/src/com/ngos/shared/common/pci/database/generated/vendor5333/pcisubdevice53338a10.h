// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCISUBDEVICE53338A10_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCISUBDEVICE53338A10_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice53338A10: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10928A10 = 0x10928A10
};



inline const char8* enumToString(PciSubDevice53338A10 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice53338A10::NONE:               return "NONE";
        case PciSubDevice53338A10::SUBDEVICE_10928A10: return "SUBDEVICE_10928A10";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice53338A10 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice53338A10 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice53338A10::SUBDEVICE_10928A10: return "Stealth 3D 4000";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCISUBDEVICE53338A10_H
