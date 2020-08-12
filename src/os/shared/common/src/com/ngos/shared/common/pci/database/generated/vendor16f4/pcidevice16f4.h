// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16F4_PCIDEVICE16F4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16F4_PCIDEVICE16F4_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice16F4: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8000 = 0x8000
};



inline const char8* enumToString(PciDevice16F4 device16F4) // TEST: NO
{
    // COMMON_LT((" | device16F4 = %u", device16F4)); // Commented to avoid bad looking logs



    switch (device16F4)
    {
        case PciDevice16F4::NONE:        return "NONE";
        case PciDevice16F4::DEVICE_8000: return "DEVICE_8000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice16F4 device16F4) // TEST: NO
{
    // COMMON_LT((" | device16F4 = %u", device16F4)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device16F4, enumToString(device16F4));

    return res;
}



inline const char8* enumToHumanString(PciDevice16F4 device16F4) // TEST: NO
{
    // COMMON_LT((" | device16F4 = %u", device16F4)); // Commented to avoid bad looking logs



    switch (device16F4)
    {
        case PciDevice16F4::DEVICE_8000: return "VW2010";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16F4_PCIDEVICE16F4_H
