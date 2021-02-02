// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1217_PCISUBDEVICE12177110_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1217_PCISUBDEVICE12177110_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12177110: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C088C = 0x103C088C,
    SUBDEVICE_103C0890 = 0x103C0890,
    SUBDEVICE_1734106C = 0x1734106C
};



inline const char8* enumToString(PciSubDevice12177110 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12177110::NONE:               return "NONE";
        case PciSubDevice12177110::SUBDEVICE_103C088C: return "SUBDEVICE_103C088C";
        case PciSubDevice12177110::SUBDEVICE_103C0890: return "SUBDEVICE_103C0890";
        case PciSubDevice12177110::SUBDEVICE_1734106C: return "SUBDEVICE_1734106C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12177110 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12177110 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12177110::SUBDEVICE_103C088C: return "NC8000 laptop";
        case PciSubDevice12177110::SUBDEVICE_103C0890: return "NC6000 laptop";
        case PciSubDevice12177110::SUBDEVICE_1734106C: return "Amilo A1645";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1217_PCISUBDEVICE12177110_H
