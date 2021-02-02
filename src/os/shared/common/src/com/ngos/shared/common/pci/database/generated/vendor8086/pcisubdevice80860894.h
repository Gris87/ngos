// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860894_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860894_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860894: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80860022 = 0x80860022,
    SUBDEVICE_80860422 = 0x80860422,
    SUBDEVICE_80860822 = 0x80860822
};



inline const char8* enumToString(PciSubDevice80860894 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860894::NONE:               return "NONE";
        case PciSubDevice80860894::SUBDEVICE_80860022: return "SUBDEVICE_80860022";
        case PciSubDevice80860894::SUBDEVICE_80860422: return "SUBDEVICE_80860422";
        case PciSubDevice80860894::SUBDEVICE_80860822: return "SUBDEVICE_80860822";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860894 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860894 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860894::SUBDEVICE_80860022: return "Centrino Wireless-N 105 BGN";
        case PciSubDevice80860894::SUBDEVICE_80860422: return "Centrino Wireless-N 105 BGN";
        case PciSubDevice80860894::SUBDEVICE_80860822: return "Centrino Wireless-N 105 BGN";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860894_H
