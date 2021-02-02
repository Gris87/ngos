// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1044_PCISUBDEVICE1044A511_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1044_PCISUBDEVICE1044A511_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1044A511: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1044C032 = 0x1044C032,
    SUBDEVICE_1044C035 = 0x1044C035
};



inline const char8* enumToString(PciSubDevice1044A511 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1044A511::NONE:               return "NONE";
        case PciSubDevice1044A511::SUBDEVICE_1044C032: return "SUBDEVICE_1044C032";
        case PciSubDevice1044A511::SUBDEVICE_1044C035: return "SUBDEVICE_1044C035";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1044A511 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1044A511 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1044A511::SUBDEVICE_1044C032: return "ASR-2005S I2O Zero Channel";
        case PciSubDevice1044A511::SUBDEVICE_1044C035: return "ASR-2010S I2O Zero Channel";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1044_PCISUBDEVICE1044A511_H
