// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1043_PCIDEVICE1043_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1043_PCIDEVICE1043_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1043: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0464 = 0x0464,
    DEVICE_0521 = 0x0521,
    DEVICE_0675 = 0x0675,
    DEVICE_9602 = 0x9602
};



inline const char8* enumToString(PciDevice1043 device1043) // TEST: NO
{
    // COMMON_LT((" | device1043 = %u", device1043)); // Commented to avoid bad looking logs



    switch (device1043)
    {
        case PciDevice1043::NONE:        return "NONE";
        case PciDevice1043::DEVICE_0464: return "DEVICE_0464";
        case PciDevice1043::DEVICE_0521: return "DEVICE_0521";
        case PciDevice1043::DEVICE_0675: return "DEVICE_0675";
        case PciDevice1043::DEVICE_9602: return "DEVICE_9602";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1043 device1043) // TEST: NO
{
    // COMMON_LT((" | device1043 = %u", device1043)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1043, enumToString(device1043));

    return res;
}



inline const char8* enumToHumanString(PciDevice1043 device1043) // TEST: NO
{
    // COMMON_LT((" | device1043 = %u", device1043)); // Commented to avoid bad looking logs



    switch (device1043)
    {
        case PciDevice1043::DEVICE_0464: return "Radeon R9 270x GPU";
        case PciDevice1043::DEVICE_0521: return "RX580 [RX 580 Dual O8G]";
        case PciDevice1043::DEVICE_0675: return "ISDNLink P-IN100-ST-D";
        case PciDevice1043::DEVICE_9602: return "AMD RS780/RS880 PCI to PCI bridge (int gfx)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1043_PCIDEVICE1043_H
