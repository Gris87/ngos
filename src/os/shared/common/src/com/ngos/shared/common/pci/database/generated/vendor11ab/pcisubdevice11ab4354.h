// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4354_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4354_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11AB4354: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028022F = 0x1028022F,
    SUBDEVICE_144DC06A = 0x144DC06A,
    SUBDEVICE_144DC072 = 0x144DC072
};



inline const char8* enumToString(PciSubDevice11AB4354 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AB4354::NONE:               return "NONE";
        case PciSubDevice11AB4354::SUBDEVICE_1028022F: return "SUBDEVICE_1028022F";
        case PciSubDevice11AB4354::SUBDEVICE_144DC06A: return "SUBDEVICE_144DC06A";
        case PciSubDevice11AB4354::SUBDEVICE_144DC072: return "SUBDEVICE_144DC072";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11AB4354 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11AB4354 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AB4354::SUBDEVICE_1028022F: return "Inspiron 1525";
        case PciSubDevice11AB4354::SUBDEVICE_144DC06A: return "R730 Laptop";
        case PciSubDevice11AB4354::SUBDEVICE_144DC072: return "Notebook N150P";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AB_PCISUBDEVICE11AB4354_H
