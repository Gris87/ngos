// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CD2_PCIDEVICE1CD2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CD2_PCIDEVICE1CD2_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1CD2: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0301 = 0x0301,
    DEVICE_0302 = 0x0302,
    DEVICE_0303 = 0x0303,
    DEVICE_0304 = 0x0304,
    DEVICE_0305 = 0x0305,
    DEVICE_0306 = 0x0306
};



inline const char8* enumToString(PciDevice1CD2 device1CD2) // TEST: NO
{
    // COMMON_LT((" | device1CD2 = %u", device1CD2)); // Commented to avoid bad looking logs



    switch (device1CD2)
    {
        case PciDevice1CD2::NONE:        return "NONE";
        case PciDevice1CD2::DEVICE_0301: return "DEVICE_0301";
        case PciDevice1CD2::DEVICE_0302: return "DEVICE_0302";
        case PciDevice1CD2::DEVICE_0303: return "DEVICE_0303";
        case PciDevice1CD2::DEVICE_0304: return "DEVICE_0304";
        case PciDevice1CD2::DEVICE_0305: return "DEVICE_0305";
        case PciDevice1CD2::DEVICE_0306: return "DEVICE_0306";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1CD2 device1CD2) // TEST: NO
{
    // COMMON_LT((" | device1CD2 = %u", device1CD2)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1CD2, enumToString(device1CD2));

    return res;
}



inline const char8* enumToHumanString(PciDevice1CD2 device1CD2) // TEST: NO
{
    // COMMON_LT((" | device1CD2 = %u", device1CD2)); // Commented to avoid bad looking logs



    switch (device1CD2)
    {
        case PciDevice1CD2::DEVICE_0301: return "Simulyzer-RT CompactPCI Serial DIO-1 card";
        case PciDevice1CD2::DEVICE_0302: return "Simulyzer-RT CompactPCI Serial PSI5-ECU-1 card";
        case PciDevice1CD2::DEVICE_0303: return "Simulyzer-RT CompactPCI Serial PSI5-SIM-1 card";
        case PciDevice1CD2::DEVICE_0304: return "Simulyzer-RT CompactPCI Serial PWR-ANA-1 card";
        case PciDevice1CD2::DEVICE_0305: return "Simulyzer-RT CompactPCI Serial CAN-1 card";
        case PciDevice1CD2::DEVICE_0306: return "Simulyzer-RT CompactPCI Serial CAN-2 card (CAN-FD)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CD2_PCIDEVICE1CD2_H
