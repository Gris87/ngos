// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1109_PCIDEVICE1109_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1109_PCIDEVICE1109_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1109: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1400 = 0x1400
};



inline const char8* enumToString(PciDevice1109 device1109) // TEST: NO
{
    // COMMON_LT((" | device1109 = %u", device1109)); // Commented to avoid bad looking logs



    switch (device1109)
    {
        case PciDevice1109::NONE:        return "NONE";
        case PciDevice1109::DEVICE_1400: return "DEVICE_1400";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1109 device1109) // TEST: NO
{
    // COMMON_LT((" | device1109 = %u", device1109)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1109, enumToString(device1109));

    return res;
}



inline const char8* enumToHumanString(PciDevice1109 device1109) // TEST: NO
{
    // COMMON_LT((" | device1109 = %u", device1109)); // Commented to avoid bad looking logs



    switch (device1109)
    {
        case PciDevice1109::DEVICE_1400: return "EM110TX [EX110TX]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1109_PCIDEVICE1109_H
