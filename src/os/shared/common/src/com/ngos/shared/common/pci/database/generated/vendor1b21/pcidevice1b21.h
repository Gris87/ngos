// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B21_PCIDEVICE1B21_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B21_PCIDEVICE1B21_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b21/pcisubdevice1b210612.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b21/pcisubdevice1b211042.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b21/pcisubdevice1b211080.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b21/pcisubdevice1b211182.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b21/pcisubdevice1b211184.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b21/pcisubdevice1b212142.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1B21: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0611 = 0x0611,
    DEVICE_0612 = 0x0612,
    DEVICE_1040 = 0x1040,
    DEVICE_1042 = 0x1042,
    DEVICE_1080 = 0x1080,
    DEVICE_1142 = 0x1142,
    DEVICE_1166 = 0x1166,
    DEVICE_1182 = 0x1182,
    DEVICE_1184 = 0x1184,
    DEVICE_1187 = 0x1187,
    DEVICE_1242 = 0x1242,
    DEVICE_1343 = 0x1343,
    DEVICE_1812 = 0x1812,
    DEVICE_2142 = 0x2142,
    DEVICE_2824 = 0x2824,
    DEVICE_3242 = 0x3242
};



inline const char8* enumToString(PciDevice1B21 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1B21::NONE:        return "NONE";
        case PciDevice1B21::DEVICE_0611: return "DEVICE_0611";
        case PciDevice1B21::DEVICE_0612: return "DEVICE_0612";
        case PciDevice1B21::DEVICE_1040: return "DEVICE_1040";
        case PciDevice1B21::DEVICE_1042: return "DEVICE_1042";
        case PciDevice1B21::DEVICE_1080: return "DEVICE_1080";
        case PciDevice1B21::DEVICE_1142: return "DEVICE_1142";
        case PciDevice1B21::DEVICE_1166: return "DEVICE_1166";
        case PciDevice1B21::DEVICE_1182: return "DEVICE_1182";
        case PciDevice1B21::DEVICE_1184: return "DEVICE_1184";
        case PciDevice1B21::DEVICE_1187: return "DEVICE_1187";
        case PciDevice1B21::DEVICE_1242: return "DEVICE_1242";
        case PciDevice1B21::DEVICE_1343: return "DEVICE_1343";
        case PciDevice1B21::DEVICE_1812: return "DEVICE_1812";
        case PciDevice1B21::DEVICE_2142: return "DEVICE_2142";
        case PciDevice1B21::DEVICE_2824: return "DEVICE_2824";
        case PciDevice1B21::DEVICE_3242: return "DEVICE_3242";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1B21 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1B21 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1B21::DEVICE_0611: return "ASM1061 SATA IDE Controller";
        case PciDevice1B21::DEVICE_0612: return "ASM1062 Serial ATA Controller";
        case PciDevice1B21::DEVICE_1040: return "ASM1040 XHCI Controller";
        case PciDevice1B21::DEVICE_1042: return "ASM1042 SuperSpeed USB Host Controller";
        case PciDevice1B21::DEVICE_1080: return "ASM1083/1085 PCIe to PCI Bridge";
        case PciDevice1B21::DEVICE_1142: return "ASM1042A USB 3.0 Host Controller";
        case PciDevice1B21::DEVICE_1166: return "ASM1166 Serial ATA Controller";
        case PciDevice1B21::DEVICE_1182: return "ASM1182e 2-Port PCIe x1 Gen2 Packet Switch";
        case PciDevice1B21::DEVICE_1184: return "ASM1184e 4-Port PCIe x1 Gen2 Packet Switch";
        case PciDevice1B21::DEVICE_1187: return "ASM1187e 7-Port PCIe x1 Gen2 Packet Switch";
        case PciDevice1B21::DEVICE_1242: return "ASM1142 USB 3.1 Host Controller";
        case PciDevice1B21::DEVICE_1343: return "ASM1143 USB 3.1 Host Controller";
        case PciDevice1B21::DEVICE_1812: return "ASM1812 6-Port PCIe x4 Gen2 Packet Switch";
        case PciDevice1B21::DEVICE_2142: return "ASM2142 USB 3.1 Host Controller";
        case PciDevice1B21::DEVICE_2824: return "ASM2824 PCIe Gen3 Packet Switch";
        case PciDevice1B21::DEVICE_3242: return "ASM3242 USB 3.2 Host Controller";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1B21 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1B21::DEVICE_0611: return "Unknown device";
        case PciDevice1B21::DEVICE_0612: return enumToHumanString((PciSubDevice1B210612)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1B21::DEVICE_1040: return "Unknown device";
        case PciDevice1B21::DEVICE_1042: return enumToHumanString((PciSubDevice1B211042)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1B21::DEVICE_1080: return enumToHumanString((PciSubDevice1B211080)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1B21::DEVICE_1142: return "Unknown device";
        case PciDevice1B21::DEVICE_1166: return "Unknown device";
        case PciDevice1B21::DEVICE_1182: return enumToHumanString((PciSubDevice1B211182)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1B21::DEVICE_1184: return enumToHumanString((PciSubDevice1B211184)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1B21::DEVICE_1187: return "Unknown device";
        case PciDevice1B21::DEVICE_1242: return "Unknown device";
        case PciDevice1B21::DEVICE_1343: return "Unknown device";
        case PciDevice1B21::DEVICE_1812: return "Unknown device";
        case PciDevice1B21::DEVICE_2142: return enumToHumanString((PciSubDevice1B212142)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1B21::DEVICE_2824: return "Unknown device";
        case PciDevice1B21::DEVICE_3242: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B21_PCIDEVICE1B21_H
