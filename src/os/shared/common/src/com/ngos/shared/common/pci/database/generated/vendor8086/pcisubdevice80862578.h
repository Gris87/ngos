// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862578_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862578_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862578: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14582578 = 0x14582578,
    SUBDEVICE_14627580 = 0x14627580,
    SUBDEVICE_15D94580 = 0x15D94580
};



inline const char8* enumToString(PciSubDevice80862578 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862578::NONE:               return "NONE";
        case PciSubDevice80862578::SUBDEVICE_14582578: return "SUBDEVICE_14582578";
        case PciSubDevice80862578::SUBDEVICE_14627580: return "SUBDEVICE_14627580";
        case PciSubDevice80862578::SUBDEVICE_15D94580: return "SUBDEVICE_15D94580";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862578 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862578 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862578::SUBDEVICE_14582578: return "GA-8KNXP motherboard (875P)";
        case PciSubDevice80862578::SUBDEVICE_14627580: return "MS-6758 (875P Neo)";
        case PciSubDevice80862578::SUBDEVICE_15D94580: return "P4SCE Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862578_H
