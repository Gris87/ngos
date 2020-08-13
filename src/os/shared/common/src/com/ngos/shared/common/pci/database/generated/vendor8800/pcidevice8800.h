// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8800_PCIDEVICE8800_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8800_PCIDEVICE8800_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice8800: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2008 = 0x2008
};



inline const char8* enumToString(PciDevice8800 device8800) // TEST: NO
{
    // COMMON_LT((" | device8800 = %u", device8800)); // Commented to avoid bad looking logs



    switch (device8800)
    {
        case PciDevice8800::NONE:        return "NONE";
        case PciDevice8800::DEVICE_2008: return "DEVICE_2008";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice8800 device8800) // TEST: NO
{
    // COMMON_LT((" | device8800 = %u", device8800)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device8800, enumToString(device8800));

    return res;
}



inline const char8* enumToHumanString(PciDevice8800 device8800) // TEST: NO
{
    // COMMON_LT((" | device8800 = %u", device8800)); // Commented to avoid bad looking logs



    switch (device8800)
    {
        case PciDevice8800::DEVICE_2008: return "Video assistant component";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8800_PCIDEVICE8800_H
