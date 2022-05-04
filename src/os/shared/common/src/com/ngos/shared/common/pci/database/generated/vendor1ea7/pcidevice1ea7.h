// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1EA7_PCIDEVICE1EA7_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1EA7_PCIDEVICE1EA7_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1EA7: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_223A = 0x223A,
    DEVICE_224A = 0x224A
};



inline const char8* enumToString(PciDevice1EA7 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1EA7::NONE:        return "NONE";
        case PciDevice1EA7::DEVICE_223A: return "DEVICE_223A";
        case PciDevice1EA7::DEVICE_224A: return "DEVICE_224A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1EA7 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1EA7 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1EA7::DEVICE_223A: return "Typhon+ PCIe to Gen-Z Bridge";
        case PciDevice1EA7::DEVICE_224A: return "IPA-PE224A CXL to Gen-Z Bridge [Sphinx]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1EA7_PCIDEVICE1EA7_H
