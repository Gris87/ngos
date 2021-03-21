// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5F_PCIDEVICE1C5F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5F_PCIDEVICE1C5F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1c5f/pcisubdevice1c5f003e.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1C5F: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_000D = 0x000D,
    DEVICE_003D = 0x003D,
    DEVICE_003E = 0x003E,
    DEVICE_0540 = 0x0540,
    DEVICE_0550 = 0x0550,
    DEVICE_0555 = 0x0555,
    DEVICE_0557 = 0x0557
};



inline const char8* enumToString(PciDevice1C5F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1C5F::NONE:        return "NONE";
        case PciDevice1C5F::DEVICE_000D: return "DEVICE_000D";
        case PciDevice1C5F::DEVICE_003D: return "DEVICE_003D";
        case PciDevice1C5F::DEVICE_003E: return "DEVICE_003E";
        case PciDevice1C5F::DEVICE_0540: return "DEVICE_0540";
        case PciDevice1C5F::DEVICE_0550: return "DEVICE_0550";
        case PciDevice1C5F::DEVICE_0555: return "DEVICE_0555";
        case PciDevice1C5F::DEVICE_0557: return "DEVICE_0557";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1C5F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1C5F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1C5F::DEVICE_000D: return "PBlaze5 520/526";
        case PciDevice1C5F::DEVICE_003D: return "PBlaze5 920/926";
        case PciDevice1C5F::DEVICE_003E: return "PBlaze6 6920";
        case PciDevice1C5F::DEVICE_0540: return "PBlaze4 NVMe SSD";
        case PciDevice1C5F::DEVICE_0550: return "PBlaze5 700/900";
        case PciDevice1C5F::DEVICE_0555: return "PBlaze5 510/516";
        case PciDevice1C5F::DEVICE_0557: return "PBlaze5 910/916";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1C5F device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1C5F::DEVICE_000D: return "Unknown device";
        case PciDevice1C5F::DEVICE_003D: return "Unknown device";
        case PciDevice1C5F::DEVICE_003E: return enumToHumanString((PciSubDevice1C5F003E)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1C5F::DEVICE_0540: return "Unknown device";
        case PciDevice1C5F::DEVICE_0550: return "Unknown device";
        case PciDevice1C5F::DEVICE_0555: return "Unknown device";
        case PciDevice1C5F::DEVICE_0557: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5F_PCIDEVICE1C5F_H
