// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F6_PCIDEVICE13F6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F6_PCIDEVICE13F6_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13f6/pcisubdevice13f60100.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13f6/pcisubdevice13f60101.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13f6/pcisubdevice13f60111.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13f6/pcisubdevice13f65011.h>
#include <com/ngos/shared/common/pci/database/generated/vendor13f6/pcisubdevice13f68788.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice13F6: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0011 = 0x0011,
    DEVICE_0100 = 0x0100,
    DEVICE_0101 = 0x0101,
    DEVICE_0111 = 0x0111,
    DEVICE_0211 = 0x0211,
    DEVICE_5011 = 0x5011,
    DEVICE_8788 = 0x8788
};



inline const char8* enumToString(PciDevice13F6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13F6::NONE:        return "NONE";
        case PciDevice13F6::DEVICE_0011: return "DEVICE_0011";
        case PciDevice13F6::DEVICE_0100: return "DEVICE_0100";
        case PciDevice13F6::DEVICE_0101: return "DEVICE_0101";
        case PciDevice13F6::DEVICE_0111: return "DEVICE_0111";
        case PciDevice13F6::DEVICE_0211: return "DEVICE_0211";
        case PciDevice13F6::DEVICE_5011: return "DEVICE_5011";
        case PciDevice13F6::DEVICE_8788: return "DEVICE_8788";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice13F6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice13F6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13F6::DEVICE_0011: return "CMi8738";
        case PciDevice13F6::DEVICE_0100: return "CM8338A";
        case PciDevice13F6::DEVICE_0101: return "CM8338B";
        case PciDevice13F6::DEVICE_0111: return "CMi8738/CMi8768 PCI Audio";
        case PciDevice13F6::DEVICE_0211: return "CM8738";
        case PciDevice13F6::DEVICE_5011: return "CM8888 [Oxygen Express]";
        case PciDevice13F6::DEVICE_8788: return "CMi8788 [Oxygen HD Audio]";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice13F6 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13F6::DEVICE_0011: return "Unknown device";
        case PciDevice13F6::DEVICE_0100: return enumToHumanString((PciSubDevice13F60100)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice13F6::DEVICE_0101: return enumToHumanString((PciSubDevice13F60101)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice13F6::DEVICE_0111: return enumToHumanString((PciSubDevice13F60111)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice13F6::DEVICE_0211: return "Unknown device";
        case PciDevice13F6::DEVICE_5011: return enumToHumanString((PciSubDevice13F65011)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice13F6::DEVICE_8788: return enumToHumanString((PciSubDevice13F68788)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F6_PCIDEVICE13F6_H
