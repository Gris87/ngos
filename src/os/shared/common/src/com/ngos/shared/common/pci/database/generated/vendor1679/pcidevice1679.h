// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1679_PCIDEVICE1679_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1679_PCIDEVICE1679_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1679: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3000 = 0x3000
};



inline const char8* enumToString(PciDevice1679 device1679) // TEST: NO
{
    // COMMON_LT((" | device1679 = %u", device1679)); // Commented to avoid bad looking logs



    switch (device1679)
    {
        case PciDevice1679::NONE:        return "NONE";
        case PciDevice1679::DEVICE_3000: return "DEVICE_3000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1679 device1679) // TEST: NO
{
    // COMMON_LT((" | device1679 = %u", device1679)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1679, enumToString(device1679));

    return res;
}



inline const char8* enumToHumanString(PciDevice1679 device1679) // TEST: NO
{
    // COMMON_LT((" | device1679 = %u", device1679)); // Commented to avoid bad looking logs



    switch (device1679)
    {
        case PciDevice1679::DEVICE_3000: return "SD Standard host controller [Ellen]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1679_PCIDEVICE1679_H
