// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0432_PCIDEVICE0432_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0432_PCIDEVICE0432_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice0432: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice0432 device0432) // TEST: NO
{
    // COMMON_LT((" | device0432 = %u", device0432)); // Commented to avoid bad looking logs



    switch (device0432)
    {
        case PciDevice0432::NONE:        return "NONE";
        case PciDevice0432::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice0432 device0432) // TEST: NO
{
    // COMMON_LT((" | device0432 = %u", device0432)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device0432, enumToString(device0432));

    return res;
}



inline const char8* enumToHumanString(PciDevice0432 device0432) // TEST: NO
{
    // COMMON_LT((" | device0432 = %u", device0432)); // Commented to avoid bad looking logs



    switch (device0432)
    {
        case PciDevice0432::DEVICE_0001: return "Pluto2 DVB-T Receiver for PCMCIA [EasyWatch MobilSet]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0432_PCIDEVICE0432_H
