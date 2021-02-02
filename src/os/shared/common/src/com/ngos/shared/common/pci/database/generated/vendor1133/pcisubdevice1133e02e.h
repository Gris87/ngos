// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E02E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E02E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1133E02E: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11332E01 = 0x11332E01,
    SUBDEVICE_1133E02E = 0x1133E02E
};



inline const char8* enumToString(PciSubDevice1133E02E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1133E02E::NONE:               return "NONE";
        case PciSubDevice1133E02E::SUBDEVICE_11332E01: return "SUBDEVICE_11332E01";
        case PciSubDevice1133E02E::SUBDEVICE_1133E02E: return "SUBDEVICE_1133E02E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1133E02E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1133E02E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1133E02E::SUBDEVICE_11332E01: return "Diva V-4BRI-8 PCIe v2";
        case PciSubDevice1133E02E::SUBDEVICE_1133E02E: return "Diva 4BRI-8 PCIe v2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E02E_H
