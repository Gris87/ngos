// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002699F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002699F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002699F: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10281720 = 0x10281720,
    SUBDEVICE_148C2380 = 0x148C2380,
    SUBDEVICE_1DA2E367 = 0x1DA2E367
};



inline const char8* enumToString(PciSubDevice1002699F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002699F::NONE:               return "NONE";
        case PciSubDevice1002699F::SUBDEVICE_10281720: return "SUBDEVICE_10281720";
        case PciSubDevice1002699F::SUBDEVICE_148C2380: return "SUBDEVICE_148C2380";
        case PciSubDevice1002699F::SUBDEVICE_1DA2E367: return "SUBDEVICE_1DA2E367";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002699F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002699F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002699F::SUBDEVICE_10281720: return "Radeon RX 550X";
        case PciSubDevice1002699F::SUBDEVICE_148C2380: return "Lexa XL [Radeon RX 550]";
        case PciSubDevice1002699F::SUBDEVICE_1DA2E367: return "Lexa PRO [Radeon RX 550]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002699F_H
