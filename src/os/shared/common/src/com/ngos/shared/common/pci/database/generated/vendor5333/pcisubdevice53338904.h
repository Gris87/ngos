// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCISUBDEVICE53338904_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCISUBDEVICE53338904_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice53338904: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101400DB = 0x101400DB,
    SUBDEVICE_4843314A = 0x4843314A,
    SUBDEVICE_53338904 = 0x53338904
};



inline const char8* enumToString(PciSubDevice53338904 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice53338904::NONE:               return "NONE";
        case PciSubDevice53338904::SUBDEVICE_101400DB: return "SUBDEVICE_101400DB";
        case PciSubDevice53338904::SUBDEVICE_4843314A: return "SUBDEVICE_4843314A";
        case PciSubDevice53338904::SUBDEVICE_53338904: return "SUBDEVICE_53338904";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice53338904 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice53338904 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice53338904::SUBDEVICE_101400DB: return "Integrated Trio3D";
        case PciSubDevice53338904::SUBDEVICE_4843314A: return "Terminator 128/3D GLH";
        case PciSubDevice53338904::SUBDEVICE_53338904: return "86C365 Trio3D AGP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCISUBDEVICE53338904_H
