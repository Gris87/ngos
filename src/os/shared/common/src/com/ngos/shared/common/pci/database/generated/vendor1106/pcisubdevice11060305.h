// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11060305_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11060305_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11060305: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10190987 = 0x10190987,
    SUBDEVICE_10438033 = 0x10438033,
    SUBDEVICE_1043803E = 0x1043803E,
    SUBDEVICE_10438042 = 0x10438042,
    SUBDEVICE_147BA401 = 0x147BA401
};



inline const char8* enumToString(PciSubDevice11060305 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11060305::NONE:               return "NONE";
        case PciSubDevice11060305::SUBDEVICE_10190987: return "SUBDEVICE_10190987";
        case PciSubDevice11060305::SUBDEVICE_10438033: return "SUBDEVICE_10438033";
        case PciSubDevice11060305::SUBDEVICE_1043803E: return "SUBDEVICE_1043803E";
        case PciSubDevice11060305::SUBDEVICE_10438042: return "SUBDEVICE_10438042";
        case PciSubDevice11060305::SUBDEVICE_147BA401: return "SUBDEVICE_147BA401";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11060305 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11060305 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11060305::SUBDEVICE_10190987: return "K7VZA Mainboard";
        case PciSubDevice11060305::SUBDEVICE_10438033: return "A7V Mainboard";
        case PciSubDevice11060305::SUBDEVICE_1043803E: return "A7V-E Mainboard";
        case PciSubDevice11060305::SUBDEVICE_10438042: return "A7V133/A7V133-C Mainboard";
        case PciSubDevice11060305::SUBDEVICE_147BA401: return "KT7/KT7-RAID/KT7A/KT7A-RAID Mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11060305_H
