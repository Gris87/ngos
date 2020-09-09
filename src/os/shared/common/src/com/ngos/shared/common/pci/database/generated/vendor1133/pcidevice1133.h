// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCIDEVICE1133_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCIDEVICE1133_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1133/pcisubdevice1133e010.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1133/pcisubdevice1133e013.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1133/pcisubdevice1133e017.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1133/pcisubdevice1133e018.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1133/pcisubdevice1133e019.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1133/pcisubdevice1133e01b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1133/pcisubdevice1133e01c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1133/pcisubdevice1133e01e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1133/pcisubdevice1133e020.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1133/pcisubdevice1133e022.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1133/pcisubdevice1133e024.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1133/pcisubdevice1133e028.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1133/pcisubdevice1133e02e.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1133/pcisubdevice1133e032.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1133: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_7701 = 0x7701,
    DEVICE_7711 = 0x7711,
    DEVICE_7901 = 0x7901,
    DEVICE_7902 = 0x7902,
    DEVICE_7911 = 0x7911,
    DEVICE_7912 = 0x7912,
    DEVICE_7921 = 0x7921,
    DEVICE_7941 = 0x7941,
    DEVICE_7942 = 0x7942,
    DEVICE_7943 = 0x7943,
    DEVICE_7944 = 0x7944,
    DEVICE_7945 = 0x7945,
    DEVICE_7948 = 0x7948,
    DEVICE_9711 = 0x9711,
    DEVICE_9911 = 0x9911,
    DEVICE_9941 = 0x9941,
    DEVICE_9A41 = 0x9A41,
    DEVICE_B921 = 0xB921,
    DEVICE_B922 = 0xB922,
    DEVICE_B923 = 0xB923,
    DEVICE_E001 = 0xE001,
    DEVICE_E002 = 0xE002,
    DEVICE_E003 = 0xE003,
    DEVICE_E004 = 0xE004,
    DEVICE_E005 = 0xE005,
    DEVICE_E006 = 0xE006,
    DEVICE_E007 = 0xE007,
    DEVICE_E008 = 0xE008,
    DEVICE_E009 = 0xE009,
    DEVICE_E00A = 0xE00A,
    DEVICE_E00B = 0xE00B,
    DEVICE_E00C = 0xE00C,
    DEVICE_E00D = 0xE00D,
    DEVICE_E00E = 0xE00E,
    DEVICE_E010 = 0xE010,
    DEVICE_E011 = 0xE011,
    DEVICE_E012 = 0xE012,
    DEVICE_E013 = 0xE013,
    DEVICE_E014 = 0xE014,
    DEVICE_E015 = 0xE015,
    DEVICE_E016 = 0xE016,
    DEVICE_E017 = 0xE017,
    DEVICE_E018 = 0xE018,
    DEVICE_E019 = 0xE019,
    DEVICE_E01A = 0xE01A,
    DEVICE_E01B = 0xE01B,
    DEVICE_E01C = 0xE01C,
    DEVICE_E01E = 0xE01E,
    DEVICE_E020 = 0xE020,
    DEVICE_E022 = 0xE022,
    DEVICE_E024 = 0xE024,
    DEVICE_E028 = 0xE028,
    DEVICE_E02A = 0xE02A,
    DEVICE_E02C = 0xE02C,
    DEVICE_E02E = 0xE02E,
    DEVICE_E032 = 0xE032,
    DEVICE_E034 = 0xE034
};



