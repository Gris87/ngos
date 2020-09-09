// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR121E_PCIDEVICE121E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR121E_PCIDEVICE121E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice121E: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0201 = 0x0201
};



inline const char8* enumToString(PciDevice121E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice121E::NONE:        return "NONE";
        case PciDevice121E::DEVICE_0201: return "DEVICE_0201";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice121E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice121E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice121E::DEVICE_0201: return "Myrinet 2000 Scalable Cluster Interconnect";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR121E_PCIDEVICE121E_H
