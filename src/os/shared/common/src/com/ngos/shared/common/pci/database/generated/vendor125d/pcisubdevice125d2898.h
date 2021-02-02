// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125D_PCISUBDEVICE125D2898_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125D_PCISUBDEVICE125D2898_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice125D2898: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_125D0424 = 0x125D0424,
    SUBDEVICE_125D0425 = 0x125D0425,
    SUBDEVICE_125D0426 = 0x125D0426,
    SUBDEVICE_125D0427 = 0x125D0427,
    SUBDEVICE_125D0428 = 0x125D0428,
    SUBDEVICE_125D0429 = 0x125D0429,
    SUBDEVICE_147AC001 = 0x147AC001,
    SUBDEVICE_148D1030 = 0x148D1030,
    SUBDEVICE_14FE0428 = 0x14FE0428,
    SUBDEVICE_14FE0429 = 0x14FE0429
};



inline const char8* enumToString(PciSubDevice125D2898 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice125D2898::NONE:               return "NONE";
        case PciSubDevice125D2898::SUBDEVICE_125D0424: return "SUBDEVICE_125D0424";
        case PciSubDevice125D2898::SUBDEVICE_125D0425: return "SUBDEVICE_125D0425";
        case PciSubDevice125D2898::SUBDEVICE_125D0426: return "SUBDEVICE_125D0426";
        case PciSubDevice125D2898::SUBDEVICE_125D0427: return "SUBDEVICE_125D0427";
        case PciSubDevice125D2898::SUBDEVICE_125D0428: return "SUBDEVICE_125D0428";
        case PciSubDevice125D2898::SUBDEVICE_125D0429: return "SUBDEVICE_125D0429";
        case PciSubDevice125D2898::SUBDEVICE_147AC001: return "SUBDEVICE_147AC001";
        case PciSubDevice125D2898::SUBDEVICE_148D1030: return "SUBDEVICE_148D1030";
        case PciSubDevice125D2898::SUBDEVICE_14FE0428: return "SUBDEVICE_14FE0428";
        case PciSubDevice125D2898::SUBDEVICE_14FE0429: return "SUBDEVICE_14FE0429";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice125D2898 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice125D2898 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice125D2898::SUBDEVICE_125D0424: return "ES56-PI Data Fax Modem";
        case PciSubDevice125D2898::SUBDEVICE_125D0425: return "ES56T-PI Data Fax Modem";
        case PciSubDevice125D2898::SUBDEVICE_125D0426: return "ES56V-PI Data Fax Modem";
        case PciSubDevice125D2898::SUBDEVICE_125D0427: return "VW-PI Data Fax Modem";
        case PciSubDevice125D2898::SUBDEVICE_125D0428: return "ES56ST-PI Data Fax Modem";
        case PciSubDevice125D2898::SUBDEVICE_125D0429: return "ES56SV-PI Data Fax Modem";
        case PciSubDevice125D2898::SUBDEVICE_147AC001: return "ES56-PI Data Fax Modem";
        case PciSubDevice125D2898::SUBDEVICE_148D1030: return "HCF WV-PI56 [ESS ES56-PI Data Fax Modem]";
        case PciSubDevice125D2898::SUBDEVICE_14FE0428: return "ES56-PI Data Fax Modem";
        case PciSubDevice125D2898::SUBDEVICE_14FE0429: return "ES56-PI Data Fax Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125D_PCISUBDEVICE125D2898_H
