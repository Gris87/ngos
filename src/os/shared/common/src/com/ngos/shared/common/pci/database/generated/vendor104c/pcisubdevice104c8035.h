// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8035_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8035_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104C8035: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C0934 = 0x103C0934,
    SUBDEVICE_103C0944 = 0x103C0944,
    SUBDEVICE_103C099C = 0x103C099C
};



inline const char8* enumToString(PciSubDevice104C8035 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8035::NONE:               return "NONE";
        case PciSubDevice104C8035::SUBDEVICE_103C0934: return "SUBDEVICE_103C0934";
        case PciSubDevice104C8035::SUBDEVICE_103C0944: return "SUBDEVICE_103C0944";
        case PciSubDevice104C8035::SUBDEVICE_103C099C: return "SUBDEVICE_103C099C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104C8035 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104C8035 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8035::SUBDEVICE_103C0934: return "Compaq nw8240/nx8220";
        case PciSubDevice104C8035::SUBDEVICE_103C0944: return "Compaq nc6220 Notebook PC";
        case PciSubDevice104C8035::SUBDEVICE_103C099C: return "NX6110/NC6120";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8035_H
