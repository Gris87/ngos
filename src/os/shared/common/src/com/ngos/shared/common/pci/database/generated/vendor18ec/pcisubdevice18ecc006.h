// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18EC_PCISUBDEVICE18ECC006_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18EC_PCISUBDEVICE18ECC006_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice18ECC006: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_18ECD001 = 0x18ECD001,
    SUBDEVICE_18ECD002 = 0x18ECD002,
    SUBDEVICE_18ECD003 = 0x18ECD003,
    SUBDEVICE_18ECD004 = 0x18ECD004
};



inline const char8* enumToString(PciSubDevice18ECC006 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice18ECC006::NONE:               return "NONE";
        case PciSubDevice18ECC006::SUBDEVICE_18ECD001: return "SUBDEVICE_18ECD001";
        case PciSubDevice18ECC006::SUBDEVICE_18ECD002: return "SUBDEVICE_18ECD002";
        case PciSubDevice18ECC006::SUBDEVICE_18ECD003: return "SUBDEVICE_18ECD003";
        case PciSubDevice18ECC006::SUBDEVICE_18ECD004: return "SUBDEVICE_18ECD004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice18ECC006 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice18ECC006 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice18ECC006::SUBDEVICE_18ECD001: return "COMBO-4MTX";
        case PciSubDevice18ECC006::SUBDEVICE_18ECD002: return "COMBO-4SFP";
        case PciSubDevice18ECC006::SUBDEVICE_18ECD003: return "COMBO-4SFPRO";
        case PciSubDevice18ECC006::SUBDEVICE_18ECD004: return "COMBO-2XFP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18EC_PCISUBDEVICE18ECC006_H
