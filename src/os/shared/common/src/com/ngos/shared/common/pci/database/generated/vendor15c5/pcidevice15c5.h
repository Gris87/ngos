// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15C5_PCIDEVICE15C5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15C5_PCIDEVICE15C5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice15C5: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8010 = 0x8010
};



inline const char8* enumToString(PciDevice15C5 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice15C5::NONE:        return "NONE";
        case PciDevice15C5::DEVICE_8010: return "DEVICE_8010";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice15C5 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice15C5 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice15C5::DEVICE_8010: return "1394b - 1394 Firewire 3-Port Host Adapter Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15C5_PCIDEVICE15C5_H
