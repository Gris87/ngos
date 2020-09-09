// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCIDEVICE103C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCIDEVICE103C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor103c/pcisubdevice103c1029.h>
#include <com/ngos/shared/common/pci/database/generated/vendor103c/pcisubdevice103c102a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor103c/pcisubdevice103c1031.h>
#include <com/ngos/shared/common/pci/database/generated/vendor103c/pcisubdevice103c1048.h>
#include <com/ngos/shared/common/pci/database/generated/vendor103c/pcisubdevice103c1290.h>
#include <com/ngos/shared/common/pci/database/generated/vendor103c/pcisubdevice103c22f6.h>
#include <com/ngos/shared/common/pci/database/generated/vendor103c/pcisubdevice103c3220.h>
#include <com/ngos/shared/common/pci/database/generated/vendor103c/pcisubdevice103c3230.h>
#include <com/ngos/shared/common/pci/database/generated/vendor103c/pcisubdevice103c3238.h>
#include <com/ngos/shared/common/pci/database/generated/vendor103c/pcisubdevice103c3239.h>
#include <com/ngos/shared/common/pci/database/generated/vendor103c/pcisubdevice103c323a.h>
#include <com/ngos/shared/common/pci/database/generated/vendor103c/pcisubdevice103c323b.h>
#include <com/ngos/shared/common/pci/database/generated/vendor103c/pcisubdevice103c323c.h>
#include <com/ngos/shared/common/pci/database/generated/vendor103c/pcisubdevice103c3300.h>
#include <com/ngos/shared/common/pci/database/generated/vendor103c/pcisubdevice103c3301.h>
#include <com/ngos/shared/common/pci/database/generated/vendor103c/pcisubdevice103c3302.h>
#include <com/ngos/shared/common/pci/database/generated/vendor103c/pcisubdevice103c3306.h>
#include <com/ngos/shared/common/pci/database/generated/vendor103c/pcisubdevice103c3307.h>
#include <com/ngos/shared/common/pci/database/generated/vendor103c/pcisubdevice103c3308.h>
#include <com/ngos/shared/common/pci/database/generated/vendor103c/pcisubdevice103c9602.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice103C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1005 = 0x1005,
    DEVICE_1008 = 0x1008,
    DEVICE_1028 = 0x1028,
    DEVICE_1029 = 0x1029,
    DEVICE_102A = 0x102A,
    DEVICE_1030 = 0x1030,
    DEVICE_1031 = 0x1031,
    DEVICE_1040 = 0x1040,
    DEVICE_1041 = 0x1041,
    DEVICE_1042 = 0x1042,
    DEVICE_1048 = 0x1048,
    DEVICE_1054 = 0x1054,
    DEVICE_1064 = 0x1064,
    DEVICE_108B = 0x108B,
    DEVICE_10C1 = 0x10C1,
    DEVICE_10ED = 0x10ED,
    DEVICE_10F0 = 0x10F0,
    DEVICE_10F1 = 0x10F1,
    DEVICE_1219 = 0x1219,
    DEVICE_121A = 0x121A,
    DEVICE_121B = 0x121B,
    DEVICE_121C = 0x121C,
    DEVICE_1229 = 0x1229,
    DEVICE_122A = 0x122A,
    DEVICE_122E = 0x122E,
    DEVICE_127B = 0x127B,
    DEVICE_127C = 0x127C,
    DEVICE_128D = 0x128D,
    DEVICE_1290 = 0x1290,
    DEVICE_1291 = 0x1291,
    DEVICE_12B4 = 0x12B4,
    DEVICE_12EB = 0x12EB,
    DEVICE_12EC = 0x12EC,
    DEVICE_12EE = 0x12EE,
    DEVICE_1302 = 0x1302,
    DEVICE_1303 = 0x1303,
    DEVICE_22F6 = 0x22F6,
    DEVICE_2910 = 0x2910,
    DEVICE_2925 = 0x2925,
    DEVICE_3206 = 0x3206,
    DEVICE_3220 = 0x3220,
    DEVICE_3230 = 0x3230,
    DEVICE_3238 = 0x3238,
    DEVICE_3239 = 0x3239,
    DEVICE_323A = 0x323A,
    DEVICE_323B = 0x323B,
    DEVICE_323C = 0x323C,
    DEVICE_3300 = 0x3300,
    DEVICE_3301 = 0x3301,
    DEVICE_3302 = 0x3302,
    DEVICE_3305 = 0x3305,
    DEVICE_3306 = 0x3306,
    DEVICE_3307 = 0x3307,
    DEVICE_3308 = 0x3308,
    DEVICE_4030 = 0x4030,
    DEVICE_4031 = 0x4031,
    DEVICE_4037 = 0x4037,
    DEVICE_9602 = 0x9602
};



