// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E53714_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E53714_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19E53714: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_19E55312 = 0x19E55312
};



inline const char8* enumToString(PciSubDevice19E53714 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E53714::NONE:               return "NONE";
        case PciSubDevice19E53714::SUBDEVICE_19E55312: return "SUBDEVICE_19E55312";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19E53714 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19E53714 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E53714::SUBDEVICE_19E55312: return "NVMe SSD ES3500P V5 2000GB 2.5\" U.2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E53714_H
