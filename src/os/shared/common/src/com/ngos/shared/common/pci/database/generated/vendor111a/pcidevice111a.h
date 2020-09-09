// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111A_PCIDEVICE111A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111A_PCIDEVICE111A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor111a/pcisubdevice111a0003.h>
#include <com/ngos/shared/common/pci/database/generated/vendor111a/pcisubdevice111a0005.h>
#include <com/ngos/shared/common/pci/database/generated/vendor111a/pcisubdevice111a0007.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice111A: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0005 = 0x0005,
    DEVICE_0007 = 0x0007,
    DEVICE_1020 = 0x1020,
    DEVICE_1203 = 0x1203
};



inline const char8* enumToString(PciDevice111A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice111A::DEVICE_0000: return "DEVICE_0000";
        case PciDevice111A::DEVICE_0002: return "DEVICE_0002";
        case PciDevice111A::DEVICE_0003: return "DEVICE_0003";
        case PciDevice111A::DEVICE_0005: return "DEVICE_0005";
        case PciDevice111A::DEVICE_0007: return "DEVICE_0007";
        case PciDevice111A::DEVICE_1020: return "DEVICE_1020";
        case PciDevice111A::DEVICE_1203: return "DEVICE_1203";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice111A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice111A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice111A::DEVICE_0000: return "155P-MF1 (FPGA)";
        case PciDevice111A::DEVICE_0002: return "155P-MF1 (ASIC)";
        case PciDevice111A::DEVICE_0003: return "ENI-25P ATM";
        case PciDevice111A::DEVICE_0005: return "SpeedStream (LANAI)";
        case PciDevice111A::DEVICE_0007: return "SpeedStream ADSL";
        case PciDevice111A::DEVICE_1020: return "SpeedStream PCI 10/100 Network Card";
        case PciDevice111A::DEVICE_1203: return "SpeedStream 1023 Wireless PCI Adapter";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice111A device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice111A::DEVICE_0000: return "Unknown device";
        case PciDevice111A::DEVICE_0002: return "Unknown device";
        case PciDevice111A::DEVICE_0003: return enumToHumanString((PciSubDevice111A0003)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice111A::DEVICE_0005: return enumToHumanString((PciSubDevice111A0005)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice111A::DEVICE_0007: return enumToHumanString((PciSubDevice111A0007)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice111A::DEVICE_1020: return "Unknown device";
        case PciDevice111A::DEVICE_1203: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111A_PCIDEVICE111A_H
