// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1415_PCIDEVICE1415_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1415_PCIDEVICE1415_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1415/pcisubdevice14159501.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1415/pcisubdevice14159510.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1415/pcisubdevice14159511.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1415/pcisubdevice1415c158.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1415: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8401 = 0x8401,
    DEVICE_8403 = 0x8403,
    DEVICE_9500 = 0x9500,
    DEVICE_9501 = 0x9501,
    DEVICE_9505 = 0x9505,
    DEVICE_950A = 0x950A,
    DEVICE_950B = 0x950B,
    DEVICE_9510 = 0x9510,
    DEVICE_9511 = 0x9511,
    DEVICE_9512 = 0x9512,
    DEVICE_9513 = 0x9513,
    DEVICE_9521 = 0x9521,
    DEVICE_9523 = 0x9523,
    DEVICE_C100 = 0xC100,
    DEVICE_C101 = 0xC101,
    DEVICE_C104 = 0xC104,
    DEVICE_C105 = 0xC105,
    DEVICE_C106 = 0xC106,
    DEVICE_C108 = 0xC108,
    DEVICE_C109 = 0xC109,
    DEVICE_C10C = 0xC10C,
    DEVICE_C10D = 0xC10D,
    DEVICE_C10E = 0xC10E,
    DEVICE_C110 = 0xC110,
    DEVICE_C114 = 0xC114,
    DEVICE_C118 = 0xC118,
    DEVICE_C11B = 0xC11B,
    DEVICE_C11C = 0xC11C,
    DEVICE_C11E = 0xC11E,
    DEVICE_C11F = 0xC11F,
    DEVICE_C120 = 0xC120,
    DEVICE_C124 = 0xC124,
    DEVICE_C126 = 0xC126,
    DEVICE_C128 = 0xC128,
    DEVICE_C12C = 0xC12C,
    DEVICE_C12E = 0xC12E,
    DEVICE_C134 = 0xC134,
    DEVICE_C138 = 0xC138,
    DEVICE_C13C = 0xC13C,
    DEVICE_C13D = 0xC13D,
    DEVICE_C140 = 0xC140,
    DEVICE_C141 = 0xC141,
    DEVICE_C144 = 0xC144,
    DEVICE_C145 = 0xC145,
    DEVICE_C146 = 0xC146,
    DEVICE_C148 = 0xC148,
    DEVICE_C149 = 0xC149,
    DEVICE_C14C = 0xC14C,
    DEVICE_C14D = 0xC14D,
    DEVICE_C14E = 0xC14E,
    DEVICE_C154 = 0xC154,
    DEVICE_C158 = 0xC158,
    DEVICE_C15C = 0xC15C,
    DEVICE_C15D = 0xC15D,
    DEVICE_C308 = 0xC308
};



