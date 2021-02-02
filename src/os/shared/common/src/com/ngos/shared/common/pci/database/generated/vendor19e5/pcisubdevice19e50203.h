// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50203_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50203_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19E50203: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_19E5D148 = 0x19E5D148,
    SUBDEVICE_19E5D301 = 0x19E5D301,
    SUBDEVICE_19E5D305 = 0x19E5D305
};



inline const char8* enumToString(PciSubDevice19E50203 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E50203::NONE:               return "NONE";
        case PciSubDevice19E50203::SUBDEVICE_19E5D148: return "SUBDEVICE_19E5D148";
        case PciSubDevice19E50203::SUBDEVICE_19E5D301: return "SUBDEVICE_19E5D301";
        case PciSubDevice19E50203::SUBDEVICE_19E5D305: return "SUBDEVICE_19E5D305";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19E50203 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19E50203 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E50203::SUBDEVICE_19E5D148: return "Hi1822 SP527 (2*16G FC)";
        case PciSubDevice19E50203::SUBDEVICE_19E5D301: return "Hi1822 SP520 (2*16G FC)";
        case PciSubDevice19E50203::SUBDEVICE_19E5D305: return "Hi1822 SP525 (2*16G FC)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50203_H
