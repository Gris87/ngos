// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862641_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862641_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862641: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140568 = 0x10140568,
    SUBDEVICE_103C0934 = 0x103C0934,
    SUBDEVICE_103C0944 = 0x103C0944,
    SUBDEVICE_103C099C = 0x103C099C
};



inline const char8* enumToString(PciSubDevice80862641 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862641::NONE:               return "NONE";
        case PciSubDevice80862641::SUBDEVICE_10140568: return "SUBDEVICE_10140568";
        case PciSubDevice80862641::SUBDEVICE_103C0934: return "SUBDEVICE_103C0934";
        case PciSubDevice80862641::SUBDEVICE_103C0944: return "SUBDEVICE_103C0944";
        case PciSubDevice80862641::SUBDEVICE_103C099C: return "SUBDEVICE_103C099C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862641 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862641 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862641::SUBDEVICE_10140568: return "ThinkPad X41";
        case PciSubDevice80862641::SUBDEVICE_103C0934: return "Compaq nw8240/nx8220";
        case PciSubDevice80862641::SUBDEVICE_103C0944: return "Compaq nc6220 Notebook PC";
        case PciSubDevice80862641::SUBDEVICE_103C099C: return "NX6110/NC6120";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862641_H
