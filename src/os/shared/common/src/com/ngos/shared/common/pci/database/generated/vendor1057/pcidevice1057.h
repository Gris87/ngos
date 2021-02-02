// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1057_PCIDEVICE1057_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1057_PCIDEVICE1057_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1057/pcisubdevice10571801.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1057/pcisubdevice10573410.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1057/pcisubdevice10575600.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1057: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0006 = 0x0006,
    DEVICE_0008 = 0x0008,
    DEVICE_0009 = 0x0009,
    DEVICE_0012 = 0x0012,
    DEVICE_0100 = 0x0100,
    DEVICE_0431 = 0x0431,
    DEVICE_1073 = 0x1073,
    DEVICE_1219 = 0x1219,
    DEVICE_1801 = 0x1801,
    DEVICE_18C0 = 0x18C0,
    DEVICE_18C1 = 0x18C1,
    DEVICE_3052 = 0x3052,
    DEVICE_3410 = 0x3410,
    DEVICE_4801 = 0x4801,
    DEVICE_4802 = 0x4802,
    DEVICE_4803 = 0x4803,
    DEVICE_4806 = 0x4806,
    DEVICE_480B = 0x480B,
    DEVICE_4D68 = 0x4D68,
    DEVICE_5600 = 0x5600,
    DEVICE_5608 = 0x5608,
    DEVICE_5803 = 0x5803,
    DEVICE_5806 = 0x5806,
    DEVICE_5808 = 0x5808,
    DEVICE_5809 = 0x5809,
    DEVICE_6400 = 0x6400,
    DEVICE_6405 = 0x6405
};



