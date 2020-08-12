// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0095_PCIDEVICE0095_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0095_PCIDEVICE0095_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice0095: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0680 = 0x0680
};



inline const char8* enumToString(PciDevice0095 device0095) // TEST: NO
{
    // COMMON_LT((" | device0095 = %u", device0095)); // Commented to avoid bad looking logs



    switch (device0095)
    {
        case PciDevice0095::NONE:        return "NONE";
        case PciDevice0095::DEVICE_0680: return "DEVICE_0680";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice0095 device0095) // TEST: NO
{
    // COMMON_LT((" | device0095 = %u", device0095)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device0095, enumToString(device0095));

    return res;
}



inline const char8* enumToHumanString(PciDevice0095 device0095) // TEST: NO
{
    // COMMON_LT((" | device0095 = %u", device0095)); // Commented to avoid bad looking logs



    switch (device0095)
    {
        case PciDevice0095::DEVICE_0680: return "Ultra ATA/133 IDE RAID CONTROLLER CARD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0095_PCIDEVICE0095_H
