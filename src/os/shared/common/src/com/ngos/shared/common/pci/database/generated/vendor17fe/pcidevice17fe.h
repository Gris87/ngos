// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17FE_PCIDEVICE17FE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17FE_PCIDEVICE17FE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice17FE: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2120 = 0x2120,
    DEVICE_2220 = 0x2220
};



inline const char8* enumToString(PciDevice17FE device17FE) // TEST: NO
{
    // COMMON_LT((" | device17FE = %u", device17FE)); // Commented to avoid bad looking logs



    switch (device17FE)
    {
        case PciDevice17FE::NONE:        return "NONE";
        case PciDevice17FE::DEVICE_2120: return "DEVICE_2120";
        case PciDevice17FE::DEVICE_2220: return "DEVICE_2220";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice17FE device17FE) // TEST: NO
{
    // COMMON_LT((" | device17FE = %u", device17FE)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device17FE, enumToString(device17FE));

    return res;
}



inline const char8* enumToHumanString(PciDevice17FE device17FE) // TEST: NO
{
    // COMMON_LT((" | device17FE = %u", device17FE)); // Commented to avoid bad looking logs



    switch (device17FE)
    {
        case PciDevice17FE::DEVICE_2120: return "IPN 2120 802.11b";
        case PciDevice17FE::DEVICE_2220: return "IPN 2220 802.11g";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17FE_PCIDEVICE17FE_H
