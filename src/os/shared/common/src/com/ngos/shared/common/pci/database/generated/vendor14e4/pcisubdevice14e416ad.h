// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416AD_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416AD_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E416AD: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1916 = 0x103C1916,
    SUBDEVICE_103C1917 = 0x103C1917,
    SUBDEVICE_103C2231 = 0x103C2231,
    SUBDEVICE_103C22FA = 0x103C22FA
};



inline const char8* enumToString(PciSubDevice14E416AD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416AD::NONE:               return "NONE";
        case PciSubDevice14E416AD::SUBDEVICE_103C1916: return "SUBDEVICE_103C1916";
        case PciSubDevice14E416AD::SUBDEVICE_103C1917: return "SUBDEVICE_103C1917";
        case PciSubDevice14E416AD::SUBDEVICE_103C2231: return "SUBDEVICE_103C2231";
        case PciSubDevice14E416AD::SUBDEVICE_103C22FA: return "SUBDEVICE_103C22FA";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E416AD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E416AD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416AD::SUBDEVICE_103C1916: return "FlexFabric 20Gb 2-port 630FLB Adapter";
        case PciSubDevice14E416AD::SUBDEVICE_103C1917: return "FlexFabric 20Gb 2-port 630M Adapter";
        case PciSubDevice14E416AD::SUBDEVICE_103C2231: return "3820C 10/20Gb Converged Network Adapter (SR-IOV VF)";
        case PciSubDevice14E416AD::SUBDEVICE_103C22FA: return "FlexFabric 10Gb 2-port 536FLB Adapter (SR-IOV VF)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416AD_H
