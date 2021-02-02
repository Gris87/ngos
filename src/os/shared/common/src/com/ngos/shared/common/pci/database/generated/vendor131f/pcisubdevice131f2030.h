// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR131F_PCISUBDEVICE131F2030_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR131F_PCISUBDEVICE131F2030_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice131F2030: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_131F2030 = 0x131F2030
};



inline const char8* enumToString(PciSubDevice131F2030 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice131F2030::NONE:               return "NONE";
        case PciSubDevice131F2030::SUBDEVICE_131F2030: return "SUBDEVICE_131F2030";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice131F2030 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice131F2030 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice131F2030::SUBDEVICE_131F2030: return "PCI Serial Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR131F_PCISUBDEVICE131F2030_H
