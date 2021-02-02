// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624C0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624C0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808624C0: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140267 = 0x10140267,
    SUBDEVICE_14625800 = 0x14625800
};



inline const char8* enumToString(PciSubDevice808624C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624C0::NONE:               return "NONE";
        case PciSubDevice808624C0::SUBDEVICE_10140267: return "SUBDEVICE_10140267";
        case PciSubDevice808624C0::SUBDEVICE_14625800: return "SUBDEVICE_14625800";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808624C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808624C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624C0::SUBDEVICE_10140267: return "NetVista A30p";
        case PciSubDevice808624C0::SUBDEVICE_14625800: return "845PE Max (MS-6580)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624C0_H
