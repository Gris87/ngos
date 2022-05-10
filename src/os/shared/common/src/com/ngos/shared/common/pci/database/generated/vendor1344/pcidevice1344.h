// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1344_PCIDEVICE1344_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1344_PCIDEVICE1344_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1344/pcisubdevice134451b1.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1344/pcisubdevice134451b2.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1344/pcisubdevice134451c0.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1344/pcisubdevice134451c1.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1344: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_5150 = 0x5150,
    DEVICE_5151 = 0x5151,
    DEVICE_5152 = 0x5152,
    DEVICE_5153 = 0x5153,
    DEVICE_5160 = 0x5160,
    DEVICE_5161 = 0x5161,
    DEVICE_5163 = 0x5163,
    DEVICE_5180 = 0x5180,
    DEVICE_5181 = 0x5181,
    DEVICE_5190 = 0x5190,
    DEVICE_5191 = 0x5191,
    DEVICE_5192 = 0x5192,
    DEVICE_51A2 = 0x51A2,
    DEVICE_51A3 = 0x51A3,
    DEVICE_51B1 = 0x51B1,
    DEVICE_51B2 = 0x51B2,
    DEVICE_51C0 = 0x51C0,
    DEVICE_51C1 = 0x51C1,
    DEVICE_51C3 = 0x51C3,
    DEVICE_51C4 = 0x51C4
};



inline const char8* enumToString(PciDevice1344 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1344::NONE:        return "NONE";
        case PciDevice1344::DEVICE_5150: return "DEVICE_5150";
        case PciDevice1344::DEVICE_5151: return "DEVICE_5151";
        case PciDevice1344::DEVICE_5152: return "DEVICE_5152";
        case PciDevice1344::DEVICE_5153: return "DEVICE_5153";
        case PciDevice1344::DEVICE_5160: return "DEVICE_5160";
        case PciDevice1344::DEVICE_5161: return "DEVICE_5161";
        case PciDevice1344::DEVICE_5163: return "DEVICE_5163";
        case PciDevice1344::DEVICE_5180: return "DEVICE_5180";
        case PciDevice1344::DEVICE_5181: return "DEVICE_5181";
        case PciDevice1344::DEVICE_5190: return "DEVICE_5190";
        case PciDevice1344::DEVICE_5191: return "DEVICE_5191";
        case PciDevice1344::DEVICE_5192: return "DEVICE_5192";
        case PciDevice1344::DEVICE_51A2: return "DEVICE_51A2";
        case PciDevice1344::DEVICE_51A3: return "DEVICE_51A3";
        case PciDevice1344::DEVICE_51B1: return "DEVICE_51B1";
        case PciDevice1344::DEVICE_51B2: return "DEVICE_51B2";
        case PciDevice1344::DEVICE_51C0: return "DEVICE_51C0";
        case PciDevice1344::DEVICE_51C1: return "DEVICE_51C1";
        case PciDevice1344::DEVICE_51C3: return "DEVICE_51C3";
        case PciDevice1344::DEVICE_51C4: return "DEVICE_51C4";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1344 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1344 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1344::DEVICE_5150: return "RealSSD P320h";
        case PciDevice1344::DEVICE_5151: return "RealSSD P320m";
        case PciDevice1344::DEVICE_5152: return "RealSSD P320s";
        case PciDevice1344::DEVICE_5153: return "RealSSD P325m";
        case PciDevice1344::DEVICE_5160: return "RealSSD P420h";
        case PciDevice1344::DEVICE_5161: return "RealSSD P420m";
        case PciDevice1344::DEVICE_5163: return "RealSSD P425m";
        case PciDevice1344::DEVICE_5180: return "9100 PRO NVMe SSD";
        case PciDevice1344::DEVICE_5181: return "9100 MAX NVMe SSD";
        case PciDevice1344::DEVICE_5190: return "9200 ECO NVMe SSD";
        case PciDevice1344::DEVICE_5191: return "9200 PRO NVMe SSD";
        case PciDevice1344::DEVICE_5192: return "9200 MAX NVMe SSD";
        case PciDevice1344::DEVICE_51A2: return "7300 PRO NVMe SSD";
        case PciDevice1344::DEVICE_51A3: return "7300 MAX NVMe SSD";
        case PciDevice1344::DEVICE_51B1: return "9300 PRO NVMe SSD";
        case PciDevice1344::DEVICE_51B2: return "9300 MAX NVMe SSD";
        case PciDevice1344::DEVICE_51C0: return "7400 PRO NVMe SSD";
        case PciDevice1344::DEVICE_51C1: return "7400 MAX NVMe SSD";
        case PciDevice1344::DEVICE_51C3: return "7450 PRO NVMe SSD";
        case PciDevice1344::DEVICE_51C4: return "7450 MAX NVMe SSD";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1344 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1344::DEVICE_5150: return "Unknown device";
        case PciDevice1344::DEVICE_5151: return "Unknown device";
        case PciDevice1344::DEVICE_5152: return "Unknown device";
        case PciDevice1344::DEVICE_5153: return "Unknown device";
        case PciDevice1344::DEVICE_5160: return "Unknown device";
        case PciDevice1344::DEVICE_5161: return "Unknown device";
        case PciDevice1344::DEVICE_5163: return "Unknown device";
        case PciDevice1344::DEVICE_5180: return "Unknown device";
        case PciDevice1344::DEVICE_5181: return "Unknown device";
        case PciDevice1344::DEVICE_5190: return "Unknown device";
        case PciDevice1344::DEVICE_5191: return "Unknown device";
        case PciDevice1344::DEVICE_5192: return "Unknown device";
        case PciDevice1344::DEVICE_51A2: return "Unknown device";
        case PciDevice1344::DEVICE_51A3: return "Unknown device";
        case PciDevice1344::DEVICE_51B1: return enumToHumanString((PciSubDevice134451B1)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1344::DEVICE_51B2: return enumToHumanString((PciSubDevice134451B2)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1344::DEVICE_51C0: return enumToHumanString((PciSubDevice134451C0)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1344::DEVICE_51C1: return enumToHumanString((PciSubDevice134451C1)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1344::DEVICE_51C3: return "Unknown device";
        case PciDevice1344::DEVICE_51C4: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1344_PCIDEVICE1344_H
