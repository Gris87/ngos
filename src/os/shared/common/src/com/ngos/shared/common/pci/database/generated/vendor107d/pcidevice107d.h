// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR107D_PCIDEVICE107D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR107D_PCIDEVICE107D_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice107D: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000
};



inline const char8* enumToString(PciDevice107D device107D) // TEST: NO
{
    // COMMON_LT((" | device107D = %u", device107D)); // Commented to avoid bad looking logs



    switch (device107D)
    {
        case PciDevice107D::DEVICE_0000: return "DEVICE_0000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice107D device107D) // TEST: NO
{
    // COMMON_LT((" | device107D = %u", device107D)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device107D, enumToString(device107D));

    return res;
}



inline const char8* enumToHumanString(PciDevice107D device107D) // TEST: NO
{
    // COMMON_LT((" | device107D = %u", device107D)); // Commented to avoid bad looking logs



    switch (device107D)
    {
        case PciDevice107D::DEVICE_0000: return "P86C850";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR107D_PCIDEVICE107D_H
