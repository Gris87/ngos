// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E020_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E020_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1133E020: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11332001 = 0x11332001,
    SUBDEVICE_1133E020 = 0x1133E020
};



inline const char8* enumToString(PciSubDevice1133E020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1133E020::NONE:               return "NONE";
        case PciSubDevice1133E020::SUBDEVICE_11332001: return "SUBDEVICE_11332001";
        case PciSubDevice1133E020::SUBDEVICE_1133E020: return "SUBDEVICE_1133E020";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1133E020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1133E020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1133E020::SUBDEVICE_11332001: return "Diva 4PRI/E1/T1-120 PCI v1";
        case PciSubDevice1133E020::SUBDEVICE_1133E020: return "Diva V-4PRI/E1/T1-120 PCI v1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E020_H
