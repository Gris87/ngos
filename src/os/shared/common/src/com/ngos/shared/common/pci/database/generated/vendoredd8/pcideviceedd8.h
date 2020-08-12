// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOREDD8_PCIDEVICEEDD8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOREDD8_PCIDEVICEEDD8_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceEDD8: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_A091 = 0xA091,
    DEVICE_A099 = 0xA099,
    DEVICE_A0A1 = 0xA0A1,
    DEVICE_A0A9 = 0xA0A9
};



inline const char8* enumToString(PciDeviceEDD8 deviceEDD8) // TEST: NO
{
    // COMMON_LT((" | deviceEDD8 = %u", deviceEDD8)); // Commented to avoid bad looking logs



    switch (deviceEDD8)
    {
        case PciDeviceEDD8::NONE:        return "NONE";
        case PciDeviceEDD8::DEVICE_A091: return "DEVICE_A091";
        case PciDeviceEDD8::DEVICE_A099: return "DEVICE_A099";
        case PciDeviceEDD8::DEVICE_A0A1: return "DEVICE_A0A1";
        case PciDeviceEDD8::DEVICE_A0A9: return "DEVICE_A0A9";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceEDD8 deviceEDD8) // TEST: NO
{
    // COMMON_LT((" | deviceEDD8 = %u", deviceEDD8)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)deviceEDD8, enumToString(deviceEDD8));

    return res;
}



inline const char8* enumToHumanString(PciDeviceEDD8 deviceEDD8) // TEST: NO
{
    // COMMON_LT((" | deviceEDD8 = %u", deviceEDD8)); // Commented to avoid bad looking logs



    switch (deviceEDD8)
    {
        case PciDeviceEDD8::DEVICE_A091: return "1000PV [Stingray]";
        case PciDeviceEDD8::DEVICE_A099: return "2000PV [Stingray]";
        case PciDeviceEDD8::DEVICE_A0A1: return "2000MT";
        case PciDeviceEDD8::DEVICE_A0A9: return "2000MI";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOREDD8_PCIDEVICEEDD8_H
