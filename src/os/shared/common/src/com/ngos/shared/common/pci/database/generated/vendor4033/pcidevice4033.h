// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4033_PCIDEVICE4033_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4033_PCIDEVICE4033_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice4033: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1360 = 0x1360
};



inline const char8* enumToString(PciDevice4033 device4033) // TEST: NO
{
    // COMMON_LT((" | device4033 = %u", device4033)); // Commented to avoid bad looking logs



    switch (device4033)
    {
        case PciDevice4033::NONE:        return "NONE";
        case PciDevice4033::DEVICE_1360: return "DEVICE_1360";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice4033 device4033) // TEST: NO
{
    // COMMON_LT((" | device4033 = %u", device4033)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device4033, enumToString(device4033));

    return res;
}



inline const char8* enumToHumanString(PciDevice4033 device4033) // TEST: NO
{
    // COMMON_LT((" | device4033 = %u", device4033)); // Commented to avoid bad looking logs



    switch (device4033)
    {
        case PciDevice4033::DEVICE_1360: return "RTL8139 Ethernet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4033_PCIDEVICE4033_H
