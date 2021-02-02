// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1113_PCISUBDEVICE11131211_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1113_PCISUBDEVICE11131211_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11131211: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1207 = 0x103C1207,
    SUBDEVICE_11131211 = 0x11131211
};



inline const char8* enumToString(PciSubDevice11131211 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11131211::NONE:               return "NONE";
        case PciSubDevice11131211::SUBDEVICE_103C1207: return "SUBDEVICE_103C1207";
        case PciSubDevice11131211::SUBDEVICE_11131211: return "SUBDEVICE_11131211";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11131211 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11131211 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11131211::SUBDEVICE_103C1207: return "EN-1207D Fast Ethernet Adapter";
        case PciSubDevice11131211::SUBDEVICE_11131211: return "EN-1207D Fast Ethernet Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1113_PCISUBDEVICE11131211_H
