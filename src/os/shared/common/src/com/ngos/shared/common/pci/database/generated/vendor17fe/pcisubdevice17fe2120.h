// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17FE_PCISUBDEVICE17FE2120_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17FE_PCISUBDEVICE17FE2120_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice17FE2120: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17370020 = 0x17370020
};



inline const char8* enumToString(PciSubDevice17FE2120 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17FE2120::NONE:               return "NONE";
        case PciSubDevice17FE2120::SUBDEVICE_17370020: return "SUBDEVICE_17370020";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice17FE2120 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice17FE2120 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice17FE2120::SUBDEVICE_17370020: return "WMP11 v4 802.11b Wireless-B PCI Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17FE_PCISUBDEVICE17FE2120_H
