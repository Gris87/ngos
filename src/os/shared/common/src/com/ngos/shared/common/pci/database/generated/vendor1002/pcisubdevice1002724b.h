// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002724B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002724B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002724B: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020B12 = 0x10020B12,
    SUBDEVICE_10020B13 = 0x10020B13
};



inline const char8* enumToString(PciSubDevice1002724B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002724B::NONE:               return "NONE";
        case PciSubDevice1002724B::SUBDEVICE_10020B12: return "SUBDEVICE_10020B12";
        case PciSubDevice1002724B::SUBDEVICE_10020B13: return "SUBDEVICE_10020B13";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002724B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002724B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002724B::SUBDEVICE_10020B12: return "Radeon X1900 (Primary)";
        case PciSubDevice1002724B::SUBDEVICE_10020B13: return "Radeon X1900 (Secondary)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002724B_H
