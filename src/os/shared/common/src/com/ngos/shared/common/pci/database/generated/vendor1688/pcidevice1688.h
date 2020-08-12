// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1688_PCIDEVICE1688_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1688_PCIDEVICE1688_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1688: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1170 = 0x1170
};



inline const char8* enumToString(PciDevice1688 device1688) // TEST: NO
{
    // COMMON_LT((" | device1688 = %u", device1688)); // Commented to avoid bad looking logs



    switch (device1688)
    {
        case PciDevice1688::NONE:        return "NONE";
        case PciDevice1688::DEVICE_1170: return "DEVICE_1170";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1688 device1688) // TEST: NO
{
    // COMMON_LT((" | device1688 = %u", device1688)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1688, enumToString(device1688));

    return res;
}



inline const char8* enumToHumanString(PciDevice1688 device1688) // TEST: NO
{
    // COMMON_LT((" | device1688 = %u", device1688)); // Commented to avoid bad looking logs



    switch (device1688)
    {
        case PciDevice1688::DEVICE_1170: return "WLAN 802.11b card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1688_PCIDEVICE1688_H
