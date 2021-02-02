// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17FE_PCISUBDEVICE17FE2220_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17FE_PCISUBDEVICE17FE2220_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice17FE2220: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14680305 = 0x14680305,
    SUBDEVICE_17370029 = 0x17370029
};



inline const char8* enumToString(PciSubDevice17FE2220 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17FE2220::NONE:               return "NONE";
        case PciSubDevice17FE2220::SUBDEVICE_14680305: return "SUBDEVICE_14680305";
        case PciSubDevice17FE2220::SUBDEVICE_17370029: return "SUBDEVICE_17370029";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice17FE2220 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice17FE2220 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17FE2220::SUBDEVICE_14680305: return "T60N871 802.11g Mini PCI Wireless Adapter";
        case PciSubDevice17FE2220::SUBDEVICE_17370029: return "WPC54G v4 802.11g Wireless-G Notebook Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17FE_PCISUBDEVICE17FE2220_H
