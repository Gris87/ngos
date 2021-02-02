// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCIDEVICE105A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCIDEVICE105A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor105a/pcisubdevice105a0d30.h>
#include <com/ngos/shared/common/pci/database/generated/vendor105a/pcisubdevice105a0d38.h>
#include <com/ngos/shared/common/pci/database/generated/vendor105a/pcisubdevice105a3319.h>
#include <com/ngos/shared/common/pci/database/generated/vendor105a/pcisubdevice105a3373.h>
#include <com/ngos/shared/common/pci/database/generated/vendor105a/pcisubdevice105a3376.h>
#include <com/ngos/shared/common/pci/database/generated/vendor105a/pcisubdevice105a4d30.h>
#include <com/ngos/shared/common/pci/database/generated/vendor105a/pcisubdevice105a4d33.h>
#include <com/ngos/shared/common/pci/database/generated/vendor105a/pcisubdevice105a4d38.h>
#include <com/ngos/shared/common/pci/database/generated/vendor105a/pcisubdevice105a4d68.h>
#include <com/ngos/shared/common/pci/database/generated/vendor105a/pcisubdevice105a4d69.h>
#include <com/ngos/shared/common/pci/database/generated/vendor105a/pcisubdevice105a5275.h>
#include <com/ngos/shared/common/pci/database/generated/vendor105a/pcisubdevice105a6268.h>
#include <com/ngos/shared/common/pci/database/generated/vendor105a/pcisubdevice105a6269.h>
#include <com/ngos/shared/common/pci/database/generated/vendor105a/pcisubdevice105a8650.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice105A: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0D30 = 0x0D30,
    DEVICE_0D38 = 0x0D38,
    DEVICE_1275 = 0x1275,
    DEVICE_3318 = 0x3318,
    DEVICE_3319 = 0x3319,
    DEVICE_3371 = 0x3371,
    DEVICE_3373 = 0x3373,
    DEVICE_3375 = 0x3375,
    DEVICE_3376 = 0x3376,
    DEVICE_3515 = 0x3515,
    DEVICE_3519 = 0x3519,
    DEVICE_3570 = 0x3570,
    DEVICE_3571 = 0x3571,
    DEVICE_3574 = 0x3574,
    DEVICE_3577 = 0x3577,
    DEVICE_3D17 = 0x3D17,
    DEVICE_3D18 = 0x3D18,
    DEVICE_3D73 = 0x3D73,
    DEVICE_3D75 = 0x3D75,
    DEVICE_3F20 = 0x3F20,
    DEVICE_4302 = 0x4302,
    DEVICE_4D30 = 0x4D30,
    DEVICE_4D33 = 0x4D33,
    DEVICE_4D38 = 0x4D38,
    DEVICE_4D68 = 0x4D68,
    DEVICE_4D69 = 0x4D69,
    DEVICE_5275 = 0x5275,
    DEVICE_5300 = 0x5300,
    DEVICE_6268 = 0x6268,
    DEVICE_6269 = 0x6269,
    DEVICE_6300 = 0x6300,
    DEVICE_6621 = 0x6621,
    DEVICE_6622 = 0x6622,
    DEVICE_6624 = 0x6624,
    DEVICE_6626 = 0x6626,
    DEVICE_6629 = 0x6629,
    DEVICE_7275 = 0x7275,
    DEVICE_8002 = 0x8002,
    DEVICE_8350 = 0x8350,
    DEVICE_8650 = 0x8650,
    DEVICE_8760 = 0x8760,
    DEVICE_C350 = 0xC350,
    DEVICE_E350 = 0xE350
};



