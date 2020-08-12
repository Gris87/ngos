// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1813_PCIDEVICE1813_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1813_PCIDEVICE1813_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1813: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4000 = 0x4000,
    DEVICE_4100 = 0x4100
};



inline const char8* enumToString(PciDevice1813 device1813) // TEST: NO
{
    // COMMON_LT((" | device1813 = %u", device1813)); // Commented to avoid bad looking logs



    switch (device1813)
    {
        case PciDevice1813::NONE:        return "NONE";
        case PciDevice1813::DEVICE_4000: return "DEVICE_4000";
        case PciDevice1813::DEVICE_4100: return "DEVICE_4100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1813 device1813) // TEST: NO
{
    // COMMON_LT((" | device1813 = %u", device1813)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1813, enumToString(device1813));

    return res;
}



inline const char8* enumToHumanString(PciDevice1813 device1813) // TEST: NO
{
    // COMMON_LT((" | device1813 = %u", device1813)); // Commented to avoid bad looking logs



    switch (device1813)
    {
        case PciDevice1813::DEVICE_4000: return "HaM controllerless modem";
        case PciDevice1813::DEVICE_4100: return "HaM plus Data Fax Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1813_PCIDEVICE1813_H
