// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1522_PCISUBDEVICE15224000_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1522_PCISUBDEVICE15224000_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice15224000: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_15224001 = 0x15224001,
    SUBDEVICE_15224002 = 0x15224002,
    SUBDEVICE_15224004 = 0x15224004,
    SUBDEVICE_15224008 = 0x15224008,
    SUBDEVICE_15224100 = 0x15224100
};



inline const char8* enumToString(PciSubDevice15224000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15224000::NONE:               return "NONE";
        case PciSubDevice15224000::SUBDEVICE_15224001: return "SUBDEVICE_15224001";
        case PciSubDevice15224000::SUBDEVICE_15224002: return "SUBDEVICE_15224002";
        case PciSubDevice15224000::SUBDEVICE_15224004: return "SUBDEVICE_15224004";
        case PciSubDevice15224000::SUBDEVICE_15224008: return "SUBDEVICE_15224008";
        case PciSubDevice15224000::SUBDEVICE_15224100: return "SUBDEVICE_15224100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice15224000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice15224000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice15224000::SUBDEVICE_15224001: return "IQ Express 1-port V.34 Super-G3 Fax";
        case PciSubDevice15224000::SUBDEVICE_15224002: return "IQ Express 2-port V.34 Super-G3 Fax";
        case PciSubDevice15224000::SUBDEVICE_15224004: return "IQ Express 4-port V.34 Super-G3 Fax";
        case PciSubDevice15224000::SUBDEVICE_15224008: return "IQ Express 8-port V.34 Super-G3 Fax";
        case PciSubDevice15224000::SUBDEVICE_15224100: return "IQ Express SideBand";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1522_PCISUBDEVICE15224000_H
