// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BB0_PCIDEVICE1BB0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BB0_PCIDEVICE1BB0_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1BB0: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0002 = 0x0002,
    DEVICE_0010 = 0x0010
};



inline const char8* enumToString(PciDevice1BB0 device1BB0) // TEST: NO
{
    // COMMON_LT((" | device1BB0 = %u", device1BB0)); // Commented to avoid bad looking logs



    switch (device1BB0)
    {
        case PciDevice1BB0::NONE:        return "NONE";
        case PciDevice1BB0::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1BB0::DEVICE_0010: return "DEVICE_0010";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1BB0 device1BB0) // TEST: NO
{
    // COMMON_LT((" | device1BB0 = %u", device1BB0)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1BB0, enumToString(device1BB0));

    return res;
}



inline const char8* enumToHumanString(PciDevice1BB0 device1BB0) // TEST: NO
{
    // COMMON_LT((" | device1BB0 = %u", device1BB0)); // Commented to avoid bad looking logs



    switch (device1BB0)
    {
        case PciDevice1BB0::DEVICE_0002: return "OmniCube Accelerator OA-3000";
        case PciDevice1BB0::DEVICE_0010: return "OmniCube Accelerator OA-3000-2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BB0_PCIDEVICE1BB0_H
