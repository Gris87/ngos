// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0070_PCIDEVICE0070_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0070_PCIDEVICE0070_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice0070: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_7801 = 0x7801
};



inline const char8* enumToString(PciDevice0070 device0070) // TEST: NO
{
    // COMMON_LT((" | device0070 = %u", device0070)); // Commented to avoid bad looking logs



    switch (device0070)
    {
        case PciDevice0070::NONE:        return "NONE";
        case PciDevice0070::DEVICE_7801: return "DEVICE_7801";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice0070 device0070) // TEST: NO
{
    // COMMON_LT((" | device0070 = %u", device0070)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device0070, enumToString(device0070));

    return res;
}



inline const char8* enumToHumanString(PciDevice0070 device0070) // TEST: NO
{
    // COMMON_LT((" | device0070 = %u", device0070)); // Commented to avoid bad looking logs



    switch (device0070)
    {
        case PciDevice0070::DEVICE_7801: return "WinTV HVR-1800 MCE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0070_PCIDEVICE0070_H
