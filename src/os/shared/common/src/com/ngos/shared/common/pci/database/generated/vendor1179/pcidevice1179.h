// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1179_PCIDEVICE1179_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1179_PCIDEVICE1179_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1179/pcisubdevice11790110.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1179/pcisubdevice11790113.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1179/pcisubdevice11790601.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1179/pcisubdevice1179060a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1179/pcisubdevice1179060f.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1179/pcisubdevice11790d01.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1179: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0102 = 0x0102,
    DEVICE_0103 = 0x0103,
    DEVICE_010E = 0x010E,
    DEVICE_010F = 0x010F,
    DEVICE_0110 = 0x0110,
    DEVICE_0113 = 0x0113,
    DEVICE_0115 = 0x0115,
    DEVICE_011A = 0x011A,
    DEVICE_0404 = 0x0404,
    DEVICE_0406 = 0x0406,
    DEVICE_0407 = 0x0407,
    DEVICE_0601 = 0x0601,
    DEVICE_0602 = 0x0602,
    DEVICE_0603 = 0x0603,
    DEVICE_0604 = 0x0604,
    DEVICE_060A = 0x060A,
    DEVICE_060F = 0x060F,
    DEVICE_0617 = 0x0617,
    DEVICE_0618 = 0x0618,
    DEVICE_0701 = 0x0701,
    DEVICE_0803 = 0x0803,
    DEVICE_0804 = 0x0804,
    DEVICE_0805 = 0x0805,
    DEVICE_0D01 = 0x0D01
};



inline const char8* enumToString(PciDevice1179 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1179::NONE:        return "NONE";
        case PciDevice1179::DEVICE_0102: return "DEVICE_0102";
        case PciDevice1179::DEVICE_0103: return "DEVICE_0103";
        case PciDevice1179::DEVICE_010E: return "DEVICE_010E";
        case PciDevice1179::DEVICE_010F: return "DEVICE_010F";
        case PciDevice1179::DEVICE_0110: return "DEVICE_0110";
        case PciDevice1179::DEVICE_0113: return "DEVICE_0113";
        case PciDevice1179::DEVICE_0115: return "DEVICE_0115";
        case PciDevice1179::DEVICE_011A: return "DEVICE_011A";
        case PciDevice1179::DEVICE_0404: return "DEVICE_0404";
        case PciDevice1179::DEVICE_0406: return "DEVICE_0406";
        case PciDevice1179::DEVICE_0407: return "DEVICE_0407";
        case PciDevice1179::DEVICE_0601: return "DEVICE_0601";
        case PciDevice1179::DEVICE_0602: return "DEVICE_0602";
        case PciDevice1179::DEVICE_0603: return "DEVICE_0603";
        case PciDevice1179::DEVICE_0604: return "DEVICE_0604";
        case PciDevice1179::DEVICE_060A: return "DEVICE_060A";
        case PciDevice1179::DEVICE_060F: return "DEVICE_060F";
        case PciDevice1179::DEVICE_0617: return "DEVICE_0617";
        case PciDevice1179::DEVICE_0618: return "DEVICE_0618";
        case PciDevice1179::DEVICE_0701: return "DEVICE_0701";
        case PciDevice1179::DEVICE_0803: return "DEVICE_0803";
        case PciDevice1179::DEVICE_0804: return "DEVICE_0804";
        case PciDevice1179::DEVICE_0805: return "DEVICE_0805";
        case PciDevice1179::DEVICE_0D01: return "DEVICE_0D01";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1179 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1179 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1179::DEVICE_0102: return "Extended IDE Controller";
        case PciDevice1179::DEVICE_0103: return "EX-IDE Type-B";
        case PciDevice1179::DEVICE_010E: return "PXP04 NVMe SSD";
        case PciDevice1179::DEVICE_010F: return "NVMe Controller";
        case PciDevice1179::DEVICE_0110: return "NVMe SSD Controller Cx5";
        case PciDevice1179::DEVICE_0113: return "BG3 NVMe SSD Controller";
        case PciDevice1179::DEVICE_0115: return "XG4 NVMe SSD Controller";
        case PciDevice1179::DEVICE_011A: return "XG6 NVMe SSD Controller";
        case PciDevice1179::DEVICE_0404: return "DVD Decoder card";
        case PciDevice1179::DEVICE_0406: return "Tecra Video Capture device";
        case PciDevice1179::DEVICE_0407: return "DVD Decoder card (Version 2)";
        case PciDevice1179::DEVICE_0601: return "CPU to PCI bridge";
        case PciDevice1179::DEVICE_0602: return "PCI to ISA bridge";
        case PciDevice1179::DEVICE_0603: return "ToPIC95 PCI to CardBus Bridge for Notebooks";
        case PciDevice1179::DEVICE_0604: return "PCI-Docking Host bridge";
        case PciDevice1179::DEVICE_060A: return "ToPIC95";
        case PciDevice1179::DEVICE_060F: return "ToPIC97";
        case PciDevice1179::DEVICE_0617: return "ToPIC100 PCI to Cardbus Bridge with ZV Support";
        case PciDevice1179::DEVICE_0618: return "CPU to PCI and PCI to ISA bridge";
        case PciDevice1179::DEVICE_0701: return "FIR Port Type-O";
        case PciDevice1179::DEVICE_0803: return "TC6371AF SD Host Controller";
        case PciDevice1179::DEVICE_0804: return "TC6371AF SmartMedia Controller";
        case PciDevice1179::DEVICE_0805: return "SD TypA Controller";
        case PciDevice1179::DEVICE_0D01: return "FIR Port Type-DO";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1179 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1179::DEVICE_0102: return "Unknown device";
        case PciDevice1179::DEVICE_0103: return "Unknown device";
        case PciDevice1179::DEVICE_010E: return "Unknown device";
        case PciDevice1179::DEVICE_010F: return "Unknown device";
        case PciDevice1179::DEVICE_0110: return enumToHumanString((PciSubDevice11790110)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1179::DEVICE_0113: return enumToHumanString((PciSubDevice11790113)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1179::DEVICE_0115: return "Unknown device";
        case PciDevice1179::DEVICE_011A: return "Unknown device";
        case PciDevice1179::DEVICE_0404: return "Unknown device";
        case PciDevice1179::DEVICE_0406: return "Unknown device";
        case PciDevice1179::DEVICE_0407: return "Unknown device";
        case PciDevice1179::DEVICE_0601: return enumToHumanString((PciSubDevice11790601)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1179::DEVICE_0602: return "Unknown device";
        case PciDevice1179::DEVICE_0603: return "Unknown device";
        case PciDevice1179::DEVICE_0604: return "Unknown device";
        case PciDevice1179::DEVICE_060A: return enumToHumanString((PciSubDevice1179060A)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1179::DEVICE_060F: return enumToHumanString((PciSubDevice1179060F)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1179::DEVICE_0617: return "Unknown device";
        case PciDevice1179::DEVICE_0618: return "Unknown device";
        case PciDevice1179::DEVICE_0701: return "Unknown device";
        case PciDevice1179::DEVICE_0803: return "Unknown device";
        case PciDevice1179::DEVICE_0804: return "Unknown device";
        case PciDevice1179::DEVICE_0805: return "Unknown device";
        case PciDevice1179::DEVICE_0D01: return enumToHumanString((PciSubDevice11790D01)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1179_PCIDEVICE1179_H
