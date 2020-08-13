// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14C1_PCIDEVICE14C1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14C1_PCIDEVICE14C1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14C1: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0008 = 0x0008,
    DEVICE_8043 = 0x8043
};



inline const char8* enumToString(PciDevice14C1 device14C1) // TEST: NO
{
    // COMMON_LT((" | device14C1 = %u", device14C1)); // Commented to avoid bad looking logs



    switch (device14C1)
    {
        case PciDevice14C1::NONE:        return "NONE";
        case PciDevice14C1::DEVICE_0008: return "DEVICE_0008";
        case PciDevice14C1::DEVICE_8043: return "DEVICE_8043";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14C1 device14C1) // TEST: NO
{
    // COMMON_LT((" | device14C1 = %u", device14C1)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device14C1, enumToString(device14C1));

    return res;
}



inline const char8* enumToHumanString(PciDevice14C1 device14C1) // TEST: NO
{
    // COMMON_LT((" | device14C1 = %u", device14C1)); // Commented to avoid bad looking logs



    switch (device14C1)
    {
        case PciDevice14C1::DEVICE_0008: return "Myri-10G Dual-Protocol NIC";
        case PciDevice14C1::DEVICE_8043: return "Myrinet 2000 Scalable Cluster Interconnect";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14C1_PCIDEVICE14C1_H
