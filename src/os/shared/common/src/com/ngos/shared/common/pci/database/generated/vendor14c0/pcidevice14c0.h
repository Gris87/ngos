// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14C0_PCIDEVICE14C0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14C0_PCIDEVICE14C0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14C0: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1201 = 0x1201
};



inline const char8* enumToString(PciDevice14C0 device14C0) // TEST: NO
{
    // COMMON_LT((" | device14C0 = %u", device14C0)); // Commented to avoid bad looking logs



    switch (device14C0)
    {
        case PciDevice14C0::NONE:        return "NONE";
        case PciDevice14C0::DEVICE_1201: return "DEVICE_1201";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14C0 device14C0) // TEST: NO
{
    // COMMON_LT((" | device14C0 = %u", device14C0)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device14C0, enumToString(device14C0));

    return res;
}



inline const char8* enumToHumanString(PciDevice14C0 device14C0) // TEST: NO
{
    // COMMON_LT((" | device14C0 = %u", device14C0)); // Commented to avoid bad looking logs



    switch (device14C0)
    {
        case PciDevice14C0::DEVICE_1201: return "X550 10Gb 2P RJ45 OCP Mezz";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14C0_PCIDEVICE14C0_H
