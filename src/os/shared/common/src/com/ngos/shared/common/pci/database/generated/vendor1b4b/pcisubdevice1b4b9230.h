// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B4B_PCISUBDEVICE1B4B9230_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B4B_PCISUBDEVICE1B4B9230_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1B4B9230: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10281FD6 = 0x10281FD6,
    SUBDEVICE_10281FDF = 0x10281FDF,
    SUBDEVICE_10281FE2 = 0x10281FE2,
    SUBDEVICE_10282010 = 0x10282010,
    SUBDEVICE_1D490300 = 0x1D490300,
    SUBDEVICE_1D490301 = 0x1D490301,
    SUBDEVICE_1D490302 = 0x1D490302,
    SUBDEVICE_1D490303 = 0x1D490303,
    SUBDEVICE_1D490304 = 0x1D490304,
    SUBDEVICE_1D490305 = 0x1D490305
};



inline const char8* enumToString(PciSubDevice1B4B9230 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1B4B9230::NONE:               return "NONE";
        case PciSubDevice1B4B9230::SUBDEVICE_10281FD6: return "SUBDEVICE_10281FD6";
        case PciSubDevice1B4B9230::SUBDEVICE_10281FDF: return "SUBDEVICE_10281FDF";
        case PciSubDevice1B4B9230::SUBDEVICE_10281FE2: return "SUBDEVICE_10281FE2";
        case PciSubDevice1B4B9230::SUBDEVICE_10282010: return "SUBDEVICE_10282010";
        case PciSubDevice1B4B9230::SUBDEVICE_1D490300: return "SUBDEVICE_1D490300";
        case PciSubDevice1B4B9230::SUBDEVICE_1D490301: return "SUBDEVICE_1D490301";
        case PciSubDevice1B4B9230::SUBDEVICE_1D490302: return "SUBDEVICE_1D490302";
        case PciSubDevice1B4B9230::SUBDEVICE_1D490303: return "SUBDEVICE_1D490303";
        case PciSubDevice1B4B9230::SUBDEVICE_1D490304: return "SUBDEVICE_1D490304";
        case PciSubDevice1B4B9230::SUBDEVICE_1D490305: return "SUBDEVICE_1D490305";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1B4B9230 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1B4B9230 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1B4B9230::SUBDEVICE_10281FD6: return "BOSS-S1 Adapter";
        case PciSubDevice1B4B9230::SUBDEVICE_10281FDF: return "BOSS-S1 Modular";
        case PciSubDevice1B4B9230::SUBDEVICE_10281FE2: return "BOSS-S1 Adapter";
        case PciSubDevice1B4B9230::SUBDEVICE_10282010: return "BOSS-S2 Adapter";
        case PciSubDevice1B4B9230::SUBDEVICE_1D490300: return "ThinkSystem M.2 with Mirroring Enablement Kit";
        case PciSubDevice1B4B9230::SUBDEVICE_1D490301: return "ThinkSystem SR630 x16 PCIE with 4 SATA ports Riser";
        case PciSubDevice1B4B9230::SUBDEVICE_1D490302: return "ThinkSystem SE350 M.2 SATA 4-Bay Data RAID Mirroring Enablement Kit";
        case PciSubDevice1B4B9230::SUBDEVICE_1D490303: return "ThinkSystem SE350 M.2 SATA 4-Bay Data RAID Mirroring Enablement Kit";
        case PciSubDevice1B4B9230::SUBDEVICE_1D490304: return "ThinkSystem M.2 SATA 2-Bay RAID Enablement Kit";
        case PciSubDevice1B4B9230::SUBDEVICE_1D490305: return "ThinkSystem 7mm SATA 2-Bay Rear RAID Enablement Kit";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B4B_PCISUBDEVICE1B4B9230_H
