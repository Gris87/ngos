// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416D6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416D6_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E416D6: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14E44120 = 0x14E44120,
    SUBDEVICE_14E44126 = 0x14E44126,
    SUBDEVICE_152D8B20 = 0x152D8B20,
    SUBDEVICE_152D8B22 = 0x152D8B22
};



inline const char8* enumToString(PciSubDevice14E416D6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416D6::NONE:               return "NONE";
        case PciSubDevice14E416D6::SUBDEVICE_14E44120: return "SUBDEVICE_14E44120";
        case PciSubDevice14E416D6::SUBDEVICE_14E44126: return "SUBDEVICE_14E44126";
        case PciSubDevice14E416D6::SUBDEVICE_152D8B20: return "SUBDEVICE_152D8B20";
        case PciSubDevice14E416D6::SUBDEVICE_152D8B22: return "SUBDEVICE_152D8B22";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E416D6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E416D6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E416D6::SUBDEVICE_14E44120: return "NetXtreme E-Series Advanced Dual-port 10Gb SFP+ Ethernet Network Daughter Card";
        case PciSubDevice14E416D6::SUBDEVICE_14E44126: return "NetXtreme-E Dual-port 10G SFP+ Ethernet OCP 3.0 Adapter (BCM957412N4120C)";
        case PciSubDevice14E416D6::SUBDEVICE_152D8B20: return "BCM57412 NetXtreme-E 10Gb RDMA Ethernet Controller";
        case PciSubDevice14E416D6::SUBDEVICE_152D8B22: return "BCM57412 NetXtreme-E 25Gb RDMA Ethernet Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E416D6_H
