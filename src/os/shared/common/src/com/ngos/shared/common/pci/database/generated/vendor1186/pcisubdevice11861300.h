// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1186_PCISUBDEVICE11861300_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1186_PCISUBDEVICE11861300_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11861300: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11861300 = 0x11861300,
    SUBDEVICE_11861301 = 0x11861301,
    SUBDEVICE_11861303 = 0x11861303
};



inline const char8* enumToString(PciSubDevice11861300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11861300::NONE:               return "NONE";
        case PciSubDevice11861300::SUBDEVICE_11861300: return "SUBDEVICE_11861300";
        case PciSubDevice11861300::SUBDEVICE_11861301: return "SUBDEVICE_11861301";
        case PciSubDevice11861300::SUBDEVICE_11861303: return "SUBDEVICE_11861303";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11861300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11861300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11861300::SUBDEVICE_11861300: return "DFE-538TX 10/100 Ethernet Adapter";
        case PciSubDevice11861300::SUBDEVICE_11861301: return "DFE-530TX+ 10/100 Ethernet Adapter";
        case PciSubDevice11861300::SUBDEVICE_11861303: return "DFE-528TX 10/100 Fast Ethernet PCI Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1186_PCISUBDEVICE11861300_H
