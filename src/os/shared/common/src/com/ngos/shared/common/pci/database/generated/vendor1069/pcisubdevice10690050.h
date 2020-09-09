// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1069_PCISUBDEVICE10690050_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1069_PCISUBDEVICE10690050_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10690050: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10690050 = 0x10690050,
    SUBDEVICE_10690052 = 0x10690052,
    SUBDEVICE_10690054 = 0x10690054
};



inline const char8* enumToString(PciSubDevice10690050 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10690050::NONE:               return "NONE";
        case PciSubDevice10690050::SUBDEVICE_10690050: return "SUBDEVICE_10690050";
        case PciSubDevice10690050::SUBDEVICE_10690052: return "SUBDEVICE_10690052";
        case PciSubDevice10690050::SUBDEVICE_10690054: return "SUBDEVICE_10690054";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10690050 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10690050 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10690050::SUBDEVICE_10690050: return "AcceleRAID 352 support Device";
        case PciSubDevice10690050::SUBDEVICE_10690052: return "AcceleRAID 170 support Device";
        case PciSubDevice10690050::SUBDEVICE_10690054: return "AcceleRAID 160 support Device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1069_PCISUBDEVICE10690050_H
