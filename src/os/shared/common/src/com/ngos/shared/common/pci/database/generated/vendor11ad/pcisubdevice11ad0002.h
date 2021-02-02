// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AD_PCISUBDEVICE11AD0002_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AD_PCISUBDEVICE11AD0002_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11AD0002: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11AD0002 = 0x11AD0002,
    SUBDEVICE_11AD0003 = 0x11AD0003,
    SUBDEVICE_11ADF003 = 0x11ADF003,
    SUBDEVICE_11ADFFFF = 0x11ADFFFF,
    SUBDEVICE_1385F004 = 0x1385F004,
    SUBDEVICE_2646F002 = 0x2646F002
};



inline const char8* enumToString(PciSubDevice11AD0002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AD0002::NONE:               return "NONE";
        case PciSubDevice11AD0002::SUBDEVICE_11AD0002: return "SUBDEVICE_11AD0002";
        case PciSubDevice11AD0002::SUBDEVICE_11AD0003: return "SUBDEVICE_11AD0003";
        case PciSubDevice11AD0002::SUBDEVICE_11ADF003: return "SUBDEVICE_11ADF003";
        case PciSubDevice11AD0002::SUBDEVICE_11ADFFFF: return "SUBDEVICE_11ADFFFF";
        case PciSubDevice11AD0002::SUBDEVICE_1385F004: return "SUBDEVICE_1385F004";
        case PciSubDevice11AD0002::SUBDEVICE_2646F002: return "SUBDEVICE_2646F002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11AD0002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11AD0002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11AD0002::SUBDEVICE_11AD0002: return "LNE100TX";
        case PciSubDevice11AD0002::SUBDEVICE_11AD0003: return "LNE100TX";
        case PciSubDevice11AD0002::SUBDEVICE_11ADF003: return "LNE100TX";
        case PciSubDevice11AD0002::SUBDEVICE_11ADFFFF: return "LNE100TX";
        case PciSubDevice11AD0002::SUBDEVICE_1385F004: return "FA310TX";
        case PciSubDevice11AD0002::SUBDEVICE_2646F002: return "KNE110TX EtheRx Fast Ethernet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AD_PCISUBDEVICE11AD0002_H
