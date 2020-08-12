// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR544D_PCIDEVICE544D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR544D_PCIDEVICE544D_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice544D: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_6178 = 0x6178
};



inline const char8* enumToString(PciDevice544D device544D) // TEST: NO
{
    // COMMON_LT((" | device544D = %u", device544D)); // Commented to avoid bad looking logs



    switch (device544D)
    {
        case PciDevice544D::NONE:        return "NONE";
        case PciDevice544D::DEVICE_6178: return "DEVICE_6178";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice544D device544D) // TEST: NO
{
    // COMMON_LT((" | device544D = %u", device544D)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device544D, enumToString(device544D));

    return res;
}



inline const char8* enumToHumanString(PciDevice544D device544D) // TEST: NO
{
    // COMMON_LT((" | device544D = %u", device544D)); // Commented to avoid bad looking logs



    switch (device544D)
    {
        case PciDevice544D::DEVICE_6178: return "DVB Tuner PCIe Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR544D_PCIDEVICE544D_H
