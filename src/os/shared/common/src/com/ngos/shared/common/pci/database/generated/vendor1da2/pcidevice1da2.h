// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DA2_PCIDEVICE1DA2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DA2_PCIDEVICE1DA2_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1DA2: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_E26A = 0xE26A
};



inline const char8* enumToString(PciDevice1DA2 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1DA2::NONE:        return "NONE";
        case PciDevice1DA2::DEVICE_E26A: return "DEVICE_E26A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1DA2 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1DA2 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1DA2::DEVICE_E26A: return "Radeon R7 250";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1DA2_PCIDEVICE1DA2_H
