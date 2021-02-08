// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDEAF_PCIDEVICEDEAF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDEAF_PCIDEVICEDEAF_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDeviceDEAF: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_9050 = 0x9050,
    DEVICE_9051 = 0x9051,
    DEVICE_9052 = 0x9052
};



inline const char8* enumToString(PciDeviceDEAF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceDEAF::NONE:        return "NONE";
        case PciDeviceDEAF::DEVICE_9050: return "DEVICE_9050";
        case PciDeviceDEAF::DEVICE_9051: return "DEVICE_9051";
        case PciDeviceDEAF::DEVICE_9052: return "DEVICE_9052";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDeviceDEAF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDeviceDEAF device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDeviceDEAF::DEVICE_9050: return "PC Weasel Virtual VGA";
        case PciDeviceDEAF::DEVICE_9051: return "PC Weasel Serial Port";
        case PciDeviceDEAF::DEVICE_9052: return "PC Weasel Watchdog Timer";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDEAF_PCIDEVICEDEAF_H
