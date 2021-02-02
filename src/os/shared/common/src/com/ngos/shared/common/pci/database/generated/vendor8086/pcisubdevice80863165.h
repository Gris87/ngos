// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863165_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863165_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863165: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80864010 = 0x80864010,
    SUBDEVICE_80864210 = 0x80864210
};



inline const char8* enumToString(PciSubDevice80863165 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863165::NONE:               return "NONE";
        case PciSubDevice80863165::SUBDEVICE_80864010: return "SUBDEVICE_80864010";
        case PciSubDevice80863165::SUBDEVICE_80864210: return "SUBDEVICE_80864210";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863165 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863165 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863165::SUBDEVICE_80864010: return "Dual Band Wireless AC 3165";
        case PciSubDevice80863165::SUBDEVICE_80864210: return "Dual Band Wireless AC 3165";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863165_H
