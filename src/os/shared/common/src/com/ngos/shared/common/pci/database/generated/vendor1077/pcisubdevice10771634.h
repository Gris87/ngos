// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10771634_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10771634_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10771634: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1077E4F1 = 0x1077E4F1,
    SUBDEVICE_1077E4F2 = 0x1077E4F2,
    SUBDEVICE_1077E4F3 = 0x1077E4F3,
    SUBDEVICE_1077E4F4 = 0x1077E4F4
};



inline const char8* enumToString(PciSubDevice10771634 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10771634::NONE:               return "NONE";
        case PciSubDevice10771634::SUBDEVICE_1077E4F1: return "SUBDEVICE_1077E4F1";
        case PciSubDevice10771634::SUBDEVICE_1077E4F2: return "SUBDEVICE_1077E4F2";
        case PciSubDevice10771634::SUBDEVICE_1077E4F3: return "SUBDEVICE_1077E4F3";
        case PciSubDevice10771634::SUBDEVICE_1077E4F4: return "SUBDEVICE_1077E4F4";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10771634 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10771634 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10771634::SUBDEVICE_1077E4F1: return "FastLinQ QL45212H 40GbE Adapter";
        case PciSubDevice10771634::SUBDEVICE_1077E4F2: return "FastLinQ QL45211H 40GbE Adapter";
        case PciSubDevice10771634::SUBDEVICE_1077E4F3: return "FastLinQ QL45412H 40GbE Adapter";
        case PciSubDevice10771634::SUBDEVICE_1077E4F4: return "FastLinQ QL45411H 40GbE Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10771634_H
