// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416FD_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416FD_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E416FD: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C309F = 0x103C309F,
    SUBDEVICE_103C30A3 = 0x103C30A3
};



inline const char8* enumToString(PciSubDevice14E416FD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416FD::NONE:               return "NONE";
        case PciSubDevice14E416FD::SUBDEVICE_103C309F: return "SUBDEVICE_103C309F";
        case PciSubDevice14E416FD::SUBDEVICE_103C30A3: return "SUBDEVICE_103C30A3";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E416FD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E416FD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416FD::SUBDEVICE_103C309F: return "Compaq nx9420 Notebook";
        case PciSubDevice14E416FD::SUBDEVICE_103C30A3: return "Compaq nw8440";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416FD_H
