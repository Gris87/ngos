// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR146A_PCIDEVICE146A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR146A_PCIDEVICE146A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice146A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3010 = 0x3010,
    DEVICE_3A11 = 0x3A11
};



inline const char8* enumToString(PciDevice146A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice146A::NONE:        return "NONE";
        case PciDevice146A::DEVICE_3010: return "DEVICE_3010";
        case PciDevice146A::DEVICE_3A11: return "DEVICE_3A11";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice146A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice146A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice146A::DEVICE_3010: return "3010 RF Synthesizer";
        case PciDevice146A::DEVICE_3A11: return "3011A PXI RF Synthesizer";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR146A_PCIDEVICE146A_H
