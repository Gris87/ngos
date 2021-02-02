// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002AA60_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002AA60_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002AA60: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1025033D = 0x1025033D,
    SUBDEVICE_10250347 = 0x10250347
};



inline const char8* enumToString(PciSubDevice1002AA60 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002AA60::NONE:               return "NONE";
        case PciSubDevice1002AA60::SUBDEVICE_1025033D: return "SUBDEVICE_1025033D";
        case PciSubDevice1002AA60::SUBDEVICE_10250347: return "SUBDEVICE_10250347";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002AA60 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002AA60 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002AA60::SUBDEVICE_1025033D: return "Mobility Radeon HD 5650";
        case PciSubDevice1002AA60::SUBDEVICE_10250347: return "Aspire 7740G";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002AA60_H
