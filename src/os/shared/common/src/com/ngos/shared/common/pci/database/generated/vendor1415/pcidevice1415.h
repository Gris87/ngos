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
    DEVICE_C158 = 0xC158,
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
        case PciDevice1415::DEVICE_C158: return "DEVICE_C158";
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
        case PciDevice1415::DEVICE_C158: return "OXPCIe952 Dual 16C950 UART";
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
        case PciDevice1415::DEVICE_C158: return enumToHumanString((PciSubDevice1415C158)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1415::DEVICE_C308: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1415_PCIDEVICE1415_H