inline const char8* enumToString(PciDevice105A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice105A::NONE:        return "NONE";
        case PciDevice105A::DEVICE_0D30: return "DEVICE_0D30";
        case PciDevice105A::DEVICE_0D38: return "DEVICE_0D38";
        case PciDevice105A::DEVICE_1275: return "DEVICE_1275";
        case PciDevice105A::DEVICE_3318: return "DEVICE_3318";
        case PciDevice105A::DEVICE_3319: return "DEVICE_3319";
        case PciDevice105A::DEVICE_3371: return "DEVICE_3371";
        case PciDevice105A::DEVICE_3373: return "DEVICE_3373";
        case PciDevice105A::DEVICE_3375: return "DEVICE_3375";
        case PciDevice105A::DEVICE_3376: return "DEVICE_3376";
        case PciDevice105A::DEVICE_3515: return "DEVICE_3515";
        case PciDevice105A::DEVICE_3519: return "DEVICE_3519";
        case PciDevice105A::DEVICE_3570: return "DEVICE_3570";
        case PciDevice105A::DEVICE_3571: return "DEVICE_3571";
        case PciDevice105A::DEVICE_3574: return "DEVICE_3574";
        case PciDevice105A::DEVICE_3577: return "DEVICE_3577";
        case PciDevice105A::DEVICE_3D17: return "DEVICE_3D17";
        case PciDevice105A::DEVICE_3D18: return "DEVICE_3D18";
        case PciDevice105A::DEVICE_3D73: return "DEVICE_3D73";
        case PciDevice105A::DEVICE_3D75: return "DEVICE_3D75";
        case PciDevice105A::DEVICE_3F20: return "DEVICE_3F20";
        case PciDevice105A::DEVICE_4302: return "DEVICE_4302";
        case PciDevice105A::DEVICE_4D30: return "DEVICE_4D30";
        case PciDevice105A::DEVICE_4D33: return "DEVICE_4D33";
        case PciDevice105A::DEVICE_4D38: return "DEVICE_4D38";
        case PciDevice105A::DEVICE_4D68: return "DEVICE_4D68";
        case PciDevice105A::DEVICE_4D69: return "DEVICE_4D69";
        case PciDevice105A::DEVICE_5275: return "DEVICE_5275";
        case PciDevice105A::DEVICE_5300: return "DEVICE_5300";
        case PciDevice105A::DEVICE_6268: return "DEVICE_6268";
        case PciDevice105A::DEVICE_6269: return "DEVICE_6269";
        case PciDevice105A::DEVICE_6300: return "DEVICE_6300";
        case PciDevice105A::DEVICE_6621: return "DEVICE_6621";
        case PciDevice105A::DEVICE_6622: return "DEVICE_6622";
        case PciDevice105A::DEVICE_6624: return "DEVICE_6624";
        case PciDevice105A::DEVICE_6626: return "DEVICE_6626";
        case PciDevice105A::DEVICE_6629: return "DEVICE_6629";
        case PciDevice105A::DEVICE_7275: return "DEVICE_7275";
        case PciDevice105A::DEVICE_8002: return "DEVICE_8002";
        case PciDevice105A::DEVICE_8350: return "DEVICE_8350";
        case PciDevice105A::DEVICE_8650: return "DEVICE_8650";
        case PciDevice105A::DEVICE_8760: return "DEVICE_8760";
        case PciDevice105A::DEVICE_C350: return "DEVICE_C350";
        case PciDevice105A::DEVICE_E350: return "DEVICE_E350";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice105A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice105A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice105A::DEVICE_0D30: return "PDC20265 (FastTrak100 Lite/Ultra100)";
        case PciDevice105A::DEVICE_0D38: return "20263";
        case PciDevice105A::DEVICE_1275: return "20275";
        case PciDevice105A::DEVICE_3318: return "PDC20318 (SATA150 TX4)";
        case PciDevice105A::DEVICE_3319: return "PDC20319 (FastTrak S150 TX4)";
        case PciDevice105A::DEVICE_3371: return "PDC20371 (FastTrak S150 TX2plus)";
        case PciDevice105A::DEVICE_3373: return "PDC20378 (FastTrak 378/SATA 378)";
        case PciDevice105A::DEVICE_3375: return "PDC20375 (SATA150 TX2plus)";
        case PciDevice105A::DEVICE_3376: return "PDC20376 (FastTrak 376)";
        case PciDevice105A::DEVICE_3515: return "PDC40719 [FastTrak TX4300/TX4310]";
        case PciDevice105A::DEVICE_3519: return "PDC40519 (FastTrak TX4200)";
        case PciDevice105A::DEVICE_3570: return "PDC20771 [FastTrak TX2300]";
        case PciDevice105A::DEVICE_3571: return "PDC20571 (FastTrak TX2200)";
        case PciDevice105A::DEVICE_3574: return "PDC20579 SATAII 150 IDE Controller";
        case PciDevice105A::DEVICE_3577: return "PDC40779 (SATA 300 779)";
        case PciDevice105A::DEVICE_3D17: return "PDC40718 (SATA 300 TX4)";
        case PciDevice105A::DEVICE_3D18: return "PDC20518/PDC40518 (SATAII 150 TX4)";
        case PciDevice105A::DEVICE_3D73: return "PDC40775 (SATA 300 TX2plus)";
        case PciDevice105A::DEVICE_3D75: return "PDC20575 (SATAII150 TX2plus)";
        case PciDevice105A::DEVICE_3F20: return "PDC42819 [FastTrak TX2650/TX4650]";
        case PciDevice105A::DEVICE_4302: return "80333 [SuperTrak EX4350]";
        case PciDevice105A::DEVICE_4D30: return "PDC20267 (FastTrak100/Ultra100)";
        case PciDevice105A::DEVICE_4D33: return "20246";
        case PciDevice105A::DEVICE_4D38: return "PDC20262 (FastTrak66/Ultra66)";
        case PciDevice105A::DEVICE_4D68: return "PDC20268 [Ultra100 TX2]";
        case PciDevice105A::DEVICE_4D69: return "20269";
        case PciDevice105A::DEVICE_5275: return "PDC20276 (MBFastTrak133 Lite)";
        case PciDevice105A::DEVICE_5300: return "DC5300";
        case PciDevice105A::DEVICE_6268: return "PDC20270 (FastTrak100 LP/TX2/TX4)";
        case PciDevice105A::DEVICE_6269: return "PDC20271 (FastTrak TX2000)";
        case PciDevice105A::DEVICE_6300: return "PDC81731 [FastTrak SX8300]";
        case PciDevice105A::DEVICE_6621: return "PDC20621 (FastTrak S150 SX4/FastTrak SX4000 lite)";
        case PciDevice105A::DEVICE_6622: return "PDC20621 [SATA150 SX4] 4 Channel IDE RAID Controller";
        case PciDevice105A::DEVICE_6624: return "PDC20621 [FastTrak SX4100]";
        case PciDevice105A::DEVICE_6626: return "PDC20618 (Ultra 618)";
        case PciDevice105A::DEVICE_6629: return "PDC20619 (FastTrak TX4000)";
        case PciDevice105A::DEVICE_7275: return "PDC20277 (SBFastTrak133 Lite)";
        case PciDevice105A::DEVICE_8002: return "SATAII150 SX8";
        case PciDevice105A::DEVICE_8350: return "80333 [SuperTrak EX8350/EX16350], 80331 [SuperTrak EX8300/EX16300]";
        case PciDevice105A::DEVICE_8650: return "81384 [SuperTrak EX SAS and SATA RAID Controller]";
        case PciDevice105A::DEVICE_8760: return "PM8010 [SuperTrak EX SAS and SATA 6G RAID Controller]";
        case PciDevice105A::DEVICE_C350: return "80333 [SuperTrak EX12350]";
        case PciDevice105A::DEVICE_E350: return "80333 [SuperTrak EX24350]";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice105A device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice105A::DEVICE_0D30: return enumToHumanString((PciSubDevice105A0D30)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice105A::DEVICE_0D38: return enumToHumanString((PciSubDevice105A0D38)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice105A::DEVICE_1275: return "Unknown device";
        case PciDevice105A::DEVICE_3318: return "Unknown device";
        case PciDevice105A::DEVICE_3319: return enumToHumanString((PciSubDevice105A3319)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice105A::DEVICE_3371: return "Unknown device";
        case PciDevice105A::DEVICE_3373: return enumToHumanString((PciSubDevice105A3373)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice105A::DEVICE_3375: return "Unknown device";
        case PciDevice105A::DEVICE_3376: return enumToHumanString((PciSubDevice105A3376)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice105A::DEVICE_3515: return "Unknown device";
        case PciDevice105A::DEVICE_3519: return "Unknown device";
        case PciDevice105A::DEVICE_3570: return "Unknown device";
        case PciDevice105A::DEVICE_3571: return "Unknown device";
        case PciDevice105A::DEVICE_3574: return "Unknown device";
        case PciDevice105A::DEVICE_3577: return "Unknown device";
        case PciDevice105A::DEVICE_3D17: return "Unknown device";
        case PciDevice105A::DEVICE_3D18: return "Unknown device";
        case PciDevice105A::DEVICE_3D73: return "Unknown device";
        case PciDevice105A::DEVICE_3D75: return "Unknown device";
        case PciDevice105A::DEVICE_3F20: return "Unknown device";
        case PciDevice105A::DEVICE_4302: return "Unknown device";
        case PciDevice105A::DEVICE_4D30: return enumToHumanString((PciSubDevice105A4D30)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice105A::DEVICE_4D33: return enumToHumanString((PciSubDevice105A4D33)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice105A::DEVICE_4D38: return enumToHumanString((PciSubDevice105A4D38)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice105A::DEVICE_4D68: return enumToHumanString((PciSubDevice105A4D68)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice105A::DEVICE_4D69: return enumToHumanString((PciSubDevice105A4D69)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice105A::DEVICE_5275: return enumToHumanString((PciSubDevice105A5275)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice105A::DEVICE_5300: return "Unknown device";
        case PciDevice105A::DEVICE_6268: return enumToHumanString((PciSubDevice105A6268)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice105A::DEVICE_6269: return enumToHumanString((PciSubDevice105A6269)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice105A::DEVICE_6300: return "Unknown device";
        case PciDevice105A::DEVICE_6621: return "Unknown device";
        case PciDevice105A::DEVICE_6622: return "Unknown device";
        case PciDevice105A::DEVICE_6624: return "Unknown device";
        case PciDevice105A::DEVICE_6626: return "Unknown device";
        case PciDevice105A::DEVICE_6629: return "Unknown device";
        case PciDevice105A::DEVICE_7275: return "Unknown device";
        case PciDevice105A::DEVICE_8002: return "Unknown device";
        case PciDevice105A::DEVICE_8350: return "Unknown device";
        case PciDevice105A::DEVICE_8650: return enumToHumanString((PciSubDevice105A8650)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice105A::DEVICE_8760: return "Unknown device";
        case PciDevice105A::DEVICE_C350: return "Unknown device";
        case PciDevice105A::DEVICE_E350: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR105A_PCIDEVICE105A_H
