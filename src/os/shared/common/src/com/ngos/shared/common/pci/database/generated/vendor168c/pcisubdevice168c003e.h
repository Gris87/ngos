// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C003E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C003E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice168C003E: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1A56143A = 0x1A56143A,
    SUBDEVICE_1A561525 = 0x1A561525
};



inline const char8* enumToString(PciSubDevice168C003E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C003E::NONE:               return "NONE";
        case PciSubDevice168C003E::SUBDEVICE_1A56143A: return "SUBDEVICE_1A56143A";
        case PciSubDevice168C003E::SUBDEVICE_1A561525: return "SUBDEVICE_1A561525";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice168C003E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice168C003E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C003E::SUBDEVICE_1A56143A: return "Killer 1435 Wireless-AC";
        case PciSubDevice168C003E::SUBDEVICE_1A561525: return "Killer N1525 Wireless-AC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C003E_H
