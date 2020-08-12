// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14B3_PCIDEVICE14B3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14B3_PCIDEVICE14B3_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14B3: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000
};



inline const char8* enumToString(PciDevice14B3 device14B3) // TEST: NO
{
    // COMMON_LT((" | device14B3 = %u", device14B3)); // Commented to avoid bad looking logs



    switch (device14B3)
    {
        case PciDevice14B3::DEVICE_0000: return "DEVICE_0000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14B3 device14B3) // TEST: NO
{
    // COMMON_LT((" | device14B3 = %u", device14B3)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device14B3, enumToString(device14B3));

    return res;
}



inline const char8* enumToHumanString(PciDevice14B3 device14B3) // TEST: NO
{
    // COMMON_LT((" | device14B3 = %u", device14B3)); // Commented to avoid bad looking logs



    switch (device14B3)
    {
        case PciDevice14B3::DEVICE_0000: return "DSL NIC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14B3_PCIDEVICE14B3_H
