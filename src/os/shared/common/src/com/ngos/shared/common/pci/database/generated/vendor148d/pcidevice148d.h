// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR148D_PCIDEVICE148D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR148D_PCIDEVICE148D_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice148D: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1003 = 0x1003
};



inline const char8* enumToString(PciDevice148D device148D) // TEST: NO
{
    // COMMON_LT((" | device148D = %u", device148D)); // Commented to avoid bad looking logs



    switch (device148D)
    {
        case PciDevice148D::NONE:        return "NONE";
        case PciDevice148D::DEVICE_1003: return "DEVICE_1003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice148D device148D) // TEST: NO
{
    // COMMON_LT((" | device148D = %u", device148D)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device148D, enumToString(device148D));

    return res;
}



inline const char8* enumToHumanString(PciDevice148D device148D) // TEST: NO
{
    // COMMON_LT((" | device148D = %u", device148D)); // Commented to avoid bad looking logs



    switch (device148D)
    {
        case PciDevice148D::DEVICE_1003: return "HCF 56k Data/Fax Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR148D_PCIDEVICE148D_H
