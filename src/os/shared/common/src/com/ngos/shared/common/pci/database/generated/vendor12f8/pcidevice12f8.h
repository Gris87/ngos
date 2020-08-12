// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12F8_PCIDEVICE12F8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12F8_PCIDEVICE12F8_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12F8: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0002 = 0x0002
};



inline const char8* enumToString(PciDevice12F8 device12F8) // TEST: NO
{
    // COMMON_LT((" | device12F8 = %u", device12F8)); // Commented to avoid bad looking logs



    switch (device12F8)
    {
        case PciDevice12F8::NONE:        return "NONE";
        case PciDevice12F8::DEVICE_0002: return "DEVICE_0002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12F8 device12F8) // TEST: NO
{
    // COMMON_LT((" | device12F8 = %u", device12F8)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device12F8, enumToString(device12F8));

    return res;
}



inline const char8* enumToHumanString(PciDevice12F8 device12F8) // TEST: NO
{
    // COMMON_LT((" | device12F8 = %u", device12F8)); // Commented to avoid bad looking logs



    switch (device12F8)
    {
        case PciDevice12F8::DEVICE_0002: return "VideoMaker";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12F8_PCIDEVICE12F8_H
