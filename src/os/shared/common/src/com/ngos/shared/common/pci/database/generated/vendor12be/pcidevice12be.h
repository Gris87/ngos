// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12BE_PCIDEVICE12BE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12BE_PCIDEVICE12BE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12BE: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3041 = 0x3041,
    DEVICE_3042 = 0x3042
};



inline const char8* enumToString(PciDevice12BE device12BE) // TEST: NO
{
    // COMMON_LT((" | device12BE = %u", device12BE)); // Commented to avoid bad looking logs



    switch (device12BE)
    {
        case PciDevice12BE::NONE:        return "NONE";
        case PciDevice12BE::DEVICE_3041: return "DEVICE_3041";
        case PciDevice12BE::DEVICE_3042: return "DEVICE_3042";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12BE device12BE) // TEST: NO
{
    // COMMON_LT((" | device12BE = %u", device12BE)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device12BE, enumToString(device12BE));

    return res;
}



inline const char8* enumToHumanString(PciDevice12BE device12BE) // TEST: NO
{
    // COMMON_LT((" | device12BE = %u", device12BE)); // Commented to avoid bad looking logs



    switch (device12BE)
    {
        case PciDevice12BE::DEVICE_3041: return "AN3041Q CO-MEM";
        case PciDevice12BE::DEVICE_3042: return "AN3042Q CO-MEM Lite";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12BE_PCIDEVICE12BE_H
