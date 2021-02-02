// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861008_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861008_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861008: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140269 = 0x10140269,
    SUBDEVICE_1028011B = 0x1028011B,
    SUBDEVICE_1028011C = 0x1028011C,
    SUBDEVICE_80861107 = 0x80861107,
    SUBDEVICE_80862107 = 0x80862107,
    SUBDEVICE_80862110 = 0x80862110,
    SUBDEVICE_80863108 = 0x80863108
};



inline const char8* enumToString(PciSubDevice80861008 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861008::NONE:               return "NONE";
        case PciSubDevice80861008::SUBDEVICE_10140269: return "SUBDEVICE_10140269";
        case PciSubDevice80861008::SUBDEVICE_1028011B: return "SUBDEVICE_1028011B";
        case PciSubDevice80861008::SUBDEVICE_1028011C: return "SUBDEVICE_1028011C";
        case PciSubDevice80861008::SUBDEVICE_80861107: return "SUBDEVICE_80861107";
        case PciSubDevice80861008::SUBDEVICE_80862107: return "SUBDEVICE_80862107";
        case PciSubDevice80861008::SUBDEVICE_80862110: return "SUBDEVICE_80862110";
        case PciSubDevice80861008::SUBDEVICE_80863108: return "SUBDEVICE_80863108";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861008 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861008 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861008::SUBDEVICE_10140269: return "iSeries 1000/100/10 Ethernet Adapter";
        case PciSubDevice80861008::SUBDEVICE_1028011B: return "PowerEdge 1650/2550";
        case PciSubDevice80861008::SUBDEVICE_1028011C: return "PRO/1000 XT Network Connection";
        case PciSubDevice80861008::SUBDEVICE_80861107: return "PRO/1000 XT Server Adapter";
        case PciSubDevice80861008::SUBDEVICE_80862107: return "PRO/1000 XT Server Adapter";
        case PciSubDevice80861008::SUBDEVICE_80862110: return "PRO/1000 XT Desktop Adapter";
        case PciSubDevice80861008::SUBDEVICE_80863108: return "PRO/1000 XT Network Connection";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861008_H
