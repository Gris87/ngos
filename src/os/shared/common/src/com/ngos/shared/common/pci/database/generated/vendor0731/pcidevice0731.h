// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCIDEVICE0731_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCIDEVICE0731_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice0731: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_7200 = 0x7200
};



inline const char8* enumToString(PciDevice0731 device0731) // TEST: NO
{
    // COMMON_LT((" | device0731 = %u", device0731)); // Commented to avoid bad looking logs



    switch (device0731)
    {
        case PciDevice0731::NONE:        return "NONE";
        case PciDevice0731::DEVICE_7200: return "DEVICE_7200";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice0731 device0731) // TEST: NO
{
    // COMMON_LT((" | device0731 = %u", device0731)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device0731, enumToString(device0731));

    return res;
}



inline const char8* enumToHumanString(PciDevice0731 device0731) // TEST: NO
{
    // COMMON_LT((" | device0731 = %u", device0731)); // Commented to avoid bad looking logs



    switch (device0731)
    {
        case PciDevice0731::DEVICE_7200: return "JM7200 Series GPU";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCIDEVICE0731_H
