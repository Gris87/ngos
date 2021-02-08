// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E017_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E017_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1133E017: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1133E017 = 0x1133E017
};



inline const char8* enumToString(PciSubDevice1133E017 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1133E017::NONE:               return "NONE";
        case PciSubDevice1133E017::SUBDEVICE_1133E017: return "SUBDEVICE_1133E017";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1133E017 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1133E017 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1133E017::SUBDEVICE_1133E017: return "Diva Server Voice 4BRI-8M 2.0 PCI";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E017_H
