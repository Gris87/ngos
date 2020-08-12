// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16E3_PCIDEVICE16E3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16E3_PCIDEVICE16E3_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice16E3: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1E0F = 0x1E0F
};



inline const char8* enumToString(PciDevice16E3 device16E3) // TEST: NO
{
    // COMMON_LT((" | device16E3 = %u", device16E3)); // Commented to avoid bad looking logs



    switch (device16E3)
    {
        case PciDevice16E3::NONE:        return "NONE";
        case PciDevice16E3::DEVICE_1E0F: return "DEVICE_1E0F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice16E3 device16E3) // TEST: NO
{
    // COMMON_LT((" | device16E3 = %u", device16E3)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device16E3, enumToString(device16E3));

    return res;
}



inline const char8* enumToHumanString(PciDevice16E3 device16E3) // TEST: NO
{
    // COMMON_LT((" | device16E3 = %u", device16E3)); // Commented to avoid bad looking logs



    switch (device16E3)
    {
        case PciDevice16E3::DEVICE_1E0F: return "LEON2FT Processor";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16E3_PCIDEVICE16E3_H
