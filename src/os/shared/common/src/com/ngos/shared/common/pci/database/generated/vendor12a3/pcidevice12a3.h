// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12A3_PCIDEVICE12A3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12A3_PCIDEVICE12A3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12A3: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8105 = 0x8105
};



inline const char8* enumToString(PciDevice12A3 device12A3) // TEST: NO
{
    // COMMON_LT((" | device12A3 = %u", device12A3)); // Commented to avoid bad looking logs



    switch (device12A3)
    {
        case PciDevice12A3::NONE:        return "NONE";
        case PciDevice12A3::DEVICE_8105: return "DEVICE_8105";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12A3 device12A3) // TEST: NO
{
    // COMMON_LT((" | device12A3 = %u", device12A3)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device12A3, enumToString(device12A3));

    return res;
}



inline const char8* enumToHumanString(PciDevice12A3 device12A3) // TEST: NO
{
    // COMMON_LT((" | device12A3 = %u", device12A3)); // Commented to avoid bad looking logs



    switch (device12A3)
    {
        case PciDevice12A3::DEVICE_8105: return "T8105 H100 Digital Switch";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12A3_PCIDEVICE12A3_H