inline const char8* enumToString(PciDevice103C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice103C::NONE:        return "NONE";
        case PciDevice103C::DEVICE_1005: return "DEVICE_1005";
        case PciDevice103C::DEVICE_1008: return "DEVICE_1008";
        case PciDevice103C::DEVICE_1028: return "DEVICE_1028";
        case PciDevice103C::DEVICE_1029: return "DEVICE_1029";
        case PciDevice103C::DEVICE_102A: return "DEVICE_102A";
        case PciDevice103C::DEVICE_1030: return "DEVICE_1030";
        case PciDevice103C::DEVICE_1031: return "DEVICE_1031";
        case PciDevice103C::DEVICE_1040: return "DEVICE_1040";
        case PciDevice103C::DEVICE_1041: return "DEVICE_1041";
        case PciDevice103C::DEVICE_1042: return "DEVICE_1042";
        case PciDevice103C::DEVICE_1048: return "DEVICE_1048";
        case PciDevice103C::DEVICE_1054: return "DEVICE_1054";
        case PciDevice103C::DEVICE_1064: return "DEVICE_1064";
        case PciDevice103C::DEVICE_108B: return "DEVICE_108B";
        case PciDevice103C::DEVICE_10C1: return "DEVICE_10C1";
        case PciDevice103C::DEVICE_10ED: return "DEVICE_10ED";
        case PciDevice103C::DEVICE_10F0: return "DEVICE_10F0";
        case PciDevice103C::DEVICE_10F1: return "DEVICE_10F1";
        case PciDevice103C::DEVICE_1219: return "DEVICE_1219";
        case PciDevice103C::DEVICE_121A: return "DEVICE_121A";
        case PciDevice103C::DEVICE_121B: return "DEVICE_121B";
        case PciDevice103C::DEVICE_121C: return "DEVICE_121C";
        case PciDevice103C::DEVICE_1229: return "DEVICE_1229";
        case PciDevice103C::DEVICE_122A: return "DEVICE_122A";
        case PciDevice103C::DEVICE_122E: return "DEVICE_122E";
        case PciDevice103C::DEVICE_127B: return "DEVICE_127B";
        case PciDevice103C::DEVICE_127C: return "DEVICE_127C";
        case PciDevice103C::DEVICE_128D: return "DEVICE_128D";
        case PciDevice103C::DEVICE_1290: return "DEVICE_1290";
        case PciDevice103C::DEVICE_1291: return "DEVICE_1291";
        case PciDevice103C::DEVICE_12B4: return "DEVICE_12B4";
        case PciDevice103C::DEVICE_12EB: return "DEVICE_12EB";
        case PciDevice103C::DEVICE_12EC: return "DEVICE_12EC";
        case PciDevice103C::DEVICE_12EE: return "DEVICE_12EE";
        case PciDevice103C::DEVICE_1302: return "DEVICE_1302";
        case PciDevice103C::DEVICE_1303: return "DEVICE_1303";
        case PciDevice103C::DEVICE_22F6: return "DEVICE_22F6";
        case PciDevice103C::DEVICE_2910: return "DEVICE_2910";
        case PciDevice103C::DEVICE_2925: return "DEVICE_2925";
        case PciDevice103C::DEVICE_3206: return "DEVICE_3206";
        case PciDevice103C::DEVICE_3220: return "DEVICE_3220";
        case PciDevice103C::DEVICE_3230: return "DEVICE_3230";
        case PciDevice103C::DEVICE_3238: return "DEVICE_3238";
        case PciDevice103C::DEVICE_3239: return "DEVICE_3239";
        case PciDevice103C::DEVICE_323A: return "DEVICE_323A";
        case PciDevice103C::DEVICE_323B: return "DEVICE_323B";
        case PciDevice103C::DEVICE_323C: return "DEVICE_323C";
        case PciDevice103C::DEVICE_3300: return "DEVICE_3300";
        case PciDevice103C::DEVICE_3301: return "DEVICE_3301";
        case PciDevice103C::DEVICE_3302: return "DEVICE_3302";
        case PciDevice103C::DEVICE_3305: return "DEVICE_3305";
        case PciDevice103C::DEVICE_3306: return "DEVICE_3306";
        case PciDevice103C::DEVICE_3307: return "DEVICE_3307";
        case PciDevice103C::DEVICE_3308: return "DEVICE_3308";
        case PciDevice103C::DEVICE_4030: return "DEVICE_4030";
        case PciDevice103C::DEVICE_4031: return "DEVICE_4031";
        case PciDevice103C::DEVICE_4037: return "DEVICE_4037";
        case PciDevice103C::DEVICE_9602: return "DEVICE_9602";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice103C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice103C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice103C::DEVICE_1005: return "A4977A Visualize EG";
        case PciDevice103C::DEVICE_1008: return "Visualize FX";
        case PciDevice103C::DEVICE_1028: return "Tach TL Fibre Channel Host Adapter";
        case PciDevice103C::DEVICE_1029: return "Tach XL2 Fibre Channel Host Adapter";
        case PciDevice103C::DEVICE_102A: return "Tach TS Fibre Channel Host Adapter";
        case PciDevice103C::DEVICE_1030: return "J2585A DeskDirect 10/100VG NIC";
        case PciDevice103C::DEVICE_1031: return "J2585B HP 10/100VG PCI LAN Adapter";
        case PciDevice103C::DEVICE_1040: return "J2973A DeskDirect 10BaseT NIC";
        case PciDevice103C::DEVICE_1041: return "J2585B DeskDirect 10/100 NIC";
        case PciDevice103C::DEVICE_1042: return "J2970A DeskDirect 10BaseT/2 NIC";
        case PciDevice103C::DEVICE_1048: return "Diva Serial [GSP] Multiport UART";
        case PciDevice103C::DEVICE_1054: return "PCI Local Bus Adapter";
        case PciDevice103C::DEVICE_1064: return "79C970 PCnet Ethernet Controller";
        case PciDevice103C::DEVICE_108B: return "Visualize FXe";
        case PciDevice103C::DEVICE_10C1: return "NetServer Smart IRQ Router";
        case PciDevice103C::DEVICE_10ED: return "TopTools Remote Control";
        case PciDevice103C::DEVICE_10F0: return "rio System Bus Adapter";
        case PciDevice103C::DEVICE_10F1: return "rio I/O Controller";
        case PciDevice103C::DEVICE_1219: return "NetServer PCI Hot-Plug Controller";
        case PciDevice103C::DEVICE_121A: return "NetServer SMIC Controller";
        case PciDevice103C::DEVICE_121B: return "NetServer Legacy COM Port Decoder";
        case PciDevice103C::DEVICE_121C: return "NetServer PCI COM Port Decoder";
        case PciDevice103C::DEVICE_1229: return "zx1 System Bus Adapter";
        case PciDevice103C::DEVICE_122A: return "zx1 I/O Controller";
        case PciDevice103C::DEVICE_122E: return "PCI-X Local Bus Adapter";
        case PciDevice103C::DEVICE_127B: return "sx1000 System Bus Adapter";
        case PciDevice103C::DEVICE_127C: return "sx1000 I/O Controller";
        case PciDevice103C::DEVICE_128D: return "Diva [GSP] Management Board";
        case PciDevice103C::DEVICE_1290: return "Auxiliary Diva Serial Port";
        case PciDevice103C::DEVICE_1291: return "Auxiliary Diva Serial Port";
        case PciDevice103C::DEVICE_12B4: return "zx1 QuickSilver AGP8x Local Bus Adapter";
        case PciDevice103C::DEVICE_12EB: return "sx2000 System Bus Adapter";
        case PciDevice103C::DEVICE_12EC: return "sx2000 I/O Controller";
        case PciDevice103C::DEVICE_12EE: return "PCI-X 2.0 Local Bus Adapter";
        case PciDevice103C::DEVICE_1302: return "RMP-3 Shared Memory Driver";
        case PciDevice103C::DEVICE_1303: return "RMP-3 (Remote Management Processor)";
        case PciDevice103C::DEVICE_22F6: return "iLO5 Virtual USB Controller";
        case PciDevice103C::DEVICE_2910: return "E2910A PCIBus Exerciser";
        case PciDevice103C::DEVICE_2925: return "E2925A 32 Bit, 33 MHzPCI Exerciser & Analyzer";
        case PciDevice103C::DEVICE_3206: return "Adaptec Embedded Serial ATA HostRAID";
        case PciDevice103C::DEVICE_3220: return "Smart Array P600";
        case PciDevice103C::DEVICE_3230: return "Smart Array Controller";
        case PciDevice103C::DEVICE_3238: return "Smart Array E200i (SAS Controller)";
        case PciDevice103C::DEVICE_3239: return "Smart Array Gen9 Controllers";
        case PciDevice103C::DEVICE_323A: return "Smart Array G6 controllers";
        case PciDevice103C::DEVICE_323B: return "Smart Array Gen8 Controllers";
        case PciDevice103C::DEVICE_323C: return "Smart Array Gen8+ Controllers";
        case PciDevice103C::DEVICE_3300: return "Integrated Lights-Out Standard Virtual USB Controller";
        case PciDevice103C::DEVICE_3301: return "Integrated Lights-Out Standard Serial Port";
        case PciDevice103C::DEVICE_3302: return "Integrated Lights-Out Standard KCS Interface";
        case PciDevice103C::DEVICE_3305: return "Integrated Lights-Out (iLO2) Controller";
        case PciDevice103C::DEVICE_3306: return "Integrated Lights-Out Standard Slave Instrumentation & System Support";
        case PciDevice103C::DEVICE_3307: return "Integrated Lights-Out Standard Management Processor Support and Messaging";
        case PciDevice103C::DEVICE_3308: return "Integrated Lights-Out Standard MS Watchdog Timer";
        case PciDevice103C::DEVICE_4030: return "zx2 System Bus Adapter";
        case PciDevice103C::DEVICE_4031: return "zx2 I/O Controller";
        case PciDevice103C::DEVICE_4037: return "PCIe Local Bus Adapter";
        case PciDevice103C::DEVICE_9602: return "AMD RS780/RS880 PCI to PCI bridge (int gfx)";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice103C device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice103C::DEVICE_1005: return "Unknown device";
        case PciDevice103C::DEVICE_1008: return "Unknown device";
        case PciDevice103C::DEVICE_1028: return "Unknown device";
        case PciDevice103C::DEVICE_1029: return enumToHumanString((PciSubDevice103C1029)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice103C::DEVICE_102A: return enumToHumanString((PciSubDevice103C102A)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice103C::DEVICE_1030: return "Unknown device";
        case PciDevice103C::DEVICE_1031: return enumToHumanString((PciSubDevice103C1031)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice103C::DEVICE_1040: return "Unknown device";
        case PciDevice103C::DEVICE_1041: return "Unknown device";
        case PciDevice103C::DEVICE_1042: return "Unknown device";
        case PciDevice103C::DEVICE_1048: return enumToHumanString((PciSubDevice103C1048)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice103C::DEVICE_1054: return "Unknown device";
        case PciDevice103C::DEVICE_1064: return "Unknown device";
        case PciDevice103C::DEVICE_108B: return "Unknown device";
        case PciDevice103C::DEVICE_10C1: return "Unknown device";
        case PciDevice103C::DEVICE_10ED: return "Unknown device";
        case PciDevice103C::DEVICE_10F0: return "Unknown device";
        case PciDevice103C::DEVICE_10F1: return "Unknown device";
        case PciDevice103C::DEVICE_1219: return "Unknown device";
        case PciDevice103C::DEVICE_121A: return "Unknown device";
        case PciDevice103C::DEVICE_121B: return "Unknown device";
        case PciDevice103C::DEVICE_121C: return "Unknown device";
        case PciDevice103C::DEVICE_1229: return "Unknown device";
        case PciDevice103C::DEVICE_122A: return "Unknown device";
        case PciDevice103C::DEVICE_122E: return "Unknown device";
        case PciDevice103C::DEVICE_127B: return "Unknown device";
        case PciDevice103C::DEVICE_127C: return "Unknown device";
        case PciDevice103C::DEVICE_128D: return "Unknown device";
        case PciDevice103C::DEVICE_1290: return enumToHumanString((PciSubDevice103C1290)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice103C::DEVICE_1291: return "Unknown device";
        case PciDevice103C::DEVICE_12B4: return "Unknown device";
        case PciDevice103C::DEVICE_12EB: return "Unknown device";
        case PciDevice103C::DEVICE_12EC: return "Unknown device";
        case PciDevice103C::DEVICE_12EE: return "Unknown device";
        case PciDevice103C::DEVICE_1302: return "Unknown device";
        case PciDevice103C::DEVICE_1303: return "Unknown device";
        case PciDevice103C::DEVICE_22F6: return enumToHumanString((PciSubDevice103C22F6)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice103C::DEVICE_2910: return "Unknown device";
        case PciDevice103C::DEVICE_2925: return "Unknown device";
        case PciDevice103C::DEVICE_3206: return "Unknown device";
        case PciDevice103C::DEVICE_3220: return enumToHumanString((PciSubDevice103C3220)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice103C::DEVICE_3230: return enumToHumanString((PciSubDevice103C3230)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice103C::DEVICE_3238: return enumToHumanString((PciSubDevice103C3238)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice103C::DEVICE_3239: return enumToHumanString((PciSubDevice103C3239)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice103C::DEVICE_323A: return enumToHumanString((PciSubDevice103C323A)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice103C::DEVICE_323B: return enumToHumanString((PciSubDevice103C323B)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice103C::DEVICE_323C: return enumToHumanString((PciSubDevice103C323C)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice103C::DEVICE_3300: return enumToHumanString((PciSubDevice103C3300)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice103C::DEVICE_3301: return enumToHumanString((PciSubDevice103C3301)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice103C::DEVICE_3302: return enumToHumanString((PciSubDevice103C3302)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice103C::DEVICE_3305: return "Unknown device";
        case PciDevice103C::DEVICE_3306: return enumToHumanString((PciSubDevice103C3306)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice103C::DEVICE_3307: return enumToHumanString((PciSubDevice103C3307)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice103C::DEVICE_3308: return enumToHumanString((PciSubDevice103C3308)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice103C::DEVICE_4030: return "Unknown device";
        case PciDevice103C::DEVICE_4031: return "Unknown device";
        case PciDevice103C::DEVICE_4037: return "Unknown device";
        case PciDevice103C::DEVICE_9602: return enumToHumanString((PciSubDevice103C9602)(subsystemVendorID << 16 | subDeviceId));

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR103C_PCIDEVICE103C_H
