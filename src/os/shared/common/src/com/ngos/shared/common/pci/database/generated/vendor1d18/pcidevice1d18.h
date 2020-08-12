// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D18_PCIDEVICE1D18_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D18_PCIDEVICE1D18_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1D18: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice1D18 device1D18) // TEST: NO
{
    // COMMON_LT((" | device1D18 = %u", device1D18)); // Commented to avoid bad looking logs



    switch (device1D18)
    {
        case PciDevice1D18::NONE:        return "NONE";
        case PciDevice1D18::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1D18 device1D18) // TEST: NO
{
    // COMMON_LT((" | device1D18 = %u", device1D18)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1D18, enumToString(device1D18));

    return res;
}



inline const char8* enumToHumanString(PciDevice1D18 device1D18) // TEST: NO
{
    // COMMON_LT((" | device1D18 = %u", device1D18)); // Commented to avoid bad looking logs



    switch (device1D18)
    {
        case PciDevice1D18::DEVICE_0001: return "Fireface UFX+";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D18_PCIDEVICE1D18_H
