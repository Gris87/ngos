// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4164E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4164E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E4164E: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C171C = 0x103C171C,
    SUBDEVICE_103C7058 = 0x103C7058
};



inline const char8* enumToString(PciSubDevice14E4164E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4164E::NONE:               return "NONE";
        case PciSubDevice14E4164E::SUBDEVICE_103C171C: return "SUBDEVICE_103C171C";
        case PciSubDevice14E4164E::SUBDEVICE_103C7058: return "SUBDEVICE_103C7058";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E4164E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E4164E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4164E::SUBDEVICE_103C171C: return "NC532m Dual Port 10GbE Multifunction BL-C Adapter";
        case PciSubDevice14E4164E::SUBDEVICE_103C7058: return "NC532i Dual Port 10GbE Multifunction BL-C Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4164E_H
