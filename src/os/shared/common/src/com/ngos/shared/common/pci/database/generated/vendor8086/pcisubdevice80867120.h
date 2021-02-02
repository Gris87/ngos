// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867120_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867120_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80867120: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_4C531040 = 0x4C531040,
    SUBDEVICE_4C531060 = 0x4C531060
};



inline const char8* enumToString(PciSubDevice80867120 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80867120::NONE:               return "NONE";
        case PciSubDevice80867120::SUBDEVICE_4C531040: return "SUBDEVICE_4C531040";
        case PciSubDevice80867120::SUBDEVICE_4C531060: return "SUBDEVICE_4C531060";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80867120 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80867120 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80867120::SUBDEVICE_4C531040: return "CL7 mainboard";
        case PciSubDevice80867120::SUBDEVICE_4C531060: return "PC7 mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867120_H
