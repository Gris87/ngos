// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020006_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020006_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11020006: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11021001 = 0x11021001,
    SUBDEVICE_11021003 = 0x11021003,
    SUBDEVICE_11021004 = 0x11021004
};



inline const char8* enumToString(PciSubDevice11020006 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11020006::NONE:               return "NONE";
        case PciSubDevice11020006::SUBDEVICE_11021001: return "SUBDEVICE_11021001";
        case PciSubDevice11020006::SUBDEVICE_11021003: return "SUBDEVICE_11021003";
        case PciSubDevice11020006::SUBDEVICE_11021004: return "SUBDEVICE_11021004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11020006 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11020006 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11020006::SUBDEVICE_11021001: return "SB0680 Sound Blaster 5.1";
        case PciSubDevice11020006::SUBDEVICE_11021003: return "SB0203 SB Live! 5.1 (Dell)";
        case PciSubDevice11020006::SUBDEVICE_11021004: return "TP0033 Ectiva Audio 5.1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11020006_H
