// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0795_PCIDEVICE0795_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0795_PCIDEVICE0795_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice0795: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_6663 = 0x6663,
    DEVICE_6666 = 0x6666
};



inline const char8* enumToString(PciDevice0795 device0795) // TEST: NO
{
    // COMMON_LT((" | device0795 = %u", device0795)); // Commented to avoid bad looking logs



    switch (device0795)
    {
        case PciDevice0795::NONE:        return "NONE";
        case PciDevice0795::DEVICE_6663: return "DEVICE_6663";
        case PciDevice0795::DEVICE_6666: return "DEVICE_6666";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice0795 device0795) // TEST: NO
{
    // COMMON_LT((" | device0795 = %u", device0795)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device0795, enumToString(device0795));

    return res;
}



inline const char8* enumToHumanString(PciDevice0795 device0795) // TEST: NO
{
    // COMMON_LT((" | device0795 = %u", device0795)); // Commented to avoid bad looking logs



    switch (device0795)
    {
        case PciDevice0795::DEVICE_6663: return "Butane II (MPEG2 encoder board)";
        case PciDevice0795::DEVICE_6666: return "MediaPress (MPEG2 encoder board)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0795_PCIDEVICE0795_H
