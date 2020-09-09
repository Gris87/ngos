// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCISUBDEVICE18140401_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCISUBDEVICE18140401_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice18140401: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17370052 = 0x17370052,
    SUBDEVICE_17F90011 = 0x17F90011,
    SUBDEVICE_17F90016 = 0x17F90016
};



inline const char8* enumToString(PciSubDevice18140401 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice18140401::NONE:               return "NONE";
        case PciSubDevice18140401::SUBDEVICE_17370052: return "SUBDEVICE_17370052";
        case PciSubDevice18140401::SUBDEVICE_17F90011: return "SUBDEVICE_17F90011";
        case PciSubDevice18140401::SUBDEVICE_17F90016: return "SUBDEVICE_17F90016";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice18140401 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice18140401 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice18140401::SUBDEVICE_17370052: return "WPC54GR v1 802.11g Wireless-G Notebook Adapter with RangeBooster";
        case PciSubDevice18140401::SUBDEVICE_17F90011: return "WPCR-137G 802.11bg Wireless CardBus Adapter";
        case PciSubDevice18140401::SUBDEVICE_17F90016: return "WPIR-119GH 802.11bg Wireless Desktop Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCISUBDEVICE18140401_H
