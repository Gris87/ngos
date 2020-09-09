// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0E11_PCISUBDEVICE0E11B178_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0E11_PCISUBDEVICE0E11B178_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice0E11B178: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E114080 = 0x0E114080,
    SUBDEVICE_0E114082 = 0x0E114082,
    SUBDEVICE_0E114083 = 0x0E114083
};



inline const char8* enumToString(PciSubDevice0E11B178 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice0E11B178::NONE:               return "NONE";
        case PciSubDevice0E11B178::SUBDEVICE_0E114080: return "SUBDEVICE_0E114080";
        case PciSubDevice0E11B178::SUBDEVICE_0E114082: return "SUBDEVICE_0E114082";
        case PciSubDevice0E11B178::SUBDEVICE_0E114083: return "SUBDEVICE_0E114083";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice0E11B178 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice0E11B178 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice0E11B178::SUBDEVICE_0E114080: return "Smart Array 5i";
        case PciSubDevice0E11B178::SUBDEVICE_0E114082: return "Smart Array 532";
        case PciSubDevice0E11B178::SUBDEVICE_0E114083: return "Smart Array 5312";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0E11_PCISUBDEVICE0E11B178_H
