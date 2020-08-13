// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16F2_PCIDEVICE16F2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16F2_PCIDEVICE16F2_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice16F2: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0200 = 0x0200
};



inline const char8* enumToString(PciDevice16F2 device16F2) // TEST: NO
{
    // COMMON_LT((" | device16F2 = %u", device16F2)); // Commented to avoid bad looking logs



    switch (device16F2)
    {
        case PciDevice16F2::NONE:        return "NONE";
        case PciDevice16F2::DEVICE_0200: return "DEVICE_0200";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice16F2 device16F2) // TEST: NO
{
    // COMMON_LT((" | device16F2 = %u", device16F2)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device16F2, enumToString(device16F2));

    return res;
}



inline const char8* enumToHumanString(PciDevice16F2 device16F2) // TEST: NO
{
    // COMMON_LT((" | device16F2 = %u", device16F2)); // Commented to avoid bad looking logs



    switch (device16F2)
    {
        case PciDevice16F2::DEVICE_0200: return "I/O board";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR16F2_PCIDEVICE16F2_H
