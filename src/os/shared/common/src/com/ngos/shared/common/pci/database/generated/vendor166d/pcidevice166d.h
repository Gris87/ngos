// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR166D_PCIDEVICE166D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR166D_PCIDEVICE166D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice166D: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0012 = 0x0012,
    DEVICE_0014 = 0x0014
};



inline const char8* enumToString(PciDevice166D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice166D::NONE:        return "NONE";
        case PciDevice166D::DEVICE_0001: return "DEVICE_0001";
        case PciDevice166D::DEVICE_0002: return "DEVICE_0002";
        case PciDevice166D::DEVICE_0012: return "DEVICE_0012";
        case PciDevice166D::DEVICE_0014: return "DEVICE_0014";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice166D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice166D device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice166D::DEVICE_0001: return "SiByte BCM1125/1125H/1250 System-on-a-Chip PCI";
        case PciDevice166D::DEVICE_0002: return "SiByte BCM1125H/1250 System-on-a-Chip HyperTransport";
        case PciDevice166D::DEVICE_0012: return "SiByte BCM1280/BCM1480 System-on-a-Chip PCI-X";
        case PciDevice166D::DEVICE_0014: return "Sibyte BCM1280/BCM1480 System-on-a-Chip HyperTransport";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR166D_PCIDEVICE166D_H
