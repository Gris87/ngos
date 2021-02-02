// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808637CE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808637CE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808637CE: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_15900215 = 0x15900215,
    SUBDEVICE_17AA4023 = 0x17AA4023,
    SUBDEVICE_17AA4025 = 0x17AA4025
};



inline const char8* enumToString(PciSubDevice808637CE subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808637CE::NONE:               return "NONE";
        case PciSubDevice808637CE::SUBDEVICE_15900215: return "SUBDEVICE_15900215";
        case PciSubDevice808637CE::SUBDEVICE_17AA4023: return "SUBDEVICE_17AA4023";
        case PciSubDevice808637CE::SUBDEVICE_17AA4025: return "SUBDEVICE_17AA4025";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808637CE subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808637CE subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808637CE::SUBDEVICE_15900215: return "Ethernet 10Gb 2-port 568i Adapter";
        case PciSubDevice808637CE::SUBDEVICE_17AA4023: return "Intel Ethernet Connection X722 for 10GbE backplane";
        case PciSubDevice808637CE::SUBDEVICE_17AA4025: return "Ethernet Connection X722 for 10GbE backplane";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808637CE_H
