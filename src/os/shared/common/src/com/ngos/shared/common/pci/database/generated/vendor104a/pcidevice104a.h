// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104A_PCIDEVICE104A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104A_PCIDEVICE104A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor104a/pcisubdevice104a0010.h>
#include <com/ngos/shared/common/pci/database/generated/vendor104a/pcisubdevice104a0500.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice104A: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
    DEVICE_0008 = 0x0008,
    DEVICE_0009 = 0x0009,
    DEVICE_0010 = 0x0010,
    DEVICE_0201 = 0x0201,
    DEVICE_0209 = 0x0209,
    DEVICE_020A = 0x020A,
    DEVICE_020B = 0x020B,
    DEVICE_0210 = 0x0210,
    DEVICE_021A = 0x021A,
    DEVICE_021B = 0x021B,
    DEVICE_0220 = 0x0220,
    DEVICE_0228 = 0x0228,
    DEVICE_0229 = 0x0229,
    DEVICE_0230 = 0x0230,
    DEVICE_0238 = 0x0238,
    DEVICE_0500 = 0x0500,
    DEVICE_0564 = 0x0564,
    DEVICE_0981 = 0x0981,
    DEVICE_1746 = 0x1746,
    DEVICE_2774 = 0x2774,
    DEVICE_3520 = 0x3520,
    DEVICE_55CC = 0x55CC
};



inline const char8* enumToString(PciDevice104A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice104A::DEVICE_0000: return "DEVICE_0000";
        case PciDevice104A::DEVICE_0008: return "DEVICE_0008";
        case PciDevice104A::DEVICE_0009: return "DEVICE_0009";
        case PciDevice104A::DEVICE_0010: return "DEVICE_0010";
        case PciDevice104A::DEVICE_0201: return "DEVICE_0201";
        case PciDevice104A::DEVICE_0209: return "DEVICE_0209";
        case PciDevice104A::DEVICE_020A: return "DEVICE_020A";
        case PciDevice104A::DEVICE_020B: return "DEVICE_020B";
        case PciDevice104A::DEVICE_0210: return "DEVICE_0210";
        case PciDevice104A::DEVICE_021A: return "DEVICE_021A";
        case PciDevice104A::DEVICE_021B: return "DEVICE_021B";
        case PciDevice104A::DEVICE_0220: return "DEVICE_0220";
        case PciDevice104A::DEVICE_0228: return "DEVICE_0228";
        case PciDevice104A::DEVICE_0229: return "DEVICE_0229";
        case PciDevice104A::DEVICE_0230: return "DEVICE_0230";
        case PciDevice104A::DEVICE_0238: return "DEVICE_0238";
        case PciDevice104A::DEVICE_0500: return "DEVICE_0500";
        case PciDevice104A::DEVICE_0564: return "DEVICE_0564";
        case PciDevice104A::DEVICE_0981: return "DEVICE_0981";
        case PciDevice104A::DEVICE_1746: return "DEVICE_1746";
        case PciDevice104A::DEVICE_2774: return "DEVICE_2774";
        case PciDevice104A::DEVICE_3520: return "DEVICE_3520";
        case PciDevice104A::DEVICE_55CC: return "DEVICE_55CC";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice104A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice104A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice104A::DEVICE_0000: return "STLS2F Host Bridge";
        case PciDevice104A::DEVICE_0008: return "STG 2000X";
        case PciDevice104A::DEVICE_0009: return "STG 1764X";
        case PciDevice104A::DEVICE_0010: return "STG4000 [3D Prophet Kyro Series]";
        case PciDevice104A::DEVICE_0201: return "STPC Vega Northbridge";
        case PciDevice104A::DEVICE_0209: return "STPC Consumer/Industrial North- and Southbridge";
        case PciDevice104A::DEVICE_020A: return "STPC Atlas/ConsumerS/Consumer IIA Northbridge";
        case PciDevice104A::DEVICE_020B: return "STPC Consumer II ISA Bridge";
        case PciDevice104A::DEVICE_0210: return "STPC Atlas ISA Bridge";
        case PciDevice104A::DEVICE_021A: return "STPC Consumer S Southbridge";
        case PciDevice104A::DEVICE_021B: return "STPC Consumer IIA Southbridge";
        case PciDevice104A::DEVICE_0220: return "STPC Industrial PCI to PCCard bridge";
        case PciDevice104A::DEVICE_0228: return "STPC Atlas IDE";
        case PciDevice104A::DEVICE_0229: return "STPC Vega IDE";
        case PciDevice104A::DEVICE_0230: return "STPC Atlas/Vega OHCI USB Controller";
        case PciDevice104A::DEVICE_0238: return "STPC Vega LAN";
        case PciDevice104A::DEVICE_0500: return "ST70137 [Unicorn] ADSL DMT Transceiver";
        case PciDevice104A::DEVICE_0564: return "STPC Client Northbridge";
        case PciDevice104A::DEVICE_0981: return "21x4x DEC-Tulip compatible 10/100 Ethernet";
        case PciDevice104A::DEVICE_1746: return "STG 1764X";
        case PciDevice104A::DEVICE_2774: return "21x4x DEC-Tulip compatible 10/100 Ethernet";
        case PciDevice104A::DEVICE_3520: return "MPEG-II decoder card";
        case PciDevice104A::DEVICE_55CC: return "STPC Client Southbridge";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice104A device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice104A::DEVICE_0000: return "Unknown device";
        case PciDevice104A::DEVICE_0008: return "Unknown device";
        case PciDevice104A::DEVICE_0009: return "Unknown device";
        case PciDevice104A::DEVICE_0010: return enumToHumanString((PciSubDevice104A0010)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice104A::DEVICE_0201: return "Unknown device";
        case PciDevice104A::DEVICE_0209: return "Unknown device";
        case PciDevice104A::DEVICE_020A: return "Unknown device";
        case PciDevice104A::DEVICE_020B: return "Unknown device";
        case PciDevice104A::DEVICE_0210: return "Unknown device";
        case PciDevice104A::DEVICE_021A: return "Unknown device";
        case PciDevice104A::DEVICE_021B: return "Unknown device";
        case PciDevice104A::DEVICE_0220: return "Unknown device";
        case PciDevice104A::DEVICE_0228: return "Unknown device";
        case PciDevice104A::DEVICE_0229: return "Unknown device";
        case PciDevice104A::DEVICE_0230: return "Unknown device";
        case PciDevice104A::DEVICE_0238: return "Unknown device";
        case PciDevice104A::DEVICE_0500: return enumToHumanString((PciSubDevice104A0500)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice104A::DEVICE_0564: return "Unknown device";
        case PciDevice104A::DEVICE_0981: return "Unknown device";
        case PciDevice104A::DEVICE_1746: return "Unknown device";
        case PciDevice104A::DEVICE_2774: return "Unknown device";
        case PciDevice104A::DEVICE_3520: return "Unknown device";
        case PciDevice104A::DEVICE_55CC: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104A_PCIDEVICE104A_H
