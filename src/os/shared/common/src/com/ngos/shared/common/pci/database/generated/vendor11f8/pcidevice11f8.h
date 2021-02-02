// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11F8_PCIDEVICE11F8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11F8_PCIDEVICE11F8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor11f8/pcisubdevice11f88032.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11F8: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_5220 = 0x5220,
    DEVICE_7364 = 0x7364,
    DEVICE_7375 = 0x7375,
    DEVICE_7384 = 0x7384,
    DEVICE_8000 = 0x8000,
    DEVICE_8009 = 0x8009,
    DEVICE_8018 = 0x8018,
    DEVICE_8032 = 0x8032,
    DEVICE_8053 = 0x8053,
    DEVICE_8054 = 0x8054,
    DEVICE_8055 = 0x8055,
    DEVICE_8056 = 0x8056,
    DEVICE_8060 = 0x8060,
    DEVICE_8063 = 0x8063,
    DEVICE_8070 = 0x8070,
    DEVICE_8071 = 0x8071,
    DEVICE_8072 = 0x8072,
    DEVICE_8073 = 0x8073,
    DEVICE_8531 = 0x8531,
    DEVICE_8546 = 0x8546
};



inline const char8* enumToString(PciDevice11F8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11F8::NONE:        return "NONE";
        case PciDevice11F8::DEVICE_5220: return "DEVICE_5220";
        case PciDevice11F8::DEVICE_7364: return "DEVICE_7364";
        case PciDevice11F8::DEVICE_7375: return "DEVICE_7375";
        case PciDevice11F8::DEVICE_7384: return "DEVICE_7384";
        case PciDevice11F8::DEVICE_8000: return "DEVICE_8000";
        case PciDevice11F8::DEVICE_8009: return "DEVICE_8009";
        case PciDevice11F8::DEVICE_8018: return "DEVICE_8018";
        case PciDevice11F8::DEVICE_8032: return "DEVICE_8032";
        case PciDevice11F8::DEVICE_8053: return "DEVICE_8053";
        case PciDevice11F8::DEVICE_8054: return "DEVICE_8054";
        case PciDevice11F8::DEVICE_8055: return "DEVICE_8055";
        case PciDevice11F8::DEVICE_8056: return "DEVICE_8056";
        case PciDevice11F8::DEVICE_8060: return "DEVICE_8060";
        case PciDevice11F8::DEVICE_8063: return "DEVICE_8063";
        case PciDevice11F8::DEVICE_8070: return "DEVICE_8070";
        case PciDevice11F8::DEVICE_8071: return "DEVICE_8071";
        case PciDevice11F8::DEVICE_8072: return "DEVICE_8072";
        case PciDevice11F8::DEVICE_8073: return "DEVICE_8073";
        case PciDevice11F8::DEVICE_8531: return "DEVICE_8531";
        case PciDevice11F8::DEVICE_8546: return "DEVICE_8546";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11F8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice11F8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11F8::DEVICE_5220: return "BR522x [PMC-Sierra maxRAID SAS Controller]";
        case PciDevice11F8::DEVICE_7364: return "PM7364 [FREEDM - 32 Frame Engine & Datalink Mgr]";
        case PciDevice11F8::DEVICE_7375: return "PM7375 [LASAR-155 ATM SAR]";
        case PciDevice11F8::DEVICE_7384: return "PM7384 [FREEDM - 84P672 Frm Engine & Datalink Mgr]";
        case PciDevice11F8::DEVICE_8000: return "PM8000 [SPC - SAS Protocol Controller]";
        case PciDevice11F8::DEVICE_8009: return "PM8009 SPCve 8x6G";
        case PciDevice11F8::DEVICE_8018: return "PM8018 Adaptec SAS Adaptor ASA-70165H PCIe Gen3 x8 6 Gbps 16-lane 4x SFF-8644";
        case PciDevice11F8::DEVICE_8032: return "PM8032 Tachyon QE8";
        case PciDevice11F8::DEVICE_8053: return "PM8053 SXP 12G 24-port SAS/SATA expander";
        case PciDevice11F8::DEVICE_8054: return "PM8054 SXP 12G 36-port SAS/SATA expander";
        case PciDevice11F8::DEVICE_8055: return "PM8055 SXP 12G 48-port SAS/SATA expander";
        case PciDevice11F8::DEVICE_8056: return "PM8056 SXP 12G 68-port SAS/SATA expander";
        case PciDevice11F8::DEVICE_8060: return "PM8060 SRCv 12G eight-port SAS/SATA RoC";
        case PciDevice11F8::DEVICE_8063: return "PM8063 SRCv 12G 16-port SAS/SATA RoC";
        case PciDevice11F8::DEVICE_8070: return "PM8070 Tachyon SPCv 12G eight-port SAS/SATA controller";
        case PciDevice11F8::DEVICE_8071: return "PM8071 Tachyon SPCve 12G eight-port SAS/SATA controller";
        case PciDevice11F8::DEVICE_8072: return "PM8072 Tachyon SPCv 12G 16-port SAS/SATA controller";
        case PciDevice11F8::DEVICE_8073: return "PM8073 Tachyon SPCve 12G 16-port SAS/SATA controller";
        case PciDevice11F8::DEVICE_8531: return "PM8531 PFX 24xG3 Fanout PCIe Switches";
        case PciDevice11F8::DEVICE_8546: return "PM8546 B-FEIP PSX 96xG3 PCIe Storage Switch";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice11F8 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11F8::DEVICE_5220: return "Unknown device";
        case PciDevice11F8::DEVICE_7364: return "Unknown device";
        case PciDevice11F8::DEVICE_7375: return "Unknown device";
        case PciDevice11F8::DEVICE_7384: return "Unknown device";
        case PciDevice11F8::DEVICE_8000: return "Unknown device";
        case PciDevice11F8::DEVICE_8009: return "Unknown device";
        case PciDevice11F8::DEVICE_8018: return "Unknown device";
        case PciDevice11F8::DEVICE_8032: return enumToHumanString((PciSubDevice11F88032)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice11F8::DEVICE_8053: return "Unknown device";
        case PciDevice11F8::DEVICE_8054: return "Unknown device";
        case PciDevice11F8::DEVICE_8055: return "Unknown device";
        case PciDevice11F8::DEVICE_8056: return "Unknown device";
        case PciDevice11F8::DEVICE_8060: return "Unknown device";
        case PciDevice11F8::DEVICE_8063: return "Unknown device";
        case PciDevice11F8::DEVICE_8070: return "Unknown device";
        case PciDevice11F8::DEVICE_8071: return "Unknown device";
        case PciDevice11F8::DEVICE_8072: return "Unknown device";
        case PciDevice11F8::DEVICE_8073: return "Unknown device";
        case PciDevice11F8::DEVICE_8531: return "Unknown device";
        case PciDevice11F8::DEVICE_8546: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11F8_PCIDEVICE11F8_H
