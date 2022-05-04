// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCIDEVICE0731_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCIDEVICE0731_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0731/pcisubdevice07317200.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0731/pcisubdevice07319100.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0731/pcisubdevice0731910a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0731/pcisubdevice0731920a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0731/pcisubdevice07319210.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0731/pcisubdevice07319230.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0731/pcisubdevice07319250.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0731/pcisubdevice0731930a.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice0731: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_7200 = 0x7200,
    DEVICE_9100 = 0x9100,
    DEVICE_910A = 0x910A,
    DEVICE_9200 = 0x9200,
    DEVICE_920A = 0x920A,
    DEVICE_920B = 0x920B,
    DEVICE_920C = 0x920C,
    DEVICE_9210 = 0x9210,
    DEVICE_9211 = 0x9211,
    DEVICE_9230 = 0x9230,
    DEVICE_9231 = 0x9231,
    DEVICE_9250 = 0x9250,
    DEVICE_930A = 0x930A,
    DEVICE_930B = 0x930B
};



inline const char8* enumToString(PciDevice0731 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice0731::NONE:        return "NONE";
        case PciDevice0731::DEVICE_7200: return "DEVICE_7200";
        case PciDevice0731::DEVICE_9100: return "DEVICE_9100";
        case PciDevice0731::DEVICE_910A: return "DEVICE_910A";
        case PciDevice0731::DEVICE_9200: return "DEVICE_9200";
        case PciDevice0731::DEVICE_920A: return "DEVICE_920A";
        case PciDevice0731::DEVICE_920B: return "DEVICE_920B";
        case PciDevice0731::DEVICE_920C: return "DEVICE_920C";
        case PciDevice0731::DEVICE_9210: return "DEVICE_9210";
        case PciDevice0731::DEVICE_9211: return "DEVICE_9211";
        case PciDevice0731::DEVICE_9230: return "DEVICE_9230";
        case PciDevice0731::DEVICE_9231: return "DEVICE_9231";
        case PciDevice0731::DEVICE_9250: return "DEVICE_9250";
        case PciDevice0731::DEVICE_930A: return "DEVICE_930A";
        case PciDevice0731::DEVICE_930B: return "DEVICE_930B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice0731 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice0731 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice0731::DEVICE_7200: return "JM7200 Series GPU";
        case PciDevice0731::DEVICE_9100: return "JM9100";
        case PciDevice0731::DEVICE_910A: return "JH910";
        case PciDevice0731::DEVICE_9200: return "JM9200";
        case PciDevice0731::DEVICE_920A: return "JH920";
        case PciDevice0731::DEVICE_920B: return "JH920-I";
        case PciDevice0731::DEVICE_920C: return "JH920-M";
        case PciDevice0731::DEVICE_9210: return "JM9210";
        case PciDevice0731::DEVICE_9211: return "JM9210-I";
        case PciDevice0731::DEVICE_9230: return "JM9230";
        case PciDevice0731::DEVICE_9231: return "JM9231-I";
        case PciDevice0731::DEVICE_9250: return "JM9250";
        case PciDevice0731::DEVICE_930A: return "JH930-I";
        case PciDevice0731::DEVICE_930B: return "JH930-M";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice0731 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice0731::DEVICE_7200: return enumToHumanString((PciSubDevice07317200)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice0731::DEVICE_9100: return enumToHumanString((PciSubDevice07319100)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice0731::DEVICE_910A: return enumToHumanString((PciSubDevice0731910A)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice0731::DEVICE_9200: return "Unknown device";
        case PciDevice0731::DEVICE_920A: return enumToHumanString((PciSubDevice0731920A)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice0731::DEVICE_920B: return "Unknown device";
        case PciDevice0731::DEVICE_920C: return "Unknown device";
        case PciDevice0731::DEVICE_9210: return enumToHumanString((PciSubDevice07319210)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice0731::DEVICE_9211: return "Unknown device";
        case PciDevice0731::DEVICE_9230: return enumToHumanString((PciSubDevice07319230)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice0731::DEVICE_9231: return "Unknown device";
        case PciDevice0731::DEVICE_9250: return enumToHumanString((PciSubDevice07319250)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice0731::DEVICE_930A: return enumToHumanString((PciSubDevice0731930A)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice0731::DEVICE_930B: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0731_PCIDEVICE0731_H
