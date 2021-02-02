// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR136B_PCIDEVICE136B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR136B_PCIDEVICE136B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice136B: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_FF01 = 0xFF01
};



inline const char8* enumToString(PciDevice136B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice136B::NONE:        return "NONE";
        case PciDevice136B::DEVICE_FF01: return "DEVICE_FF01";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice136B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice136B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice136B::DEVICE_FF01: return "KL5A72002 Motion JPEG";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR136B_PCIDEVICE136B_H
