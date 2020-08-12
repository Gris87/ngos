// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC1_PCIDEVICE1FC1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC1_PCIDEVICE1FC1_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1FC1: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_000D = 0x000D,
    DEVICE_0010 = 0x0010
};



inline const char8* enumToString(PciDevice1FC1 device1FC1) // TEST: NO
{
    // COMMON_LT((" | device1FC1 = %u", device1FC1)); // Commented to avoid bad looking logs



    switch (device1FC1)
    {
        case PciDevice1FC1::NONE:        return "NONE";
        case PciDevice1FC1::DEVICE_000D: return "DEVICE_000D";
        case PciDevice1FC1::DEVICE_0010: return "DEVICE_0010";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1FC1 device1FC1) // TEST: NO
{
    // COMMON_LT((" | device1FC1 = %u", device1FC1)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1FC1, enumToString(device1FC1));

    return res;
}



inline const char8* enumToHumanString(PciDevice1FC1 device1FC1) // TEST: NO
{
    // COMMON_LT((" | device1FC1 = %u", device1FC1)); // Commented to avoid bad looking logs



    switch (device1FC1)
    {
        case PciDevice1FC1::DEVICE_000D: return "IBA6110 InfiniBand HCA";
        case PciDevice1FC1::DEVICE_0010: return "IBA6120 InfiniBand HCA";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC1_PCIDEVICE1FC1_H
