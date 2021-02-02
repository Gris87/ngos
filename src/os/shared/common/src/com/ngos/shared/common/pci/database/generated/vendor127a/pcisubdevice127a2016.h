// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A2016_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A2016_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice127A2016: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_122D4051 = 0x122D4051,
    SUBDEVICE_122D4052 = 0x122D4052,
    SUBDEVICE_122D4054 = 0x122D4054,
    SUBDEVICE_122D4056 = 0x122D4056,
    SUBDEVICE_122D4057 = 0x122D4057
};



inline const char8* enumToString(PciSubDevice127A2016 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A2016::NONE:               return "NONE";
        case PciSubDevice127A2016::SUBDEVICE_122D4051: return "SUBDEVICE_122D4051";
        case PciSubDevice127A2016::SUBDEVICE_122D4052: return "SUBDEVICE_122D4052";
        case PciSubDevice127A2016::SUBDEVICE_122D4054: return "SUBDEVICE_122D4054";
        case PciSubDevice127A2016::SUBDEVICE_122D4056: return "SUBDEVICE_122D4056";
        case PciSubDevice127A2016::SUBDEVICE_122D4057: return "SUBDEVICE_122D4057";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice127A2016 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice127A2016 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A2016::SUBDEVICE_122D4051: return "MSP3880V-W";
        case PciSubDevice127A2016::SUBDEVICE_122D4052: return "MSP3880SP-W";
        case PciSubDevice127A2016::SUBDEVICE_122D4054: return "MSP3880V-U";
        case PciSubDevice127A2016::SUBDEVICE_122D4056: return "MSP3880SP-U";
        case PciSubDevice127A2016::SUBDEVICE_122D4057: return "MSP3880SP-A";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A2016_H