inline const char8* enumToString(PciDevice1415 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1415::NONE:        return "NONE";
        case PciDevice1415::DEVICE_8401: return "DEVICE_8401";
        case PciDevice1415::DEVICE_8403: return "DEVICE_8403";
        case PciDevice1415::DEVICE_9500: return "DEVICE_9500";
        case PciDevice1415::DEVICE_9501: return "DEVICE_9501";
        case PciDevice1415::DEVICE_9505: return "DEVICE_9505";
        case PciDevice1415::DEVICE_950A: return "DEVICE_950A";
        case PciDevice1415::DEVICE_950B: return "DEVICE_950B";
        case PciDevice1415::DEVICE_9510: return "DEVICE_9510";
        case PciDevice1415::DEVICE_9511: return "DEVICE_9511";
        case PciDevice1415::DEVICE_9512: return "DEVICE_9512";
        case PciDevice1415::DEVICE_9513: return "DEVICE_9513";
        case PciDevice1415::DEVICE_9521: return "DEVICE_9521";
        case PciDevice1415::DEVICE_9523: return "DEVICE_9523";
        case PciDevice1415::DEVICE_C100: return "DEVICE_C100";
        case PciDevice1415::DEVICE_C101: return "DEVICE_C101";
        case PciDevice1415::DEVICE_C104: return "DEVICE_C104";
        case PciDevice1415::DEVICE_C105: return "DEVICE_C105";
        case PciDevice1415::DEVICE_C106: return "DEVICE_C106";
        case PciDevice1415::DEVICE_C108: return "DEVICE_C108";
        case PciDevice1415::DEVICE_C109: return "DEVICE_C109";
        case PciDevice1415::DEVICE_C10C: return "DEVICE_C10C";
        case PciDevice1415::DEVICE_C10D: return "DEVICE_C10D";
        case PciDevice1415::DEVICE_C10E: return "DEVICE_C10E";
        case PciDevice1415::DEVICE_C110: return "DEVICE_C110";
        case PciDevice1415::DEVICE_C114: return "DEVICE_C114";
        case PciDevice1415::DEVICE_C118: return "DEVICE_C118";
        case PciDevice1415::DEVICE_C11B: return "DEVICE_C11B";
        case PciDevice1415::DEVICE_C11C: return "DEVICE_C11C";
        case PciDevice1415::DEVICE_C11E: return "DEVICE_C11E";
        case PciDevice1415::DEVICE_C11F: return "DEVICE_C11F";
        case PciDevice1415::DEVICE_C120: return "DEVICE_C120";
        case PciDevice1415::DEVICE_C124: return "DEVICE_C124";
        case PciDevice1415::DEVICE_C126: return "DEVICE_C126";
        case PciDevice1415::DEVICE_C128: return "DEVICE_C128";
        case PciDevice1415::DEVICE_C12C: return "DEVICE_C12C";
        case PciDevice1415::DEVICE_C12E: return "DEVICE_C12E";
        case PciDevice1415::DEVICE_C134: return "DEVICE_C134";
        case PciDevice1415::DEVICE_C138: return "DEVICE_C138";
        case PciDevice1415::DEVICE_C13C: return "DEVICE_C13C";
        case PciDevice1415::DEVICE_C13D: return "DEVICE_C13D";
        case PciDevice1415::DEVICE_C140: return "DEVICE_C140";
        case PciDevice1415::DEVICE_C141: return "DEVICE_C141";
        case PciDevice1415::DEVICE_C144: return "DEVICE_C144";
        case PciDevice1415::DEVICE_C145: return "DEVICE_C145";
        case PciDevice1415::DEVICE_C146: return "DEVICE_C146";
        case PciDevice1415::DEVICE_C148: return "DEVICE_C148";
        case PciDevice1415::DEVICE_C149: return "DEVICE_C149";
        case PciDevice1415::DEVICE_C14C: return "DEVICE_C14C";
        case PciDevice1415::DEVICE_C14D: return "DEVICE_C14D";
        case PciDevice1415::DEVICE_C14E: return "DEVICE_C14E";
        case PciDevice1415::DEVICE_C154: return "DEVICE_C154";
        case PciDevice1415::DEVICE_C158: return "DEVICE_C158";
        case PciDevice1415::DEVICE_C15C: return "DEVICE_C15C";
        case PciDevice1415::DEVICE_C15D: return "DEVICE_C15D";
        case PciDevice1415::DEVICE_C308: return "DEVICE_C308";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1415 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1415 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1415::DEVICE_8401: return "OX9162 Mode 1 (8-bit bus)";
        case PciDevice1415::DEVICE_8403: return "OX9162 Mode 0 (parallel port)";
        case PciDevice1415::DEVICE_9500: return "OX16PCI954 (Quad 16950 UART) function 0 (Disabled)";
        case PciDevice1415::DEVICE_9501: return "OX16PCI954 (Quad 16950 UART) function 0 (Uart)";
        case PciDevice1415::DEVICE_9505: return "OXuPCI952 (Dual 16C950 UART)";
        case PciDevice1415::DEVICE_950A: return "EXSYS EX-41092 Dual 16950 Serial adapter";
        case PciDevice1415::DEVICE_950B: return "OXCB950 Cardbus 16950 UART";
        case PciDevice1415::DEVICE_9510: return "OX16PCI954 (Quad 16950 UART) function 1 (Disabled)";
        case PciDevice1415::DEVICE_9511: return "OX16PCI954 (Quad 16950 UART) function 1 (8bit bus)";
        case PciDevice1415::DEVICE_9512: return "OX16PCI954 (Quad 16950 UART) function 1 (32bit bus)";
        case PciDevice1415::DEVICE_9513: return "OX16PCI954 (Quad 16950 UART) function 1 (parallel port)";
        case PciDevice1415::DEVICE_9521: return "OX16PCI952 (Dual 16950 UART)";
        case PciDevice1415::DEVICE_9523: return "OX16PCI952 Integrated Parallel Port";
        case PciDevice1415::DEVICE_C100: return "OXPCIe952 Parallel Port";
        case PciDevice1415::DEVICE_C101: return "OXPCIe952 Legacy 950 UART";
        case PciDevice1415::DEVICE_C104: return "OXPCIe952 Parallel Port";
        case PciDevice1415::DEVICE_C105: return "OXPCIe952 Legacy 950 UART";
        case PciDevice1415::DEVICE_C106: return "OXPCIe952 GPIO";
        case PciDevice1415::DEVICE_C108: return "OXPCIe952 Parallel Port";
        case PciDevice1415::DEVICE_C109: return "OXPCIe952 Legacy 950 UART";
        case PciDevice1415::DEVICE_C10C: return "OXPCIe952 Parallel Port";
        case PciDevice1415::DEVICE_C10D: return "OXPCIe952 Legacy 950 UART";
        case PciDevice1415::DEVICE_C10E: return "OXPCIe952 GPIO";
        case PciDevice1415::DEVICE_C110: return "OXPCIe952 Parallel Port";
        case PciDevice1415::DEVICE_C114: return "OXPCIe952 Parallel Port";
        case PciDevice1415::DEVICE_C118: return "OXPCIe952 Parallel Port";
        case PciDevice1415::DEVICE_C11B: return "OXPCIe952 Native 950 UART";
        case PciDevice1415::DEVICE_C11C: return "OXPCIe952 Parallel Port";
        case PciDevice1415::DEVICE_C11E: return "OXPCIe952 GPIO";
        case PciDevice1415::DEVICE_C11F: return "OXPCIe952 Native 950 UART";
        case PciDevice1415::DEVICE_C120: return "OXPCIe952 Legacy 950 UART";
        case PciDevice1415::DEVICE_C124: return "OXPCIe952 Legacy 950 UART";
        case PciDevice1415::DEVICE_C126: return "OXPCIe952 GPIO";
        case PciDevice1415::DEVICE_C128: return "OXPCIe952 Legacy 950 UART";
        case PciDevice1415::DEVICE_C12C: return "OXPCIe952 Legacy 950 UART";
        case PciDevice1415::DEVICE_C12E: return "OXPCIe952 GPIO";
        case PciDevice1415::DEVICE_C134: return "OXPCIe952 GPIO";
        case PciDevice1415::DEVICE_C138: return "OXPCIe952 Native 950 UART";
        case PciDevice1415::DEVICE_C13C: return "OXPCIe952 GPIO";
        case PciDevice1415::DEVICE_C13D: return "OXPCIe952 Native 950 UART";
        case PciDevice1415::DEVICE_C140: return "OXPCIe952 Legacy 950 UART #1";
        case PciDevice1415::DEVICE_C141: return "OXPCIe952 Legacy 950 UART #2";
        case PciDevice1415::DEVICE_C144: return "OXPCIe952 Legacy 950 UART #1";
        case PciDevice1415::DEVICE_C145: return "OXPCIe952 Legacy 950 UART #2";
        case PciDevice1415::DEVICE_C146: return "OXPCIe952 GPIO";
        case PciDevice1415::DEVICE_C148: return "OXPCIe952 Legacy 950 UART #1";
        case PciDevice1415::DEVICE_C149: return "OXPCIe952 Legacy 950 UART #2";
        case PciDevice1415::DEVICE_C14C: return "OXPCIe952 Legacy 950 UART #1";
        case PciDevice1415::DEVICE_C14D: return "OXPCIe952 Legacy 950 UART #2";
        case PciDevice1415::DEVICE_C14E: return "OXPCIe952 GPIO";
        case PciDevice1415::DEVICE_C154: return "OXPCIe952 GPIO";
        case PciDevice1415::DEVICE_C158: return "OXPCIe952 Dual Native 950 UART";
        case PciDevice1415::DEVICE_C15C: return "OXPCIe952 GPIO";
        case PciDevice1415::DEVICE_C15D: return "OXPCIe952 Dual Native 950 UART";
        case PciDevice1415::DEVICE_C308: return "EX-44016 16-port serial";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1415 device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1415::DEVICE_8401: return "Unknown device";
        case PciDevice1415::DEVICE_8403: return "Unknown device";
        case PciDevice1415::DEVICE_9500: return "Unknown device";
        case PciDevice1415::DEVICE_9501: return enumToHumanString((PciSubDevice14159501)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1415::DEVICE_9505: return "Unknown device";
        case PciDevice1415::DEVICE_950A: return "Unknown device";
        case PciDevice1415::DEVICE_950B: return "Unknown device";
        case PciDevice1415::DEVICE_9510: return enumToHumanString((PciSubDevice14159510)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1415::DEVICE_9511: return enumToHumanString((PciSubDevice14159511)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1415::DEVICE_9512: return "Unknown device";
        case PciDevice1415::DEVICE_9513: return "Unknown device";
        case PciDevice1415::DEVICE_9521: return "Unknown device";
        case PciDevice1415::DEVICE_9523: return "Unknown device";
        case PciDevice1415::DEVICE_C100: return "Unknown device";
        case PciDevice1415::DEVICE_C101: return "Unknown device";
        case PciDevice1415::DEVICE_C104: return "Unknown device";
        case PciDevice1415::DEVICE_C105: return "Unknown device";
        case PciDevice1415::DEVICE_C106: return "Unknown device";
        case PciDevice1415::DEVICE_C108: return "Unknown device";
        case PciDevice1415::DEVICE_C109: return "Unknown device";
        case PciDevice1415::DEVICE_C10C: return "Unknown device";
        case PciDevice1415::DEVICE_C10D: return "Unknown device";
        case PciDevice1415::DEVICE_C10E: return "Unknown device";
        case PciDevice1415::DEVICE_C110: return "Unknown device";
        case PciDevice1415::DEVICE_C114: return "Unknown device";
        case PciDevice1415::DEVICE_C118: return "Unknown device";
        case PciDevice1415::DEVICE_C11B: return "Unknown device";
        case PciDevice1415::DEVICE_C11C: return "Unknown device";
        case PciDevice1415::DEVICE_C11E: return "Unknown device";
        case PciDevice1415::DEVICE_C11F: return "Unknown device";
        case PciDevice1415::DEVICE_C120: return "Unknown device";
        case PciDevice1415::DEVICE_C124: return "Unknown device";
        case PciDevice1415::DEVICE_C126: return "Unknown device";
        case PciDevice1415::DEVICE_C128: return "Unknown device";
        case PciDevice1415::DEVICE_C12C: return "Unknown device";
        case PciDevice1415::DEVICE_C12E: return "Unknown device";
        case PciDevice1415::DEVICE_C134: return "Unknown device";
        case PciDevice1415::DEVICE_C138: return "Unknown device";
        case PciDevice1415::DEVICE_C13C: return "Unknown device";
        case PciDevice1415::DEVICE_C13D: return "Unknown device";
        case PciDevice1415::DEVICE_C140: return "Unknown device";
        case PciDevice1415::DEVICE_C141: return "Unknown device";
        case PciDevice1415::DEVICE_C144: return "Unknown device";
        case PciDevice1415::DEVICE_C145: return "Unknown device";
        case PciDevice1415::DEVICE_C146: return "Unknown device";
        case PciDevice1415::DEVICE_C148: return "Unknown device";
        case PciDevice1415::DEVICE_C149: return "Unknown device";
        case PciDevice1415::DEVICE_C14C: return "Unknown device";
        case PciDevice1415::DEVICE_C14D: return "Unknown device";
        case PciDevice1415::DEVICE_C14E: return "Unknown device";
        case PciDevice1415::DEVICE_C154: return "Unknown device";
        case PciDevice1415::DEVICE_C158: return enumToHumanString((PciSubDevice1415C158)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1415::DEVICE_C15C: return "Unknown device";
        case PciDevice1415::DEVICE_C15D: return "Unknown device";
        case PciDevice1415::DEVICE_C308: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1415_PCIDEVICE1415_H
