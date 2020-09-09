// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862E21_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862E21_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862E21: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104382D3 = 0x104382D3,
    SUBDEVICE_14585000 = 0x14585000
};



inline const char8* enumToString(PciSubDevice80862E21 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862E21::NONE:               return "NONE";
        case PciSubDevice80862E21::SUBDEVICE_104382D3: return "SUBDEVICE_104382D3";
        case PciSubDevice80862E21::SUBDEVICE_14585000: return "SUBDEVICE_14585000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862E21 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862E21 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862E21::SUBDEVICE_104382D3: return "P5Q Deluxe Motherboard";
        case PciSubDevice80862E21::SUBDEVICE_14585000: return "GA-EP45-DS5 Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862E21_H
