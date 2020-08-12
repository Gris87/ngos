// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D0F_PCIDEVICE1D0F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D0F_PCIDEVICE1D0F_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1D0F: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_CD01 = 0xCD01,
    DEVICE_EC20 = 0xEC20,
    DEVICE_EFA0 = 0xEFA0,
    DEVICE_EFA1 = 0xEFA1
};



inline const char8* enumToString(PciDevice1D0F device1D0F) // TEST: NO
{
    // COMMON_LT((" | device1D0F = %u", device1D0F)); // Commented to avoid bad looking logs



    switch (device1D0F)
    {
        case PciDevice1D0F::NONE:        return "NONE";
        case PciDevice1D0F::DEVICE_CD01: return "DEVICE_CD01";
        case PciDevice1D0F::DEVICE_EC20: return "DEVICE_EC20";
        case PciDevice1D0F::DEVICE_EFA0: return "DEVICE_EFA0";
        case PciDevice1D0F::DEVICE_EFA1: return "DEVICE_EFA1";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1D0F device1D0F) // TEST: NO
{
    // COMMON_LT((" | device1D0F = %u", device1D0F)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1D0F, enumToString(device1D0F));

    return res;
}



inline const char8* enumToHumanString(PciDevice1D0F device1D0F) // TEST: NO
{
    // COMMON_LT((" | device1D0F = %u", device1D0F)); // Commented to avoid bad looking logs



    switch (device1D0F)
    {
        case PciDevice1D0F::DEVICE_CD01: return "NVMe SSD Controller";
        case PciDevice1D0F::DEVICE_EC20: return "Elastic Network Adapter (ENA)";
        case PciDevice1D0F::DEVICE_EFA0: return "Elastic Fabric Adapter (EFA)";
        case PciDevice1D0F::DEVICE_EFA1: return "Elastic Fabric Adapter (EFA)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D0F_PCIDEVICE1D0F_H
