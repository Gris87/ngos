// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCIDEVICE1FC9_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCIDEVICE1FC9_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1fc9/pcisubdevice1fc93010.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1fc9/pcisubdevice1fc93014.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1fc9/pcisubdevice1fc93110.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1fc9/pcisubdevice1fc93114.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1fc9/pcisubdevice1fc93310.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1fc9/pcisubdevice1fc93314.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1fc9/pcisubdevice1fc94020.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1fc9/pcisubdevice1fc94022.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1fc9/pcisubdevice1fc94025.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1fc9/pcisubdevice1fc94026.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1fc9/pcisubdevice1fc94027.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1FC9: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3009 = 0x3009,
    DEVICE_3010 = 0x3010,
    DEVICE_3014 = 0x3014,
    DEVICE_3110 = 0x3110,
    DEVICE_3114 = 0x3114,
    DEVICE_3310 = 0x3310,
    DEVICE_3314 = 0x3314,
    DEVICE_4010 = 0x4010,
    DEVICE_4020 = 0x4020,
    DEVICE_4022 = 0x4022,
    DEVICE_4024 = 0x4024,
    DEVICE_4025 = 0x4025,
    DEVICE_4026 = 0x4026,
    DEVICE_4027 = 0x4027,
    DEVICE_4527 = 0x4527
};



inline const char8* enumToString(PciDevice1FC9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1FC9::NONE:        return "NONE";
        case PciDevice1FC9::DEVICE_3009: return "DEVICE_3009";
        case PciDevice1FC9::DEVICE_3010: return "DEVICE_3010";
        case PciDevice1FC9::DEVICE_3014: return "DEVICE_3014";
        case PciDevice1FC9::DEVICE_3110: return "DEVICE_3110";
        case PciDevice1FC9::DEVICE_3114: return "DEVICE_3114";
        case PciDevice1FC9::DEVICE_3310: return "DEVICE_3310";
        case PciDevice1FC9::DEVICE_3314: return "DEVICE_3314";
        case PciDevice1FC9::DEVICE_4010: return "DEVICE_4010";
        case PciDevice1FC9::DEVICE_4020: return "DEVICE_4020";
        case PciDevice1FC9::DEVICE_4022: return "DEVICE_4022";
        case PciDevice1FC9::DEVICE_4024: return "DEVICE_4024";
        case PciDevice1FC9::DEVICE_4025: return "DEVICE_4025";
        case PciDevice1FC9::DEVICE_4026: return "DEVICE_4026";
        case PciDevice1FC9::DEVICE_4027: return "DEVICE_4027";
        case PciDevice1FC9::DEVICE_4527: return "DEVICE_4527";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1FC9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1FC9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1FC9::DEVICE_3009: return "10-Giga TOE SmartNIC";
        case PciDevice1FC9::DEVICE_3010: return "10-Giga TOE SmartNIC";
        case PciDevice1FC9::DEVICE_3014: return "10-Giga TOE SmartNIC 2-Port";
        case PciDevice1FC9::DEVICE_3110: return "10-Giga TOE Single Port SmartNIC";
        case PciDevice1FC9::DEVICE_3114: return "10-Giga TOE Dual Port Low Profile SmartNIC";
        case PciDevice1FC9::DEVICE_3310: return "10-Giga TOE SFP+ Single Port SmartNIC";
        case PciDevice1FC9::DEVICE_3314: return "10-Giga TOE Dual Port Low Profile SmartNIC";
        case PciDevice1FC9::DEVICE_4010: return "TN4010 Clean SROM";
        case PciDevice1FC9::DEVICE_4020: return "TN9030 10GbE CX4 Ethernet Adapter";
        case PciDevice1FC9::DEVICE_4022: return "TN9310 10GbE SFP+ Ethernet Adapter";
        case PciDevice1FC9::DEVICE_4024: return "TN9210 10GBase-T Ethernet Adapter";
        case PciDevice1FC9::DEVICE_4025: return "TN9510 10GBase-T/NBASE-T Ethernet Adapter";
        case PciDevice1FC9::DEVICE_4026: return "TN9610 10GbE SFP+ Ethernet Adapter";
        case PciDevice1FC9::DEVICE_4027: return "TN9710P 10GBase-T/NBASE-T Ethernet Adapter";
        case PciDevice1FC9::DEVICE_4527: return "TN9710Q 5GBase-T/NBASE-T Ethernet Adapter";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1FC9 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1FC9::DEVICE_3009: return "Unknown device";
        case PciDevice1FC9::DEVICE_3010: return enumToHumanString((PciSubDevice1FC93010)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1FC9::DEVICE_3014: return enumToHumanString((PciSubDevice1FC93014)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1FC9::DEVICE_3110: return enumToHumanString((PciSubDevice1FC93110)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1FC9::DEVICE_3114: return enumToHumanString((PciSubDevice1FC93114)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1FC9::DEVICE_3310: return enumToHumanString((PciSubDevice1FC93310)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1FC9::DEVICE_3314: return enumToHumanString((PciSubDevice1FC93314)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1FC9::DEVICE_4010: return "Unknown device";
        case PciDevice1FC9::DEVICE_4020: return enumToHumanString((PciSubDevice1FC94020)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1FC9::DEVICE_4022: return enumToHumanString((PciSubDevice1FC94022)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1FC9::DEVICE_4024: return "Unknown device";
        case PciDevice1FC9::DEVICE_4025: return enumToHumanString((PciSubDevice1FC94025)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1FC9::DEVICE_4026: return enumToHumanString((PciSubDevice1FC94026)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1FC9::DEVICE_4027: return enumToHumanString((PciSubDevice1FC94027)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1FC9::DEVICE_4527: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCIDEVICE1FC9_H
