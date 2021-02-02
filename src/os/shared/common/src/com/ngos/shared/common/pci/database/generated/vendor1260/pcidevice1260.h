// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1260_PCIDEVICE1260_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1260_PCIDEVICE1260_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1260/pcisubdevice12603872.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1260/pcisubdevice12603873.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1260/pcisubdevice12603886.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1260/pcisubdevice12603890.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1260/pcisubdevice1260ffff.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1260: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3872 = 0x3872,
    DEVICE_3873 = 0x3873,
    DEVICE_3877 = 0x3877,
    DEVICE_3886 = 0x3886,
    DEVICE_3890 = 0x3890,
    DEVICE_8130 = 0x8130,
    DEVICE_8131 = 0x8131,
    DEVICE_FFFF = 0xFFFF
};



inline const char8* enumToString(PciDevice1260 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1260::NONE:        return "NONE";
        case PciDevice1260::DEVICE_3872: return "DEVICE_3872";
        case PciDevice1260::DEVICE_3873: return "DEVICE_3873";
        case PciDevice1260::DEVICE_3877: return "DEVICE_3877";
        case PciDevice1260::DEVICE_3886: return "DEVICE_3886";
        case PciDevice1260::DEVICE_3890: return "DEVICE_3890";
        case PciDevice1260::DEVICE_8130: return "DEVICE_8130";
        case PciDevice1260::DEVICE_8131: return "DEVICE_8131";
        case PciDevice1260::DEVICE_FFFF: return "DEVICE_FFFF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1260 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1260 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1260::DEVICE_3872: return "ISL3872 [Prism 3]";
        case PciDevice1260::DEVICE_3873: return "ISL3874 [Prism 2.5]/ISL3872 [Prism 3]";
        case PciDevice1260::DEVICE_3877: return "ISL3877 [Prism Indigo]";
        case PciDevice1260::DEVICE_3886: return "ISL3886 [Prism Javelin/Prism Xbow]";
        case PciDevice1260::DEVICE_3890: return "ISL3890 [Prism GT/Prism Duette]/ISL3886 [Prism Javelin/Prism Xbow]";
        case PciDevice1260::DEVICE_8130: return "HMP8130 NTSC/PAL Video Decoder";
        case PciDevice1260::DEVICE_8131: return "HMP8131 NTSC/PAL Video Decoder";
        case PciDevice1260::DEVICE_FFFF: return "ISL3886IK";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1260 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1260::DEVICE_3872: return enumToHumanString((PciSubDevice12603872)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1260::DEVICE_3873: return enumToHumanString((PciSubDevice12603873)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1260::DEVICE_3877: return "Unknown device";
        case PciDevice1260::DEVICE_3886: return enumToHumanString((PciSubDevice12603886)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1260::DEVICE_3890: return enumToHumanString((PciSubDevice12603890)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1260::DEVICE_8130: return "Unknown device";
        case PciDevice1260::DEVICE_8131: return "Unknown device";
        case PciDevice1260::DEVICE_FFFF: return enumToHumanString((PciSubDevice1260FFFF)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1260_PCIDEVICE1260_H
