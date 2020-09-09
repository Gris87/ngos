// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002AA10_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002AA10_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002AA10: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_174BAA10 = 0x174BAA10,
    SUBDEVICE_18BCAA10 = 0x18BCAA10
};



inline const char8* enumToString(PciSubDevice1002AA10 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002AA10::NONE:               return "NONE";
        case PciSubDevice1002AA10::SUBDEVICE_174BAA10: return "SUBDEVICE_174BAA10";
        case PciSubDevice1002AA10::SUBDEVICE_18BCAA10: return "SUBDEVICE_18BCAA10";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002AA10 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002AA10 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002AA10::SUBDEVICE_174BAA10: return "Radeon HD 2400 PRO";
        case PciSubDevice1002AA10::SUBDEVICE_18BCAA10: return "Radeon HD 2400 PRO";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002AA10_H
