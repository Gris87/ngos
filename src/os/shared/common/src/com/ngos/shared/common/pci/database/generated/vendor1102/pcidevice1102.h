// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCIDEVICE1102_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCIDEVICE1102_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1102/pcisubdevice11020002.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1102/pcisubdevice11020003.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1102/pcisubdevice11020004.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1102/pcisubdevice11020005.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1102/pcisubdevice11020006.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1102/pcisubdevice11020007.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1102/pcisubdevice11020008.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1102/pcisubdevice11020009.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1102/pcisubdevice1102000b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1102/pcisubdevice11020012.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1102/pcisubdevice11024001.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1102/pcisubdevice11027002.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1102/pcisubdevice11027003.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1102/pcisubdevice11027005.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1102/pcisubdevice11028938.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1102: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0005 = 0x0005,
    DEVICE_0006 = 0x0006,
    DEVICE_0007 = 0x0007,
    DEVICE_0008 = 0x0008,
    DEVICE_0009 = 0x0009,
    DEVICE_000B = 0x000B,
    DEVICE_0012 = 0x0012,
    DEVICE_4001 = 0x4001,
    DEVICE_7002 = 0x7002,
    DEVICE_7003 = 0x7003,
    DEVICE_7004 = 0x7004,
    DEVICE_7005 = 0x7005,
    DEVICE_7006 = 0x7006,
    DEVICE_8938 = 0x8938
};



inline const char8* enumToString(PciDevice1102 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1102::NONE:        return "NONE";
        case PciDevice1102::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1102::DEVICE_0003: return "DEVICE_0003";
        case PciDevice1102::DEVICE_0004: return "DEVICE_0004";
        case PciDevice1102::DEVICE_0005: return "DEVICE_0005";
        case PciDevice1102::DEVICE_0006: return "DEVICE_0006";
        case PciDevice1102::DEVICE_0007: return "DEVICE_0007";
        case PciDevice1102::DEVICE_0008: return "DEVICE_0008";
        case PciDevice1102::DEVICE_0009: return "DEVICE_0009";
        case PciDevice1102::DEVICE_000B: return "DEVICE_000B";
        case PciDevice1102::DEVICE_0012: return "DEVICE_0012";
        case PciDevice1102::DEVICE_4001: return "DEVICE_4001";
        case PciDevice1102::DEVICE_7002: return "DEVICE_7002";
        case PciDevice1102::DEVICE_7003: return "DEVICE_7003";
        case PciDevice1102::DEVICE_7004: return "DEVICE_7004";
        case PciDevice1102::DEVICE_7005: return "DEVICE_7005";
        case PciDevice1102::DEVICE_7006: return "DEVICE_7006";
        case PciDevice1102::DEVICE_8938: return "DEVICE_8938";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1102 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1102 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1102::DEVICE_0002: return "EMU10k1 [Sound Blaster Live! Series]";
        case PciDevice1102::DEVICE_0003: return "SB AWE64(D)";
        case PciDevice1102::DEVICE_0004: return "EMU10k2/CA0100/CA0102/CA10200 [Sound Blaster Audigy Series]";
        case PciDevice1102::DEVICE_0005: return "EMU20k1 [Sound Blaster X-Fi Series]";
        case PciDevice1102::DEVICE_0006: return "EMU10k1X / CA0103 [SB Live! OEM / SB 5.1 / Ectiva 5.1]";
        case PciDevice1102::DEVICE_0007: return "CA0106/CA0111 [SB Live!/Audigy/X-Fi Series]";
        case PciDevice1102::DEVICE_0008: return "CA0108/CA10300 [Sound Blaster Audigy Series]";
        case PciDevice1102::DEVICE_0009: return "CA0110 [Sound Blaster X-Fi Xtreme Audio]";
        case PciDevice1102::DEVICE_000B: return "EMU20k2 [Sound Blaster X-Fi Titanium Series]";
        case PciDevice1102::DEVICE_0012: return "Sound Core3D [Sound Blaster Recon3D / Z-Series]";
        case PciDevice1102::DEVICE_4001: return "SB Audigy FireWire Port";
        case PciDevice1102::DEVICE_7002: return "SB Live! Game Port";
        case PciDevice1102::DEVICE_7003: return "SB Audigy Game Port";
        case PciDevice1102::DEVICE_7004: return "[SB Live! Value] Input device controller";
        case PciDevice1102::DEVICE_7005: return "SB Audigy LS Game Port";
        case PciDevice1102::DEVICE_7006: return "[SB X-Fi Xtreme Audio] CA0110-IBG PCIe to PCI Bridge";
        case PciDevice1102::DEVICE_8938: return "Ectiva EV1938";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1102 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1102::DEVICE_0002: return enumToHumanString((PciSubDevice11020002)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1102::DEVICE_0003: return enumToHumanString((PciSubDevice11020003)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1102::DEVICE_0004: return enumToHumanString((PciSubDevice11020004)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1102::DEVICE_0005: return enumToHumanString((PciSubDevice11020005)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1102::DEVICE_0006: return enumToHumanString((PciSubDevice11020006)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1102::DEVICE_0007: return enumToHumanString((PciSubDevice11020007)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1102::DEVICE_0008: return enumToHumanString((PciSubDevice11020008)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1102::DEVICE_0009: return enumToHumanString((PciSubDevice11020009)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1102::DEVICE_000B: return enumToHumanString((PciSubDevice1102000B)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1102::DEVICE_0012: return enumToHumanString((PciSubDevice11020012)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1102::DEVICE_4001: return enumToHumanString((PciSubDevice11024001)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1102::DEVICE_7002: return enumToHumanString((PciSubDevice11027002)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1102::DEVICE_7003: return enumToHumanString((PciSubDevice11027003)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1102::DEVICE_7004: return "Unknown device";
        case PciDevice1102::DEVICE_7005: return enumToHumanString((PciSubDevice11027005)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1102::DEVICE_7006: return "Unknown device";
        case PciDevice1102::DEVICE_8938: return enumToHumanString((PciSubDevice11028938)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCIDEVICE1102_H
