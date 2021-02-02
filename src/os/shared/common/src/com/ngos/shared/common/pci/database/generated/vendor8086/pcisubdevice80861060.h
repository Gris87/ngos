// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861060_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861060_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861060: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80860060 = 0x80860060,
    SUBDEVICE_80861060 = 0x80861060
};



inline const char8* enumToString(PciSubDevice80861060 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861060::NONE:               return "NONE";
        case PciSubDevice80861060::SUBDEVICE_80860060: return "SUBDEVICE_80860060";
        case PciSubDevice80861060::SUBDEVICE_80861060: return "SUBDEVICE_80861060";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861060 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861060 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861060::SUBDEVICE_80860060: return "PRO/1000 PB Dual Port Server Connection";
        case PciSubDevice80861060::SUBDEVICE_80861060: return "PRO/1000 PB Dual Port Server Connection";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861060_H
