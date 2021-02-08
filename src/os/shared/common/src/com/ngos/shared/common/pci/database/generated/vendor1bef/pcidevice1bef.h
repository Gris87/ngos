// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BEF_PCIDEVICE1BEF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BEF_PCIDEVICE1BEF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1BEF: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0011 = 0x0011
};



inline const char8* enumToString(PciDevice1BEF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1BEF::NONE:        return "NONE";
        case PciDevice1BEF::DEVICE_0011: return "DEVICE_0011";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1BEF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1BEF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1BEF::DEVICE_0011: return "MIPS SoC PCI Express Port";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BEF_PCIDEVICE1BEF_H
