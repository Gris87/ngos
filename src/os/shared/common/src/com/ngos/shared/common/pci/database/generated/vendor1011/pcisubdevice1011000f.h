// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1011_PCISUBDEVICE1011000F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1011_PCISUBDEVICE1011000F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1011000F: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1011DEF1 = 0x1011DEF1,
    SUBDEVICE_103CDEF1 = 0x103CDEF1
};



inline const char8* enumToString(PciSubDevice1011000F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1011000F::NONE:               return "NONE";
        case PciSubDevice1011000F::SUBDEVICE_1011DEF1: return "SUBDEVICE_1011DEF1";
        case PciSubDevice1011000F::SUBDEVICE_103CDEF1: return "SUBDEVICE_103CDEF1";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1011000F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1011000F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1011000F::SUBDEVICE_1011DEF1: return "FDDI controller (DEFPA)";
        case PciSubDevice1011000F::SUBDEVICE_103CDEF1: return "FDDI controller (3X-DEFPA)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1011_PCISUBDEVICE1011000F_H
