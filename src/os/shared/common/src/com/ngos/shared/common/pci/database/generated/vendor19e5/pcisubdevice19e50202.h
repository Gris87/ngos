// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50202_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50202_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19E50202: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_19E5D149 = 0x19E5D149,
    SUBDEVICE_19E5D302 = 0x19E5D302,
    SUBDEVICE_19E5D304 = 0x19E5D304
};



inline const char8* enumToString(PciSubDevice19E50202 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E50202::NONE:               return "NONE";
        case PciSubDevice19E50202::SUBDEVICE_19E5D149: return "SUBDEVICE_19E5D149";
        case PciSubDevice19E50202::SUBDEVICE_19E5D302: return "SUBDEVICE_19E5D302";
        case PciSubDevice19E50202::SUBDEVICE_19E5D304: return "SUBDEVICE_19E5D304";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19E50202 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19E50202 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E50202::SUBDEVICE_19E5D149: return "Hi1822 SP528 (2*32G FC)";
        case PciSubDevice19E50202::SUBDEVICE_19E5D302: return "Hi1822 SP521 (2*32G FC)";
        case PciSubDevice19E50202::SUBDEVICE_19E5D304: return "Hi1822 SP526 (2*32G FC)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50202_H
