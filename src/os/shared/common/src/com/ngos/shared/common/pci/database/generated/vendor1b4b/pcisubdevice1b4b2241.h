// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B4B_PCISUBDEVICE1B4B2241_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B4B_PCISUBDEVICE1B4B2241_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1B4B2241: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10282112 = 0x10282112,
    SUBDEVICE_10282113 = 0x10282113,
    SUBDEVICE_10282151 = 0x10282151,
    SUBDEVICE_10282196 = 0x10282196,
    SUBDEVICE_1B4B2241 = 0x1B4B2241,
    SUBDEVICE_1D490306 = 0x1D490306,
    SUBDEVICE_1D490307 = 0x1D490307
};



inline const char8* enumToString(PciSubDevice1B4B2241 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1B4B2241::NONE:               return "NONE";
        case PciSubDevice1B4B2241::SUBDEVICE_10282112: return "SUBDEVICE_10282112";
        case PciSubDevice1B4B2241::SUBDEVICE_10282113: return "SUBDEVICE_10282113";
        case PciSubDevice1B4B2241::SUBDEVICE_10282151: return "SUBDEVICE_10282151";
        case PciSubDevice1B4B2241::SUBDEVICE_10282196: return "SUBDEVICE_10282196";
        case PciSubDevice1B4B2241::SUBDEVICE_1B4B2241: return "SUBDEVICE_1B4B2241";
        case PciSubDevice1B4B2241::SUBDEVICE_1D490306: return "SUBDEVICE_1D490306";
        case PciSubDevice1B4B2241::SUBDEVICE_1D490307: return "SUBDEVICE_1D490307";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1B4B2241 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1B4B2241 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1B4B2241::SUBDEVICE_10282112: return "BOSS-N1 Monolithic";
        case PciSubDevice1B4B2241::SUBDEVICE_10282113: return "BOSS-N1 Modular";
        case PciSubDevice1B4B2241::SUBDEVICE_10282151: return "BOSS-N1 Modular ET";
        case PciSubDevice1B4B2241::SUBDEVICE_10282196: return "ROR-N100";
        case PciSubDevice1B4B2241::SUBDEVICE_1B4B2241: return "Santa Cruz NVMe Host Adapter";
        case PciSubDevice1B4B2241::SUBDEVICE_1D490306: return "ThinkSystem M.2 NVMe 2-Bay RAID Enablement Kit";
        case PciSubDevice1B4B2241::SUBDEVICE_1D490307: return "ThinkSystem 7mm NVMe 2-Bay Rear RAID Enablement Kit";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B4B_PCISUBDEVICE1B4B2241_H
