// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A4311_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A4311_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice127A4311: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_127A4311 = 0x127A4311,
    SUBDEVICE_13E00210 = 0x13E00210
};



inline const char8* enumToString(PciSubDevice127A4311 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A4311::NONE:               return "NONE";
        case PciSubDevice127A4311::SUBDEVICE_127A4311: return "SUBDEVICE_127A4311";
        case PciSubDevice127A4311::SUBDEVICE_13E00210: return "SUBDEVICE_13E00210";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice127A4311 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice127A4311 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A4311::SUBDEVICE_127A4311: return "Ring Modular? Riptide HSF RT HP Dom";
        case PciSubDevice127A4311::SUBDEVICE_13E00210: return "HP-GVC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A4311_H
