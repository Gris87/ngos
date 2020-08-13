// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4D51_PCIDEVICE4D51_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4D51_PCIDEVICE4D51_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice4D51: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0200 = 0x0200
};



inline const char8* enumToString(PciDevice4D51 device4D51) // TEST: NO
{
    // COMMON_LT((" | device4D51 = %u", device4D51)); // Commented to avoid bad looking logs



    switch (device4D51)
    {
        case PciDevice4D51::NONE:        return "NONE";
        case PciDevice4D51::DEVICE_0200: return "DEVICE_0200";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice4D51 device4D51) // TEST: NO
{
    // COMMON_LT((" | device4D51 = %u", device4D51)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device4D51, enumToString(device4D51));

    return res;
}



inline const char8* enumToHumanString(PciDevice4D51 device4D51) // TEST: NO
{
    // COMMON_LT((" | device4D51 = %u", device4D51)); // Commented to avoid bad looking logs



    switch (device4D51)
    {
        case PciDevice4D51::DEVICE_0200: return "MQ-200";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4D51_PCIDEVICE4D51_H
