// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002731F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002731F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002731F: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14582313 = 0x14582313,
    SUBDEVICE_16825701 = 0x16825701,
    SUBDEVICE_18495120 = 0x18495120,
    SUBDEVICE_1DA2E411 = 0x1DA2E411
};



inline const char8* enumToString(PciSubDevice1002731F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002731F::NONE:               return "NONE";
        case PciSubDevice1002731F::SUBDEVICE_14582313: return "SUBDEVICE_14582313";
        case PciSubDevice1002731F::SUBDEVICE_16825701: return "SUBDEVICE_16825701";
        case PciSubDevice1002731F::SUBDEVICE_18495120: return "SUBDEVICE_18495120";
        case PciSubDevice1002731F::SUBDEVICE_1DA2E411: return "SUBDEVICE_1DA2E411";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002731F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002731F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002731F::SUBDEVICE_14582313: return "Radeon RX 5700 XT Gaming OC";
        case PciSubDevice1002731F::SUBDEVICE_16825701: return "RX 5700 XT RAW II";
        case PciSubDevice1002731F::SUBDEVICE_18495120: return "Radeon RX 5600 XT";
        case PciSubDevice1002731F::SUBDEVICE_1DA2E411: return "Radeon RX 5600 XT";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002731F_H
