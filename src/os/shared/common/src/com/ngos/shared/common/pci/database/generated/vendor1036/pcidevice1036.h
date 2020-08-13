// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1036_PCIDEVICE1036_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1036_PCIDEVICE1036_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1036: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000
};



inline const char8* enumToString(PciDevice1036 device1036) // TEST: NO
{
    // COMMON_LT((" | device1036 = %u", device1036)); // Commented to avoid bad looking logs



    switch (device1036)
    {
        case PciDevice1036::DEVICE_0000: return "DEVICE_0000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1036 device1036) // TEST: NO
{
    // COMMON_LT((" | device1036 = %u", device1036)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1036, enumToString(device1036));

    return res;
}



inline const char8* enumToHumanString(PciDevice1036 device1036) // TEST: NO
{
    // COMMON_LT((" | device1036 = %u", device1036)); // Commented to avoid bad looking logs



    switch (device1036)
    {
        case PciDevice1036::DEVICE_0000: return "TMC-18C30 [36C70]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1036_PCIDEVICE1036_H
