// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000008F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000008F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1000008F: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10928000 = 0x10928000,
    SUBDEVICE_10928760 = 0x10928760
};



inline const char8* enumToString(PciSubDevice1000008F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1000008F::NONE:               return "NONE";
        case PciSubDevice1000008F::SUBDEVICE_10928000: return "SUBDEVICE_10928000";
        case PciSubDevice1000008F::SUBDEVICE_10928760: return "SUBDEVICE_10928760";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1000008F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1000008F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1000008F::SUBDEVICE_10928000: return "FirePort 40 SCSI Controller";
        case PciSubDevice1000008F::SUBDEVICE_10928760: return "FirePort 40 Dual SCSI Host Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000008F_H
