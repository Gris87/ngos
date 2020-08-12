// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR157C_PCIDEVICE157C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR157C_PCIDEVICE157C_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice157C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8001 = 0x8001
};



inline const char8* enumToString(PciDevice157C device157C) // TEST: NO
{
    // COMMON_LT((" | device157C = %u", device157C)); // Commented to avoid bad looking logs



    switch (device157C)
    {
        case PciDevice157C::NONE:        return "NONE";
        case PciDevice157C::DEVICE_8001: return "DEVICE_8001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice157C device157C) // TEST: NO
{
    // COMMON_LT((" | device157C = %u", device157C)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device157C, enumToString(device157C));

    return res;
}



inline const char8* enumToHumanString(PciDevice157C device157C) // TEST: NO
{
    // COMMON_LT((" | device157C = %u", device157C)); // Commented to avoid bad looking logs



    switch (device157C)
    {
        case PciDevice157C::DEVICE_8001: return "Fix2000 PCI Y2K Compliance Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR157C_PCIDEVICE157C_H
