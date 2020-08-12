// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR2000_PCIDEVICE2000_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR2000_PCIDEVICE2000_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice2000: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2800 = 0x2800
};



inline const char8* enumToString(PciDevice2000 device2000) // TEST: NO
{
    // COMMON_LT((" | device2000 = %u", device2000)); // Commented to avoid bad looking logs



    switch (device2000)
    {
        case PciDevice2000::NONE:        return "NONE";
        case PciDevice2000::DEVICE_2800: return "DEVICE_2800";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice2000 device2000) // TEST: NO
{
    // COMMON_LT((" | device2000 = %u", device2000)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device2000, enumToString(device2000));

    return res;
}



inline const char8* enumToHumanString(PciDevice2000 device2000) // TEST: NO
{
    // COMMON_LT((" | device2000 = %u", device2000)); // Commented to avoid bad looking logs



    switch (device2000)
    {
        case PciDevice2000::DEVICE_2800: return "SmartPCI2800 V.92 PCI Soft DFT";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR2000_PCIDEVICE2000_H
