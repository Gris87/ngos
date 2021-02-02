// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4381_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4381_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11AB4381: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_12592803 = 0x12592803,
    SUBDEVICE_12592804 = 0x12592804
};



inline const char8* enumToString(PciSubDevice11AB4381 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AB4381::NONE:               return "NONE";
        case PciSubDevice11AB4381::SUBDEVICE_12592803: return "SUBDEVICE_12592803";
        case PciSubDevice11AB4381::SUBDEVICE_12592804: return "SUBDEVICE_12592804";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11AB4381 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11AB4381 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AB4381::SUBDEVICE_12592803: return "AT-2814FX";
        case PciSubDevice11AB4381::SUBDEVICE_12592804: return "AT-2874xx";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4381_H
