// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0010_PCIDEVICE0010_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0010_PCIDEVICE0010_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice0010: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8139 = 0x8139
};



inline const char8* enumToString(PciDevice0010 device0010) // TEST: NO
{
    // COMMON_LT((" | device0010 = %u", device0010)); // Commented to avoid bad looking logs



    switch (device0010)
    {
        case PciDevice0010::NONE:        return "NONE";
        case PciDevice0010::DEVICE_8139: return "DEVICE_8139";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice0010 device0010) // TEST: NO
{
    // COMMON_LT((" | device0010 = %u", device0010)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device0010, enumToString(device0010));

    return res;
}



inline const char8* enumToHumanString(PciDevice0010 device0010) // TEST: NO
{
    // COMMON_LT((" | device0010 = %u", device0010)); // Commented to avoid bad looking logs



    switch (device0010)
    {
        case PciDevice0010::DEVICE_8139: return "AT-2500TX V3 Ethernet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0010_PCIDEVICE0010_H
