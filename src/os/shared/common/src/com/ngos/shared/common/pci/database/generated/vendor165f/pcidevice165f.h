// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR165F_PCIDEVICE165F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR165F_PCIDEVICE165F_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice165F: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1020 = 0x1020
};



inline const char8* enumToString(PciDevice165F device165F) // TEST: NO
{
    // COMMON_LT((" | device165F = %u", device165F)); // Commented to avoid bad looking logs



    switch (device165F)
    {
        case PciDevice165F::NONE:        return "NONE";
        case PciDevice165F::DEVICE_1020: return "DEVICE_1020";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice165F device165F) // TEST: NO
{
    // COMMON_LT((" | device165F = %u", device165F)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device165F, enumToString(device165F));

    return res;
}



inline const char8* enumToHumanString(PciDevice165F device165F) // TEST: NO
{
    // COMMON_LT((" | device165F = %u", device165F)); // Commented to avoid bad looking logs



    switch (device165F)
    {
        case PciDevice165F::DEVICE_1020: return "LMLM4 MPEG-4 encoder";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR165F_PCIDEVICE165F_H
