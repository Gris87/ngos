// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCISUBDEVICE53338A21_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCISUBDEVICE53338A21_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice53338A21: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_53338A21 = 0x53338A21
};



inline const char8* enumToString(PciSubDevice53338A21 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice53338A21::NONE:               return "NONE";
        case PciSubDevice53338A21::SUBDEVICE_53338A21: return "SUBDEVICE_53338A21";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice53338A21 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice53338A21 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice53338A21::SUBDEVICE_53338A21: return "86C390 Savage3D/MV";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCISUBDEVICE53338A21_H
