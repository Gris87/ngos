// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E38_PCIDEVICE1E38_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E38_PCIDEVICE1E38_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1E38: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0102 = 0x0102
};



inline const char8* enumToString(PciDevice1E38 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E38::NONE:        return "NONE";
        case PciDevice1E38::DEVICE_0102: return "DEVICE_0102";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1E38 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1E38 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E38::DEVICE_0102: return "Xplorer X1600";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E38_PCIDEVICE1E38_H
