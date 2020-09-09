// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCISUBDEVICE10DF0720_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCISUBDEVICE10DF0720_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DF0720: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1934 = 0x103C1934,
    SUBDEVICE_103C1935 = 0x103C1935,
    SUBDEVICE_103C21D4 = 0x103C21D4,
    SUBDEVICE_103C220A = 0x103C220A,
    SUBDEVICE_103C803F = 0x103C803F,
    SUBDEVICE_103C8144 = 0x103C8144,
    SUBDEVICE_17AA1056 = 0x17AA1056,
    SUBDEVICE_17AA1057 = 0x17AA1057,
    SUBDEVICE_17AA1059 = 0x17AA1059,
    SUBDEVICE_17AA4014 = 0x17AA4014
};



inline const char8* enumToString(PciSubDevice10DF0720 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DF0720::NONE:               return "NONE";
        case PciSubDevice10DF0720::SUBDEVICE_103C1934: return "SUBDEVICE_103C1934";
        case PciSubDevice10DF0720::SUBDEVICE_103C1935: return "SUBDEVICE_103C1935";
        case PciSubDevice10DF0720::SUBDEVICE_103C21D4: return "SUBDEVICE_103C21D4";
        case PciSubDevice10DF0720::SUBDEVICE_103C220A: return "SUBDEVICE_103C220A";
        case PciSubDevice10DF0720::SUBDEVICE_103C803F: return "SUBDEVICE_103C803F";
        case PciSubDevice10DF0720::SUBDEVICE_103C8144: return "SUBDEVICE_103C8144";
        case PciSubDevice10DF0720::SUBDEVICE_17AA1056: return "SUBDEVICE_17AA1056";
        case PciSubDevice10DF0720::SUBDEVICE_17AA1057: return "SUBDEVICE_17AA1057";
        case PciSubDevice10DF0720::SUBDEVICE_17AA1059: return "SUBDEVICE_17AA1059";
        case PciSubDevice10DF0720::SUBDEVICE_17AA4014: return "SUBDEVICE_17AA4014";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DF0720 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DF0720 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DF0720::SUBDEVICE_103C1934: return "FlexFabric 20Gb 2-port 650M Adapter";
        case PciSubDevice10DF0720::SUBDEVICE_103C1935: return "FlexFabric 20Gb 2-port 650FLB Adapter";
        case PciSubDevice10DF0720::SUBDEVICE_103C21D4: return "StoreFabric CN1200E 10Gb Converged Network Adapter";
        case PciSubDevice10DF0720::SUBDEVICE_103C220A: return "FlexFabric 10Gb 2-port 556FLR-SFP+ Adapter";
        case PciSubDevice10DF0720::SUBDEVICE_103C803F: return "Ethernet 10Gb 2-port 557SFP+ Adapter";
        case PciSubDevice10DF0720::SUBDEVICE_103C8144: return "FlexFabric 10GB 2-port 556FLR-T Adapter";
        case PciSubDevice10DF0720::SUBDEVICE_17AA1056: return "ThinkServer OCm14102-UX-L AnyFabric";
        case PciSubDevice10DF0720::SUBDEVICE_17AA1057: return "ThinkServer OCm14104-UX-L AnyFabric";
        case PciSubDevice10DF0720::SUBDEVICE_17AA1059: return "ThinkServer OCm14104-UT-L AnyFabric";
        case PciSubDevice10DF0720::SUBDEVICE_17AA4014: return "ThinkServer OCm14102-NX-L AnyFabric";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCISUBDEVICE10DF0720_H
