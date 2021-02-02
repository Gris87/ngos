// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B0550_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B0550_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102B0550: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102B00C0 = 0x102B00C0,
    SUBDEVICE_102B00C1 = 0x102B00C1,
    SUBDEVICE_102B00C3 = 0x102B00C3,
    SUBDEVICE_102B00C5 = 0x102B00C5
};



inline const char8* enumToString(PciSubDevice102B0550 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B0550::NONE:               return "NONE";
        case PciSubDevice102B0550::SUBDEVICE_102B00C0: return "SUBDEVICE_102B00C0";
        case PciSubDevice102B0550::SUBDEVICE_102B00C1: return "SUBDEVICE_102B00C1";
        case PciSubDevice102B0550::SUBDEVICE_102B00C3: return "SUBDEVICE_102B00C3";
        case PciSubDevice102B0550::SUBDEVICE_102B00C5: return "SUBDEVICE_102B00C5";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102B0550 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102B0550 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B0550::SUBDEVICE_102B00C0: return "MURA-IPX-I4EF";
        case PciSubDevice102B0550::SUBDEVICE_102B00C1: return "MURA-IPX-I4DF";
        case PciSubDevice102B0550::SUBDEVICE_102B00C3: return "MURA-IPX-I4DHF";
        case PciSubDevice102B0550::SUBDEVICE_102B00C5: return "MURA-IPX-I4EHF";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B0550_H
