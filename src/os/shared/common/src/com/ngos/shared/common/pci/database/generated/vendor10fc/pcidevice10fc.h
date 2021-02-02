// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10FC_PCIDEVICE10FC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10FC_PCIDEVICE10FC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10FC: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0003 = 0x0003,
    DEVICE_0005 = 0x0005
};



inline const char8* enumToString(PciDevice10FC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10FC::NONE:        return "NONE";
        case PciDevice10FC::DEVICE_0003: return "DEVICE_0003";
        case PciDevice10FC::DEVICE_0005: return "DEVICE_0005";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10FC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice10FC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10FC::DEVICE_0003: return "Cardbus IDE Controller";
        case PciDevice10FC::DEVICE_0005: return "Cardbus SCSI CBSC II";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10FC_PCIDEVICE10FC_H
