// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026665_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026665_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026665: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17AA1309 = 0x17AA1309,
    SUBDEVICE_17AA368F = 0x17AA368F
};



inline const char8* enumToString(PciSubDevice10026665 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026665::NONE:               return "NONE";
        case PciSubDevice10026665::SUBDEVICE_17AA1309: return "SUBDEVICE_17AA1309";
        case PciSubDevice10026665::SUBDEVICE_17AA368F: return "SUBDEVICE_17AA368F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026665 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026665 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026665::SUBDEVICE_17AA1309: return "Z50-75 Radeon R7 M260DX";
        case PciSubDevice10026665::SUBDEVICE_17AA368F: return "Radeon R5 A230";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026665_H
