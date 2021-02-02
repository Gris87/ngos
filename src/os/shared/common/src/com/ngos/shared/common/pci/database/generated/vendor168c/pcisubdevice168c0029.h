// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0029_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0029_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice168C0029: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_07774005 = 0x07774005,
    SUBDEVICE_11863A7A = 0x11863A7A,
    SUBDEVICE_11863A7D = 0x11863A7D,
    SUBDEVICE_168C0029 = 0x168C0029,
    SUBDEVICE_168C2096 = 0x168C2096
};



inline const char8* enumToString(PciSubDevice168C0029 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C0029::NONE:               return "NONE";
        case PciSubDevice168C0029::SUBDEVICE_07774005: return "SUBDEVICE_07774005";
        case PciSubDevice168C0029::SUBDEVICE_11863A7A: return "SUBDEVICE_11863A7A";
        case PciSubDevice168C0029::SUBDEVICE_11863A7D: return "SUBDEVICE_11863A7D";
        case PciSubDevice168C0029::SUBDEVICE_168C0029: return "SUBDEVICE_168C0029";
        case PciSubDevice168C0029::SUBDEVICE_168C2096: return "SUBDEVICE_168C2096";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice168C0029 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice168C0029 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C0029::SUBDEVICE_07774005: return "SR71-15 802.11an Mini PCI Adapter";
        case PciSubDevice168C0029::SUBDEVICE_11863A7A: return "DWA-552 802.11n Xtreme N Desktop Adapter (rev A2)";
        case PciSubDevice168C0029::SUBDEVICE_11863A7D: return "DWA-552 802.11n Xtreme N Desktop Adapter (rev A3)";
        case PciSubDevice168C0029::SUBDEVICE_168C0029: return "AR922X Wireless Network Adapter";
        case PciSubDevice168C0029::SUBDEVICE_168C2096: return "Compex WLM200NX / Wistron DNMA-92";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0029_H
