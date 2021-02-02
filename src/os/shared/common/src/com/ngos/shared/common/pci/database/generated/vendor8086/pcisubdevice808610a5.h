// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610A5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610A5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808610A5: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_808610A5 = 0x808610A5,
    SUBDEVICE_808610A6 = 0x808610A6
};



inline const char8* enumToString(PciSubDevice808610A5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610A5::NONE:               return "NONE";
        case PciSubDevice808610A5::SUBDEVICE_808610A5: return "SUBDEVICE_808610A5";
        case PciSubDevice808610A5::SUBDEVICE_808610A6: return "SUBDEVICE_808610A6";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808610A5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808610A5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610A5::SUBDEVICE_808610A5: return "PRO/1000 PF Quad Port Server Adapter";
        case PciSubDevice808610A5::SUBDEVICE_808610A6: return "PRO/1000 PF Quad Port Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610A5_H
