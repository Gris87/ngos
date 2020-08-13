// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111A_PCIDEVICE111A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111A_PCIDEVICE111A_H



#include <com/ngos/shared/common/ngos/types.h>
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



inline const char8* enumToString(PciDevice111A device111A) // TEST: NO
{
    // COMMON_LT((" | device111A = %u", device111A)); // Commented to avoid bad looking logs



    switch (device111A)
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



inline const char8* enumToFullString(PciDevice111A device111A) // TEST: NO
{
    // COMMON_LT((" | device111A = %u", device111A)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device111A, enumToString(device111A));

    return res;
}



inline const char8* enumToHumanString(PciDevice111A device111A) // TEST: NO
{
    // COMMON_LT((" | device111A = %u", device111A)); // Commented to avoid bad looking logs



    switch (device111A)
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



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111A_PCIDEVICE111A_H
