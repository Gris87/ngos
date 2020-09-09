// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E01E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E01E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1133E01E: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11331E01 = 0x11331E01,
    SUBDEVICE_1133E01E = 0x1133E01E
};



inline const char8* enumToString(PciSubDevice1133E01E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1133E01E::NONE:               return "NONE";
        case PciSubDevice1133E01E::SUBDEVICE_11331E01: return "SUBDEVICE_11331E01";
        case PciSubDevice1133E01E::SUBDEVICE_1133E01E: return "SUBDEVICE_1133E01E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1133E01E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1133E01E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1133E01E::SUBDEVICE_11331E01: return "Diva 2PRI/E1/T1-60 PCI v1";
        case PciSubDevice1133E01E::SUBDEVICE_1133E01E: return "Diva V-2PRI/E1/T1-60 PCI v1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E01E_H
