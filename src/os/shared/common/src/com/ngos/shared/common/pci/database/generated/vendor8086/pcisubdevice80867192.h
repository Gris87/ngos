// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867192_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867192_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80867192: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E110460 = 0x0E110460,
    SUBDEVICE_11790001 = 0x11790001,
    SUBDEVICE_4C531000 = 0x4C531000,
    SUBDEVICE_80867190 = 0x80867190
};



inline const char8* enumToString(PciSubDevice80867192 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80867192::NONE:               return "NONE";
        case PciSubDevice80867192::SUBDEVICE_0E110460: return "SUBDEVICE_0E110460";
        case PciSubDevice80867192::SUBDEVICE_11790001: return "SUBDEVICE_11790001";
        case PciSubDevice80867192::SUBDEVICE_4C531000: return "SUBDEVICE_4C531000";
        case PciSubDevice80867192::SUBDEVICE_80867190: return "SUBDEVICE_80867190";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80867192 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80867192 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80867192::SUBDEVICE_0E110460: return "Armada 1700 Laptop System Chipset";
        case PciSubDevice80867192::SUBDEVICE_11790001: return "Satellite 4010";
        case PciSubDevice80867192::SUBDEVICE_4C531000: return "CC7/CR7/CP7/VC7/VP7/VR7 mainboard";
        case PciSubDevice80867192::SUBDEVICE_80867190: return "Dell PowerEdge 350";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80867192_H
