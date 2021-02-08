// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860887_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860887_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860887: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80864062 = 0x80864062,
    SUBDEVICE_80864462 = 0x80864462
};



inline const char8* enumToString(PciSubDevice80860887 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860887::NONE:               return "NONE";
        case PciSubDevice80860887::SUBDEVICE_80864062: return "SUBDEVICE_80864062";
        case PciSubDevice80860887::SUBDEVICE_80864462: return "SUBDEVICE_80864462";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860887 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860887 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860887::SUBDEVICE_80864062: return "Centrino Wireless-N 2230 BGN";
        case PciSubDevice80860887::SUBDEVICE_80864462: return "Centrino Wireless-N 2230 BGN";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860887_H
