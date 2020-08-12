// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR167D_PCIDEVICE167D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR167D_PCIDEVICE167D_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice167D: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_A000 = 0xA000
};



inline const char8* enumToString(PciDevice167D device167D) // TEST: NO
{
    // COMMON_LT((" | device167D = %u", device167D)); // Commented to avoid bad looking logs



    switch (device167D)
    {
        case PciDevice167D::NONE:        return "NONE";
        case PciDevice167D::DEVICE_A000: return "DEVICE_A000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice167D device167D) // TEST: NO
{
    // COMMON_LT((" | device167D = %u", device167D)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device167D, enumToString(device167D));

    return res;
}



inline const char8* enumToHumanString(PciDevice167D device167D) // TEST: NO
{
    // COMMON_LT((" | device167D = %u", device167D)); // Commented to avoid bad looking logs



    switch (device167D)
    {
        case PciDevice167D::DEVICE_A000: return "MagicLAN SWL-2210P 802.11b [Intersil ISL3874]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR167D_PCIDEVICE167D_H
