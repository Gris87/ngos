// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861461_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861461_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861461: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_15D93480 = 0x15D93480,
    SUBDEVICE_4C531090 = 0x4C531090
};



inline const char8* enumToString(PciSubDevice80861461 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861461::NONE:               return "NONE";
        case PciSubDevice80861461::SUBDEVICE_15D93480: return "SUBDEVICE_15D93480";
        case PciSubDevice80861461::SUBDEVICE_4C531090: return "SUBDEVICE_4C531090";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861461 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861461 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861461::SUBDEVICE_15D93480: return "P4DP6";
        case PciSubDevice80861461::SUBDEVICE_4C531090: return "Cx9/Vx9 mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861461_H
