// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0357_PCIDEVICE0357_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0357_PCIDEVICE0357_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice0357: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_000A = 0x000A
};



inline const char8* enumToString(PciDevice0357 device0357) // TEST: NO
{
    // COMMON_LT((" | device0357 = %u", device0357)); // Commented to avoid bad looking logs



    switch (device0357)
    {
        case PciDevice0357::NONE:        return "NONE";
        case PciDevice0357::DEVICE_000A: return "DEVICE_000A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice0357 device0357) // TEST: NO
{
    // COMMON_LT((" | device0357 = %u", device0357)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device0357, enumToString(device0357));

    return res;
}



inline const char8* enumToHumanString(PciDevice0357 device0357) // TEST: NO
{
    // COMMON_LT((" | device0357 = %u", device0357)); // Commented to avoid bad looking logs



    switch (device0357)
    {
        case PciDevice0357::DEVICE_000A: return "TTP-Monitoring Card V2.0";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0357_PCIDEVICE0357_H
