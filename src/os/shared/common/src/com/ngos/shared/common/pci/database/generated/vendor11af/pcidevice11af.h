// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AF_PCIDEVICE11AF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AF_PCIDEVICE11AF_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11AF: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_EE40 = 0xEE40
};



inline const char8* enumToString(PciDevice11AF device11AF) // TEST: NO
{
    // COMMON_LT((" | device11AF = %u", device11AF)); // Commented to avoid bad looking logs



    switch (device11AF)
    {
        case PciDevice11AF::NONE:        return "NONE";
        case PciDevice11AF::DEVICE_0001: return "DEVICE_0001";
        case PciDevice11AF::DEVICE_EE40: return "DEVICE_EE40";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11AF device11AF) // TEST: NO
{
    // COMMON_LT((" | device11AF = %u", device11AF)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device11AF, enumToString(device11AF));

    return res;
}



inline const char8* enumToHumanString(PciDevice11AF device11AF) // TEST: NO
{
    // COMMON_LT((" | device11AF = %u", device11AF)); // Commented to avoid bad looking logs



    switch (device11AF)
    {
        case PciDevice11AF::DEVICE_0001: return "Cinema";
        case PciDevice11AF::DEVICE_EE40: return "Digidesign Audiomedia III";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11AF_PCIDEVICE11AF_H