inline const char8* enumToString(PciDevice1057 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1057::NONE:        return "NONE";
        case PciDevice1057::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1057::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1057::DEVICE_0003: return "DEVICE_0003";
        case PciDevice1057::DEVICE_0004: return "DEVICE_0004";
        case PciDevice1057::DEVICE_0006: return "DEVICE_0006";
        case PciDevice1057::DEVICE_0008: return "DEVICE_0008";
        case PciDevice1057::DEVICE_0009: return "DEVICE_0009";
        case PciDevice1057::DEVICE_0012: return "DEVICE_0012";
        case PciDevice1057::DEVICE_0100: return "DEVICE_0100";
        case PciDevice1057::DEVICE_0431: return "DEVICE_0431";
        case PciDevice1057::DEVICE_1073: return "DEVICE_1073";
        case PciDevice1057::DEVICE_1219: return "DEVICE_1219";
        case PciDevice1057::DEVICE_1801: return "DEVICE_1801";
        case PciDevice1057::DEVICE_18C0: return "DEVICE_18C0";
        case PciDevice1057::DEVICE_18C1: return "DEVICE_18C1";
        case PciDevice1057::DEVICE_3052: return "DEVICE_3052";
        case PciDevice1057::DEVICE_3410: return "DEVICE_3410";
        case PciDevice1057::DEVICE_4801: return "DEVICE_4801";
        case PciDevice1057::DEVICE_4802: return "DEVICE_4802";
        case PciDevice1057::DEVICE_4803: return "DEVICE_4803";
        case PciDevice1057::DEVICE_4806: return "DEVICE_4806";
        case PciDevice1057::DEVICE_480B: return "DEVICE_480B";
        case PciDevice1057::DEVICE_4D68: return "DEVICE_4D68";
        case PciDevice1057::DEVICE_5600: return "DEVICE_5600";
        case PciDevice1057::DEVICE_5608: return "DEVICE_5608";
        case PciDevice1057::DEVICE_5803: return "DEVICE_5803";
        case PciDevice1057::DEVICE_5806: return "DEVICE_5806";
        case PciDevice1057::DEVICE_5808: return "DEVICE_5808";
        case PciDevice1057::DEVICE_5809: return "DEVICE_5809";
        case PciDevice1057::DEVICE_6400: return "DEVICE_6400";
        case PciDevice1057::DEVICE_6405: return "DEVICE_6405";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1057 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1057 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1057::DEVICE_0001: return "MPC105 [Eagle]";
        case PciDevice1057::DEVICE_0002: return "MPC106 [Grackle]";
        case PciDevice1057::DEVICE_0003: return "MPC8240 [Kahlua]";
        case PciDevice1057::DEVICE_0004: return "MPC107";
        case PciDevice1057::DEVICE_0006: return "MPC8245 [Unity]";
        case PciDevice1057::DEVICE_0008: return "MPC8540";
        case PciDevice1057::DEVICE_0009: return "MPC8560";
        case PciDevice1057::DEVICE_0012: return "MPC8548 [PowerQUICC III]";
        case PciDevice1057::DEVICE_0100: return "MC145575 [HFC-PCI]";
        case PciDevice1057::DEVICE_0431: return "KTbad_int829c 100VG";
        case PciDevice1057::DEVICE_1073: return "Nokia N770";
        case PciDevice1057::DEVICE_1219: return "Nokia N800";
        case PciDevice1057::DEVICE_1801: return "DSP56301 Digital Signal Processor";
        case PciDevice1057::DEVICE_18C0: return "MPC8265A/8266/8272";
        case PciDevice1057::DEVICE_18C1: return "MPC8271/MPC8272";
        case PciDevice1057::DEVICE_3052: return "SM56 Data Fax Modem";
        case PciDevice1057::DEVICE_3410: return "DSP56361 Digital Signal Processor";
        case PciDevice1057::DEVICE_4801: return "Raven";
        case PciDevice1057::DEVICE_4802: return "Falcon";
        case PciDevice1057::DEVICE_4803: return "Hawk";
        case PciDevice1057::DEVICE_4806: return "CPX8216";
        case PciDevice1057::DEVICE_480B: return "MPC7410";
        case PciDevice1057::DEVICE_4D68: return "20268";
        case PciDevice1057::DEVICE_5600: return "SM56 PCI Modem";
        case PciDevice1057::DEVICE_5608: return "Wildcard X100P";
        case PciDevice1057::DEVICE_5803: return "MPC5200";
        case PciDevice1057::DEVICE_5806: return "MCF54 Coldfire";
        case PciDevice1057::DEVICE_5808: return "MPC8220";
        case PciDevice1057::DEVICE_5809: return "MPC5200B";
        case PciDevice1057::DEVICE_6400: return "MPC190 Security Processor (S1 family, encryption)";
        case PciDevice1057::DEVICE_6405: return "MPC184 Security Processor (S1 family)";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1057 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1057::DEVICE_0001: return "Unknown device";
        case PciDevice1057::DEVICE_0002: return "Unknown device";
        case PciDevice1057::DEVICE_0003: return "Unknown device";
        case PciDevice1057::DEVICE_0004: return "Unknown device";
        case PciDevice1057::DEVICE_0006: return "Unknown device";
        case PciDevice1057::DEVICE_0008: return "Unknown device";
        case PciDevice1057::DEVICE_0009: return "Unknown device";
        case PciDevice1057::DEVICE_0012: return "Unknown device";
        case PciDevice1057::DEVICE_0100: return "Unknown device";
        case PciDevice1057::DEVICE_0431: return "Unknown device";
        case PciDevice1057::DEVICE_1073: return "Unknown device";
        case PciDevice1057::DEVICE_1219: return "Unknown device";
        case PciDevice1057::DEVICE_1801: return enumToHumanString((PciSubDevice10571801)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1057::DEVICE_18C0: return "Unknown device";
        case PciDevice1057::DEVICE_18C1: return "Unknown device";
        case PciDevice1057::DEVICE_3052: return "Unknown device";
        case PciDevice1057::DEVICE_3410: return enumToHumanString((PciSubDevice10573410)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1057::DEVICE_4801: return "Unknown device";
        case PciDevice1057::DEVICE_4802: return "Unknown device";
        case PciDevice1057::DEVICE_4803: return "Unknown device";
        case PciDevice1057::DEVICE_4806: return "Unknown device";
        case PciDevice1057::DEVICE_480B: return "Unknown device";
        case PciDevice1057::DEVICE_4D68: return "Unknown device";
        case PciDevice1057::DEVICE_5600: return enumToHumanString((PciSubDevice10575600)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1057::DEVICE_5608: return "Unknown device";
        case PciDevice1057::DEVICE_5803: return "Unknown device";
        case PciDevice1057::DEVICE_5806: return "Unknown device";
        case PciDevice1057::DEVICE_5808: return "Unknown device";
        case PciDevice1057::DEVICE_5809: return "Unknown device";
        case PciDevice1057::DEVICE_6400: return "Unknown device";
        case PciDevice1057::DEVICE_6405: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1057_PCIDEVICE1057_H
