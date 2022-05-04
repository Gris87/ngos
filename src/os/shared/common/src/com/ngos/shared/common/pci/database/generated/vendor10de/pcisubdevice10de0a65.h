// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0A65_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0A65_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0A65: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10438334 = 0x10438334,
    SUBDEVICE_145836A9 = 0x145836A9,
    SUBDEVICE_14628094 = 0x14628094,
    SUBDEVICE_19DA7222 = 0x19DA7222
};



inline const char8* enumToString(PciSubDevice10DE0A65 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0A65::NONE:               return "NONE";
        case PciSubDevice10DE0A65::SUBDEVICE_10438334: return "SUBDEVICE_10438334";
        case PciSubDevice10DE0A65::SUBDEVICE_145836A9: return "SUBDEVICE_145836A9";
        case PciSubDevice10DE0A65::SUBDEVICE_14628094: return "SUBDEVICE_14628094";
        case PciSubDevice10DE0A65::SUBDEVICE_19DA7222: return "SUBDEVICE_19DA7222";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0A65 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0A65 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0A65::SUBDEVICE_10438334: return "EN210 SILENT";
        case PciSubDevice10DE0A65::SUBDEVICE_145836A9: return "GV-N210D3-1GI (rev. 6.0/6.1)";
        case PciSubDevice10DE0A65::SUBDEVICE_14628094: return "N210 [Geforce 210] PCIe graphics adapter";
        case PciSubDevice10DE0A65::SUBDEVICE_19DA7222: return "GeForce 210 1GB [Synergy Edition]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0A65_H