inline const char8* enumToString(PciDevice1133 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1133::NONE:        return "NONE";
        case PciDevice1133::DEVICE_7701: return "DEVICE_7701";
        case PciDevice1133::DEVICE_7711: return "DEVICE_7711";
        case PciDevice1133::DEVICE_7901: return "DEVICE_7901";
        case PciDevice1133::DEVICE_7902: return "DEVICE_7902";
        case PciDevice1133::DEVICE_7911: return "DEVICE_7911";
        case PciDevice1133::DEVICE_7912: return "DEVICE_7912";
        case PciDevice1133::DEVICE_7921: return "DEVICE_7921";
        case PciDevice1133::DEVICE_7941: return "DEVICE_7941";
        case PciDevice1133::DEVICE_7942: return "DEVICE_7942";
        case PciDevice1133::DEVICE_7943: return "DEVICE_7943";
        case PciDevice1133::DEVICE_7944: return "DEVICE_7944";
        case PciDevice1133::DEVICE_7945: return "DEVICE_7945";
        case PciDevice1133::DEVICE_7948: return "DEVICE_7948";
        case PciDevice1133::DEVICE_9711: return "DEVICE_9711";
        case PciDevice1133::DEVICE_9911: return "DEVICE_9911";
        case PciDevice1133::DEVICE_9941: return "DEVICE_9941";
        case PciDevice1133::DEVICE_9A41: return "DEVICE_9A41";
        case PciDevice1133::DEVICE_B921: return "DEVICE_B921";
        case PciDevice1133::DEVICE_B922: return "DEVICE_B922";
        case PciDevice1133::DEVICE_B923: return "DEVICE_B923";
        case PciDevice1133::DEVICE_E001: return "DEVICE_E001";
        case PciDevice1133::DEVICE_E002: return "DEVICE_E002";
        case PciDevice1133::DEVICE_E003: return "DEVICE_E003";
        case PciDevice1133::DEVICE_E004: return "DEVICE_E004";
        case PciDevice1133::DEVICE_E005: return "DEVICE_E005";
        case PciDevice1133::DEVICE_E006: return "DEVICE_E006";
        case PciDevice1133::DEVICE_E007: return "DEVICE_E007";
        case PciDevice1133::DEVICE_E008: return "DEVICE_E008";
        case PciDevice1133::DEVICE_E009: return "DEVICE_E009";
        case PciDevice1133::DEVICE_E00A: return "DEVICE_E00A";
        case PciDevice1133::DEVICE_E00B: return "DEVICE_E00B";
        case PciDevice1133::DEVICE_E00C: return "DEVICE_E00C";
        case PciDevice1133::DEVICE_E00D: return "DEVICE_E00D";
        case PciDevice1133::DEVICE_E00E: return "DEVICE_E00E";
        case PciDevice1133::DEVICE_E010: return "DEVICE_E010";
        case PciDevice1133::DEVICE_E011: return "DEVICE_E011";
        case PciDevice1133::DEVICE_E012: return "DEVICE_E012";
        case PciDevice1133::DEVICE_E013: return "DEVICE_E013";
        case PciDevice1133::DEVICE_E014: return "DEVICE_E014";
        case PciDevice1133::DEVICE_E015: return "DEVICE_E015";
        case PciDevice1133::DEVICE_E016: return "DEVICE_E016";
        case PciDevice1133::DEVICE_E017: return "DEVICE_E017";
        case PciDevice1133::DEVICE_E018: return "DEVICE_E018";
        case PciDevice1133::DEVICE_E019: return "DEVICE_E019";
        case PciDevice1133::DEVICE_E01A: return "DEVICE_E01A";
        case PciDevice1133::DEVICE_E01B: return "DEVICE_E01B";
        case PciDevice1133::DEVICE_E01C: return "DEVICE_E01C";
        case PciDevice1133::DEVICE_E01E: return "DEVICE_E01E";
        case PciDevice1133::DEVICE_E020: return "DEVICE_E020";
        case PciDevice1133::DEVICE_E022: return "DEVICE_E022";
        case PciDevice1133::DEVICE_E024: return "DEVICE_E024";
        case PciDevice1133::DEVICE_E028: return "DEVICE_E028";
        case PciDevice1133::DEVICE_E02A: return "DEVICE_E02A";
        case PciDevice1133::DEVICE_E02C: return "DEVICE_E02C";
        case PciDevice1133::DEVICE_E02E: return "DEVICE_E02E";
        case PciDevice1133::DEVICE_E032: return "DEVICE_E032";
        case PciDevice1133::DEVICE_E034: return "DEVICE_E034";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1133 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1133 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1133::DEVICE_7701: return "Eiconcard C90";
        case PciDevice1133::DEVICE_7711: return "Eiconcard C91";
        case PciDevice1133::DEVICE_7901: return "EiconCard S90";
        case PciDevice1133::DEVICE_7902: return "EiconCard S90";
        case PciDevice1133::DEVICE_7911: return "EiconCard S91";
        case PciDevice1133::DEVICE_7912: return "EiconCard S91";
        case PciDevice1133::DEVICE_7921: return "Eiconcard S92";
        case PciDevice1133::DEVICE_7941: return "EiconCard S94";
        case PciDevice1133::DEVICE_7942: return "EiconCard S94";
        case PciDevice1133::DEVICE_7943: return "EiconCard S94";
        case PciDevice1133::DEVICE_7944: return "EiconCard S94";
        case PciDevice1133::DEVICE_7945: return "Eiconcard S94";
        case PciDevice1133::DEVICE_7948: return "Eiconcard S94 64bit/66MHz";
        case PciDevice1133::DEVICE_9711: return "Eiconcard S91 V2";
        case PciDevice1133::DEVICE_9911: return "Eiconcard S91 V2";
        case PciDevice1133::DEVICE_9941: return "Eiconcard S94 V2";
        case PciDevice1133::DEVICE_9A41: return "Eiconcard S94 PCIe";
        case PciDevice1133::DEVICE_B921: return "EiconCard P92";
        case PciDevice1133::DEVICE_B922: return "EiconCard P92";
        case PciDevice1133::DEVICE_B923: return "EiconCard P92";
        case PciDevice1133::DEVICE_E001: return "Diva Pro 2.0 S/T";
        case PciDevice1133::DEVICE_E002: return "Diva 2.0 S/T PCI";
        case PciDevice1133::DEVICE_E003: return "Diva Pro 2.0 U";
        case PciDevice1133::DEVICE_E004: return "Diva 2.0 U PCI";
        case PciDevice1133::DEVICE_E005: return "Diva 2.01 S/T PCI";
        case PciDevice1133::DEVICE_E006: return "Diva CT S/T PCI";
        case PciDevice1133::DEVICE_E007: return "Diva CT U PCI";
        case PciDevice1133::DEVICE_E008: return "Diva CT Lite S/T PCI";
        case PciDevice1133::DEVICE_E009: return "Diva CT Lite U PCI";
        case PciDevice1133::DEVICE_E00A: return "Diva ISDN+V.90 PCI";
        case PciDevice1133::DEVICE_E00B: return "Diva ISDN PCI 2.02";
        case PciDevice1133::DEVICE_E00C: return "Diva 2.02 PCI U";
        case PciDevice1133::DEVICE_E00D: return "Diva Pro 3.0 PCI";
        case PciDevice1133::DEVICE_E00E: return "Diva ISDN+CT S/T PCI Rev 2";
        case PciDevice1133::DEVICE_E010: return "Diva Server BRI-2M PCI";
        case PciDevice1133::DEVICE_E011: return "Diva Server BRI S/T Rev 2";
        case PciDevice1133::DEVICE_E012: return "Diva Server 4BRI-8M PCI";
        case PciDevice1133::DEVICE_E013: return "4BRI";
        case PciDevice1133::DEVICE_E014: return "Diva Server PRI-30M PCI";
        case PciDevice1133::DEVICE_E015: return "Diva PRI PCI v2";
        case PciDevice1133::DEVICE_E016: return "Diva Server Voice 4BRI PCI";
        case PciDevice1133::DEVICE_E017: return "Diva Server Voice 4BRI Rev 2";
        case PciDevice1133::DEVICE_E018: return "BRI";
        case PciDevice1133::DEVICE_E019: return "Diva Server Voice PRI Rev 2";
        case PciDevice1133::DEVICE_E01A: return "Diva BRI-2FX PCI v2";
        case PciDevice1133::DEVICE_E01B: return "Diva Server Voice BRI-2M 2.0 PCI";
        case PciDevice1133::DEVICE_E01C: return "PRI";
        case PciDevice1133::DEVICE_E01E: return "2PRI";
        case PciDevice1133::DEVICE_E020: return "4PRI";
        case PciDevice1133::DEVICE_E022: return "Analog-2";
        case PciDevice1133::DEVICE_E024: return "Analog-4";
        case PciDevice1133::DEVICE_E028: return "Analog-8";
        case PciDevice1133::DEVICE_E02A: return "Diva IPM-300 PCI v1";
        case PciDevice1133::DEVICE_E02C: return "Diva IPM-600 PCI v1";
        case PciDevice1133::DEVICE_E02E: return "4BRI";
        case PciDevice1133::DEVICE_E032: return "BRI";
        case PciDevice1133::DEVICE_E034: return "Diva BRI-CTI PCI v2";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1133 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1133::DEVICE_7701: return "Unknown device";
        case PciDevice1133::DEVICE_7711: return "Unknown device";
        case PciDevice1133::DEVICE_7901: return "Unknown device";
        case PciDevice1133::DEVICE_7902: return "Unknown device";
        case PciDevice1133::DEVICE_7911: return "Unknown device";
        case PciDevice1133::DEVICE_7912: return "Unknown device";
        case PciDevice1133::DEVICE_7921: return "Unknown device";
        case PciDevice1133::DEVICE_7941: return "Unknown device";
        case PciDevice1133::DEVICE_7942: return "Unknown device";
        case PciDevice1133::DEVICE_7943: return "Unknown device";
        case PciDevice1133::DEVICE_7944: return "Unknown device";
        case PciDevice1133::DEVICE_7945: return "Unknown device";
        case PciDevice1133::DEVICE_7948: return "Unknown device";
        case PciDevice1133::DEVICE_9711: return "Unknown device";
        case PciDevice1133::DEVICE_9911: return "Unknown device";
        case PciDevice1133::DEVICE_9941: return "Unknown device";
        case PciDevice1133::DEVICE_9A41: return "Unknown device";
        case PciDevice1133::DEVICE_B921: return "Unknown device";
        case PciDevice1133::DEVICE_B922: return "Unknown device";
        case PciDevice1133::DEVICE_B923: return "Unknown device";
        case PciDevice1133::DEVICE_E001: return "Unknown device";
        case PciDevice1133::DEVICE_E002: return "Unknown device";
        case PciDevice1133::DEVICE_E003: return "Unknown device";
        case PciDevice1133::DEVICE_E004: return "Unknown device";
        case PciDevice1133::DEVICE_E005: return "Unknown device";
        case PciDevice1133::DEVICE_E006: return "Unknown device";
        case PciDevice1133::DEVICE_E007: return "Unknown device";
        case PciDevice1133::DEVICE_E008: return "Unknown device";
        case PciDevice1133::DEVICE_E009: return "Unknown device";
        case PciDevice1133::DEVICE_E00A: return "Unknown device";
        case PciDevice1133::DEVICE_E00B: return "Unknown device";
        case PciDevice1133::DEVICE_E00C: return "Unknown device";
        case PciDevice1133::DEVICE_E00D: return "Unknown device";
        case PciDevice1133::DEVICE_E00E: return "Unknown device";
        case PciDevice1133::DEVICE_E010: return enumToHumanString((PciSubDevice1133E010)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1133::DEVICE_E011: return "Unknown device";
        case PciDevice1133::DEVICE_E012: return "Unknown device";
        case PciDevice1133::DEVICE_E013: return enumToHumanString((PciSubDevice1133E013)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1133::DEVICE_E014: return "Unknown device";
        case PciDevice1133::DEVICE_E015: return "Unknown device";
        case PciDevice1133::DEVICE_E016: return "Unknown device";
        case PciDevice1133::DEVICE_E017: return enumToHumanString((PciSubDevice1133E017)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1133::DEVICE_E018: return enumToHumanString((PciSubDevice1133E018)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1133::DEVICE_E019: return enumToHumanString((PciSubDevice1133E019)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1133::DEVICE_E01A: return "Unknown device";
        case PciDevice1133::DEVICE_E01B: return enumToHumanString((PciSubDevice1133E01B)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1133::DEVICE_E01C: return enumToHumanString((PciSubDevice1133E01C)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1133::DEVICE_E01E: return enumToHumanString((PciSubDevice1133E01E)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1133::DEVICE_E020: return enumToHumanString((PciSubDevice1133E020)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1133::DEVICE_E022: return enumToHumanString((PciSubDevice1133E022)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1133::DEVICE_E024: return enumToHumanString((PciSubDevice1133E024)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1133::DEVICE_E028: return enumToHumanString((PciSubDevice1133E028)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1133::DEVICE_E02A: return "Unknown device";
        case PciDevice1133::DEVICE_E02C: return "Unknown device";
        case PciDevice1133::DEVICE_E02E: return enumToHumanString((PciSubDevice1133E02E)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1133::DEVICE_E032: return enumToHumanString((PciSubDevice1133E032)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1133::DEVICE_E034: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCIDEVICE1133_H
