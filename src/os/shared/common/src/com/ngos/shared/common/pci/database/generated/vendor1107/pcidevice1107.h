// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1107_PCIDEVICE1107_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1107_PCIDEVICE1107_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1107: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0576 = 0x0576
};



inline const char8* enumToString(PciDevice1107 device1107) // TEST: NO
{
    // COMMON_LT((" | device1107 = %u", device1107)); // Commented to avoid bad looking logs



    switch (device1107)
    {
        case PciDevice1107::NONE:        return "NONE";
        case PciDevice1107::DEVICE_0576: return "DEVICE_0576";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1107 device1107) // TEST: NO
{
    // COMMON_LT((" | device1107 = %u", device1107)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1107, enumToString(device1107));

    return res;
}



inline const char8* enumToHumanString(PciDevice1107 device1107) // TEST: NO
{
    // COMMON_LT((" | device1107 = %u", device1107)); // Commented to avoid bad looking logs



    switch (device1107)
    {
        case PciDevice1107::DEVICE_0576: return "VIA VT82C570MV [Apollo] (Wrong vendor ID!)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1107_PCIDEVICE1107_H
