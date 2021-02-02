// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125B_PCISUBDEVICE125B9100_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125B_PCISUBDEVICE125B9100_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice125B9100: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_A0001000 = 0xA0001000,
    SUBDEVICE_A0002000 = 0xA0002000,
    SUBDEVICE_A0006000 = 0xA0006000,
    SUBDEVICE_A0007000 = 0xA0007000,
    SUBDEVICE_EA501C10 = 0xEA501C10
};



inline const char8* enumToString(PciSubDevice125B9100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice125B9100::NONE:               return "NONE";
        case PciSubDevice125B9100::SUBDEVICE_A0001000: return "SUBDEVICE_A0001000";
        case PciSubDevice125B9100::SUBDEVICE_A0002000: return "SUBDEVICE_A0002000";
        case PciSubDevice125B9100::SUBDEVICE_A0006000: return "SUBDEVICE_A0006000";
        case PciSubDevice125B9100::SUBDEVICE_A0007000: return "SUBDEVICE_A0007000";
        case PciSubDevice125B9100::SUBDEVICE_EA501C10: return "SUBDEVICE_EA501C10";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice125B9100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice125B9100 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice125B9100::SUBDEVICE_A0001000: return "Serial Port";
        case PciSubDevice125B9100::SUBDEVICE_A0002000: return "Parallel Port";
        case PciSubDevice125B9100::SUBDEVICE_A0006000: return "SPI";
        case PciSubDevice125B9100::SUBDEVICE_A0007000: return "Local Bus";
        case PciSubDevice125B9100::SUBDEVICE_EA501C10: return "RXi2-BP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125B_PCISUBDEVICE125B9100_H
