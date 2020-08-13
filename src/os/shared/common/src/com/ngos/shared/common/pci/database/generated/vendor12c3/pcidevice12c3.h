// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12C3_PCIDEVICE12C3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12C3_PCIDEVICE12C3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12C3: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0058 = 0x0058,
    DEVICE_5598 = 0x5598
};



inline const char8* enumToString(PciDevice12C3 device12C3) // TEST: NO
{
    // COMMON_LT((" | device12C3 = %u", device12C3)); // Commented to avoid bad looking logs



    switch (device12C3)
    {
        case PciDevice12C3::NONE:        return "NONE";
        case PciDevice12C3::DEVICE_0058: return "DEVICE_0058";
        case PciDevice12C3::DEVICE_5598: return "DEVICE_5598";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12C3 device12C3) // TEST: NO
{
    // COMMON_LT((" | device12C3 = %u", device12C3)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device12C3, enumToString(device12C3));

    return res;
}



inline const char8* enumToHumanString(PciDevice12C3 device12C3) // TEST: NO
{
    // COMMON_LT((" | device12C3 = %u", device12C3)); // Commented to avoid bad looking logs



    switch (device12C3)
    {
        case PciDevice12C3::DEVICE_0058: return "PCI NE2K Ethernet";
        case PciDevice12C3::DEVICE_5598: return "PCI NE2K Ethernet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12C3_PCIDEVICE12C3_H
