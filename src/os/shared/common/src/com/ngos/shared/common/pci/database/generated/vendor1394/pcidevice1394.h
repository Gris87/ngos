// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1394_PCIDEVICE1394_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1394_PCIDEVICE1394_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1394: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice1394 device1394) // TEST: NO
{
    // COMMON_LT((" | device1394 = %u", device1394)); // Commented to avoid bad looking logs



    switch (device1394)
    {
        case PciDevice1394::NONE:        return "NONE";
        case PciDevice1394::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1394 device1394) // TEST: NO
{
    // COMMON_LT((" | device1394 = %u", device1394)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1394, enumToString(device1394));

    return res;
}



inline const char8* enumToHumanString(PciDevice1394 device1394) // TEST: NO
{
    // COMMON_LT((" | device1394 = %u", device1394)); // Commented to avoid bad looking logs



    switch (device1394)
    {
        case PciDevice1394::DEVICE_0001: return "LXT1001 Gigabit Ethernet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1394_PCIDEVICE1394_H
