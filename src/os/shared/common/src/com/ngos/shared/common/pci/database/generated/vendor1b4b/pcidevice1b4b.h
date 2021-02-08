// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B4B_PCIDEVICE1B4B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B4B_PCIDEVICE1B4B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b4b/pcisubdevice1b4b2241.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b4b/pcisubdevice1b4b9123.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b4b/pcisubdevice1b4b9130.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1b4b/pcisubdevice1b4b9230.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1B4B: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0640 = 0x0640,
    DEVICE_2241 = 0x2241,
    DEVICE_9120 = 0x9120,
    DEVICE_9123 = 0x9123,
    DEVICE_9125 = 0x9125,
    DEVICE_9128 = 0x9128,
    DEVICE_9130 = 0x9130,
    DEVICE_9172 = 0x9172,
    DEVICE_9178 = 0x9178,
    DEVICE_917A = 0x917A,
    DEVICE_9183 = 0x9183,
    DEVICE_9192 = 0x9192,
    DEVICE_91A0 = 0x91A0,
    DEVICE_91A4 = 0x91A4,
    DEVICE_9215 = 0x9215,
    DEVICE_9220 = 0x9220,
    DEVICE_9230 = 0x9230,
    DEVICE_9235 = 0x9235,
    DEVICE_9445 = 0x9445,
    DEVICE_9480 = 0x9480,
    DEVICE_9485 = 0x9485
};



inline const char8* enumToString(PciDevice1B4B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1B4B::NONE:        return "NONE";
        case PciDevice1B4B::DEVICE_0640: return "DEVICE_0640";
        case PciDevice1B4B::DEVICE_2241: return "DEVICE_2241";
        case PciDevice1B4B::DEVICE_9120: return "DEVICE_9120";
        case PciDevice1B4B::DEVICE_9123: return "DEVICE_9123";
        case PciDevice1B4B::DEVICE_9125: return "DEVICE_9125";
        case PciDevice1B4B::DEVICE_9128: return "DEVICE_9128";
        case PciDevice1B4B::DEVICE_9130: return "DEVICE_9130";
        case PciDevice1B4B::DEVICE_9172: return "DEVICE_9172";
        case PciDevice1B4B::DEVICE_9178: return "DEVICE_9178";
        case PciDevice1B4B::DEVICE_917A: return "DEVICE_917A";
        case PciDevice1B4B::DEVICE_9183: return "DEVICE_9183";
        case PciDevice1B4B::DEVICE_9192: return "DEVICE_9192";
        case PciDevice1B4B::DEVICE_91A0: return "DEVICE_91A0";
        case PciDevice1B4B::DEVICE_91A4: return "DEVICE_91A4";
        case PciDevice1B4B::DEVICE_9215: return "DEVICE_9215";
        case PciDevice1B4B::DEVICE_9220: return "DEVICE_9220";
        case PciDevice1B4B::DEVICE_9230: return "DEVICE_9230";
        case PciDevice1B4B::DEVICE_9235: return "DEVICE_9235";
        case PciDevice1B4B::DEVICE_9445: return "DEVICE_9445";
        case PciDevice1B4B::DEVICE_9480: return "DEVICE_9480";
        case PciDevice1B4B::DEVICE_9485: return "DEVICE_9485";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1B4B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1B4B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1B4B::DEVICE_0640: return "88SE9128 SATA III 6Gb/s RAID Controller";
        case PciDevice1B4B::DEVICE_2241: return "88NR2241 Non-Volatile memory controller";
        case PciDevice1B4B::DEVICE_9120: return "88SE9120 SATA 6Gb/s Controller";
        case PciDevice1B4B::DEVICE_9123: return "88SE9123 PCIe SATA 6.0 Gb/s controller";
        case PciDevice1B4B::DEVICE_9125: return "88SE9125 PCIe SATA 6.0 Gb/s controller";
        case PciDevice1B4B::DEVICE_9128: return "88SE9128 PCIe SATA 6 Gb/s RAID controller";
        case PciDevice1B4B::DEVICE_9130: return "88SE9128 PCIe SATA 6 Gb/s RAID controller with HyperDuo";
        case PciDevice1B4B::DEVICE_9172: return "88SE9172 SATA 6Gb/s Controller";
        case PciDevice1B4B::DEVICE_9178: return "88SE9170 PCIe SATA 6Gb/s Controller";
        case PciDevice1B4B::DEVICE_917A: return "88SE9172 SATA III 6Gb/s RAID Controller";
        case PciDevice1B4B::DEVICE_9183: return "88SS9183 PCIe SSD Controller";
        case PciDevice1B4B::DEVICE_9192: return "88SE9172 SATA III 6Gb/s RAID Controller";
        case PciDevice1B4B::DEVICE_91A0: return "88SE912x SATA 6Gb/s Controller [IDE mode]";
        case PciDevice1B4B::DEVICE_91A4: return "88SE912x IDE Controller";
        case PciDevice1B4B::DEVICE_9215: return "88SE9215 PCIe 2.0 x1 4-port SATA 6 Gb/s Controller";
        case PciDevice1B4B::DEVICE_9220: return "88SE9220 PCIe 2.0 x2 2-port SATA 6 Gb/s RAID Controller";
        case PciDevice1B4B::DEVICE_9230: return "88SE9230 PCIe 2.0 x2 4-port SATA 6 Gb/s RAID Controller";
        case PciDevice1B4B::DEVICE_9235: return "88SE9235 PCIe 2.0 x2 4-port SATA 6 Gb/s Controller";
        case PciDevice1B4B::DEVICE_9445: return "88SE9445 PCIe 2.0 x4 4-Port SAS/SATA 6 Gbps RAID Controller";
        case PciDevice1B4B::DEVICE_9480: return "88SE9480 SAS/SATA 6Gb/s RAID controller";
        case PciDevice1B4B::DEVICE_9485: return "88SE9485 SAS/SATA 6Gb/s controller";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1B4B device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1B4B::DEVICE_0640: return "Unknown device";
        case PciDevice1B4B::DEVICE_2241: return enumToHumanString((PciSubDevice1B4B2241)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1B4B::DEVICE_9120: return "Unknown device";
        case PciDevice1B4B::DEVICE_9123: return enumToHumanString((PciSubDevice1B4B9123)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1B4B::DEVICE_9125: return "Unknown device";
        case PciDevice1B4B::DEVICE_9128: return "Unknown device";
        case PciDevice1B4B::DEVICE_9130: return enumToHumanString((PciSubDevice1B4B9130)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1B4B::DEVICE_9172: return "Unknown device";
        case PciDevice1B4B::DEVICE_9178: return "Unknown device";
        case PciDevice1B4B::DEVICE_917A: return "Unknown device";
        case PciDevice1B4B::DEVICE_9183: return "Unknown device";
        case PciDevice1B4B::DEVICE_9192: return "Unknown device";
        case PciDevice1B4B::DEVICE_91A0: return "Unknown device";
        case PciDevice1B4B::DEVICE_91A4: return "Unknown device";
        case PciDevice1B4B::DEVICE_9215: return "Unknown device";
        case PciDevice1B4B::DEVICE_9220: return "Unknown device";
        case PciDevice1B4B::DEVICE_9230: return enumToHumanString((PciSubDevice1B4B9230)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1B4B::DEVICE_9235: return "Unknown device";
        case PciDevice1B4B::DEVICE_9445: return "Unknown device";
        case PciDevice1B4B::DEVICE_9480: return "Unknown device";
        case PciDevice1B4B::DEVICE_9485: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B4B_PCIDEVICE1B4B_H
