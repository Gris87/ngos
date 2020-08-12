// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1204_PCIDEVICE1204_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1204_PCIDEVICE1204_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1204: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1965 = 0x1965
};



inline const char8* enumToString(PciDevice1204 device1204) // TEST: NO
{
    // COMMON_LT((" | device1204 = %u", device1204)); // Commented to avoid bad looking logs



    switch (device1204)
    {
        case PciDevice1204::NONE:        return "NONE";
        case PciDevice1204::DEVICE_1965: return "DEVICE_1965";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1204 device1204) // TEST: NO
{
    // COMMON_LT((" | device1204 = %u", device1204)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1204, enumToString(device1204));

    return res;
}



inline const char8* enumToHumanString(PciDevice1204 device1204) // TEST: NO
{
    // COMMON_LT((" | device1204 = %u", device1204)); // Commented to avoid bad looking logs



    switch (device1204)
    {
        case PciDevice1204::DEVICE_1965: return "SB6501 802.11ad Wireless Network Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1204_PCIDEVICE1204_H
