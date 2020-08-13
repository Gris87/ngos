// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1344_PCIDEVICE1344_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1344_PCIDEVICE1344_H



#include <com/ngos/shared/common/ngos/types.h>
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
    DEVICE_5192 = 0x5192
};



inline const char8* enumToString(PciDevice1344 device1344) // TEST: NO
{
    // COMMON_LT((" | device1344 = %u", device1344)); // Commented to avoid bad looking logs



    switch (device1344)
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

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1344 device1344) // TEST: NO
{
    // COMMON_LT((" | device1344 = %u", device1344)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1344, enumToString(device1344));

    return res;
}



inline const char8* enumToHumanString(PciDevice1344 device1344) // TEST: NO
{
    // COMMON_LT((" | device1344 = %u", device1344)); // Commented to avoid bad looking logs



    switch (device1344)
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

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1344_PCIDEVICE1344_H
