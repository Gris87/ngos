// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1743_PCIDEVICE1743_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1743_PCIDEVICE1743_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1743: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8139 = 0x8139
};



inline const char8* enumToString(PciDevice1743 device1743) // TEST: NO
{
    // COMMON_LT((" | device1743 = %u", device1743)); // Commented to avoid bad looking logs



    switch (device1743)
    {
        case PciDevice1743::NONE:        return "NONE";
        case PciDevice1743::DEVICE_8139: return "DEVICE_8139";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1743 device1743) // TEST: NO
{
    // COMMON_LT((" | device1743 = %u", device1743)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1743, enumToString(device1743));

    return res;
}



inline const char8* enumToHumanString(PciDevice1743 device1743) // TEST: NO
{
    // COMMON_LT((" | device1743 = %u", device1743)); // Commented to avoid bad looking logs



    switch (device1743)
    {
        case PciDevice1743::DEVICE_8139: return "ROL/F-100 Fast Ethernet Adapter with ROL";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1743_PCIDEVICE1743_H
