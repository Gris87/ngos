// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1013_PCISUBDEVICE101300BC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1013_PCISUBDEVICE101300BC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice101300BC: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101300BC = 0x101300BC
};



inline const char8* enumToString(PciSubDevice101300BC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice101300BC::NONE:               return "NONE";
        case PciSubDevice101300BC::SUBDEVICE_101300BC: return "SUBDEVICE_101300BC";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice101300BC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice101300BC subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice101300BC::SUBDEVICE_101300BC: return "CL-GD5480";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1013_PCISUBDEVICE101300BC_H
