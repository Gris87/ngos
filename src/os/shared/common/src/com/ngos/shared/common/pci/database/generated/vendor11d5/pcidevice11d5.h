// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11D5_PCIDEVICE11D5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11D5_PCIDEVICE11D5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11D5: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0115 = 0x0115,
    DEVICE_0117 = 0x0117
};



inline const char8* enumToString(PciDevice11D5 device11D5) // TEST: NO
{
    // COMMON_LT((" | device11D5 = %u", device11D5)); // Commented to avoid bad looking logs



    switch (device11D5)
    {
        case PciDevice11D5::NONE:        return "NONE";
        case PciDevice11D5::DEVICE_0115: return "DEVICE_0115";
        case PciDevice11D5::DEVICE_0117: return "DEVICE_0117";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11D5 device11D5) // TEST: NO
{
    // COMMON_LT((" | device11D5 = %u", device11D5)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device11D5, enumToString(device11D5));

    return res;
}



inline const char8* enumToHumanString(PciDevice11D5 device11D5) // TEST: NO
{
    // COMMON_LT((" | device11D5 = %u", device11D5)); // Commented to avoid bad looking logs



    switch (device11D5)
    {
        case PciDevice11D5::DEVICE_0115: return "10115";
        case PciDevice11D5::DEVICE_0117: return "10117";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11D5_PCIDEVICE11D5_H
