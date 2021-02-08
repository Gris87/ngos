// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862921_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862921_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862921: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280235 = 0x10280235,
    SUBDEVICE_10280236 = 0x10280236,
    SUBDEVICE_10280237 = 0x10280237,
    SUBDEVICE_14627360 = 0x14627360
};



inline const char8* enumToString(PciSubDevice80862921 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862921::NONE:               return "NONE";
        case PciSubDevice80862921::SUBDEVICE_10280235: return "SUBDEVICE_10280235";
        case PciSubDevice80862921::SUBDEVICE_10280236: return "SUBDEVICE_10280236";
        case PciSubDevice80862921::SUBDEVICE_10280237: return "SUBDEVICE_10280237";
        case PciSubDevice80862921::SUBDEVICE_14627360: return "SUBDEVICE_14627360";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862921 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862921 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862921::SUBDEVICE_10280235: return "PowerEdge R710 SATA IDE Controller";
        case PciSubDevice80862921::SUBDEVICE_10280236: return "PowerEdge R610 SATA IDE Controller";
        case PciSubDevice80862921::SUBDEVICE_10280237: return "PowerEdge T610 SATA IDE Controller";
        case PciSubDevice80862921::SUBDEVICE_14627360: return "G33/P35 Neo";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862921_H
