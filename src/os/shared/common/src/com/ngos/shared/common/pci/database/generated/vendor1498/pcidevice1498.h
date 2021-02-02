// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1498_PCIDEVICE1498_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1498_PCIDEVICE1498_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1498: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0330 = 0x0330,
    DEVICE_035D = 0x035D,
    DEVICE_0385 = 0x0385,
    DEVICE_21CC = 0x21CC,
    DEVICE_21CD = 0x21CD,
    DEVICE_3064 = 0x3064,
    DEVICE_30C8 = 0x30C8,
    DEVICE_70C8 = 0x70C8,
    DEVICE_9177 = 0x9177
};



inline const char8* enumToString(PciDevice1498 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1498::NONE:        return "NONE";
        case PciDevice1498::DEVICE_0330: return "DEVICE_0330";
        case PciDevice1498::DEVICE_035D: return "DEVICE_035D";
        case PciDevice1498::DEVICE_0385: return "DEVICE_0385";
        case PciDevice1498::DEVICE_21CC: return "DEVICE_21CC";
        case PciDevice1498::DEVICE_21CD: return "DEVICE_21CD";
        case PciDevice1498::DEVICE_3064: return "DEVICE_3064";
        case PciDevice1498::DEVICE_30C8: return "DEVICE_30C8";
        case PciDevice1498::DEVICE_70C8: return "DEVICE_70C8";
        case PciDevice1498::DEVICE_9177: return "DEVICE_9177";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1498 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1498 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1498::DEVICE_0330: return "TPMC816 2 Channel CAN bus controller.";
        case PciDevice1498::DEVICE_035D: return "TPMC861 4-Channel Isolated Serial Interface RS422/RS485";
        case PciDevice1498::DEVICE_0385: return "TPMC901 Extended CAN bus with 2/4/6 CAN controller";
        case PciDevice1498::DEVICE_21CC: return "TCP460 CompactPCI 16 Channel Serial Interface RS232/RS422";
        case PciDevice1498::DEVICE_21CD: return "TCP461 CompactPCI 8 Channel Serial Interface RS232/RS422";
        case PciDevice1498::DEVICE_3064: return "TPCI100 (2 Slot IndustryPack PCI Carrier)";
        case PciDevice1498::DEVICE_30C8: return "TPCI200 4 Slot IndustryPack PCI Carrier";
        case PciDevice1498::DEVICE_70C8: return "TPCE200 4 Slot IndustryPack PCIe Carrier";
        case PciDevice1498::DEVICE_9177: return "TXMC375 8 channel RS232/RS422/RS485 programmable serial interface";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1498_PCIDEVICE1498_H
