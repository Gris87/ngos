// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E4C_PCIDEVICE1E4C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E4C_PCIDEVICE1E4C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1E4C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0010 = 0x0010
};



inline const char8* enumToString(PciDevice1E4C device1E4C) // TEST: NO
{
    // COMMON_LT((" | device1E4C = %u", device1E4C)); // Commented to avoid bad looking logs



    switch (device1E4C)
    {
        case PciDevice1E4C::NONE:        return "NONE";
        case PciDevice1E4C::DEVICE_0010: return "DEVICE_0010";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1E4C device1E4C) // TEST: NO
{
    // COMMON_LT((" | device1E4C = %u", device1E4C)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1E4C, enumToString(device1E4C));

    return res;
}



inline const char8* enumToHumanString(PciDevice1E4C device1E4C) // TEST: NO
{
    // COMMON_LT((" | device1E4C = %u", device1E4C)); // Commented to avoid bad looking logs



    switch (device1E4C)
    {
        case PciDevice1E4C::DEVICE_0010: return "Gemini [ Lida ]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E4C_PCIDEVICE1E4C_H
