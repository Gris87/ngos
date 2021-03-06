// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCISUBDEVICE11311562_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCISUBDEVICE11311562_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11311562: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1775C200 = 0x1775C200
};



inline const char8* enumToString(PciSubDevice11311562 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11311562::NONE:               return "NONE";
        case PciSubDevice11311562::SUBDEVICE_1775C200: return "SUBDEVICE_1775C200";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11311562 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11311562 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11311562::SUBDEVICE_1775C200: return "C2K onboard USB 2.0 host controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1131_PCISUBDEVICE11311562_H
