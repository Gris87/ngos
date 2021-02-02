// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCISUBDEVICE1FC94022_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCISUBDEVICE1FC94022_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1FC94022: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10438709 = 0x10438709,
    SUBDEVICE_11864D00 = 0x11864D00,
    SUBDEVICE_14328103 = 0x14328103,
    SUBDEVICE_1FC93015 = 0x1FC93015
};



inline const char8* enumToString(PciSubDevice1FC94022 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1FC94022::NONE:               return "NONE";
        case PciSubDevice1FC94022::SUBDEVICE_10438709: return "SUBDEVICE_10438709";
        case PciSubDevice1FC94022::SUBDEVICE_11864D00: return "SUBDEVICE_11864D00";
        case PciSubDevice1FC94022::SUBDEVICE_14328103: return "SUBDEVICE_14328103";
        case PciSubDevice1FC94022::SUBDEVICE_1FC93015: return "SUBDEVICE_1FC93015";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1FC94022 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1FC94022 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1FC94022::SUBDEVICE_10438709: return "XG-C100F 10GbE SFP+ Ethernet Adapter";
        case PciSubDevice1FC94022::SUBDEVICE_11864D00: return "DXE-810S 10GbE SFP+ Ethernet Adapter";
        case PciSubDevice1FC94022::SUBDEVICE_14328103: return "10 Gigabit Ethernet SFP+ PCI Express Adapter";
        case PciSubDevice1FC94022::SUBDEVICE_1FC93015: return "Ethernet Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1FC9_PCISUBDEVICE1FC94022_H
