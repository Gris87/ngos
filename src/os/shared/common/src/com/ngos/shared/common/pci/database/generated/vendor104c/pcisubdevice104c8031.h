// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8031_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8031_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104C8031: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250064 = 0x10250064,
    SUBDEVICE_10250080 = 0x10250080,
    SUBDEVICE_103C0934 = 0x103C0934,
    SUBDEVICE_103C0944 = 0x103C0944,
    SUBDEVICE_103C099C = 0x103C099C,
    SUBDEVICE_103C308B = 0x103C308B
};



inline const char8* enumToString(PciSubDevice104C8031 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8031::NONE:               return "NONE";
        case PciSubDevice104C8031::SUBDEVICE_10250064: return "SUBDEVICE_10250064";
        case PciSubDevice104C8031::SUBDEVICE_10250080: return "SUBDEVICE_10250080";
        case PciSubDevice104C8031::SUBDEVICE_103C0934: return "SUBDEVICE_103C0934";
        case PciSubDevice104C8031::SUBDEVICE_103C0944: return "SUBDEVICE_103C0944";
        case PciSubDevice104C8031::SUBDEVICE_103C099C: return "SUBDEVICE_103C099C";
        case PciSubDevice104C8031::SUBDEVICE_103C308B: return "SUBDEVICE_103C308B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104C8031 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104C8031 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8031::SUBDEVICE_10250064: return "Extensa 3000 series laptop";
        case PciSubDevice104C8031::SUBDEVICE_10250080: return "Aspire 5024WLMi";
        case PciSubDevice104C8031::SUBDEVICE_103C0934: return "Compaq nw8240/nx8220";
        case PciSubDevice104C8031::SUBDEVICE_103C0944: return "Compaq nc6220 Notebook PC";
        case PciSubDevice104C8031::SUBDEVICE_103C099C: return "NX6110/NC6120";
        case PciSubDevice104C8031::SUBDEVICE_103C308B: return "MX6125";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8031_H
