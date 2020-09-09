// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B91563_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B91563_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B91563: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B91563 = 0x10B91563,
    SUBDEVICE_18491563 = 0x18491563
};



inline const char8* enumToString(PciSubDevice10B91563 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B91563::NONE:               return "NONE";
        case PciSubDevice10B91563::SUBDEVICE_10B91563: return "SUBDEVICE_10B91563";
        case PciSubDevice10B91563::SUBDEVICE_18491563: return "SUBDEVICE_18491563";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B91563 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B91563 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B91563::SUBDEVICE_10B91563: return "ASRock 939Dual-SATA2 Motherboard";
        case PciSubDevice10B91563::SUBDEVICE_18491563: return "ASRock 939Dual-SATA2 Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B9_PCISUBDEVICE10B91563_H
