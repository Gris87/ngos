// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR544C_PCIDEVICE544C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR544C_PCIDEVICE544C_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice544C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0350 = 0x0350
};



inline const char8* enumToString(PciDevice544C device544C) // TEST: NO
{
    // COMMON_LT((" | device544C = %u", device544C)); // Commented to avoid bad looking logs



    switch (device544C)
    {
        case PciDevice544C::NONE:        return "NONE";
        case PciDevice544C::DEVICE_0350: return "DEVICE_0350";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice544C device544C) // TEST: NO
{
    // COMMON_LT((" | device544C = %u", device544C)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device544C, enumToString(device544C));

    return res;
}



inline const char8* enumToHumanString(PciDevice544C device544C) // TEST: NO
{
    // COMMON_LT((" | device544C = %u", device544C)); // Commented to avoid bad looking logs



    switch (device544C)
    {
        case PciDevice544C::DEVICE_0350: return "TL880-based HDTV/ATSC tuner";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR544C_PCIDEVICE544C_H
