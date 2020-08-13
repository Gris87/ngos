// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F0_PCIDEVICE13F0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F0_PCIDEVICE13F0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice13F0: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0200 = 0x0200,
    DEVICE_0201 = 0x0201,
    DEVICE_1021 = 0x1021,
    DEVICE_1023 = 0x1023
};



inline const char8* enumToString(PciDevice13F0 device13F0) // TEST: NO
{
    // COMMON_LT((" | device13F0 = %u", device13F0)); // Commented to avoid bad looking logs



    switch (device13F0)
    {
        case PciDevice13F0::NONE:        return "NONE";
        case PciDevice13F0::DEVICE_0200: return "DEVICE_0200";
        case PciDevice13F0::DEVICE_0201: return "DEVICE_0201";
        case PciDevice13F0::DEVICE_1021: return "DEVICE_1021";
        case PciDevice13F0::DEVICE_1023: return "DEVICE_1023";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice13F0 device13F0) // TEST: NO
{
    // COMMON_LT((" | device13F0 = %u", device13F0)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device13F0, enumToString(device13F0));

    return res;
}



inline const char8* enumToHumanString(PciDevice13F0 device13F0) // TEST: NO
{
    // COMMON_LT((" | device13F0 = %u", device13F0)); // Commented to avoid bad looking logs



    switch (device13F0)
    {
        case PciDevice13F0::DEVICE_0200: return "IC Plus IP100A Integrated 10/100 Ethernet MAC + PHY";
        case PciDevice13F0::DEVICE_0201: return "ST201 Sundance Ethernet";
        case PciDevice13F0::DEVICE_1021: return "TC902x Gigabit Ethernet";
        case PciDevice13F0::DEVICE_1023: return "IP1000 Family Gigabit Ethernet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F0_PCIDEVICE13F0_H
