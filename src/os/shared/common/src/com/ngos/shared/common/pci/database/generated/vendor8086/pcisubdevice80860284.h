// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860284_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860284_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860284: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102809BE = 0x102809BE
};



inline const char8* enumToString(PciSubDevice80860284 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860284::NONE:               return "NONE";
        case PciSubDevice80860284::SUBDEVICE_102809BE: return "SUBDEVICE_102809BE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860284 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860284 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860284::SUBDEVICE_102809BE: return "Latitude 7410";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860284_H
