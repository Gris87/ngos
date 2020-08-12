// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDCBA_PCIDEVICEDCBA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDCBA_PCIDEVICEDCBA_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceDCBA: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0046 = 0x0046,
    DEVICE_0047 = 0x0047,
    DEVICE_0048 = 0x0048,
    DEVICE_004E = 0x004E,
    DEVICE_004F = 0x004F,
    DEVICE_0052 = 0x0052,
    DEVICE_0066 = 0x0066
};



inline const char8* enumToString(PciDeviceDCBA deviceDCBA) // TEST: NO
{
    // COMMON_LT((" | deviceDCBA = %u", deviceDCBA)); // Commented to avoid bad looking logs



    switch (deviceDCBA)
    {
        case PciDeviceDCBA::NONE:        return "NONE";
        case PciDeviceDCBA::DEVICE_0046: return "DEVICE_0046";
        case PciDeviceDCBA::DEVICE_0047: return "DEVICE_0047";
        case PciDeviceDCBA::DEVICE_0048: return "DEVICE_0048";
        case PciDeviceDCBA::DEVICE_004E: return "DEVICE_004E";
        case PciDeviceDCBA::DEVICE_004F: return "DEVICE_004F";
        case PciDeviceDCBA::DEVICE_0052: return "DEVICE_0052";
        case PciDeviceDCBA::DEVICE_0066: return "DEVICE_0066";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceDCBA deviceDCBA) // TEST: NO
{
    // COMMON_LT((" | deviceDCBA = %u", deviceDCBA)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)deviceDCBA, enumToString(deviceDCBA));

    return res;
}



inline const char8* enumToHumanString(PciDeviceDCBA deviceDCBA) // TEST: NO
{
    // COMMON_LT((" | deviceDCBA = %u", deviceDCBA)); // Commented to avoid bad looking logs



    switch (deviceDCBA)
    {
        case PciDeviceDCBA::DEVICE_0046: return "PCIe Altera Cyclone IV";
        case PciDeviceDCBA::DEVICE_0047: return "VPX-RCB";
        case PciDeviceDCBA::DEVICE_0048: return "PMC-Biserial-III-BAE9";
        case PciDeviceDCBA::DEVICE_004E: return "PC104p-Biserial-III-NVY5";
        case PciDeviceDCBA::DEVICE_004F: return "PC104p-Biserial-III-NVY6";
        case PciDeviceDCBA::DEVICE_0052: return "PCIeBiSerialDb37 BA22 LVDS IO";
        case PciDeviceDCBA::DEVICE_0066: return "PMC-OctalUART-232";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDCBA_PCIDEVICEDCBA_H
