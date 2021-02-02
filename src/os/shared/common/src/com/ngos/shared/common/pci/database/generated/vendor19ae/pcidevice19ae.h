// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19AE_PCIDEVICE19AE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19AE_PCIDEVICE19AE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice19AE: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0520 = 0x0520,
    DEVICE_0521 = 0x0521
};



inline const char8* enumToString(PciDevice19AE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice19AE::NONE:        return "NONE";
        case PciDevice19AE::DEVICE_0520: return "DEVICE_0520";
        case PciDevice19AE::DEVICE_0521: return "DEVICE_0521";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice19AE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice19AE device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice19AE::DEVICE_0520: return "4135 HFT Interface Controller";
        case PciDevice19AE::DEVICE_0521: return "Decimator";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19AE_PCIDEVICE19AE_H
