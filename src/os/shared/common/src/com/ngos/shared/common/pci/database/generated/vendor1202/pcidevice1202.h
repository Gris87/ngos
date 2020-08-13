// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1202_PCIDEVICE1202_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1202_PCIDEVICE1202_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1202: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4300 = 0x4300
};



inline const char8* enumToString(PciDevice1202 device1202) // TEST: NO
{
    // COMMON_LT((" | device1202 = %u", device1202)); // Commented to avoid bad looking logs



    switch (device1202)
    {
        case PciDevice1202::NONE:        return "NONE";
        case PciDevice1202::DEVICE_4300: return "DEVICE_4300";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1202 device1202) // TEST: NO
{
    // COMMON_LT((" | device1202 = %u", device1202)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1202, enumToString(device1202));

    return res;
}



inline const char8* enumToHumanString(PciDevice1202 device1202) // TEST: NO
{
    // COMMON_LT((" | device1202 = %u", device1202)); // Commented to avoid bad looking logs



    switch (device1202)
    {
        case PciDevice1202::DEVICE_4300: return "Gigabit Ethernet Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1202_PCIDEVICE1202_H
